#include "stdafx.h"
#include "StraightCon.h"

#include "Player.h"
#include "Export_Function.h"

CStraightCon::CStraightCon(LPDIRECT3DDEVICE9 pGraphicDev)
	: CConveyor(pGraphicDev)
{

}

CStraightCon::~CStraightCon(void)
{

}

HRESULT CStraightCon::Ready_GameObject(const _uint& iFlag)
{
	CConveyor::Ready_GameObject(iFlag);

	return S_OK;
}

_int CStraightCon::Update_GameObject(const _float& fTimeDelta)
{
	CConveyor::Update_GameObject(fTimeDelta);
	
	return NO_EVENT;
}

_int CStraightCon::LateUpdate_GameObject(const _float & fTimeDelta)
{
	m_bColl = Collision_ToObject(L"GameLogic", L"Player", fTimeDelta);

	if (m_bColl)
	{
		Engine::CTransform* pPlayerTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
		CPlayer* pPlayer = dynamic_cast<CPlayer*>(Engine::Get_GameObj(L"GameLogic", L"Player"));

		if (!pPlayer->GetbIsConveyor())
		{
			if (m_pTransformCom->Get_Angle()->y == D3DXToRadian(0))
			{
				pPlayerTransformCom->Move_Pos(&(_vec3(0.f, 0.f, -1.f) * fTimeDelta));
			}
			else if (m_pTransformCom->Get_Angle()->y == D3DXToRadian(90))
			{
				pPlayerTransformCom->Move_Pos(&(_vec3(-1.f, 0.f, 0.f) *fTimeDelta));
			}
			else if (m_pTransformCom->Get_Angle()->y == D3DXToRadian(180))
			{
				pPlayerTransformCom->Move_Pos(&(_vec3(0.f, 0.f, 1.f) * fTimeDelta));
			}
			else if (m_pTransformCom->Get_Angle()->y == D3DXToRadian(270))
			{
				pPlayerTransformCom->Move_Pos(&(_vec3(1.f, 0.f, 0.f) * fTimeDelta));
			}

			pPlayer->Set_bIsConveyor(true);

		}
	}

	CConveyor::Update_GameObject(fTimeDelta);

	LPD3DXEFFECT	pEffect = m_pShaderCom->Get_EffectHandle();
	pEffect->AddRef();

	SetUp_ConstantTable(pEffect);

	m_fTimeAcc += fTimeDelta;
	pEffect->SetFloat("g_TimeAccY", m_fTimeAcc);

	Safe_Release(pEffect);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	return NO_EVENT;
}

void CStraightCon::Render_GameObject(void)
{
	CConveyor::Render_GameObject();
}

HRESULT CStraightCon::Add_Component(void)
{
	
	return S_OK;
}

_bool CStraightCon::Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag, const _float& fTimeDelta)
{
	Engine::CColliderBox*	pPlayerColliderCom = dynamic_cast<Engine::CColliderBox*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Collider", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderCom, false);
	
	if (m_bFirst)
	{
		m_bFirst = false;
		return false;
	}

	auto iter_begin = Engine::Get_Layer(pLayerTag)->Get_MapObject()->begin();
	auto iter_end = Engine::Get_Layer(pLayerTag)->Get_MapObject()->end();

	for (; iter_begin != iter_end; ++iter_begin)
	{
		wstring szTemp = iter_begin->first;
		_int iSearch =  szTemp.find(L"HeavyMetal");
		_int iSearch1 = szTemp.find(L"Shiny");
		if (iSearch >= 0 || iSearch1 >= 0)
		{
			Engine::CCollider*	pObjectColliderCom = dynamic_cast<Engine::CCollider*>(Engine::Get_Component(pLayerTag, iter_begin->first, L"Com_Collider", Engine::ID_STATIC));
			Engine::CTransform* pObjectTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(pLayerTag,iter_begin->first,L"Com_Transform",Engine::ID_DYNAMIC));

			if (m_pCalculatorCom->Collision_OBB(pObjectColliderCom->Get_Min(),
				pObjectColliderCom->Get_Max(),
				pObjectColliderCom->Get_ColliderMatrix(),
				m_pColliderCom->Get_Min(),
				m_pColliderCom->Get_Max(),
				m_pColliderCom->Get_ColliderMatrix()))
			{
				CStaticMeshObj* pObj = dynamic_cast<CStaticMeshObj*>(Engine::Get_GameObj(L"GameLogic", iter_begin->first));

				if (!pObj->GetbIsConveyor())
				{
					if (m_pTransformCom->Get_Angle()->y == D3DXToRadian(0))
					{
						pObjectTransformCom->Move_Pos(&(_vec3(0.f, 0.f, -1.f) * fTimeDelta));
					}
					else if (m_pTransformCom->Get_Angle()->y == D3DXToRadian(90))
					{
						pObjectTransformCom->Move_Pos(&(_vec3(-1.f, 0.f, 0.f) * fTimeDelta));
					}
					else if (m_pTransformCom->Get_Angle()->y == D3DXToRadian(180))
					{
						pObjectTransformCom->Move_Pos(&(_vec3(0.f, 0.f, 1.f) * fTimeDelta));
					}
					else if (m_pTransformCom->Get_Angle()->y == D3DXToRadian(270))
					{
						pObjectTransformCom->Move_Pos(&(_vec3(1.f, 0.f, 0.f) * fTimeDelta));
					}
					pObj->Set_bIsConveyor(true);
				}
			}
		}
	}

	return m_pCalculatorCom->Collision_OBB(pPlayerColliderCom->Get_Min(),
			pPlayerColliderCom->Get_Max(),
			pPlayerColliderCom->Get_ColliderBoxMatrix(),
			m_pColliderCom->Get_Min(),
			m_pColliderCom->Get_Max(),
			m_pColliderCom->Get_ColliderMatrix());

	/*	return m_pCalculatorCom->Collision_AABB(pPlayerColliderCom->Get_Min(),
											pPlayerColliderCom->Get_Max(),
											pPlayerColliderCom->Get_ColliderBoxMatrix(),
											m_pColliderCom->Get_Min(), 
											m_pColliderCom->Get_Max(), 
											m_pColliderCom->Get_ColliderMatrix());*/
}

CStraightCon* CStraightCon::Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag)
{
	CStraightCon*	pInstance = new CStraightCon(pGraphicDev);

	memcpy(pInstance->m_ObjTag, ObjTag.c_str(), (ObjTag.length() + 1) * sizeof(_tchar));
	memcpy(pInstance->m_MeshTag, MeshTag.c_str(), (MeshTag.length() + 1) * sizeof(_tchar));

	if (FAILED(pInstance->Ready_GameObject(iFlag)))
		Engine::Safe_Release(pInstance);
	
	return pInstance;
}

void CStraightCon::Free(void)
{
	Engine::CGameObject::Free();
}

HRESULT CStraightCon::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
{
	_matrix			matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);

	return S_OK;
}
#include "stdafx.h"
#include "CornerCon.h"

#include "Player.h"
#include "Export_Function.h"

CCornerCon::CCornerCon(LPDIRECT3DDEVICE9 pGraphicDev)
	: CConveyor(pGraphicDev)
{

}

CCornerCon::~CCornerCon(void)
{

}

HRESULT CCornerCon::Ready_GameObject(const _uint& iFlag)
{
	CConveyor::Ready_GameObject(iFlag);

	return S_OK;
}

_int CCornerCon::Update_GameObject(const _float& fTimeDelta)
{
	CConveyor::Update_GameObject(fTimeDelta);
	
	return NO_EVENT;
}

_int CCornerCon::LateUpdate_GameObject(const _float & fTimeDelta)
{
	m_bColl = Collision_ToObject(L"GameLogic", L"Player", fTimeDelta);

	if (m_bColl)
	{
		CPlayer* pPlayer = dynamic_cast<CPlayer*>(Engine::Get_GameObj(L"GameLogic", L"Player"));

		if (!pPlayer->GetbIsConveyor())
		{
			if (m_bIsReverse)
				dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC))->Move_Pos(&(_vec3(1.f, 0.f, -1.f) * fTimeDelta));
			else
				dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC))->Move_Pos(&(_vec3(-1.f, 0.f, 1.f) * fTimeDelta));
			pPlayer->Set_bIsConveyor(true);
		}
	}

	CConveyor::Update_GameObject(fTimeDelta);

	LPD3DXEFFECT	pEffect = m_pShaderCom->Get_EffectHandle();
	pEffect->AddRef();

	SetUp_ConstantTable(pEffect);

	Safe_Release(pEffect);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);


	return NO_EVENT;
}

void CCornerCon::Render_GameObject(void)
{
	CConveyor::Render_GameObject();
}

void CCornerCon::Set_Reverse(_bool bIsReverse)
{
	m_bIsReverse = bIsReverse;
}

HRESULT CCornerCon::Add_Component(void)
{
	
	return S_OK;
}

_bool CCornerCon::Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag, const _float& fTimeDelta)
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
		_int iSearch = szTemp.find(L"HeavyMetal");
		_int iSearch1 = szTemp.find(L"Shiny_");
		if (iSearch >= 0 || iSearch1 >= 0)
		{
			Engine::CCollider*	pObjectColliderCom = dynamic_cast<Engine::CCollider*>(Engine::Get_Component(pLayerTag, iter_begin->first, L"Com_Collider", Engine::ID_STATIC));
			Engine::CTransform* pObjectTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(pLayerTag, iter_begin->first, L"Com_Transform", Engine::ID_DYNAMIC));

			if (m_pCalculatorCom->Collision_OBB(pObjectColliderCom->Get_Min(),
				pObjectColliderCom->Get_Max(),
				pObjectColliderCom->Get_ColliderMatrix(),
				m_pColliderCom->Get_Min(),
				m_pColliderCom->Get_Max(),
				m_pColliderCom->Get_ColliderMatrix()))
			{
				if (m_bIsReverse)
					pObjectTransformCom->Move_Pos(&(_vec3(1.f, 0.f, -1.f) * fTimeDelta));
				else
					pObjectTransformCom->Move_Pos(&(_vec3(-1.f, 0.f, 1.f) * fTimeDelta));
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

CCornerCon* CCornerCon::Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag)
{
	CCornerCon*	pInstance = new CCornerCon(pGraphicDev);

	memcpy(pInstance->m_ObjTag, ObjTag.c_str(), (ObjTag.length() + 1) * sizeof(_tchar));
	memcpy(pInstance->m_MeshTag, MeshTag.c_str(), (MeshTag.length() + 1) * sizeof(_tchar));

	if (FAILED(pInstance->Ready_GameObject(iFlag)))
		Engine::Safe_Release(pInstance);
	
	return pInstance;
}

void CCornerCon::Free(void)
{
	Engine::CGameObject::Free();
}

HRESULT CCornerCon::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
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
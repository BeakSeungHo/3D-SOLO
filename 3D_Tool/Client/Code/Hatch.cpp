#include "stdafx.h"
#include "Hatch.h"

#include "Shiny.h"
#include "Export_Function.h"

CHatch::CHatch(LPDIRECT3DDEVICE9 pGraphicDev)
	: CStaticMeshObj(pGraphicDev)
{

}

CHatch::~CHatch(void)
{

}

HRESULT CHatch::Ready_GameObject(const _uint& iFlag)
{
	CStaticMeshObj::Ready_GameObject(iFlag);

	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	return S_OK;
}

_int CHatch::Update_GameObject(const _float& fTimeDelta)
{
	CStaticMeshObj::Update_GameObject(fTimeDelta);
	



	return NO_EVENT;
}

_int CHatch::LateUpdate_GameObject(const _float & fTimeDelta)
{
	Engine::CTransform* Temp = nullptr;
	m_bColl = Collision_ToObject(L"GameLogic", L"HatchShiny");

	if (m_bColl)
		m_fTimeAcc = 0.f;
	else
		m_fTimeAcc += fTimeDelta;

	if (m_fTimeAcc > 5)
	{
		m_pTransformCom->Set_Pos(&(m_vOriPos - _vec3(0.f, 2.f, 0.f)));
		++m_iCount;

		m_szTag = L"HatchShiny_" + to_wstring(m_iCount);

		m_pShiny = CShiny::Create(m_pGraphicDev, 0, L"Shiny_Barrel", m_szTag);

		Engine::Get_Layer(L"GameLogic")->Add_GameObject(m_pShiny->GetObjTag(), m_pShiny);

		m_fTimeAcc = 0.f;
	}

	if (D3DXVec3Length(&(m_vOriPos - *m_pTransformCom->Get_Info(Engine::INFO_POS))) > 0.1f)
	{
		_vec3 vPos;
		D3DXVec3Lerp(&vPos, &m_vOriPos, m_pTransformCom->Get_Info(Engine::INFO_POS), 0.1f);
		m_pTransformCom->Set_Pos(&vPos);

		dynamic_cast<Engine::CTransform*>(m_pShiny->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(&vPos);
	}

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	return NO_EVENT;
}

void CHatch::Render_GameObject(void)
{
	CStaticMeshObj::Render_GameObject();

	_matrix		matWorld;
	m_pTransformCom->Get_WorldMatrix(&matWorld);

	m_pColliderCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);
	m_pColiderSphereCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);
}

void CHatch::Set_OriPos(_vec3 vOriPos)
{
	m_vOriPos = vOriPos;
}


HRESULT CHatch::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	pComponent = m_pColliderCom = Engine::CCollider::Create(m_pGraphicDev,
		m_pMeshCom->Get_VtxPos(),
		m_pMeshCom->Get_NumVtx(),
		m_pMeshCom->Get_Stride());
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Collider", pComponent);

	pComponent = m_pColiderSphereCom = Engine::CColliderSphere::Create(m_pGraphicDev,
		m_pTransformCom->Get_Info(Engine::INFO_POS), 50.f);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_ColliderSphere", pComponent);
	
	return S_OK;
}

_bool CHatch::Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag)
{
	Engine::CCollider*			pObjectColliderCom = nullptr;
	Engine::CColliderSphere*	pObjectColiderSphereCom = nullptr;
	Engine::CTransform*			pObjectTransformCom = nullptr;

	auto iter_begin = Engine::Get_Layer(L"GameLogic")->Get_MapObject()->begin();
	auto iter_end = Engine::Get_Layer(L"GameLogic")->Get_MapObject()->end();

	for (; iter_begin != iter_end; ++iter_begin)
	{
		wstring temp = iter_begin->first;
		_int iSearch = temp.find(L"HatchShiny");

		if (iSearch >= 0)
		{
			pObjectColiderSphereCom = dynamic_cast<Engine::CColliderSphere*>(Engine::Get_Component(pLayerTag, iter_begin->first, L"Com_ColliderSphere", Engine::ID_STATIC));
			pObjectTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(pLayerTag, iter_begin->first, L"Com_Transform", Engine::ID_DYNAMIC));

			if (m_pCalculatorCom->Coliision_Sphere(pObjectTransformCom->Get_Info(Engine::INFO_POS),
												pObjectColiderSphereCom->Get_Radius(),
												m_pTransformCom->Get_Info(Engine::INFO_POS),
												m_pColiderSphereCom->Get_Radius()))
			{
				pObjectColliderCom = dynamic_cast<Engine::CCollider*>(Engine::Get_Component(pLayerTag, iter_begin->first, L"Com_Collider", Engine::ID_STATIC));

				if (m_pCalculatorCom->Collision_OBB(pObjectColliderCom->Get_Min(),
					pObjectColliderCom->Get_Max(),
					pObjectColliderCom->Get_ColliderMatrix(),
					m_pColliderCom->Get_Min(),
					m_pColliderCom->Get_Max(),
					m_pColliderCom->Get_ColliderMatrix()))
				{
					return true;
				}
			}

			
		}
	}

	return false;
}

CHatch* CHatch::Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag)
{
	CHatch*	pInstance = new CHatch(pGraphicDev);

	memcpy(pInstance->m_ObjTag, ObjTag.c_str(), (ObjTag.length() + 1) * sizeof(_tchar));
	memcpy(pInstance->m_MeshTag, MeshTag.c_str(), (MeshTag.length() + 1) * sizeof(_tchar));

	if (FAILED(pInstance->Ready_GameObject(iFlag)))
		Engine::Safe_Release(pInstance);
	
	return pInstance;
}

void CHatch::Free(void)
{
	Engine::CGameObject::Free();
}

HRESULT CHatch::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
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
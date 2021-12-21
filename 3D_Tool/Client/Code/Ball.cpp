#include "stdafx.h"
#include "Ball.h"

#include "Export_Function.h"

CBall::CBall(LPDIRECT3DDEVICE9 pGraphicDev)
	: CStaticMeshObj(pGraphicDev)
{

}

CBall::~CBall(void)
{

}

HRESULT CBall::Ready_GameObject(const _uint& iFlag)
{
	CStaticMeshObj::Ready_GameObject(iFlag);

	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	return S_OK;
}

_int CBall::Update_GameObject(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_GameObject(fTimeDelta);
	
	

	return NO_EVENT;
}

_int CBall::LateUpdate_GameObject(const _float & fTimeDelta)
{
	m_bColl = Collision_ToObject(L"GameLogic", L"Player");

	if (m_bColl)
	{
		Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));

		_vec3 vDir = *m_pTransformCom->Get_Info(Engine::INFO_POS) - *pPlayerTransCom->Get_Info(Engine::INFO_POS);
		vDir.y = 0;
		D3DXVec3Normalize(&vDir, &vDir);
		m_vEndPos = *m_pTransformCom->Get_Info(Engine::INFO_POS) + vDir * 30.f * fTimeDelta;

		//m_pTransformCom->Set_Pos(&(*m_pTransformCom->Get_Info(Engine::INFO_POS) + vDir * fTimeDelta));
	}
	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	if (D3DXVec3Length(&(*m_pTransformCom->Get_Info(Engine::INFO_POS) - m_vEndPos)) >= 0.2f)
		m_pTransformCom->Chase_Target(&m_vEndPos, 0.05f);

	return NO_EVENT;
}

void CBall::Render_GameObject(void)
{
	CStaticMeshObj::Render_GameObject();

	_matrix		matWorld;
	m_pTransformCom->Get_WorldMatrix(&matWorld);

	m_pColiderSphereCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);

}

void CBall::EndPos(_vec3 vPos)
{
	m_vEndPos = vPos;
}

HRESULT CBall::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	pComponent = m_pColiderSphereCom = Engine::CColliderSphere::Create(m_pGraphicDev,
		m_pTransformCom->Get_Info(Engine::INFO_POS), 50.f);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_ColliderSphere", pComponent);
	
	return S_OK;
}

_bool CBall::Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag)
{
	Engine::CTransform*			pPlayerTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pPlayerTransformCom, false);

	Engine::CColliderSphere*	pPlayerColliderSphereCom = dynamic_cast<Engine::CColliderSphere*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_ColliderSphere", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderSphereCom, false);


	return m_pCalculatorCom->Coliision_Sphere(pPlayerTransformCom->Get_Info(Engine::INFO_POS),
		pPlayerColliderSphereCom->Get_Radius(),
		m_pTransformCom->Get_Info(Engine::INFO_POS),
		m_pColiderSphereCom->Get_Radius());
}

CBall* CBall::Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag)
{
	CBall*	pInstance = new CBall(pGraphicDev);

	memcpy(pInstance->m_ObjTag, ObjTag.c_str(), (ObjTag.length() + 1) * sizeof(_tchar));
	memcpy(pInstance->m_MeshTag, MeshTag.c_str(), (MeshTag.length() + 1) * sizeof(_tchar));

	if (FAILED(pInstance->Ready_GameObject(iFlag)))
		Engine::Safe_Release(pInstance);
	
	return pInstance;
}

void CBall::Free(void)
{
	Engine::CGameObject::Free();
}

HRESULT CBall::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
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
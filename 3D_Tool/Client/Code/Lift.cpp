#include "stdafx.h"
#include "Lift.h"

#include "Export_Function.h"

#include "MazeWall.h"
#include "Player.h"

CLift::CLift(LPDIRECT3DDEVICE9 pGraphicDev)
	: CStaticMeshObj(pGraphicDev)
{

}

CLift::~CLift(void)
{

}

HRESULT CLift::Ready_GameObject(const _uint& iFlag)
{
	CStaticMeshObj::Ready_GameObject(iFlag);

	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	return S_OK;
}

_int CLift::Update_GameObject(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_GameObject(fTimeDelta);
	
	m_bColl = Collision_ToObject(L"GameLogic", L"Player");
	
	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	if (m_bColl)
		return CHANGE_SCENE;

	if (m_bIsDead)
		return DEAD_OBJ;

	return NO_EVENT;
}

void CLift::Render_GameObject(void)
{
	CStaticMeshObj::Render_GameObject();

	_matrix		matWorld;
	m_pTransformCom->Get_WorldMatrix(&matWorld);

	matWorld.m[3][0] += 1.f;
	matWorld.m[3][2] += 1.f;

	m_pColiderSphereCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);

}

HRESULT CLift::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	pComponent = m_pColiderSphereCom = Engine::CColliderSphere::Create(m_pGraphicDev,
		m_pTransformCom->Get_Info(Engine::INFO_POS), 100.f);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_ColliderSphere", pComponent);
	
	return S_OK;
}

_bool CLift::Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag)
{
	Engine::CTransform*			pPlayerTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pPlayerTransformCom, false);

	Engine::CColliderSphere*	pPlayerColliderSphereCom = dynamic_cast<Engine::CColliderSphere*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_ColliderSphere", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderSphereCom, false);

	_vec3 vPos = *m_pTransformCom->Get_Info(Engine::INFO_POS);

	vPos.x += 1.f;
	vPos.z += 1.f;

	return m_pCalculatorCom->Coliision_Sphere(pPlayerTransformCom->Get_Info(Engine::INFO_POS),
		pPlayerColliderSphereCom->Get_Radius(),
		&vPos,
		m_pColiderSphereCom->Get_Radius());
}

CLift* CLift::Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag)
{
	CLift*	pInstance = new CLift(pGraphicDev);

	memcpy(pInstance->m_ObjTag, ObjTag.c_str(), (ObjTag.length() + 1) * sizeof(_tchar));
	memcpy(pInstance->m_MeshTag, MeshTag.c_str(), (MeshTag.length() + 1) * sizeof(_tchar));

	if (FAILED(pInstance->Ready_GameObject(iFlag)))
		Engine::Safe_Release(pInstance);
	
	return pInstance;
}

void CLift::Free(void)
{
	Engine::CGameObject::Free();
}

HRESULT CLift::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
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
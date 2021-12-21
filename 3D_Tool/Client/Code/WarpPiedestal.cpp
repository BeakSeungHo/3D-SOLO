#include "stdafx.h"
#include "WarpPiedestal.h"

#include "Export_Function.h"

#include "MazeWall.h"
#include "Player.h"

CWarpPiedestal::CWarpPiedestal(LPDIRECT3DDEVICE9 pGraphicDev)
	: CStaticMeshObj(pGraphicDev)
{

}

CWarpPiedestal::~CWarpPiedestal(void)
{

}

HRESULT CWarpPiedestal::Ready_GameObject(const _uint& iFlag)
{
	CStaticMeshObj::Ready_GameObject(iFlag);

	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	return S_OK;
}

_int CWarpPiedestal::Update_GameObject(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_GameObject(fTimeDelta);
	
	m_bColl = Collision_ToObject(L"GameLogic", L"Player");

	if (m_bColl)
	{
		auto iter_begin = Engine::Get_Layer(L"GameLogic")->Get_MapObject()->begin();
		auto iter_end = Engine::Get_Layer(L"GameLogic")->Get_MapObject()->end();

		for (; iter_begin != iter_end; ++iter_begin)
		{
			wstring TempTag = iter_begin->first;

			_int iSearch = TempTag.find(L"MazeWall");
			
			if (iSearch >= 0)
				dynamic_cast<CMazeWall*>(iter_begin->second)->Set_Triger(true);

		}

		dynamic_cast<CPlayer*>(Engine::Get_GameObj(L"GameLogic",L"Player"))->Set_Triger(true);

	}

	//m_bDraw = m_pOptimizationCom->Is_InFrustum_ForObject(&vPos, 0.f);
		
	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);


	if (m_bIsDead)
		return DEAD_OBJ;

	return NO_EVENT;
}

void CWarpPiedestal::Render_GameObject(void)
{
	CStaticMeshObj::Render_GameObject();

	_matrix		matWorld;
	m_pTransformCom->Get_WorldMatrix(&matWorld);

	matWorld.m[3][0] += 0.5f;
	matWorld.m[3][2] -= 0.5f;

	m_pColiderSphereCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);

}

HRESULT CWarpPiedestal::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	pComponent = m_pColiderSphereCom = Engine::CColliderSphere::Create(m_pGraphicDev,
		m_pTransformCom->Get_Info(Engine::INFO_POS), 100.f);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_ColliderSphere", pComponent);
	
	return S_OK;
}

_bool CWarpPiedestal::Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag)
{
	Engine::CTransform*			pPlayerTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pPlayerTransformCom, false);

	Engine::CColliderSphere*	pPlayerColliderSphereCom = dynamic_cast<Engine::CColliderSphere*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_ColliderSphere", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderSphereCom, false);

	_vec3 vPos = *m_pTransformCom->Get_Info(Engine::INFO_POS);

	vPos.x += 0.5f;
	vPos.z -= 0.5f;

	return m_pCalculatorCom->Coliision_Sphere(pPlayerTransformCom->Get_Info(Engine::INFO_POS),
		pPlayerColliderSphereCom->Get_Radius(),
		&vPos,
		m_pColiderSphereCom->Get_Radius());
}

CWarpPiedestal* CWarpPiedestal::Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag)
{
	CWarpPiedestal*	pInstance = new CWarpPiedestal(pGraphicDev);

	memcpy(pInstance->m_ObjTag, ObjTag.c_str(), (ObjTag.length() + 1) * sizeof(_tchar));
	memcpy(pInstance->m_MeshTag, MeshTag.c_str(), (MeshTag.length() + 1) * sizeof(_tchar));

	if (FAILED(pInstance->Ready_GameObject(iFlag)))
		Engine::Safe_Release(pInstance);
	
	return pInstance;
}

void CWarpPiedestal::Free(void)
{
	Engine::CGameObject::Free();
}

HRESULT CWarpPiedestal::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
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
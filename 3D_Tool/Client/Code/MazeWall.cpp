#include "stdafx.h"
#include "MazeWall.h"

#include "Player.h"
#include "Export_Function.h"

CMazeWall::CMazeWall(LPDIRECT3DDEVICE9 pGraphicDev)
	: CStaticMeshObj(pGraphicDev)
{

}

CMazeWall::~CMazeWall(void)
{

}

HRESULT CMazeWall::Ready_GameObject(const _uint& iFlag)
{
	CStaticMeshObj::Ready_GameObject(iFlag);

	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	return S_OK;
}

_int CMazeWall::Update_GameObject(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_GameObject(fTimeDelta);

	return NO_EVENT;
}

_int CMazeWall::LateUpdate_GameObject(const _float & fTimeDelta)
{
	m_bColl = Collision_ToObject(L"GameLogic", L"Player");

	if (m_bTriger)
		m_bIsMove = true;

	if (m_bColl)
		dynamic_cast<CPlayer*>(Engine::Get_GameObj(L"GameLogic", L"Player"))->Set_bIsColl(true);

	if (m_bIsMove)
		m_pTransformCom->Set_Pos(&(*m_pTransformCom->Get_Info(Engine::INFO_POS) + (m_vOriPos - *m_pTransformCom->Get_Info(Engine::INFO_POS)) * 0.1f));
	else
		m_pTransformCom->Set_Pos(&(*m_pTransformCom->Get_Info(Engine::INFO_POS) + (m_vOriPos + m_vDir - *m_pTransformCom->Get_Info(Engine::INFO_POS)) * 0.1f));

	Engine::CGameObject::Update_GameObject(fTimeDelta);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	return NO_EVENT;
}

void CMazeWall::Render_GameObject(void)
{
	CStaticMeshObj::Render_GameObject();

	_matrix		matWorld;
	m_pTransformCom->Get_WorldMatrix(&matWorld);
			
	m_pColliderCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);

	if (m_pTransformCom->Get_Angle()->y == D3DXToRadian(90))
		matWorld.m[3][0] += 1.f;
	else
		matWorld.m[3][2] += 1.f;

	matWorld.m[3][1] += 0.5f;

	m_pColiderSphereCom->Render_Collider(Engine::COLLTYPE(m_bSphereColl), &matWorld);
}

void CMazeWall::Set_OriPos(_vec3 vOriPos)
{
	m_vOriPos = vOriPos;
}

void CMazeWall::Set_Direction(_vec3 vDir)
{
	m_vDir = vDir;
}

void CMazeWall::Set_Triger(_bool bTriger)
{
	m_bTriger = bTriger;
}

void CMazeWall::Set_Action(_bool bAction)
{
	m_bIsAction = bAction;
}

HRESULT CMazeWall::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	pComponent = m_pColliderCom = Engine::CCollider::Create(m_pGraphicDev,
		m_pMeshCom->Get_VtxPos(),
		m_pMeshCom->Get_NumVtx(),
		m_pMeshCom->Get_Stride());
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Collider", pComponent);

	pComponent = m_pColiderSphereCom = Engine::CColliderSphere::Create(m_pGraphicDev,
		m_pTransformCom->Get_Info(Engine::INFO_POS), 200.f);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_ColliderSphere", pComponent);
	
	return S_OK;
}

_bool CMazeWall::Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag)
{
	Engine::CColliderBox*	pPlayerColliderCom = dynamic_cast<Engine::CColliderBox*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Collider", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderCom, false);

	Engine::CTransform*			pPlayerTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pPlayerTransformCom, false);

	Engine::CColliderSphere*	pPlayerColliderSphereCom = dynamic_cast<Engine::CColliderSphere*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_ColliderSphere", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderSphereCom, false);

	_vec3 vPos = *m_pTransformCom->Get_Info(Engine::INFO_POS);

	if (m_pTransformCom->Get_Angle()->y == D3DXToRadian(90))
		vPos.x += 1.f;
	else
		vPos.z += 1.f;

	vPos.y += 0.5f;

	if (m_bSphereColl = m_pCalculatorCom->Coliision_Sphere(pPlayerTransformCom->Get_Info(Engine::INFO_POS),
		pPlayerColliderSphereCom->Get_Radius(),
		&vPos,
		m_pColiderSphereCom->Get_Radius()))
	{
		if(m_bIsAction)
			m_bIsMove = true;

		return m_pCalculatorCom->Collision_OBB(pPlayerColliderCom->Get_Min(),
			pPlayerColliderCom->Get_Max(),
			pPlayerColliderCom->Get_ColliderBoxMatrix(),
			m_pColliderCom->Get_Min(),
			m_pColliderCom->Get_Max(),
			m_pColliderCom->Get_ColliderMatrix());
	}
	else
	{	
		m_bIsMove = false;

		return false;
	}
}

CMazeWall* CMazeWall::Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag)
{
	CMazeWall*	pInstance = new CMazeWall(pGraphicDev);

	memcpy(pInstance->m_ObjTag, ObjTag.c_str(), (ObjTag.length() + 1) * sizeof(_tchar));
	memcpy(pInstance->m_MeshTag, MeshTag.c_str(), (MeshTag.length() + 1) * sizeof(_tchar));

	if (FAILED(pInstance->Ready_GameObject(iFlag)))
		Engine::Safe_Release(pInstance);
	
	return pInstance;
}

void CMazeWall::Free(void)
{
	Engine::CGameObject::Free();
}

HRESULT CMazeWall::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
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
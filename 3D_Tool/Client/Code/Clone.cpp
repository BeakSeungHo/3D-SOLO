#include "stdafx.h"
#include "Clone.h"

#include "Export_Function.h"

#include "Aim.h"
#include "HeavyMetal.h"

CClone::CClone(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CClone::~CClone(void)
{
}

HRESULT CClone::Ready_GameObject(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	m_pMeshCom->Set_AnimationSet(PLAYER_IDLE);

	m_pTransformCom->Set_Scale(0.01f, 0.01f, 0.01f);

	_matrix		matWorld;
	D3DXMatrixIdentity(&matWorld);
	matWorld.m[0][0] = 0.01f;
	matWorld.m[1][1] = 0.01f;
	matWorld.m[2][2] = 0.01f;

	m_pColiderSphereCom->Render_Collider(Engine::COL_FALSE, &matWorld);
	m_pColliderBoxCom->Render_Collider(Engine::COL_FALSE, &matWorld);

	return S_OK;
}

_int CClone::Update_GameObject(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_GameObject(fTimeDelta);

	m_pMeshCom->Play_Animation(fTimeDelta);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	if(m_bIsDead)
		return DEAD_OBJ;

	return NO_EVENT;
}

void CClone::Render_GameObject(void)
{
	m_pMeshCom->Play_Animation(0);

	m_pGraphicDev->SetTransform(D3DTS_WORLD, &m_pTransformCom->m_matWorld);

	_matrix		matWorld;
	m_pTransformCom->Get_WorldMatrix(&matWorld);

	m_pColiderSphereCom->Render_Collider(Engine::COL_FALSE, &matWorld);
	m_pColliderBoxCom->Render_Collider(Engine::COL_FALSE, &matWorld);


	LPD3DXEFFECT	pEffect = m_pShaderCom->Get_EffectHandle();
	NULL_CHECK(pEffect);
	pEffect->AddRef();

	_uint	iPassMax = 0;

	FAILED_CHECK_RETURN(SetUp_ConstantTable(pEffect), );

	pEffect->Begin(&iPassMax, 0);

	pEffect->BeginPass(0);

	m_pMeshCom->Render_Meshes();

	pEffect->EndPass();

	pEffect->End();

	Safe_Release(pEffect);
	
}

void CClone::Set_bIsColl(_bool bIsColl)
{
	m_bIsColl = bIsColl;
}

HRESULT CClone::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	pComponent = m_pMeshCom = dynamic_cast<Engine::CDynamicMesh*>(Engine::Clone(RESOURCE_STAGE, L"Mesh_Player"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Mesh", pComponent);


	pComponent = m_pTransformCom = Engine::CTransform::Create();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_DYNAMIC].emplace(L"Com_Transform", pComponent);

	pComponent = m_pRendererCom = Engine::Get_Renderer();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	pComponent->AddRef();
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Renderer", pComponent);

	pComponent = m_pCalculatorCom = Engine::CCalculator::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Calculator", pComponent);

	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone_Prototype(L"Shader_Mesh"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);

	pComponent = m_pColiderSphereCom = Engine::CColliderSphere::Create(m_pGraphicDev,
		m_pTransformCom->Get_Info(Engine::INFO_POS), 30.f);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_ColliderSphere", pComponent);

	// collider
	pComponent = m_pColliderBoxCom = Engine::CColliderBox::Create(m_pGraphicDev, m_pTransformCom->Get_Info(Engine::INFO_POS), &_vec3(-30.f,-30.f,-30.f), &_vec3(30.f,30.f,50.f));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Collider", pComponent);

	return S_OK;
}


HRESULT CClone::SetUp_ConstantTable(LPD3DXEFFECT & pEffect)
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


CClone* CClone::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CClone*	pInstance = new CClone(pGraphicDev);

	if (FAILED(pInstance->Ready_GameObject()))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CClone::Free(void)
{
	Engine::CGameObject::Free();
}


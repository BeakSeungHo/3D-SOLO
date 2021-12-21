#include "stdafx.h"
#include "StaticMeshObj.h"

#include "Export_Function.h"

CStaticMeshObj::CStaticMeshObj(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CStaticMeshObj::~CStaticMeshObj(void)
{

}

HRESULT CStaticMeshObj::Ready_GameObject(const _uint& iFlag)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	m_pTransformCom->Set_Scale(0.01f, 0.01f, 0.01f);

	m_pTransformCom->Set_Pos(0.f,0.f,0.f);
	
	m_iFlag = iFlag;

	return S_OK;
}

_int CStaticMeshObj::Update_GameObject(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_GameObject(fTimeDelta);

	//m_bColl = Collision_ToObject(L"GameLogic", L"Player");

	_vec3 vPos;
	m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);

	m_bDraw = m_pOptimizationCom->Is_InFrustum_ForObject(&vPos, 4.f);
		
	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);


	return 0;
}

_int CStaticMeshObj::LateUpdate_GameObject(const _float & fTimeDelta)
{
	return 0;
}

void CStaticMeshObj::Render_GameObject(void)
{
	if (false == m_bDraw)
		return;

	LPD3DXEFFECT	pEffect = m_pShaderCom->Get_EffectHandle();
	NULL_CHECK(pEffect);
	pEffect->AddRef();

	_uint	iPassMax = 0;

	FAILED_CHECK_RETURN(SetUp_ConstantTable(pEffect), );

	pEffect->Begin(&iPassMax, 0);

	m_pMeshCom->Render_Meshes(pEffect);

	pEffect->End();

	Safe_Release(pEffect);

	_matrix		matWorld;
	m_pTransformCom->Get_WorldMatrix(&matWorld);


}

void CStaticMeshObj::Set_bIsConveyor(_bool bIsConveyor)
{
	m_bIsConveyor = bIsConveyor;
}


HRESULT CStaticMeshObj::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	pComponent = m_pMeshCom = dynamic_cast<Engine::CStaticMesh*>(Engine::Clone(RESOURCE_STAGE, m_MeshTag));
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

	//// collider
	//pComponent = m_pColliderCom = Engine::CCollider::Create(m_pGraphicDev,
	//	m_pMeshCom->Get_VtxPos(),
	//	m_pMeshCom->Get_NumVtx(),
	//	m_pMeshCom->Get_Stride());
	//NULL_CHECK_RETURN(pComponent, );
	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Collider", pComponent);

	pComponent = m_pOptimizationCom = dynamic_cast<Engine::COptimization*>
										(Engine::Clone_Prototype(L"Proto_Optimization"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Optimization", pComponent);
	
	return S_OK;
}

_bool CStaticMeshObj::Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag)
{
	Engine::CCollider*	pPlayerColliderCom = dynamic_cast<Engine::CCollider*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Collider", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderCom, false);
	
	return false;
	//if(0 == m_iFlag)
	//	return m_pCalculatorCom->Collision_OBB(pPlayerColliderCom->Get_Min(),
	//										pPlayerColliderCom->Get_Max(),
	//										pPlayerColliderCom->Get_ColliderMatrix(),
	//										m_pColliderCom->Get_Min(),
	//										m_pColliderCom->Get_Max(),
	//										m_pColliderCom->Get_ColliderMatrix());


	//else
	//	return m_pCalculatorCom->Collision_AABB(pPlayerColliderCom->Get_Min(),
	//										pPlayerColliderCom->Get_Max(),
	//										pPlayerColliderCom->Get_ColliderMatrix(), 
	//										m_pColliderCom->Get_Min(), 
	//										m_pColliderCom->Get_Max(), 
	//										m_pColliderCom->Get_ColliderMatrix());
}

CStaticMeshObj* CStaticMeshObj::Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag)
{
	CStaticMeshObj*	pInstance = new CStaticMeshObj(pGraphicDev);

	memcpy(pInstance->m_ObjTag, ObjTag.c_str(), (ObjTag.length() + 1) * sizeof(_tchar));
	memcpy(pInstance->m_MeshTag, MeshTag.c_str(), (MeshTag.length() + 1) * sizeof(_tchar));

	if (FAILED(pInstance->Ready_GameObject(iFlag)))
		Engine::Safe_Release(pInstance);
	
	return pInstance;
}

void CStaticMeshObj::Free(void)
{
	Engine::CGameObject::Free();
}

HRESULT CStaticMeshObj::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
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
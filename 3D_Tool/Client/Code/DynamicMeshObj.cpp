#include "stdafx.h"
#include "DynamicMeshObj.h"

#include "Export_Function.h"

CDynamicMeshObj::CDynamicMeshObj(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CDynamicMeshObj::~CDynamicMeshObj(void)
{

}

HRESULT CDynamicMeshObj::Ready_GameObject(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	//m_pMeshCom->Set_AnimationSet(57);

	//m_pNaviCom->Set_Index(0);

	m_pTransformCom->Set_Scale(1.f, 1.f, 1.f);
	m_pTransformCom->Set_Pos(0.01f, 0.01f, 0.01f);

	return S_OK;
}

_int CDynamicMeshObj::Update_GameObject(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_GameObject(fTimeDelta);

	//m_pMeshCom->Play_Animation(fTimeDelta);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);


	return 0;
}

void CDynamicMeshObj::Render_GameObject(void)
{
	m_pGraphicDev->SetTransform(D3DTS_WORLD, &m_pTransformCom->m_matWorld);

	m_pMeshCom->Render_Meshes();

	//_matrix		matWorld;
	//m_pTransformCom->Get_WorldMatrix(&matWorld);

	//m_pColliderCom->Render_Collider(Engine::COL_FALSE, &matWorld);	
	
}

void CDynamicMeshObj::SaveData(HANDLE hFile)
{
	_ulong dwByte = 0;


	_int iTagSize = (lstrlen(m_MeshTag) + 1) * sizeof(_tchar);

	WriteFile(hFile, &iTagSize, sizeof(_int), &dwByte, nullptr);
	WriteFile(hFile, m_MeshTag, iTagSize * sizeof(_tchar), &dwByte, nullptr);

	WriteFile(hFile, m_pTransformCom->Get_Scale(), sizeof(_vec3), &dwByte, nullptr);
	WriteFile(hFile, m_pTransformCom->Get_Angle(), sizeof(_vec3), &dwByte, nullptr);

	WriteFile(hFile, m_pTransformCom->Get_Info(Engine::INFO_POS), sizeof(_vec3), &dwByte, nullptr);

	return;
}

HRESULT CDynamicMeshObj::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	pComponent = m_pMeshCom = dynamic_cast<Engine::CDynamicMesh*>(Engine::Clone(RESOURCE_STAGE, m_MeshTag));
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
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Collider", pComponent);

	return S_OK;
}

CDynamicMeshObj* CDynamicMeshObj::Create(LPDIRECT3DDEVICE9 pGraphicDev, wstring MeshTag, wstring ObjTag)
{
	CDynamicMeshObj*	pInstance = new CDynamicMeshObj(pGraphicDev);

	memcpy(pInstance->m_ObjTag, ObjTag.c_str(), (ObjTag.length() + 1) * sizeof(_tchar));
	memcpy(pInstance->m_MeshTag, MeshTag.c_str(), (MeshTag.length() + 1) * sizeof(_tchar));

	if (FAILED(pInstance->Ready_GameObject()))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CDynamicMeshObj::Free(void)
{


	Engine::CGameObject::Free();
}
#include "stdafx.h"
#include "LoadPlayer.h"

#include "Export_Function.h"

CLoadPlayer::CLoadPlayer(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CLoadPlayer::~CLoadPlayer(void)
{
}

HRESULT CLoadPlayer::Ready_GameObject(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	m_pMeshCom->Set_AnimationSet(27);

	m_pTransformCom->m_vScale.x = 0.005f;
	m_pTransformCom->m_vScale.y = 0.005f;
	m_pTransformCom->m_vScale.z = 0.005f;
	m_pTransformCom->Set_Pos(-0.6f, -0.6f, 0.1f);

	m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(90.f));

	return S_OK;
}

_int CLoadPlayer::Update_GameObject(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_GameObject(fTimeDelta);
	
	m_pMeshCom->Play_Animation(fTimeDelta);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_UI, this);

	if(m_bIsDead)
		return DEAD_OBJ;

	return NO_EVENT;
}

void CLoadPlayer::Render_GameObject(void)
{
	//m_pGraphicDev->SetTransform(D3DTS_WORLD, &m_pTransformCom->m_matWorld);

	LPD3DXEFFECT	pEffect = m_pShaderCom->Get_EffectHandle();
	NULL_CHECK(pEffect);
	pEffect->AddRef();

	_uint	iPassMax = 0;

	FAILED_CHECK_RETURN(SetUp_ConstantTable(pEffect), );

	pEffect->Begin(&iPassMax, 0);

	pEffect->BeginPass(2);

	m_pMeshCom->Render_Meshes();

	pEffect->EndPass();

	pEffect->End();

	Safe_Release(pEffect);
	
}


HRESULT CLoadPlayer::Add_Component(void)
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

	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone_Prototype(L"Shader_UI"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);

	return S_OK;
}

HRESULT CLoadPlayer::SetUp_ConstantTable(LPD3DXEFFECT & pEffect)
{
	_matrix			matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	//m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	//m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	D3DXMatrixIdentity(&matView);
	D3DXMatrixIdentity(&matProj);

	//D3DXMatrixOrthoLH(&matProj, WINCX, WINCY, 1.f, 1000.f);

	//matProj.m[0][0] = 2.f / WINCX;
	//matProj.m[1][1] = 2.f / WINCY;
	//matProj.m[2][2] = 1.f / (1000.f - 1.f);
	//matProj.m[3][2] = -1.f * matProj.m[2][2];

	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);

	return S_OK;
}


CLoadPlayer* CLoadPlayer::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CLoadPlayer*	pInstance = new CLoadPlayer(pGraphicDev);

	if (FAILED(pInstance->Ready_GameObject()))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CLoadPlayer::Free(void)
{
	Engine::CGameObject::Free();
}


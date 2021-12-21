#include "stdafx.h"
#include "CloneEffect.h"

#include "Player.h"

#include "Export_Function.h"

CCloneEffect::CCloneEffect(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CCloneEffect::~CCloneEffect(void)
{

}

HRESULT CCloneEffect::Ready_GameObject(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	m_pTransformCom->Set_Scale(8.f,8.f,8.f);

	m_pTransformCom->Rotation(Engine::ROT_X, D3DXToRadian(90));

	return S_OK;
}

_int CCloneEffect::Update_GameObject(const _float& fTimeDelta)
{
	if(nullptr == m_pPlayer)
		m_pPlayer = dynamic_cast<CPlayer*>(Engine::Get_GameObj(L"GameLogic", L"Player"));

	m_fFrameCnt += m_fFrameMax * fTimeDelta;

	if (m_fFrameCnt >= m_fFrameMax)
	{
		m_fFrameCnt = 0.f;
	}
		

	Engine::CGameObject::Update_GameObject(fTimeDelta);	

	
	_vec3 vPos = *dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC))->Get_Info(Engine::INFO_POS);
	_vec3 vLook = *dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC))->Get_Info(Engine::INFO_LOOK);
	D3DXVec3Normalize(&vLook, &vLook);

	
	
	_matrix	matWorld, matView, matBill;
	
	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);

	D3DXMatrixIdentity(&matBill);

	matBill._11 = matView._11;
	matBill._13 = matView._13;
	matBill._31 = matView._31;
	matBill._33 = matView._33;

	D3DXMatrixInverse(&matBill, NULL, &matBill);

	m_pTransformCom->Set_WorldMatrix(&(matBill * matWorld));

	Engine::CGameObject::Compute_ViewZ(&m_pTransformCom->m_vInfo[Engine::INFO_POS]);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_ALPHA, this);

	return 0;
}

void CCloneEffect::Render_GameObject(void)
{

	LPD3DXEFFECT	Effect = m_pShaderCom->Get_EffectHandle();
	NULL_CHECK(Effect);
	Effect->AddRef();

	_uint	iPassMax = 0;

	FAILED_CHECK_RETURN(SetUp_ConstantTable(Effect), );

	Effect->Begin(&iPassMax, 0);

	Effect->BeginPass(0);

	m_pBufferCom->Render_Buffer();

	Effect->EndPass();

	Effect->End();

	Safe_Release(Effect);
}

HRESULT CCloneEffect::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	pComponent = m_pBufferCom = dynamic_cast<Engine::CRcTex*>(Engine::Clone(RESOURCE_STATIC, L"Buffer_RcTex"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	pComponent = m_pTransformCom = Engine::CTransform::Create();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_DYNAMIC].emplace(L"Com_Transform", pComponent);

	pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(RESOURCE_STAGE, L"Texture_Aim"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Texture", pComponent);

	pComponent = m_pRendererCom = Engine::Get_Renderer();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	pComponent->AddRef();
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Renderer", pComponent);
	
	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone_Prototype(L"Shader_Effect"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);
	
	return S_OK;
}



HRESULT CCloneEffect::SetUp_ConstantTable(LPD3DXEFFECT& Effect)
{
	_matrix			matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	Effect->SetMatrix("g_matWorld", &matWorld);
	Effect->SetMatrix("g_matView", &matView);
	Effect->SetMatrix("g_matProj", &matProj);

	m_pTextureCom->Set_Texture(Effect, "g_BaseTexture");
	Engine::SetUp_OnShader(Effect, L"Target_Depth", "g_DepthTexture");

	return S_OK;
}

CCloneEffect* CCloneEffect::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CCloneEffect*	pInstance = new CCloneEffect(pGraphicDev);

	if (FAILED(pInstance->Ready_GameObject()))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CCloneEffect::Free(void)
{


	Engine::CGameObject::Free();
}


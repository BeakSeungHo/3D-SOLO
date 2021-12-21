#include "stdafx.h"
#include "Laser.h"

#include "StaticCamera.h"
#include "Robot.h"
#include "Player.h"

#include "Export_Function.h"

CLaser::CLaser(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CLaser::~CLaser(void)
{

}

HRESULT CLaser::Ready_GameObject(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	D3DXCreateLine(m_pGraphicDev, &m_pLine);

	return S_OK;
}

_int CLaser::Update_GameObject(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_GameObject(fTimeDelta);	

	
	if(m_bIsDead)
		return DEAD_OBJ;

	return NO_EVENT;
}

void CLaser::Render_GameObject(void)
{

	LPD3DXEFFECT	pEffect = m_pShaderCom->Get_EffectHandle();
	NULL_CHECK(pEffect);
	pEffect->AddRef();

	_uint	iPassMax = 0;

	FAILED_CHECK_RETURN(SetUp_ConstantTable(pEffect), );

	pEffect->Begin(&iPassMax, 0);

	pEffect->BeginPass(0);

	m_pLine->SetWidth(3.f);

	//m_pLine->Begin();

	_matrix		matWorld, ViewMat, ProjMat, LineMat;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	ViewMat = *dynamic_cast<CStaticCamera*>(Engine::Get_GameObj(L"GameLogic", L"StaticCamera"))->Get_ViewSpace();
	ProjMat = *dynamic_cast<CStaticCamera*>(Engine::Get_GameObj(L"GameLogic", L"StaticCamera"))->Get_Projection();
	LineMat = matWorld * ViewMat * ProjMat;

	//m_pBufferCom->Render_Buffer();
	
	m_pLine->DrawTransform(m_vLaser, 2, &LineMat, D3DCOLOR_XRGB(255, 0, 0));

	//m_pLine->End();

	pEffect->EndPass();

	pEffect->End();

	Safe_Release(pEffect);

	
	m_pColiderBoxCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);
}

HRESULT CLaser::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	pComponent = m_pCalculatorCom = Engine::CCalculator::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Calculator", pComponent);

	pComponent = m_pTransformCom = Engine::CTransform::Create();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_DYNAMIC].emplace(L"Com_Transform", pComponent);

	pComponent = m_pRendererCom = Engine::Get_Renderer();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	pComponent->AddRef();
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Renderer", pComponent);
	
	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone_Prototype(L"Shader_Effect"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);

	pComponent = m_pNaviCom = dynamic_cast<Engine::CNaviMesh*>(Engine::Clone(RESOURCE_STAGE, L"Mesh_Navi"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Navi", pComponent);

	return S_OK;
}


HRESULT CLaser::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
{
	_matrix			matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);

	Engine::SetUp_OnShader(pEffect, L"Target_Depth", "g_DepthTexture");

	return S_OK;
}

CLaser* CLaser::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CLaser*	pInstance = new CLaser(pGraphicDev);

	if (FAILED(pInstance->Ready_GameObject()))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CLaser::Free(void)
{
	m_pLine->Release();
	Engine::CGameObject::Free();
}


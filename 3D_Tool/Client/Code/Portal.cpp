#include "stdafx.h"
#include "Portal.h"

#include "Export_Function.h"
#include "Shiny.h"

CPortal::CPortal(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CPortal::~CPortal(void)
{

}

HRESULT CPortal::Ready_GameObject(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	m_pTransformCom->Set_Scale(1.f,1.f,1.f);
	m_pTransformCom->FixingRotation(Engine::ROT_X, D3DXToRadian(90));

	return S_OK;
}

_int CPortal::Update_GameObject(const _float& fTimeDelta)
{
	m_fFrameCnt += m_fFrameMax * fTimeDelta;

	if (m_fFrameCnt >= m_fFrameMax)
	{
		m_fFrameCnt = 0.f;
	}

	if (m_bIsMove == true)
	{
		m_fTimeAcc += fTimeDelta;

		if (m_fTimeAcc > 5)
		{
			m_pTransformCom->Set_Pos(38.f + 1.5f * m_iMoveCount, 2.f, 21.f);
			m_fTimeAcc = 0;
			++m_iMoveCount;
		}
		if(m_iMoveCount > 2)
			m_iMoveCount = 0;
	}
	else if (m_bIsMove == false)
	{
		Collision_ToObject(L"GameLogic");
	}

	Engine::CGameObject::Update_GameObject(fTimeDelta);	

	//_matrix	matWorld, matView, matBill;
	//
	//m_pTransformCom->Get_WorldMatrix(&matWorld);
	//m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);

	//D3DXMatrixIdentity(&matBill);

	//matBill._11 = matView._11;
	//matBill._13 = matView._13;
	//matBill._31 = matView._31;
	//matBill._33 = matView._33;

	//D3DXMatrixInverse(&matBill, NULL, &matBill);

	//m_pTransformCom->Set_WorldMatrix(&(matBill * matWorld));	

	Engine::CGameObject::Compute_ViewZ(&m_pTransformCom->m_vInfo[Engine::INFO_POS]);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_ALPHA, this);

	return 0;
}

void CPortal::Render_GameObject(void)
{

	LPD3DXEFFECT	pEffect = m_pShaderCom->Get_EffectHandle();
	NULL_CHECK(pEffect);
	pEffect->AddRef();

	_uint	iPassMax = 0;

	FAILED_CHECK_RETURN(SetUp_ConstantTable(pEffect), );

	pEffect->Begin(&iPassMax, 0);

	pEffect->BeginPass(0);

	m_pBufferCom->Render_Buffer();

	pEffect->EndPass();

	pEffect->End();

	Safe_Release(pEffect);

	_matrix		matWorld;
	m_pTransformCom->Get_WorldMatrix(&matWorld);

	m_pColiderSphereCom->Render_Collider(Engine::COL_FALSE, &matWorld);
}

void CPortal::Set_bIsMove(_bool bIsMove)
{
	m_bIsMove = bIsMove;
}

void CPortal::Set_MaxFrame(_float fMaxFrame)
{
	m_fFrameMax = fMaxFrame;
}

HRESULT CPortal::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	pComponent = m_pBufferCom = dynamic_cast<Engine::CRcTex*>(Engine::Clone(RESOURCE_STATIC, L"Buffer_RcTex"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	pComponent = m_pTransformCom = Engine::CTransform::Create();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_DYNAMIC].emplace(L"Com_Transform", pComponent);

	pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(RESOURCE_STAGE, m_TexTag));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Texture", pComponent);

	pComponent = m_pRendererCom = Engine::Get_Renderer();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	pComponent->AddRef();
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Renderer", pComponent);
	
	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone_Prototype(L"Shader_Effect"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);
	
	pComponent = m_pCalculatorCom = Engine::CCalculator::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Calculator", pComponent);

	pComponent = m_pColiderSphereCom = Engine::CColliderSphere::Create(m_pGraphicDev,
		m_pTransformCom->Get_Info(Engine::INFO_POS), 10.f);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_ColliderSphere", pComponent);

	return S_OK;
}

_bool CPortal::Collision_ToObject(const _tchar * pLayerTag)
{

	Engine::CTransform* pObjTransform = nullptr;
	Engine::CColliderSphere* pObjColiderSphere = nullptr;

	auto iter_begin = Engine::Get_Layer(L"GameLogic")->Get_MapObject()->begin();
	auto iter_end = Engine::Get_Layer(L"GameLogic")->Get_MapObject()->end();

	for (; iter_begin != iter_end; ++iter_begin)
	{
		wstring temp = iter_begin->first;
		_int iSearch = temp.find(L"HatchShiny_");

		if (iSearch >= 0)
		{	
			pObjTransform = dynamic_cast<Engine::CTransform*>(iter_begin->second->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
			pObjColiderSphere = dynamic_cast<Engine::CColliderSphere*>(iter_begin->second->Get_Component(L"Com_ColliderSphere", Engine::ID_STATIC));

			if (m_pCalculatorCom->Coliision_Sphere(pObjTransform->Get_Info(Engine::INFO_POS), pObjColiderSphere->Get_Radius(),
													m_pTransformCom->Get_Info(Engine::INFO_POS), m_pColiderSphereCom->Get_Radius()))
			{
				dynamic_cast<CShiny*>(iter_begin->second)->Set_Lerp(false);
				pObjTransform->Set_Pos(dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic",L"Portal_1", L"Com_Transform", Engine::ID_DYNAMIC))->Get_Info(Engine::INFO_POS));
			
				return true;
			}
		}
	}

	return false;
}



HRESULT CPortal::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
{
	_matrix			matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);

	m_pTextureCom->Set_Texture(pEffect, "g_BaseTexture", _uint(m_fFrameCnt));
	Engine::SetUp_OnShader(pEffect, L"Target_Depth", "g_DepthTexture");

	return S_OK;
}

CPortal* CPortal::Create(LPDIRECT3DDEVICE9 pGraphicDev, wstring TexTag)
{
	CPortal*	pInstance = new CPortal(pGraphicDev);

	memcpy(pInstance->m_TexTag, TexTag.c_str(), (TexTag.length() + 1) * sizeof(_tchar));

	if (FAILED(pInstance->Ready_GameObject()))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CPortal::Free(void)
{


	Engine::CGameObject::Free();
}


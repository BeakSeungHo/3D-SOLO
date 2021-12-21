#include "stdafx.h"
#include "Terrain.h"
#include "Player.h"

#include "Export_Function.h"
#include "SoundMgr.h"

CTerrain::CTerrain(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CTerrain::~CTerrain(void)
{

}

HRESULT CTerrain::Ready_GameObject(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	m_pTransformCom->Set_Scale(0.8f,0.8f,0.8f);

	m_pIndex = new Engine::INDEX32[m_pBufferCom->Get_TriCnt()];

	return S_OK;
}

_int CTerrain::Update_GameObject(const _float& fTimeDelta)
{
	_int iExit = Engine::CGameObject::Update_GameObject(fTimeDelta);

	if (m_iBufferCount >= 3 && m_bIsDraw && m_iBufferCount < 8)
		m_bColl = Collision_ToObject(L"GameLogic", L"Player");

	if (m_iBufferCount == 3 && m_bColl == true)
	{
		dynamic_cast<CTerrain*>(Engine::Get_GameObj(L"GameLogic",L"Terrain_4"))->SetDraw(true);
		dynamic_cast<CTerrain*>(Engine::Get_GameObj(L"GameLogic", L"Terrain_5"))->SetDraw(true);
		dynamic_cast<CTerrain*>(Engine::Get_GameObj(L"GameLogic", L"Terrain_6"))->SetDraw(true);
		dynamic_cast<CTerrain*>(Engine::Get_GameObj(L"GameLogic", L"Terrain_7"))->SetDraw(true);
		m_bIsDraw = false;
	}

	if (m_iBufferCount > 3 && m_bColl == true && m_bBlink != true)
	{
		m_bBlink = true;

		switch (m_iBufferCount)
		{
			case 4:
				CSoundMgr::GetInstance()->PlaySound(L"simon_a.ogg", CSoundMgr::EFFECT);
				break;
			case 5:
				CSoundMgr::GetInstance()->PlaySound(L"simon_c.ogg", CSoundMgr::EFFECT);
				break;
			case 6:
				CSoundMgr::GetInstance()->PlaySound(L"simon_d.ogg", CSoundMgr::EFFECT);
				break;
			case 7:
				CSoundMgr::GetInstance()->PlaySound(L"simon_e.ogg", CSoundMgr::EFFECT);
				break;
			default:
				break;
		}

		dynamic_cast<CPlayer*>(Engine::Get_GameObj(L"GameLogic", L"Player"))->InputTile(m_iBufferCount);
	}
		

	//m_pOptimizationCom->Is_InFrustum_ForTerrain(m_pBufferCom->Get_VtxPos(),
	//											m_pBufferCom->Get_VtxCntX(), 
	//											m_pBufferCom->Get_VtxCntZ(), 
	//											m_pIndex, 
	//											&m_dwTriCnt);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	return iExit;
}

void CTerrain::Render_GameObject(void)
{
	if(m_bIsDraw != true)
		return;
	
	LPD3DXEFFECT	pEffect = m_pShaderCom->Get_EffectHandle();
	NULL_CHECK(pEffect);
	pEffect->AddRef();

	_uint	iPassMax = 0;
	_uint	iPass = 0;

	if (m_bBlink)
	{
		iPass = 1;
		BlinkTile();
		pEffect->SetFloat("g_fAlpha", m_fAlphaAcc);
	}
		
		
	FAILED_CHECK_RETURN(SetUp_ConstantTable(pEffect), );

	pEffect->Begin(&iPassMax, 0);

	pEffect->BeginPass(iPass);

	m_pBufferCom->Render_Buffer();

	pEffect->EndPass();

	pEffect->End();

	Safe_Release(pEffect);

	if (m_iBufferCount >= 3 && m_iBufferCount < 8)
	{
		_matrix		matWorld;
		m_pTransformCom->Get_WorldMatrix(&matWorld);

		matWorld.m[3][0] += 0.5f;
		matWorld.m[3][2] += 0.5f;

		m_pColiderSphereCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);
	}
}

void CTerrain::BlinkTile()
{
	m_iTexCount = 4;
	m_fAlphaAcc -= 0.1f;
	if (m_fAlphaAcc <= 0)
	{
		m_fAlphaAcc = 1.f;
		++m_iBlinkCount;
	}
	if (m_iBlinkCount > 3 && m_iBufferCount > 3)
	{
		m_bBlink = false;
		m_iBlinkCount = 0;
		m_iTexCount = 2;
	}
}

void CTerrain::SetTexCount(_int iCount)
{
	m_iTexCount = iCount;
}

void CTerrain::SetDraw(_bool bDraw)
{
	m_bIsDraw = bDraw;
}

void CTerrain::SetBlinkTile(_bool bBlink)
{
	m_bBlink = bBlink;
}

HRESULT CTerrain::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	wstring Tag = L"Buffer_TerrainTex_";
	Tag += to_wstring(m_iBufferCount);

	pComponent = m_pBufferCom = dynamic_cast<Engine::CTerrainTex*>(Engine::Clone(RESOURCE_STATIC, Tag.c_str()));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	pComponent = m_pTransformCom = Engine::CTransform::Create();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_DYNAMIC].emplace(L"Com_Transform", pComponent);

	pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(RESOURCE_STAGE, L"Texture_Terrain"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Texture", pComponent);

	pComponent = m_pRendererCom = Engine::Get_Renderer();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	pComponent->AddRef();
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Renderer", pComponent);

	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone_Prototype(L"Shader_Terrain"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);

	if (m_iBufferCount > 3 && m_iBufferCount < 8)
		m_bIsDraw = false;

	if (m_iBufferCount == 3)
		m_bBlink = true;

	if (m_iBufferCount >= 3 && m_iBufferCount < 8)
	{
		Engine::CComponent*		pComponent = nullptr;

		pComponent = m_pCalculatorCom = Engine::CCalculator::Create(m_pGraphicDev);
		NULL_CHECK_RETURN(pComponent, E_FAIL);
		m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Calculator", pComponent);

		pComponent = m_pColiderSphereCom = Engine::CColliderSphere::Create(m_pGraphicDev,
			&(*m_pTransformCom->Get_Info(Engine::INFO_POS) + _vec3(0.5f, 0.f, 0.5f)), 0.5f);
		NULL_CHECK_RETURN(pComponent, E_FAIL);
		m_mapComponent[Engine::ID_STATIC].emplace(L"Com_ColliderSphere", pComponent);
	}

	pComponent = m_pOptimizationCom = dynamic_cast<Engine::COptimization*>
		(Engine::Clone_Prototype(L"Proto_Optimization"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Optimization", pComponent);
	
	return S_OK;
}

HRESULT CTerrain::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
{
	_matrix			matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);

	m_pTextureCom->Set_Texture(pEffect, "g_BaseTexture", m_iTexCount);

	pEffect->SetFloat("g_fDetail", 1.f);

	return S_OK;
}

_bool CTerrain::Collision_ToObject(const _tchar * pLayerTag, const _tchar * pObjTag)
{
	Engine::CTransform*			pPlayerTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pPlayerTransformCom, false);

	Engine::CColliderSphere*	pPlayerColliderSphereCom = dynamic_cast<Engine::CColliderSphere*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_ColliderSphere", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderSphereCom, false);


	return m_pCalculatorCom->Coliision_Sphere(pPlayerTransformCom->Get_Info(Engine::INFO_POS),
		pPlayerColliderSphereCom->Get_Radius(),
		&(*m_pTransformCom->Get_Info(Engine::INFO_POS) + _vec3(0.5f, 0.f, 0.5f)),
		m_pColiderSphereCom->Get_Radius());
}



CTerrain* CTerrain::Create(LPDIRECT3DDEVICE9 pGraphicDev, _int BufferCount)
{
	CTerrain*	pInstance = new CTerrain(pGraphicDev);

	pInstance->m_iBufferCount = BufferCount;

	if (FAILED(pInstance->Ready_GameObject()))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CTerrain::Free(void)
{
	Engine::Safe_Delete_Array(m_pIndex);

	Engine::CGameObject::Free();
}


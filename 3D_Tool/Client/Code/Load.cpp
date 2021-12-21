#include "stdafx.h"
#include "Load.h"
#include "Stage.h"

#include "LoadPlayer.h"

#include "Export_Function.h"
#include "SoundMgr.h"

CLoad::CLoad(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CScene(pGraphicDev)
{

}

CLoad::~CLoad(void)
{

}

HRESULT CLoad::Ready_Scene(void)
{
	FAILED_CHECK_RETURN(Engine::CScene::Ready_Scene(), E_FAIL);
	FAILED_CHECK_RETURN(Ready_Resource(m_pGraphicDev, RESOURCE_END), E_FAIL);

	FAILED_CHECK_RETURN(Ready_GameLogic_Layer(L"GameLogic"), E_FAIL);

	m_pLoading = CLoading::Create(m_pGraphicDev, LOADING_STAGE);
	NULL_CHECK_RETURN(m_pLoading, E_FAIL);

	return S_OK;
}

_int CLoad::Update_Scene(const _float& fTimeDelta)
{
	_int iExit = Engine::CScene::Update_Scene(fTimeDelta);

	if (true == m_pLoading->Get_Finish())
	{
		Engine::CScene*		pScene = CStage::Create(m_pGraphicDev);
		NULL_CHECK_RETURN(pScene, E_FAIL);

		FAILED_CHECK_RETURN(Engine::SetUp_Scene(pScene), E_FAIL);

		return iExit;
	}
	return iExit;
}

_int CLoad::LateUpdate_Scene(const _float & fTimeDelta)
{
	_int iExit = Engine::CScene::LateUpdate_Scene(fTimeDelta);

	return iExit;
}

void CLoad::Render_Scene(void)
{
	// DEBUG ¿ë
	//Engine::Render_Font(L"Font_Default", m_pLoading->Get_LoadString(), &_vec2(10.f, 10.f), D3DXCOLOR(1.f, 0.f, 0.f, 1.f));
	Engine::Render_Font(L"Font_Default", L"LOADING ...", &_vec2(250.f, 380.f), D3DXCOLOR(1.f, 1.f, 1.f, 1.f));
}

CLoad* CLoad::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CLoad*	pInstance = new CLoad(pGraphicDev);

	if (FAILED(pInstance->Ready_Scene()))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CLoad::Free(void)
{
	Engine::Safe_Release(m_pLoading);
	Engine::CScene::Free();
}

HRESULT CLoad::Ready_GameLogic_Layer(const _tchar* pLayerTag)
{
	Engine::CLayer*		pLayer = Engine::CLayer::Create();
	NULL_CHECK_RETURN(pLayer, E_FAIL);

	pLayer->Reset_Object();

	Engine::CGameObject*		pGameObject = nullptr;

	// BackGround
	pGameObject = CBackGround::Create(m_pGraphicDev, L"Texture_Back_1");
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"BackGround", pGameObject), E_FAIL);

	pGameObject = CLoadPlayer::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"LoadPlayer", pGameObject), E_FAIL);

	m_mapLayer.emplace(pLayerTag, pLayer);

	return S_OK;
}

HRESULT CLoad::Ready_Resource(LPDIRECT3DDEVICE9& pGraphicDev, RESOURCEID eMax)
{

	FAILED_CHECK_RETURN(Engine::Ready_Texture(pGraphicDev,
		RESOURCE_LOGO,
		L"Texture_Back_1",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/Loading/LoadingScreen.tga"),
		E_FAIL);

	return S_OK;
}

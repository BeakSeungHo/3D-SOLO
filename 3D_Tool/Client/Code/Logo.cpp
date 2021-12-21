#include "stdafx.h"
#include "Logo.h"

#include "Smoke.h"
#include "BackGround.h"
#include "Button.h"
#include "Load.h"

#include "Export_Function.h"
#include "SoundMgr.h"

CLogo::CLogo(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CScene(pGraphicDev)
{

}

CLogo::~CLogo(void)
{

}

HRESULT CLogo::Ready_Scene(void)
{
	FAILED_CHECK_RETURN(Engine::CScene::Ready_Scene(), E_FAIL);
	FAILED_CHECK_RETURN(Ready_Resource(m_pGraphicDev, RESOURCE_END), E_FAIL);

	FAILED_CHECK_RETURN(Ready_GameLogic_Layer(L"GameLogic"), E_FAIL);

	CSoundMgr::GetInstance()->PlayBGM(L"WarpMusic_HighIntensity.ogg");

	return S_OK;
}

_int CLogo::Update_Scene(const _float& fTimeDelta)
{
	_int iExit = Engine::CScene::Update_Scene(fTimeDelta);

	Key_Input();
	

	return iExit;
}

_int CLogo::LateUpdate_Scene(const _float & fTimeDelta)
{
	_int iExit = Engine::CScene::LateUpdate_Scene(fTimeDelta);

	return iExit;
}

void CLogo::Render_Scene(void)
{
	// DEBUG 용
	//Engine::Render_Font(L"Font_Default", m_pLoading->Get_LoadString(), &_vec2(10.f, 10.f), D3DXCOLOR(1.f, 0.f, 0.f, 1.f));

}

CLogo* CLogo::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CLogo*	pInstance = new CLogo(pGraphicDev);

	if (FAILED(pInstance->Ready_Scene()))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CLogo::Free(void)
{
	Engine::CScene::Free();
}

HRESULT CLogo::Ready_GameLogic_Layer(const _tchar* pLayerTag)
{
	Engine::CLayer*		pLayer = Engine::CLayer::Create();
	NULL_CHECK_RETURN(pLayer, E_FAIL);

	pLayer->Reset_Object();

	Engine::CGameObject*		pGameObject = nullptr;
	CSmoke*						pSmoke = nullptr;
	// BackGround

	_int SmokeCount = 0;
	wstring SmokeTag = L"";
	for (_int i = 0; i < 4; ++i)
	{
		for (_int j = 0; j < 4; ++j)
		{
			SmokeTag = L"Somke" + to_wstring(SmokeCount);
			pSmoke = CSmoke::Create(m_pGraphicDev, SmokeTag);
			NULL_CHECK_RETURN(pSmoke, E_FAIL);
			FAILED_CHECK_RETURN(pLayer->Add_GameObject(pSmoke->Get_ObjTag(), pSmoke), E_FAIL);
			dynamic_cast<Engine::CTransform*>(pSmoke->Get_Component(L"Com_Transform",Engine::ID_DYNAMIC))->Set_Pos(&_vec3(-1.f + i * 0.6f ,-1.f + j * 0.6f,0.8f));
			++SmokeCount;
		}
	}



	pGameObject = CBackGround::Create(m_pGraphicDev, L"Texture_Back_0");
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"BackGround", pGameObject), E_FAIL);

	pGameObject = CBackGround::Create(m_pGraphicDev, L"Texture_Logo");
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Logo", pGameObject), E_FAIL);
	dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Scale(0.8f,0.8f,0.f);
	dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(0.f,0.6f,0.f);

	pGameObject = CButton::Create(m_pGraphicDev, L"Texture_NewGame");
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"NewGame", pGameObject), E_FAIL);
	dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(0.f, 0.f, 0.f);
	dynamic_cast<CButton*>(pGameObject)->Set_TexCnt(1);
	vecButton.push_back(pGameObject);

	pGameObject = CButton::Create(m_pGraphicDev, L"Texture_Challenge");
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Challenge", pGameObject), E_FAIL);
	dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(0.f, -0.2f, 0.f);
	vecButton.push_back(pGameObject);

	pGameObject = CButton::Create(m_pGraphicDev, L"Texture_HelpOption");
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"HelpOption", pGameObject), E_FAIL);
	dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(0.f, -0.4f, 0.f);
	vecButton.push_back(pGameObject);

	pGameObject = CButton::Create(m_pGraphicDev, L"Texture_LeaderBoard");
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"LeaderBoard", pGameObject), E_FAIL);
	dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(0.f, -0.6f, 0.f);
	vecButton.push_back(pGameObject);

	pGameObject = CButton::Create(m_pGraphicDev, L"Texture_Exit");
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Exit", pGameObject), E_FAIL);
	dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(0.f, -0.8f, 0.f);
	vecButton.push_back(pGameObject);

	m_mapLayer.emplace(pLayerTag, pLayer);

	return S_OK;
}

HRESULT CLogo::Ready_Resource(LPDIRECT3DDEVICE9& pGraphicDev, RESOURCEID eMax)
{
	// 메모리 예약
	Engine::Reserve_ContainerSize(eMax);

	FAILED_CHECK_RETURN(Engine::Ready_Buffer(pGraphicDev,
		RESOURCE_STATIC,
		L"Buffer_RcTex",
		Engine::BUFFER_RCTEX),
		E_FAIL);

	// 텍스쳐
	FAILED_CHECK_RETURN(Engine::Ready_Texture(pGraphicDev,
		RESOURCE_LOGO,
		L"Texture_Back_0",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/UIScreen/UI_Back_0.tga"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Texture(pGraphicDev,
		RESOURCE_LOGO,
		L"Texture_Logo",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/LogoEnd/WARP_LOGO_White_0.tga"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Texture(pGraphicDev,
		RESOURCE_LOGO,
		L"Texture_NewGame",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/LogoEnd/NewGame_%d.png",2),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Texture(pGraphicDev,
		RESOURCE_LOGO,
		L"Texture_Challenge",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/LogoEnd/Challenge_%d.png",2),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Texture(pGraphicDev,
		RESOURCE_LOGO,
		L"Texture_HelpOption",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/LogoEnd/Help&Option_%d.png",2),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Texture(pGraphicDev,
		RESOURCE_LOGO,
		L"Texture_LeaderBoard",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/LogoEnd/LeaderBoard_%d.png",2),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Texture(pGraphicDev,
		RESOURCE_LOGO,
		L"Texture_Exit",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/LogoEnd/Exit_%d.png", 2),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Texture(pGraphicDev,
		RESOURCE_LOGO,
		L"Texture_Smoke",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/Effect/Smoke_0.tga"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Mesh_Player",
		Engine::TYPE_DYNAMIC,
		L"../Bin/Resource/Warp/Mesh/DynamicMesh/Player/",
		L"Player.x"),
		E_FAIL);

	return S_OK;
}

void CLogo::Key_Input()
{
	
	
	if (Engine::KeyDown(DIK_UP))
	{
		auto iter_begin = vecButton.begin();
		auto iter_end = vecButton.end();
		
		for (; iter_begin != iter_end; ++iter_begin)
		{
			if (1 == dynamic_cast<CButton*>(*iter_begin)->Get_TexCnt())
			{
				if(*iter_begin == vecButton.front())
					break;
				else
				{
					dynamic_cast<CButton*>(*iter_begin)->Set_TexCnt(0);
					--iter_begin;
					dynamic_cast<CButton*>(*iter_begin)->Set_TexCnt(1);
					break;
				}
			}
		}

	}
	else if (Engine::KeyDown(DIK_DOWN))
	{
		auto iter_begin = vecButton.begin();
		auto iter_end = vecButton.end();

		for (; iter_begin != iter_end; ++iter_begin)
		{
			if (1 == dynamic_cast<CButton*>(*iter_begin)->Get_TexCnt())
			{
				if (*iter_begin == vecButton.back())
					break;
				else
				{
					dynamic_cast<CButton*>(*iter_begin)->Set_TexCnt(0);
					++iter_begin;
					dynamic_cast<CButton*>(*iter_begin)->Set_TexCnt(1);
					break;
				}
			}
		}
	}

	if (Engine::KeyDown(DIK_RETURN))
	{
		auto iter_begin = vecButton.begin();
		auto iter_end = vecButton.end();

		for (; iter_begin != iter_end; ++iter_begin)
		{
			if (1 == dynamic_cast<CButton*>(*iter_begin)->Get_TexCnt())
			{
				if (*iter_begin == vecButton.front())
				{
					Engine::CScene*		pScene = CLoad::Create(m_pGraphicDev);

					Engine::SetUp_Scene(pScene);
					break;
				}
				else if (*iter_begin == vecButton.back())
				{
					::DestroyWindow(g_hWnd);
					break;
				}

			}
		}

		
	}
}

#include "stdafx.h"
#include "Stage.h"

#include "Export_Function.h"
#include "StaticMeshObj.h"
#include "DynamicMeshObj.h"
#include "DoorFrame.h"
#include "Door.h"
#include "Switch.h"
#include "Ball.h"
#include "StraightCon.h"
#include "MazeWall.h"
#include "WarpPiedestal.h"
#include "HeavyMetal.h"
#include "Lift.h"

#include "Robot.h"
#include "RobotGun.h"

#include "Stage2.h"
#include "SoundMgr.h"


CStage::CStage(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CScene(pGraphicDev)
{

}

CStage::~CStage(void)
{

}

HRESULT CStage::Ready_Scene(void)
{
	FAILED_CHECK_RETURN(Engine::CScene::Ready_Scene(), E_FAIL);
	FAILED_CHECK_RETURN(Ready_LightInfo(), E_FAIL);
	FAILED_CHECK_RETURN(Ready_Prototype(), E_FAIL);
	FAILED_CHECK_RETURN(Ready_GameLogic_Layer(L"GameLogic"), E_FAIL);
	

	//FAILED_CHECK_RETURN(Ready_UI_Layer(L"UI"), E_FAIL);
	m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, TRUE);

	m_pGraphicDev->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	m_pGraphicDev->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	m_pGraphicDev->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

	Load_TerrainData();
	Load_MeshData();

	vector<_int>	TempIndex;

	TempIndex.push_back(4);
	TempIndex.push_back(7);
	TempIndex.push_back(5);

	m_mapBlinkIndex.insert(make_pair(0, TempIndex));

	TempIndex.push_back(6);
	TempIndex.push_back(5);

	m_mapBlinkIndex.insert(make_pair(1, TempIndex));

	CSoundMgr::GetInstance()->StopAll();

	CSoundMgr::GetInstance()->PlayBGM(L"Music_PLACEHOLDER.ogg");

	return S_OK;
}

_int CStage::Update_Scene(const _float& fTimeDelta)
{
	m_fTime += fTimeDelta;

	if(m_bClear)
		m_fTimeAcc += fTimeDelta;

	if (m_fTimeAcc >= 5)
	{
		m_bClear = false;
		m_fTimeAcc = 0;
	}
		

	_int iExit = Engine::CScene::Update_Scene(fTimeDelta);


	if (CHANGE_SCENE == iExit || Engine::KeyDown(DIK_RETURN))
	{
		Engine::CScene*		pScene = CStage2::Create(m_pGraphicDev);
		NULL_CHECK_RETURN(pScene, E_FAIL);

		FAILED_CHECK_RETURN(Engine::SetUp_Scene(pScene), E_FAIL);

		return iExit;
	}

	BlinkTilePattern();
	MoveCamera();

	if (m_bMaze)
	{
		m_fMazeTime += fTimeDelta;
		if (m_fMazeTime > 2)
		{
			MazeMove();
			m_bMaze = false;
			m_fMazeTime = 0.f;
		}
	}

	return S_OK;
}

_int CStage::LateUpdate_Scene(const _float & fTimeDelta)
{
	_int iExit = Engine::CScene::LateUpdate_Scene(fTimeDelta);

	return iExit;
}

void CStage::Render_Scene(void)
{
	//++m_dwRenderCnt;

	//if (m_fTime >= 1.f)
	//{
	//	wsprintf(m_szFPS, L"FPS : %d", m_dwRenderCnt);
	//	m_fTime = 0.f;
	//	m_dwRenderCnt = 0;
	//}

	//Engine::Render_Font(L"Font_Default", m_szFPS, &_vec2(10.f, 10.f), D3DXCOLOR(1.f, 0.f, 0.f,1.f));

}

CStage* CStage::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CStage*	pInstance = new CStage(pGraphicDev);

	if (FAILED(pInstance->Ready_Scene()))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CStage::Free(void)
{
	Engine::CScene::Free();
}

HRESULT CStage::Ready_GameLogic_Layer(const _tchar* pLayerTag)
{
	Engine::CLayer*		pLayer = Engine::CLayer::Create();
	NULL_CHECK_RETURN(pLayer, E_FAIL);

	Engine::CGameObject*		pGameObject = nullptr;

	pGameObject = CPlayer::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//dynamic_cast<CPlayer*>(pGameObject)->Set_Triger(true);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Player", pGameObject), E_FAIL);

	Engine::CTransform*	pPlayerTransform = dynamic_cast<Engine::CTransform*>
		(pLayer->Get_Component(L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pPlayerTransform, E_FAIL);

	//pGameObject = CRobot::Create(m_pGraphicDev);
	//NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Robot_0", pGameObject), E_FAIL);

	//pGameObject = CRobotGun::Create(m_pGraphicDev, 0);
	//NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"RobotGun_0", pGameObject), E_FAIL);

	// StaticCamera
	pGameObject = CStaticCamera::Create(m_pGraphicDev,
		pPlayerTransform,
		&_vec3(4.f , 6.f, 4.f),
		&_vec3(0.f, 0.f, 0.f),
		&_vec3(0.f, 1.f, 0.f),
		D3DXToRadian(45.f),
		_float(WINCX) / WINCY,
		1.f,
		1000.f);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"StaticCamera", pGameObject), E_FAIL);
	dynamic_cast<CStaticCamera*>(pGameObject)->Set_Fix(_vec3(5.f, 2.f, 1.f), _vec3(6.f, 0.f, 5.f));

	m_mapLayer.emplace(pLayerTag, pLayer);	

	return S_OK;
}

HRESULT CStage::Ready_UI_Layer(const _tchar* pLayerTag)
{
	Engine::CLayer*		pLayer = Engine::CLayer::Create();
	NULL_CHECK_RETURN(pLayer, E_FAIL);

	//Engine::CGameObject*		pGameObject = nullptr;

	//auto	iter = find_if(m_mapLayer.begin(), m_mapLayer.end(), Engine::CTag_Finder(L"GameLogic"));
	//if (iter == m_mapLayer.end())
	//	return E_FAIL;

	//Engine::CTransform*	pPlayerTransform = dynamic_cast<Engine::CTransform*>
	//	(iter->second->Get_Component(L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
	//NULL_CHECK_RETURN(pPlayerTransform, E_FAIL);

	//// StaticCamera
	//pGameObject = CStaticCamera::Create(m_pGraphicDev,
	//									pPlayerTransform,
	//									&_vec3(0.f, 10.f, -5.f),
	//									&_vec3(0.f, 0.f, 0.f),
	//									&_vec3(0.f, 1.f, 0.f),
	//									D3DXToRadian(45.f),
	//									_float(WINCX) / WINCY,
	//									1.f,
	//									1000.f);
	//NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"StaticCamera", pGameObject), E_FAIL);

	m_mapLayer.emplace(pLayerTag, pLayer);

	return S_OK;
}

HRESULT CStage::Ready_LightInfo(void)
{
	D3DLIGHT9			tLightInfo;
	ZeroMemory(&tLightInfo, sizeof(D3DLIGHT9));

	tLightInfo.Type = D3DLIGHT_DIRECTIONAL;

	tLightInfo.Diffuse = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	tLightInfo.Specular = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	tLightInfo.Ambient = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.f);
	tLightInfo.Direction = _vec3(1.f, -1.f, 1.f);

	FAILED_CHECK_RETURN(Engine::Ready_Light(m_pGraphicDev, &tLightInfo, 0), E_FAIL);


	//tLightInfo.Type = D3DLIGHT_POINT;

	//tLightInfo.Diffuse = D3DXCOLOR(0.f, 1.f, 0.f, 1.f);
	//tLightInfo.Specular = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	//tLightInfo.Ambient = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	//tLightInfo.Position = _vec3(10.f, 2.f, 10.f);
	//tLightInfo.Range = 10.f;
	//tLightInfo.Attenuation0 = 1.f;

	//FAILED_CHECK_RETURN(Engine::Ready_Light(m_pGraphicDev, &tLightInfo, 1), E_FAIL);


	//tLightInfo.Type = D3DLIGHT_POINT;

	//tLightInfo.Diffuse = D3DXCOLOR(1.f, 0.f, 0.f, 1.f);
	//tLightInfo.Specular = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	//tLightInfo.Ambient = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	//tLightInfo.Position = _vec3(30.f, 2.f, 10.f);
	//tLightInfo.Range = 10.f;
	//tLightInfo.Attenuation0 = 1.f;

	//FAILED_CHECK_RETURN(Engine::Ready_Light(m_pGraphicDev, &tLightInfo, 2), E_FAIL);

	return S_OK;
}

HRESULT CStage::Ready_Prototype(void)
{
	Engine::CComponent*		pComponent = nullptr;

	// Optimization
	pComponent = Engine::COptimization::Create(m_pGraphicDev, Engine::COptimization::Enable, 129, 129);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	Engine::Ready_Prototype(L"Proto_Optimization", pComponent);


	return S_OK;
}

void CStage::Load_TerrainData(void)
{
	_ulong dwByte = 0, dwCntX = 1, dwCntZ = 1, dwVtxItv = 1, dwDetail = 1;
	_int iSize = 0, iTexCnt = 0, BufferCount = 0;
	
	_vec3 vPos;

	HANDLE hFile = ::CreateFile(L"../Bin/Data/TerrainTest.dat", GENERIC_READ, 0, nullptr,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (INVALID_HANDLE_VALUE == hFile)
		return;

	while (true)
	{
		ReadFile(hFile, &iSize, sizeof(_int), &dwByte, nullptr);
		if (0 == dwByte)
			break;
		ReadFile(hFile, m_Tag, sizeof(_tchar) * iSize, &dwByte, nullptr);

		ReadFile(hFile, &BufferCount, sizeof(_int), &dwByte, nullptr);
		ReadFile(hFile, &dwCntX, sizeof(_ulong), &dwByte, nullptr);
		ReadFile(hFile, &dwCntZ, sizeof(_ulong), &dwByte, nullptr);
		ReadFile(hFile, &dwVtxItv, sizeof(_ulong), &dwByte, nullptr);
		ReadFile(hFile, &dwDetail, sizeof(_ulong), &dwByte, nullptr);

		BufferTag[BufferCount] = L"Buffer_TerrainTex_" + to_wstring(BufferCount);

		Engine::Ready_Buffer(m_pGraphicDev,
			RESOURCE_STATIC,
			BufferTag[BufferCount].c_str(),
			Engine::BUFFER_TERRAINTEX,
			dwCntX,
			dwCntZ,
			dwVtxItv,
			dwDetail);

		ReadFile(hFile, &vPos, sizeof(_vec3), &dwByte, nullptr);
		ReadFile(hFile, &iTexCnt, sizeof(_int), &dwByte, nullptr);

		CTerrain* pTerrain = CTerrain::Create(m_pGraphicDev, BufferCount);
		pTerrain->SetTexCount(iTexCnt);
		dynamic_cast<Engine::CTransform*>(pTerrain->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(vPos.x, vPos.y, vPos.z);

		m_TagString[m_TerrainCount] = m_Tag;

		m_mapLayer.find(L"GameLogic")->second->Add_GameObject(m_TagString[m_TerrainCount].c_str(), pTerrain);
		
		m_TerrainCount++;

		if (0 == dwByte)
			break;
	}
	CloseHandle(hFile);

	

}

void CStage::Load_MeshData(void)
{
	_ulong dwByte = 0;
	_int iSize = 0, iLength = 0;
	_vec3 vPos, vScale, vAngle;
	wstring	szTag;
	CStaticMeshObj* pStaticMesh = nullptr;
	CDynamicMeshObj* pDynamicMesh = nullptr;
	CDoorFrame*		pDoorFrame = nullptr;
	CDoor*			pDoor = nullptr;
	CSwitch*		pSwitch = nullptr;
	CBall*			pBall	= nullptr;
	CStraightCon*	pStraightCon	= nullptr;
	CMazeWall*		pMazeWall = nullptr;
	CWarpPiedestal*	pWarpPied = nullptr;
	CHeavyMetal*	pHeavyMetal = nullptr;
	CLift*			pLift = nullptr;
	Engine::CTransform* pTransform = nullptr;
	_vec3 vPointA, vPointB, vPointC;

	HANDLE hFile = ::CreateFile(L"../Bin/Data/Test.dat", GENERIC_READ, 0, nullptr,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (INVALID_HANDLE_VALUE == hFile)
		return;

	while (true)
	{
		ReadFile(hFile, &iSize, sizeof(_int), &dwByte, nullptr);
		if (0 == dwByte)
			break;
		for (int i = 0; i < iSize; ++i)
		{
			ReadFile(hFile, &iLength, sizeof(_int), &dwByte, nullptr);
			ReadFile(hFile, m_szTag, sizeof(_tchar) * iLength, &dwByte, nullptr);
			ReadFile(hFile, &iLength, sizeof(_int), &dwByte, nullptr);
			ReadFile(hFile, m_szFilepath, sizeof(_tchar) * iLength, &dwByte, nullptr);
			ReadFile(hFile, &iLength, sizeof(_int), &dwByte, nullptr);
			ReadFile(hFile, m_szName, sizeof(_tchar) * iLength, &dwByte, nullptr);

		}
		ReadFile(hFile, &iSize, sizeof(_int), &dwByte, nullptr);
		for (int i = 0; i < iSize; ++i)
		{
			ReadFile(hFile, &iLength, sizeof(_int), &dwByte, nullptr);
			ReadFile(hFile, m_szTag, sizeof(_tchar) * iLength, &dwByte, nullptr);
			ReadFile(hFile, &iLength, sizeof(_int), &dwByte, nullptr);
			ReadFile(hFile, m_szFilepath, sizeof(_tchar) * iLength, &dwByte, nullptr);
			ReadFile(hFile, &iLength, sizeof(_int), &dwByte, nullptr);
			ReadFile(hFile, m_szName, sizeof(_tchar) * iLength, &dwByte, nullptr);

		}


		ReadFile(hFile, &iSize, sizeof(_int), &dwByte, nullptr);

		for (int i = 0; i < iSize; ++i)
		{
			ReadFile(hFile, &iLength, sizeof(_int), &dwByte, nullptr);
			ReadFile(hFile, m_StaticTag, sizeof(_tchar) * iLength, &dwByte, NULL);

			ReadFile(hFile, &iLength, sizeof(_int), &dwByte, nullptr);
			ReadFile(hFile, m_MeshTag, iLength * sizeof(_tchar), &dwByte, nullptr);

			ReadFile(hFile, &vScale, sizeof(_vec3), &dwByte, nullptr);
			ReadFile(hFile, &vAngle, sizeof(_vec3), &dwByte, nullptr);

			ReadFile(hFile, &vPos, sizeof(_vec3), &dwByte, nullptr);


			szTag = m_StaticTag;

			_int Findint = szTag.find(L"doorframe");

			if (Findint >= 0)
			{
				szTag.erase(0, szTag.find('_', szTag.length() - 3) + 1);

				if (_wtoi(szTag.c_str()) != 2)
				{
					pDoorFrame = CDoorFrame::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);

					pTransform = dynamic_cast<Engine::CTransform*>(pDoorFrame->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
					pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
					pTransform->Rotation(Engine::ROT_X, vAngle.x);
					pTransform->Rotation(Engine::ROT_Y, vAngle.y);
					pTransform->Rotation(Engine::ROT_Z, vAngle.z);
					pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

					m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pDoorFrame->GetObjTag(), pDoorFrame);


					pDoorFrame->Set_Count(_wtoi(szTag.c_str()));

					continue;
					
				}
			}

			Findint = szTag.find(L"doorLeft" );

			if (Findint >= 0)
			{
				pDoor = CDoor::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);
				pDoor->Set_OriPos(vPos);
				pDoor->Set_Direction(_vec3(0.f, 0.f, -1.f));
				pTransform = dynamic_cast<Engine::CTransform*>(pDoor->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
				pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
				pTransform->Rotation(Engine::ROT_X, vAngle.x);
				pTransform->Rotation(Engine::ROT_Y, vAngle.y);
				pTransform->Rotation(Engine::ROT_Z, vAngle.z);
				pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

				m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pDoor->GetObjTag(), pDoor);

				continue;

			}
			Findint = szTag.find(L"doorRight");

			if (Findint >= 0)
			{
				pDoor = CDoor::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);
				pDoor->Set_OriPos(vPos);
				pDoor->Set_Direction(_vec3(0.f,0.f,1.f));
				pTransform = dynamic_cast<Engine::CTransform*>(pDoor->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
				pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
				pTransform->Rotation(Engine::ROT_X, vAngle.x);
				pTransform->Rotation(Engine::ROT_Y, vAngle.y);
				pTransform->Rotation(Engine::ROT_Z, vAngle.z);
				pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

				m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pDoor->GetObjTag(), pDoor);

				continue;
			}

			Findint = szTag.find(L"switch");

			if (Findint >= 0)
			{
				pSwitch = CSwitch::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);
			
				pTransform = dynamic_cast<Engine::CTransform*>(pSwitch->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
				pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
				pTransform->Rotation(Engine::ROT_X, vAngle.x);
				pTransform->Rotation(Engine::ROT_Y, vAngle.y);
				pTransform->Rotation(Engine::ROT_Z, vAngle.z);
				pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

				m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pSwitch->GetObjTag(), pSwitch);

				continue;
			}

			Findint = szTag.find(L"Ball");

			if (Findint >= 0)
			{
				pBall = CBall::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);
				
				pBall->EndPos(vPos);
				pTransform = dynamic_cast<Engine::CTransform*>(pBall->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
				pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
				pTransform->Rotation(Engine::ROT_X, vAngle.x);
				pTransform->Rotation(Engine::ROT_Y, vAngle.y);
				pTransform->Rotation(Engine::ROT_Z, vAngle.z);
				pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

				m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pBall->GetObjTag(), pBall);

				continue;
			}

			Findint = szTag.find(L"conveyor");

			if (Findint >= 0)
			{
				pStraightCon = CStraightCon::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);

				pTransform = dynamic_cast<Engine::CTransform*>(pStraightCon->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
				pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
				pTransform->Rotation(Engine::ROT_X, vAngle.x);
				pTransform->Rotation(Engine::ROT_Y, vAngle.y);
				pTransform->Rotation(Engine::ROT_Z, vAngle.z);
				pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

				m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pStraightCon->GetObjTag(), pStraightCon);

				continue;
			}

			Findint = szTag.find(L"MazeWall_3x1");

			if (Findint >= 0)
			{
				szTag.erase(0, szTag.find('_', szTag.length() - 3) + 1);

				if (_wtoi(szTag.c_str()) < 5)
				{
					pMazeWall = CMazeWall::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);
					pMazeWall->Set_OriPos(vPos);
					pMazeWall->Set_Direction(_vec3(0.f, -2.f, 0.f));
					pMazeWall->Set_Action(true);
					pTransform = dynamic_cast<Engine::CTransform*>(pMazeWall->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
					pTransform->Set_Scale(vScale.x, 0.02f, vScale.z);
					pTransform->Rotation(Engine::ROT_X, vAngle.x);
					pTransform->Rotation(Engine::ROT_Y, vAngle.y);
					pTransform->Rotation(Engine::ROT_Z, vAngle.z);
					pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

					m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pMazeWall->GetObjTag(), pMazeWall);

					continue;
				}
				
				szTag = m_StaticTag;
			}

			Findint = szTag.find(L"MazeWall_4x1");

			if (Findint >= 0)
			{
				szTag.erase(0, szTag.find('_', szTag.length() - 3) + 1);

				if (_wtoi(szTag.c_str()) < 7)
				{
					pMazeWall = CMazeWall::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);
					pMazeWall->Set_OriPos(vPos);
					pMazeWall->Set_Direction(_vec3(0.f, -2.f, 0.f));
					pMazeWall->Set_Action(true);
					pTransform = dynamic_cast<Engine::CTransform*>(pMazeWall->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
					pTransform->Set_Scale(vScale.x, 0.02f, vScale.z);
					pTransform->Rotation(Engine::ROT_X, vAngle.x);
					pTransform->Rotation(Engine::ROT_Y, vAngle.y);
					pTransform->Rotation(Engine::ROT_Z, vAngle.z);
					pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

					m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pMazeWall->GetObjTag(), pMazeWall);

					continue;
				}

				szTag = m_StaticTag;
			}

			Findint = szTag.find(L"MazeWall_5x1");	

			if (Findint >= 0)
			{
				szTag.erase(0, szTag.find('_', szTag.length() - 3) + 1);

				if (_wtoi(szTag.c_str()) < 6)
				{
					pMazeWall = CMazeWall::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);
					pMazeWall->Set_OriPos(vPos);
					pMazeWall->Set_Direction(_vec3(0.f, -2.f, 0.f));
					pMazeWall->Set_Action(true);
					pTransform = dynamic_cast<Engine::CTransform*>(pMazeWall->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
					pTransform->Set_Scale(vScale.x, 0.02f, vScale.z);
					pTransform->Rotation(Engine::ROT_X, vAngle.x);
					pTransform->Rotation(Engine::ROT_Y, vAngle.y);
					pTransform->Rotation(Engine::ROT_Z, vAngle.z);
					pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

					m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pMazeWall->GetObjTag(), pMazeWall);

					continue;
				}

				szTag = m_StaticTag;
			}

			Findint = szTag.find(L"MazeWall");

			if (Findint >= 0)
			{
				pMazeWall = CMazeWall::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);
				pMazeWall->Set_OriPos(vPos);
				pMazeWall->Set_Direction(_vec3(0.f, -2.f, 0.f));
				pTransform = dynamic_cast<Engine::CTransform*>(pMazeWall->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
				pTransform->Set_Scale(vScale.x, 0.02f, vScale.z);
				pTransform->Rotation(Engine::ROT_X, vAngle.x);
				pTransform->Rotation(Engine::ROT_Y, vAngle.y);
				pTransform->Rotation(Engine::ROT_Z, vAngle.z);
				pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

				m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pMazeWall->GetObjTag(), pMazeWall);

				continue;
			}

			Findint = szTag.find(L"warp_piedestal");

			if (Findint >= 0)
			{
				pWarpPied = CWarpPiedestal::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);
			
				pTransform = dynamic_cast<Engine::CTransform*>(pWarpPied->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
				pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
				pTransform->Rotation(Engine::ROT_X, vAngle.x);
				pTransform->Rotation(Engine::ROT_Y, vAngle.y);
				pTransform->Rotation(Engine::ROT_Z, vAngle.z);
				pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

				m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pWarpPied->GetObjTag(), pWarpPied);

				continue;
			}

			Findint = szTag.find(L"HeavyMetal");

			if (Findint >= 0)
			{
				pHeavyMetal = CHeavyMetal::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);
				pTransform = dynamic_cast<Engine::CTransform*>(pHeavyMetal->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
				pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
				pTransform->Rotation(Engine::ROT_X, vAngle.x);
				pTransform->Rotation(Engine::ROT_Y, vAngle.y);
				pTransform->Rotation(Engine::ROT_Z, vAngle.z);
				pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

				m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pHeavyMetal->GetObjTag(), pHeavyMetal);

				continue;

			}

			Findint = szTag.find(L"Lift");

			if (Findint >= 0)
			{
				pLift = CLift::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);

				pTransform = dynamic_cast<Engine::CTransform*>(pLift->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
				pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
				pTransform->Rotation(Engine::ROT_X, vAngle.x);
				pTransform->Rotation(Engine::ROT_Y, vAngle.y);
				pTransform->Rotation(Engine::ROT_Z, vAngle.z);
				pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

				m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pLift->GetObjTag(), pLift);

				continue;
			}

			pStaticMesh = CStaticMeshObj::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);

			pTransform = dynamic_cast<Engine::CTransform*>(pStaticMesh->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
			pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
			pTransform->Rotation(Engine::ROT_X, vAngle.x);
			pTransform->Rotation(Engine::ROT_Y, vAngle.y);
			pTransform->Rotation(Engine::ROT_Z, vAngle.z);
			pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

			m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pStaticMesh->GetObjTag(), pStaticMesh);

		}


		ReadFile(hFile, &iSize, sizeof(_int), &dwByte, nullptr);

		for (int i = 0; i < iSize; ++i)
		{
			ReadFile(hFile, &iLength, sizeof(_int), &dwByte, nullptr);
			ReadFile(hFile, m_DynamicTag, sizeof(_tchar) * iLength, &dwByte, NULL);

			ReadFile(hFile, &iLength, sizeof(_int), &dwByte, nullptr);
			ReadFile(hFile, m_MeshTag, iLength * sizeof(_tchar), &dwByte, nullptr);

			ReadFile(hFile, &vScale, sizeof(_vec3), &dwByte, nullptr);
			ReadFile(hFile, &vAngle, sizeof(_vec3), &dwByte, nullptr);

			ReadFile(hFile, &vPos, sizeof(_vec3), &dwByte, nullptr);

			szTag = m_DynamicTag;

			pDynamicMesh = CDynamicMeshObj::Create(m_pGraphicDev, m_MeshTag ,szTag);
			pTransform = dynamic_cast<Engine::CTransform*>(pDynamicMesh->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
			pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
			pTransform->Rotation(Engine::ROT_X, vAngle.x);
			pTransform->Rotation(Engine::ROT_Y, vAngle.y);
			pTransform->Rotation(Engine::ROT_Z, vAngle.z);
			pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

			m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pDynamicMesh->GetObjTag(), pDynamicMesh);

		}


		if (m_pNaviCom == nullptr)
			m_pNaviCom = dynamic_cast<Engine::CNaviMesh*>(Get_Component(L"GameLogic", L"Player", L"Com_Navi", Engine::ID_STATIC));

		ReadFile(hFile, &iSize, sizeof(_int), &dwByte, nullptr);
		for (int i = 0; i < iSize; ++i)
		{

			ReadFile(hFile, &vPointA, sizeof(_vec3), &dwByte, NULL);
			ReadFile(hFile, &vPointB, sizeof(_vec3), &dwByte, NULL);
			ReadFile(hFile, &vPointC, sizeof(_vec3), &dwByte, NULL);

			m_pNaviCom->Add_Cell(vPointA, vPointB, vPointC);

		}

		if (0 == dwByte)
			break;
	}
	CloseHandle(hFile);

	return;
}

void CStage::BlinkTilePattern(void)
{
	if(dynamic_cast<CTerrain*>(Engine::Get_GameObj(L"GameLogic", L"Terrain_3"))->GetDraw())
		return;

	dynamic_cast<CTerrain*>(Engine::Get_GameObj(L"GameLogic", L"Terrain_4"))->SetTexCount(2);
	dynamic_cast<CTerrain*>(Engine::Get_GameObj(L"GameLogic", L"Terrain_5"))->SetTexCount(2);
	dynamic_cast<CTerrain*>(Engine::Get_GameObj(L"GameLogic", L"Terrain_6"))->SetTexCount(2);
	dynamic_cast<CTerrain*>(Engine::Get_GameObj(L"GameLogic", L"Terrain_7"))->SetTexCount(2);


	if (m_iPatternCount > 1)
	{
		dynamic_cast<CDoor*>(Engine::Get_GameObj(L"GameLogic", L"wall_inswd_doorLeft_1x_4"))->Set_Move(true);
		dynamic_cast<CDoor*>(Engine::Get_GameObj(L"GameLogic", L"wall_inswd_doorRight_1x_4"))->Set_Move(true);
		return;
	}
		

	vector<_int>* pTempVec = dynamic_cast<CPlayer*>(Engine::Get_GameObj(L"GameLogic", L"Player"))->GetPlayerTile();
	
	if (m_mapBlinkIndex.find(m_iPatternCount)->second.size() <= pTempVec->size())
	{
		PatternPass();
		m_uPreIndex = 0;
		m_uNextIndex = 0;
		pTempVec->clear();
		m_bClear = true;
		return;
	}

	if(m_uNextIndex >= m_mapBlinkIndex.find(m_iPatternCount)->second.size())
		return;
	if (!m_bClear)
	{
		wstring szTemp = L"Terrain_" + to_wstring(m_mapBlinkIndex.find(m_iPatternCount)->second[m_uPreIndex]);
		if (!dynamic_cast<CTerrain*>(Engine::Get_GameObj(L"GameLogic", szTemp.c_str()))->GetBlink())
		{
			szTemp = L"Terrain_" + to_wstring(m_mapBlinkIndex.find(m_iPatternCount)->second[m_uNextIndex]);
			dynamic_cast<CTerrain*>(Engine::Get_GameObj(L"GameLogic", szTemp.c_str()))->SetBlinkTile(true);

			m_uPreIndex = m_uNextIndex;
			m_uNextIndex = m_uPreIndex + 1;
		}
	}
	
}

_bool CStage::PatternPass()
{
	vector<_int>* pTempVec = dynamic_cast<CPlayer*>(Engine::Get_GameObj(L"GameLogic", L"Player"))->GetPlayerTile();

	switch (m_iPatternCount)
	{
	case 0:
		for (_uint i = 0; i < m_mapBlinkIndex.find(0)->second.size(); ++i)
		{
			if(m_mapBlinkIndex.find(m_iPatternCount)->second[i] != (*pTempVec)[i])
				return false;
		}
		break;
	case 1:
		for (_uint i = 0; i < m_mapBlinkIndex.find(1)->second.size(); ++i)
		{
			if (m_mapBlinkIndex.find(m_iPatternCount)->second[i] != (*pTempVec)[i])
				return false;
		}
		break;
	default:
		break;
	}

	++m_iPatternCount;
	return true;
}

void CStage::MoveCamera()
{
	CStaticCamera* pCam = dynamic_cast<CStaticCamera*>(Engine::Get_GameObj(L"GameLogic", L"StaticCamera"));
	Engine::CTransform* pPlayerTrans = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic",L"Player",L"Com_Transform",Engine::ID_DYNAMIC));

	_vec3 vPos = *pPlayerTrans->Get_Info(Engine::INFO_POS);

	//pCam->Set_IsDest(false);

	if (0 == m_pNaviCom->Get_Index() || 1 == m_pNaviCom->Get_Index())
	{
		pCam->Set_Fix(_vec3(5.f,2.f,1.f), _vec3(6.f,0.f,5.f));
	}
	else if (10 == m_pNaviCom->Get_Index() || 11 == m_pNaviCom->Get_Index())
	{
		pCam->Set_IsFix(false);
		pCam->Set_Destination(_vec3(10.f, 8.f, 1.f), _vec3(10.f, 0.f, 5.f));
	}
	else if (55 == m_pNaviCom->Get_Index() || 56 == m_pNaviCom->Get_Index()
		|| 57 == m_pNaviCom->Get_Index() || 58 == m_pNaviCom->Get_Index()
		|| 59 == m_pNaviCom->Get_Index() || 60 == m_pNaviCom->Get_Index())
	{
		pCam->Set_Destination(_vec3(vPos.x, 4.f, vPos.z-4.f), _vec3(vPos.x, vPos.y, vPos.z));
			
	}
	else if (125 == m_pNaviCom->Get_Index() || 126 == m_pNaviCom->Get_Index())
	{
		pCam->Set_Destination(_vec3(36.f, 10.f, -1.f), _vec3(36.f, 0.f, 2.f));
		pCam->Set_Distance(8.f);
		m_bMaze =true;

		auto iter_begin = Get_Layer(L"GameLogic")->Get_MapObject()->begin();
		auto iter_end = Get_Layer(L"GameLogic")->Get_MapObject()->end();

		for (; iter_begin != iter_end; ++iter_begin)
		{
			wstring szTemp = iter_begin->first;

			_int iSearch = szTemp.find(L"MazeWall");

			if (iSearch >= 0)
			{
				if (dynamic_cast<CMazeWall*>(iter_begin->second)->Get_Action())
				{
					dynamic_cast<CMazeWall*>(iter_begin->second)->Set_Triger(true);
				}
			}
		}
	}
}

void CStage::MazeMove()
{
	auto iter_begin = Get_Layer(L"GameLogic")->Get_MapObject()->begin();
	auto iter_end = Get_Layer(L"GameLogic")->Get_MapObject()->end();

	for (; iter_begin != iter_end; ++iter_begin)
	{
		wstring szTemp = iter_begin->first;

		_int iSearch = szTemp.find(L"MazeWall");

		if (iSearch >= 0)
		{
			if (dynamic_cast<CMazeWall*>(iter_begin->second)->Get_Action())
			{
				dynamic_cast<CMazeWall*>(iter_begin->second)->Set_Triger(false);
			}
		}
	}
}

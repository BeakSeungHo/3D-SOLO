#include "stdafx.h"
#include "Stage2.h"

#include "Export_Function.h"
#include "StaticMeshObj.h"
#include "DynamicMeshObj.h"
#include "Door.h"
#include "HeavyMetal.h"
#include "PowerCell.h"
#include "Robot.h"
#include "RobotGun.h"
#include "RobotLaser.h"
#include "FixedLaser.h"
#include "StraightCon.h"
#include "CornerCon.h"
#include "Shiny.h"
#include "Hatch.h"
#include "Portal.h"
#include "BossWall.h"
#include "Boss.h"
#include "CheckPoint.h"
#include "SoundMgr.h"

CStage2::CStage2(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CScene(pGraphicDev)
{

}

CStage2::~CStage2(void)
{

}

HRESULT CStage2::Ready_Scene(void)
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
	CSoundMgr::GetInstance()->StopAll();

	CSoundMgr::GetInstance()->PlayBGM(L"Warp_MainMusicLevel2.ogg");

	return S_OK;
}

_int CStage2::Update_Scene(const _float& fTimeDelta)
{
	m_fTime += fTimeDelta;

	m_fTimeAcc += fTimeDelta;

	if (m_fTimeAcc >= 5.f)
	{
		CShiny*	pShiny = nullptr;
		CHeavyMetal* pHeavy = nullptr;
		m_fTimeAcc = 0.f;
		if (m_bIsBarrel)
		{
			
			wstring StaticTag = L"ConShiny_" + to_wstring(m_iShinyCount);
			dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", StaticTag.c_str(), L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(29.f, 0.f, 11.35f);
			++m_iShinyCount;
			StaticTag = L"ConShiny_" + to_wstring(m_iShinyCount);
			dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", StaticTag.c_str(), L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(25.85f, 0.f, 21.5f);
			++m_iShinyCount;

			if (m_iShinyCount >= 20)
				m_iShinyCount = 0;
			
			m_bIsBarrel = false;
		}
		else
		{
			m_HeavyTag = L"ConHeavyMetal_" + to_wstring(m_iHeavyCount);
			pHeavy = CHeavyMetal::Create(m_pGraphicDev, 0, L"HeavyMetal_Barrel", m_HeavyTag);
			dynamic_cast<Engine::CTransform*>(pHeavy->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(29.f, 0.f, 11.35f);
			Get_Layer(L"GameLogic")->Add_GameObject(pHeavy->GetObjTag(), pHeavy);
			++m_iHeavyCount;
			m_HeavyTag = L"ConHeavyMetal_" + to_wstring(m_iHeavyCount);
			pHeavy = CHeavyMetal::Create(m_pGraphicDev, 0, L"HeavyMetal_Barrel", m_HeavyTag);
			dynamic_cast<Engine::CTransform*>(pHeavy->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(25.85f, 0.f, 21.5f);
			Get_Layer(L"GameLogic")->Add_GameObject(pHeavy->GetObjTag(), pHeavy);
			++m_iHeavyCount;
			
			if (m_iHeavyCount >= 50)
				m_iHeavyCount = 0;

			m_bIsBarrel = true;
		}
	}

	Engine::CScene::Update_Scene(fTimeDelta);

	MoveCamera();

	return S_OK;
}

_int CStage2::LateUpdate_Scene(const _float & fTimeDelta)
{
	_int iExit = Engine::CScene::LateUpdate_Scene(fTimeDelta);

	return iExit;
}

void CStage2::Render_Scene(void)
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

CStage2* CStage2::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CStage2*	pInstance = new CStage2(pGraphicDev);

	if (FAILED(pInstance->Ready_Scene()))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CStage2::Free(void)
{
	Engine::CScene::Free();
}

HRESULT CStage2::Ready_GameLogic_Layer(const _tchar* pLayerTag)
{
	Engine::CLayer*		pLayer = Engine::CLayer::Create();
	NULL_CHECK_RETURN(pLayer, E_FAIL);

	Engine::CGameObject*		pGameObject = nullptr;
	
	pGameObject = CPlayer::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CPlayer*>(pGameObject)->Set_Triger(true);
	dynamic_cast<CPlayer*>(pGameObject)->Set_CheckPos(_vec3(-1.f,0.f,1.f));
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Player", pGameObject), E_FAIL);

	Engine::CTransform*	pPlayerTransform = dynamic_cast<Engine::CTransform*>
		(pLayer->Get_Component(L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pPlayerTransform, E_FAIL);

	pPlayerTransform->Set_Pos(&_vec3(-1.f,0.f,1.f));
	//pPlayerTransform->Set_Pos(&_vec3(58.f, 0.f, 21.f));

	// StaticCamera
	pGameObject = CStaticCamera::Create(m_pGraphicDev,
		pPlayerTransform,
		&_vec3(-1.f , 6.f, -3.f),
		&_vec3(-1.f, 0.f, 1.f),
		&_vec3(0.f, 1.f, 0.f),
		D3DXToRadian(45.f),
		_float(WINCX) / WINCY,
		1.f,
		1000.f);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"StaticCamera", pGameObject), E_FAIL);

	for (_int i = 0; i < 20; ++i)
	{
		wstring StaticTag = L"ConShiny_" + to_wstring(i);
		CShiny* pShiny = CShiny::Create(m_pGraphicDev, 0, L"Shiny_Barrel", StaticTag);
		dynamic_cast<Engine::CTransform*>(pShiny->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(24.f, 0.f, 22.4f);
		pLayer->Add_GameObject(pShiny->GetObjTag(), pShiny);
	}

	pGameObject = CPortal::Create(m_pGraphicDev, L"Texture_OrangePortal");
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Portal_0", pGameObject), E_FAIL);
	dynamic_cast<Engine::CTransform*>(pLayer->Get_Component(L"Portal_0",L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(36.f,0.1f,21.f);

	pGameObject = CPortal::Create(m_pGraphicDev, L"Texture_BluePortal");
	dynamic_cast<CPortal*>(pGameObject)->Set_bIsMove(true);
	dynamic_cast<CPortal*>(pGameObject)->Set_MaxFrame(68.f);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Portal_1", pGameObject), E_FAIL);
	dynamic_cast<Engine::CTransform*>(pLayer->Get_Component(L"Portal_1", L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(38.f, 2.f, 21.f);

	pGameObject = CBoss::Create(m_pGraphicDev);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Boss", pGameObject), E_FAIL);
	dynamic_cast<Engine::CTransform*>(pLayer->Get_Component(L"Boss", L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(60.4f, 0.f, 21.f);

	m_mapLayer.emplace(pLayerTag, pLayer);

	return S_OK;
}

HRESULT CStage2::Ready_UI_Layer(const _tchar* pLayerTag)
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

HRESULT CStage2::Ready_LightInfo(void)
{
	//D3DLIGHT9			tLightInfo;
	//ZeroMemory(&tLightInfo, sizeof(D3DLIGHT9));

	//tLightInfo.Type = D3DLIGHT_DIRECTIONAL;

	//tLightInfo.Diffuse = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	//tLightInfo.Specular = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	//tLightInfo.Ambient = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.f);
	//tLightInfo.Direction = _vec3(1.f, -1.f, 1.f);

	//FAILED_CHECK_RETURN(Engine::Ready_Light(m_pGraphicDev, &tLightInfo, 0), E_FAIL);


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

HRESULT CStage2::Ready_Prototype(void)
{
	//Engine::CComponent*		pComponent = nullptr;

	//// Optimization
	//pComponent = Engine::COptimization::Create(m_pGraphicDev, Engine::COptimization::Enable, 129, 129);
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//Engine::Ready_Prototype(L"Proto_Optimization", pComponent);


	return S_OK;
}

void CStage2::Load_TerrainData(void)
{
	_ulong dwByte = 0, dwCntX = 1, dwCntZ = 1, dwVtxItv = 1, dwDetail = 1;
	_int iSize = 0, iTexCnt = 0, BufferCount = 0;
	
	_vec3 vPos;
	_uint uCount = 0;

	HANDLE hFile = ::CreateFile(L"../Bin/Data/Stage2TerrainTest.dat", GENERIC_READ, 0, nullptr,
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

		BufferCount += 8;
		BufferTag[uCount] = L"Buffer_TerrainTex_" + to_wstring(BufferCount);

		Engine::Ready_Buffer(m_pGraphicDev,
			RESOURCE_STATIC,
			BufferTag[uCount].c_str(),
			Engine::BUFFER_TERRAINTEX,
			dwCntX,
			dwCntZ,
			dwVtxItv,
			dwDetail);
		++uCount;

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

void CStage2::Load_MeshData(void)
{
	_ulong dwByte = 0;
	_int iSize = 0, iLength = 0;
	_vec3 vPos, vScale, vAngle;
	wstring	szTag;
	CStaticMeshObj* pStaticMesh = nullptr;
	CDynamicMeshObj* pDynamicMesh = nullptr;
	CDoor*			pDoor = nullptr;
	CHeavyMetal*	pHeavyMetal = nullptr;
	CPowerCell*		pPowerCell	= nullptr;
	CRobot*			pRobot = nullptr;
	CRobotGun*		pRobotGun = nullptr;
	CRobotLaser*	pRobotLaser = nullptr;
	CFixedLaser*	pFixedLaser = nullptr;
	CStraightCon*	pStraightCon = nullptr;
	CCornerCon*		pCornerCon = nullptr;
	CHatch*			pHatch = nullptr;
	CBossWall*		pBossWall = nullptr;
	CCheckPoint*	pCheckPoint = nullptr;
	Engine::CTransform* pTransform = nullptr;
	_vec3 vPointA, vPointB, vPointC;
	_int iRobotLaserCount = 0;
	_int iFixedLaserCount = 0;

	HANDLE hFile = ::CreateFile(L"../Bin/Data/Stage2Test.dat", GENERIC_READ, 0, nullptr,
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

			_int Findint = szTag.find(L"Door");

			if (Findint >= 0)
			{
				szTag.erase(0, szTag.find('_', szTag.length() - 3) + 1);

				if (_wtoi(szTag.c_str()) > 5)
				{
					pDoor = CDoor::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);
					pDoor->Set_OriPos(vPos);

					if (_wtoi(szTag.c_str()) % 2 == 0)
						pDoor->Set_Direction(_vec3(0.f, 0.f, 2.f));
					else
						pDoor->Set_Direction(_vec3(0.f, 0.f, -2.f));
					pTransform = dynamic_cast<Engine::CTransform*>(pDoor->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
					pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
					pTransform->Rotation(Engine::ROT_X, vAngle.x);
					pTransform->Rotation(Engine::ROT_Y, vAngle.y);
					pTransform->Rotation(Engine::ROT_Z, vAngle.z);
					pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

					m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pDoor->GetObjTag(), pDoor);

					continue;
				}
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

			Findint = szTag.find(L"powercell");

			if (Findint >= 0)
			{
				pPowerCell = CPowerCell::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);
				pTransform = dynamic_cast<Engine::CTransform*>(pPowerCell->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
				pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
				pTransform->Rotation(Engine::ROT_X, vAngle.x);
				pTransform->Rotation(Engine::ROT_Y, vAngle.y);
				pTransform->Rotation(Engine::ROT_Z, vAngle.z);
				pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

				m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pPowerCell->GetObjTag(), pPowerCell);

				continue;

			}

			Findint = szTag.find(L"Robotgun");
			
			if (Findint >= 0)
			{
				RobotLaserTag[iRobotLaserCount] = L"RobotLaser_" + to_wstring(iRobotLaserCount);

				pRobotLaser = CRobotLaser::Create(m_pGraphicDev);
				pRobotLaser->Set_Count(iRobotLaserCount);
				m_mapLayer.find(L"GameLogic")->second->Add_GameObject(RobotLaserTag[iRobotLaserCount].c_str(), pRobotLaser);

				pRobotGun = CRobotGun::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);
				pRobotGun->Set_Count(iRobotLaserCount++);
				//pTransform = dynamic_cast<Engine::CTransform*>(pRobotGun->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
				//pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
				//pTransform->Rotation(Engine::ROT_X, vAngle.x);
				//pTransform->Rotation(Engine::ROT_Y, vAngle.y);
				//pTransform->Rotation(Engine::ROT_Z, vAngle.z);
				//pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

				m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pRobotGun->GetObjTag(), pRobotGun);

				continue;

			}

			Findint = szTag.find(L"conveyorcorner");

			if (Findint >= 0)
			{
				pCornerCon = CCornerCon::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);

				pTransform = dynamic_cast<Engine::CTransform*>(pCornerCon->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
				pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
				pTransform->Rotation(Engine::ROT_X, vAngle.x);
				pTransform->Rotation(Engine::ROT_Y, vAngle.y);
				pTransform->Rotation(Engine::ROT_Z, vAngle.z);
				pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

				Findint = szTag.find(L"reverse");

				if (Findint >= 0)
					pCornerCon->Set_Reverse(true);

				m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pCornerCon->GetObjTag(), pCornerCon);

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

			Findint = szTag.find(L"HatchPlatform");

			if (Findint >= 0)
			{
				pHatch = CHatch::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);
				pHatch->Set_OriPos(vPos);

				pTransform = dynamic_cast<Engine::CTransform*>(pHatch->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
				pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
				pTransform->Rotation(Engine::ROT_X, vAngle.x);
				pTransform->Rotation(Engine::ROT_Y, vAngle.y);
				pTransform->Rotation(Engine::ROT_Z, vAngle.z);
				pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

				m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pHatch->GetObjTag(), pHatch);

				continue;

			}


			Findint = szTag.find(L"Laser_Fixed");

			if (Findint >= 0)
			{
				FixedLaserTag[iFixedLaserCount] = L"FixedLaser_" + to_wstring(iRobotLaserCount);

				pFixedLaser = CFixedLaser::Create(m_pGraphicDev);
				pFixedLaser->Set_Count(iFixedLaserCount);
				m_mapLayer.find(L"GameLogic")->second->Add_GameObject(FixedLaserTag[iFixedLaserCount].c_str(), pFixedLaser);
				++iFixedLaserCount;
			}

			Findint = szTag.find(L"Wall_int_column_1x_b");

			if (Findint >= 0)
			{
				pBossWall = CBossWall::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);

				pTransform = dynamic_cast<Engine::CTransform*>(pBossWall->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
				pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
				pTransform->Rotation(Engine::ROT_X, vAngle.x);
				pTransform->Rotation(Engine::ROT_Y, vAngle.y);
				pTransform->Rotation(Engine::ROT_Z, vAngle.z);
				pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

				m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pBossWall->GetObjTag(), pBossWall);

				continue;

			}

			Findint = szTag.find(L"checkpoint");

			if (Findint >= 0)
			{
				pCheckPoint = CCheckPoint::Create(m_pGraphicDev, 0, m_MeshTag, m_StaticTag);

				pTransform = dynamic_cast<Engine::CTransform*>(pCheckPoint->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
				pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
				pTransform->Rotation(Engine::ROT_X, vAngle.x);
				pTransform->Rotation(Engine::ROT_Y, vAngle.y);
				pTransform->Rotation(Engine::ROT_Z, vAngle.z);
				pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

				m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pCheckPoint->GetObjTag(), pCheckPoint);

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

			_int Findint = szTag.find(L"Robot");

			if (Findint >= 0)
			{
				szTag.erase(0, szTag.find('_', szTag.length() - 3) + 1);

				pRobot = CRobot::Create(m_pGraphicDev, m_DynamicTag);
				pRobot->Set_Count(_wtoi(szTag.c_str()));
				pTransform = dynamic_cast<Engine::CTransform*>(pRobot->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
				pTransform->Set_Scale(vScale.x, vScale.y, vScale.z);
				pTransform->Rotation(Engine::ROT_X, vAngle.x);
				pTransform->Rotation(Engine::ROT_Y, vAngle.y);
				pTransform->Rotation(Engine::ROT_Z, vAngle.z);
				pTransform->Set_Pos(vPos.x, vPos.y, vPos.z);

				m_mapLayer.find(L"GameLogic")->second->Add_GameObject(pRobot->GetObjTag(), pRobot);
				continue;

			}

			pDynamicMesh = CDynamicMeshObj::Create(m_pGraphicDev, m_MeshTag , m_DynamicTag);
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
			if (i == 80 || i == 81)
			{
				dynamic_cast<Engine::CNaviMesh*>(Get_Component(L"GameLogic", L"RobotLaser_0", L"Com_Navi", Engine::ID_STATIC))->Add_Cell(vPointA, vPointB, vPointC);
				dynamic_cast<Engine::CNaviMesh*>(Get_Component(L"GameLogic", L"RobotLaser_1", L"Com_Navi", Engine::ID_STATIC))->Add_Cell(vPointA, vPointB, vPointC);
			}
		}

		if (0 == dwByte)
			break;
	}
	CloseHandle(hFile);

	return;
}

void CStage2::MoveCamera()
{
	CStaticCamera* pCam = dynamic_cast<CStaticCamera*>(Engine::Get_GameObj(L"GameLogic", L"StaticCamera"));
	Engine::CTransform* pPlayerTrans = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
	_vec3 vPos = *pPlayerTrans->Get_Info(Engine::INFO_POS);
	if (108	== m_pNaviCom->Get_Index() || 109 == m_pNaviCom->Get_Index()
		|| 110 == m_pNaviCom->Get_Index() || 111 == m_pNaviCom->Get_Index()
		|| 112 == m_pNaviCom->Get_Index() || 113 == m_pNaviCom->Get_Index())
	{
		pCam->Set_Destination(_vec3(vPos.x, 8.f, vPos.z-1.f), _vec3(vPos.x, 0.f, vPos.z));
	}

	if (133 == m_pNaviCom->Get_Index() || 134 == m_pNaviCom->Get_Index())
	{
		pCam->Set_Destination(_vec3(36.f , 10.f,17.f), _vec3(36.f ,0.f,21.f) );
	}
}


//52번 인덱스 / 53번 인덱스 = 파워셀 입구
//70번 인덱스 / 71번 인덱스 = 열리는 입구
//131번 인덱스 / 132번 인덱스 = 해치 있는곳
//141번 인덱스 / 142번 인덱스 = 포탈끝난 후 입구 앞
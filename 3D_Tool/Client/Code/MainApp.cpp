#include "stdafx.h"
#include "MainApp.h"

#include "Export_Function.h"
#include "Logo.h"
#include "Stage.h"
#include "SoundMgr.h"

CMainApp::CMainApp(void)
{

}

CMainApp::~CMainApp(void)
{

}

HRESULT CMainApp::Ready_MainApp(void)
{
	FAILED_CHECK_RETURN(SetUp_DefaultSetting(&m_pGraphicDev), E_FAIL);

	FAILED_CHECK_RETURN(Engine::Get_Renderer()->Ready_Renderer(m_pGraphicDev), E_FAIL);

	FAILED_CHECK_RETURN(Ready_Scene(m_pGraphicDev, &m_pManagement), E_FAIL);

	m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, FALSE);

	return S_OK;
}

_int CMainApp::Update_MainApp(const _float& fTimeDelta)
{
	Engine::Set_InputDev();
	CSoundMgr::GetInstance()->UpdateSound();
	if (nullptr != m_pManagement)
		m_pManagement->Update_Scene(fTimeDelta);

	/*_long	dwMouseMove = 0;

	if (dwMouseMove = Engine::Get_DIMouseMove(Engine::DIMS_Z))
	{
		int a = 0;
	}*/


	return 0;
}

_int CMainApp::LateUpdate_MainApp(const _float & fTimeDelta)
{
	if (nullptr != m_pManagement)
		m_pManagement->LateUpdate_Scene(fTimeDelta);

	return 0;
}

void CMainApp::Render_MainApp(void)
{
	//m_pGraphicDev->SetRenderState(D3DRS_ZENABLE, TRUE);			// Z���ۿ� ������ �ϵ�, �ڵ� ������ ���� ���� ������ �Ǵ��ϴ� �ɼ�
	//m_pGraphicDev->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);	// Z���ۿ� �ȼ����� ���� ���� ���� ���� ������ �Ǵ��ϴ� �ɼ�

	Engine::Render_Begin(D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.f));
	
	if (nullptr != m_pManagement)
		m_pManagement->Render_Scene(m_pGraphicDev);

	Engine::Render_End();
}

HRESULT CMainApp::SetUp_DefaultSetting(LPDIRECT3DDEVICE9 * ppGraphicDev)
{
	FAILED_CHECK_RETURN(Engine::Ready_GraphicDev(g_hWnd,
		Engine::MODE_WIN,
		WINCX,
		WINCY,
		&m_pDeviceClass),
		E_FAIL);

	m_pDeviceClass->AddRef();

	(*ppGraphicDev) = m_pDeviceClass->GetDevice();
	(*ppGraphicDev)->AddRef();

	// FONT

	FAILED_CHECK_RETURN(Engine::Ready_Font(m_pGraphicDev, L"Font_Default", L"�ü�", 20, 40, FW_HEAVY), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Font(m_pGraphicDev, L"Font_Second", L"����", 10, 10, FW_THIN), E_FAIL);

	// INPUTDEV
	FAILED_CHECK_RETURN(Engine::Ready_InputDev(g_hInst, g_hWnd), E_FAIL);
	
	CSoundMgr::GetInstance()->Initialize();

	return S_OK;
}

HRESULT CMainApp::Ready_Scene(LPDIRECT3DDEVICE9& pGraphicDev, 
								Engine::CManagement ** ppManagement)
{
	Engine::CScene*		pScene = nullptr;

	FAILED_CHECK_RETURN(Engine::Create_Management(pGraphicDev,ppManagement), E_FAIL);
	(*ppManagement)->AddRef();

	pScene = CLogo::Create(pGraphicDev);
	NULL_CHECK_RETURN(pScene, E_FAIL);

	FAILED_CHECK_RETURN((*ppManagement)->SetUp_Scene(pScene), E_FAIL);
	
	return S_OK;
}

CMainApp* CMainApp::Create(void)
{
	CMainApp*	pInstance = new CMainApp;

	if (FAILED(pInstance->Ready_MainApp()))
		Safe_Release(pInstance);

	return pInstance;
}

void CMainApp::Free(void)
{
	CSoundMgr::GetInstance()->DestroyInstance();
	Engine::Safe_Release(m_pGraphicDev);
	Engine::Safe_Release(m_pDeviceClass);
	Engine::Safe_Release(m_pManagement);

	Engine::Release_Resources();
	Engine::Release_Utility();
	Engine::Release_System();
}


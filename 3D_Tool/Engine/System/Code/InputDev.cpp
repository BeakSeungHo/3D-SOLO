#include "InputDev.h"

USING(Engine)
IMPLEMENT_SINGLETON(CInputDev)

Engine::CInputDev::CInputDev(void)
{
	ZeroMemory(m_byKeyDown, sizeof(m_byKeyDown));
	ZeroMemory(m_byKeyState,sizeof(m_byKeyState));
}

Engine::CInputDev::~CInputDev(void)
{
	Free();
}

_bool CInputDev::KeyDown(_ubyte byKeyID)
{
	if (!m_byKeyDown[byKeyID] && m_byCurKey[byKeyID])
	{
		m_byKeyDown[byKeyID] = true;
		return true;
	}
	// ���� ������ �ְ� ���� ������ �ʾ��� �� FALSE
	if (m_byKeyDown[byKeyID] && !m_byCurKey[byKeyID])
	{
		m_byKeyDown[byKeyID] = false;
		return false;
	}

	return false;
}

_bool CInputDev::KeyPressing(_ubyte byKeyID)
{
	if (m_byCurKey[byKeyID])
		return true;

	return false;
}

HRESULT Engine::CInputDev::Ready_InputDev(HINSTANCE hInst, HWND hWnd)
{

	// DInput �İ�ü�� �����ϴ� �Լ�
	FAILED_CHECK_RETURN(DirectInput8Create(hInst,
											DIRECTINPUT_VERSION,
											IID_IDirectInput8,
											(void**)&m_pInputSDK,
											NULL), E_FAIL);

	// Ű���� ��ü ����
	FAILED_CHECK_RETURN(m_pInputSDK->CreateDevice(GUID_SysKeyboard, &m_pKeyBoard, nullptr), E_FAIL);

	// ������ Ű���� ��ü�� ���� ������ �� ��ü���� �����ϴ� �Լ�
	m_pKeyBoard->SetDataFormat(&c_dfDIKeyboard);

	// ��ġ�� ���� �������� �������ִ� �Լ�, (Ŭ���̾�Ʈ�� ���ִ� ���¿��� Ű �Է��� ������ ������ �����ϴ� �Լ�)
	m_pKeyBoard->SetCooperativeLevel(hWnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);

	// ��ġ�� ���� access ������ �޾ƿ��� �Լ�
	m_pKeyBoard->Acquire();


	// ���콺 ��ü ����
	FAILED_CHECK_RETURN(m_pInputSDK->CreateDevice(GUID_SysMouse, &m_pMouse, nullptr), E_FAIL);

	// ������ ���콺 ��ü�� ���� ������ �� ��ü���� �����ϴ� �Լ�
	m_pMouse->SetDataFormat(&c_dfDIMouse);

	// ��ġ�� ���� �������� �������ִ� �Լ�, Ŭ���̾�Ʈ�� ���ִ� ���¿��� Ű �Է��� ������ ������ �����ϴ� �Լ�
	m_pMouse->SetCooperativeLevel(hWnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);

	// ��ġ�� ���� access ������ �޾ƿ��� �Լ�
	m_pMouse->Acquire();


	return S_OK;
}

void Engine::CInputDev::Set_InputDev(void)
{
	m_pKeyBoard->GetDeviceState(256, m_byKeyState);
	m_pMouse->GetDeviceState(sizeof(m_tMouseState), &m_tMouseState);

	ZeroMemory(m_byCurKey, sizeof(m_byCurKey));

	if (m_byKeyState[DIK_UP] & 0x80)
		m_byCurKey[DIK_UP] |= m_byKeyState[DIK_UP];
	if (m_byKeyState[DIK_DOWN] & 0x80)
		m_byCurKey[DIK_DOWN] |= m_byKeyState[DIK_DOWN];
	if(m_byKeyState[DIK_LEFT] & 0x80)
		m_byCurKey[DIK_LEFT] |= m_byKeyState[DIK_LEFT];
	if (m_byKeyState[DIK_RIGHT] & 0x80)
		m_byCurKey[DIK_RIGHT] |= m_byKeyState[DIK_RIGHT];
	if (m_byKeyState[DIK_RETURN] & 0x80)
		m_byCurKey[DIK_RETURN] |= m_byKeyState[DIK_RETURN];
	if (m_byKeyState[DIK_C] & 0x80)
		m_byCurKey[DIK_C] |= m_byKeyState[DIK_C];
	if (m_byKeyState[DIK_F] & 0x80)
		m_byCurKey[DIK_F] |= m_byKeyState[DIK_F];
	if (m_byKeyState[DIK_R] & 0x80)
		m_byCurKey[DIK_R] |= m_byKeyState[DIK_R];
	if (m_byKeyState[DIK_X] & 0x80)
		m_byCurKey[DIK_X] |= m_byKeyState[DIK_X];
	
}

void Engine::CInputDev::Free(void)
{
	Engine::Safe_Release(m_pKeyBoard);
	Engine::Safe_Release(m_pMouse);
	Engine::Safe_Release(m_pInputSDK);
}


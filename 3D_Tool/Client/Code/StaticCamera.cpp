#include "stdafx.h"
#include "StaticCamera.h"

#include "Export_Function.h"

CStaticCamera::CStaticCamera(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CCamera(pGraphicDev)
{

}

CStaticCamera::~CStaticCamera(void)
{

}

void CStaticCamera::SetUp_Target(Engine::CTransform* pTargetInfo)
{
	m_pTargetInfo = pTargetInfo;
}

HRESULT CStaticCamera::Ready_GameObject(const _vec3* pEye,
										const _vec3* pAt,
										const _vec3* pUp,
										const _float& fFovY,
										const _float& fAspect,
										const _float& fNear,
										const _float& fFar)
{
	m_vEye = *pEye;
	m_vAt = *pAt;
	m_vUp = *pUp;

	m_fFovY = fFovY;
	m_fAspect = fAspect;
	m_fNear = fNear;
	m_fFar = fFar;

	FAILED_CHECK_RETURN(Engine::CCamera::Ready_GameObject(), E_FAIL);


	return S_OK;
}

_int CStaticCamera::Update_GameObject(const _float& fTimeDelta)
{
	if (m_bIsFix)
	{
		m_vEye = m_vFixEye;
		m_vAt = m_vFixAt;
	}
	else if(m_bIsDest)
		Move_Dest(fTimeDelta);
	else
		Target_Renewal(fTimeDelta);
	//Key_Input(fTimeDelta);

	_int iExit = Engine::CCamera::Update_GameObject(fTimeDelta);

	return iExit;
}

void CStaticCamera::Set_Destination(_vec3 vDestEye, _vec3 vDestAt)
{
	m_vDesEye = vDestEye;
	m_vDesAt = vDestAt;
	
	m_bIsDest = true;
}

void CStaticCamera::Set_Fix(_vec3 vFixEye, _vec3 vFixAt)
{
	m_vFixEye = vFixEye;
	m_vFixAt = vFixAt;
	
	m_bIsFix = true;
}

void CStaticCamera::Set_IsDest(_bool bIsDest)
{
	m_bIsDest = bIsDest;
}

void CStaticCamera::Set_IsFix(_bool bIsFix)
{
	m_bIsFix = bIsFix;
}

void CStaticCamera::Set_Distance(_float fDist)
{
	m_fDistance = fDist;
}

void CStaticCamera::Key_Input(const _float& fTimeDelta)
{
	/*if (Engine::Get_DIKeyState(DIK_Q) & 0x80)
		m_fAngle += D3DXToRadian(45.f) * fTimeDelta;

	if (Engine::Get_DIKeyState(DIK_A) & 0x80)
		m_fAngle -= D3DXToRadian(45.f) * fTimeDelta;

	if (Engine::Get_DIKeyState(DIK_O) & 0x80)
		m_fDistance += fTimeDelta * 20.f;

	if (Engine::Get_DIKeyState(DIK_P) & 0x80)
		m_fDistance -= fTimeDelta * 20.f;*/
}

void CStaticCamera::Target_Renewal(const _float& fTimeDelta)
{
	//m_vEye = m_pTargetInfo->m_vInfo[Engine::INFO_LOOK] * -1.f;
	//D3DXVec3Normalize(&m_vEye, &m_vEye);

	//m_vEye *= m_fDistance;

	//_vec3		vRight;
	//memcpy(&vRight, &m_pTargetInfo->m_matWorld.m[0][0], sizeof(_vec3));

	//_matrix		matRotAxis;
	//D3DXMatrixRotationAxis(&matRotAxis, &vRight, m_fAngle);
	//D3DXVec3TransformNormal(&m_vEye, &m_vEye, &matRotAxis);

	_vec3 vEye, vAt;

	vEye = _vec3(m_pTargetInfo->m_vInfo[Engine::INFO_POS].x, m_fDistance, m_pTargetInfo->m_vInfo[Engine::INFO_POS].z - 4);;
	vAt = m_pTargetInfo->m_vInfo[Engine::INFO_POS];

	D3DXVec3Lerp(&m_vEye, &m_vEye, &vEye, 0.1f);
	D3DXVec3Lerp(&m_vAt, &m_vAt, &vAt, 0.1f);

}

void CStaticCamera::Move_Dest(const _float & fTimeDelta)
{
	D3DXVec3Lerp(&m_vEye, &m_vEye, &m_vDesEye, 0.1f);
	D3DXVec3Lerp(&m_vAt, &m_vAt, &m_vDesAt, 0.1f);

	if (D3DXVec3Length(&(m_vDesEye - m_vEye)) < 0.1f && D3DXVec3Length(&(m_vDesAt - m_vAt)) < 0.1f)
		m_bIsDest = false;
}

CStaticCamera* CStaticCamera::Create(LPDIRECT3DDEVICE9 pGraphicDev, 
									Engine::CTransform* pTargetInfo,
									const _vec3* pEye,
									const _vec3* pAt,
									const _vec3* pUp,
									const _float& fFovY,
									const _float& fAspect,
									const _float& fNear,
									const _float& fFar)
{
	CStaticCamera*	pInstance = new CStaticCamera(pGraphicDev);

	if (FAILED(pInstance->Ready_GameObject(pEye, pAt, pUp, fFovY, fAspect, fNear, fFar)))
		Engine::Safe_Release(pInstance);
	
	pInstance->SetUp_Target(pTargetInfo);

	return pInstance;
}

void CStaticCamera::Free(void)
{
	Engine::CCamera::Free();
}


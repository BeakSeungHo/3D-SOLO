#ifndef StaticCamera_h__
#define StaticCamera_h__

#include "Defines.h"
#include "Camera.h"

BEGIN(Engine)

class CTransform;

END
class CStaticCamera : public Engine::CCamera
{
private:
	explicit CStaticCamera(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CStaticCamera(void);

public:
	void	SetUp_Target(Engine::CTransform* pTargetInfo);

public:
	HRESULT Ready_GameObject(const _vec3* pEye,
							const _vec3* pAt,
							const _vec3* pUp,
							const _float& fFovY,
							const _float& fAspect,
							const _float& fNear,
							const _float& fFar);
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	
	void	Set_Destination(_vec3 vDestEye, _vec3 vDestAt);
	void	Set_Fix(_vec3 vFixEye, _vec3 vFixAt);

	void	Set_IsDest(_bool bIsDest);
	void	Set_IsFix(_bool bIsFix);

	void	Set_Distance(_float fDist);

private:
	void	Key_Input(const _float& fTimeDelta);
	void	Target_Renewal(const _float& fTimeDelta);
	void	Move_Dest(const _float& fTimeDelta);

private:
	Engine::CTransform*		m_pTargetInfo = nullptr;
	_float					m_fDistance = 6.f;
	_float					m_fAngle = 0.f;
	_float					m_fDestTime = 0.f;
	_bool					m_bIsDest = false;
	_bool					m_bIsFix = false;
	_vec3					m_vFixEye, m_vFixAt;
	_vec3					m_vDesEye, m_vDesAt;

public:
	static CStaticCamera*		Create(LPDIRECT3DDEVICE9 pGraphicDev, 
										Engine::CTransform* pTargetInfo,
										const _vec3* pEye,
										const _vec3* pAt,
										const _vec3* pUp,
										const _float& fFovY,
										const _float& fAspect,
										const _float& fNear,
										const _float& fFar);

private:
	virtual void Free(void) override;

};


#endif // StaticCamera_h__

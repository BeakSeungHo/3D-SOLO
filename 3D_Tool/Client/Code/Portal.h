#ifndef Portal_h__
#define Portal_h__

#include "Defines.h"
#include "GameObject.h"

BEGIN(Engine)

class CRcTex;
class CTexture;
class CTransform;
class CRenderer;
class CShader;
class CCalculator;
class CColliderSphere;

END

class CPortal : public Engine::CGameObject
{
private:
	explicit CPortal(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CPortal(void);

public:
	virtual HRESULT Ready_GameObject(void) override;
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;
	void	Set_bIsMove(_bool bIsMove);
	void	Set_MaxFrame(_float fMaxFrame);

private:
	HRESULT		Add_Component(void);
	_bool		Collision_ToObject(const _tchar* pLayerTag);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CRcTex*				m_pBufferCom = nullptr;
	Engine::CTexture*			m_pTextureCom = nullptr;
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CShader*			m_pShaderCom = nullptr;
	Engine::CCalculator*		m_pCalculatorCom = nullptr;
	Engine::CColliderSphere*	m_pColiderSphereCom = nullptr;
	
	_float						m_fFrameCnt = 0;
	_float						m_fFrameMax = 32.f;
	
	_bool						m_bIsMove = false;
	_int						m_iMoveCount = 0;
	_float						m_fTimeAcc= 0.f;
	_tchar						m_TexTag[128];

public:
	static CPortal*		Create(LPDIRECT3DDEVICE9 pGraphicDev, wstring TexTag);

private:
	virtual void Free(void) override;
};

#endif // Portal_h__

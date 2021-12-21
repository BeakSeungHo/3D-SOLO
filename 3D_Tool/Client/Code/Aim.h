#ifndef Aim_h__
#define Aim_h__

#include "Defines.h"
#include "GameObject.h"

BEGIN(Engine)

class CRcTex;
class CTexture;
class CTransform;
class CRenderer;
class CShader;
class CColliderSphere;

END

class CAim : public Engine::CGameObject
{
private:
	explicit CAim(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CAim(void);

public:
	virtual HRESULT Ready_GameObject(void) override;
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;

private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CRcTex*				m_pBufferCom = nullptr;
	Engine::CTexture*			m_pTextureCom = nullptr;
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CShader*			m_pShaderCom = nullptr;
	Engine::CColliderSphere*	m_pColiderSphereCom = nullptr;

	_float					m_fFrameCnt = 0;
	_float					m_fFrameMax = 2.f;
	
public:
	static CAim*		Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;
};

#endif // Aim_h__

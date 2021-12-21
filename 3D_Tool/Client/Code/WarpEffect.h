#ifndef WarpEffect_h__
#define WarpEffect_h__

#include "Defines.h"
#include "GameObject.h"

BEGIN(Engine)

class CRcTex;
class CTexture;
class CTransform;
class CRenderer;
class CShader;

END

class CPlayer;
class CWarpEffect : public Engine::CGameObject
{
private:
	explicit CWarpEffect(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CWarpEffect(void);

public:
	virtual HRESULT Ready_GameObject(void) override;
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;

private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& Effect);

private:
	Engine::CRcTex*			m_pBufferCom = nullptr;
	Engine::CTexture*		m_pTextureCom = nullptr;
	Engine::CTransform*		m_pTransformCom = nullptr;
	Engine::CRenderer*		m_pRendererCom = nullptr;
	Engine::CShader*		m_pShaderCom = nullptr;
	CPlayer*				m_pPlayer = nullptr;

	_float					m_fFrameCnt = 0;
	_float					m_fFrameMax = 16.f;
	
public:
	static CWarpEffect*		Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;
};

#endif // WarpEffect_h__

#ifndef Smoke_h__
#define Smoke_h__

#include "Defines.h"
#include "GameObject.h"

BEGIN(Engine)

class CRcTex;
class CTexture;
class CTransform;
class CRenderer;
class CShader;

END

class CSmoke : public Engine::CGameObject
{
private:
	explicit CSmoke(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CSmoke(void);

public:
	virtual HRESULT Ready_GameObject(void) override;
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;
	_tchar*	Get_ObjTag() { return m_ObjTag; }

private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CRcTex*			m_pBufferCom = nullptr;
	Engine::CTexture*		m_pTextureCom = nullptr;
	Engine::CTransform*		m_pTransformCom = nullptr;
	Engine::CRenderer*		m_pRendererCom = nullptr;
	Engine::CShader*		m_pShaderCom = nullptr;

	_float					m_fFrameCnt = 0;
	_float					m_fFrameMax = 1.f;
	_tchar					m_ObjTag[128];

public:
	static CSmoke*		Create(LPDIRECT3DDEVICE9 pGraphicDev, wstring ObjTag);

private:
	virtual void Free(void) override;
};

#endif // Smoke_h__

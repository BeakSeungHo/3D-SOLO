#ifndef LaunchEffect_h__
#define LaunchEffect_h__

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
class CLaunchEffect : public Engine::CGameObject
{
private:
	explicit CLaunchEffect(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CLaunchEffect(void);

public:
	virtual HRESULT Ready_GameObject(void) override;
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;
	_tchar*		Get_ObjTag() { return m_ObjTag; }

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

	_float					m_fTimeAcc = 0.f;
	_tchar					m_ObjTag[128];
	
public:
	static CLaunchEffect*		Create(LPDIRECT3DDEVICE9 pGraphicDev, wstring ObjTag);

private:
	virtual void Free(void) override;
};

#endif // LaunchEffect_h__

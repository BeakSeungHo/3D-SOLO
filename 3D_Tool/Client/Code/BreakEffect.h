#ifndef BreakEffect_h__
#define BreakEffect_h__

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
class CBreakEffect : public Engine::CGameObject
{
private:
	explicit CBreakEffect(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CBreakEffect(void);

public:
	virtual HRESULT Ready_GameObject(void) override;
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;
	void	Set_Scale(_int iScale);

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
	_float					m_fScale = 0.f;
	
public:
	static CBreakEffect*		Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;
};

#endif // BreakEffect_h__

#ifndef Button_h__
#define Button_h__

#include "Defines.h"
#include "GameObject.h"

BEGIN(Engine)

class CRcTex;
class CTexture;
class CTransform;
class CRenderer;
class CShader;

END

class CButton : public Engine::CGameObject
{
private:
	explicit CButton(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CButton(void);

public:
	virtual HRESULT Ready_GameObject(void) override;
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;

	_int	Get_TexCnt() { return m_iTexCnt; }
	void	Set_TexCnt(_int iCnt);

private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CRcTex*			m_pBufferCom = nullptr;
	Engine::CTexture*		m_pTextureCom = nullptr;
	Engine::CTransform*		m_pTransformCom = nullptr;
	Engine::CRenderer*		m_pRendererCom = nullptr;
	Engine::CShader*		m_pShaderCom = nullptr;

	_int					m_iTexCnt = 0;
	_tchar					m_TexTag[128];
	
public:
	static CButton*		Create(LPDIRECT3DDEVICE9 pGraphicDev, wstring TexTag);

private:
	virtual void Free(void) override;
};

#endif // Button_h__

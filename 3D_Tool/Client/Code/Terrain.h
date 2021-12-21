#ifndef Terrain_h__
#define Terrain_h__

#include "Defines.h"
#include "GameObject.h"

BEGIN(Engine)

class CTerrainTex;
class CTexture;
class CTransform;
class CRenderer;
class CCalculator;
class CColliderSphere;
class COptimization;
class CShader;

END

class CTerrain : public Engine::CGameObject
{
private:
	explicit CTerrain(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CTerrain(void);

public:
	virtual HRESULT Ready_GameObject(void) override;
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;
	void	BlinkTile();
	void	SetTexCount(_int iCount);
	void	SetDraw(_bool bDraw);
	void	SetBlinkTile(_bool bBlink);

	_bool	GetDraw() { return m_bIsDraw; }
	_bool	GetBlink() { return m_bBlink; }

private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);
	_bool		Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag);

private:
	Engine::CTerrainTex*		m_pBufferCom = nullptr;
	Engine::CTexture*			m_pTextureCom = nullptr;
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CCalculator*		m_pCalculatorCom = nullptr;
	Engine::CColliderSphere*	m_pColiderSphereCom = nullptr;
	Engine::COptimization*		m_pOptimizationCom = nullptr;
	Engine::CShader*			m_pShaderCom = nullptr;

	_int					m_iTexCount = 0;
	_int					m_iBufferCount = 0;
	
	Engine::INDEX32*		m_pIndex = nullptr;
	_ulong					m_dwTriCnt = 0;

	_bool					m_bIsDraw = true;
	_bool					m_bColl = false;
	_bool					m_bBlink = false;
	_float					m_fAlphaAcc = 1.f;
	_int					m_iBlinkCount = 0;

public:
	static CTerrain*		Create(LPDIRECT3DDEVICE9 pGraphicDev, _int BufferCount);

private:
	virtual void Free(void) override;
};

#endif // Terrain_h__

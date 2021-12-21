#ifndef Laser_h__
#define Laser_h__

#include "Defines.h"
#include "GameObject.h"

BEGIN(Engine)

class CCalculator;
class CTransform;
class CRenderer;
class CShader;
class CNaviMesh;
class CColliderBox;

END

class CLaser : public Engine::CGameObject
{
protected:
	explicit CLaser(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CLaser(void);

public:
	virtual HRESULT Ready_GameObject(void) override;
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;

private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

protected:
	Engine::CCalculator*		m_pCalculatorCom = nullptr;
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CShader*			m_pShaderCom = nullptr;
	Engine::CColliderBox*		m_pColiderBoxCom = nullptr;
	Engine::CNaviMesh*			m_pNaviCom = nullptr;
	ID3DXLine*					m_pLine = nullptr;
	D3DXVECTOR3					m_vLaser[2];
	
	const	_matrix*			m_pParentBoneMatrix = nullptr;
	const	_matrix*			m_pParentWorldMatrix = nullptr;

	_int						m_iCount = 0;
	wstring						m_szParentTag;
	_bool						m_bColl = false;
	
public:
	static CLaser*		Create(LPDIRECT3DDEVICE9 pGraphicDev);

protected:
	virtual void Free(void) override;
};

#endif // Laser_h__

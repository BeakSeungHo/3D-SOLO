#ifndef Clone_h__
#define Clone_h__

#include "Defines.h"
#include "GameObject.h"

BEGIN(Engine)

class CDynamicMesh;
class CTransform;
class CRenderer;
class CCalculator;
class CColliderSphere;
class CColliderBox;
class CShader;

END

class CClone : public Engine::CGameObject
{
private:
	explicit CClone(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CClone(void);

public:
	virtual HRESULT Ready_GameObject(void) override;
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;
	void	Set_bIsColl(_bool bIsColl);

private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CCalculator*		m_pCalculatorCom = nullptr;
	Engine::CDynamicMesh*		m_pMeshCom = nullptr;
	Engine::CColliderBox*		m_pColliderBoxCom = nullptr;
	Engine::CColliderSphere*	m_pColiderSphereCom = nullptr;
	Engine::CShader*			m_pShaderCom = nullptr;

	_bool					m_bIsColl = false;


public:
	static CClone*		Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;
};

#endif // Clone_h__

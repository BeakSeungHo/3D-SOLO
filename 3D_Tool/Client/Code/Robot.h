#ifndef Robot_h__
#define Robot_h__

#include "Defines.h"
#include "GameObject.h"

BEGIN(Engine)

class CNaviMesh;
class CDynamicMesh;
class CTransform;
class CRenderer;
class CCalculator;
class CColliderBox;
class CColliderSphere;
class CShader;

END

class CRobot : public Engine::CGameObject
{
private:
	explicit CRobot(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CRobot(void);

public:
	virtual HRESULT Ready_GameObject(void) override;
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual _int LateUpdate_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;
	void	Set_Count(_int iCount);
	void	Set_State(ROBOTSTATE eState);

	_tchar*		GetObjTag() { return m_ObjTag; }

private:
	HRESULT		Add_Component(void);
	_bool		Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CCalculator*		m_pCalculatorCom = nullptr;
	Engine::CDynamicMesh*		m_pMeshCom = nullptr;
	Engine::CColliderBox*		m_pColliderBoxCom = nullptr;
	Engine::CColliderSphere*	m_pColiderSphereCom = nullptr;
	Engine::CShader*			m_pShaderCom = nullptr;

	_int						m_iCount = 0;
	_float						m_fAngle = 0;
	_bool						m_bColl = false;
	_float						m_fSpeed = 0.5f;
	_tchar						m_ObjTag[128];
	ROBOTSTATE					m_eCurState;

public:
	static CRobot*		Create(LPDIRECT3DDEVICE9 pGraphicDev, wstring ObjTag);

private:
	virtual void Free(void) override;
};

#endif // Robot_h__

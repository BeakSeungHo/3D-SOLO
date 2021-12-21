#ifndef Boss_h__
#define Boss_h__

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

class CBoss : public Engine::CGameObject
{
private:
	explicit CBoss(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CBoss(void);

public:
	virtual HRESULT Ready_GameObject(void) override;
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual _int LateUpdate_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;
	void	Set_Count(_int iCount);
	void	Set_State(BOSSSTATE eState);
	void	Set_BrokenCountUP();

private:
	HRESULT		Add_Component(void);
	_bool		Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag);
	_bool		Collision_Attack();
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CCalculator*		m_pCalculatorCom = nullptr;
	Engine::CDynamicMesh*		m_pMeshCom = nullptr;
	Engine::CColliderBox*		m_pColliderBoxCom = nullptr;
	Engine::CColliderSphere*	m_pColliderSphereCom = nullptr;
	Engine::CColliderSphere*	m_pAttackSphereCom = nullptr;
	Engine::CShader*			m_pShaderCom = nullptr;

	_int						m_iCount = 0;
	_float						m_fAngle = 0;
	_bool						m_bColl = false;
	_bool						m_bFrist = true;
	_bool						m_bAttackColl = false;
	_float						m_fSpeed = 0.5f;
	BOSSSTATE					m_eCurState;

	Engine::CGameObject*		m_pTarget = nullptr;
	_vec3						m_vecPatrol[5];
	_vec3						m_vDir = {0.f,0.f,0.f};
	_vec3						m_vSlide = {0.f,0.f,0.f};
	_vec3						m_vSlideNoraml = {0.f,0.f,0.f};
	_int						m_iPatrolCount = 0;
	_int						m_iBrokenCount = 0;
	_matrix						m_matRightArm;

public:
	static CBoss*		Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;
};

#endif // Boss_h__

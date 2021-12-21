#ifndef Player_h__
#define Player_h__

#include "Defines.h"
#include "GameObject.h"

BEGIN(Engine)

class CNaviMesh;
class CDynamicMesh;
class CStaticMesh;
class CTransform;
class CRenderer;
class CCalculator;
class CColliderSphere;
class CColliderBox;
class CShader;

END

class CAim;
class CClone;
class CWarpEffect;
class CCloneEffect;
class CBreakEffect;
class CPlayer : public Engine::CGameObject
{
private:
	explicit CPlayer(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CPlayer(void);

public:
	virtual HRESULT Ready_GameObject(void) override;
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual _int LateUpdate_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;
	void	Set_bIsColl(_bool bIsColl);
	void	Set_bIsConveyor(_bool bIsConveyor);
	void	Set_bIsObj(_bool bIsObj);
	void	Set_Triger(_bool bIsTriger);
	void	Set_bWarpEffect(_bool bWarpEffect);

	void	Set_CheckPos(_vec3 vCheckPos);
	void	Set_CloneMesh(Engine::CStaticMesh* pClone);
	void	InputTile(_int iIndex);

public:
	_bool					GetbIsBreak() { return m_bIsBreak; }
	_bool					GetbIsObj() { return m_bIsInObj; }
	_bool					GetbIsWarp() { return m_bIsWarp; }
	_bool					GetbIsConveyor() { return m_bIsConveyor; }
	_bool					GetbIsClone() { return m_bIsClone; }
	Engine::CStaticMesh*	GetCloneMesh() { return m_pCloneObjMeshCom; }
	CAim*					GetAim()	{ return m_pAim; }
	vector<_int>*			GetPlayerTile() { return &m_CheckTileVec; }

private:
	HRESULT		Add_Component(void);
	void		Key_Input(const _float& fTimeDelta);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CCalculator*		m_pCalculatorCom = nullptr;
	Engine::CDynamicMesh*		m_pMeshCom = nullptr;
	Engine::CStaticMesh*		m_pCloneObjMeshCom = nullptr;
	Engine::CNaviMesh*			m_pNaviCom = nullptr;
	Engine::CColliderBox*		m_pColliderBoxCom = nullptr;
	Engine::CColliderSphere*	m_pColiderSphereCom = nullptr;
	Engine::CShader*			m_pShaderCom = nullptr;

	CAim*						m_pAim = nullptr;
	CClone*						m_pClone = nullptr;
	CWarpEffect*				m_pWarpEffect = nullptr;
	CCloneEffect*				m_pCloneEffect = nullptr;
	//CBreakEffect*				m_pBreakEffect = nullptr;

	_bool					m_bIsColl = false;
	_bool					m_bIsConveyor = false;
	_bool					m_bIsWarp = false;
	_bool					m_bWarpEffect = false;
	_bool					m_bIsInObj = false;
	_bool					m_bIsBreak = false;
	_bool					m_bIsTriger = false;
	_bool					m_bIsClone = false;
	_bool					m_bFirst = true;
	_vec3					m_vPos, m_vDir, vPastPos, m_vCheckPos;
	_float					m_fSpeed = 2.f;
	vector<_int>			m_CheckTileVec;
	_int					m_iBreakCount = 0;
	_float					m_fTimeAcc = 0.f;
	_float					m_fBreakTimeAcc = 0.f;

	PLAYERSTATE				m_eCurState;

public:
	static CPlayer*		Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;
};

#endif // Player_h__

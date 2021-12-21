#ifndef MazeWall_h__
#define MazeWall_h__

#include "Defines.h"
#include "StaticMeshObj.h"

class CMazeWall : public CStaticMeshObj
{
private:
	explicit CMazeWall(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CMazeWall(void);

public:

public:
	HRESULT Ready_GameObject(const _uint& iFlag);
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual _int LateUpdate_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;
	void	Set_OriPos(_vec3 vOriPos);
	void	Set_Direction(_vec3 vDir);
	void	Set_Triger(_bool bTriger);
	void	Set_Action(_bool bAction);

	_bool	Get_Action() { return m_bIsAction; }

private:
	HRESULT		Add_Component(void);
	_bool		Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CCollider*			m_pColliderCom		= nullptr;
	Engine::CColliderSphere*	m_pColiderSphereCom = nullptr;

	_uint						m_iFlag = 0;
	_bool						m_bColl = false;
	_bool						m_bSphereColl = false;
	_bool						m_bDraw = true;
	_bool						m_bIsAction = false;
	_bool						m_bIsMove = false;
	_bool						m_bTriger = false;
	_vec3						m_vDir, m_vOriPos;

public:
	static CMazeWall*		Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag);

private:
	virtual void Free(void) override;
};

#endif // MazeWall_h__

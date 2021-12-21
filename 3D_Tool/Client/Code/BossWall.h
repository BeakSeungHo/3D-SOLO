#ifndef BossWall_h__
#define BossWall_h__

#include "Defines.h"
#include "StaticMeshObj.h"

class CBossWall : public CStaticMeshObj
{
private:
	explicit CBossWall(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CBossWall(void);

public:

public:
	HRESULT Ready_GameObject(const _uint& iFlag);
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual _int LateUpdate_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;
	void	Set_Break(_bool bIsBreak);

private:
	HRESULT		Add_Component(void);
	_bool		Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CCollider*			m_pColliderCom		= nullptr;
	Engine::CStaticMesh*		m_pNextMeshCom		= nullptr;
	Engine::CColliderSphere*	m_pColiderSphereCom = nullptr;

	_uint						m_iFlag = 0;
	_bool						m_bColl = false;
	_bool						m_bDraw = true;
	_bool						m_bFirst = true;
	_bool						m_bIsBreak = false;
	_bool						m_bIsChange = false;

public:
	static CBossWall*		Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag);

private:
	virtual void Free(void) override;
};

#endif // BossWall_h__

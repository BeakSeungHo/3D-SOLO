#ifndef Door_h__
#define Door_h__

#include "Defines.h"
#include "StaticMeshObj.h"

class CDoor : public CStaticMeshObj
{
private:
	explicit CDoor(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CDoor(void);

public:

public:
	HRESULT Ready_GameObject(const _uint& iFlag);
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual _int LateUpdate_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;
	void	Set_Move(_bool bIsMove);
	void	Set_OriPos(_vec3 vOriPos);
	void	Set_Direction(_vec3 vDir);

private:
	HRESULT		Add_Component(void);
	_bool		Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CCollider*			m_pColliderCom		= nullptr;
	Engine::CColliderSphere*	m_pColiderSphereCom = nullptr;

	_uint						m_iFlag = 0;
	_bool						m_bColl = false;
	_bool						m_bDraw = true;
	_bool						m_bIsMove = false;
	_bool						m_bIsSound = true;
	_vec3						m_vDir, m_vOriPos;

public:
	static CDoor*		Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag);

private:
	virtual void Free(void) override;
};

#endif // Door_h__

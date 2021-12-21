#ifndef DoorFrame_h__
#define DoorFrame_h__

#include "Defines.h"
#include "StaticMeshObj.h"

class CDoor;
class CDoorFrame : public CStaticMeshObj
{
private:
	explicit CDoorFrame(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CDoorFrame(void);

public:

public:
	HRESULT Ready_GameObject(const _uint& iFlag);
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual _int LateUpdate_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;
	void	Set_Count(_int iCount);
	void	Set_Coll(_bool bColl);

private:
	HRESULT		Add_Component(void);
	_bool		Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CCollider*			m_pColliderCom		= nullptr;
	Engine::CColliderSphere*	m_pColiderSphereCom = nullptr;

	CDoor*						m_pDoorLeft = nullptr;
	CDoor*						m_pDoorRight = nullptr;

	_bool						m_bColl = false;
	_bool						m_bDraw = true;
	_int						m_iCount;

public:
	static CDoorFrame*		Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag);

private:
	virtual void Free(void) override;
};

#endif // DoorFrame_h__

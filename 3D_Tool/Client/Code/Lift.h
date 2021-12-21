#ifndef Lift_h__
#define Lift_h__

#include "Defines.h"
#include "StaticMeshObj.h"

class CLift : public CStaticMeshObj
{
private:
	explicit CLift(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CLift(void);

public:

public:
	HRESULT Ready_GameObject(const _uint& iFlag);
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;

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


public:
	static CLift*		Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag);

private:
	virtual void Free(void) override;
};

#endif // Lift_h__

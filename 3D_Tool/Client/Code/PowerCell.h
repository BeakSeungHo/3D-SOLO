#ifndef PowerCell_h__
#define PowerCell_h__

#include "Defines.h"
#include "StaticMeshObj.h"

class CPowerCell : public CStaticMeshObj
{
private:
	explicit CPowerCell(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CPowerCell(void);

public:

public:
	HRESULT Ready_GameObject(const _uint& iFlag);
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual _int LateUpdate_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;

private:
	HRESULT		Add_Component(void);
	_bool		Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CCollider*			m_pColliderCom		= nullptr;
	Engine::CColliderSphere*	m_pColiderSphereCom = nullptr;

	_bool						m_bColl = false;

public:
	static CPowerCell*		Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag,wstring ObjTag);

private:
	virtual void Free(void) override;
};

#endif // PowerCell_h__

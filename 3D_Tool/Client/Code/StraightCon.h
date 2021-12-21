#ifndef StraightCon_h__
#define StraightCon_h__

#include "Defines.h"
#include "Conveyor.h"

class CStraightCon : public CConveyor
{
private:
	explicit CStraightCon(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CStraightCon(void);

public:

public:
	HRESULT Ready_GameObject(const _uint& iFlag);
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual _int LateUpdate_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;

private:
	HRESULT		Add_Component(void);
	_bool		Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag, const _float& fTimeDelta);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	_float						m_fTimeAcc = 0.f;
	_bool						m_bColl = false;
	_bool						m_bDraw = true;

public:
	static CStraightCon*		Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag);

private:
	virtual void Free(void) override;
};

#endif // StraightCon_h__

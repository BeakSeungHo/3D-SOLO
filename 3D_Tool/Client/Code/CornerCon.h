#ifndef CornerCon_h__
#define CornerCon_h__

#include "Defines.h"
#include "Conveyor.h"

class CCornerCon : public CConveyor
{
private:
	explicit CCornerCon(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CCornerCon(void);

public:

public:
	HRESULT Ready_GameObject(const _uint& iFlag);
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual _int LateUpdate_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;

	void Set_Reverse(_bool bIsReverse);

	_bool Get_Reverse() { return m_bIsReverse; }

private:
	HRESULT		Add_Component(void);
	_bool		Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag, const _float& fTimeDelta);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	_float						m_fTimeAcc = 0.f;
	_bool						m_bColl = false;
	_bool						m_bDraw = true;
	_bool						m_bIsReverse = false;

public:
	static CCornerCon*		Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag);

private:
	virtual void Free(void) override;
};

#endif // CornerCon_h__

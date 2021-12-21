#ifndef Conveyor_h__
#define Conveyor_h__

#include "Defines.h"
#include "StaticMeshObj.h"

class CConveyor : public CStaticMeshObj
{
protected:
	explicit CConveyor(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CConveyor(void);

public:
	HRESULT Ready_GameObject(const _uint& iFlag);
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;

private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

protected:
	Engine::CCollider*			m_pColliderCom		= nullptr;
	Engine::CColliderSphere*	m_pColiderSphereCom = nullptr;

	_float						m_fTimeAcc = 0.f;
	_uint						m_iFlag = 0;
	_bool						m_bColl = false;
	_bool						m_bDraw = true;
	_bool						m_bFirst = true;

public:
	static CConveyor*		Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag);

protected:
	virtual void Free(void) override;
};

#endif // Conveyor_h__

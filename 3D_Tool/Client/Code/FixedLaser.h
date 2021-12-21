#ifndef FixedLaser_h__
#define FixedLaser_h__

#include "Defines.h"
#include "Laser.h"

BEGIN(Engine)

class CCalculator;
class CTransform;
class CRenderer;
class CShader;
class CNaviMesh;
class CColliderBox;

END

class CFixedLaser : public CLaser
{
private:
	explicit CFixedLaser(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CFixedLaser(void);

public:
	virtual HRESULT Ready_GameObject(void) override;
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual _int LateUpdate_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;
	void	Set_Count(_int iCount);

private:
	HRESULT		Add_Component(void);
	_bool		Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

	_int						m_iCount = 0;
	wstring						m_szParentTag;
	_bool						m_bColl = false;
	_bool						m_bFirst = true;
	_vec3						vLaserStart, vLaserEnd;

public:
	static CFixedLaser*		Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;
};

#endif // FixedLaser_h__

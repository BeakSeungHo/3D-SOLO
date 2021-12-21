#ifndef RobotLaser_h__
#define RobotLaser_h__

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

class CRobotLaser : public CLaser
{
private:
	explicit CRobotLaser(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CRobotLaser(void);

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

private:
	_int						m_iCount = 0;
	wstring						m_szParentTag;
	_bool						m_bColl = false;
	_vec3						vLaserStart, vLaserEnd;
	
public:
	static CRobotLaser*		Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;
};

#endif // RobotLaser_h__

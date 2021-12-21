#ifndef RobotGun_h__
#define RobotGun_h__

#include "Defines.h"
#include "StaticMeshObj.h"

class CRobotGun : public CStaticMeshObj
{
private:
	explicit CRobotGun(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CRobotGun(void);

public:

public:
	HRESULT Ready_GameObject(const _uint& iFlag);
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;
	void	Set_Count(_int iCount);

private:
	HRESULT		Add_Component(void);

private:
	_uint					m_iFlag = 0;
	_int					m_iCount = 0;

	const	_matrix*		m_pParentBoneMatrix = nullptr;
	const	_matrix*		m_pParentWorldMatrix = nullptr;

public:
	static CRobotGun*		Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag , wstring ObjTag);

private:
	virtual void Free(void) override;
};

#endif // RobotGun_h__

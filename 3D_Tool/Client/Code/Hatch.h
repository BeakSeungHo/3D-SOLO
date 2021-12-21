#ifndef Hatch_h__
#define Hatch_h__

#include "Defines.h"
#include "StaticMeshObj.h"

class CShiny;
class CHatch : public CStaticMeshObj
{
private:
	explicit CHatch(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CHatch(void);

public:

public:
	HRESULT Ready_GameObject(const _uint& iFlag);
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual _int LateUpdate_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;
	void	Set_OriPos(_vec3 vOriPos);

private:
	HRESULT		Add_Component(void);
	_bool		Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CCollider*			m_pColliderCom		= nullptr;
	Engine::CColliderSphere*	m_pColiderSphereCom = nullptr;
	CShiny*						m_pShiny = nullptr;

	_uint						m_iFlag = 0;
	_bool						m_bColl = false;
	_bool						m_bDraw = true;
	_float						m_fTimeAcc = 0.f;
	_vec3						m_vOriPos , m_vDir;

	_int						m_iCount = -1;
	wstring						m_szTag;

public:
	static CHatch*		Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag);

private:
	virtual void Free(void) override;
};

#endif // Hatch_h__

#ifndef GameObject_h__
#define GameObject_h__

#include "Engine_Defines.h"
#include "Base.h"

#include "Component.h"

BEGIN(Engine)

class ENGINE_DLL CGameObject : public CBase
{
protected:
	explicit	CGameObject(LPDIRECT3DDEVICE9	pGraphicDev);
	virtual ~CGameObject();

public:
	_float				Get_ViewZ(void) const { return m_fViewZ; }
	CComponent*			Find_Component(const _tchar* pComponentTag, COMPONENTID eID);
	CComponent*			Get_Component(const _tchar* pComponentTag, COMPONENTID eID);


public:
	virtual HRESULT		Ready_GameObject(void);
	virtual _int		Update_GameObject(const _float& fTimeDelta);
	virtual _int		LateUpdate_GameObject(const _float& fTimeDelta);
	virtual void		Render_GameObject(void);

public:
	void				Compute_ViewZ(const _vec3* pPos);
	void				Set_bIsDead(_bool bIsDead);
	void				IsDead();

protected:
	LPDIRECT3DDEVICE9									m_pGraphicDev;
	map<const _tchar*, CComponent*>			m_mapComponent[ID_END];
	_float												m_fViewZ;
	_bool												m_bIsDead = false;

public:
	virtual void Free(void);


};

END
#endif // GameObject_h__

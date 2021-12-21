#ifndef Layer_h__
#define Layer_h__

#include "GameObject.h"


BEGIN(Engine)

class ENGINE_DLL CLayer : public CBase
{
private:
	explicit CLayer(void);
	virtual ~CLayer(void);


public:
	CComponent*			Get_Component(const _tchar* pObjTag,  
										const _tchar* pComponentTag,
										COMPONENTID eID);
	
	CGameObject*		Get_GameObj(const _tchar* pObjTag);

public:
	HRESULT	Ready_Layer(void);
	_int	Update_Layer(const _float& fTimeDelta);
	_int	LateUpdate_Layer(const _float& fTimeDelta);
	//void	Render_Layer(void);

	HRESULT	Add_GameObject(const _tchar* pObjTag, CGameObject* pGameObject);
	map<const _tchar*, CGameObject*>*	Get_MapObject() {	return &m_mapObject;	}
	void	Reset_Object();
	
private:
	map<const _tchar*, CGameObject*>			m_mapObject;

public:
	static CLayer*		Create(void);
private:
	virtual void		Free(void);

};

END
#endif // Layer_h__

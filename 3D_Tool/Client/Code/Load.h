#ifndef Load_h__
#define Load_h__

#include "Defines.h"
#include "Scene.h"

#include "BackGround.h"

#include "Loading.h"

class CLoad : public Engine::CScene
{
private:
	explicit CLoad(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CLoad(void);


public:
	virtual HRESULT Ready_Scene(void) override;
	virtual _int Update_Scene(const _float& fTimeDelta) override;
	virtual _int LateUpdate_Scene(const _float& fTimeDelta) override;
	virtual void Render_Scene(void) override;

private:
	HRESULT		Ready_Environment_Layer(const _tchar* pLayerTag) { return S_OK; }
	HRESULT		Ready_GameLogic_Layer(const _tchar* pLayerTag);
	HRESULT		Ready_UI_Layer(const _tchar* pLayerTag) { return S_OK; }
	HRESULT		Ready_Resource(LPDIRECT3DDEVICE9& pGraphicDev, RESOURCEID eMax);

private:
	_matrix						m_matView, m_matProj;
	CLoading*					m_pLoading;

public:
	static CLoad*		Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;
};


#endif // Load_h__

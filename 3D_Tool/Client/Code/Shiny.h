#ifndef Shiny_h__
#define Shiny_h__

#include "Defines.h"
#include "StaticMeshObj.h"

class CShiny : public CStaticMeshObj
{
private:
	explicit CShiny(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CShiny(void);

public:

public:
	HRESULT Ready_GameObject(const _uint& iFlag);
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual _int LateUpdate_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;
	void	Set_Lerp(_bool bIsLerp);
	void	Set_EndPos(_vec3 vEndPos);

private:
	HRESULT		Add_Component(void);
	_bool		Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CCollider*			m_pColliderCom		= nullptr;
	Engine::CColliderSphere*	m_pColiderSphereCom = nullptr;

	_uint						m_iFlag = 0;
	_bool						m_bColl = false;
	_bool						m_bDraw = true;
	_bool						m_bFirst = true;

	_vec3						m_vEndPos;
	_bool						m_bIsLerp = false;
	_int						m_iEffectCount = 0;

public:
	static CShiny*		Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag);

private:
	virtual void Free(void) override;
};

#endif // Shiny_h__

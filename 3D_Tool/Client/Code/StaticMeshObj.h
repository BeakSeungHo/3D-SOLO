#ifndef StaticMeshObj_h__
#define StaticMeshObj_h__

#include "Defines.h"
#include "GameObject.h"

BEGIN(Engine)

class CStaticMesh;
class CTransform;
class CRenderer;
class CCalculator;
class CCollider;
class CColliderSphere;
class CShader;
class COptimization;

END

class CStaticMeshObj : public Engine::CGameObject
{
protected:
	explicit CStaticMeshObj(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CStaticMeshObj(void);

public:

public:
	HRESULT Ready_GameObject(const _uint& iFlag);
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual _int LateUpdate_GameObject(const _float& fTimeDelta);
	virtual void Render_GameObject(void) override;

	void		Set_bIsConveyor(_bool bIsConveyor);
	_bool		GetbIsConveyor() { return m_bIsConveyor; }
	_tchar*		GetObjTag() { return m_ObjTag; }

private:
	HRESULT		Add_Component(void);
	_bool		Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

protected:
	Engine::CTransform*			m_pTransformCom		= nullptr;
	Engine::CRenderer*			m_pRendererCom		= nullptr;
	Engine::CCalculator*		m_pCalculatorCom	= nullptr;
	Engine::CStaticMesh*		m_pMeshCom			= nullptr;
	Engine::COptimization*		m_pOptimizationCom	= nullptr;
	Engine::CShader*			m_pShaderCom		= nullptr;
	_tchar						m_MeshTag[128];
	_tchar						m_ObjTag[128];

	_uint						m_iFlag = 0;
	_bool						m_bColl = false;
	_bool						m_bIsConveyor = false;
	_bool						m_bDraw = true;

public:
	static CStaticMeshObj*		Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag);

private:
	virtual void Free(void) override;
};

#endif // Stone_h__

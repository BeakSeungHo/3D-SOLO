#ifndef DynamicMeshObj_h__
#define DynamicMeshObj_h__

#include "Defines.h"
#include "GameObject.h"

BEGIN(Engine)

class CNaviMesh;
class CDynamicMesh;
class CTransform;
class CRenderer;
class CCalculator;
class CCollider;
class CShader;

END

class CDynamicMeshObj : public Engine::CGameObject
{
private:
	explicit CDynamicMeshObj(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CDynamicMeshObj(void);

public:
	virtual HRESULT Ready_GameObject(void) override;
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;
	void	SaveData(HANDLE hFile);

	_tchar*		GetObjTag() { return m_ObjTag; }

private:
	HRESULT		Add_Component(void);

private:
	Engine::CTransform*		m_pTransformCom = nullptr;
	Engine::CRenderer*		m_pRendererCom = nullptr;
	Engine::CCalculator*	m_pCalculatorCom = nullptr;
	Engine::CDynamicMesh*	m_pMeshCom = nullptr;
	Engine::CCollider*		m_pColliderCom = nullptr;
	Engine::CShader*		m_pShaderCom = nullptr;

	_tchar					m_MeshTag[128];
	_tchar					m_ObjTag[128];
	_vec3					m_vDir;
	_float					m_fSpeed = 4.f;
public:
	static CDynamicMeshObj*		Create(LPDIRECT3DDEVICE9 pGraphicDev, wstring MeshTag, wstring ObjTag);

private:
	virtual void Free(void) override;
};

#endif // DynamicMeshObj_h__

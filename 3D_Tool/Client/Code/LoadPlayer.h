#ifndef LoadPlayer_h__
#define LoadPlayer_h__

#include "Defines.h"
#include "GameObject.h"

BEGIN(Engine)

class CNaviMesh;
class CDynamicMesh;
class CStaticMesh;
class CTransform;
class CRenderer;
class CCalculator;
class CColliderSphere;
class CColliderBox;
class CShader;

END

class CAim;
class CClone;
class CWarpEffect;
class CCloneEffect;
class CLoadPlayer : public Engine::CGameObject
{
private:
	explicit CLoadPlayer(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CLoadPlayer(void);

public:
	virtual HRESULT Ready_GameObject(void) override;
	virtual _int Update_GameObject(const _float& fTimeDelta) override;
	virtual void Render_GameObject(void) override;

private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CDynamicMesh*		m_pMeshCom = nullptr;
	Engine::CShader*			m_pShaderCom = nullptr;

	_vec3					m_vPos, m_vDir, vPastPos;

	_float					m_fTimeAcc = 0.f;

public:
	static CLoadPlayer*		Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;
};

#endif // LoadPlayer_h__

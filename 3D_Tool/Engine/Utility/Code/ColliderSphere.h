#ifndef ColliderSphere_h__
#define ColliderSphere_h__

#include "Component.h"

BEGIN(Engine)

class ENGINE_DLL CColliderSphere : public CComponent
{
private:
	explicit CColliderSphere(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CColliderSphere(void);

public:
	const _vec3*		Get_Pos(void)  { return &m_vPos; }
	const _float*		Get_Radius(void) { return &m_fRadius; }
	const _matrix*		Get_ColliderMatrix(void) { return &m_matWorld; }


public:
	HRESULT		Ready_Collider(const _vec3* pPos, const _float& fRadius);
	void		Render_Collider(COLLTYPE eType, const _matrix* pColliderMatrix);

private:
	_vec3		m_vPos;
	_float		m_fRadius;
	_matrix		m_matWorld;
	LPDIRECT3DDEVICE9			m_pGraphicDev;
	LPD3DXMESH					m_pSphere;

#ifdef _DEBUG
	
	LPDIRECT3DTEXTURE9			m_pTexture[COL_END];

#endif

public:
	static CColliderSphere*		Create(LPDIRECT3DDEVICE9 pGraphicDev, 
									const _vec3* pPos, 
									const _float& fRadius);

private:
	virtual void		Free(void);
};

END
#endif // ColliderSphere_h__

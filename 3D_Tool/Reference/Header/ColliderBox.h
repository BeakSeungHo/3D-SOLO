#ifndef ColliderBox_h__
#define ColliderBox_h__

#include "Component.h"

BEGIN(Engine)

class ENGINE_DLL CColliderBox : public CComponent
{
private:
	explicit CColliderBox(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CColliderBox(void);

public:
	const _vec3*		Get_Min(void)  { return &m_vMin; }
	const _vec3*		Get_Max(void) { return &m_vMax; }
	const _matrix*		Get_ColliderBoxMatrix(void) { return &m_matWorld; }

public:
	HRESULT		Ready_Collider(const _vec3* pPos, const _vec3* vMin, const _vec3* vMax);
	void		Render_Collider(COLLTYPE eType, const _matrix* pColliderBoxMatrix);

private:
	_vec3		m_vMin, m_vMax;
	_matrix		m_matWorld;
	LPDIRECT3DDEVICE9			m_pGraphicDev;

#ifdef _DEBUG
	
	LPDIRECT3DVERTEXBUFFER9		m_pVB;
	LPDIRECT3DINDEXBUFFER9		m_pIB;
	LPDIRECT3DTEXTURE9			m_pTexture[COL_END];
	
#endif

public:
	static CColliderBox*		Create(LPDIRECT3DDEVICE9 pGraphicDev, 
									const _vec3* pPos, 
									const _vec3* vMin,
									const _vec3* vMax);

private:
	virtual void		Free(void);
};

END
#endif // ColliderBox_h__

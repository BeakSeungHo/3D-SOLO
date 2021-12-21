#ifndef Frustum_h__
#define Frustum_h__

#include "Engine_Defines.h"
#include "Base.h"

BEGIN(Engine)

class CQuadTree;
class ENGINE_DLL CFrustum : public CBase 
{
private:
	explicit CFrustum(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CFrustum(void);

public:
	LPDIRECT3DDEVICE9		Get_Device(void) { return m_pGraphicDev; }

public:
	HRESULT			Ready_Frustum(void);

	_bool			Is_InFrustum(const _vec3* pPos);
	_bool			Is_InFrustum(const _vec3* pPos, _float fRadius);

	_bool			Is_InFrustum_ForObject(const _vec3* pWorldPos, _float fRadius = 0.f);

	void			Is_InFrustum_ForTerrain(const _vec3* pVtxPos,
											const _ulong& dwCntX,
											const _ulong& dwCntZ,
											INDEX32* pIndex,
											_ulong* pTriCnt,
											CQuadTree* pQuadTree);	

private:
	LPDIRECT3DDEVICE9		m_pGraphicDev;
	_vec3					m_vPoint[8];
	D3DXPLANE				m_Plane[6];

public:
	static CFrustum*		Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual void			Free(void);
};

END
#endif // Frustum_h__

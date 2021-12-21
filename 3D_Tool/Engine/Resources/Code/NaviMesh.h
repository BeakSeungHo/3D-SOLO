#ifndef NaviMesh_h__
#define NaviMesh_h__

#include "Mesh.h"
#include "Cell.h"

BEGIN(Engine)

class ENGINE_DLL CNaviMesh : public CMesh
{
private:
	explicit CNaviMesh(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CNaviMesh(const CNaviMesh& rhs);
	virtual ~CNaviMesh(void);

public:
	void		Set_Index(const _ulong& dwIndex) { m_dwIndex = dwIndex; }
	_ulong		const Get_Index() { return m_dwIndex; }

public:
	HRESULT				Ready_NaviMesh(void);
	void				Render_NaviMesh(void);
	_vec3				Move_OnNaviMesh(const _vec3* pTargetPos, const _vec3* pTargetDir);
	_vec3				Warp_OnNaviMesh(const _vec3* pTargetPos, const _vec3* pEndPos);
	_vec3				AimMove_OnNaviMesh(const _vec3* pTargetPos, const _vec3* pEndPos);
	_vec3				Laser_OnNaviMesh(const _vec3* pStart, const _vec3* pEnd);
	void				Add_Cell(_vec3 vPoint1, _vec3 vPoint2, _vec3 vPoint3 );
	vector<CCell*>*		Get_vecCell() { return &m_vecCell; }
	void				Set_Point(int index, CCell::POINT PointType, _vec3 vPos);
	void				Together_Point();

private:
	HRESULT		Link_Cell(void);

private:
	vector<CCell*>			m_vecCell;
	_ulong					m_dwIndex;

public:
	static	CNaviMesh*		Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual CResources*		Clone(void);
	virtual void			Free(void);
};

END
#endif // NaviMesh_h__

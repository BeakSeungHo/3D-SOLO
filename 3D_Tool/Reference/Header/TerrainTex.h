#ifndef TerrainTex_h__
#define TerrainTex_h__

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CTerrainTex : public CVIBuffer
{
private:
	explicit CTerrainTex(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CTerrainTex(const CTerrainTex& rhs);
	virtual ~CTerrainTex(void);

public:
	const _vec3*		Get_VtxPos(void) const { return m_pPos; }
	_ulong				Get_VtxCntX(void) const { return m_dwVtxCntX;}
	_ulong				Get_VtxCntZ(void) const { return m_dwVtxCntZ; }
	_ulong				Get_VtxItv(void) const { return m_dwVtxItv; }
	_ulong				Get_Detail(void) const { return m_dwDetail; }

	void				Copy_Indieces(INDEX32* pIndex, const _ulong& dwTriCnt);

public:
	HRESULT Ready_Buffer(const _ulong& dwCntX, 
						const _ulong& dwCntZ,	
						const _ulong dwVtxItv = 1,
						const _ulong& dwDetail = 1);

	void	Change_Buffer(const _ulong& dwCntX,
						const _ulong& dwCntZ,
						const _ulong dwVtxItv = 1,
						const _ulong& dwDetail = 1);

private:
	HANDLE				m_hFile;
	BITMAPFILEHEADER	m_fH;
	BITMAPINFOHEADER	m_iH;

	_vec3*				m_pPos;
	_bool				m_bClone;
	_ulong				m_dwVtxCntX;
	_ulong				m_dwVtxCntZ;
	_ulong				m_dwVtxItv;
	_ulong				m_dwDetail;

public:
	static CTerrainTex*		Create(LPDIRECT3DDEVICE9 pGraphicDev, 
							const _ulong& dwCntX, 
							const _ulong& dwCntZ, 
							const _ulong& dwVtxItv,
							const _ulong& dwDetail);

	virtual CResources* Clone(void) override;

private:
	virtual void Free(void);
};

END
#endif // TerrainTex_h__

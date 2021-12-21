#ifndef Calculator_h__
#define Calculator_h__

#include "Component.h"


BEGIN(Engine)

class CTerrainTex;
class CTransform;
class CColliderSphere;
class CColliderBox;

class ENGINE_DLL CCalculator : public CComponent
{
private:
	typedef	struct tagOBB
	{
		_vec3		vPoint[8];		// ť�긦 �̷�� ����
		_vec3		vCenter;		// ť���� ����
		_vec3		vProjAxis[3];	// �������� �� ���� ���� ������� ���� ���� 
		_vec3		vAxis[3];		// ť���� ��� ������ ��, ���� ����

	}OBB;

private:
	explicit CCalculator(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CCalculator(void);

public:
	HRESULT		Ready_Calculator(void);

	_float		Compute_HeightOnTerrain(const _vec3* pPos, 
										const _vec3* pTerrainVtxPos,
										const _ulong& dwCntX,
										const _ulong& dwCntZ);

	_float		Compute_HeightOnTerrain1(_vec3* pPos,
										const _vec3* pTerrainVtxPos,
										const _ulong& dwCntX,
										const _ulong& dwCntZ);

	_vec3		Picking_OnTerrain(HWND hWnd,
									const CTerrainTex* pTerrainBufferCom,
									const CTransform*	pTerrainTransformCom);

	_bool		Collision_AABB(const _vec3* pDestMin, const _vec3* pDestMax, const _matrix* pDestWorld,
								const _vec3* pSourMin, const _vec3* pSourMax, const _matrix* pSourWorld);

	_bool		Collision_AABB(CColliderBox* pSourBoxCom);

	_bool		Collision_OBB(const _vec3* pDestMin, const _vec3* pDestMax, const _matrix* pDestWorld,
								const _vec3* pSourMin, const _vec3* pSourMax, const _matrix* pSourWorld);

	_bool		Coliision_Sphere(const _vec3* pDestPos, const _float* fDestRadius, 
									const _vec3* pSourPos, const _float* fSourRadius );

	void		Input_ColliderSphere(CColliderSphere* ComSphere);

	void		Set_Point(OBB* pObb, const _vec3* pMin, const _vec3* pMax);
	void		Set_Axis(OBB* pObb);

private:
	LPDIRECT3DDEVICE9			m_pGraphicDev;

public:
	static CCalculator*			Create(LPDIRECT3DDEVICE9 pGraphicDev);
private:
	virtual void				Free(void);

};

END
#endif // Calculator_h__

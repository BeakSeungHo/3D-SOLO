#include "Cell.h"
#include "Line.h"

USING(Engine)

Engine::CCell::CCell(LPDIRECT3DDEVICE9 pGraphicDev)
	: m_pGraphicDev(pGraphicDev)
{
	m_pGraphicDev->AddRef();
	ZeroMemory(m_pNeighbor, sizeof(CCell*) * NEIGHBOR_END);
}

Engine::CCell::~CCell(void)
{

}

void CCell::Set_Point(POINT eType, _vec3 vPos)
{
	m_vPoint[eType] = vPos;
}

void CCell::Set_Target(_bool IsTarget)
{
	m_bIsTarget = IsTarget;
}

HRESULT Engine::CCell::Ready_Cell(const _ulong& dwIndex, const _vec3* pPointA, const _vec3* pPointB, const _vec3* pPointC)
{
	m_dwIndex = dwIndex;

	m_vPoint[POINT_A] = *pPointA;
	m_vPoint[POINT_B] = *pPointB;
	m_vPoint[POINT_C] = *pPointC;

	m_pLine[LINE_AB] = CLine::Create(&_vec2(m_vPoint[POINT_A].x, m_vPoint[POINT_A].z), 
									 &_vec2(m_vPoint[POINT_B].x, m_vPoint[POINT_B].z));

	m_pLine[LINE_BC] = CLine::Create(&_vec2(m_vPoint[POINT_B].x, m_vPoint[POINT_B].z),
									 &_vec2(m_vPoint[POINT_C].x, m_vPoint[POINT_C].z));

	m_pLine[LINE_CA] = CLine::Create(&_vec2(m_vPoint[POINT_C].x, m_vPoint[POINT_C].z),
									 &_vec2(m_vPoint[POINT_A].x, m_vPoint[POINT_A].z));

#ifdef _DEBUG
	FAILED_CHECK_RETURN(D3DXCreateLine(m_pGraphicDev, &m_pD3DXLine), E_FAIL);

#endif
	return S_OK;
}

_bool Engine::CCell::Compare_Point(const _vec2* pPointF, const _vec2* pPointS, CCell* pCell)
{
	if (_vec2(m_vPoint[POINT_A].x, m_vPoint[POINT_A].z) == *pPointF)
	{
		if (_vec2(m_vPoint[POINT_B].x, m_vPoint[POINT_B].z) == *pPointS)
		{
			m_pNeighbor[NEIGHBOR_AB] = pCell;
			return true;
		}
		if (_vec2(m_vPoint[POINT_C].x, m_vPoint[POINT_C].z) == *pPointS)
		{
			m_pNeighbor[NEIGHBOR_CA] = pCell;
			return true;
		}
	}

	if (_vec2(m_vPoint[POINT_B].x, m_vPoint[POINT_B].z) == *pPointF)
	{
		if (_vec2(m_vPoint[POINT_A].x, m_vPoint[POINT_A].z) == *pPointS)
		{
			m_pNeighbor[NEIGHBOR_AB] = pCell;
			return true;
		}
		if (_vec2(m_vPoint[POINT_C].x, m_vPoint[POINT_C].z) == *pPointS)
		{
			m_pNeighbor[NEIGHBOR_BC] = pCell;
			return true;
		}
	}

	if (_vec2(m_vPoint[POINT_C].x, m_vPoint[POINT_C].z) == *pPointF)
	{
		if (_vec2(m_vPoint[POINT_B].x, m_vPoint[POINT_B].z) == *pPointS)
		{
			m_pNeighbor[NEIGHBOR_BC] = pCell;
			return true;
		}
		if (_vec2(m_vPoint[POINT_A].x, m_vPoint[POINT_A].z) == *pPointS)
		{
			m_pNeighbor[NEIGHBOR_CA] = pCell;
			return true;
		}
	}


	return false;
}

void Engine::CCell::Render_Cell(void)
{
	_vec3	vPoint[4];

	vPoint[0] = m_vPoint[POINT_A];
	vPoint[1] = m_vPoint[POINT_B];
	vPoint[2] = m_vPoint[POINT_C];
	vPoint[3] = m_vPoint[POINT_A];

	_matrix		matView, matProj;

	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	for (_ulong i = 0; i < 4; ++i)
	{
		D3DXVec3TransformCoord(&vPoint[i], &vPoint[i], &matView);

		if (vPoint[i].z <= 0.1f)
			vPoint[i].z = 0.1f;

		D3DXVec3TransformCoord(&vPoint[i], &vPoint[i], &matProj);
	}

#ifdef _DEBUG

	m_pD3DXLine->SetWidth(3.f);	// 라인의 굵기를 결정하는 함수
	m_pGraphicDev->EndScene();
	m_pGraphicDev->BeginScene();

	m_pD3DXLine->Begin();

	_matrix matTemp;
	if(m_bIsTarget != true)
		m_pD3DXLine->DrawTransform(vPoint, 4, D3DXMatrixIdentity(&matTemp), D3DXCOLOR(1.f, 0.f, 0.f, 1.f));
	else
		m_pD3DXLine->DrawTransform(vPoint, 4, D3DXMatrixIdentity(&matTemp), D3DXCOLOR(0.f, 1.f, 0.f, 1.f));

	m_pD3DXLine->End();
#endif

}

Engine::CCell* Engine::CCell::Create(LPDIRECT3DDEVICE9 pGraphicDev, const _ulong& dwIndex, const _vec3* pPointA, const _vec3* pPointB, const _vec3* pPointC)
{
	CCell*	pInstance = new CCell(pGraphicDev);

	if (FAILED(pInstance->Ready_Cell(dwIndex, pPointA, pPointB, pPointC)))
		Safe_Release(pInstance);

	return pInstance;
}

void Engine::CCell::Free(void)
{
	for (_uint i = 0; i < LINE_END; ++i)
		Safe_Release(m_pLine[i]);

#ifdef _DEBUG
	Safe_Release(m_pD3DXLine);
#endif

	Safe_Release(m_pGraphicDev);
}

Engine::CCell::COMPARE Engine::CCell::Compare(const _vec3* pEndPos, _ulong* pIndex)
{
	for (_ulong i = 0; i < LINE_END; ++i)
	{
		if (CLine::COMPARE_LEFT == m_pLine[i]->Compare(&_vec2(pEndPos->x, pEndPos->z)))
		{
			if (nullptr == m_pNeighbor[i])
				return COMPARE_STOP;
			else
			{
				*pIndex = *m_pNeighbor[i]->Get_Index();
				return COMPARE_MOVE;
			}
		}
	}

	return COMPARE_MOVE;
}

Engine::CCell::COMPARE CCell::WarpCompare(const _vec3 * pEndPos)
{
	
	if (CLine::COMPARE_LEFT == m_pLine[LINE_AB]->WarpCompare(pEndPos) &&
		CLine::COMPARE_LEFT == m_pLine[LINE_BC]->WarpCompare(pEndPos) &&
		CLine::COMPARE_LEFT == m_pLine[LINE_CA]->WarpCompare(pEndPos))
	{
		return COMPARE_MOVE;
	}
	else
		return COMPARE_STOP;
	

	return COMPARE_MOVE;
}

_vec3 CCell::SetOnNavi(const _vec3 * pTargetPos, const _vec3 * pEndPos)
{

	_float	fPosXMin, fPosXMax, fPosZMin, fPosZMax;

	fPosXMin = pTargetPos->x > pEndPos->x ? pEndPos->x : pTargetPos->x;
	fPosXMax = pTargetPos->x > pEndPos->x ? pTargetPos->x : pEndPos->x;
	fPosZMin = pTargetPos->z > pEndPos->z ? pEndPos->z : pTargetPos->z;
	fPosZMax = pTargetPos->z > pEndPos->z ? pTargetPos->z : pEndPos->z;

	for (_ulong i = 0; i < LINE_END; ++i)
	{
		_vec3 Temp = m_pLine[i]->CrossLinePoint(pTargetPos, pEndPos);

		if (Temp.x >= fPosXMin && Temp.x <= fPosXMax && Temp.z >= fPosZMin && Temp.z <= fPosZMax)
		{
			return Temp;
		}
			
	}

	return _vec3(-1.f,0.f,-1.f);
}

_vec3 CCell::LaserOnNavi(const _vec3 * pStart, const _vec3 * pEnd)
{
	_vec3 vResult = *pStart;
	m_bIsLaser = false;
	_float	fPosXMin, fPosXMax, fPosZMin, fPosZMax;

	fPosXMin = pStart->x > pEnd->x ? pEnd->x : pStart->x;
	fPosXMax = pStart->x > pEnd->x ? pStart->x : pEnd->x;
	fPosZMin = pStart->z > pEnd->z ? pEnd->z : pStart->z;
	fPosZMax = pStart->z > pEnd->z ? pStart->z : pEnd->z;

	for (_ulong i = 0; i < LINE_END; ++i)
	{
		_vec3 Temp = m_pLine[i]->CrossLinePoint(pStart, pEnd);

		Temp.y = 0.f;

		if (CLine::COMPARE_LEFT == m_pLine[LINE_AB]->WarpCompare(&Temp) &&
			CLine::COMPARE_LEFT == m_pLine[LINE_BC]->WarpCompare(&Temp) &&
			CLine::COMPARE_LEFT == m_pLine[LINE_CA]->WarpCompare(&Temp))
		{
			if (Temp.x >= fPosXMin && Temp.x <= fPosXMax && Temp.z >= fPosZMin && Temp.z <= fPosZMax)
			{
				if (D3DXVec3Length(&(*pStart - vResult)) < D3DXVec3Length(&(*pStart - Temp)))
				{
					vResult = Temp;
					m_bIsLaser = true;
				}
			}
		}
	}

	if(m_bIsLaser)
		return vResult;

	return _vec3(-1.f, 0.f, -1.f);
}


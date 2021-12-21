#include "NaviMesh.h"

USING(Engine)

Engine::CNaviMesh::CNaviMesh(LPDIRECT3DDEVICE9 pGraphicDev)
	:CMesh(pGraphicDev)
	, m_dwIndex(0)
{

}

Engine::CNaviMesh::CNaviMesh(const CNaviMesh& rhs)
	: CMesh(rhs)
	, m_vecCell(rhs.m_vecCell)
	, m_dwIndex(rhs.m_dwIndex)	
{
	for (auto& iter : m_vecCell)
		iter->AddRef();
}

Engine::CNaviMesh::~CNaviMesh(void)
{

}

HRESULT Engine::CNaviMesh::Ready_NaviMesh(void)
{
	m_vecCell.reserve(10);

	return S_OK;
}

void CNaviMesh::Render_NaviMesh(void)
{
	for (auto& iter : m_vecCell)
		iter->Render_Cell();

}

_vec3 CNaviMesh::Move_OnNaviMesh(const _vec3 * pTargetPos, const _vec3 * pTargetDir)
{
	_vec3	vEndPos = *pTargetPos + *pTargetDir;

	D3DXPLANE plane;

	D3DXPlaneFromPoints(&plane, m_vecCell[m_dwIndex]->Get_Point(CCell::POINT_A), m_vecCell[m_dwIndex]->Get_Point(CCell::POINT_B), m_vecCell[m_dwIndex]->Get_Point(CCell::POINT_C));

	vEndPos.y = -(plane.a * vEndPos.x + plane.c * vEndPos.z + plane.d) / plane.b;

	if (CCell::COMPARE_MOVE == m_vecCell[m_dwIndex]->Compare(&vEndPos, &m_dwIndex))
	{
		if (vEndPos.y - pTargetPos->y > 0.5f)
			return *pTargetPos;
		if (pTargetPos->y > vEndPos.y)
			vEndPos.y = pTargetPos->y;

		return vEndPos;
	}
	else if (CCell::COMPARE_STOP == m_vecCell[m_dwIndex]->Compare(&vEndPos, &m_dwIndex))
	{	
		return *pTargetPos;
	}
	
}

_vec3 CNaviMesh::Warp_OnNaviMesh(const _vec3 * pTargetPos, const _vec3 * pEndPos)
{
	_vec3	vEndPos = *pEndPos;

	for (_int i = 0; i < m_vecCell.size(); ++i)
	{
		_vec3	vEndPos = *pEndPos;

		D3DXPLANE plane;

		D3DXPlaneFromPoints(&plane, m_vecCell[m_dwIndex]->Get_Point(CCell::POINT_A), m_vecCell[m_dwIndex]->Get_Point(CCell::POINT_B), m_vecCell[m_dwIndex]->Get_Point(CCell::POINT_C));

		vEndPos.y = -(plane.a * vEndPos.x + plane.c * vEndPos.z + plane.d) / plane.b;

		if (CCell::COMPARE_MOVE == m_vecCell[i]->WarpCompare(&vEndPos))
		{
			m_dwIndex = i;
			return vEndPos;
		}
	}

	return *pTargetPos;
}

_vec3 CNaviMesh::AimMove_OnNaviMesh(const _vec3 * pTargetPos, const _vec3 * pEndPos)
{
	_vec3	vEndPos = *pEndPos;

	for (_int i = 0; i < m_vecCell.size(); ++i)
	{
		vEndPos.y = 0.3f;

		if (CCell::COMPARE_MOVE == m_vecCell[i]->WarpCompare(&vEndPos))
			return vEndPos;
	}

	for (_int i = 0; i < m_vecCell.size(); ++i)
	{
		_vec3 Temp = m_vecCell[i]->SetOnNavi(pTargetPos, pEndPos);

		if (Temp.x == -1 && Temp.z == -1)
			continue;
		else
		{
			vEndPos.x = Temp.x;
			vEndPos.y = Temp.y;
			vEndPos.z = Temp.z;

			if (D3DXVec3Length(&(*pTargetPos - vEndPos)) < 0.1f)
			{
				vEndPos = *pTargetPos;
				vEndPos.y = 0.3f;
			}
		}
	}
	return vEndPos;
}

_vec3 CNaviMesh::Laser_OnNaviMesh(const _vec3 * pStart, const _vec3 * pEnd)
{
	_vec3 vEndPos = *pStart;

	for (_int i = 0; i < m_vecCell.size(); ++i)
	{
		_vec3 Temp = m_vecCell[i]->LaserOnNavi(pStart, pEnd);

		if (Temp.x == -1 && Temp.z == -1)
			continue;
		else
		{
			if (D3DXVec3Length(&(*pStart - vEndPos)) < D3DXVec3Length(&(*pStart - Temp)))
			{
				vEndPos.x = Temp.x;
				vEndPos.y = Temp.y;
				vEndPos.z = Temp.z;
			}
		}
	}

	return vEndPos;
}

void CNaviMesh::Add_Cell(_vec3 vPoint1, _vec3 vPoint2, _vec3 vPoint3)
{
	CCell* pCell = nullptr;

	pCell = CCell::Create(m_pGraphicDev,
		m_vecCell.size(),
		&vPoint1,
		&vPoint2,
		&vPoint3);
	//NULL_CHECK_RETURN(pCell, E_FAIL);
	m_vecCell.push_back(pCell);

	Link_Cell();
}

void CNaviMesh::Set_Point(int index, CCell::POINT PointType, _vec3 vPos)
{
	m_vecCell[index]->Set_Point(PointType, vPos);
}

void CNaviMesh::Together_Point()
{
	_ulong	dwSize = m_vecCell.size();

	for (_ulong i = 0; i < dwSize; ++i)
	{
		for (_ulong j = 0; j < dwSize; ++j)
		{
			if (i == j)
				continue;
			
			if (D3DXVec3Length(&(*m_vecCell[i]->Get_Point(CCell::POINT_A) - *m_vecCell[j]->Get_Point(CCell::POINT_A))) < 0.1)
			{
				m_vecCell[j]->Set_Point(CCell::POINT_A, *m_vecCell[i]->Get_Point(CCell::POINT_A) );
			}
			if (D3DXVec3Length(&(*m_vecCell[i]->Get_Point(CCell::POINT_A) - *m_vecCell[j]->Get_Point(CCell::POINT_B))) < 0.1)
			{
				m_vecCell[j]->Set_Point(CCell::POINT_B, *m_vecCell[i]->Get_Point(CCell::POINT_A));
			}
			if (D3DXVec3Length(&(*m_vecCell[i]->Get_Point(CCell::POINT_A) - *m_vecCell[j]->Get_Point(CCell::POINT_C))) < 0.1)
			{
				m_vecCell[j]->Set_Point(CCell::POINT_C, *m_vecCell[i]->Get_Point(CCell::POINT_A));
			}

			if (D3DXVec3Length(&(*m_vecCell[i]->Get_Point(CCell::POINT_B) - *m_vecCell[j]->Get_Point(CCell::POINT_A))) < 0.1)
			{
				m_vecCell[j]->Set_Point(CCell::POINT_A, *m_vecCell[i]->Get_Point(CCell::POINT_B));
			}
			if (D3DXVec3Length(&(*m_vecCell[i]->Get_Point(CCell::POINT_B) - *m_vecCell[j]->Get_Point(CCell::POINT_B))) < 0.1)
			{
				m_vecCell[j]->Set_Point(CCell::POINT_B, *m_vecCell[i]->Get_Point(CCell::POINT_B));
			}
			if (D3DXVec3Length(&(*m_vecCell[i]->Get_Point(CCell::POINT_B) - *m_vecCell[j]->Get_Point(CCell::POINT_C))) < 0.1)
			{
				m_vecCell[j]->Set_Point(CCell::POINT_C, *m_vecCell[i]->Get_Point(CCell::POINT_B));
			}

			if (D3DXVec3Length(&(*m_vecCell[i]->Get_Point(CCell::POINT_C) - *m_vecCell[j]->Get_Point(CCell::POINT_A))) < 0.1)
			{
				m_vecCell[j]->Set_Point(CCell::POINT_A, *m_vecCell[i]->Get_Point(CCell::POINT_C));
			}
			if (D3DXVec3Length(&(*m_vecCell[i]->Get_Point(CCell::POINT_C) - *m_vecCell[j]->Get_Point(CCell::POINT_B))) < 0.1)
			{
				m_vecCell[j]->Set_Point(CCell::POINT_B, *m_vecCell[i]->Get_Point(CCell::POINT_C));
			}
			if (D3DXVec3Length(&(*m_vecCell[i]->Get_Point(CCell::POINT_C) - *m_vecCell[j]->Get_Point(CCell::POINT_C))) < 0.1)
			{
				m_vecCell[j]->Set_Point(CCell::POINT_C, *m_vecCell[i]->Get_Point(CCell::POINT_C));
			}
		}
	}

}

HRESULT Engine::CNaviMesh::Link_Cell(void)
{
	_ulong	dwSize = m_vecCell.size();

	for (_ulong i = 0; i < dwSize; ++i)
	{
		for (_ulong j = 0; j < dwSize; ++j)
		{
			if(i == j)
				continue;

			if(nullptr == m_vecCell[i]->Get_Neighbor(CCell::NEIGHBOR_AB) &&
				true == m_vecCell[j]->Compare_Point(&_vec2(m_vecCell[i]->Get_Point(CCell::POINT_A)->x, m_vecCell[i]->Get_Point(CCell::POINT_A)->z),
													&_vec2(m_vecCell[i]->Get_Point(CCell::POINT_B)->x, m_vecCell[i]->Get_Point(CCell::POINT_B)->z),
													m_vecCell[i]))
			{
				m_vecCell[i]->Set_Neighbor(CCell::NEIGHBOR_AB, m_vecCell[j]);
				continue;
			}

			if (nullptr == m_vecCell[i]->Get_Neighbor(CCell::NEIGHBOR_BC) &&
				true == m_vecCell[j]->Compare_Point(&_vec2(m_vecCell[i]->Get_Point(CCell::POINT_B)->x, m_vecCell[i]->Get_Point(CCell::POINT_B)->z),
													&_vec2(m_vecCell[i]->Get_Point(CCell::POINT_C)->x, m_vecCell[i]->Get_Point(CCell::POINT_C)->z),
													m_vecCell[i]))
			{
				m_vecCell[i]->Set_Neighbor(CCell::NEIGHBOR_BC, m_vecCell[j]);
				continue;
			}


			if (nullptr == m_vecCell[i]->Get_Neighbor(CCell::NEIGHBOR_CA) &&
				true == m_vecCell[j]->Compare_Point(&_vec2(m_vecCell[i]->Get_Point(CCell::POINT_C)->x, m_vecCell[i]->Get_Point(CCell::POINT_C)->z),
													&_vec2(m_vecCell[i]->Get_Point(CCell::POINT_A)->x, m_vecCell[i]->Get_Point(CCell::POINT_A)->z),
													m_vecCell[i]))
			{
				m_vecCell[i]->Set_Neighbor(CCell::NEIGHBOR_CA, m_vecCell[j]);
				continue;
			}
		}
	}

	return S_OK;
}

Engine::CNaviMesh* Engine::CNaviMesh::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CNaviMesh*	pInstance = new CNaviMesh(pGraphicDev);

	if (FAILED(pInstance->Ready_NaviMesh()))
		Safe_Release(pInstance);

	return pInstance;
}

Engine::CResources* Engine::CNaviMesh::Clone(void)
{
	return new CNaviMesh(*this);
}

void Engine::CNaviMesh::Free(void)
{
	for_each(m_vecCell.begin(), m_vecCell.end(), CDeleteObj());
	m_vecCell.clear();

	CMesh::Free();
}


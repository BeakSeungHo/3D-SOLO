#include "Line.h"

USING(Engine)

Engine::CLine::CLine(void)
{

}

Engine::CLine::~CLine(void)
{

}

HRESULT Engine::CLine::Ready_Line(const _vec2* pPointA, const _vec2* pPointB)
{
	m_vPoint[POINT_START]	= *pPointA;
	m_vPoint[POINT_FINISH]	= *pPointB;

	m_vDirection = m_vPoint[POINT_FINISH] - m_vPoint[POINT_START];
	
	m_vNormal = _vec2(m_vDirection.y * -1.f, m_vDirection.x);
	
	D3DXVec2Normalize(&m_vNormal, &m_vNormal);


	return S_OK;
}

Engine::CLine::COMPARE Engine::CLine::Compare(const _vec2* pEndPos)
{
	_vec2		vDest = *pEndPos - m_vPoint[POINT_START];

	_float		fResult = D3DXVec2Dot(D3DXVec2Normalize(&vDest, &vDest), &m_vNormal);

	if (0.f <= fResult)
		return COMPARE_LEFT;
	else
		return COMPARE_RIGHT;

}

Engine::CLine::COMPARE CLine::WarpCompare(const _vec3 * pEndPos)
{
	_vec3 vTempCross = {0.f,0.f,0.f};

	D3DXVec3Cross(&vTempCross, &_vec3(m_vDirection.x, 0.f, m_vDirection.y), &_vec3(0.f,1.f,0.f));

	_vec3		vDest = (_vec3(m_vPoint[POINT_START].x,0.f, m_vPoint[POINT_START].y) -*pEndPos);

	D3DXVec3Normalize(&vTempCross,&vTempCross);
	D3DXVec3Normalize(&vDest, &vDest);

	_float		fResult = D3DXVec3Dot(&vTempCross,&vDest);
	
	if (0.f <= fResult)
		return COMPARE_LEFT;
	else
		return COMPARE_RIGHT;
}

_vec3 CLine::CrossLinePoint(const _vec3 * vPoint1, const _vec3 * vPoint2)
{
	float finclina1 = 0,finclina2 = 0, fcon1 = 0,fcon2 = 0;
	
	if (vPoint1->x != vPoint2->x)
	{
		finclina1 = (vPoint2->z - vPoint1->z) / (vPoint2->x - vPoint1->x);
		fcon1 = vPoint1->z - (vPoint2->z - vPoint1->z) / (vPoint2->x - vPoint1->x) * vPoint1->x;
	}

	if (m_vPoint[POINT_START].x != m_vPoint[POINT_FINISH].x)
	{
		finclina2 = (m_vPoint[POINT_FINISH].y - m_vPoint[POINT_START].y) / (m_vPoint[POINT_FINISH].x - m_vPoint[POINT_START].x);
		fcon2 = m_vPoint[POINT_START].y - (m_vPoint[POINT_FINISH].y - m_vPoint[POINT_START].y) / (m_vPoint[POINT_FINISH].x - m_vPoint[POINT_START].x) * m_vPoint[POINT_START].x;
	}

	if(vPoint1->x == vPoint2->x && m_vPoint[POINT_START].x == m_vPoint[POINT_FINISH].x)
		return _vec3(-1,0,-1);

	_vec3 vResult;
	if (vPoint1->x == vPoint2->x)
	{
		vResult.x = vPoint1->x;
		vResult.y = 0.3f;
		vResult.z = finclina2*vResult.x + fcon2;

		return vResult;
	}
	else if (m_vPoint[POINT_START].x == m_vPoint[POINT_FINISH].x)
	{
		vResult.x = m_vPoint[POINT_START].x;
		vResult.y = 0.3f;
		vResult.z = finclina1*vResult.x + fcon1;

		return vResult;
	}

	vResult.x = -(fcon1 - fcon2) / (finclina1 - finclina2);
	vResult.y = 0.3f;
	vResult.z = finclina1*vResult.x  +fcon1;

	return vResult;
}

Engine::CLine* Engine::CLine::Create(const _vec2* pPointA, const _vec2* pPointB)
{
	CLine*	pInstance = new CLine;

	if (FAILED(pInstance->Ready_Line(pPointA, pPointB)))
		Safe_Release(pInstance);

	return pInstance;
}

void Engine::CLine::Free(void)
{

}


#include "ColliderSphere.h"

USING(Engine)
Engine::CColliderSphere::CColliderSphere(LPDIRECT3DDEVICE9 pGraphicDev)
	: m_pGraphicDev(pGraphicDev)
{
	m_pGraphicDev->AddRef();
}

Engine::CColliderSphere::~CColliderSphere(void)
{

}

HRESULT Engine::CColliderSphere::Ready_Collider(const _vec3* pPos, const _float& fRadius)
{

	D3DXCreateSphere(m_pGraphicDev, fRadius, 10, 10, &m_pSphere, NULL);

	m_vPos = *pPos;
	m_fRadius = fRadius;

#ifdef _DEBUG

	for (_uint i = 0; i < COL_END; ++i)
	{
		m_pGraphicDev->CreateTexture(1, 1, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, &m_pTexture[i], NULL);

		D3DLOCKED_RECT	tLockRect;
		ZeroMemory(&tLockRect, sizeof(D3DLOCKED_RECT));

		m_pTexture[i]->LockRect(0, &tLockRect, NULL, NULL);

		*((_ulong*)tLockRect.pBits) = D3DXCOLOR(1.f * i, 1.f * (1.f - i), 0.f, 1.f);

		m_pTexture[i]->UnlockRect(0);
	}
#endif

	return S_OK;
}

void Engine::CColliderSphere::Render_Collider(COLLTYPE eType, const _matrix* pColliderMatrix)
{
	m_matWorld = *pColliderMatrix;

#ifdef _DEBUG
	m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, FALSE);
	m_pGraphicDev->SetTransform(D3DTS_WORLD, pColliderMatrix);

	m_pGraphicDev->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	m_pGraphicDev->SetTexture(0, m_pTexture[eType]);

	m_pGraphicDev->SetFVF(FVF_CUBE);
	m_pSphere->DrawSubset(0);

	m_pGraphicDev->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID	);
	m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, TRUE);
#endif
}

Engine::CColliderSphere* Engine::CColliderSphere::Create(LPDIRECT3DDEVICE9 pGraphicDev, const _vec3* pPos, const _float& fRadius)
{
	CColliderSphere*	pInstance = new CColliderSphere(pGraphicDev);

	if (FAILED(pInstance->Ready_Collider(pPos, fRadius)))
		Safe_Release(pInstance);

	return pInstance;
}

void Engine::CColliderSphere::Free(void)
{
	#ifdef _DEBUG

	for (_uint i = 0; i < COL_END; ++i)
		Safe_Release(m_pTexture[i]);

#endif
	
	m_pSphere->Release();
	Safe_Release(m_pGraphicDev);
}


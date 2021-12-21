#include "Export_Utility.h"

USING(Engine)
IMPLEMENT_SINGLETON(CRenderer)

Engine::CRenderer::CRenderer(void)
	: m_pVB(nullptr)
	, m_pIB(nullptr)
{

}

Engine::CRenderer::~CRenderer(void)
{
	Safe_Release(m_pVB);
	Safe_Release(m_pIB);

	Free();
}

void Engine::CRenderer::Add_RenderGroup(RENDERID eGroup, CGameObject* pGameObject)
{
	if (RENDER_END <= eGroup)
		return;

	m_RenderGroup[eGroup].push_back(pGameObject);

	pGameObject->AddRef();
}

void Engine::CRenderer::Render_GameObject(LPDIRECT3DDEVICE9& pGraphicDev)
{
	Render_Priority(pGraphicDev);
	
	Render_Defferd(pGraphicDev);
	Render_LightAcc(pGraphicDev);

	Render_Blend(pGraphicDev);

	Render_Alpha(pGraphicDev);
	Render_UI(pGraphicDev);

#ifdef _DEBUG
	//Engine::Render_DebugBuffer(L"MRT_Defferd");
	//Engine::Render_DebugBuffer(L"MRT_LightAcc");
#endif // _DEBUG
		
	Clear_RenderGroup();
}

void Engine::CRenderer::Clear_RenderGroup(void)
{
	for (_uint i = 0; i < RENDER_END; ++i)
	{
		for_each(m_RenderGroup[i].begin(), m_RenderGroup[i].end(), CDeleteObj());
		m_RenderGroup[i].clear();
	}
}

HRESULT Engine::CRenderer::Ready_Renderer(LPDIRECT3DDEVICE9& pGraphicDev)
{
	FAILED_CHECK_RETURN(pGraphicDev->CreateVertexBuffer(sizeof(VTXSCREEN) * 4,
		0,
		FVF_SCREEN,
		D3DPOOL_MANAGED,
		&m_pVB,
		NULL),
		E_FAIL);


	FAILED_CHECK_RETURN(pGraphicDev->CreateIndexBuffer(sizeof(INDEX16) * 2,	// 생성할 인덱스 버퍼의 크기
		0,					// 버퍼의 종류(숫자가 0인 경우 정적 버퍼)
		D3DFMT_INDEX16,			// 생성하는 인덱스의 속성값
		D3DPOOL_MANAGED,	// 메모리 풀의 설정
		&m_pIB,
		NULL),
		E_FAIL);

	D3DVIEWPORT9		ViewPort;
	pGraphicDev->GetViewport(&ViewPort);

	VTXSCREEN*		pVertex = nullptr;

	m_pVB->Lock(0, 0, (void**)&pVertex, 0);

	pVertex[0].vPos = _vec4(0.f, 0.f, 0.f, 1.f);
	pVertex[0].vTexUV = _vec2(0.f, 0.f);

	pVertex[1].vPos = _vec4(_float(ViewPort.Width), 0.f, 0.f, 1.f);
	pVertex[1].vTexUV = _vec2(1.f, 0.f);

	pVertex[2].vPos = _vec4(_float(ViewPort.Width), _float(ViewPort.Height), 0.f, 1.f);
	pVertex[2].vTexUV = _vec2(1.f, 1.f);

	pVertex[3].vPos = _vec4(0.f, _float(ViewPort.Height), 0.f, 1.f);
	pVertex[3].vTexUV = _vec2(0.f, 1.f);

	m_pVB->Unlock();

	INDEX16*		pIndex = nullptr;

	m_pIB->Lock(0, 0, (void**)&pIndex, 0);

	// 0
	pIndex[0]._0 = 0;
	pIndex[0]._1 = 1;
	pIndex[0]._2 = 2;

	// 1
	pIndex[1]._0 = 0;
	pIndex[1]._1 = 2;
	pIndex[1]._2 = 3;

	m_pIB->Unlock();


	return S_OK;
}

void CRenderer::Render_Priority(LPDIRECT3DDEVICE9 & pGraphicDev)
{
	//pGraphicDev->SetRenderState(D3DRS_LIGHTING, FALSE);
	//pGraphicDev->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

	for (auto& iter : m_RenderGroup[RENDER_PRIORITY])
		iter->Render_GameObject();

	//pGraphicDev->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	//pGraphicDev->SetRenderState(D3DRS_LIGHTING, TRUE);
}

void CRenderer::Render_NonAlpha(LPDIRECT3DDEVICE9 & pGraphicDev)
{
	//pGraphicDev->SetRenderState(D3DRS_LIGHTING, FALSE);

	for (auto& iter : m_RenderGroup[RENDER_NONALPHA])
		iter->Render_GameObject();

	//pGraphicDev->SetRenderState(D3DRS_LIGHTING, TRUE);
}

_bool	Compare_Z(CGameObject* pDest, CGameObject* pSour)
{
	return pDest->Get_ViewZ() > pSour->Get_ViewZ();
}

void CRenderer::Render_Alpha(LPDIRECT3DDEVICE9 & pGraphicDev)
{
	//pGraphicDev->SetRenderState(D3DRS_LIGHTING, FALSE);
	//pGraphicDev->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	//pGraphicDev->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	//pGraphicDev->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	m_RenderGroup[RENDER_ALPHA].sort(Compare_Z);

	for (auto& iter : m_RenderGroup[RENDER_ALPHA])
		iter->Render_GameObject();

	//pGraphicDev->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
	//pGraphicDev->SetRenderState(D3DRS_LIGHTING, TRUE);
}

void CRenderer::Render_UI(LPDIRECT3DDEVICE9 & pGraphicDev)
{
	//pGraphicDev->SetRenderState(D3DRS_LIGHTING, FALSE);
	
	for (auto& iter : m_RenderGroup[RENDER_UI])
		iter->Render_GameObject();

	//pGraphicDev->SetRenderState(D3DRS_LIGHTING, TRUE);
}


void Engine::CRenderer::Render_Blend(LPDIRECT3DDEVICE9& pGraphicDev)
{
	CShader*	pShader = dynamic_cast<Engine::CShader*>(Engine::Clone_Prototype(L"Shader_Blend"));
	NULL_CHECK(pShader);

	LPD3DXEFFECT pEffect = pShader->Get_EffectHandle();
	pEffect->AddRef();

	Engine::SetUp_OnShader(pEffect, L"Target_Albedo", "g_AlbedoTexture");
	Engine::SetUp_OnShader(pEffect, L"Target_Light", "g_LightTexture");
	Engine::SetUp_OnShader(pEffect, L"Target_Specular", "g_SpecularTexture");

	pEffect->Begin(NULL, 0);
	pEffect->BeginPass(1);

	pGraphicDev->SetStreamSource(0, m_pVB, 0, sizeof(VTXSCREEN));
	pGraphicDev->SetFVF(FVF_SCREEN);
	pGraphicDev->SetIndices(m_pIB);
	pGraphicDev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);

	pEffect->EndPass();
	pEffect->End();


	Safe_Release(pEffect);
	Safe_Release(pShader);
}

void Engine::CRenderer::Render_LightAcc(LPDIRECT3DDEVICE9& pGraphicDev)
{
	Engine::Begin_MRT(L"MRT_LightAcc");

	CShader*	pShader = dynamic_cast<Engine::CShader*>(Engine::Clone_Prototype(L"Shader_Light"));
	NULL_CHECK(pShader);

	LPD3DXEFFECT pEffect = pShader->Get_EffectHandle();
	pEffect->AddRef();

	Engine::SetUp_OnShader(pEffect, L"Target_Normal", "g_NormalTexture");
	Engine::SetUp_OnShader(pEffect, L"Target_Depth", "g_DepthTexture");

	pEffect->Begin(NULL, 0);

	Engine::Render_Light(pEffect);

	pEffect->End();

	Engine::End_MRT(L"MRT_LightAcc");

	Safe_Release(pEffect);
	Safe_Release(pShader);
}

void Engine::CRenderer::Render_Defferd(LPDIRECT3DDEVICE9& pGraphicDev)
{
	Engine::Begin_MRT(L"MRT_Defferd");

	Render_NonAlpha(pGraphicDev);

	Engine::End_MRT(L"MRT_Defferd");
}


void Engine::CRenderer::Free(void)
{
	Clear_RenderGroup();
}


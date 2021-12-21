#include "stdafx.h"
#include "Switch.h"

#include "Export_Function.h"

#include "Door.h"
#include "SoundMgr.h"

CSwitch::CSwitch(LPDIRECT3DDEVICE9 pGraphicDev)
	: CStaticMeshObj(pGraphicDev)
{

}

CSwitch::~CSwitch(void)
{

}

HRESULT CSwitch::Ready_GameObject(const _uint& iFlag)
{
	CStaticMeshObj::Ready_GameObject(iFlag);

	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	return S_OK;
}

_int CSwitch::Update_GameObject(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_GameObject(fTimeDelta);
	
	return NO_EVENT;
}

_int CSwitch::LateUpdate_GameObject(const _float & fTimeDelta)
{
	m_bColl = Collision_ToObject(L"GameLogic", L"Player") || Collision_ToObject(L"GameLogic", L"Skeleton_Ball_0");

	if (m_bColl)
	{
		m_fCross = 1.f;
		wstring tag = L"wall_inswd_doorLeft_1x_2";
		m_pDoorLeft = dynamic_cast<CDoor*>(dynamic_cast<CStaticMeshObj*>(Engine::Get_GameObj(L"GameLogic", tag.c_str())));
		m_pDoorLeft->Set_Move(true);
		tag = L"wall_inswd_doorRight_1x_2";
		m_pDoorRight = dynamic_cast<CDoor*>(dynamic_cast<CStaticMeshObj*>(Engine::Get_GameObj(L"GameLogic", tag.c_str())));
		m_pDoorRight->Set_Move(true);
		if (m_bIsSound)
		{
			CSoundMgr::GetInstance()->PlaySound(L"switch_moved.ogg", CSoundMgr::EFFECT);
			m_bIsSound = false;
		}
	}
	else
	{
		m_fCross = 6.f;
		if (!m_bIsSound)
		{
			CSoundMgr::GetInstance()->PlaySound(L"switch_moved.ogg", CSoundMgr::EFFECT);
			m_bIsSound = true;
		}
		if (m_pDoorLeft)
			m_pDoorLeft->Set_Move(false);
		if (m_pDoorRight)
			m_pDoorRight->Set_Move(false);
	}

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	return NO_EVENT;
}

void CSwitch::Render_GameObject(void)
{
	if (false == m_bDraw)
		return;

	LPD3DXEFFECT	pEffect = m_pShaderCom->Get_EffectHandle();
	NULL_CHECK(pEffect);
	pEffect->AddRef();

	_uint	iPassMax = 0;

	FAILED_CHECK_RETURN(SetUp_ConstantTable(pEffect), );

	pEffect->Begin(&iPassMax, 0);

	m_pMeshCom->Render_Meshes(pEffect);

	pEffect->End();

	Safe_Release(pEffect);

	_matrix		matWorld;
	m_pTransformCom->Get_WorldMatrix(&matWorld);

	m_pColiderSphereCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);

}

HRESULT CSwitch::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	pComponent = m_pColiderSphereCom = Engine::CColliderSphere::Create(m_pGraphicDev,
		m_pTransformCom->Get_Info(Engine::INFO_POS), 50.f);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_ColliderSphere", pComponent);
	
	return S_OK;
}

_bool CSwitch::Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag)
{
	Engine::CTransform*			pPlayerTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pPlayerTransformCom, false);

	Engine::CColliderSphere*	pPlayerColliderSphereCom = dynamic_cast<Engine::CColliderSphere*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_ColliderSphere", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderSphereCom, false);


	return m_pCalculatorCom->Coliision_Sphere(pPlayerTransformCom->Get_Info(Engine::INFO_POS),
		pPlayerColliderSphereCom->Get_Radius(),
		m_pTransformCom->Get_Info(Engine::INFO_POS),
		m_pColiderSphereCom->Get_Radius());
}

CSwitch* CSwitch::Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag)
{
	CSwitch*	pInstance = new CSwitch(pGraphicDev);

	memcpy(pInstance->m_ObjTag, ObjTag.c_str(), (ObjTag.length() + 1) * sizeof(_tchar));
	memcpy(pInstance->m_MeshTag, MeshTag.c_str(), (MeshTag.length() + 1) * sizeof(_tchar));

	if (FAILED(pInstance->Ready_GameObject(iFlag)))
		Engine::Safe_Release(pInstance);
	
	return pInstance;
}

void CSwitch::Free(void)
{
	Engine::CGameObject::Free();
}

HRESULT CSwitch::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
{
	_matrix			matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);

	pEffect->SetFloat("g_fCrossY", m_fCross);

	return S_OK;
}
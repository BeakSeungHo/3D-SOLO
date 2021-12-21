#include "stdafx.h"
#include "DoorFrame.h"
#include "Door.h"
#include "Export_Function.h"

CDoorFrame::CDoorFrame(LPDIRECT3DDEVICE9 pGraphicDev)
	: CStaticMeshObj(pGraphicDev)
{

}

CDoorFrame::~CDoorFrame(void)
{

}

HRESULT CDoorFrame::Ready_GameObject(const _uint& iFlag)
{
	CStaticMeshObj::Ready_GameObject(iFlag);

	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	return S_OK;
}

_int CDoorFrame::Update_GameObject(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_GameObject(fTimeDelta);
	
	return NO_EVENT;
}

_int CDoorFrame::LateUpdate_GameObject(const _float & fTimeDelta)
{
	m_bColl = Collision_ToObject(L"GameLogic", L"Player");

	if (m_bColl)
	{
		wstring tag = L"wall_inswd_doorLeft_1x_" + to_wstring(m_iCount);
		m_pDoorLeft = dynamic_cast<CDoor*>(dynamic_cast<CStaticMeshObj*>(Engine::Get_GameObj(L"GameLogic", tag.c_str())));
		m_pDoorLeft->Set_Move(true);
		tag = L"wall_inswd_doorRight_1x_" + to_wstring(m_iCount);
		m_pDoorRight = dynamic_cast<CDoor*>(dynamic_cast<CStaticMeshObj*>(Engine::Get_GameObj(L"GameLogic", tag.c_str())));
		m_pDoorRight->Set_Move(true);
	}
	else
	{
		if (m_pDoorLeft)
			m_pDoorLeft->Set_Move(false);
		if (m_pDoorRight)
			m_pDoorRight->Set_Move(false);
	}

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	return NO_EVENT;
}

void CDoorFrame::Render_GameObject(void)
{
	CStaticMeshObj::Render_GameObject();

	_matrix		matWorld;
	m_pTransformCom->Get_WorldMatrix(&matWorld);

	m_pColiderSphereCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);

}

void CDoorFrame::Set_Count(_int iCount)
{
	m_iCount = iCount;
}

void CDoorFrame::Set_Coll(_bool bColl)
{
	m_bColl = bColl;
}

HRESULT CDoorFrame::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	pComponent = m_pColiderSphereCom = Engine::CColliderSphere::Create(m_pGraphicDev,
		m_pTransformCom->Get_Info(Engine::INFO_POS), 100.f);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_ColliderSphere", pComponent);
	
	return S_OK;
}

_bool CDoorFrame::Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag)
{
	Engine::CTransform*			pPlayerTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(pLayerTag,pObjTag,L"Com_Transform",Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pPlayerTransformCom, false);

	Engine::CColliderSphere*	pPlayerColliderSphereCom = dynamic_cast<Engine::CColliderSphere*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_ColliderSphere", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderSphereCom, false);
	

	return m_pCalculatorCom->Coliision_Sphere(pPlayerTransformCom->Get_Info(Engine::INFO_POS),
		pPlayerColliderSphereCom->Get_Radius(),
		m_pTransformCom->Get_Info(Engine::INFO_POS),
		m_pColiderSphereCom->Get_Radius());
}

CDoorFrame* CDoorFrame::Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag)
{
	CDoorFrame*	pInstance = new CDoorFrame(pGraphicDev);

	memcpy(pInstance->m_ObjTag, ObjTag.c_str(), (ObjTag.length() + 1) * sizeof(_tchar));
	memcpy(pInstance->m_MeshTag, MeshTag.c_str(), (MeshTag.length() + 1) * sizeof(_tchar));

	if (FAILED(pInstance->Ready_GameObject(iFlag)))
		Engine::Safe_Release(pInstance);
	
	return pInstance;
}

void CDoorFrame::Free(void)
{
	Engine::CGameObject::Free();
}

HRESULT CDoorFrame::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
{
	_matrix			matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);

	return S_OK;
}
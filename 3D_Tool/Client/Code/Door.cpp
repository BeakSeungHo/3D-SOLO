#include "stdafx.h"
#include "Door.h"

#include "Player.h"
#include "Export_Function.h"

#include "SoundMgr.h"

CDoor::CDoor(LPDIRECT3DDEVICE9 pGraphicDev)
	: CStaticMeshObj(pGraphicDev)
{

}

CDoor::~CDoor(void)
{

}

HRESULT CDoor::Ready_GameObject(const _uint& iFlag)
{
	CStaticMeshObj::Ready_GameObject(iFlag);

	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	return S_OK;
}

_int CDoor::Update_GameObject(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_GameObject(fTimeDelta);
	
	return NO_EVENT;
}

_int CDoor::LateUpdate_GameObject(const _float & fTimeDelta)
{
	m_bColl = Collision_ToObject(L"GameLogic", L"Player");

	if (m_bColl)
		dynamic_cast<CPlayer*>(Engine::Get_GameObj(L"GameLogic", L"Player"))->Set_bIsColl(true);


	if (m_bIsMove)
	{
		if (m_bIsSound)
		{
			CSoundMgr::GetInstance()->PlaySound(L"MagnetDoorSlide.ogg", CSoundMgr::EFFECT);
			m_bIsSound = false;
		}

		m_pTransformCom->Set_Pos(&(*m_pTransformCom->Get_Info(Engine::INFO_POS) + (m_vOriPos + m_vDir * 0.6f - *m_pTransformCom->Get_Info(Engine::INFO_POS)) * 0.1f));
	}

	else
	{
		if (!m_bIsSound)
		{
			CSoundMgr::GetInstance()->PlaySound(L"MagnetDoorSlide.ogg", CSoundMgr::EFFECT);
			m_bIsSound = true;
		}

		m_pTransformCom->Set_Pos(&(*m_pTransformCom->Get_Info(Engine::INFO_POS) + (m_vOriPos - *m_pTransformCom->Get_Info(Engine::INFO_POS)) * 0.1f));
	}

	Engine::CGameObject::Update_GameObject(fTimeDelta);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	return NO_EVENT;
}

void CDoor::Render_GameObject(void)
{
	CStaticMeshObj::Render_GameObject();

	_matrix		matWorld;
	m_pTransformCom->Get_WorldMatrix(&matWorld);

	m_pColliderCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);
	m_pColiderSphereCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);
}

void CDoor::Set_Move(_bool bIsMove)
{
	m_bIsMove = bIsMove;
}

void CDoor::Set_OriPos(_vec3 vOriPos)
{
	m_vOriPos = vOriPos;
}

void CDoor::Set_Direction(_vec3 vDir)
{
	m_vDir = vDir;
}

HRESULT CDoor::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	pComponent = m_pColliderCom = Engine::CCollider::Create(m_pGraphicDev,
		m_pMeshCom->Get_VtxPos(),
		m_pMeshCom->Get_NumVtx(),
		m_pMeshCom->Get_Stride());
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Collider", pComponent);

	pComponent = m_pColiderSphereCom = Engine::CColliderSphere::Create(m_pGraphicDev,
		m_pTransformCom->Get_Info(Engine::INFO_POS), 50.f);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_ColliderSphere", pComponent);
	
	return S_OK;
}

_bool CDoor::Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag)
{
	Engine::CColliderBox*	pPlayerColliderCom = dynamic_cast<Engine::CColliderBox*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Collider", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderCom, false);
	
	Engine::CTransform*			pPlayerTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pPlayerTransformCom, false);

	Engine::CColliderSphere*	pPlayerColliderSphereCom = dynamic_cast<Engine::CColliderSphere*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_ColliderSphere", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderSphereCom, false);


	if (m_pCalculatorCom->Coliision_Sphere(pPlayerTransformCom->Get_Info(Engine::INFO_POS),
		pPlayerColliderSphereCom->Get_Radius(),
		m_pTransformCom->Get_Info(Engine::INFO_POS),
		m_pColiderSphereCom->Get_Radius()))
	{
		return m_pCalculatorCom->Collision_OBB(pPlayerColliderCom->Get_Min(),
			pPlayerColliderCom->Get_Max(),
			pPlayerColliderCom->Get_ColliderBoxMatrix(),
			m_pColliderCom->Get_Min(),
			m_pColliderCom->Get_Max(),
			m_pColliderCom->Get_ColliderMatrix());
	}
	else
		return false;
}

CDoor* CDoor::Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag)
{
	CDoor*	pInstance = new CDoor(pGraphicDev);

	memcpy(pInstance->m_ObjTag, ObjTag.c_str(), (ObjTag.length() + 1) * sizeof(_tchar));
	memcpy(pInstance->m_MeshTag, MeshTag.c_str(), (MeshTag.length() + 1) * sizeof(_tchar));

	if (FAILED(pInstance->Ready_GameObject(iFlag)))
		Engine::Safe_Release(pInstance);
	
	return pInstance;
}

void CDoor::Free(void)
{
	Engine::CGameObject::Free();
}

HRESULT CDoor::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
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
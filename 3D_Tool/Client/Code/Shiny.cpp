#include "stdafx.h"
#include "Shiny.h"

#include "Player.h"
#include "Aim.h"
#include "Explosion.h"
#include "LaunchEffect.h"
#include "SoundMgr.h"
#include "Export_Function.h"

CShiny::CShiny(LPDIRECT3DDEVICE9 pGraphicDev)
	: CStaticMeshObj(pGraphicDev)
{

}

CShiny::~CShiny(void)
{

}

HRESULT CShiny::Ready_GameObject(const _uint& iFlag)
{
	CStaticMeshObj::Ready_GameObject(iFlag);

	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	return S_OK;
}

_int CShiny::Update_GameObject(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_GameObject(fTimeDelta);
	
	m_pTransformCom->m_matWorld.m[3][1] -= 9.8f * fTimeDelta;

	if (m_pTransformCom->m_matWorld.m[3][1] < 0.f)
		m_pTransformCom->m_matWorld.m[3][1] = 0.f;

	m_pTransformCom->Set_Pos(m_pTransformCom->m_matWorld.m[3][0],
		m_pTransformCom->m_matWorld.m[3][1],
		m_pTransformCom->m_matWorld.m[3][2]);



	m_bIsConveyor = false;
		

	return NO_EVENT;
}

_int CShiny::LateUpdate_GameObject(const _float & fTimeDelta)
{
	if (m_bIsLerp)
	{
		_vec3 vPos;
		//wstring szTemp = L"LaunchEffect_" + to_wstring(m_iEffectCount);
		//m_iEffectCount++;
		D3DXVec3Lerp(&vPos, m_pTransformCom->Get_Info(Engine::INFO_POS), &m_vEndPos, 0.2f);
		//CLaunchEffect* pLaunchEffect = CLaunchEffect::Create(m_pGraphicDev, szTemp);
		//dynamic_cast<Engine::CTransform*>(pLaunchEffect->Get_Component(L"Com_Transform",Engine::ID_DYNAMIC))->Set_Pos(m_pTransformCom->Get_Info(Engine::INFO_POS)->x, 0.3f, m_pTransformCom->Get_Info(Engine::INFO_POS)->z);
		//Engine::Get_Layer(L"GameLogic")->Add_GameObject(pLaunchEffect->Get_ObjTag(), pLaunchEffect);
		m_pTransformCom->Set_Pos(&vPos);
		if (D3DXVec3Length(&(*m_pTransformCom->Get_Info(Engine::INFO_POS) - m_vEndPos)) < 0.1f)
		{
			m_bIsLerp = false;
		//	m_iEffectCount = 0;
		}
	}

	m_bColl = Collision_ToObject(L"GameLogic", L"Player");

	if (m_bColl)
		dynamic_cast<CPlayer*>(Engine::Get_GameObj(L"GameLogic", L"Player"))->Set_bIsColl(true);

	Engine::CGameObject::Update_GameObject(fTimeDelta);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);


	if (m_bIsDead)
	{
		CExplosion* pExplosion = CExplosion::Create(m_pGraphicDev);
		dynamic_cast<Engine::CTransform*>(pExplosion->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(m_pTransformCom->Get_Info(Engine::INFO_POS)->x, 0.2f, m_pTransformCom->Get_Info(Engine::INFO_POS)->z);
		Engine::Get_Layer(L"GameLogic")->Add_GameObject(L"Explosion", pExplosion);
		CSoundMgr::GetInstance()->PlaySound(L"Explosive_barrel_clic.ogg",CSoundMgr::EFFECT);

		return DEAD_OBJ;
	}

	return NO_EVENT;
}

void CShiny::Render_GameObject(void)
{
	CStaticMeshObj::Render_GameObject();

	_matrix		matWorld;
	m_pTransformCom->Get_WorldMatrix(&matWorld);

	m_pColliderCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);
	m_pColiderSphereCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);
}

void CShiny::Set_Lerp(_bool bIsLerp)
{
	m_bIsLerp = bIsLerp;
}

void CShiny::Set_EndPos(_vec3 vEndPos)
{
	m_vEndPos = vEndPos;
}

HRESULT CShiny::Add_Component(void)
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

_bool CShiny::Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag)
{
	Engine::CColliderBox*	pPlayerColliderCom = dynamic_cast<Engine::CColliderBox*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Collider", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderCom, false);
	
	Engine::CTransform*			pPlayerTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pPlayerTransformCom, false);

	Engine::CColliderSphere*	pPlayerColliderSphereCom = dynamic_cast<Engine::CColliderSphere*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_ColliderSphere", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderSphereCom, false);

	CPlayer*	pPlayer = dynamic_cast<CPlayer*>(Engine::Get_GameObj(L"GameLogic", L"Player"));

	Engine::CTransform*			pAimTransformCom = dynamic_cast<Engine::CTransform*>(pPlayer->GetAim()->Get_Component(L"Com_Transform",Engine::ID_DYNAMIC));
	Engine::CColliderSphere*	pAimColliderSphereCom = dynamic_cast<Engine::CColliderSphere*>(pPlayer->GetAim()->Get_Component(L"Com_ColliderSphere", Engine::ID_STATIC));

	if (m_pCalculatorCom->Coliision_Sphere(pAimTransformCom->Get_Info(Engine::INFO_POS),
		pAimColliderSphereCom->Get_Radius(),
		m_pTransformCom->Get_Info(Engine::INFO_POS),
		m_pColiderSphereCom->Get_Radius()))
	{
		dynamic_cast<Engine::CTransform*>(pPlayer->GetAim()->Get_Component(L"Com_Transform",Engine::ID_DYNAMIC))->Set_Pos(m_pTransformCom->Get_Info(Engine::INFO_POS));
	}

	if (m_pCalculatorCom->Coliision_Sphere(pPlayerTransformCom->Get_Info(Engine::INFO_POS),
		pPlayerColliderSphereCom->Get_Radius(),
		m_pTransformCom->Get_Info(Engine::INFO_POS),
		m_pColiderSphereCom->Get_Radius()))
	{
		if (pPlayer->GetbIsBreak())
		{
			pPlayer->Set_bIsObj(false);
			m_bIsDead = true;
			return false;
		}
			

		if (pPlayer->GetbIsWarp())
		{
			pPlayer->Set_bIsObj(true);
			pPlayer->Set_CloneMesh(dynamic_cast<Engine::CStaticMesh*>(Engine::Clone(RESOURCE_STAGE, m_MeshTag)));
			dynamic_cast<Engine::CTransform*>(pPlayer->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(m_pTransformCom->Get_Info(Engine::INFO_POS));
			return false;
		}
		
		pPlayer->Set_bIsObj(false);
		return m_pCalculatorCom->Collision_OBB(pPlayerColliderCom->Get_Min(),
			pPlayerColliderCom->Get_Max(),
			pPlayerColliderCom->Get_ColliderBoxMatrix(),
			m_pColliderCom->Get_Min(),
			m_pColliderCom->Get_Max(),
			m_pColliderCom->Get_ColliderMatrix());
		
	}
	//else
	//{
	//	pPlayer->Set_bIsObj(false);
	//	return false;
	//}

	return false;
}

CShiny* CShiny::Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MeshTag, wstring ObjTag)
{
	CShiny*	pInstance = new CShiny(pGraphicDev);

	memcpy(pInstance->m_ObjTag, ObjTag.c_str(), (ObjTag.length() + 1) * sizeof(_tchar));
	memcpy(pInstance->m_MeshTag, MeshTag.c_str(), (MeshTag.length() + 1) * sizeof(_tchar));

	if (FAILED(pInstance->Ready_GameObject(iFlag)))
		Engine::Safe_Release(pInstance);
	
	return pInstance;
}

void CShiny::Free(void)
{
	Engine::CGameObject::Free();
}

HRESULT CShiny::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
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
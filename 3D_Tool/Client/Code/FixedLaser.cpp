#include "stdafx.h"
#include "FixedLaser.h"

#include "StaticCamera.h"
#include "Robot.h"
#include "Player.h"

#include "Export_Function.h"

CFixedLaser::CFixedLaser(LPDIRECT3DDEVICE9 pGraphicDev)
	: CLaser(pGraphicDev)
{

}

CFixedLaser::~CFixedLaser(void)
{

}

HRESULT CFixedLaser::Ready_GameObject(void)
{
	CLaser::Ready_GameObject();

	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	m_vLaser[0] = { 0.f,0.f, 0.f };
	m_vLaser[1] = { 1.5f,0.f, 0.f };

	if(m_iCount >= 7)
		m_vLaser[1] = { 2.5f,0.f, 0.f };

	m_pTransformCom->Set_Scale(100.f, 100.f, 100.f);
	m_pTransformCom->Rotation(Engine::ROT_Z, D3DXToRadian(90));

	return S_OK;
}

_int CFixedLaser::Update_GameObject(const _float& fTimeDelta)
{
	_int iEvent = CLaser::Update_GameObject(fTimeDelta);	

	m_vLaser[1] = { 1.5f ,0.f,0.f };

	if (m_iCount >= 7)
		m_vLaser[1] = { 2.5f,0.f, 0.f };

	wstring szTag = L"Laser_Fixed_" + to_wstring(m_iCount);

	Engine::CTransform*	pRobotTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", szTag.c_str(), L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pRobotTransCom, 0);

	m_pParentWorldMatrix = pRobotTransCom->Get_WorldMatrixPointer();
	

	m_pTransformCom->Set_ParentMatrix(m_pParentWorldMatrix);

	_matrix		matWorld;

	m_pTransformCom->Get_WorldMatrix(&matWorld);

	D3DXVec3TransformCoord(&vLaserStart, &m_vLaser[0], &matWorld);
	D3DXVec3TransformCoord(&vLaserEnd, &m_vLaser[1], &matWorld);
	
	m_bColl = Collision_ToObject(L"GameLogic", L"Player");

	if(m_bIsDead)
		return iEvent;

	return iEvent;
}

_int CFixedLaser::LateUpdate_GameObject(const _float & fTimeDelta)
{
	Engine::CGameObject::Compute_ViewZ(&m_pTransformCom->m_vInfo[Engine::INFO_POS]);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_ALPHA, this);

	return NO_EVENT;
}

void CFixedLaser::Render_GameObject(void)
{
	CLaser::Render_GameObject();
}

void CFixedLaser::Set_Count(_int iCount)
{
	m_iCount = iCount;
}

HRESULT CFixedLaser::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	pComponent = m_pColiderBoxCom = Engine::CColliderBox::Create(m_pGraphicDev,
	m_pTransformCom->Get_Info(Engine::INFO_POS), &_vec3(0.f, -0.001f, -1.f), &_vec3(1.5f, 0.001f, 1.f));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_ColliderBox", pComponent);

	return S_OK;
}

_bool CFixedLaser::Collision_ToObject(const _tchar * pLayerTag, const _tchar * pObjTag)
{
	Engine::CCollider*			pObjectColliderCom = nullptr;
	Engine::CTransform*			pObjectTransformCom = nullptr;

	if (m_bFirst)
	{
		m_bFirst = false;
		return false;
	}

	auto iter_begin = Engine::Get_Layer(L"GameLogic")->Get_MapObject()->begin();
	auto iter_end = Engine::Get_Layer(L"GameLogic")->Get_MapObject()->end();

	for (; iter_begin != iter_end; ++iter_begin)
	{
		wstring temp = iter_begin->first;
		_int iSearch = temp.find(L"HeavyMetal");

		if (iSearch >= 0)
		{
			pObjectColliderCom = dynamic_cast<Engine::CCollider*>(Engine::Get_Component(pLayerTag, iter_begin->first, L"Com_Collider", Engine::ID_STATIC));
		
			if (m_pCalculatorCom->Collision_OBB(pObjectColliderCom->Get_Min(),
				pObjectColliderCom->Get_Max(),
				pObjectColliderCom->Get_ColliderMatrix(),
				m_pColiderBoxCom->Get_Min(),
				m_pColiderBoxCom->Get_Max(),
				m_pColiderBoxCom->Get_ColliderBoxMatrix()))
			{
				Engine::Get_GameObj(pLayerTag, iter_begin->first)->IsDead();
				break;
			}
		}

		iSearch = temp.find(L"Player");

		if (iSearch >= 0)
		{
			if (dynamic_cast<CPlayer*>(Engine::Get_GameObj(pLayerTag, iter_begin->first))->GetbIsObj())
				continue;

			Engine::CColliderBox* pPlayerColliderBoxCom = dynamic_cast<Engine::CColliderBox*>(Engine::Get_Component(pLayerTag, iter_begin->first, L"Com_Collider", Engine::ID_STATIC));

			if (m_pCalculatorCom->Collision_OBB(pPlayerColliderBoxCom->Get_Min(),
				pPlayerColliderBoxCom->Get_Max(),
				pPlayerColliderBoxCom->Get_ColliderBoxMatrix(),
				m_pColiderBoxCom->Get_Min(),
				m_pColiderBoxCom->Get_Max(),
				m_pColiderBoxCom->Get_ColliderBoxMatrix()))
			{
				Engine::Get_GameObj(pLayerTag, iter_begin->first)->IsDead();

				continue;
			}
		}
	}

	auto iter_begin2 = Engine::Get_Layer(L"GameLogic")->Get_MapObject()->begin();
	auto iter_end2 = Engine::Get_Layer(L"GameLogic")->Get_MapObject()->end();

	for (; iter_begin2 != iter_end2; ++iter_begin2)
	{
		wstring temp = iter_begin2->first;
		_int iSearch = temp.find(L"Shiny");

		if (iSearch >= 0)
		{
			pObjectColliderCom = dynamic_cast<Engine::CCollider*>(Engine::Get_Component(pLayerTag, iter_begin2->first, L"Com_Collider", Engine::ID_STATIC));

			if (m_pCalculatorCom->Collision_OBB(pObjectColliderCom->Get_Min(),
				pObjectColliderCom->Get_Max(),
				pObjectColliderCom->Get_ColliderMatrix(),
				m_pColiderBoxCom->Get_Min(),
				m_pColiderBoxCom->Get_Max(),
				m_pColiderBoxCom->Get_ColliderBoxMatrix()))
			{
				pObjectTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(pLayerTag, iter_begin2->first, L"Com_Transform", Engine::ID_DYNAMIC));

				_float fLength = D3DXVec3Length(&(vLaserStart - *pObjectTransformCom->Get_Info(Engine::INFO_POS)));

				m_vLaser[1] = { fLength ,0.f,0.f };

				break;
			}
		}
	}

	Engine::CColliderBox* pPlayerColliderCom = dynamic_cast<Engine::CColliderBox*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Collider", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderCom, false);

	pObjectTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pObjectTransformCom, false);

	CPlayer*	pPlayer = dynamic_cast<CPlayer*>(Engine::Get_GameObj(L"GameLogic", L"Player"));

	if (pPlayer->GetbIsObj())
		return false;

	return m_pCalculatorCom->Collision_OBB(pPlayerColliderCom->Get_Min(),
		pPlayerColliderCom->Get_Max(),
		pPlayerColliderCom->Get_ColliderBoxMatrix(),
		m_pColiderBoxCom->Get_Min(),
		m_pColiderBoxCom->Get_Max(),
		m_pColiderBoxCom->Get_ColliderBoxMatrix());

	
}



HRESULT CFixedLaser::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
{
	/*_matrix			matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);

	Engine::SetUp_OnShader(pEffect, L"Target_Depth", "g_DepthTexture");

	return S_OK;*/
	return S_OK;
}

CFixedLaser* CFixedLaser::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CFixedLaser*	pInstance = new CFixedLaser(pGraphicDev);

	if (FAILED(pInstance->Ready_GameObject()))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CFixedLaser::Free(void)
{
	CLaser::Free();
}


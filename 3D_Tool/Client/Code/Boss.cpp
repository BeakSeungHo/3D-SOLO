#include "stdafx.h"
#include "Boss.h"

#include "Player.h"
#include "BossWall.h"

#include "Export_Function.h"

CBoss::CBoss(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CBoss::~CBoss(void)
{

}

HRESULT CBoss::Ready_GameObject(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	m_pMeshCom->Set_AnimationSet(BOSS_SEACH);

	m_pTransformCom->Set_Scale(0.01f, 0.01f, 0.01f);

	m_vecPatrol[0] = { 60.4f, 0.f ,21.f };
	m_vecPatrol[1] = { 60.4f, 0.f ,18.9f };
	m_vecPatrol[2] = { 58.f , 0.f ,18.9f };
	m_vecPatrol[3] = { 58.f , 0.f ,23.2f };
	m_vecPatrol[4] = { 60.4f, 0.f ,23.2f };

	return S_OK;
}

_int CBoss::Update_GameObject(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_GameObject(fTimeDelta);

	if (m_pMeshCom->Is_AnimationSetEnd())
	{
		if (nullptr == m_pTarget)
		{
			if (D3DXVec3Length(&(*m_pTransformCom->Get_Info(Engine::INFO_POS) - m_vecPatrol[m_iPatrolCount])) < 0.3f)
			{
				++m_iPatrolCount;
				m_eCurState = BOSS_SEACH;
				m_pMeshCom->Set_AnimationSet(BOSS_SEACH);
				if (m_iPatrolCount > 4)
					m_iPatrolCount = 0;
			}
			else if (BOSS_SEACH == m_eCurState || BOSS_RUN == m_eCurState || BOSS_ATTACK == m_eCurState && m_pMeshCom->Is_AnimationSetEnd())
			{
				m_eCurState = BOSS_WALK;
				m_pMeshCom->Set_AnimationSet(BOSS_WALK);
			}
			else
			{
				m_eCurState = BOSS_WALK;
				m_pMeshCom->Set_AnimationSet(BOSS_WALK);
			}

			if (BOSS_WALK == m_eCurState)
			{
				m_fSpeed = 1.f;
				m_pTransformCom->Move_TargetPos(&m_vecPatrol[m_iPatrolCount], m_fSpeed, fTimeDelta);

				_vec3 m_vDir = m_vecPatrol[m_iPatrolCount] - *m_pTransformCom->Get_Info(Engine::INFO_POS);

				D3DXVec3Normalize(&m_vDir, &m_vDir);

				if (abs(m_vDir.x) > abs(m_vDir.z))
				{
					if (m_vDir.x > 0.f)
					{
						m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(90));

						if (m_vDir.z > 0.3 && m_vDir.z < 0.6)
							m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(45));
						else if (m_vDir.z < -0.6 && m_vDir.z > -0.3)
							m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(135));
					}
					else if (m_vDir.x < 0.f)
					{
						m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(270));
						if (m_vDir.z > 0.3 && m_vDir.z < 0.6)
							m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(315));
						else if (m_vDir.z < -0.6 && m_vDir.z > -0.3)
							m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(225));
					}
				}
				else
				{
					if (m_vDir.z > 0.f)
					{
						m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(0));
					}
					else if (m_vDir.z < 0.f)
					{
						m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(180));
					}
				}

			}
		}
		else
		{
			Engine::CTransform* pTransform = dynamic_cast<Engine::CTransform*>(m_pTarget->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));

			if (D3DXVec3Length(&(*pTransform->Get_Info(Engine::INFO_POS) - *m_pTransformCom->Get_Info(Engine::INFO_POS))) < 1.f)
			{
				m_eCurState = BOSS_ATTACK;
				m_pMeshCom->Set_AnimationSet(BOSS_ATTACK);
			}
			else
			{
				m_fSpeed = 1.5f;
				m_pTransformCom->Move_TargetPos(pTransform->Get_Info(Engine::INFO_POS), m_fSpeed, fTimeDelta);
				m_eCurState = BOSS_RUN;
				m_pMeshCom->Set_AnimationSet(BOSS_RUN);

				m_vDir = *pTransform->Get_Info(Engine::INFO_POS) - *m_pTransformCom->Get_Info(Engine::INFO_POS);

				D3DXVec3Normalize(&m_vDir, &m_vDir);

				if (abs(m_vDir.x) > abs(m_vDir.z))
				{
					if (m_vDir.x > 0.f)
					{
						m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(90));

						if (m_vDir.z > 0.3 && m_vDir.z < 0.6)
							m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(45));
						else if (m_vDir.z < -0.6 && m_vDir.z > -0.3)
							m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(135));
					}
					else if (m_vDir.x < 0.f)
					{
						m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(270));
						if (m_vDir.z > 0.3 && m_vDir.z < 0.6)
							m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(315));
						else if (m_vDir.z < -0.6 && m_vDir.z > -0.3)
							m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(225));
					}
				}
				else
				{
					if (m_vDir.z > 0.f)
					{
						m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(0));
					}
					else if (m_vDir.z < 0.f)
					{
						m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(180));
					}
				}
			}
		}
	}

	if (m_iBrokenCount >= 6)
	{
		m_eCurState = BOSS_STUNE;
		m_pMeshCom->Set_AnimationSet(BOSS_STUNE);
	}
	
	


	return NO_EVENT;
}

_int CBoss::LateUpdate_GameObject(const _float & fTimeDelta)
{
	m_bColl = Collision_ToObject(L"GameLogic", L"Player");
	m_bAttackColl = Collision_Attack();


	if (m_bColl)
	{
		m_pTransformCom->Move_Pos(&(-m_vDir * m_fSpeed * fTimeDelta));
		m_pTransformCom->Move_Pos(&(m_vSlide * m_fSpeed * fTimeDelta));
	}


	m_pMeshCom->Play_Animation(fTimeDelta);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);


	if (m_bIsDead)
		return DEAD_OBJ;

	return NO_EVENT;
}

void CBoss::Render_GameObject(void)
{
	_matrix		matWorld;
	m_pTransformCom->Get_WorldMatrix(&matWorld);

	m_pColliderBoxCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);
	m_pColliderSphereCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);

	const Engine::D3DXFRAME_DERIVED* pBone = m_pMeshCom->Get_FrameByName("b_pneuWeapon1");
	m_matRightArm = pBone->CombinedTransformationMatrix * matWorld;
	m_pAttackSphereCom->Render_Collider(Engine::COLLTYPE(m_bAttackColl), &m_matRightArm);
	
	LPD3DXEFFECT	pEffect = m_pShaderCom->Get_EffectHandle();
	NULL_CHECK(pEffect);
	pEffect->AddRef();

	_uint	iPassMax = 0;

	FAILED_CHECK_RETURN(SetUp_ConstantTable(pEffect), );

	pEffect->Begin(&iPassMax, 0);

	pEffect->BeginPass(0);

	m_pMeshCom->Render_Meshes(pEffect);

	pEffect->EndPass();

	pEffect->End();

	Safe_Release(pEffect);
}

void CBoss::Set_Count(_int iCount)
{
	m_iCount = iCount;
}

void CBoss::Set_State(BOSSSTATE eState)
{
	m_eCurState = eState;
	m_pMeshCom->Set_AnimationSet(eState);
}

void CBoss::Set_BrokenCountUP()
{
	++m_iBrokenCount;
}

HRESULT CBoss::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	pComponent = m_pMeshCom = dynamic_cast<Engine::CDynamicMesh*>(Engine::Clone(RESOURCE_STAGE, L"Boss"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Mesh", pComponent);

	pComponent = m_pTransformCom = Engine::CTransform::Create();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_DYNAMIC].emplace(L"Com_Transform", pComponent);

	pComponent = m_pRendererCom = Engine::Get_Renderer();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	pComponent->AddRef();
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Renderer", pComponent);

	pComponent = m_pCalculatorCom = Engine::CCalculator::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Calculator", pComponent);

	pComponent = m_pColliderBoxCom = Engine::CColliderBox::Create(m_pGraphicDev, m_pTransformCom->Get_Info(Engine::INFO_POS), &_vec3(-30.f, -30.f, -30.f), &_vec3(30.f, 30.f, 30.f));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Collider", pComponent);

	pComponent = m_pColliderSphereCom = Engine::CColliderSphere::Create(m_pGraphicDev,
		m_pTransformCom->Get_Info(Engine::INFO_POS), 500.f);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_ColliderSphere", pComponent);

	pComponent = m_pAttackSphereCom = Engine::CColliderSphere::Create(m_pGraphicDev,
		m_pTransformCom->Get_Info(Engine::INFO_POS), 50.f);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_AttackSphere", pComponent);

	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone_Prototype(L"Shader_Mesh"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);

	return S_OK;
}

_bool CBoss::Collision_ToObject(const _tchar * pLayerTag, const _tchar * pObjTag)
{
	Engine::CColliderBox*	pPlayerColliderCom = dynamic_cast<Engine::CColliderBox*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Collider", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderCom, false);

	Engine::CTransform*			pPlayerTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pPlayerTransformCom, false);

	Engine::CColliderSphere*	pPlayerColliderSphereCom = dynamic_cast<Engine::CColliderSphere*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_ColliderSphere", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderSphereCom, false);

	CPlayer*	pPlayer = dynamic_cast<CPlayer*>(Engine::Get_GameObj(L"GameLogic", L"Player"));
	
	if (m_pCalculatorCom->Coliision_Sphere(pPlayerTransformCom->Get_Info(Engine::INFO_POS),
		pPlayerColliderSphereCom->Get_Radius(),
		m_pTransformCom->Get_Info(Engine::INFO_POS),
		m_pColliderSphereCom->Get_Radius()))
	{
		if (pPlayer->GetbIsObj() && !pPlayer->GetbIsClone())
			m_pTarget = nullptr;
		else
			m_pTarget = pPlayer;
	}
	else
		m_pTarget = nullptr;


	Engine::CCollider*			pObjectColliderCom = nullptr;
	Engine::CTransform*			pObjectTransformCom = nullptr;

	auto iter_begin = Engine::Get_Layer(L"GameLogic")->Get_MapObject()->begin();
	auto iter_end = Engine::Get_Layer(L"GameLogic")->Get_MapObject()->end();

	for (; iter_begin != iter_end; ++iter_begin)
	{
		wstring temp = iter_begin->first;
		_int iSearch = temp.find(L"HeavyMetal");
		_int iSerach2 = temp.find(L"Wall_int_column_1x_b");

		if (iSearch >= 0 || iSerach2 >= 0)
		{
			pObjectColliderCom = dynamic_cast<Engine::CCollider*>(Engine::Get_Component(pLayerTag, iter_begin->first, L"Com_Collider", Engine::ID_STATIC));
			pObjectTransformCom = dynamic_cast<Engine::CTransform*>(iter_begin->second->Get_Component(L"Com_Transform",Engine::ID_DYNAMIC));

			if (m_pCalculatorCom->Collision_OBB(pObjectColliderCom->Get_Min(),
				pObjectColliderCom->Get_Max(),
				pObjectColliderCom->Get_ColliderMatrix(),
				m_pColliderBoxCom->Get_Min(),
				m_pColliderBoxCom->Get_Max(),
				m_pColliderBoxCom->Get_ColliderBoxMatrix()))
			{
				_vec3 vPos = *pObjectTransformCom->Get_Info(Engine::INFO_POS) - *m_pTransformCom->Get_Info(Engine::INFO_POS);
				if (abs(vPos.x) > abs(vPos.z))
				{
					if (vPos.x > 0.f)
					{
						m_vSlideNoraml = {0.f,0.f,-1.f};
					}
					else if (vPos.x < 0.f)
					{
						m_vSlideNoraml = { 0.f,0.f,1.f };
					}
				}
				else
				{
					if (vPos.z > 0.f)
					{
						m_vSlideNoraml = { 1.f,0.f,0.f };
					}
					else if (vPos.z < 0.f)
					{
						m_vSlideNoraml = { -1.f,0.f,0.f };
					}
				}

				m_vSlide = m_vDir - m_vSlideNoraml*(D3DXVec3Dot(&m_vDir ,&m_vSlideNoraml));

				return true;
			}
		}
	}

	return false;
}

_bool CBoss::Collision_Attack()
{
	if (BOSS_ATTACK == m_eCurState)
	{
	
		_vec3 vPos = m_matRightArm.m[3];

		Engine::CColliderSphere*			pObjectColliderCom = nullptr;
		Engine::CTransform*			pObjectTransformCom = nullptr;

		auto iter_begin = Engine::Get_Layer(L"GameLogic")->Get_MapObject()->begin();
		auto iter_end = Engine::Get_Layer(L"GameLogic")->Get_MapObject()->end();

		for (; iter_begin != iter_end; ++iter_begin)
		{
			wstring temp = iter_begin->first;
			_int iSearch = temp.find(L"HeavyMetal");

			if (iSearch >= 0)
			{
				pObjectColliderCom = dynamic_cast<Engine::CColliderSphere*>(iter_begin->second->Get_Component(L"Com_ColliderSphere", Engine::ID_STATIC));
				pObjectTransformCom = dynamic_cast<Engine::CTransform*>(iter_begin->second->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));

				if (m_pCalculatorCom->Coliision_Sphere(pObjectTransformCom->Get_Info(Engine::INFO_POS),
					pObjectColliderCom->Get_Radius(),
					&vPos,
					m_pAttackSphereCom->Get_Radius()))
				{
					Engine::Get_GameObj(L"GameLogic", iter_begin->first)->IsDead();
				}
			}

			iSearch = temp.find(L"Wall_int_column_1x_b");

			if (iSearch >= 0)
			{
				pObjectColliderCom = dynamic_cast<Engine::CColliderSphere*>(iter_begin->second->Get_Component(L"Com_ColliderSphere", Engine::ID_STATIC));
				pObjectTransformCom = dynamic_cast<Engine::CTransform*>(iter_begin->second->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));

				_vec3 ObjPos = *pObjectTransformCom->Get_Info(Engine::INFO_POS);

				if (pObjectTransformCom->Get_Angle()->y == D3DXToRadian(90))
				{
					ObjPos.x += 0.5f;
					ObjPos.z -= 0.5f;
				}
				else
				{
					ObjPos.x += 0.5f;
					ObjPos.z += 0.5f;
				}

				if (m_pCalculatorCom->Coliision_Sphere(&ObjPos,
					pObjectColliderCom->Get_Radius(),
					&vPos,
					m_pAttackSphereCom->Get_Radius()))
				{	
					dynamic_cast<CBossWall*>(iter_begin->second)->Set_Break(true);
					
				}
			}

			iSearch = temp.find(L"Player");

			if (iSearch >= 0)
			{
				pObjectColliderCom = dynamic_cast<Engine::CColliderSphere*>(iter_begin->second->Get_Component(L"Com_ColliderSphere", Engine::ID_STATIC));
				pObjectTransformCom = dynamic_cast<Engine::CTransform*>(iter_begin->second->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
			
				pObjectColliderCom = dynamic_cast<Engine::CColliderSphere*>(iter_begin->second->Get_Component(L"Com_ColliderSphere", Engine::ID_STATIC));
				pObjectTransformCom = dynamic_cast<Engine::CTransform*>(iter_begin->second->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));

				if (m_pCalculatorCom->Coliision_Sphere(pObjectTransformCom->Get_Info(Engine::INFO_POS),
					pObjectColliderCom->Get_Radius(),
					&vPos,
					m_pAttackSphereCom->Get_Radius()))
				{
					Engine::Get_GameObj(L"GameLogic", iter_begin->first)->IsDead();
				}
			}
		}

		if (nullptr != m_pTarget)
		{
			Engine::CTransform* pTargetTransform = dynamic_cast<Engine::CTransform*>(m_pTarget->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));

			Engine::CColliderSphere*	pPlayerColliderSphereCom = dynamic_cast<Engine::CColliderSphere*>(m_pTarget->Get_Component(L"Com_ColliderSphere", Engine::ID_STATIC));
			NULL_CHECK_RETURN(pPlayerColliderSphereCom, false);

			if (m_pCalculatorCom->Coliision_Sphere(pTargetTransform->Get_Info(Engine::INFO_POS),
				pPlayerColliderSphereCom->Get_Radius(),
				&vPos,
				m_pAttackSphereCom->Get_Radius()))
			{
				return true;
			}
		}
		
	}

	return false;
}

CBoss* CBoss::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CBoss*	pInstance = new CBoss(pGraphicDev);

	if (FAILED(pInstance->Ready_GameObject()))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CBoss::Free(void)
{


	Engine::CGameObject::Free();
}


HRESULT CBoss::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
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

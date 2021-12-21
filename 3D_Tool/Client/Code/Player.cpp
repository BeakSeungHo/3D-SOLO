#include "stdafx.h"
#include "Player.h"

#include "Export_Function.h"

#include "Aim.h"
#include "HeavyMetal.h"
#include "Shiny.h"
#include "Clone.h"
#include "WarpEffect.h"
#include "CloneEffect.h"
#include "BreakEffect.h"
#include "SoundMgr.h"

CPlayer::CPlayer(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CPlayer::~CPlayer(void)
{
}

HRESULT CPlayer::Ready_GameObject(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	m_pMeshCom->Set_AnimationSet(4);

	m_pNaviCom->Set_Index(0);

	m_pTransformCom->Set_Scale(0.01f, 0.01f, 0.01f);
	m_pTransformCom->Set_Pos(4.5f, 0.01f, 5.f);
	m_vCheckPos = _vec3(4.5f,0.01f, 5.f);
	m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(90.f));

	_matrix		matWorld;
	D3DXMatrixIdentity(&matWorld);
	matWorld.m[0][0] = 0.01f;
	matWorld.m[1][1] = 0.01f;
	matWorld.m[2][2] = 0.01f;
	
	matWorld.m[3][0] = 4.5f;
	matWorld.m[3][1] = 0.f;
	matWorld.m[3][2] = 5.f;

	m_pColiderSphereCom->Render_Collider(Engine::COL_FALSE, &matWorld);
	m_pColliderBoxCom->Render_Collider(Engine::COL_FALSE, &matWorld);

	m_pAim = CAim::Create(m_pGraphicDev);
	m_pWarpEffect = CWarpEffect::Create(m_pGraphicDev);
	m_pCloneEffect = CCloneEffect::Create(m_pGraphicDev);
	//m_pBreakEffect = CBreakEffect::Create(m_pGraphicDev);

	return S_OK;
}

_int CPlayer::Update_GameObject(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_GameObject(fTimeDelta);

	m_fTimeAcc += fTimeDelta;

	if (m_fTimeAcc >= 10.f)
	{
		srand((unsigned int)time(NULL));
		int RandomCount = rand() % 32 + 1;

		wstring szIDLESOUND = L"vox_zero_idle_00" + to_wstring(RandomCount);
		szIDLESOUND += L".ogg";

		CSoundMgr::GetInstance()->PlaySound(szIDLESOUND,CSoundMgr::PLAYER);

		m_fTimeAcc = 0.f;
	}
	m_fBreakTimeAcc += fTimeDelta;
	
	if (m_fBreakTimeAcc >= 5.f)
	{
		--m_iBreakCount;
		m_fBreakTimeAcc = 0.f;
		if(m_iBreakCount < 0)
			m_iBreakCount = 0;
	}

	if(m_eCurState != PLAYER_RECOIL && m_eCurState != PLAYER_RESPAWN)
		Key_Input(fTimeDelta);

	if(m_bWarpEffect)
		m_pWarpEffect->Update_GameObject(fTimeDelta);
	
	if(m_bIsClone)
		m_pCloneEffect->Update_GameObject(fTimeDelta);

	//if(m_pBreakEffect)
	//	m_pBreakEffect->Update_GameObject(fTimeDelta);

	if (m_bIsClone && nullptr != m_pClone)
	{
		m_pClone->Update_GameObject(fTimeDelta);
	}

	if (m_bIsTriger && !m_bIsClone)
	{
		m_pAim->Update_GameObject(fTimeDelta);
		Engine::CTransform* pAimTransform = dynamic_cast<Engine::CTransform*>(m_pAim->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
		_vec3 vPos = _vec3(*m_pTransformCom->Get_Info(Engine::INFO_POS) + m_vDir * 1.5f);
		pAimTransform->Set_Pos(&_vec3(m_pNaviCom->AimMove_OnNaviMesh(&m_vPos, &vPos)));
	}

	return NO_EVENT;
}

_int CPlayer::LateUpdate_GameObject(const _float & fTimeDelta)
{

	if (m_bIsColl)
	{
		m_pTransformCom->Move_Pos(&(-m_vDir * m_fSpeed * fTimeDelta));
		m_bIsColl = false;
	}
	if (m_bIsDead && m_eCurState != PLAYER_AFTER01 && !m_bIsWarp)
	{
		m_eCurState = PLAYER_RECOIL;
		m_pMeshCom->Set_AnimationSet(PLAYER_RECOIL);
	}
	if (PLAYER_RECOIL == m_eCurState && m_pMeshCom->Is_AnimationSetEnd())
	{
		m_eCurState = PLAYER_RESPAWN;
		m_pMeshCom->Set_AnimationSet(PLAYER_RESPAWN);
		m_pNaviCom->Warp_OnNaviMesh(m_pTransformCom->Get_Info(Engine::INFO_POS), &m_vCheckPos);
		m_pTransformCom->Set_Pos(&m_vCheckPos);
		m_bIsWarp = false;
		m_bIsInObj = false;
		m_bIsClone = false;

		if (m_pClone)
			::Safe_Release(m_pClone);
	}
	else if (PLAYER_RESPAWN == m_eCurState && m_pMeshCom->Is_AnimationSetEnd())
	{
		m_eCurState = PLAYER_IDLE;
		m_pMeshCom->Set_AnimationSet(PLAYER_IDLE);
	}

	Engine::CGameObject::Update_GameObject(fTimeDelta);

	m_bIsConveyor = false;
	m_bIsDead = false;

	m_pMeshCom->Play_Animation(fTimeDelta);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	return NO_EVENT;
}

void CPlayer::Render_GameObject(void)
{
	m_pMeshCom->Play_Animation(0);

	//m_pGraphicDev->SetTransform(D3DTS_WORLD, &m_pTransformCom->m_matWorld);

#ifdef _DEBUG
	//m_pNaviCom->Render_NaviMesh();

#endif

	_matrix		matWorld;
	m_pTransformCom->Get_WorldMatrix(&matWorld);

	m_pColiderSphereCom->Render_Collider(Engine::COL_FALSE, &matWorld);
	m_pColliderBoxCom->Render_Collider(Engine::COL_FALSE, &matWorld);

	if (m_bIsInObj && !m_bIsClone)
		return;

	LPD3DXEFFECT	pEffect = m_pShaderCom->Get_EffectHandle();
	NULL_CHECK(pEffect);
	pEffect->AddRef();

	_uint	iPassMax = 0;

	FAILED_CHECK_RETURN(SetUp_ConstantTable(pEffect), );

	pEffect->Begin(&iPassMax, 0);

	pEffect->BeginPass(0);

	if(m_bIsInObj && m_bIsClone)
		m_pCloneObjMeshCom->Render_Meshes();
	else
		m_pMeshCom->Render_Meshes();

	pEffect->EndPass();

	pEffect->End();

	Safe_Release(pEffect);
	
}

void CPlayer::Set_bIsColl(_bool bIsColl)
{
	m_bIsColl = bIsColl;
}

void CPlayer::Set_bIsConveyor(_bool bIsConveyor)
{
	m_bIsConveyor = bIsConveyor;
}

void CPlayer::Set_bIsObj(_bool bIsObj)
{
	m_bIsInObj = bIsObj;
}

void CPlayer::Set_Triger(_bool bIsTriger)
{
	m_bIsTriger = bIsTriger;
}


void CPlayer::Set_CheckPos(_vec3 vCheckPos)
{
	m_vCheckPos = vCheckPos;
}

void CPlayer::InputTile(_int iIndex)
{
	m_CheckTileVec.push_back(iIndex);
}

void CPlayer::Set_CloneMesh(Engine::CStaticMesh * pClone)
{
	if(nullptr != m_pCloneObjMeshCom)
		::Safe_Release(m_pCloneObjMeshCom);

	m_pCloneObjMeshCom = pClone;
}

void CPlayer::Set_bWarpEffect(_bool bWarpEffect)
{
	m_bWarpEffect = bWarpEffect;
}

HRESULT CPlayer::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	pComponent = m_pMeshCom = dynamic_cast<Engine::CDynamicMesh*>(Engine::Clone(RESOURCE_STAGE, L"Mesh_Player"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Mesh", pComponent);

	pComponent = m_pNaviCom = dynamic_cast<Engine::CNaviMesh*>(Engine::Clone(RESOURCE_STAGE, L"Mesh_Navi"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Navi", pComponent);

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

	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone_Prototype(L"Shader_Mesh"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);

	pComponent = m_pColiderSphereCom = Engine::CColliderSphere::Create(m_pGraphicDev,
		m_pTransformCom->Get_Info(Engine::INFO_POS), 30.f);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_ColliderSphere", pComponent);

	// collider
	pComponent = m_pColliderBoxCom = Engine::CColliderBox::Create(m_pGraphicDev, m_pTransformCom->Get_Info(Engine::INFO_POS), &_vec3(-30.f,-30.f,-30.f), &_vec3(30.f,30.f,50.f));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Collider", pComponent);

	return S_OK;
}

void CPlayer::Key_Input(const _float& fTimeDelta)
{
	m_pTransformCom->Get_Info(Engine::INFO_POS, &m_vPos);
	m_pTransformCom->Get_Info(Engine::INFO_LOOK, &m_vDir);
	D3DXVec3Normalize(&m_vDir, &m_vDir);

	m_vPos += _vec3(0.f, -9.8f * fTimeDelta, 0.f);
	if (m_vPos.y < 0.f)
		m_vPos.y = 0.f;

	if (Engine::KeyDown(DIK_X))
	{
		m_bIsDead = true;
	}
	
	if (!m_bIsWarp)
	{
		if (Engine::KeyPressing(DIK_UP))
		{
			m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(0.f));

			if (Engine::KeyPressing(DIK_LEFT))
				m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(315.f));
			else if (Engine::KeyPressing(DIK_RIGHT))
				m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(45.f));

			m_pTransformCom->Set_Pos(&(m_pNaviCom->Move_OnNaviMesh(&m_vPos, &(m_vDir * m_fSpeed * fTimeDelta))));
			m_pMeshCom->Set_AnimationSet(PLAYER_WALK);
			m_eCurState = PLAYER_WALK;
		}
		else if (Engine::KeyPressing(DIK_DOWN))
		{
			m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(180.f));

			if (Engine::KeyPressing(DIK_LEFT))
				m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(225.f));
			else if (Engine::KeyPressing(DIK_RIGHT))
				m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(135.f));

			m_pTransformCom->Set_Pos(&(m_pNaviCom->Move_OnNaviMesh(&m_vPos, &(m_vDir * m_fSpeed * fTimeDelta))));
			m_pMeshCom->Set_AnimationSet(PLAYER_WALK);
			m_eCurState = PLAYER_WALK;
		}
		else if (Engine::KeyPressing(DIK_LEFT))
		{
			m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(270.f));

			m_pTransformCom->Set_Pos(&(m_pNaviCom->Move_OnNaviMesh(&m_vPos, &(m_vDir * m_fSpeed * fTimeDelta))));
			m_pMeshCom->Set_AnimationSet(PLAYER_WALK);
			m_eCurState = PLAYER_WALK;
		}
		else if (Engine::KeyPressing(DIK_RIGHT))
		{
			m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(90.f));

			m_pTransformCom->Set_Pos(&(m_pNaviCom->Move_OnNaviMesh(&m_vPos, &(m_vDir * m_fSpeed * fTimeDelta))));
			m_pMeshCom->Set_AnimationSet(PLAYER_WALK);
			m_eCurState = PLAYER_WALK;
		}
		else
		{
			m_pMeshCom->Set_AnimationSet(PLAYER_IDLE);
			m_eCurState = PLAYER_IDLE;
		}

		if (Engine::KeyDown(DIK_C) && m_bIsTriger)
		{
			m_bIsWarp = true;
			m_bWarpEffect = true;
			m_pMeshCom->Set_AnimationSet(PLAYER_WARPEND);
			m_eCurState = PLAYER_WARPEND;

			dynamic_cast<Engine::CTransform*>(m_pWarpEffect->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(m_pTransformCom->Get_Info(Engine::INFO_POS)->x, 0.2f, m_pTransformCom->Get_Info(Engine::INFO_POS)->z);

			m_pTransformCom->Set_Pos(&m_pNaviCom->Warp_OnNaviMesh(&m_vPos, dynamic_cast<Engine::CTransform*>(m_pAim->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Get_Info(Engine::INFO_POS)));
			CSoundMgr::GetInstance()->PlaySound(L"Player_Warp.ogg", CSoundMgr::PLAYER);
			m_fTimeAcc = 0.f;
		}

		if (Engine::KeyDown(DIK_R))
		{
			m_bIsClone ^= true;
			dynamic_cast<Engine::CTransform*>(m_pCloneEffect->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(m_pTransformCom->Get_Info(Engine::INFO_POS)->x, 0.2f, m_pTransformCom->Get_Info(Engine::INFO_POS)->z);
			if (nullptr == m_pClone)
			{
				Engine::CTransform* pCloneTransform = nullptr;

				m_pClone = CClone::Create(m_pGraphicDev);
				pCloneTransform = dynamic_cast<Engine::CTransform*>(m_pClone->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
				pCloneTransform->Set_Pos(m_pTransformCom->Get_Info(Engine::INFO_POS));
				pCloneTransform->FixingRotation(Engine::ROT_X, m_pTransformCom->Get_Angle()->x);
				pCloneTransform->FixingRotation(Engine::ROT_Y, m_pTransformCom->Get_Angle()->y);
				pCloneTransform->FixingRotation(Engine::ROT_Z, m_pTransformCom->Get_Angle()->z);
				m_pTransformCom->Set_Pos(&(*m_pTransformCom->Get_Info(Engine::INFO_POS) + m_vDir));
				CSoundMgr::GetInstance()->PlaySound(L"Decoy_created.ogg", CSoundMgr::EFFECT);
			}
			else
			{
				m_pTransformCom->Set_Pos(dynamic_cast<Engine::CTransform*>(m_pClone->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Get_Info(Engine::INFO_POS));
				::Safe_Release(m_pClone);
				CSoundMgr::GetInstance()->PlaySound(L"Decoy_destroyed.ogg", CSoundMgr::EFFECT);
			}

		}
		//if (true == m_pMeshCom->Is_AnimationSetEnd())
		//	m_pMeshCom->Set_AnimationSet(PLAYER_IDLE);
	}
	else if (m_bIsInObj)
	{
		m_fTimeAcc = 0.f;
		//dynamic_cast<Engine::CTransform*>(m_pBreakEffect->Get_Component(L"Com_Transform",Engine::ID_DYNAMIC))->Set_Pos(m_pTransformCom->Get_Info(Engine::INFO_POS)->x, 0.5f, m_pTransformCom->Get_Info(Engine::INFO_POS)->z);
		if (!m_bIsClone)
		{
			if (Engine::KeyDown(DIK_UP))
			{
				m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(0.f));

				if (Engine::KeyDown(DIK_LEFT))
					m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(315.f));
				else if (Engine::KeyDown(DIK_RIGHT))
					m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(45.f));
				m_fBreakTimeAcc = 0.f;
				++m_iBreakCount;
			}
			else if (Engine::KeyDown(DIK_DOWN))
			{
				m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(180.f));

				if (Engine::KeyDown(DIK_LEFT))
					m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(225.f));
				else if (Engine::KeyDown(DIK_RIGHT))
					m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(135.f));
				m_fBreakTimeAcc = 0.f;
				++m_iBreakCount;
			}
			else if (Engine::KeyDown(DIK_LEFT))
			{
				m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(270.f));

				++m_iBreakCount;
			}
			else if (Engine::KeyDown(DIK_RIGHT))
			{
				m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(90.f));
				m_fBreakTimeAcc = 0.f;
				++m_iBreakCount;
			}

			if (Engine::KeyDown(DIK_C))
			{
				m_bIsWarp = true;
				m_bIsInObj = false;
				m_iBreakCount = 0;
				m_pMeshCom->Set_AnimationSet(PLAYER_WARPEND);
				m_eCurState = PLAYER_WARPEND;
				m_pTransformCom->Set_Pos(&m_pNaviCom->Warp_OnNaviMesh(&m_vPos, dynamic_cast<Engine::CTransform*>(m_pAim->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Get_Info(Engine::INFO_POS)));
				CSoundMgr::GetInstance()->PlaySound(L"Player_Warp.ogg", CSoundMgr::PLAYER);
			}

			if (Engine::KeyDown(DIK_F))
			{

				Engine::CTransform*			pObjectTransformCom = nullptr;
				Engine::CColliderSphere*	pObjColliderSphereCom = nullptr;
				CShiny*						pShiny = nullptr;

				auto iter_begin = Engine::Get_Layer(L"GameLogic")->Get_MapObject()->begin();
				auto iter_end = Engine::Get_Layer(L"GameLogic")->Get_MapObject()->end();

				for (; iter_begin != iter_end; ++iter_begin)
				{
					wstring temp = iter_begin->first;
					_int iSearch = temp.find(L"HatchShiny");

					if (iSearch >= 0)
					{
						pObjectTransformCom = dynamic_cast<Engine::CTransform*>(iter_begin->second->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
						pObjColliderSphereCom = dynamic_cast<Engine::CColliderSphere*>(iter_begin->second->Get_Component(L"Com_ColliderSphere", Engine::ID_STATIC));

						if (m_pCalculatorCom->Coliision_Sphere(pObjectTransformCom->Get_Info(Engine::INFO_POS), pObjColliderSphereCom->Get_Radius(),
							m_pTransformCom->Get_Info(Engine::INFO_POS), m_pColiderSphereCom->Get_Radius()))
						{
							pShiny = dynamic_cast<CShiny*>(iter_begin->second);
							pShiny->Set_Lerp(true);
							pShiny->Set_EndPos(_vec3(*pObjectTransformCom->Get_Info(Engine::INFO_POS) + m_vDir * 1.5f));
						}
					}
				}
				m_bIsWarp = false;
				m_bIsInObj = false;
				m_pMeshCom->Set_AnimationSet(PLAYER_LAUNCH);
				m_eCurState = PLAYER_LAUNCH;
				m_pTransformCom->Move_Pos(&-m_vDir);
				CSoundMgr::GetInstance()->PlaySound(L"Launch_object_Variation1.ogg",CSoundMgr::EFFECT);
			}

			if (Engine::KeyDown(DIK_R))
			{
				m_bIsClone = true;
				dynamic_cast<Engine::CTransform*>(m_pCloneEffect->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(m_pTransformCom->Get_Info(Engine::INFO_POS)->x, 0.2f, m_pTransformCom->Get_Info(Engine::INFO_POS)->z);
				vPastPos = *m_pTransformCom->Get_Info(Engine::INFO_POS);
				m_pTransformCom->Set_Pos(&(*m_pTransformCom->Get_Info(Engine::INFO_POS) + m_vDir));
				CSoundMgr::GetInstance()->PlaySound(L"Decoy_created.ogg", CSoundMgr::EFFECT);
			}
		}
		else if (m_bIsClone)
		{
			if (Engine::KeyPressing(DIK_UP))
			{
				m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(0.f));

				if (Engine::KeyPressing(DIK_LEFT))
					m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(315.f));
				else if (Engine::KeyPressing(DIK_RIGHT))
					m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(45.f));

				m_pTransformCom->Set_Pos(&(m_pNaviCom->Move_OnNaviMesh(&m_vPos, &(m_vDir * m_fSpeed * fTimeDelta))));
			}
			else if (Engine::KeyPressing(DIK_DOWN))
			{
				m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(180.f));

				if (Engine::KeyPressing(DIK_LEFT))
					m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(225.f));
				else if (Engine::KeyPressing(DIK_RIGHT))
					m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(135.f));

				m_pTransformCom->Set_Pos(&(m_pNaviCom->Move_OnNaviMesh(&m_vPos, &(m_vDir * m_fSpeed * fTimeDelta))));
			}
			else if (Engine::KeyPressing(DIK_LEFT))
			{
				m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(270.f));

				m_pTransformCom->Set_Pos(&(m_pNaviCom->Move_OnNaviMesh(&m_vPos, &(m_vDir * m_fSpeed * fTimeDelta))));
			}
			else if (Engine::KeyPressing(DIK_RIGHT))
			{
				m_pTransformCom->FixingRotation(Engine::ROT_Y, D3DXToRadian(90.f));

				m_pTransformCom->Set_Pos(&(m_pNaviCom->Move_OnNaviMesh(&m_vPos, &(m_vDir * m_fSpeed * fTimeDelta))));
			}

			if (Engine::KeyDown(DIK_R))
			{
				m_bIsClone = false;
				m_pTransformCom->Set_Pos(&vPastPos);
				CSoundMgr::GetInstance()->PlaySound(L"Decoy_destroyed.ogg",CSoundMgr::EFFECT);
			}
		}



	}
	else
	{
		if (!m_bIsInObj)
		{
			if (PLAYER_WARPFALL == m_eCurState)
			{
				if (true == m_pMeshCom->Is_AnimationSetEnd())
				{
					m_pMeshCom->Set_AnimationSet(PLAYER_WARPEND);
					m_eCurState = PLAYER_WARPEND;
				}
			}
			else if (PLAYER_WARPEND == m_eCurState)
			{
				if (true == m_pMeshCom->Is_AnimationSetEnd())
				{
					m_pMeshCom->Set_AnimationSet(PLAYER_IDLE);
					m_eCurState = PLAYER_IDLE;
					m_bIsWarp = false;
				}
			}
			else if (PLAYER_LAUNCH == m_eCurState)
			{
				if (true == m_pMeshCom->Is_AnimationSetEnd())
				{
					m_pMeshCom->Set_AnimationSet(PLAYER_IDLE);
					m_eCurState = PLAYER_IDLE;
				}
			}
		}
	}
	
	if (10 <= m_iBreakCount)
	{
		if (m_eCurState == PLAYER_AFTER01)
		{	
			if (true == m_pMeshCom->Is_AnimationSetEnd())
			{
				m_pMeshCom->Set_AnimationSet(PLAYER_IDLE);
				m_eCurState = PLAYER_IDLE;
				m_iBreakCount = 0;
				m_bIsWarp = false;
				m_bIsBreak = false;
			}
		}
		else
		{
			m_bIsBreak = true;
			m_pMeshCom->Set_AnimationSet(PLAYER_AFTER01);
			m_eCurState = PLAYER_AFTER01;
		}
	}
	//m_pBreakEffect->Set_Scale(m_iBreakCount);
}

HRESULT CPlayer::SetUp_ConstantTable(LPD3DXEFFECT & pEffect)
{
	_matrix			matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);
	pEffect->SetVector("g_vCamPos", (_vec4*)&matView.m[3][0]);

	return S_OK;
}


CPlayer* CPlayer::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CPlayer*	pInstance = new CPlayer(pGraphicDev);

	if (FAILED(pInstance->Ready_GameObject()))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CPlayer::Free(void)
{
	//Engine::Safe_Release(m_pBreakEffect);
	Engine::Safe_Release(m_pCloneObjMeshCom);
	Engine::Safe_Release(m_pCloneEffect);
	Engine::Safe_Release(m_pWarpEffect);
	Engine::Safe_Release(m_pAim);
	Engine::CGameObject::Free();
}


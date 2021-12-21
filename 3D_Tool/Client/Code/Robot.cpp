#include "stdafx.h"
#include "Robot.h"

#include "Player.h"
#include "DynamicMesh.h"
#include "Aim.h"
#include "Explosion.h"
#include "SoundMgr.h"

#include "Export_Function.h"

CRobot::CRobot(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CRobot::~CRobot(void)
{

}

HRESULT CRobot::Ready_GameObject(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	
	m_eCurState = ROBOT_SEACH;
	m_pMeshCom->Set_AnimationSet(ROBOT_SEACH);

	m_pTransformCom->Set_Scale(0.01f, 0.01f, 0.01f);

	return S_OK;
}

_int CRobot::Update_GameObject(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_GameObject(fTimeDelta);

		

	return NO_EVENT;
}

_int CRobot::LateUpdate_GameObject(const _float & fTimeDelta)
{
	if (m_eCurState == ROBOT_SHOT && m_pMeshCom->Is_AnimationSetEnd())
	{
		m_eCurState = ROBOT_SEACH;
		m_pMeshCom->Set_AnimationSet(ROBOT_SEACH);
	}

	m_bColl = Collision_ToObject(L"GameLogic", L"Player");
	if (m_eCurState == ROBOT_SEACH)
	{
		m_fAngle += m_fSpeed;

		if (m_fAngle > 45 || m_fAngle < -45)
			m_fSpeed *= -1;

		m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(m_fSpeed));
	}

	m_pMeshCom->Play_Animation(fTimeDelta);

	if (m_bColl)
		dynamic_cast<CPlayer*>(Engine::Get_GameObj(L"GameLogic", L"Player"))->Set_bIsColl(true);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	if (m_bIsDead)
	{
		CSoundMgr::GetInstance()->PlaySound(L"Explosive_barrel_clic.ogg", CSoundMgr::EFFECT);
		return DEAD_OBJ;
	}
		

	return NO_EVENT;
}

void CRobot::Render_GameObject(void)
{

	_matrix		matWorld;
	m_pTransformCom->Get_WorldMatrix(&matWorld);

	m_pColliderBoxCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);
	m_pColiderSphereCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);
	
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

void CRobot::Set_Count(_int iCount)
{
	m_iCount = iCount;
}

void CRobot::Set_State(ROBOTSTATE eState)
{
	m_eCurState = eState;
	m_pMeshCom->Set_AnimationSet(eState);
}

HRESULT CRobot::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	pComponent = m_pMeshCom = Engine::CDynamicMesh::Create(m_pGraphicDev, L"../Bin/Resource/Warp/Mesh/DynamicMesh/Robot/", L"Robot.x");
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

	pComponent = m_pColiderSphereCom = Engine::CColliderSphere::Create(m_pGraphicDev,
		m_pTransformCom->Get_Info(Engine::INFO_POS), 50.f);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_ColliderSphere", pComponent);

	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone_Prototype(L"Shader_Mesh"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);

	return S_OK;
}

_bool CRobot::Collision_ToObject(const _tchar * pLayerTag, const _tchar * pObjTag)
{
	Engine::CColliderBox*	pPlayerColliderCom = dynamic_cast<Engine::CColliderBox*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Collider", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderCom, false);

	Engine::CTransform*			pPlayerTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pPlayerTransformCom, false);

	Engine::CColliderSphere*	pPlayerColliderSphereCom = dynamic_cast<Engine::CColliderSphere*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_ColliderSphere", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderSphereCom, false);

	CPlayer*	pPlayer = dynamic_cast<CPlayer*>(Engine::Get_GameObj(L"GameLogic", L"Player"));

	Engine::CTransform*			pAimTransformCom = dynamic_cast<Engine::CTransform*>(pPlayer->GetAim()->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC));
	Engine::CColliderSphere*	pAimColliderSphereCom = dynamic_cast<Engine::CColliderSphere*>(pPlayer->GetAim()->Get_Component(L"Com_ColliderSphere", Engine::ID_STATIC));

	if (m_pCalculatorCom->Coliision_Sphere(pAimTransformCom->Get_Info(Engine::INFO_POS),
		pAimColliderSphereCom->Get_Radius(),
		m_pTransformCom->Get_Info(Engine::INFO_POS),
		m_pColiderSphereCom->Get_Radius()))
	{
		dynamic_cast<Engine::CTransform*>(pPlayer->GetAim()->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(m_pTransformCom->Get_Info(Engine::INFO_POS));
	}

	if (m_pCalculatorCom->Coliision_Sphere(pPlayerTransformCom->Get_Info(Engine::INFO_POS),
		pPlayerColliderSphereCom->Get_Radius(),
		m_pTransformCom->Get_Info(Engine::INFO_POS),
		m_pColiderSphereCom->Get_Radius()))
	{
		if (pPlayer->GetbIsBreak())
		{
			pPlayer->Set_bIsObj(false);
			wstring szTag = L"Robotgun_" + to_wstring(m_iCount);
			Engine::CGameObject* pTemp = Engine::Get_GameObj(L"GameLogic", szTag.c_str());
			pTemp->IsDead();

			CExplosion* pExplosion = CExplosion::Create(m_pGraphicDev);
			dynamic_cast<Engine::CTransform*>(pExplosion->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(m_pTransformCom->Get_Info(Engine::INFO_POS));
			Engine::Get_Layer(L"GameLogic")->Add_GameObject(L"Explosion", pExplosion);

			m_bIsDead = true;
			return false;
		}


		if (pPlayer->GetbIsWarp())
		{
			pPlayer->Set_bIsObj(true);
			dynamic_cast<Engine::CTransform*>(pPlayer->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->Set_Pos(m_pTransformCom->Get_Info(Engine::INFO_POS));
			return false;
		}

		pPlayer->Set_bIsObj(false);
		return m_pCalculatorCom->Collision_OBB(pPlayerColliderCom->Get_Min(),
			pPlayerColliderCom->Get_Max(),
			pPlayerColliderCom->Get_ColliderBoxMatrix(),
			m_pColliderBoxCom->Get_Min(),
			m_pColliderBoxCom->Get_Max(),
			m_pColliderBoxCom->Get_ColliderBoxMatrix());

	}

	return false;
}

CRobot* CRobot::Create(LPDIRECT3DDEVICE9 pGraphicDev, wstring ObjTag)
{
	CRobot*	pInstance = new CRobot(pGraphicDev);

	memcpy(pInstance->m_ObjTag, ObjTag.c_str(), (ObjTag.length() + 1) * sizeof(_tchar));

	if (FAILED(pInstance->Ready_GameObject()))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CRobot::Free(void)
{


	Engine::CGameObject::Free();
}


HRESULT CRobot::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
{
	_matrix			matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);

	//const D3DLIGHT9*		pLight = Engine::Get_LightInfo(0);
	//NULL_CHECK_RETURN(pLight, S_OK);


	//pEffect->SetVector("g_vLightDir", &_vec4(pLight->Direction, 0.f));
	//pEffect->SetVector("g_vLightDiffuse", (_vec4*)&pLight->Diffuse);
	//pEffect->SetVector("g_vLightSpecular", (_vec4*)&pLight->Specular);
	//pEffect->SetVector("g_vLightAmbient", (_vec4*)&pLight->Ambient);


	//D3DMATERIAL9		tMtrlInfo;
	//ZeroMemory(&tMtrlInfo, sizeof(D3DMATERIAL9));

	//tMtrlInfo.Diffuse = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	//tMtrlInfo.Specular = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	//tMtrlInfo.Ambient = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	//tMtrlInfo.Emissive = D3DXCOLOR(0.f, 0.f, 0.f, 1.f);
	//tMtrlInfo.Power = 100.f;

	//pEffect->SetVector("g_vMtrlDiffuse", (_vec4*)&tMtrlInfo.Diffuse);
	//pEffect->SetVector("g_vMtrlSpecular", (_vec4*)&tMtrlInfo.Specular);
	//pEffect->SetVector("g_vMtrlAmbient", (_vec4*)&tMtrlInfo.Ambient);

	//_vec4		vCamPos;
	//D3DXMatrixInverse(&matView, NULL, &matView);
	//memcpy(&vCamPos, &matView.m[3][0], sizeof(_vec4));

	//pEffect->SetVector("g_vCamPos", &vCamPos);
	//pEffect->SetFloat("g_fPower", tMtrlInfo.Power);

	return S_OK;
}

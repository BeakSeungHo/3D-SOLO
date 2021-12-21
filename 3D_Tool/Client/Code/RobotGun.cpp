#include "stdafx.h"
#include "RobotGun.h"

#include "Export_Function.h"

CRobotGun::CRobotGun(LPDIRECT3DDEVICE9 pGraphicDev)
	: CStaticMeshObj(pGraphicDev)
{

}

CRobotGun::~CRobotGun(void)
{

}

HRESULT CRobotGun::Ready_GameObject(const _uint& iFlag)
{
	CStaticMeshObj::Ready_GameObject(iFlag);

	m_pTransformCom->Set_Scale(1.f,1.f,1.f);

	return S_OK;
}

_int CRobotGun::Update_GameObject(const _float& fTimeDelta)
{
	if (nullptr == m_pParentBoneMatrix)
	{
		wstring szTag = L"Robot_" + to_wstring(m_iCount);

		Engine::CDynamicMesh*	pRobotMeshCom = dynamic_cast<Engine::CDynamicMesh*>(Engine::Get_Component(L"GameLogic", szTag.c_str(), L"Com_Mesh", Engine::ID_STATIC));
		NULL_CHECK_RETURN(pRobotMeshCom, 0);

		const Engine::D3DXFRAME_DERIVED* pBone = pRobotMeshCom->Get_FrameByName("b_Bot_RightAttachement");
		NULL_CHECK_RETURN(pBone, 0);

		m_pParentBoneMatrix = &pBone->CombinedTransformationMatrix;

		Engine::CTransform*	pRobotTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", szTag.c_str(), L"Com_Transform", Engine::ID_DYNAMIC));
		NULL_CHECK_RETURN(pRobotTransCom, 0);

		m_pParentWorldMatrix = pRobotTransCom->Get_WorldMatrixPointer();
	}

	Engine::CGameObject::Update_GameObject(fTimeDelta);

	m_pTransformCom->Set_ParentMatrix(&(*m_pParentBoneMatrix * *m_pParentWorldMatrix));
	//m_pTransformCom->m_matWorld.m[3][0] -= 0.2f;
	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	if (m_bIsDead)
	{
		wstring szTag = L"RobotLaser_" + to_wstring(m_iCount);
		Engine::CGameObject* pTemp = Engine::Get_GameObj(L"GameLogic", szTag.c_str());
		pTemp->IsDead();

		return DEAD_OBJ;
	}
		

	return NO_EVENT;
}

void CRobotGun::Render_GameObject(void)
{
	CStaticMeshObj::Render_GameObject();
}

void CRobotGun::Set_Count(_int iCount)
{
	m_iCount = iCount;
}

HRESULT CRobotGun::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	return S_OK;
}

CRobotGun* CRobotGun::Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iFlag, wstring MesgTag , wstring ObjTag)
{
	CRobotGun*	pInstance = new CRobotGun(pGraphicDev);

	memcpy(pInstance->m_ObjTag, ObjTag.c_str(), (ObjTag.length() + 1) * sizeof(_tchar));
	memcpy(pInstance->m_MeshTag, MesgTag.c_str(), (MesgTag.length() + 1) * sizeof(_tchar));

	if (FAILED(pInstance->Ready_GameObject(iFlag)))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CRobotGun::Free(void)
{
	Engine::CGameObject::Free();
}



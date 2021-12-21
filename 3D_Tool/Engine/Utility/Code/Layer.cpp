#include "Layer.h"

USING(Engine)

Engine::CLayer::CLayer(void)
{

}

Engine::CLayer::~CLayer(void)
{

}

HRESULT Engine::CLayer::Ready_Layer(void)
{
	return S_OK;
}

_int Engine::CLayer::Update_Layer(const _float& fTimeDelta)
{
	_int iExit = 0;

	auto iter_begin = m_mapObject.begin();
	auto iter_end = m_mapObject.end();

	for (; iter_begin != iter_end; ++iter_begin)
	{
		iExit = iter_begin->second->Update_GameObject(fTimeDelta);

		if (DEAD_OBJ == iExit)
		{
			Safe_Release((iter_begin->second));
			iter_begin = m_mapObject.erase(iter_begin);
		}
		else if(CHANGE_SCENE == iExit)
			break;
	}

	return iExit;
}

_int CLayer::LateUpdate_Layer(const _float & fTimeDelta)
{
	_int iExit = 0;

	auto iter_begin = m_mapObject.begin();
	auto iter_end = m_mapObject.end();

	for (; iter_begin != iter_end; ++iter_begin)
	{
		iExit = iter_begin->second->LateUpdate_GameObject(fTimeDelta);

		if (DEAD_OBJ == iExit)
		{
			Safe_Release((iter_begin->second));
			iter_begin = m_mapObject.erase(iter_begin);
		}
		else if (CHANGE_SCENE == iExit)
			break;
	}

	return iExit;
}

//void Engine::CLayer::Render_Layer(void)
//{
//
//}

HRESULT Engine::CLayer::Add_GameObject(const _tchar* pObjTag, CGameObject* pGameObject)
{
	if (nullptr == pGameObject)
		return E_FAIL;

	m_mapObject.emplace(pObjTag, pGameObject);

	return S_OK;
}

void CLayer::Reset_Object()
{
	for_each(m_mapObject.begin(), m_mapObject.end(), CDeleteMap());

	m_mapObject.clear();
}

Engine::CLayer* Engine::CLayer::Create(void)
{
	CLayer*		pInstance = new CLayer;

	if (FAILED(pInstance->Ready_Layer()))
		Safe_Release(pInstance);

	return pInstance;
}

void Engine::CLayer::Free(void)
{
	for_each(m_mapObject.begin(), m_mapObject.end(), CDeleteMap());
		
	m_mapObject.clear();
}

Engine::CComponent* Engine::CLayer::Get_Component(const _tchar* pObjTag, const _tchar* pComponentTag, COMPONENTID eID)
{
	auto	iter = find_if(m_mapObject.begin(), m_mapObject.end(), CTag_Finder(pObjTag));

	if (iter == m_mapObject.end())
		return nullptr;

	return iter->second->Get_Component(pComponentTag, eID);
}

CGameObject * CLayer::Get_GameObj(const _tchar * pObjTag)
{
	auto	iter = find_if(m_mapObject.begin(), m_mapObject.end(), CTag_Finder(pObjTag));

	if (iter == m_mapObject.end())
		return nullptr;

	return iter->second;
}


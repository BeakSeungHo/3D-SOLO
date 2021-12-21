#ifndef Stage_h__
#define Stage_h__

#include "Defines.h"
#include "Scene.h"

#include "Terrain.h"
#include "Player.h"
#include "StaticCamera.h"
#include "DynamicCamera.h"
#include "NaviMesh.h"


class CStage : public Engine::CScene
{
private:
	explicit CStage(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CStage(void);


public:
	virtual HRESULT Ready_Scene(void) override;
	virtual _int Update_Scene(const _float& fTimeDelta) override;
	virtual _int LateUpdate_Scene(const _float& fTimeDelta) override;
	virtual void Render_Scene(void) override;

private:
	HRESULT		Ready_Environment_Layer(const _tchar* pLayerTag) { return S_OK; }
	HRESULT		Ready_GameLogic_Layer(const _tchar* pLayerTag);
	HRESULT		Ready_UI_Layer(const _tchar* pLayerTag);
	HRESULT		Ready_LightInfo(void);
	HRESULT		Ready_Prototype(void);
	void		Load_TerrainData(void);
	void		Load_MeshData(void);

	void		BlinkTilePattern(void);
	_bool		PatternPass();

	void		MoveCamera();
	void		MazeMove();

private:
	_matrix						m_matView, m_matProj;
	_ulong						m_dwRenderCnt = 0;
	_tchar						m_szFPS[256];
	_float						m_fTime = 0.f;
	_float						m_fTimeAcc = 0.f;
	_bool						m_bClear = false;
	_bool						m_bMaze = false;
	_float						m_fMazeTime = 0.f;

	Engine::CNaviMesh*				m_pNaviCom = nullptr;

	_int				m_TerrainCount = 0;

	_int				m_iPatternCount = 0;
	_uint				m_uPreIndex = 0;
	_uint				m_uNextIndex = 0;


	wstring				m_TagString[10];
	_tchar				m_Tag[128];
	wstring				BufferTag[10];


	_tchar		m_StaticTag[128] = {};
	_tchar		m_DynamicTag[128] = {};
	_tchar		m_MeshTag[128] = {};
	_tchar		m_szTag[128] = {};
	_tchar		m_szFilepath[128] = {};
	_tchar		m_szName[128] = {};

	map<_int,vector<_int>>	m_mapBlinkIndex;

public:
	static CStage*		Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;
};


#endif // Stage_h__

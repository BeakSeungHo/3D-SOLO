#include "stdafx.h"
#include "Loading.h"

#include "Export_Function.h"

CLoading::CLoading(LPDIRECT3DDEVICE9 pGraphicDev)
	: m_pGraphicDev(pGraphicDev)
	, m_bFinish(false)
{
	ZeroMemory(m_szLoading, sizeof(_tchar) * 256);
	m_pGraphicDev->AddRef();
}

CLoading::~CLoading(void)
{

}

_uint	CALLBACK CLoading::Thread_Main(void* pArg)
{
	CLoading*		pLoading = (CLoading*)pArg;

	_uint iFlag = 0;

	EnterCriticalSection(pLoading->Get_Crt());

	switch (pLoading->Get_LoadingID())
	{
	case LOADING_STAGE:
		iFlag = pLoading->Loading_ForStage();		
		break;

	case LOADING_BOSS:
		break;
	}
	
	LeaveCriticalSection(pLoading->Get_Crt());
	_endthreadex(0);

	return iFlag;
}

HRESULT CLoading::Ready_Loading(LOADINGID eLoading)
{
	InitializeCriticalSection(&m_Crt);

	m_hThread = (HANDLE)_beginthreadex(NULL, 0, Thread_Main, this, 0, NULL);

	m_eLoading = eLoading;

	return S_OK;
}

_uint CLoading::Loading_ForStage(void)
{
	lstrcpy(m_szLoading, L"Buffer Loading.............................");
	
	lstrcpy(m_szLoading, L"Texture Loading.............................");
	
	// ÅØ½ºÃÄ

	Engine::Ready_Texture(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Texture_Terrain",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/Terrain/Terrain_%d.jpg", 6);

	Engine::Ready_Texture(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Texture_Aim",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/Player/T_Circle_Aim_DA_%d.tga",2);

	Engine::Ready_Texture(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Texture_Laser",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/Effect/Laser/GlowLaser.tga");
	
	Engine::Ready_Texture(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Texture_WarpEffect",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/Effect/WARPSTART2/WARPSTART_%d.tga", 16);

	Engine::Ready_Texture(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Texture_Explosion",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/Effect/Explosion/Explosion_R_%d.tga", 16);
	
	Engine::Ready_Texture(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Texture_OrangePortal",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/Effect/Portal/OrangePortal/OrangePortal_%d.png", 32);

	Engine::Ready_Texture(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Texture_BluePortal",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/Effect/Portal/BluePortal/BluePortal_%d.png", 68);

	Engine::Ready_Texture(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Texture_CheckPoint",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/Effect/CheckPoint/CheckPointEffect.tga");

	Engine::Ready_Texture(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Texture_LaunchEffect",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/Effect/Trail_0.tga");

	Engine::Ready_Texture(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Texture_WaveEffect",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/Effect/HeatWave_0.tga");

	Engine::Ready_Texture(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Texture_BreakEffect",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Warp/Texture/Effect/Smoke/PuffSmoke2.tga");

	//Engine::Ready_Texture(m_pGraphicDev,
	//	RESOURCE_STAGE,
	//	L"Texture_CheckPointFont",
	//	Engine::TEX_NORMAL,
	//	L"../Bin/Resource/Warp/Texture/Effect/CheckPoint/CheckPointFont.tga");


	lstrcpy(m_szLoading, L"Mesh Loading.............................");


	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Robot",
		Engine::TYPE_DYNAMIC,
		L"../Bin/Resource/Warp/Mesh/DynamicMesh/Robot/",
		L"Robot.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_inswd_1x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/EventObject/",
		L"wall_inswd_1x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_inswd_6x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/EventObject/",
		L"wall_inswd_6x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_inswd_15x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/EventObject/",
		L"wall_inswd_15x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_inswd_corner_1x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/EventObject/",
		L"wall_inswd_corner_1x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_inswd_doorframe_4x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/EventObject/",
		L"wall_inswd_doorframe_4x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_inswd_doorLeft_1x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/EventObject/",
		L"wall_inswd_doorLeft_1x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_inswd_doorRight_1x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/EventObject/",
		L"wall_inswd_doorRight_1x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Skeleton_Ball",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/EventObject/",
		L"Skeleton_Ball.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"sm_floorswitch128",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/EventObject/",
		L"sm_floorswitch128.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"ObjectHatch",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/EventObject/",
		L"ObjectHatch.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"ObjectHatchPlatform",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/EventObject/",
		L"ObjectHatchPlatform.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"checkpoint_machine",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/EventObject/",
		L"checkpoint_machine.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Lift",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/EventObject/",
		L"Lift.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"DoorDouble_Lower_4x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/EventObject/",
		L"DoorDouble_Lower_4x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"DoorDoubleFrame_Upper_4x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/EventObject/",
		L"DoorDoubleFrame_Upper_4x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Boggy",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"Boggy.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"CardBoardBox_A",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"CardBoardBox_A.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"CardBoardBox_A1",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"CardBoardBox_A1.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"CardBoardBox_A2",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"CardBoardBox_A2.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"CardBoardBox_B1",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"CardBoardBox_B1.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"CardBoardBox_B2",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"CardBoardBox_B2.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Garbagebag",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"Garbagebag.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Garbagebin",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"Garbagebin.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Handrail",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"Handrail.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Handrail_corner_1x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"Handrail_corner_1x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Handrail_2x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"Handrail_2x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Handrail_3x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"Handrail_3x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"sm_fan",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"sm_fan.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"sm_pushcart",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"sm_pushcart.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Stool",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"Stool.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"AutopsyBed_regular",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"AutopsyBed_regular.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Computer_4_2x1x3",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"Computer_4_2x1x3.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"ComputeSmall_1_2x1x2",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"ComputeSmall_1_2x1x2.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"ComputeSmall_2_2x1x2",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"ComputeSmall_2_2x1x2.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Concrete_Slab",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DecoObject/",
		L"Concrete_Slab.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"cnt_labyrinth_1x1y05z",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"cnt_labyrinth_1x1y05z.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"cnt_labyrinthWall_1x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"cnt_labyrinthWall_1x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"conveyor1x1",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"conveyor1x1.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"conveyor1x4",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"conveyor1x4.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"conveyorcorner1x1",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"conveyorcorner1x1.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"conveyorcorner1x1reverse",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"conveyorcorner1x1reverse.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"MazeWall_3x1",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"MazeWall_3x1.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"MazeWall_4x1",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"MazeWall_4x1.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"MazeWall_5x1",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"MazeWall_5x1.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"sm_warp_piedestal_colomn",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"sm_warp_piedestal_colomn.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_Int_column_1x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"wall_Int_column_1x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_Int_corner_1x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"wall_Int_corner_1x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_Int_corner_2x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"wall_Int_corner_2x.x"),
		E_FAIL);
		
	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Wall_int_DoorFrame_4x1x3",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"Wall_int_DoorFrame_4x1x3.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_Int_End_1x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"wall_Int_End_1x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_Int_straight_1x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"wall_Int_straight_1x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_Int_straight_2x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"wall_Int_straight_2x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_Int_straight_4x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"wall_Int_straight_4x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_Int_straight_4x2y_BunkBeds",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"wall_Int_straight_4x2y_BunkBeds.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_Int_straight_05x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"wall_Int_straight_05x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_Int_Tshape_1x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"wall_Int_Tshape_1x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_int_Xshape_1x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"wall_int_Xshape_1x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Table_basic_2x1y",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"Table_basic_2x1y.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"table_basichalf_2x1y",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"table_basichalf_2x1y.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Table_corner_1x1y",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"Table_corner_1x1y.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"table_doors_1x1y",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"table_doors_1x1y.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"table_doors_2x1y",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"table_doors_2x1y.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"table_bigdrawers_2x1y",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"table_bigdrawers_2x1y.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"sm_cabaret",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"sm_cabaret.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"st_airpipe_FanGrid",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"st_airpipe_FanGrid.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"st_airpipe_x1",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"st_airpipe_x1.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"st_airpipe_corner_3x",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"st_airpipe_corner_3x.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_Int_straight_2x2y",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/Map/",
		L"wall_Int_straight_2x2y.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_ext_window_4x_CNT",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/PlayerObject/",
		L"wall_ext_window_4x_CNT.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_ext_window_6_CNT",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/PlayerObject/",
		L"wall_ext_window_6_CNT.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"wall_ext_window_cornerOUT_4x_CNT",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/PlayerObject/",
		L"wall_ext_window_cornerOUT_4x_CNT.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"sm_powercell",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/PlayerObject/",
		L"sm_powercell.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"DYN_Generator_Base",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/PlayerObject/",
		L"DYN_Generator_Base.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Laser_Fixed",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/PlayerObject/",
		L"Laser_Fixed.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Wall_int_column_1x_b",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/PlayerObject/",
		L"Wall_int_column_1x_b.x"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Robotgun",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/RobotGun/",
		L"Robotgun.x"),
		E_FAIL);

	Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"HeavyMetal_Barrel",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DestroyObject/",
		L"HeavyMetal_Barrel.X");

	Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Shiny_Barrel",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/DestroyObject/",
		L"Shiny_Barrel.X");

	Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Colum_Broken",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Warp/Mesh/StaticMesh/PlayerObject/",
		L"Column_1x1_broken.X");

	Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Boss",
		Engine::TYPE_DYNAMIC,
		L"../Bin/Resource/Warp/Mesh/DynamicMesh/Boss/",
		L"Boss_AType.X");

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		RESOURCE_STAGE,
		L"Mesh_Navi",
		Engine::TYPE_NAVI,
		NULL,
		NULL),
		E_FAIL);

	
	lstrcpy(m_szLoading, L"Loading Complete!!!");

	m_bFinish = true;


	return 0;
}

CLoading* CLoading::Create(LPDIRECT3DDEVICE9 pGraphicDev, LOADINGID eLoading)
{
	CLoading*	pInstance = new CLoading(pGraphicDev);

	if (FAILED(pInstance->Ready_Loading(eLoading)))
		Safe_Release(pInstance);

	return pInstance;

}

void CLoading::Free(void)
{
	WaitForSingleObject(m_hThread, INFINITE);
	CloseHandle(m_hThread);
	DeleteCriticalSection(&m_Crt);

	Engine::Safe_Release(m_pGraphicDev);
}


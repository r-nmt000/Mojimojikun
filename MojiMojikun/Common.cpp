#include "Common.h"
#include "GamePlay.h"
#include "NomoTex.h"
#include <iostream>
#include <stdexcept>
#include <XnCppWrapper.h>
#include <XnVSessionManager.h>
#include <XnVWaveDetector.h>

//*********************************************************

//　　　　　　　　　グローバル変数

//*********************************************************

//__________________________________
//				色々
//__________________________________

float g_fColor[][3] =
{
	{1,0,0},	// Red
	{0,1,0},	// Green
	{0,0.5,1},	// Light blue
	{1,1,0},	// Yellow
	{1,0.5,0},	// Orange
	{1,0,1},	// Purple
	{1,1,1},	// White
	{0,0,0}		// Black
};

int g_Count = 0;
//__________________________________
//				Main.cpp
//__________________________________

// OpenNI オブジェクト
xn::Context g_Context;
xn::DepthGenerator g_DepthGenerator;
xn::HandsGenerator g_HandsGenerator;

// NITE オブジェクト
XnVSessionManager* g_pSessionManager;
XnVFlowRouter* g_pFlowRouter;

// デプスマップの表示・非表示フラグ
XnBool g_bDrawDepthMap = true;
XnBool g_bPrintFrameID = false;
// スムージングの有無フラグ
XnFloat g_fSmoothing = 0.0f;
XnBool g_bPause = false;
XnBool g_bQuit = false;

//セッションの状態
SessionState g_SessionState = NOT_IN_SESSION;
//__________________________________
//			PointDrawer.cpp
//__________________________________

// 手をトラッキングするオブジェクト
MenuIcon*		g_pMenuIcon;
XnVPointDrawer* g_pDrawer;
//ポインタのテクスチャ
NomoTex* g_pPointTexture;
//タイトルのテクスチャ
NomoTex* g_pTitleTexture;
//Historyのサイズ（3D表示）
int g_3DHisBufSize = 30;

//__________________________________
//			MenuItem.cpp
//__________________________________

// メニューアイコンのオブジェクト
MenuItem* g_pMI_Start;
MenuItem* g_pMI_Level;
MenuItem* g_pMI_PlayNum;
MenuItem* g_pMI_Instruction;
MenuItem* g_pMI_Calibration;
MenuItem* g_pMI_Miss;
MenuItem* g_pMI_OK;
//レベルセレクト画面
MenuItem* g_pMI_Level_Hard;
MenuItem* g_pMI_Level_Normal;
MenuItem* g_pMI_Level_Easy;
//プレイヤ数選択がめん
MenuItem* g_pMI_PlayNum_One;
MenuItem* g_pMI_PlayNum_Two;
//終了
MenuItem* g_pMI_Exit;
//メニューアイテムが選択されたかどうか
BOOL g_SelectFlg = FALSE;
//メニューアイテムが移動状態か
BOOL g_MoveModeFlg1 = FALSE;
BOOL g_MoveModeFlg2 = FALSE;
//OpenNI関連
XnCallbackHandle g_UserCallbacks; 
XnCallbackHandle g_CalibrationCallbacks;
XnCallbackHandle g_PoseCallbacks;
xn::PoseDetectionCapability g_PoseDet = user.GetPoseDetectionCap();
//__________________________________
//			壁たち
//__________________________________
NomoWall* g_pT_Wall;
NomoWall* g_pX_Wall;
NomoWall* g_pY_Wall;
NomoWall* g_pH_Wall;
NomoWall* g_pK_Wall;
NomoWall* g_pV_Wall;
NomoWall* g_pRKagi_Wall;
NomoWall* g_pLKagi_Wall;
NomoWall* g_pKune_Wall;
NomoWall* g_pRikishi_Wall;
NomoWall* g_pManji_Wall;
NomoWall* g_pGyakuManji_Wall;
NomoWall* g_pBaseball_Wall;
NomoWall* g_pMonsterBall_Wall;

NomoWall* g_pMO_Wall;
NomoWall* g_pZI_Wall;
NomoWall* g_pO_Wall;



//__________________________________
//			サウンド関連
//__________________________________
BOOL g_SoundFlg		= FALSE;
BOOL g_PlayBGMFlg	= FALSE;

//__________________________________
//			BouNinGen.cpp
//__________________________________
BouNinGen* g_pBNG;
//__________________________________
//		画面切り替え用のフラグ
//__________________________________
//トラッキング開始判定
BOOL		g_TrackHandFlg = false;
//キャリブレーション中フラグ
BOOL		g_CalibrationMode = false;
//キャリブレーションミスフラグ
BOOL		g_MissCalibrationFlg = false;
//OKの表示
BOOL		g_OKFlg		  = false;
//ゲーム画面描画
BOOL		g_GameDrawFlg = false;
//メニュー画面描画
BOOL		g_MenuDrawFlg = true;
//メインメニュー画面描画
BOOL		g_MainMenuDrawFlg = true;
//セレクトレベル画面描画
BOOL		g_LevelDrawFlg = false;
//プレイヤー数選択画面描画
BOOL		g_PlayNumDrawFlg = false;
//トランジションフラグ
BOOL		g_StartTransitionFlg = FALSE;
BOOL		g_EndTransitionFlg = FALSE;

//__________________________________
//		スレッド管理
//__________________________________
BOOL ExitNIThreadFlg = FALSE;
//__________________________________
//		難易度、プレイヤー数
//__________________________________
int		g_GAMELEVEL;
int		g_PLAYNUM;
//************************終わり***************************

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//岸の追加

IplImage* camera;
xn::ImageGenerator image;
xn::UserGenerator user;

xn::SkeletonCapability skelton = user.GetSkeletonCap();

// 表示状態
bool isShowImage;
bool isShowUser;
bool isShowSkelton;

//通過してるかのフラグ
bool ALLisPass = true;
//キャリブレーションのフラグ
extern bool Calibration_flg = false;

//壁の番号
int wall_number;

double movewall_ichi = 0;

//岸の追加おしまい
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//ゲームを終了する
void CleanupExit()
{
	g_Context.Shutdown();

	exit (1);
}

#ifdef USE_GLUT

//キーボード操作
void glutKeyboard (unsigned char key,int x, int y)
{
	switch (key)
	{
	case 27:
		// 終了
		CleanupExit();
	case'p':
		// ポーズ
		g_bPause = !g_bPause;
		break;
	case 'd':
		// デプスマップの表示・非表示
		//g_bDrawDepthMap = !g_bDrawDepthMap;
		//pDrawer->SetDepthMap(g_bDrawDepthMap);
		break;
	case 'f':
		//g_bPrintFrameID = !g_bPrintFrameID;
		//g_pDrawer->SetFrameID(g_bPrintFrameID);
		break;
/*
	case 's':
		// スムーズにするかどうか
		if (g_fSmoothing == 0)
			g_fSmoothing = 0.1;
		else 
			g_fSmoothing = 0;
		g_HandsGenerator.SetSmoothing(g_fSmoothing);
		break;
*/
	case 'e':
		// セッションの終了
		g_pSessionManager->EndSession();
		break;
	}
}

static void Update(int value)
{
	if(g_GameDrawFlg == true){
	     GamePlay::game_update();
	}

	glutPostRedisplay();
	glutTimerFunc(WAIT_TIME, Update, value);
}

//y座標の反転
float MirrorYposition(float Ypos, float Hight){
	float fRet = 0;
	float Deff = Ypos - (Hight/2);
	
	fRet = (Hight/2) - Deff;
	return fRet;
}

//諸々初期化
void glInit (int * pargc, char ** argv)
{
	glutInit(pargc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1280, 960);
	//glutInitWindowSize(GL_WIN_SIZE_X, GL_WIN_SIZE_Y);
	glutCreateWindow ("もじもじくん");
	//glutFullScreen();
	glutSetCursor(GLUT_CURSOR_NONE);
	//カラーバッファ初期化
	glClearColor(1.0, 1.0, 1.0, 1.0);
	//射影変換
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//視角度、縦横比（アスペクト）、前面、後面、設定する
	gluPerspective(45.0, (float)GL_WIN_SIZE_Y/GL_WIN_SIZE_X, -3, 50.0);
	//モデル変換
	glMatrixMode(GL_MODELVIEW);
	//ポリゴンの表面だけ描画する
	glCullFace(GL_BACK);
	//各コールバック関数の登録
	glutKeyboardFunc(glutKeyboard);
	glutDisplayFunc(glutDisplay);

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);


	glEnableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

    glutTimerFunc(WAIT_TIME, Update, 0);
}
#endif
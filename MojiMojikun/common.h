#pragma once
#include <XnVFlowRouter.h>
#include <glut.h>
#include <XnVSessionManager.h>

//下の2つを追加する  by岸
#include "opencv/cv.h"
#include "opencv/highgui.h"

#include "PointDrawer.h"
#include "MenuItem.h"
#include "Macro.h"
#include "Nomotex.h"
#include "BMP.h"
#include "MenuIcon.h"
#include "BouNinGen.h"
#include "NomoWall.h"

//************************終わり***************************

//*********************************************************

//　　　　　　　　　グローバル変数

//*********************************************************


//__________________________________
//				　色々
//__________________________________

extern float g_fColor[][3];
extern int	 g_Count;
//__________________________________
//				Main.cpp
//__________________________________

// OpenNI オブジェクト
extern xn::Context g_Context;
extern xn::DepthGenerator g_DepthGenerator;
extern xn::HandsGenerator g_HandsGenerator;

// NITE オブジェクト
extern XnVSessionManager* g_pSessionManager;
extern XnVFlowRouter* g_pFlowRouter;


//セッションの状態
extern SessionState g_SessionState;
// デプスマップの表示・非表示フラグ
extern XnBool g_bDrawDepthMap;
extern XnBool g_bPrintFrameID;
// スムージングの有無フラグ
extern XnFloat	 g_fSmoothing;
extern XnBool	 g_bPause;
extern XnBool	 g_bQuit;
//OpenNI関連
extern XnCallbackHandle g_UserCallbacks; 
extern XnCallbackHandle g_CalibrationCallbacks;
extern XnCallbackHandle g_PoseCallbacks;
extern xn::PoseDetectionCapability g_PoseDet;
//__________________________________
//			PointDrawer.cpp
//__________________________________

// 手をトラッキングするオブジェクト
extern MenuIcon*			g_pMenuIcon;
extern XnVPointDrawer* g_pDrawer;
extern NomoTex*			   g_pPointTexture;
extern NomoTex*			   g_pTitleTexture;
//Historyのサイズ（3D表示）
extern int g_3DHisBufSize;

//__________________________________
//			MenuItem.cpp
//__________________________________

// メニューアイコンのオブジェクト
extern MenuItem* g_pMI_Start;
extern MenuItem* g_pMI_Level;
extern MenuItem* g_pMI_PlayNum;
extern MenuItem* g_pMI_Instruction;
extern MenuItem* g_pMI_Calibration;
extern MenuItem* g_pMI_Miss;
extern MenuItem* g_pMI_OK;
extern MenuItem* g_pMI_Exit;
//レベルセレクト画面
extern MenuItem* g_pMI_Level_Hard;
extern MenuItem* g_pMI_Level_Normal;
extern MenuItem* g_pMI_Level_Easy;
//プレイヤ数選択がめん
extern MenuItem* g_pMI_PlayNum_One;
extern MenuItem* g_pMI_PlayNum_Two;
//メニューアイテムが選択されたかどうか
extern BOOL		 g_SelectFlg;
extern BOOL		 g_MoveModeFlg1;
extern BOOL		 g_MoveModeFlg2;

//__________________________________
//			壁たち
//__________________________________
extern NomoWall* g_pT_Wall;
extern NomoWall* g_pX_Wall;
extern NomoWall* g_pY_Wall;
extern NomoWall* g_pH_Wall;
extern NomoWall* g_pK_Wall;
extern NomoWall* g_pV_Wall;
extern NomoWall* g_pRKagi_Wall;
extern NomoWall* g_pLKagi_Wall;
extern NomoWall* g_pKune_Wall;
extern NomoWall* g_pRikishi_Wall;
extern NomoWall* g_pManji_Wall;
extern NomoWall* g_pGyakuManji_Wall;
extern NomoWall* g_pBaseball_Wall;
extern NomoWall* g_pMonsterBall_Wall;

extern NomoWall* g_pMO_Wall;
extern NomoWall* g_pZI_Wall;
extern NomoWall* g_pO_Wall;

//__________________________________
//			サウンド関連
//__________________________________
extern BOOL		 g_SoundFlg;
extern BOOL		 g_PlayBGMFlg;

//__________________________________
//			BouNinGen.cpp
//__________________________________
extern BouNinGen* g_pBNG;


//__________________________________
//		画面切り替え用のフラグ
//__________________________________
//トラッキング開始判定
extern BOOL		g_TrackHandFlg;
//キャリブレーション中フラグ
extern BOOL		g_CalibrationMode;
//キャリブレーションミスフラグ
extern BOOL		g_MissCalibrationFlg;
//OKフラグ
extern BOOL		g_OKFlg;
//ゲーム画面描画
extern BOOL		g_GameDrawFlg;
//メニュー画面描画
extern BOOL		g_MenuDrawFlg;
//メインメニュー画面描画
extern BOOL		g_MainMenuDrawFlg;
//セレクトレベル画面描画
extern BOOL		g_LevelDrawFlg;
//プレイヤー数選択画面描画
extern BOOL		g_PlayNumDrawFlg;
//トランジションフラグ
extern BOOL		g_StartTransitionFlg;
extern BOOL		g_EndTransitionFlg;

//__________________________________
//		スレッド管理
//__________________________________
extern BOOL ExitNIThreadFlg;

//__________________________________
//		難易度、プレイヤー数
//__________________________________
extern int		g_GAMELEVEL;
extern int		g_PLAYNUM;

//************************終わり***************************


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
//岸の追加

extern IplImage* camera;
extern xn::ImageGenerator image;
extern xn::UserGenerator user;

extern xn::SkeletonCapability skelton;

// 表示状態
extern bool isShowImage;
extern bool isShowUser;
extern bool isShowSkelton;

//通過してるかのフラグ
extern bool ALLisPass;
//キャリブレーションのフラグ
extern bool Calibration_flg;
extern int wall_number;

extern double movewall_ichi;

//岸の追加おしまい
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


void CleanupExit();
float MirrorYposition(float Ypos, float Hight);
void glutDisplay (void);
void glutKeyboard (unsigned char key,int x, int y);
void glInit (int * pargc, char ** argv);
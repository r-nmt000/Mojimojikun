
#include <iostream>
#include <stdexcept>


//#include <opencv/cv.h>
//#include <opencv/highgui.h>

#include <XnCppWrapper.h>
#include <XnVSessionManager.h>
#include <XnVWaveDetector.h>

#include "common.h"
#include "NomoTex.h"
#include "CallBack.h"
#include "UpdateNIData.h"
#include "NomoWall.h"

#define USE_GLUT
/*******************************
　　　　ここに自分の名前を定義してね！
		他の人の定義が書いてあったら消すように！
********************************/
#define KISHI

// 設定ファイルのパス(環境に合わせて変更してください)
#ifdef defined NOMOTO
	const char* CONFIG_XML_PATH = "D:\\Visual Studio 2010\\Projects\\NHK\\SamplesConfig.xml";
	const char* YOUR_RECORD_ONI_PATH = "D:\\Visual Studio 2010\\Projects\\NHK\\MojiMojikun\\Record.oni";
#elif defined KISHI
	const char* CONFIG_XML_PATH = "C:/Documents and Settings/Administrator/My Documents/Visual Studio 2010/Projects/MojiMojikun/MojiMojikun/SamplesConfig.xml";
	const char* YOUR_RECORD_ONI_PATH = "C:/Documents and Settings/Administrator/My Documents/Visual Studio 2010\Projects/MojiMojikun/Record.oni";
#elif defined HIRADE

#endif



void TouchKey_N(unsigned char key, int x, int y)
{
	switch(key) {

		//デバッグ用コマンド的なもの
		case 'g':
           g_GameDrawFlg = true;
		   break;
		case 'p':
           Calibration_flg = false;
		   break;
		default :
			break;

	}
	glutPostRedisplay();
}

BOOL MozioInit(/*XnCallbackHandle UserCallbacks, XnCallbackHandle CalibrationCallbacks, XnCallbackHandle PoseCallbacks, xn::PoseDetectionCapability PoseDet*/)
{
	BOOL bRet = FALSE;
#ifdef USE_POINTDRAWER
	// NITEのセッションマネージャーを初期化する

	g_pSessionManager = new XnVSessionManager;
	rc = g_pSessionManager->Initialize(&g_Context, "Wave,Click", "RaiseHand");
	if (rc != XN_STATUS_OK) {
		throw std::runtime_error(xnGetStatusString(rc));
	}

	// セッションの開始終了を通知するコールバックを登録する
	XnVHandle sessionCallnack = g_pSessionManager->RegisterSession(0,
											&SessionStart, &SessionEnd );
	
	//手をトラッキングするアイコンの作成
	g_pDrawer = new XnVPointDrawer(50, g_DepthGenerator); 
	//イベントリスナーの作成
	g_pFlowRouter = new XnVFlowRouter;
	g_pFlowRouter->SetActive(g_pDrawer);

	g_pSessionManager->AddListener(g_pFlowRouter);

	g_pDrawer->RegisterNoPoints(NULL, NoHands);
	//デプスマップの描画
	//g_pDrawer->SetDepthMap(g_bDrawDepthMap);
#else
	//メニューアイコンの作成
	g_pMenuIcon = new MenuIcon(50, g_DepthGenerator);
#endif
	// メニュー項目となる文字列 
	float BigSize[]		 = { V_LEN_BIG, SPACE_BIG };
	float BigMidSize[]	 = { V_LEN_BIGMID, SPACE_BIGMID };
	float MidSize[]		 = { V_LEN_MID, SPACE_MID };
	float MidSmallSize[] = { V_LEN_MIDSMALL, SPACE_MIDSMALL };
	float SmallSize[]	 = { V_LEN_SMALL, SPACE_SMALL };
	//メインメニューのオブジェクト
	g_pMI_Start			= new MenuItem( "GAME START"			, VIRTEX_X_START,	VIRTEX_Y_START,		MidSize );
	g_pMI_Level			= new MenuItem( "SELECT LEVEL"			, VIRTEX_X_LEVEL,	VIRTEX_Y_LEVEL,		0, MOVE_Y_LEVEL,	MidSmallSize, 30 );
	g_pMI_PlayNum		= new MenuItem( "PLAYER NUMBER"			, VIRTEX_X_PLAYNUM,	VIRTEX_Y_PLAYNUM,	0, MOVE_Y_PLAYNUM,	MidSmallSize, 30 );
	g_pMI_Instruction	= new MenuItem( "PLEASE KINECT POSE"	, VIRTEX_X_INST,	VIRTEX_Y_INST, 		BigMidSize );
	g_pMI_Calibration	= new MenuItem( "CALIBRATING"			, VIRTEX_X_CAL,		VIRTEX_Y_CAL, 		BigMidSize );
	g_pMI_Miss			= new MenuItem( "TRY AGAIN"				, VIRTEX_X_CAL,		VIRTEX_Y_CAL, 		BigMidSize );
	g_pMI_OK			= new MenuItem( "OK"					, VIRTEX_X_OK,		VIRTEX_Y_OK, 		BigSize );
	//セレクトメニューのオブジェクト
	g_pMI_Level_Hard	= new MenuItem( "HARD"					, VIRTEX_X_LEVEL_HARD,	VIRTEX_Y_LEVEL_HARD,	 0, MOVE_Y_LEVEL_HARD,	SmallSize, 20);
	g_pMI_Level_Normal	= new MenuItem( "NORMAL"				, VIRTEX_X_LEVEL_NORMAL,VIRTEX_Y_LEVEL_NORMAL,	 0, MOVE_Y_LEVEL_NORMAL,SmallSize, 20);
	g_pMI_Level_Easy	= new MenuItem( "EASY"					, VIRTEX_X_LEVEL_EASY,	VIRTEX_Y_LEVEL_EASY,	 0, MOVE_Y_LEVEL_EASY,	SmallSize, 20);
	//プレイヤー数選択メニューのオブジェクト
	g_pMI_PlayNum_One	= new MenuItem( "ONE"					, VIRTEX_X_PLAYNUM_ONE, VIRTEX_Y_PLAYNUM_ONE,	 0, MOVE_Y_PLAYNUM_ONE,	SmallSize, 20);
	g_pMI_PlayNum_Two	= new MenuItem( "TWO"					, VIRTEX_X_PLAYNUM_TWO, VIRTEX_Y_PLAYNUM_TWO,	 0, MOVE_Y_PLAYNUM_TWO,	SmallSize, 20);
	g_pTitleTexture		= new NomoTex("data/Mozio.bmp",0);
	g_pPointTexture		= new NomoTex("data/Pointer.bmp",1);
	//終了メニューオブジェクト
	g_pMI_Exit			= new MenuItem( "EXIT"					, VIRTEX_X_EXIT,	VIRTEX_Y_EXIT,		SmallSize );
	//棒人間のオブジェクト
	g_pBNG				= new BouNinGen();
	//T壁
	g_pT_Wall			= new NomoWall("data/Wall/T_Wall.bmp");
	g_pX_Wall			= new NomoWall("data/Wall/X_Wall.bmp");
	g_pY_Wall			= new NomoWall("data/Wall/Y_Wall.bmp");
	g_pH_Wall			= new NomoWall("data/Wall/H_Wall.bmp");
	g_pK_Wall		    = new NomoWall("data/Wall/K_Wall.bmp");
	g_pV_Wall		    = new NomoWall("data/Wall/V_Wall.bmp");
	g_pRKagi_Wall		= new NomoWall("data/Wall/RKagi_Wall.bmp");
	g_pLKagi_Wall		= new NomoWall("data/Wall/LKagi_Wall.bmp");
	g_pKune_Wall		= new NomoWall("data/Wall/Kune_Wall.bmp");
	g_pRikishi_Wall		= new NomoWall("data/Wall/Rikishi_Wall.bmp");
	g_pManji_Wall		= new NomoWall("data/Wall/Manji_Wall.bmp");
	g_pGyakuManji_Wall	= new NomoWall("data/Wall/GyakuManji_Wall.bmp");
	g_pBaseball_Wall	= new NomoWall("data/Wall/Baseball_Wall.bmp");
	g_pMonsterBall_Wall	= new NomoWall("data/Wall/MonsterBall_Wall.bmp");
    g_pMO_Wall			= new NomoWall("data/Wall/MO.bmp");

	g_pZI_Wall			= new NomoWall("data/Wall/ZI.bmp");
	g_pO_Wall			= new NomoWall("data/Wall/O.bmp");
	bRet = TRUE;

	return bRet;
}
	




//*********************************************************

//　　　　　　　　　　　メイン関数

//*********************************************************

int main (int argc, char **argv) 
{
	g_UserCallbacks = NULL;
	g_CalibrationCallbacks = NULL;
	g_PoseCallbacks = NULL;
	g_PoseDet = user.GetPoseDetectionCap();
	try{
	//#define USE_ONI
#ifdef USE_ONI//ONIファイルを使う場合
		/*
		//コンテキストの初期化
		XnStatus rc = g_Context.Init();
		if (rc != XN_STATUS_OK) {
		  throw std::runtime_error(xnGetStatusString(rc));
		}
		*/
		// ONIファイルからレコードデータを読み込む    
		rc = g_Context.OpenFileRecording(YOUR_RECORD_ONI_PATH);    
		if (rc != XN_STATUS_OK){
			throw std::runtime_error(xnGetStatusString(rc)); 
		}
#else 
		//キネクトを使う場合
		// OpenNIのコンテキストを初期化する
		XnStatus rc = g_Context.InitFromXmlFile(CONFIG_XML_PATH);
		if (rc != XN_STATUS_OK) {
		  throw std::runtime_error(xnGetStatusString(rc));
		}
#endif
		// デプスジェネレータの作成
		rc = g_Context.FindExistingNode(XN_NODE_TYPE_DEPTH, g_DepthGenerator);
		if (rc != XN_STATUS_OK) {
			throw std::runtime_error(xnGetStatusString(rc));
		}

		// ハンドジェネレータの作成
		rc = g_Context.FindExistingNode(XN_NODE_TYPE_HANDS, g_HandsGenerator);
		if (rc != XN_STATUS_OK) {
		  throw std::runtime_error(xnGetStatusString(rc));
		}

		//******************************
		//          岸の追加
		//*******************************

		camera = 0;
		// イメージジェネレータの作成
		//xn::ImageGenerator image;
		rc = g_Context.FindExistingNode(XN_NODE_TYPE_IMAGE, image);
		if (rc != XN_STATUS_OK) {
		  throw std::runtime_error(xnGetStatusString(rc));
		}
	

		// デプスの座標をイメージに合わせる
		g_DepthGenerator.GetAlternativeViewPointCap().SetViewPoint(image);
	

		// ユーザーの作成
		//xn::UserGenerator user;
		rc = g_Context.FindExistingNode( XN_NODE_TYPE_USER, user );
		if ( rc != XN_STATUS_OK ) {
				rc = user.Create(g_Context);
				if ( rc != XN_STATUS_OK ) {
					throw std::runtime_error( xnGetStatusString( rc ) );
				}
		}

		// ユーザー検出機能をサポートしているか確認
		if (!user.IsCapabilitySupported(XN_CAPABILITY_SKELETON)) {
			throw std::runtime_error("ユーザー検出をサポートしてません");
		}

		
		XnChar pose[20] = "";

		// キャリブレーションにポーズが必要
		/*xn::SkeletonCapability*/ skelton = user.GetSkeletonCap();
		if (skelton.NeedPoseForCalibration()) {
			// ポーズ検出のサポートチェック
			if (!user.IsCapabilitySupported(XN_CAPABILITY_POSE_DETECTION)) {
				throw std::runtime_error("ポーズ検出をサポートしてません");
			}

			// キャリブレーションポーズの取得
			skelton.GetCalibrationPose(pose);

			// ポーズ検出のコールバックを登録
			g_PoseDet = user.GetPoseDetectionCap();
			rc = g_PoseDet.RegisterToPoseCallbacks(&::PoseDetected, &::PoseLost,
				&user, g_PoseCallbacks);
			if( rc != XN_STATUS_OK ){
				throw std::runtime_error("ポーズ検出のコールバック関数を登録できません");
			}
		}

		// ユーザー認識のコールバックを登録
		user.RegisterUserCallbacks(&::UserDetected, &::UserLost, pose,
		g_UserCallbacks);

		// キャリブレーションのコールバックを登録
		rc = skelton.RegisterCalibrationCallbacks(&::CalibrationStart, &::CalibrationEnd,
		&user, g_CalibrationCallbacks);
		if( rc != XN_STATUS_OK ){
			throw std::runtime_error("キャリブレーションのコールバック関数を登録できません");
		}
			

		// ユーザートラッキングで、すべてをトラッキングする
		rc = skelton.SetSkeletonProfile(XN_SKEL_PROFILE_ALL);
		if( rc != XN_STATUS_OK ){
			throw std::runtime_error("SetSkeletonProfileが失敗しました");
		}
		// カメラサイズのイメージを作成(8bitのRGB)
		XnMapOutputMode outputMode;
		image.GetMapOutputMode(outputMode);
		camera = ::cvCreateImage(cvSize(outputMode.nXRes, outputMode.nYRes),
		  IPL_DEPTH_8U, 3);
		if (!camera) {
		  throw std::runtime_error("error : cvCreateImage");
		}

		// 表示状態
		isShowImage = false;
		isShowUser = true;
		isShowSkelton = true;

		//***************************************
		//岸の追加おしまい
		//*****************************************
		if(MozioInit() ){
			std::cout << "Initialize Success" << std::endl;

			//GLUTの初期化
			glInit(&argc, argv);

			//キーボードでショートカット  byきし
			glutKeyboardFunc(TouchKey_N);
		
			//キネクトデータの更新は別スレッドで行う
			UpdateNIData();
			//メインループ
			glutMainLoop();

			//コールバック関数の登録解除、ゲームオブジェクトの削除
			//UnregAndClearGameObject( UserCallbacks, CalibrationCallbacks, PoseCallbacks, PoseDet );
		}
		else{
			throw std::runtime_error("error : MozioInit exception");
		}
		
	}
	catch (std::exception& ex) 
	{
		std::cout << ex.what() << std::endl;
	}
	/*
	//OpenNI関連の初期化、もじおのオブジェクト生成
	if( MozioInit( UserCallbacks, CalibrationCallbacks, PoseCallbacks, PoseDet) ){
		//GLUTの初期化
		glInit(&argc, argv);

		//キーボードでショートカット  byきし
		glutKeyboardFunc(TouchKey_N);
		
		//キネクトデータの更新は別スレッドで行う
		UpdateNIData();
		//メインループ
		glutMainLoop();

		//コールバック関数の登録解除、ゲームオブジェクトの削除
		UnregAndClearGameObject( UserCallbacks, CalibrationCallbacks, PoseCallbacks, PoseDet );
	}*/
  return 0;
}

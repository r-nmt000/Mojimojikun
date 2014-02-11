#include "Common.h"
#include <Mmsystem.h>
#include <Windows.h>
#include "NomoTex.h"
#include "MenuDisplay.h"

//GamePlay.hを追加　岸
#include "GamePlay.h"
#include "passage.h"


//*********************************************************
//						glutDisplay
//				フレームごとに呼ばれる描画関数
//*********************************************************
void glutDisplay (void)
{

	//if文で無理矢理囲う　岸
    if(g_GameDrawFlg != TRUE){
	     glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	     // Setup the OpenGL viewpoint
	     glMatrixMode(GL_PROJECTION);
	     //glPushMatrix();
	     glLoadIdentity();

	     //XnMapOutputMode mode;
	     //g_DepthGenerator.GetMapOutputMode(mode);
	     //視点、視野の設定
	     //glOrtho(left, right, bottom, top, near, far);
	     glOrtho(0, GL_WIN_SIZE_X/*mode.nXRes*/, 0/*mode.nYRes*/, GL_WIN_SIZE_Y, 0, 50.0);


	     //glDisable(GL_TEXTURE_2D);

	     if (!g_bPause)
	     {
		     //キネクトからの情報の更新
		    // g_Context.WaitOneUpdateAll(g_DepthGenerator);
#ifdef USE_POINTDRAWER
		     // Update NITE tree
		     g_pSessionManager->Update(&g_Context);
#else
			 //トラッキングが完了していたら
			 //メニューアイコンの更新 nomoto
			 if( g_TrackHandFlg != FALSE ){
				 g_pMenuIcon->Update();
			 }
#endif
#ifdef USE_GLUT
		     //セッションの状態を表示
		     //PrintSessionState(g_SessionState);
		     //メニュー画面の描画
		     DrawMenu();
			 //passage::passage_main ();
#endif
	     }

#ifdef USE_GLUT
	glutSwapBuffers();
#endif
    } else{
		  //Gemedisplayを呼ぶとゲームスタート
		  GamePlay::Gamedisplay();
		  
	}
}


#include "Common.h"
#include <Mmsystem.h>
#include <Windows.h>
#include "NomoTex.h"
#include "Sound.h"
#include "Transition.h"
#include "ExitGame.h"



//*********************************************************
//						DrawMainMenu
//				　メインメニュー画面の描画
//*********************************************************
void DrawMainMenu(void)
{
	static float Darkness = 0;

	GLUtesselator *tess;
	glEnable(GL_DEPTH_TEST);
	glPushMatrix();
	glClearColor(1,1,1,1);
	//通常表示
	if( !g_LevelDrawFlg && !g_PlayNumDrawFlg && !g_MoveModeFlg1 && !g_MoveModeFlg2 ){

		//平常時にスピードを初期化
		g_pMI_Level->SetSpeed(SPEED_LEVEL);
		g_pMI_Level_Hard->SetSpeed(SPEED_LEVEL_HARD);
		g_pMI_Level_Normal->SetSpeed(SPEED_LEVEL_NORMAL);
		g_pMI_Level_Easy->SetSpeed(SPEED_LEVEL_EASY);
		g_pMI_PlayNum->SetSpeed(SPEED_PLAYNUM);
		g_pMI_PlayNum_One->SetSpeed(SPEED_PLAYNUM_ONE);
		g_pMI_PlayNum_Two->SetSpeed(SPEED_PLAYNUM_TWO);

		//メニュー項目となる文字列の描画
		//音鳴り状態
		if( g_SoundFlg && g_pMI_Start->GetSoundFlg() ){
			float fColor[] = {0.5 + 0.5 * sin((float)g_Count*2), 0,0};
			g_pMI_Start->SetColor(fColor);


		}
		//音鳴り解除
		else if( !g_SoundFlg && g_pMI_Start->GetSoundFlg() ){
			g_pMI_Start->SetSoundFlg(FALSE);
			g_MainMenuDrawFlg = FALSE;
			g_GameDrawFlg = TRUE;
			g_EndTransitionFlg = FALSE;
			Darkness = 1;
		}
		//ゲームスタート選択時
		else if( g_pMI_Start->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE){
			if( g_SelectFlg ){
				if( !g_SoundFlg ){
					g_pMI_Start->SetSoundFlg(TRUE);
					ControlSound(L"GameStart.wav");
					g_EndTransitionFlg = TRUE;
				}
			}
			g_pMI_Start->SetColor(g_fColor[RED]);
		}
		else{
			g_pMI_Start->SetColor(g_fColor[BLUE]);
		}

		//レベル選択時
		if( g_pMI_Level->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE){
			if( g_SelectFlg != FALSE ){
				ControlSound(L"SelectOption.wav");
				g_MoveModeFlg1 = TRUE;
				g_LevelDrawFlg = TRUE;
				//移動可能にする
				g_pMI_Level->SetMove(TRUE);
				g_pMI_Level_Hard->SetMove(TRUE);
				g_pMI_Level_Normal->SetMove(TRUE);
				g_pMI_Level_Easy->SetMove(TRUE);
				//不可視にする
				g_pMI_Start->SetDrawable(FALSE);
				g_pMI_PlayNum->SetDrawable(FALSE);
				g_pMI_Instruction->SetDrawable(FALSE);
				g_pMI_OK->SetDrawable(FALSE);
			}
			g_pMI_Level->SetColor(g_fColor[RED]);
		}
		else{
			g_pMI_Level->SetColor(g_fColor[BLUE]);
		}
		//プレイヤー数選択時
		if( g_pMI_PlayNum->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE){
			if( g_SelectFlg != FALSE ){
				ControlSound(L"SelectOption.wav");
				g_MoveModeFlg1 = TRUE;
				g_PlayNumDrawFlg = TRUE;
				g_pMI_PlayNum->SetMove(TRUE);
				g_pMI_PlayNum_One->SetMove(TRUE);
				g_pMI_PlayNum_Two->SetMove(TRUE);
				g_pMI_Level->SetDrawable(FALSE);
				g_pMI_Start->SetDrawable(FALSE);
				g_pMI_Instruction->SetDrawable(FALSE);
				g_pMI_OK->SetDrawable(FALSE);
			}
			g_pMI_PlayNum->SetColor(g_fColor[RED]);
		}
		else{
			g_pMI_PlayNum->SetColor(g_fColor[BLUE]);
		}
		//音鳴り状態
		if( g_SoundFlg && g_pMI_Exit->GetSoundFlg() ){
			float fColor[] = {0.5 + 0.5 * sin((float)g_Count*2), 0,0};
			g_pMI_Exit->SetColor(fColor);
		}
		//音鳴り解除
		else if( !g_SoundFlg && g_pMI_Exit->GetSoundFlg() ){
			g_pMI_Exit->SetSoundFlg(FALSE);
			g_EndTransitionFlg = FALSE;
			//もじお終了
			ExitMozio(g_UserCallbacks, g_CalibrationCallbacks, g_PoseCallbacks, g_PoseDet);
		}
		//終了選択時
		else if( g_pMI_Exit->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE){
			if( g_SelectFlg ){
				if( !g_SoundFlg ){
					g_pMI_Exit->SetSoundFlg(TRUE);
					g_EndTransitionFlg = TRUE;
					ControlSound(L"SelectOption.wav");
				}
			}
			g_pMI_Exit->SetColor(g_fColor[RED]);
		}
		else{
			g_pMI_Exit->SetColor(g_fColor[BLUE]);
		}
		//テクスチャのロード
		
		//g_pPointTexture		= new NomoTex("Pointer.bmp" ,1);
		g_pTitleTexture->TexSet();
		//glBindTexture(GL_TEXTURE_2D, g_pTitleTexture->GetTexNum());
		glBegin( GL_POLYGON );
			glColor3f(1.0, 1.0, 1.0);         
			glTexCoord2d( 0.0, 0.0);  glVertex3f( 0, 0, -30.0);  //左下
			glTexCoord2d( 1.0, 0.0);  glVertex3f( 640, 0, -30.0);  //右下
			glTexCoord2d( 1.0, 1.0);  glVertex3f( 640, 480, -30.0);  //右上
			glTexCoord2d( 0.0, 1.0);  glVertex3f(  0, 480, -30.0);  //左上
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);

		g_pMI_Start->Draw();
		g_pMI_Level->Draw();
		g_pMI_PlayNum->Draw();
		g_pMI_Exit->Draw();


		//トラッキングが済んだかどうか判定
		if( !g_TrackHandFlg ){
			glDepthMask(GL_FALSE);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			//うす暗くする
			glBegin( GL_POLYGON );
				glColor4f(0, 0, 0, 0.9);         
				glVertex3f( 0, 0, 0);  //左下
				glVertex3f( 640, 0, 0);  //右下
				glVertex3f( 640, 480, 0);  //右上
				glVertex3f(  0, 480, 0);  //左上
			glEnd();
			glDisable(GL_BLEND);
			glDepthMask(GL_TRUE);
			float fRed[] = {0.5 + 0.5*sin(g_Count / 8.0), 0,0};
			float fBlue[] = {0, 0,0.5 + 0.5*sin(g_Count / 8.0)};
			float fYellow[] = {0.5+0.5*sin(g_Count/8.0), 0.5+0.5*sin(g_Count/8.0), 0 };
			//float fYellow[] = {0.5,0,0.5};
			//g_pMI_Instruction->SetLUPosition(VIRTEX_X_INST -10.0 * ((int)g_Count % 270), VIRTEX_Y_INST);
			//キャリブレーション中の時
			if( g_CalibrationMode ){
				g_pMI_Calibration->SetColor( fYellow );
				g_pMI_Calibration->Draw();
			}
			//キャリブレーション失敗したとき
			else if( g_MissCalibrationFlg ){
				//音鳴り状態
				if( g_SoundFlg && g_pMI_Miss->GetSoundFlg() ){
					g_pMI_Miss->SetColor( fBlue );
					g_pMI_Miss->Draw();
				}
				//音鳴り解除
				else if(!g_SoundFlg && g_pMI_Miss->GetSoundFlg()){
					g_pMI_Miss->SetSoundFlg(FALSE);
					//g_pMI_Miss = FALSE;
					g_MissCalibrationFlg = false;
				}
				else{
					//サウンド鳴らす
					g_SoundFlg = TRUE;
					g_pMI_Miss->SetSoundFlg(TRUE);
					ControlSound(L"MissCal.wav");
				}
			}
			else{
				g_pMI_Instruction->SetColor( fRed );
				g_pMI_Instruction->Draw();
			}
		}
		if( g_OKFlg ){

			//音鳴り状態
			if( g_SoundFlg && g_pMI_OK->GetSoundFlg() ){
				glDepthMask(GL_FALSE);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBegin( GL_POLYGON );
					glColor4f(0, 0, 0, 0.9);         
					glVertex3f( 0, 0, 0);  //左下
					glVertex3f( 640, 0, 0);  //右下
					glVertex3f( 640, 480, 0);  //右上
					glVertex3f(  0, 480, 0);  //左上
				glEnd();
				glDisable(GL_BLEND);
				glDepthMask(GL_TRUE);
				float fColor[] = {0, 0.5 + 0.5 * sin(g_Count / 5.0), 0};
				g_pMI_OK->SetColor( fColor );
				g_pMI_OK->Draw();
			}
			//音鳴り解除
			else if(!g_SoundFlg && g_pMI_OK->GetSoundFlg()){
				g_pMI_OK->SetSoundFlg(FALSE);
				g_OKFlg = FALSE;
			}
			else{
				//サウンド鳴らす
				g_SoundFlg = TRUE;
				g_pMI_OK->SetSoundFlg(TRUE);
				ControlSound(L"SelectOption.wav");
			}
		}
		if(g_StartTransitionFlg){
			Menu_DecrementDarkTransition(&Darkness);
			if(Darkness < 0 ){
				Darkness = 0;
				g_StartTransitionFlg = FALSE;
			}
		}
		else if(g_EndTransitionFlg){
			Menu_IncrementDarkTransition(&Darkness);
		}

	}
	//ムーブ１（メイン表示→レベル画面）
	else if( g_MoveModeFlg1 && g_LevelDrawFlg ){
		g_pMI_Level->Move( 0, MOVE_Y_LEVEL, UP, TRUE);
		g_pMI_Level->Draw();
		Sleep(30);
	}
	//ムーブ２（メイン表示→レベル画面）
	else if( g_MoveModeFlg2 && g_LevelDrawFlg ){
		//可視状態にする
		g_pMI_Level_Hard->SetDrawable(TRUE);
		g_pMI_Level_Normal->SetDrawable(TRUE);
		g_pMI_Level_Easy->SetDrawable(TRUE);
		//移動させる
		g_pMI_Level_Hard->Move( 0, MOVE_Y_LEVEL_HARD, DOWN, FALSE );
		g_pMI_Level_Normal->Move( 0, MOVE_Y_LEVEL_NORMAL, DOWN, FALSE );
		g_pMI_Level_Easy->Move( 0, MOVE_Y_LEVEL_EASY, DOWN, TRUE );
		//描画する
		g_pMI_Level_Hard->Draw();
		g_pMI_Level_Normal->Draw();
		g_pMI_Level_Easy->Draw();
		Sleep(30);
	}
	//ムーブ１（メイン表示→プレイヤー画面）
	else if( g_MoveModeFlg1 && g_PlayNumDrawFlg ){
		g_pMI_PlayNum->Move( 0, MOVE_Y_PLAYNUM, UP, TRUE);
		g_pMI_PlayNum->Draw();
		Sleep(30);
	}
	//ムーブ２（メイン表示→プレイヤー画面）
	else if( g_MoveModeFlg2 && g_PlayNumDrawFlg ){
		//可視状態にする
		g_pMI_PlayNum_One->SetDrawable(TRUE);
		g_pMI_PlayNum_Two->SetDrawable(TRUE);
		//移動させる
		g_pMI_PlayNum_One->Move( 0, MOVE_Y_PLAYNUM_ONE, DOWN, FALSE );
		g_pMI_PlayNum_Two->Move( 0, MOVE_Y_PLAYNUM_TWO, DOWN, TRUE );
		//描画する
		g_pMI_PlayNum_One->Draw();
		g_pMI_PlayNum_Two->Draw();
		g_pMI_PlayNum->Draw();
		Sleep(30);
	}
	glPopMatrix();
	g_pTitleTexture->DeleteTex();
	g_Count++;
	if(g_Count > 1000){
		g_Count = 0;
	}
}


//*********************************************************
//						DrawLevelMenu
//				　メニュー画面の描画
//*********************************************************
void DrawLevelMenu(){

	//デプスの更新
	glEnable(GL_DEPTH_TEST);
	if(!g_MoveModeFlg1 && !g_MoveModeFlg2){
		//平常時に変化したスピードを初期化
		g_pMI_Level->SetSpeed(SPEED_LEVEL);
		g_pMI_Level_Hard->SetSpeed(SPEED_LEVEL_HARD);
		g_pMI_Level_Normal->SetSpeed(SPEED_LEVEL_NORMAL);
		g_pMI_Level_Easy->SetSpeed(SPEED_LEVEL_EASY);
		//ポインタがSELECT LEVELの上にきたとき
		//音鳴り状態
		if( g_SoundFlg && g_pMI_Level->GetSoundFlg() ){
			float fColor[] = {0.5 + 0.5 * sin((float)g_Count*2), 0,0};
			g_pMI_Level->SetColor(fColor);
		}
		//音鳴り解除
		else if( !g_SoundFlg && g_pMI_Level_Hard->GetSoundFlg() ){
			g_pMI_Level->SetSoundFlg(FALSE);
		}
		else if( g_pMI_Level->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE){
			if( g_SelectFlg == TRUE ){
				g_pMI_Level->SetSoundFlg(TRUE);
				ControlSound(L"SelectOption.wav");
				g_MoveModeFlg1 = TRUE;
				g_pMI_Level->SetMove(TRUE);
				g_pMI_Level_Hard->SetMove(TRUE);
				g_pMI_Level_Normal->SetMove(TRUE);
				g_pMI_Level_Easy->SetMove(TRUE);
			}
			g_pMI_Level->SetColor(g_fColor[RED]);
		}
		else{
			g_pMI_Level->SetColor(g_fColor[BLUE]);
		}
//****************************************************
//HARD
//****************************************************
		//音鳴りモード
		if( g_SoundFlg && g_pMI_Level_Hard->GetSoundFlg() ){
			float fColor[] = {0.5 + 0.5 * sin((float)g_Count*2), 0,0};
			g_pMI_Level_Hard->SetColor(fColor);
		}
		//音鳴り解除
		else if( !g_SoundFlg && g_pMI_Level_Hard->GetSoundFlg() ){
			g_pMI_Level_Hard->SetSoundFlg(FALSE);
		}
		//ハードにポインタのった状態
		else if( g_pMI_Level_Hard->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE){
			//ハードが選択されたらレベルをハードに
			if( g_SelectFlg ){
				if( !g_SoundFlg ){
					g_pMI_Level_Hard->SetSoundFlg(TRUE);
					ControlSound(L"SelectLvPly.wav");
					g_GAMELEVEL = HARD;
				}
			}
			g_pMI_Level_Hard->SetColor(g_fColor[RED]);
		}
		else{
			g_pMI_Level_Hard->SetColor(g_fColor[BLUE]);
		}
//****************************************************
//NORMAL
//****************************************************
		//音鳴り状態
		if( g_SoundFlg &&g_pMI_Level_Normal->GetSoundFlg() ){
			float fColor[] = {0.5 + 0.5 * sin((float)g_Count*2), 0,0};
			g_pMI_Level_Normal->SetColor(fColor);
		}
		//音鳴り解除
		else if( !g_SoundFlg && g_pMI_Level_Normal->GetSoundFlg() ){
			g_pMI_Level_Normal->SetSoundFlg(FALSE);
		}
		else if( g_pMI_Level_Normal->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE){
			//ノーマルが選択されたらレベルをノーマルに
			if( g_SelectFlg ){
				if( !g_SoundFlg ){
					g_pMI_Level_Normal->SetSoundFlg(TRUE);
					ControlSound(L"SelectLvPly.wav");
					g_GAMELEVEL = NORMAL;
				}
			}
			g_pMI_Level_Normal->SetColor(g_fColor[RED]);
		}
		else{
			g_pMI_Level_Normal->SetColor(g_fColor[BLUE]);
		}
//****************************************************
//EASY
//****************************************************
		//音鳴り状態
		if( g_SoundFlg && g_pMI_Level_Easy->GetSoundFlg() ){
			float fColor[] = {0.5 + 0.5 * sin((float)g_Count*2.0), 0,0};
			g_pMI_Level_Easy->SetColor(fColor);
		}
		//音鳴り解除
		else if( !g_SoundFlg && g_pMI_Level_Easy->GetSoundFlg() ){
			g_pMI_Level_Easy->SetSoundFlg(FALSE);
		}
		else if( g_pMI_Level_Easy->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE){
			//イージーが選択されたらレベルをイージーに
			if( g_SelectFlg ){
				if( !g_SoundFlg ){
					g_pMI_Level_Easy->SetSoundFlg(TRUE);
					ControlSound(L"SelectLvPly.wav");
					g_GAMELEVEL = EASY;
				}
			}
			g_pMI_Level_Easy->SetColor(g_fColor[RED]);
		}
		else{
			g_pMI_Level_Easy->SetColor(g_fColor[BLUE]);
		}
		g_pMI_Level->Draw();
		g_pMI_Level_Hard->Draw();
		g_pMI_Level_Normal->Draw();
		g_pMI_Level_Easy->Draw();
	}
	else if( g_MoveModeFlg1 ){
		g_pMI_Level_Hard->Move(0, VIRTEX_Y_LEVEL_HARD, UP, FALSE);
		g_pMI_Level_Normal->Move(0, VIRTEX_Y_LEVEL_NORMAL, UP, FALSE);
		g_pMI_Level_Easy->Move(0, VIRTEX_Y_LEVEL_EASY, UP, TRUE);
		g_pMI_Level_Hard->Draw();
		g_pMI_Level_Normal->Draw();
		g_pMI_Level_Easy->Draw();
		Sleep(30);
	}
	else if( g_MoveModeFlg2 ){
		g_pMI_Level_Hard->SetDrawable( FALSE );
		g_pMI_Level_Normal->SetDrawable( FALSE );
		g_pMI_Level_Easy->SetDrawable( FALSE );
		g_pMI_Level->Move(0, VIRTEX_Y_LEVEL, DOWN, TRUE );
		g_pMI_Level->Draw();
		//表示可能にする
		g_pMI_Start->SetDrawable(TRUE);
		g_pMI_PlayNum->SetDrawable(TRUE);
		g_pMI_Instruction->SetDrawable(TRUE);
		g_pMI_OK->SetDrawable(TRUE);
		Sleep(30);
	}
	g_Count++;
}

//*********************************************************
//						DrawPlayerMenu
//				　プレイヤー数選択メニュー画面の描画
//*********************************************************
void DrawPlayerMenu(){
	//デプスの更新
	glEnable(GL_DEPTH_TEST);
	if(!g_MoveModeFlg1 && !g_MoveModeFlg2){
		//平常時にスピードを初期化しとく
		g_pMI_PlayNum->SetSpeed(SPEED_PLAYNUM);
		g_pMI_PlayNum_One->SetSpeed(SPEED_PLAYNUM_ONE);
		g_pMI_PlayNum_Two->SetSpeed(SPEED_PLAYNUM_TWO);
		//メニュー項目となる文字列の描画
		//音鳴りモード
		if( g_SoundFlg && g_pMI_PlayNum->GetSoundFlg()){
			float fColor[] = {0.5 + 0.5 * sin((float)g_Count*2), 0,0};
			g_pMI_PlayNum->SetColor(fColor);
		}
		//音鳴り解除
		else if( !g_SoundFlg && g_pMI_PlayNum->GetSoundFlg() ){
			g_pMI_PlayNum->SetSoundFlg(FALSE);
		}
		else if( g_pMI_PlayNum->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE){
			if( g_SelectFlg ){
				if( !g_SoundFlg ){
					g_pMI_PlayNum->SetSoundFlg(TRUE);
					ControlSound(L"SelectOption.wav");
				}
				g_MoveModeFlg1 = TRUE;
				g_pMI_PlayNum->SetMove(TRUE);
				g_pMI_PlayNum_One->SetMove(TRUE);
				g_pMI_PlayNum_Two->SetMove(TRUE);

			}
			g_pMI_PlayNum->SetColor(g_fColor[RED]);
		}
		else{
			g_pMI_PlayNum->SetColor(g_fColor[BLUE]);
		}
//****************************************************
//一人プレイ
//****************************************************
		//音鳴りモード
		if( g_SoundFlg && g_pMI_PlayNum_One->GetSoundFlg()){
			float fColor[] = {0.5 + 0.5 * sin((float)g_Count*2), 0,0};
			g_pMI_PlayNum_One->SetColor(fColor);
		}
		//音鳴り解除
		else if( !g_SoundFlg && g_pMI_PlayNum_One->GetSoundFlg() ){
			g_pMI_PlayNum_One->SetSoundFlg(FALSE);
		}
		//ポインタがONEの上に乗った時
		if( g_pMI_PlayNum_One->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE){
			//ONEが選択されたら一人プレイ
			if( g_SelectFlg ){
				if( !g_SoundFlg ){
					g_pMI_PlayNum_One->SetSoundFlg(TRUE);
					ControlSound(L"SelectLvPly.wav");
					g_PLAYNUM = ONE_PLAYER;
				}
			}
			g_pMI_PlayNum_One->SetColor(g_fColor[RED]);
		}
		else{
			g_pMI_PlayNum_One->SetColor(g_fColor[BLUE]);
		}
//****************************************************
//二人プレイ
//****************************************************
		//音鳴りモード
		if( g_SoundFlg && g_pMI_PlayNum_Two->GetSoundFlg()){
			float fColor[] = {0.5 + 0.5 * sin((float)g_Count*2), 0,0};
			g_pMI_PlayNum_Two->SetColor(fColor);
		}
		//音鳴り解除
		else if( !g_SoundFlg && g_pMI_PlayNum_Two->GetSoundFlg() ){
			g_pMI_PlayNum_Two->SetSoundFlg(FALSE);
		}
		else if( g_pMI_PlayNum_Two->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE){
			if( g_SelectFlg ){
				if( !g_SoundFlg ){
					g_pMI_PlayNum_Two->SetSoundFlg(TRUE);
					ControlSound(L"SelectLvPly.wav");
					g_PLAYNUM = TWO_PLAYER;
				}
			}
			g_pMI_PlayNum_Two->SetColor(g_fColor[RED]);
		}
		else{
			g_pMI_PlayNum_Two->SetColor(g_fColor[BLUE]);
		}
		g_pMI_PlayNum->Draw();
		g_pMI_PlayNum_One->Draw();
		g_pMI_PlayNum_Two->Draw();

	}
	else if( g_MoveModeFlg1 ){
		g_pMI_PlayNum_One->Move(0, VIRTEX_Y_LEVEL_HARD, UP, FALSE);
		g_pMI_PlayNum_Two->Move(0, VIRTEX_Y_LEVEL_NORMAL, UP, TRUE);
		g_pMI_PlayNum_One->Draw();
		g_pMI_PlayNum_Two->Draw();
		Sleep(30);
	}
	else if( g_MoveModeFlg2 ){
		g_pMI_PlayNum_One->SetDrawable( FALSE );
		g_pMI_PlayNum_Two->SetDrawable( FALSE );
		g_pMI_PlayNum->Move(0, VIRTEX_Y_LEVEL, DOWN, TRUE );
		g_pMI_PlayNum->Draw();
		//表示可能にする
		g_pMI_Start->SetDrawable(TRUE);
		g_pMI_Level->SetDrawable(TRUE);
		g_pMI_Instruction->SetDrawable(TRUE);
		g_pMI_OK->SetDrawable(TRUE);
		Sleep(30);
	}
	g_Count++;
}
//*********************************************************
//						MenuDraw
//				　メニュー画面の描画
//*********************************************************
void DrawMenu(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	SoundInit();

	//メインメニューへ
	if(g_MainMenuDrawFlg){
		DrawMainMenu();
	}
	//レベル選択メニューへ
	else if(g_LevelDrawFlg){
		DrawLevelMenu();
	}
	//プレイヤー数選択メニューへ
	else if(g_PlayNumDrawFlg){
		DrawPlayerMenu();
	}
}
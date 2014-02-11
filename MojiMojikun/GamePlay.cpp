#include "GamePlay.h"
#include "common.h"
#include "Sound.h"
#include "Transition.h"
#include "Number.h"

   bool gameinitFlg = false;
   bool gameover_Flg = false;
   bool mizubashira_Flg = false;

   static MCI_OPEN_PARMS mop;           //midiを鳴らす変数
   //static MCI_STATUS_PARMS msp;
   static MCI_PLAY_PARMS mpp;
   static HWND hWnd;
   LPARAM lParam;
   //static MSG wParam;
   Mix_Music *music;      //ＢＧＭ用
   Mix_Chunk    *chunk,*chunk2;    //効果音用

   BMP *texture1;            //テクスチャの変数
   BMP *texture2;
   BMP *texture3;
   BMP *texture4;
   BMP *texture5;
   BMP *texture6;
   BMP *texture7;
   //BMP *texture11;

   //BMP *texture_w0;
   //BMP *texture_w1;
   //BMP *texture_w2;
   //BMP *texture_w3;
   //BMP *texture_w4;
   //BMP *texture_w5;
   //BMP *texture_w6;
   //BMP *texture_w7;
   //BMP *texture_w8;
   //BMP *texture_w9;
   BMP *texture_wn;
   //BMPImage texture1;

   float diffuse[]={0,0,0/*0.5, 0.5, 0.5*/, 1.0};
   float specular []={0.8,0.8,0.8,1.0};
   float ambient []={0.0,0.0,0.0/*0.5,0.8,0.5*/,1.0};
   float shininess = 128.0;

   double Road_Length=32;
   double Road_Height=4;
   double Road_Width=2;

   double x1=0,y2=-4,z1=2;   //視点の位置

   double ichi = 30;
   double theta = -1;
   double r = -1;

   //int wall_number = 0;
   //壁の枚数
   int wall_count = 0;

   //体力
   int HP = 3;
   //壁の速さ
   double speed = 0;

void GamePlay::Road()
{
	int i;

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture3->texture);

	for (i=0; i*Road_Height < Road_Length+1; i+=1)
	{
	    glBegin( GL_POLYGON );
		    glColor3f( 1, 1, 1);
		    glTexCoord2d( 0.0, 0.0);
			glVertex3f( -Road_Width, i*Road_Height  , 0.0);
			glTexCoord2d( 0.0, 1.0);
			glVertex3f( -Road_Width, (i+1)*Road_Height, 0.0);
		    glTexCoord2d( 1.0, 1.0);
            glVertex3f(  Road_Width, (i+1)*Road_Height, 0.0);
			glTexCoord2d( 1.0, 0.0);
			glVertex3f(  Road_Width, i*Road_Height, 0.0);
        glEnd();
	}

    glBindTexture(GL_TEXTURE_2D, 0);

    glPopMatrix();
}

void GamePlay::Kabe()           //壁を描く
{
	    int i;
	    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, texture2->texture);

		for (i=1; i*Road_Height < Road_Length+1; i+=1)
	    {
			//左面
            glBegin( GL_POLYGON );
			    glColor3f( 1, 1, 1);         
		        glTexCoord2d( 0.0, 0.0);  glVertex3f( -Road_Width,     i*Road_Height, 0.0);  //左下
		        glTexCoord2d( 0.0, 1.0);  glVertex3f( -Road_Width,     i*Road_Height, 4.0);  //左上
                glTexCoord2d( 1.0, 1.0);  glVertex3f( -Road_Width, (i+1)*Road_Height, 4.0);  //右上
		        glTexCoord2d( 1.0, 0.0);  glVertex3f( -Road_Width, (i+1)*Road_Height, 0.0);  //右下
            glEnd();
			//右面
			glBegin( GL_POLYGON );
			    glColor3f( 1, 1, 1);         
		        glTexCoord2d( 0.0, 0.0);  glVertex3f(  Road_Width, (i+1)*Road_Height, 0.0);  //左下
		        glTexCoord2d( 0.0, 1.0);  glVertex3f(  Road_Width, (i+1)*Road_Height, 4.0);  //左上
                glTexCoord2d( 1.0, 1.0);  glVertex3f(  Road_Width,     i*Road_Height, 4.0);  //右上
		        glTexCoord2d( 1.0, 0.0);  glVertex3f(  Road_Width,     i*Road_Height, 0.0);  //右下
            glEnd();
		}

		//左面
        glBegin( GL_POLYGON );
			glColor3f( 1, 1, 1);         
		    glTexCoord2d( 0.0, 0.0);  glVertex3f( -Road_Width*3, Road_Height, 0.0);  //左下
		    glTexCoord2d( 0.0, 1.0);  glVertex3f( -Road_Width*3, Road_Height, 4.0);  //左上
            glTexCoord2d( 1.0, 1.0);  glVertex3f(   -Road_Width, Road_Height, 4.0);  //右上
		    glTexCoord2d( 1.0, 0.0);  glVertex3f(   -Road_Width, Road_Height, 0.0);  //右下
        glEnd();
	    //右面
	    glBegin( GL_POLYGON );
			glColor3f( 1, 1, 1);         
		    glTexCoord2d( 0.0, 0.0);  glVertex3f(    Road_Width, Road_Height, 0.0);  //左下
		    glTexCoord2d( 0.0, 1.0);  glVertex3f(    Road_Width, Road_Height, 4.0);  //左上
            glTexCoord2d( 1.0, 1.0);  glVertex3f(  Road_Width*3, Road_Height, 4.0);  //右上
		    glTexCoord2d( 1.0, 0.0);  glVertex3f(  Road_Width*3, Road_Height, 0.0);  //右下
        glEnd();

		glBindTexture(GL_TEXTURE_2D, 0);
		glBindTexture(GL_TEXTURE_2D, texture_wn->texture);

		//点数板
	    glBegin( GL_POLYGON );
			glColor3f( 1, 1, 1);         
		    glTexCoord2d( 0.0, 0.0);  glVertex3f(  Road_Width+0.3, Road_Height-0.1, 1.0);  //左下
		    glTexCoord2d( 0.0, 1.0);  glVertex3f(  Road_Width+0.3, Road_Height-0.1, 2.0);  //左上
            glTexCoord2d( 1.0, 1.0);  glVertex3f(  Road_Width+1.3, Road_Height-0.1, 2.0);  //右上
		    glTexCoord2d( 1.0, 0.0);  glVertex3f(  Road_Width+1.3, Road_Height-0.1, 1.0);  //右下
        glEnd();

	    glBegin( GL_POLYGON );
			glColor3f( 1, 1, 1);         
		    glTexCoord2d( 0.0, 0.0);  glVertex3f(  Road_Width+1.3, Road_Height-0.1, 1.0);  //左下
		    glTexCoord2d( 0.0, 1.0);  glVertex3f(  Road_Width+1.3, Road_Height-0.1, 2.0);  //左上
            glTexCoord2d( 1.0, 1.0);  glVertex3f(  Road_Width+2.3, Road_Height-0.1, 2.0);  //右上
		    glTexCoord2d( 1.0, 0.0);  glVertex3f(  Road_Width+2.3, Road_Height-0.1, 1.0);  //右下
        glEnd();

		//glPushMatrix();
		//glTranslatef( Road_Width+0.8, Road_Height-0.1, 1.5);
		ScoreBoard();
		//glPopMatrix();
        glBindTexture(GL_TEXTURE_2D, 0);

		//体力板
		glBindTexture(GL_TEXTURE_2D, texture5->texture);
		if(HP > 0){
	        glBegin( GL_POLYGON );
			    glColor3f( 1, 1, 1);         
		        glTexCoord2d( 0.0, 0.0);  glVertex3f(  -Road_Width-1.3, Road_Height-0.1, 0.5);  //左下
		        glTexCoord2d( 0.0, 1.0);  glVertex3f(  -Road_Width-1.3, Road_Height-0.1, 1.5);  //左上
                glTexCoord2d( 1.0, 1.0);  glVertex3f(  -Road_Width-0.3, Road_Height-0.1, 1.5);  //右上
		        glTexCoord2d( 1.0, 0.0);  glVertex3f(  -Road_Width-0.3, Road_Height-0.1, 0.5);  //右下
            glEnd();
		}
		if(HP > 1){
	        glBegin( GL_POLYGON );
			    glColor3f( 1, 1, 1);         
		        glTexCoord2d( 0.0, 0.0);  glVertex3f(  -Road_Width-1.3, Road_Height-0.1, 1.5);  //左下
		        glTexCoord2d( 0.0, 1.0);  glVertex3f(  -Road_Width-1.3, Road_Height-0.1, 2.5);  //左上
                glTexCoord2d( 1.0, 1.0);  glVertex3f(  -Road_Width-0.3, Road_Height-0.1, 2.5);  //右上
		        glTexCoord2d( 1.0, 0.0);  glVertex3f(  -Road_Width-0.3, Road_Height-0.1, 1.5);  //右下
            glEnd();
		}
		if(HP > 2){
	        glBegin( GL_POLYGON );
			    glColor3f( 1, 1, 1);         
		        glTexCoord2d( 0.0, 0.0);  glVertex3f(  -Road_Width-1.3, Road_Height-0.1, 2.5);  //左下
		        glTexCoord2d( 0.0, 1.0);  glVertex3f(  -Road_Width-1.3, Road_Height-0.1, 3.5);  //左上
                glTexCoord2d( 1.0, 1.0);  glVertex3f(  -Road_Width-0.3, Road_Height-0.1, 3.5);  //右上
		        glTexCoord2d( 1.0, 0.0);  glVertex3f(  -Road_Width-0.3, Road_Height-0.1, 2.5);  //右下
            glEnd();
		}
        glBindTexture(GL_TEXTURE_2D, 0);
		if(ALLisPass){
			glBindTexture(GL_TEXTURE_2D, texture6->texture);
		} else{
		    glBindTexture(GL_TEXTURE_2D, texture7->texture);
		}
	    glBegin( GL_POLYGON );
			glColor3f( 1, 1, 1);         
		    glTexCoord2d( 0.0, 0.0);  glVertex3f(  Road_Width+0.3, Road_Height-0.1, 2.5);  //左下
		    glTexCoord2d( 0.0, 1.0);  glVertex3f(  Road_Width+0.3, Road_Height-0.1, 3.5);  //左上
            glTexCoord2d( 1.0, 1.0);  glVertex3f(  Road_Width+1.3, Road_Height-0.1, 3.5);  //右上
		    glTexCoord2d( 1.0, 0.0);  glVertex3f(  Road_Width+1.3, Road_Height-0.1, 2.5);  //右下
        glEnd();
        glBindTexture(GL_TEXTURE_2D, 0);

	    glPopMatrix();
}

void GamePlay::Sky()
{
    int i;
	int j;
    glPushMatrix();

	//空
	//　テクスチャをバインド
    glBindTexture(GL_TEXTURE_2D, texture1->texture);
    glBegin( GL_POLYGON );
		glColor3f( 1, 1, 1);
		glTexCoord2d( 0.0, 0.0);
		glVertex3f( -30, 30,  0);  //左下
		glTexCoord2d( 0.0, 1.0);
		glVertex3f( -30, 30, 45);  //左上
        glTexCoord2d( 1.0, 1.0);
		glVertex3f(  30, 30, 45);  //右上
		glTexCoord2d( 1.0, 0.0);
		glVertex3f(  30, 30,  0);  //右下
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

	//地面

	for(j=0; j*Road_Width*2 < 30; j+=1)
	{
		for (i=0; i*Road_Height < Road_Length+1; i+=1)
		{
		    glBindTexture(GL_TEXTURE_2D, texture4->texture);

		    glBegin( GL_POLYGON );
	        glColor3f( 1.0, 1.0, 1.0);
		        glTexCoord2d( 0.0, 0.0);  glVertex3f( -(j+1)*Road_Width*2,     i*Road_Height, 0.0);  //左下
		        glTexCoord2d( 0.0, 1.0);  glVertex3f( -(j+1)*Road_Width*2, (i+1)*Road_Height, 0.0);  //左上
                glTexCoord2d( 1.0, 1.0);  glVertex3f(     -j*Road_Width*2, (i+1)*Road_Height, 0.0);  //右上
		        glTexCoord2d( 1.0, 0.0);  glVertex3f(     -j*Road_Width*2,     i*Road_Height, 0.0);  //右下
            glEnd();

		    glBegin( GL_POLYGON );
	        glColor3f( 1, 1, 1);
		        glTexCoord2d( 0.0, 0.0);  glVertex3f(      j*Road_Width*2,     i*Road_Height, 0.0);  //左下
		        glTexCoord2d( 0.0, 1.0);  glVertex3f(      j*Road_Width*2, (i+1)*Road_Height, 0.0);  //左上
                glTexCoord2d( 1.0, 1.0);  glVertex3f(  (j+1)*Road_Width*2, (i+1)*Road_Height, 0.0);  //右上
		        glTexCoord2d( 1.0, 0.0);  glVertex3f(  (j+1)*Road_Width*2,     i*Road_Height, 0.0);  //右下
            glEnd();

			glBindTexture(GL_TEXTURE_2D, 0);
		}
	    glBindTexture(GL_TEXTURE_2D, texture3->texture);

		glBegin( GL_POLYGON );
	    glColor3f( 1.0, 1.0, 1.0);
		    glTexCoord2d( 0.0, 0.0);  glVertex3f( -(j+1)*Road_Width*2,  0, -4.0);  //左下
		    glTexCoord2d( 0.0, 1.0);  glVertex3f( -(j+1)*Road_Width*2,  0,    0);  //左上
            glTexCoord2d( 1.0, 1.0);  glVertex3f(     -j*Road_Width*2,  0,    0);  //右上
		    glTexCoord2d( 1.0, 0.0);  glVertex3f(     -j*Road_Width*2,  0, -4.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );
	    glColor3f( 1.0, 1.0, 1.0);
		    glTexCoord2d( 0.0, 0.0);  glVertex3f(      j*Road_Width*2,  0, -4.0);  //左下
		    glTexCoord2d( 0.0, 1.0);  glVertex3f(      j*Road_Width*2,  0,    0);  //左上
            glTexCoord2d( 1.0, 1.0);  glVertex3f(  (j+1)*Road_Width*2,  0,    0);  //右上
		    glTexCoord2d( 1.0, 0.0);  glVertex3f(  (j+1)*Road_Width*2,  0, -4.0);  //右下
        glEnd();

		glBindTexture(GL_TEXTURE_2D, 0);
	}
	/*
	glBegin( GL_POLYGON );
	    glColor3f( 0.3, 1.0, 0.3);
		glVertex3f( -30,  0,  -0.1);  //左下
	    glVertex3f( -30, 30,  -0.1);  //左上
        glVertex3f(  30, 30,  -0.1);  //右上
	    glVertex3f(  30,  0,  -0.1);  //右下
    glEnd();
	
	//草の部分
	glBegin( GL_POLYGON );
	    glColor3f( 0.3, 1.0, 0.3);
		glTexCoord2d( 0.0, 0.0);
		glVertex3f( -Road_Width*3,          0,  0);  //左下
	    glTexCoord2d( 0.0, 1.0);
	    glVertex3f( -Road_Width*3, Road_Height, 0);  //左上
		glTexCoord2d( 1.0, 1.0);
        glVertex3f(   -Road_Width, Road_Height, 0);  //右上
		glTexCoord2d( 1.0, 0.0);
	    glVertex3f(   -Road_Width,           0, 0);  //右下
    glEnd();

	glBegin( GL_POLYGON );
	    glColor3f( 0.3, 1.0, 0.3);
		glTexCoord2d( 0.0, 0.0);
		glVertex3f(    Road_Width,           0, 0);  //左下
	    glTexCoord2d( 0.0, 1.0);
	    glVertex3f(    Road_Width, Road_Height, 0);  //左上
		glTexCoord2d( 1.0, 1.0);
        glVertex3f(  Road_Width*3, Road_Height, 0);  //右上
		glTexCoord2d( 1.0, 0.0);
	    glVertex3f(  Road_Width*3,           0, 0);  //右下
    glEnd();

	glBegin( GL_POLYGON );
	    glColor3f( 0.3, 1.0, 0.3);
		glTexCoord2d( 0.0, 0.0);
		glVertex3f(    Road_Width,           0, 0);  //左下
	    glTexCoord2d( 0.0, 1.0);
	    glVertex3f(    Road_Width, Road_Height, 0);  //左上
		glTexCoord2d( 1.0, 1.0);
        glVertex3f(  Road_Width*3, Road_Height, 0);  //右上
		glTexCoord2d( 1.0, 0.0);
	    glVertex3f(  Road_Width*3,           0, 0);  //右下
    glEnd();
	*/

    //池
	glBegin( GL_POLYGON );
	    glColor3f( 0.5, 0.5, 1.0);
		glVertex3f( -30,   0,  -1.0);  //左下
	    glVertex3f( -30, -10,  -1.0);  //左上
        glVertex3f(  30, -10,  -1.0);  //右上
	    glVertex3f(  30,   0,  -1.0);  //右下
    glEnd();

    glPopMatrix();
}

//水柱
void GamePlay::mizubashira()
{
	theta = theta + 0.25;
	if(theta > 3.14){
		theta = 0;
		mizubashira_Flg = false;
	}

	int kakudo = 0;

    glPushMatrix();
    //float diffuse[]={1,1,1,1};
	glTranslatef( 0, -2, -1.0+sin(theta));
    //glRotatef(180, 1, 0, 0);
	//glScalef( 3, 3, 3);

	//真ん中の柱
    glPushMatrix();
    //diffuse[0] = 1; diffuse[1] = 1; diffuse[2] = 0;
    //glMaterialfv(GL_FRONT,GL_DIFFUSE  , diffuse);
	glColor3f( 0.9, 0.9, 1.0);
    glTranslatef( 0, 0, -0.5);
    glScalef(0.7, 0.7, 3);
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();

	//水の粒
	for(kakudo=0; kakudo<360; kakudo=kakudo+30){

	    glPushMatrix();
	    glColor3f( 0.9, 0.9, 1.0);
	    glRotatef(kakudo, 0, 0, 1);
        glTranslatef( -1.5, 0, -0.3);
        //glScalef(1.5, 1.5, 3);
        glutSolidSphere(0.2, 10, 10);
        glPopMatrix();

		/*
	    glPushMatrix();
	    glColor3f( 0.9, 0.9, 1.0);
	    glRotatef(kakudo, 0, 0, 1);
        glTranslatef( -0.4, 0, 1.0);
        //glScalef(1.5, 1.5, 3);
        glutSolidSphere(0.1, 10, 10);
        glPopMatrix();
		*/

        glPushMatrix();
        //diffuse[0] = 1; diffuse[1] = 1; diffuse[2] = 0;
        //glMaterialfv(GL_FRONT,GL_DIFFUSE  , diffuse);
	    glColor3f( 0.9, 0.9, 1.0);
		glRotatef(kakudo, 0, 0, 1);
        glTranslatef( -1.0, 0, 0);
        glScalef(0.4, 0.4, 2);
        glutSolidSphere(0.5, 10, 10);
        glPopMatrix();

	}

	glPopMatrix();
}



void GamePlay::ScoreBoard(){
	glPushMatrix();
	glColor3f( 0.1, 0.1, 0.1);
	glScalef(0.2, 0.2, 0.2);

	if(wall_count/10 == 1){ one((Road_Width+0.8)*5, (Road_Height-0.1)*5, 7.5);}
	else if(wall_count/10 == 2){ two((Road_Width+0.8)*5, (Road_Height-0.1)*5, 7.5);}
	else if(wall_count/10 == 3){ three((Road_Width+0.8)*5, (Road_Height-0.1)*5, 7.5);}
	else if(wall_count/10 == 4){ four((Road_Width+0.8)*5, (Road_Height-0.1)*5, 7.5);}
	else if(wall_count/10 == 5){ five((Road_Width+0.8)*5, (Road_Height-0.1)*5, 7.5);}
	else if(wall_count/10 == 6){ six((Road_Width+0.8)*5, (Road_Height-0.1)*5, 7.5);}
	else if(wall_count/10 == 7){ seven((Road_Width+0.8)*5, (Road_Height-0.1)*5, 7.5);}
	else if(wall_count/10 == 8){ eight((Road_Width+0.8)*5, (Road_Height-0.1)*5, 7.5);}
	else if(wall_count/10 == 9){ nine((Road_Width+0.8)*5, (Road_Height-0.1)*5, 7.5);}
	//else if(wall_count == 100) { one(-2, 10, 2); zero(1, 10, 2);}

    if(wall_count%10 == 1){ one((Road_Width+1.8)*5, (Road_Height-0.1)*5, 7.5);}
	else if(wall_count%10 == 2){ two((Road_Width+1.8)*5, (Road_Height-0.1)*5, 7.5);}
	else if(wall_count%10 == 3){ three((Road_Width+1.8)*5, (Road_Height-0.1)*5, 7.5);}
	else if(wall_count%10 == 4){ four((Road_Width+1.8)*5, (Road_Height-0.1)*5, 7.5);}
	else if(wall_count%10 == 5){ five((Road_Width+1.8)*5, (Road_Height-0.1)*5, 7.5);}
	else if(wall_count%10 == 6){ six((Road_Width+1.8)*5, (Road_Height-0.1)*5, 7.5);}
	else if(wall_count%10 == 7){ seven((Road_Width+1.8)*5, (Road_Height-0.1)*5, 7.5);}
	else if(wall_count%10 == 8){ eight((Road_Width+1.8)*5, (Road_Height-0.1)*5, 7.5);}
	else if(wall_count%10 == 9){ nine((Road_Width+1.8)*5, (Road_Height-0.1)*5, 7.5);}
    else if(wall_count%10 == 0){ zero((Road_Width+1.8)*5, (Road_Height-0.1)*5, 7.5);}

	//tenn(7, 10, 1);
	glPopMatrix();
}

void GamePlay::clash(int hp)
{
	HP = HP - 1;
	Mix_PlayChannel( -1,chunk2,0 );            // 効果音2再生
	if(HP == 0){
         y2 = y2 - 5;
		 z1 = z1 + 2;
		 gameover_Flg = true;
         ControlSound(L"data/se_mob04.wav");
		 //PlaySound(L"data/se_mob04.wav", NULL, SND_FILENAME|SND_ASYNC);
		 mizubashira_Flg = true;
		 Calibration_flg = false;
	}
}

void FreeGame(){
	//テクスチャオブジェクトの破棄
	delete texture1;
	delete texture2;
    delete texture3;
	delete texture4;
	delete texture5;
	delete texture6;
	delete texture7;
    delete texture_wn;
	/* 演奏停止 */
    Mix_HaltMusic();

    /* 読み込んだ曲を解放 */
    Mix_FreeMusic(music);
    Mix_FreeChunk(chunk);     // ロードした効果音1を開放
    Mix_FreeChunk(chunk2);    // ロードした効果音2を開放

	//ゲーム描画オフ
	g_GameDrawFlg = FALSE;
	//メインメニュー描画オン
	g_MainMenuDrawFlg = TRUE;
	//ゲーム初期化オフ
	gameinitFlg = FALSE;
	//水柱オフ	
	mizubashira_Flg = FALSE;
}

void GamePlay::Gamedisplay()
{
	static float InnerRad = 0;
	static float Darkness = 1;
	//LPCWSTR	SoundName = NULL;
	float OuterRad = 10;
	
	if(gameinitFlg != true){
		GameInit();

		//SoundInit();
		switch(rand()%3){
			case 0: 
				music = Mix_LoadMUS("data/BGM0.wav");
				break;
			case 1:
				music = Mix_LoadMUS("data/BGM1.wav");
				break;
			case 2:
				music = Mix_LoadMUS("data/BGM2.wav");
				break;
			default:
				break;
		}
		chunk = Mix_LoadWAV("data/se_mod01.wav");      // 効果音ファイル1をロード
        chunk2 = Mix_LoadWAV("data/se_mod05.wav");    // 効果音ファイル2をロード

		Mix_PlayMusic(music,-1);                 //演奏開始

		gameinitFlg = true;
	}


	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	
	gluLookAt(x1,y2,z1,      // 視点の位置
		       0,y2+5,2,     // 注視点
			  0,0,1);        // カメラの上方向ベクトル
	/*
	//トランジションモード	
	if(g_TransitionFlg){
		glPushMatrix();
			//glTranslatef(320,240,0);
			GameTransition(InnerRad, OuterRad);
		glPopMatrix();
		InnerRad = InnerRad+0.1;
		if(InnerRad > 5){
			g_TransitionFlg = false;
			InnerRad = 0;
		}
	}*/

	glEnable(GL_ALPHA_TEST);//アルファテスト開始
    //　テクスチャマッピング有効化
    glEnable(GL_TEXTURE_2D);
	//ここに描きたい物を書く．
	glEnable (GL_DEPTH_TEST);
    glMaterialfv(GL_FRONT,GL_DIFFUSE  , diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR , specular);
    glMaterialfv(GL_FRONT,GL_DIFFUSE  , ambient);
    glMaterialf(GL_FRONT,GL_SHININESS, shininess);


	//壁の種類ごとに描画＆衝突判定
	if(wall_number == T_WALL){
		//Wall::T_wall(0, ichi, 0);
		glColor3f( 0,1,1);
		g_pT_Wall->Draw(ichi);
	} else if(wall_number == X_WALL){
	    //Wall::X_wall(0, ichi, 0);
		glColor3f( 0,1,1);
		g_pX_Wall->Draw(ichi);
	} else if(wall_number == Y_WALL){
	    //Wall::Y_wall(0, ichi, 0);
		glColor3f( 0,1,1);
		g_pY_Wall->Draw(ichi);
	} else if(wall_number == H_WALL){
	    //Wall::H_wall(0, ichi, 0);
		glColor3f( 0,1,1);
		g_pH_Wall->Draw(ichi);
	} else if(wall_number == K_WALL){
	   // Wall::K_wall(0, ichi, 0);
		glColor3f( 0,1,1);
		g_pK_Wall->Draw(ichi);
	} else if(wall_number == V_WALL){
	   // Wall::V_wall(0, ichi, 0);
		glColor3f( 1,1,0);
		g_pV_Wall->Draw(ichi);
	} else if(wall_number == RKAGI_WALL){
	    //Wall::KagiR_wall(0, ichi, 0);
		glColor3f( 1,1,0);
		g_pRKagi_Wall->Draw(ichi);
	} else if(wall_number == LKAGI_WALL){
	    //Wall::KagiL_wall(0, ichi, 0);
		glColor3f( 1,1,0);
		g_pLKagi_Wall->Draw(ichi);
	} else if(wall_number == KUNE_WALL){
	    //Wall::Kune_wall(0, ichi, 0);
		glColor3f( 1,1,0);
		g_pKune_Wall->Draw(ichi);
	} else if(wall_number == RIKISHI_WALL){
	    //Wall::Rikishi_wall(0, ichi, 0);
		glColor3f( 1,1,0);
		g_pRikishi_Wall->Draw(ichi);
	} else if(wall_number == MANJI_WALL){
	    // Wall::Manji_wall(0, ichi, 0);
		glColor3f( 1,0,0);
		g_pManji_Wall->Draw(ichi);
	} else if(wall_number == GYAKUMANJI_WALL){
	    // Wall::GyakuManji_wall(0, ichi, 0);
		glColor3f( 1,0,0);
		g_pGyakuManji_Wall->Draw(ichi);
	} else if(wall_number == BASEBALL_WALL){
	    //Wall::Baseball_wall(0, ichi, 0);
		glColor3f( 1,0,0);
		g_pBaseball_Wall->Draw(ichi);
	} else if(wall_number == MONSTERBALL_WALL){
	    //Wall::Monsterball_wall(0, ichi, 0);
		glColor3f( 1,0,0);
		g_pMonsterBall_Wall->Draw(ichi);
	} else if(wall_number == MO_WALL){
		glColor3f( 1,0,0);
	    g_pMO_Wall->Draw(ichi);
	} else if(wall_number ==  ZI_WALL){
		glColor3f( 1,0,0);
	    g_pZI_Wall->Draw(ichi);
	} else if(wall_number == O_WALL){
		glColor3f( 1,0,0);
	    g_pO_Wall->Draw(ichi);
	}
/*	} else if(wall_number == 14){
		r = r + 0.05;
		movewall_ichi = 1.5*sin(r);
	    Wall::Move_wall(0, ichi, 0, movewall_ichi);
	}*/

	//空＆草原＆池描画
	Sky();

	//壁描画
	Kabe();
	//道描画
	Road();
	//棒人間を描画（引数は壁ごとの当たり判定として使う）
	g_pBNG->Update(wall_number);


	if(mizubashira_Flg == true){
		g_PlayBGMFlg = FALSE;
		g_EndTransitionFlg = TRUE;
		//mizubashira();
		//効果音が鳴り終わったらトランジション準備
		if(!g_SoundFlg){
			//終了トランジションの準備
			g_EndTransitionFlg = FALSE;
			g_StartTransitionFlg = TRUE;
			FreeGame();
		}

	}

	//トランジションモード	
	if(g_StartTransitionFlg){
		Game_DecrementDarkTransition(&Darkness);
		if(Darkness <= 0){
		g_StartTransitionFlg = FALSE;
		Darkness = 0;
	    }
	}
	else if(g_EndTransitionFlg){
		Game_IncrementDarkTransition(&Darkness);
	}

	glPopMatrix();

	glDisable (GL_LIGHTING);
	glDisable (GL_DEPTH_TEST);
	//　テクスチャマッピング無効化
    glDisable(GL_TEXTURE_2D);
	glDisable(GL_ALPHA_TEST);//アルファテスト終了

	//glFlush();
	//ichi=ichi-0.1;
	//if(ichi < 0) ichi = 20;

	glutSwapBuffers();
}

void GamePlay::GameInit()
{
	
	int width = GL_WIN_SIZE_X, height = GL_WIN_SIZE_Y;
	float aspect = (float) width / (float) height;

 	//視点の位置　初期化
     x1=0;
	 y2=-4;
	 z1=2;   
	//HP初期化
	 HP = 3;
	 //キャリブレーションフラグたてる
	 Calibration_flg = TRUE;
	 //トランジションフラグを立てる
	 g_StartTransitionFlg = TRUE;
	 //壁のカウント初期化
	 wall_count = 0;

	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA);

	//glutCreateWindow("もじもじ君");

	glClearColor ( 0.0, 0.0, 0.0, 0.0 );

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 45.0, aspect, 0.1, 40.0 );
	glMatrixMode( GL_MODELVIEW );
	glEnable(GL_LIGHT0);
	
	//テクスチャのロード
	//texture1.Load("kira1.bmp");
	texture1 = new BMP("data/skysample.bmp");
	texture2 = new BMP("data/rengasample.bmp");
    texture3 = new BMP("data/stonesample.bmp");
	texture4 = new BMP("data/greensample.bmp");
	texture5 = new BMP("data/heart.bmp");
	texture6 = new BMP("data/OK.bmp");
	texture7 = new BMP("data/OUT.bmp");
    texture_wn = new BMP("data/wood_n.bmp");

    //乱数の初期化
	srand((unsigned int)time(NULL));
	wall_number = rand() % 3;

	//難易度で壁のスピードを変える
	if(g_GAMELEVEL == EASY) speed = 0.1;
	if(g_GAMELEVEL == NORMAL) speed = 0.13;
	if(g_GAMELEVEL == HARD) speed = 0.16;

	//glutTimerFunc(WAIT_TIME, update, 0);
}

void GamePlay::game_update()
{	
	if(Calibration_flg){
	    ichi = ichi - speed;
	    if(ichi < 0){
		    ichi = Road_Length;
		    if(!ALLisPass){
		        clash(HP);
		    } else{
				Mix_PlayChannel( -1,chunk,0 );            // 効果音1再生
			}
		    wall_count = wall_count+1;
			if(speed < 1.5){
			    if(wall_count%5 == 0 && wall_count != 0){
					speed = speed + 0.03;
					if(g_GAMELEVEL == NORMAL) g_GAMELEVEL = HARD;
					if(g_GAMELEVEL == EASY) g_GAMELEVEL = NORMAL;
			    }
		    }
			//も→じ→おの順に表示させたいのでここはランダムじゃない
			if(wall_number == MO_WALL){
				wall_number = ZI_WALL;
			}
			else if(wall_number == ZI_WALL){
				wall_number = O_WALL;
			}
			else{
				do{
					if(g_GAMELEVEL == EASY) wall_number = rand() % 5;
					if(g_GAMELEVEL == NORMAL) wall_number = rand() % 10;
					if(g_GAMELEVEL == HARD) wall_number = rand() % 15;
				}while( (wall_number == ZI_WALL) ||(wall_number == O_WALL) );
			}
			//wall_number = O_WALL;
			//HP = 3;
	    }
	}
}
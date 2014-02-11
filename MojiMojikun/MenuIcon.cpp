//#include "MenuIcon.h"
#include "XnVDepthMessage.h"
#include "Common.h"
#include <XnVHandPointContext.h>

#include <glut.h>

#define POINT_DEPTH -3

MenuIcon::MenuIcon(XnUInt32 nHistory, xn::DepthGenerator depthGenerator) :
	m_nHistorySize(nHistory), m_DepthGenerator(depthGenerator)
{
	m_pfPositionBuffer = new XnFloat[nHistory*3];
}


MenuIcon::~MenuIcon(void)
{
	std::map< XnUInt32, std::list<XnPoint3D> >::iterator iter;
	for(iter = m_History.begin(); iter != m_History.end(); ++iter){
		iter->second.clear();
	}
	m_History.clear();

	delete []m_pfPositionBuffer;
}

//ユーザーID登録
void MenuIcon::SetUserID( XnUserID userid ){
	UserID = userid;
}

static XnBool bShouldPrint = false;
// 最新の位置情報をm_Historyにぶちこむ
void MenuIcon::OnPointUpdate()
{
	XnSkeletonJointPosition JointPosition;
	skelton.GetSkeletonJointPosition(UserID, XN_SKEL_RIGHT_HAND, JointPosition);
	// positions are kept in projective coordinates, since they are only used for drawing
	XnPoint3D ptProjective(JointPosition.position);

	if (bShouldPrint)printf("Point (%f,%f,%f)", ptProjective.X, ptProjective.Y, ptProjective.Z);
	m_DepthGenerator.ConvertRealWorldToProjective(1, &ptProjective, &ptProjective);
	if (bShouldPrint)printf(" -> (%f,%f,%f)\n", ptProjective.X, ptProjective.Y, ptProjective.Z);

	// Add new position to the history buffer
	m_History[UserID].push_front(ptProjective);
	// Keep size of history buffer
	if (m_History[UserID].size() > m_nHistorySize)
		m_History[UserID].pop_back();
	bShouldPrint = false;
}


//StrとDesを誤差の差分が誤差の範囲内か見る
bool MenuIcon::ComparePosition( XnFloat Str, XnFloat Des, XnFloat EMargin ) const
{
	BOOL bRet = FALSE;
	XnFloat Deff = Str - Des;
	//差分が欲しいのでマイナスはプラスに変える
	if( Deff < 0 ){
		Deff = Deff*(-1);
	}
	//指定の誤差以内かどうかみる
	if( Deff < EMargin ){
		bRet = TRUE;
	}

	return bRet;
}
//選択中ゲージの表示
//選択完了までの進行を表す
void MenuIcon::DrawGage(int Current, int MaxBuf, float XPos, float YPos) const{
	float CurrentAngleMax = ((float)Current/MaxBuf)*360;
	float CurrentAngle = 0;
	float CurrentAnglePlus = 0;
	//音鳴り中のときは赤点滅
	if( g_SoundFlg ){
		for(int i=0; i < CurrentAngleMax; i++){
			CurrentAngle = (-i+90)*PI/180;
			CurrentAnglePlus = ((-i-10)+90)*PI/180;
			glPushMatrix();
			glTranslatef(XPos, YPos, -1);
			//glDepthMask(GL_FALSE);
			glEnable(GL_BLEND);
			//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glBegin( GL_POLYGON );
				glColor4f(0.5 + 0.5 * sin((float)g_Count*2), 0, 0, 1.0);         
				glVertex3f( 33*cos(CurrentAngle), 33*sin(CurrentAngle), 0);  //左上
				glVertex3f( 24*cos(CurrentAngle), 24*sin(CurrentAngle), 0);	 //左下
				glVertex3f( 33*cos(CurrentAnglePlus), 33*sin(CurrentAnglePlus), 0); //右下
				glVertex3f( 24*cos(CurrentAnglePlus), 24*sin(CurrentAnglePlus), 0);	//右上
			glEnd();
			glDisable(GL_BLEND);
			//glDepthMask(GL_TRUE);
			glPopMatrix();
		}
	}
	else {
		for(int i=0; i < CurrentAngleMax; i++){
		CurrentAngle = (-i+90)*PI/180;
		CurrentAnglePlus = ((-i-10)+90)*PI/180;
		glPushMatrix();
		glTranslatef(XPos, YPos, -1);
		//glDepthMask(GL_FALSE);
		glEnable(GL_BLEND);
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBegin( GL_POLYGON );
			glColor4f(0, 1.0, 0, 1.0);         
			glVertex3f( 33*cos(CurrentAngle), 33*sin(CurrentAngle), 0);  //左上
			glVertex3f( 24*cos(CurrentAngle), 24*sin(CurrentAngle), 0);	 //左下
			glVertex3f( 33*cos(CurrentAnglePlus), 33*sin(CurrentAnglePlus), 0); //右下
			glVertex3f( 24*cos(CurrentAnglePlus), 24*sin(CurrentAnglePlus), 0);	//右上
		glEnd();
		glDisable(GL_BLEND);
		//glDepthMask(GL_TRUE);
		glPopMatrix();
		}
	}

}

#define ERROR_MARGIN 3
bool MenuIcon::SelectMenu(int MaxBuf, float XPos, float YPos) const
{
	int		i = 0;
	BOOL	bRet = TRUE;
	XnFloat	EMargin = ERROR_MARGIN;	
	//m_pfPositionBufferを比較
	//誤差範囲内ならフラグをたてる
	for( ; i*3+2 < (MaxBuf-1); i++ ){
		if( ComparePosition(m_pfPositionBuffer[3*i], m_pfPositionBuffer[3*i+3], EMargin) ){
				if( ComparePosition(m_pfPositionBuffer[3*i+1], m_pfPositionBuffer[3*i+4], EMargin) ){
					//ずれがなければforを回し続ける
					continue;
				}
		}
		//ずれたらブレーク
		bRet = FALSE;
		break;
	}
	int i3 = i*3;
	//選択中ゲージを表示
	DrawGage(i3, MaxBuf, XPos, YPos);

	return bRet;
}



//アイコンにテクスチャを張る
void MenuIcon::DrawIconTexture(float Xpos, float Ypos){

	float Ambient[4]  = {0.9,1.0,0.9,1.0};
	float Diffuse[4]  = {0.9,1.0,0.9,1.0};
	float Specular[4] = {0.9,0.9,0.9,1.0};
	float Light[4]    = {0, 0, 3, 1};
	if( g_TrackHandFlg && !g_OKFlg ){
		glEnable(GL_DEPTH_TEST);
		glPushMatrix();
		glTranslatef(Xpos, Ypos, 0);
		g_pPointTexture->TexSet();
		//glBindTexture(GL_TEXTURE_2D, g_pPointTexture->texture);
		glBegin( GL_POLYGON );
			glColor3f(1.0, 1.0, 1.0);
			for(int i = 0; i < 360; i++){
				float angle = i*PI/180;
				glTexCoord2d( 0.3*cos(angle)+0.5, 0.3*sin(angle)+0.5 );
				glVertex3f( 25*cos(angle), 25*sin(angle), POINT_DEPTH );
			}

		glEnd();
		glPopMatrix();

		g_pPointTexture->DeleteTex();
		glDisable(GL_DEPTH_TEST);
	}
}

//アイコンを画面に描画
void MenuIcon::DrawMenuIcon() 
{
	//HistoryBufferはg_3DHiBufSizeの三倍の値なので三倍してSelectMenuに渡す
	float MaxBufSize = 3*g_3DHisBufSize;
	std::map<XnUInt32, std::list<XnPoint3D> >::const_iterator PointIterator;
	glEnable(GL_DEPTH_TEST);
	// Go over each existing hand
	for (PointIterator = m_History.begin();
		PointIterator != m_History.end();
		++PointIterator)
	{
		// Clear buffer
		XnUInt32 nPoints = 0;
		XnUInt32 i = 0;
		XnUInt32 Id = PointIterator->first;

		// Go over all previous positions of current hand
		//
		std::list<XnPoint3D>::const_iterator PositionIterator;
		for (PositionIterator = PointIterator->second.begin();
			PositionIterator != PointIterator->second.end();
			++PositionIterator, ++i)
		{
			// Add position to buffer
			XnPoint3D pt(*PositionIterator);
			m_pfPositionBuffer[3*i]		= pt.X;
			m_pfPositionBuffer[3*i + 1] = MirrorYposition(pt.Y, GL_WIN_SIZE_Y);
			m_pfPositionBuffer[3*i + 2] = -10;//pt.Z();
		}
		
		//手を一定の位置で止めているかどうか（メニューを選択しているかどうか）チェック
		if( !g_MoveModeFlg1 || !g_MoveModeFlg2 ){
			if( (g_pMI_Start->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE) || (g_pMI_Level->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE) ||
				(g_pMI_PlayNum->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE) || (g_pMI_Level_Hard->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE) ||
				(g_pMI_Level_Normal->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE) || (g_pMI_Level_Easy->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE) ||
				(g_pMI_PlayNum_One->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE) || (g_pMI_PlayNum_Two->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE) ||
				(g_pMI_Exit->PointOnItem(g_pMenuIcon->GetPositionBuffer()) != FALSE) ){

					if( g_StartTransitionFlg ){
						g_SelectFlg = FALSE;
					}
					else if( SelectMenu( MaxBufSize,  m_pfPositionBuffer[0], m_pfPositionBuffer[1]) ){
						g_SelectFlg = TRUE;	
					}
					else{
						g_SelectFlg = FALSE;
					}
			}
		}
		if( g_SoundFlg && !g_OKFlg ){
			//音鳴り中だったらゲージを赤点滅させる
			DrawGage( MaxBufSize, MaxBufSize, m_pfPositionBuffer[0], m_pfPositionBuffer[1]);
		}
		

		DrawIconTexture(m_pfPositionBuffer[0], m_pfPositionBuffer[1]);
	}
	glDisable(GL_DEPTH_TEST);
}

// 情報の更新。1フレームごとに呼ばれる
void MenuIcon::Update()
{
	//アイコン位置情報の取得
	OnPointUpdate();
	// アイコンの描画
	DrawMenuIcon();
}

//バッファの位置情報を取得
XnFloat* MenuIcon::GetPositionBuffer()
{
	return m_pfPositionBuffer;
}
/*

void glPrintString(void *font, char *str)
{
	int i,l = strlen(str);

	for(i=0; i<l; i++)
	{
		glutBitmapCharacter(font,*str++);
	}
}

void PrintSessionState(SessionState eState)
{
	glColor4f(1,0,1,1);
	glRasterPos2i(20, 20);
	XnChar strLabel[200];

	switch (eState)
	{
	case IN_SESSION:
		sprintf(strLabel, "Tracking hands"); break;
	case NOT_IN_SESSION:
		sprintf(strLabel, "Perform click or wave gestures to track hand"); break;
	case QUICK_REFOCUS:
		sprintf(strLabel, "Raise your hand for it to be identified, or perform click or wave gestures"); break;
	}

	glPrintString(GLUT_BITMAP_HELVETICA_18, strLabel);
}*/
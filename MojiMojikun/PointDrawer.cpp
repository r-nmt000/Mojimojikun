/*******************************************************************************
*                                                                              *
*   PrimeSense NITE 1.3 - Point Viewer Sample                                  *
*   Copyright (C) 2010 PrimeSense Ltd.                                         *
*                                                                              *
*******************************************************************************/


#include "XnVDepthMessage.h"
#include "Common.h"
#include <XnVHandPointContext.h>

#include <glut.h>

#define POINT_DEPTH -3
/*ちっとはずしとく
#ifdef USE_GLUT
	#if (XN_PLATFORM == XN_PLATFORM_MACOSX)
		#include <GLUT/glut.h>
	#else
		#include <GL/glut.h>
	#endif
#elif defined(USE_GLES)
	#include "opengles.h"
#endif
*/
// Constructor. Receives the number of previous positions to store per hand,
// and a source for depth map
XnVPointDrawer::XnVPointDrawer(XnUInt32 nHistory, xn::DepthGenerator depthGenerator) :
	XnVPointControl("XnVPointDrawer"),
	m_nHistorySize(nHistory), m_DepthGenerator(depthGenerator), m_bDrawDM(false), m_bFrameID(false)
{
	m_pfPositionBuffer = new XnFloat[nHistory*3];
}

// Destructor. Clear all data structures
XnVPointDrawer::~XnVPointDrawer()
{
	std::map<XnUInt32, std::list<XnPoint3D> >::iterator iter;
	for (iter = m_History.begin(); iter != m_History.end(); ++iter)
	{
		iter->second.clear();
	}
	m_History.clear();

	delete []m_pfPositionBuffer;
}

// デプスマップの表示・非表示
void XnVPointDrawer::SetDepthMap(XnBool bDrawDM)
{
	m_bDrawDM = bDrawDM;
}
// フレームIDの表示・表示
void XnVPointDrawer::SetFrameID(XnBool bFrameID)
{
	m_bFrameID = bFrameID;
}

// Handle creation of a new hand
//手のトラッキングができたときフラグを立てる関数
static XnBool bShouldPrint = false;
void XnVPointDrawer::OnPointCreate(const XnVHandPointContext* cxt)
{
	printf("** %d\n", cxt->nID);
	// Create entry for the hand
	m_History[cxt->nID].clear();
	bShouldPrint = true;
	OnPointUpdate(cxt);
	bShouldPrint = true;
	//トラッキング完了
	g_TrackHandFlg = TRUE;
	g_OKFlg = TRUE;
}
// Handle new position of an existing hand
void XnVPointDrawer::OnPointUpdate(const XnVHandPointContext* cxt)
{
	// positions are kept in projective coordinates, since they are only used for drawing
	XnPoint3D ptProjective(cxt->ptPosition);

	if (bShouldPrint)printf("Point (%f,%f,%f)", ptProjective.X, ptProjective.Y, ptProjective.Z);
	m_DepthGenerator.ConvertRealWorldToProjective(1, &ptProjective, &ptProjective);
	if (bShouldPrint)printf(" -> (%f,%f,%f)\n", ptProjective.X, ptProjective.Y, ptProjective.Z);

	// Add new position to the history buffer
	m_History[cxt->nID].push_front(ptProjective);
	// Keep size of history buffer
	if (m_History[cxt->nID].size() > m_nHistorySize)
		m_History[cxt->nID].pop_back();
	bShouldPrint = false;
}

// Handle destruction of an existing hand
void XnVPointDrawer::OnPointDestroy(XnUInt32 nID)
{
	// No need for the history buffer
	m_History.erase(nID);
}

#define MAX_DEPTH 10000
float g_pDepthHist[MAX_DEPTH];
unsigned int getClosestPowerOfTwo(unsigned int n)
{
	unsigned int m = 2;
	while(m < n) m<<=1;

	return m;
}
GLuint initTexture(void** buf, int& width, int& height)
{
	GLuint texID = 0;
	glGenTextures(1,&texID);

	width = getClosestPowerOfTwo(width);
	height = getClosestPowerOfTwo(height); 
	*buf = new unsigned char[width*height*4];
	glBindTexture(GL_TEXTURE_2D,texID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return texID;
}

GLfloat texcoords[8];
void DrawRectangle(float topLeftX, float topLeftY, float bottomRightX, float bottomRightY)
{
	GLfloat verts[8] = {	topLeftX, topLeftY,
		topLeftX, bottomRightY,
		bottomRightX, bottomRightY,
		bottomRightX, topLeftY
	};
	glVertexPointer(2, GL_FLOAT, 0, verts);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	glFlush();
}
void DrawTexture(float topLeftX, float topLeftY, float bottomRightX, float bottomRightY)
{
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, texcoords);

	DrawRectangle(topLeftX, topLeftY, bottomRightX, bottomRightY);

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void DrawDepthMap(const xn::DepthMetaData& dm)
{
	static bool bInitialized = false;	
	static GLuint depthTexID;
	static unsigned char* pDepthTexBuf;
	static int texWidth, texHeight;

	 float topLeftX;
	 float topLeftY;
	 float bottomRightY;
	 float bottomRightX;
	float texXpos;
	float texYpos;

	if(!bInitialized)
	{
		XnUInt16 nXRes = dm.XRes();
		XnUInt16 nYRes = dm.YRes();
		texWidth =  getClosestPowerOfTwo(nXRes);
		texHeight = getClosestPowerOfTwo(nYRes);

		depthTexID = initTexture((void**)&pDepthTexBuf,texWidth, texHeight) ;

		bInitialized = true;

		topLeftX = nXRes;
		topLeftY = 0;
		bottomRightY = nYRes;
		bottomRightX = 0;
		texXpos =(float)nXRes/texWidth;
		texYpos  =(float)nYRes/texHeight;

		memset(texcoords, 0, 8*sizeof(float));
		texcoords[0] = texXpos, texcoords[1] = texYpos, texcoords[2] = texXpos, texcoords[7] = texYpos;

	}
	unsigned int nValue = 0;
	unsigned int nHistValue = 0;
	unsigned int nIndex = 0;
	unsigned int nX = 0;
	unsigned int nY = 0;
	unsigned int nNumberOfPoints = 0;
	XnUInt16 g_nXRes = dm.XRes();
	XnUInt16 g_nYRes = dm.YRes();

	unsigned char* pDestImage = pDepthTexBuf;

	const XnUInt16* pDepth = dm.Data();

	// Calculate the accumulative histogram
	memset(g_pDepthHist, 0, MAX_DEPTH*sizeof(float));
	for (nY=0; nY<g_nYRes; nY++)
	{
		for (nX=0; nX<g_nXRes; nX++)
		{
			nValue = *pDepth;

			if (nValue != 0)
			{
				g_pDepthHist[nValue]++;
				nNumberOfPoints++;
			}

			pDepth++;
		}
	}

	for (nIndex=1; nIndex<MAX_DEPTH; nIndex++)
	{
		g_pDepthHist[nIndex] += g_pDepthHist[nIndex-1];
	}
	if (nNumberOfPoints)
	{
		for (nIndex=1; nIndex<MAX_DEPTH; nIndex++)
		{
			g_pDepthHist[nIndex] = (unsigned int)(256 * (1.0f - (g_pDepthHist[nIndex] / nNumberOfPoints)));
		}
	}

	pDepth = dm.Data();
	{
		XnUInt32 nIndex = 0;
		// Prepare the texture map
		for (nY=0; nY<g_nYRes; nY++)
		{
			for (nX=0; nX < g_nXRes; nX++, nIndex++)
			{
				nValue = *pDepth;

				if (nValue != 0)
				{
					nHistValue = g_pDepthHist[nValue];

					pDestImage[0] = nHistValue; 
					pDestImage[1] = nHistValue;
					pDestImage[2] = nHistValue;
				}
				else
				{
					pDestImage[0] = 0;
					pDestImage[1] = 0;
					pDestImage[2] = 0;
				}

				pDepth++;
				pDestImage+=3;
			}

			pDestImage += (texWidth - g_nXRes) *3;
		}
	}
	glBindTexture(GL_TEXTURE_2D, depthTexID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, pDepthTexBuf);

	// Display the OpenGL texture map
	glColor4f(0.5,0.5,0.5,1);

	glEnable(GL_TEXTURE_2D);
	DrawTexture(dm.XRes(),dm.YRes(),0,0);	
	glDisable(GL_TEXTURE_2D);
}
#ifdef USE_GLUT
void glPrintString(void *font, char *str)
{
	int i,l = strlen(str);

	for(i=0; i<l; i++)
	{
		glutBitmapCharacter(font,*str++);
	}
}
void DrawFrameID(XnUInt32 nFrameID)
{
	glColor4f(1,0,0,1);
	glRasterPos2i(20, 50);
	XnChar strLabel[20];
	sprintf(strLabel, "%d", nFrameID);
	glPrintString(GLUT_BITMAP_HELVETICA_18, strLabel);
}
#endif

//StrとDesを誤差の差分が誤差の範囲内か見る
BOOL XnVPointDrawer::ComparePosition( XnFloat Str, XnFloat Des, XnFloat EMargin ) const
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
void XnVPointDrawer::DrawGage(int Current, int MaxBuf, float XPos, float YPos) const{
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
BOOL XnVPointDrawer::SelectMenu(int MaxBuf, float XPos, float YPos) const
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
// Colors for the points
XnFloat Colors[][3] =
{
	{1,0,0},	// Red
	{0,1,0},	// Green
	{0,0.5,1},	// Light blue
	{1,1,0},	// Yellow
	{1,0.5,0},	// Orange
	{1,0,1},	// Purple
	{1,1,1},	// White. reserved for the primary point
	{0,0,0}		// Black
};
XnUInt32 nColors = 7;

//y座標の反転
float MirrorYpos(float Ypos, float Hight){
	float fRet = 0;
	float Deff = Ypos - (Hight/2);
	
	fRet = (Hight/2) - Deff;
	return fRet;
}

//アイコンにテクスチャを張る
void DrawIcon(float Xpos, float Ypos){

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
void XnVPointDrawer::Draw() const
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
			m_pfPositionBuffer[3*i + 1] = MirrorYpos(pt.Y, GL_WIN_SIZE_Y);
			m_pfPositionBuffer[3*i + 2] = -10;//pt.Z();
		}


		// 色を設定。IDによって色を変える
		XnUInt32 nColor = Id % nColors;
		XnUInt32 nSingle = GetPrimaryID();
		if (Id == GetPrimaryID())
			nColor = 7;
		// アイコンの色を指定
		glColor4f(Colors[nColor][0],
				Colors[nColor][1],
				Colors[nColor][2],
				1.0f);	
		
		//手を一定の位置で止めているかどうか（メニューを選択しているかどうか）チェック
		if( !g_MoveModeFlg1 || !g_MoveModeFlg2 ){
			if( (g_pMI_Start->PointOnItem(g_pDrawer->GetPositionBuffer()) != FALSE) || (g_pMI_Level->PointOnItem(g_pDrawer->GetPositionBuffer()) != FALSE) ||
				(g_pMI_PlayNum->PointOnItem(g_pDrawer->GetPositionBuffer()) != FALSE) || (g_pMI_Level_Hard->PointOnItem(g_pDrawer->GetPositionBuffer()) != FALSE) ||
				(g_pMI_Level_Normal->PointOnItem(g_pDrawer->GetPositionBuffer()) != FALSE) || (g_pMI_Level_Easy->PointOnItem(g_pDrawer->GetPositionBuffer()) != FALSE) ||
				(g_pMI_PlayNum_One->PointOnItem(g_pDrawer->GetPositionBuffer()) != FALSE) || (g_pMI_PlayNum_Two->PointOnItem(g_pDrawer->GetPositionBuffer()) != FALSE) ){

					if( SelectMenu( MaxBufSize,  m_pfPositionBuffer[0], m_pfPositionBuffer[1]) ){
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
		
		//アイコンサイズを指定
		/*
		glPointSize(2);
		glVertexPointer(3, GL_FLOAT, 0, m_pfPositionBuffer);
		//軌跡の表示
		glDrawArrays(GL_LINE_STRIP, 0, i);
		//アイコンの表示
		glPointSize(8);
		glDrawArrays(GL_POINTS, 0, 1);
		glFlush();
		*/
		DrawIcon(m_pfPositionBuffer[0], m_pfPositionBuffer[1]);
	}
	glDisable(GL_DEPTH_TEST);
}

// 情報の更新。1フレームごとに呼ばれる
void XnVPointDrawer::Update(XnVMessage* pMessage)
{
	// 親クラスのUpdateを呼び出す
	XnVPointControl::Update(pMessage);

	// アイコンの描画
	Draw();
}

//バッファの位置情報を取得
XnFloat* XnVPointDrawer::GetPositionBuffer()
{
	return m_pfPositionBuffer;
}
#ifdef USE_GLUT
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
}


#endif

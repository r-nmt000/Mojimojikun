#pragma once
#include <stdlib.h>
#include <Windows.h>
#include "glut.h"
#include <math.h>
#include "XnVDepthMessage.h"
#include "NomoWall.h"

#define InValue 1000



class BouNinGen
{
public:
	BouNinGen(void);
	~BouNinGen(void);
	void		 Update(int i);
	void		 DrawBNG();
	void		 SetUserID(XnUserID UID);
	XnUserID	 GetUserID();
	void		 ConvertONItoGLPosition(XnPoint3D* ptProjective);
	void		 ExchangeYandZ(XnPoint3D* ptProjective);
	void		 SetPoint(BYTE pByte[][PICTURE_WIDTH]);
	XnPoint3D	 GetPoint(int XN_SKEL);
	BOOL		 JudgeCollision(BYTE pByte[][PICTURE_WIDTH], XnPoint3D* ptProjective);

private:
	//頭
	XnSkeletonJointPosition Edge_Head;
	//首
	XnSkeletonJointPosition Edge_Neck;
	//みぞおち
	XnSkeletonJointPosition Edge_Torso;
	//右肩
	XnSkeletonJointPosition Edge_RightShoulder;
	//右ひじ
	XnSkeletonJointPosition Edge_RightElbow;
	//右手
	XnSkeletonJointPosition Edge_RightHand;
	//左肩
	XnSkeletonJointPosition Edge_LeftShoulder;
	//左ひじ
	XnSkeletonJointPosition Edge_LeftElbow;
	//左手
	XnSkeletonJointPosition Edge_LeftHand;
	//右おしり
	XnSkeletonJointPosition Edge_RightHip;
	//右ひざ
	XnSkeletonJointPosition Edge_RightKnee;
	//右足
	XnSkeletonJointPosition Edge_RightFoot;
	//左おしり
	XnSkeletonJointPosition Edge_LeftHip;
	//左ひざ
	XnSkeletonJointPosition Edge_LeftKnee;
	//左足
	XnSkeletonJointPosition Edge_LeftFoot;

	//股
	//左しりと右しりの中央から算出
	XnSkeletonJointPosition Edge_Croch;

	//ユーザーID
	XnUserID m_UserID;
	//最初の変換かどうか判定するフラグ
	BOOL	FirstConvertFlg;
	//基準点
	XnFloat StandardX;
	XnFloat StandardY;
	XnFloat StandardZ;
	//移動差分
	XnFloat MoveX;
	XnFloat MoveY;
};

//----------------ローカル関数-------------------
float hypot3f( float x, float y, float z );
BOOL CompareCos( float cos, int i );
BOOL CompareSin( float sin, int i);
void Cylinder( XnSkeletonJointPosition Position1, XnSkeletonJointPosition Position2 );
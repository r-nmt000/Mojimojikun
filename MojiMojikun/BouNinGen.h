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
	//��
	XnSkeletonJointPosition Edge_Head;
	//��
	XnSkeletonJointPosition Edge_Neck;
	//�݂�����
	XnSkeletonJointPosition Edge_Torso;
	//�E��
	XnSkeletonJointPosition Edge_RightShoulder;
	//�E�Ђ�
	XnSkeletonJointPosition Edge_RightElbow;
	//�E��
	XnSkeletonJointPosition Edge_RightHand;
	//����
	XnSkeletonJointPosition Edge_LeftShoulder;
	//���Ђ�
	XnSkeletonJointPosition Edge_LeftElbow;
	//����
	XnSkeletonJointPosition Edge_LeftHand;
	//�E������
	XnSkeletonJointPosition Edge_RightHip;
	//�E�Ђ�
	XnSkeletonJointPosition Edge_RightKnee;
	//�E��
	XnSkeletonJointPosition Edge_RightFoot;
	//��������
	XnSkeletonJointPosition Edge_LeftHip;
	//���Ђ�
	XnSkeletonJointPosition Edge_LeftKnee;
	//����
	XnSkeletonJointPosition Edge_LeftFoot;

	//��
	//������ƉE����̒�������Z�o
	XnSkeletonJointPosition Edge_Croch;

	//���[�U�[ID
	XnUserID m_UserID;
	//�ŏ��̕ϊ����ǂ������肷��t���O
	BOOL	FirstConvertFlg;
	//��_
	XnFloat StandardX;
	XnFloat StandardY;
	XnFloat StandardZ;
	//�ړ�����
	XnFloat MoveX;
	XnFloat MoveY;
};

//----------------���[�J���֐�-------------------
float hypot3f( float x, float y, float z );
BOOL CompareCos( float cos, int i );
BOOL CompareSin( float sin, int i);
void Cylinder( XnSkeletonJointPosition Position1, XnSkeletonJointPosition Position2 );
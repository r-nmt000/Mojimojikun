#include "BouNinGen.h"
#include "common.h"




double CosToRad[360] = {1.00,0.99,0.99,0.99,0.99,0.99,0.99,0.99,0.99,0.98,
						0.98,0.98,0.97,0.97,0.97,0.96,0.96,0.95,0.95,0.94,
						0.93,0.93,0.92,0.92,0.91,0.90,0.89,0.89,0.88,0.87,
						0.86,0.85,0.84,0.83,0.82,0.81,0.80,0.79,0.78,0.77,
						0.76,0.75,0.74,0.73,0.71,0.70,0.69,0.68,0.67,0.66,
						0.64,0.63,0.62,0.60,0.59,0.57,0.56,0.54,0.53,0.51,
						0.50,0.48,0.47,0.45,0.44,0.42,0.40,0.39,0.37,0.36,
						0.34,0.33,0.31,0.29,0.27,0.25,0.24,0.22,0.21,0.19,
						0.17,0.16,0.14,0.12,0.10,0.09,0.07,0.05,0.03,0.01,
						0.0,										      //90
						-0.01,-0.03,-0.05,-0.07,-0.09,-0.10,-0.12,-0.14,-0.16,
						-0.17,-0.19,-0.21,-0.22,-0.24,-0.25,-0.27,-0.29,-0.31,-0.33,
						-0.34,-0.36,-0.37,-0.39,-0.40,-0.42,-0.44,-0.45,-0.47,-0.48,
						-0.50,-0.51,-0.53,-0.54,-0.56,-0.57,-0.59,-0.60,-0.62,-0.63,
						-0.64,-0.66,-0.67,-0.68,-0.69,-0.70,-0.71,-0.73,-0.74,-0.75,
						-0.76,-0.77,-0.78,-0.79,-0.80,-0.81,-0.82,-0.83,-0.84,-0.85,
						-0.86,-0.87,-0.88,-0.89,-0.89,-0.90,-0.91,-0.92,-0.92,-0.93,
						-0.93,-0.94,-0.95,-0.95,-0.96,-0.96,-0.97,-0.97,-0.97,-0.98,
						-0.98,-0.98,-0.99,-0.99,-0.99,-0.99,-0.99,-0.99,-0.99,-0.99,
						-1.00,
						-0.99,-0.99,-0.99,-0.99,-0.99,-0.99,-0.99,-0.99,-0.98,
						-0.98,-0.98,-0.97,-0.97,-0.97,-0.96,-0.96,-0.95,-0.95,-0.94,
						-0.93,-0.93,-0.92,-0.92,-0.91,-0.90,-0.89,-0.89,-0.88,-0.87,
						-0.86,-0.85,-0.84,-0.83,-0.82,-0.81,-0.80,-0.79,-0.78,-0.77,
						-0.76,-0.75,-0.74,-0.73,-0.71,-0.70,-0.69,-0.68,-0.67,-0.66,
						-0.64,-0.63,-0.62,-0.60,-0.59,-0.57,-0.56,-0.54,-0.53,-0.51,
						-0.50,-0.48,-0.47,-0.45,-0.44,-0.42,-0.40,-0.39,-0.37,-0.36,
						-0.34,-0.33,-0.31,-0.29,-0.27,-0.25,-0.24,-0.22,-0.21,-0.19,
						-0.17,-0.16,-0.14,-0.12,-0.10,-0.09,-0.07,-0.05,-0.03,-0.01,
						0.0,
						0.01,0.03,0.05,0.07,0.09,0.10,0.12,0.14,0.16,
						0.17,0.19,0.21,0.22,0.24,0.25,0.27,0.29,0.31,0.33,
						0.34,0.36,0.37,0.39,0.40,0.42,0.44,0.45,0.47,0.48,
						0.50,0.51,0.53,0.54,0.56,0.57,0.59,0.60,0.62,0.63,
						0.64,0.66,0.67,0.68,0.69,0.70,0.71,0.73,0.74,0.75,
						0.76,0.77,0.78,0.79,0.80,0.81,0.82,0.83,0.84,0.85,
						0.86,0.87,0.88,0.89,0.89,0.90,0.91,0.92,0.92,0.93,
						0.93,0.94,0.95,0.95,0.96,0.96,0.97,0.97,0.97,0.98,
						0.98,0.98,0.99,0.99,0.99,0.99,0.99,0.99,0.99,0.99
						};

double SinToRad[360] = {0.00,0.01,0.03,0.05,0.07,0.09,0.10,0.12,0.14,0.16,
						0.17,0.19,0.21,0.22,0.24,0.26,0.28,0.29,0.31,0.33,
						0.34,0.36,0.37,0.39,0.41,0.42,0.44,0.45,0.47,0.48,
						0.50,0.51,0.53,0.54,0.56,0.57,0.59,0.60,0.62,0.63,
						0.64,0.66,0.67,0.68,0.69,0.71,0.72,0.73,0.74,0.75,
						0.77,0.78,0.79,0.80,0.81,0.82,0.83,0.84,0.85,0.86,
						0.87,0.87,0.88,0.89,0.90,0.91,0.91,0.92,0.93,0.93,
						0.94,0.95,0.95,0.96,0.96,0.97,0.97,0.97,0.98,0.98,
						0.98,0.99,0.99,0.99,0.99,0.99,0.99,0.99,0.99,0.99,
						1.00,												//90
						0.99,0.99,0.99,0.99,0.99,0.99,0.99,0.99,0.99,
						0.98,0.98,0.98,0.97,0.97,0.97,0.96,0.96,0.95,0.95,
						0.94,0.93,0.93,0.91,0.91,0.92,0.89,0.90,0.87,0.88,
						0.87,0.86,0.85,0.84,0.83,0.82,0.81,0.80,0.79,0.78,
						0.77,0.75,0.74,0.73,0.72,0.71,0.69,0.68,0.67,0.66,
						0.64,0.63,0.62,0.60,0.59,0.57,0.56,0.54,0.53,0.51,
						0.50,0.48,0.47,0.45,0.44,0.42,0.41,0.39,0.37,0.36,
						0.34,0.33,0.31,0.29,0.28,0.26,0.24,0.22,0.21,0.19,
						0.17,0.16,0.14,0.12,0.10,0.09,0.07,0.05,0.03,0.01,
						0.00,												//180
						-0.01,-0.03,-0.05,-0.07,-0.09,-0.10,-0.12,-0.14,-0.16,
						-0.17,-0.19,-0.21,-0.22,-0.24,-0.26,-0.28,-0.29,-0.31,-0.33,
						-0.34,-0.36,-0.37,-0.39,-0.41,-0.42,-0.44,-0.45,-0.47,-0.48,
						-0.50,-0.51,-0.53,-0.54,-0.56,-0.57,-0.59,-0.60,-0.62,-0.63,
						-0.64,-0.66,-0.67,-0.68,-0.69,-0.71,-0.72,-0.73,-0.74,-0.75,
						-0.77,-0.78,-0.79,-0.80,-0.81,-0.82,-0.83,-0.84,-0.85,-0.86,
						-0.87,-0.87,-0.88,-0.89,-0.90,-0.91,-0.91,-0.92,-0.93,-0.93,
						-0.94,-0.95,-0.95,-0.96,-0.96,-0.97,-0.97,-0.97,-0.98,-0.98,
						-0.98,-0.99,-0.99,-0.99,-0.99,-0.99,-0.99,-0.99,-0.99,-0.99,
						-1.00,												//270
						-0.99,-0.99,-0.99,-0.99,-0.99,-0.99,-0.99,-0.99,-0.99,
						-0.98,-0.98,-0.98,-0.97,-0.97,-0.97,-0.96,-0.96,-0.95,-0.95,
						-0.94,-0.93,-0.93,-0.91,-0.91,-0.92,-0.89,-0.90,-0.87,-0.88,
						-0.87,-0.86,-0.85,-0.84,-0.83,-0.82,-0.81,-0.80,-0.79,-0.78,
						-0.77,-0.75,-0.74,-0.73,-0.72,-0.71,-0.69,-0.68,-0.67,-0.66,
						-0.64,-0.63,-0.62,-0.60,-0.59,-0.57,-0.56,-0.54,-0.53,-0.51,
						-0.50,-0.48,-0.47,-0.45,-0.44,-0.42,-0.41,-0.39,-0.37,-0.36,
						-0.34,-0.33,-0.31,-0.29,-0.28,-0.26,-0.24,-0.22,-0.21,-0.19,
						-0.17,-0.16,-0.14,-0.12,-0.10,-0.09,-0.07,-0.05,-0.03,-0.01
						};



//-----------------�N���X�_�l�Ԃ̃����o�֐�--------------------
BouNinGen::BouNinGen(void)
{
	XnPoint3D ptProjective[16] ={
									{0		,1	,2.5},//��
									{0		,1	,2.2},//��
									{0		,1	,1.7},//�݂�����
									{0.3	,1	,2.0},//�E��
									{0.7	,1	,1.7},//�E�Ђ�
									{1.0	,1	,1.3},//�E��
									{-0.3	,1	,2.0},//����
									{-0.7	,1	,1.7},//���Ђ�
									{-1.0	,1	,1.3},//����
									{0.3	,1	,1.3},//�E����
									{0.7	,1	,0.8},//�E�Ђ�
									{0.7	,1	,0.2},//�E��
									{-0.3	,1	,1.3},//������
									{-0.7	,1	,0.8},//���Ђ�
									{-0.7	,1	,0.2},//����

									{0		,1	,1.3} //��
	};

	Edge_Head.position			= ptProjective[0];
	Edge_Neck.position			= ptProjective[1];
	Edge_Torso.position			= ptProjective[2];
	Edge_RightShoulder.position = ptProjective[3];
	Edge_RightElbow.position	= ptProjective[4];
	Edge_RightHand.position		= ptProjective[5];
	Edge_LeftShoulder.position	= ptProjective[6];
	Edge_LeftElbow.position		= ptProjective[7];
	Edge_LeftHand.position		= ptProjective[8];
	Edge_RightHip.position		= ptProjective[9];
	Edge_RightKnee.position		= ptProjective[10];
	Edge_RightFoot.position		= ptProjective[11];
	Edge_LeftHip.position		= ptProjective[12];
	Edge_LeftKnee.position		= ptProjective[13];
	Edge_LeftFoot.position		= ptProjective[14];
	Edge_Croch.position			= ptProjective[15];

	FirstConvertFlg = TRUE;
	StandardX = 0;
	StandardY = 2.2;
}


BouNinGen::~BouNinGen(void)
{
}




void BouNinGen::Update(int i/*BYTE pByte[][PICTURE_WIDTH]*/){
	switch(i){
		case T_WALL:
			SetPoint(g_pT_Wall->pByte);
			break;
		case X_WALL:
			SetPoint(g_pX_Wall->pByte);
			break;
		case Y_WALL:
			SetPoint(g_pY_Wall->pByte);
			break;
		case H_WALL:
			SetPoint(g_pH_Wall->pByte);
			break;
		case K_WALL:
			SetPoint(g_pK_Wall->pByte);
			break;
		case V_WALL:
			SetPoint(g_pV_Wall->pByte);
			break;
		case RKAGI_WALL:
			SetPoint(g_pRKagi_Wall->pByte);
			break;
		case LKAGI_WALL:
			SetPoint(g_pLKagi_Wall->pByte);
			break;
		case KUNE_WALL:
			SetPoint(g_pKune_Wall->pByte);
			break;
		case RIKISHI_WALL:
			SetPoint(g_pRikishi_Wall->pByte);
			break;
		case MANJI_WALL:
			SetPoint(g_pManji_Wall->pByte);
			break;
		case GYAKUMANJI_WALL:
			SetPoint(g_pGyakuManji_Wall->pByte);
			break;
		case BASEBALL_WALL:
			SetPoint(g_pBaseball_Wall->pByte);
			break;
		case MONSTERBALL_WALL:
			SetPoint(g_pMonsterBall_Wall->pByte);
			break;
		case MO_WALL:
			SetPoint(g_pMO_Wall->pByte);
			break;
		case ZI_WALL:
			SetPoint(g_pZI_Wall->pByte);
			break;
		case O_WALL:
			SetPoint(g_pO_Wall->pByte);
			break;
		default:
			break;

	}
	DrawBNG();
}
void BouNinGen::DrawBNG(){
	float ambient []={0.0,0.0,0.0,1.0};
	float diffuse[]={0.0,0.0,0.0,1};
	float specular []={1,1,1,1.0};
	float shininess = 30.0;
    float light[] = { 0,0.5,1, 1};
	glEnable (GL_DEPTH_TEST);
		glEnable(GL_LIGHT0);
    		glEnable(GL_LIGHTING);
	    		glMaterialfv(GL_FRONT,GL_DIFFUSE  , diffuse);
    			glMaterialfv(GL_FRONT,GL_SPECULAR , specular);
    			glMaterialfv(GL_FRONT,GL_AMBIENT  , ambient);
    			glMaterialf(GL_FRONT,GL_SHININESS, shininess);
				glLightfv(GL_LIGHT0, GL_POSITION, light);
				//��
				glPushMatrix();
				glTranslatef(Edge_Head.position.X, 1, Edge_Head.position.Z);
       	        glutSolidSphere(0.2,50,50);
				glPopMatrix();
				//���̏�
       	        Cylinder(Edge_Neck, Edge_Torso);
				//���̉�
				Cylinder(Edge_Torso, Edge_Croch);
				//�E�r��
				Cylinder(Edge_RightShoulder, Edge_RightElbow);
				//�E�r��
				Cylinder(Edge_RightElbow,Edge_RightHand);
				//���r��
				Cylinder(Edge_LeftShoulder, Edge_LeftElbow);
				//���r��
				Cylinder(Edge_LeftElbow, Edge_LeftHand);
				//�E����
				Cylinder(Edge_RightHip, Edge_RightKnee);
				//�E����
				Cylinder(Edge_RightKnee, Edge_RightFoot);
				//������
				Cylinder(Edge_LeftHip, Edge_LeftKnee);
				//������
				Cylinder(Edge_LeftKnee, Edge_LeftFoot);
				
	        glDisable (GL_LIGHT0);
		glDisable (GL_LIGHTING);
	glDisable (GL_DEPTH_TEST);
	glFlush();
}

void BouNinGen::ConvertONItoGLPosition(XnPoint3D* ptProjective){


	for(int i=0; i<15; i++){
		//�k�߂�
		ptProjective[i].X = ptProjective[i].X/170.0;
		ptProjective[i].Y = ptProjective[i].Y/170.0;
		//ptProjective[i].Z = ptProjective[i].Z/10.0;
		//��_�ֈړ����邽�߂̍������v�Z����
		
		if(FirstConvertFlg){
			MoveX = ptProjective[0].X - StandardX;
			MoveY = ptProjective[0].Y - StandardY;
			FirstConvertFlg = FALSE;
		}
		
		//������ƂȂ�ʒu�ɂ���悤�ɑ̑S�̂𕽍s�ړ�������
		
		ptProjective[i].X = ptProjective[i].X-MoveX;
		ptProjective[i].Y = ptProjective[i].Y-MoveY;
		//ptProjective[i].Z = ptProjective[i].Z-MoveZ;
		
	}

}

void BouNinGen::ExchangeYandZ(XnPoint3D* ptProjective){
	XnFloat Temp = 0;
	for(int i=0; i<15; i++){
		ptProjective[i].Z = ptProjective[i].Y;
		ptProjective[i].Y = 1;
	}
}

void BouNinGen::SetUserID( XnUserID UID ){
	m_UserID = UID;
}

XnUserID BouNinGen::GetUserID(){
	return m_UserID;
}
void BouNinGen::SetPoint(BYTE pByte[][PICTURE_WIDTH]){
	
	XnUserID UserID = GetUserID();
	//�e�p�[�c�̍��W���擾
	skelton.GetSkeletonJointPosition(UserID, XN_SKEL_HEAD			, Edge_Head);
	skelton.GetSkeletonJointPosition(UserID, XN_SKEL_NECK			, Edge_Neck);
	skelton.GetSkeletonJointPosition(UserID, XN_SKEL_TORSO			, Edge_Torso);
	skelton.GetSkeletonJointPosition(UserID, XN_SKEL_RIGHT_SHOULDER	, Edge_RightShoulder);
	skelton.GetSkeletonJointPosition(UserID, XN_SKEL_RIGHT_ELBOW	, Edge_RightElbow);
	skelton.GetSkeletonJointPosition(UserID, XN_SKEL_RIGHT_HAND		, Edge_RightHand);
	skelton.GetSkeletonJointPosition(UserID, XN_SKEL_LEFT_SHOULDER	, Edge_LeftShoulder);
	skelton.GetSkeletonJointPosition(UserID, XN_SKEL_LEFT_ELBOW		, Edge_LeftElbow);
	skelton.GetSkeletonJointPosition(UserID, XN_SKEL_LEFT_HAND		, Edge_LeftHand);
	skelton.GetSkeletonJointPosition(UserID, XN_SKEL_RIGHT_HIP		, Edge_RightHip);
	skelton.GetSkeletonJointPosition(UserID, XN_SKEL_LEFT_KNEE		, Edge_RightKnee);
	skelton.GetSkeletonJointPosition(UserID, XN_SKEL_LEFT_FOOT		, Edge_RightFoot);
	skelton.GetSkeletonJointPosition(UserID, XN_SKEL_RIGHT_HIP		, Edge_LeftHip);
	skelton.GetSkeletonJointPosition(UserID, XN_SKEL_RIGHT_KNEE		, Edge_LeftKnee);
	skelton.GetSkeletonJointPosition(UserID, XN_SKEL_RIGHT_FOOT		, Edge_LeftFoot);

	XnPoint3D ptProjective[15] = { 	Edge_Head.position,			
									Edge_Neck.position,		
									Edge_Torso.position,			
									Edge_RightShoulder.position, 
									Edge_RightElbow.position,	
									Edge_RightHand.position,		
									Edge_LeftShoulder.position,	
									Edge_LeftElbow.position,		
									Edge_LeftHand.position,		
									Edge_RightHip.position,		
									Edge_RightKnee.position	,	
									Edge_RightFoot.position,		
									Edge_LeftHip.position,		
									Edge_LeftKnee.position,		
									Edge_LeftFoot.position
	};
	//���W��ϊ�
	g_DepthGenerator.ConvertRealWorldToProjective(15, ptProjective, ptProjective);
	//���ˉe�̍��W����Փ˔��肵�����̂�
	//�����ŏՓ˔����������Ⴄ
	ALLisPass = JudgeCollision(pByte, ptProjective);
	//Y���W��␳
	for(int i=0; i < 15; i++){
		ptProjective[i].Y = MirrorYposition(ptProjective[i].Y, GL_WIN_SIZE_Y);
	}
	//���ˉe���瓧���@�ˉe�֕ϊ�
	ConvertONItoGLPosition(ptProjective);
	//Y��Z�����ւ��AY�𖳌��ɂ���
	ExchangeYandZ(ptProjective);
	//������Ȃ���
	Edge_Head.position			= ptProjective[0];
	Edge_Neck.position			= ptProjective[1];
	Edge_Torso.position			= ptProjective[2];
	Edge_RightShoulder.position = ptProjective[3];
	Edge_RightElbow.position	= ptProjective[4];
	Edge_RightHand.position		= ptProjective[5];
	Edge_LeftShoulder.position	= ptProjective[6];
	Edge_LeftElbow.position		= ptProjective[7];
	Edge_LeftHand.position		= ptProjective[8];
	Edge_RightHip.position		= ptProjective[9];
	Edge_RightKnee.position		= ptProjective[10];
	Edge_RightFoot.position		= ptProjective[11];
	Edge_LeftHip.position		= ptProjective[12];
	Edge_LeftKnee.position		= ptProjective[13];
	Edge_LeftFoot.position		= ptProjective[14];

	//�҂̈ʒu�͂����肩��Z�o
	Edge_Croch.position.X = (ptProjective[9].X+ptProjective[12].X)/2;
	Edge_Croch.position.Y = (ptProjective[9].Y+ptProjective[12].Y)/2;
	Edge_Croch.position.Z = (ptProjective[9].Z+ptProjective[12].Z)/2;
}
XnPoint3D BouNinGen::GetPoint(int XN_SKEL){
	XnPoint3D pt;
	return pt;
}



BOOL BouNinGen::JudgeCollision(BYTE pByte[][PICTURE_WIDTH], XnPoint3D* ptProjective){
	BOOL bRet = FALSE;

	if(pByte[(int)ptProjective[0].Y][(int)ptProjective[0].X] == 0)if(pByte[(int)ptProjective[1].Y][(int)ptProjective[1].X] == 0){
		if(pByte[(int)ptProjective[2].Y][(int)ptProjective[2].X] == 0)if(pByte[(int)ptProjective[3].Y][(int)ptProjective[3].X] == 0){
			if(pByte[(int)ptProjective[4].Y][(int)ptProjective[4].X] == 0)if(pByte[(int)ptProjective[5].Y][(int)ptProjective[5].X] == 0){
				if(pByte[(int)ptProjective[6].Y][(int)ptProjective[6].X] == 0)if(pByte[(int)ptProjective[7].Y][(int)ptProjective[7].X] == 0){
					if(pByte[(int)ptProjective[8].Y][(int)ptProjective[8].X] == 0)if(pByte[(int)ptProjective[9].Y][(int)ptProjective[9].X] == 0){
						if(pByte[(int)ptProjective[10].Y][(int)ptProjective[10].X] == 0){//if(pByte[(int)ptProjective[11].Y][(int)ptProjective[11].X] == 0){
							if(pByte[(int)ptProjective[12].Y][(int)ptProjective[12].X] == 0)if(pByte[(int)ptProjective[13].Y][(int)ptProjective[13].X] == 0){
								//if(pByte[(int)ptProjective[14].Y][(int)ptProjective[14].X] == 0){
									bRet = TRUE;
								//}
							}
						}
					}
				}
			}
		}
	}
	return bRet;
}
//-------------------------------------------------------------



//----------------���[�J���֐�-------------------
float hypot3f( float x, float y, float z ){
	float FRet;
	
	//�Q����v�Z
	x = x*x;
	y = y*y;
	z = z*z;
	//���������v�Z
	FRet = sqrtf(x+y+z);
	return FRet;
}

BOOL CompareCos( float cos, int i ){
	int bRet = FALSE;
	double Ans = CosToRad[i] - cos;
	if( (-0.015 <= Ans) && (Ans < 0.015) ){
		bRet = TRUE;
	}
	return bRet;
}
BOOL CompareSin( float sin, int i){
	int bRet = FALSE;
	double Ans = SinToRad[i] - sin;
	if( (-0.015 <= Ans) && (Ans < 0.015) ){
		bRet = TRUE;
	}
	return bRet;
}
void Cylinder( /*�㑤*/XnSkeletonJointPosition Position1, /*����*/XnSkeletonJointPosition Position2 ){
	float Edge1[3] = {Position1.position.X,Position1.position.Y,Position1.position.Z};
	float Edge2[3] = {Position2.position.X,Position2.position.Y,Position2.position.Z};
	float i;
	float pi = 3.1415;
	//�p�x
	float t;
	//���a
	float Rad = 0.05;
	//�Q�_�̍��� 2�_�����ԃx�N�g��
	float Deff[3] = {Edge2[0]-Edge1[0], Edge2[1]-Edge1[1], Edge2[2]-Edge1[2]};
	//�Q�_�Ԃ̋���
	float Length = hypot3f(Deff[0],Deff[1],Deff[2]);
	//Edge1����x,y,z���W
	float x1,y1,z1 = 0;
	//Edge2����x,y,z���W
	float x2,y2,z2 = 0;

	//y���𒆐S�ɃӉ�]�����]
	float seeta = InValue;
	//x���𒆐S�ɃƉ�]�����]
	float fai = InValue;
	//x���𒆐S�ɃƉ�]�����]�̃T�C��
	float sin_seeta = hypotf(Deff[0],Deff[2])/hypot3f(Deff[0],Deff[1],Deff[2]);
	//x���𒆐S�ɃƉ�]�����]�̃R�T�C��
	float cos_seeta = Deff[1]/hypot3f(Deff[0],Deff[1],Deff[2]);
	//y���𒆐S�ɃӉ�]�����]�̃T�C��
	float sin_fai = Deff[0]/hypot(Deff[0],Deff[2]);
	//y���𒆐S�ɃӉ�]�����]�̃R�T�C��
	float cos_fai = Deff[2]/hypot(Deff[0],Deff[2]);

	//�Ƃƃӂ����肷��
	for(i = 0; i < 360; i++){
		if( seeta == InValue ){
			if( CompareCos(cos_seeta, i) ){
				if( CompareSin(sin_seeta, i) ){
					seeta = i;
				}
			}
		}
		if( fai == InValue ){
			if( CompareCos(cos_fai, i) ){
				if( CompareSin(sin_fai, i) ){
					fai = i;
				}
			}
		}
	}
	glPushMatrix();	
	
	//Edge1�̈ʒu�֍��W���ړ�������
	glTranslatef(Edge1[0],Edge1[1],Edge1[2]);
	//y���Ӊ�]
	//�ӂ������Ȓl�̂Ƃ��A��]�͕s�v�Ȃ̂ł��Ȃ�
	if(fai != InValue){
		glRotatef(fai, 0,1,0);
	}
	//x���Ɖ�]
	//�Ƃ������Ȓl�̂Ƃ��A��]�͕s�v�Ȃ̂ł��Ȃ�
	if(seeta != InValue){
		glRotatef(seeta, 1,0,0);
	}

	glBegin(GL_QUAD_STRIP);
	for(i = 0; i<=360.0; i=i+1){
		t = i*pi/180.0;
		glNormal3f((float)cos(t)		, 0.0	, (float)sin(t));
		glVertex3f((float)(Rad*cos(t))	, 0.0	, (float)(Rad*sin(t)));
		glVertex3f((float)(Rad*cos(t))	, Length, (float)(Rad*sin(t)));
		
	}
	glEnd();
	glPopMatrix();

	
}
//-----------------------------------------------
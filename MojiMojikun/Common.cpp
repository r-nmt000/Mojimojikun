#include "Common.h"
#include "GamePlay.h"
#include "NomoTex.h"
#include <iostream>
#include <stdexcept>
#include <XnCppWrapper.h>
#include <XnVSessionManager.h>
#include <XnVWaveDetector.h>

//*********************************************************

//�@�@�@�@�@�@�@�@�@�O���[�o���ϐ�

//*********************************************************

//__________________________________
//				�F�X
//__________________________________

float g_fColor[][3] =
{
	{1,0,0},	// Red
	{0,1,0},	// Green
	{0,0.5,1},	// Light blue
	{1,1,0},	// Yellow
	{1,0.5,0},	// Orange
	{1,0,1},	// Purple
	{1,1,1},	// White
	{0,0,0}		// Black
};

int g_Count = 0;
//__________________________________
//				Main.cpp
//__________________________________

// OpenNI �I�u�W�F�N�g
xn::Context g_Context;
xn::DepthGenerator g_DepthGenerator;
xn::HandsGenerator g_HandsGenerator;

// NITE �I�u�W�F�N�g
XnVSessionManager* g_pSessionManager;
XnVFlowRouter* g_pFlowRouter;

// �f�v�X�}�b�v�̕\���E��\���t���O
XnBool g_bDrawDepthMap = true;
XnBool g_bPrintFrameID = false;
// �X���[�W���O�̗L���t���O
XnFloat g_fSmoothing = 0.0f;
XnBool g_bPause = false;
XnBool g_bQuit = false;

//�Z�b�V�����̏��
SessionState g_SessionState = NOT_IN_SESSION;
//__________________________________
//			PointDrawer.cpp
//__________________________________

// ����g���b�L���O����I�u�W�F�N�g
MenuIcon*		g_pMenuIcon;
XnVPointDrawer* g_pDrawer;
//�|�C���^�̃e�N�X�`��
NomoTex* g_pPointTexture;
//�^�C�g���̃e�N�X�`��
NomoTex* g_pTitleTexture;
//History�̃T�C�Y�i3D�\���j
int g_3DHisBufSize = 30;

//__________________________________
//			MenuItem.cpp
//__________________________________

// ���j���[�A�C�R���̃I�u�W�F�N�g
MenuItem* g_pMI_Start;
MenuItem* g_pMI_Level;
MenuItem* g_pMI_PlayNum;
MenuItem* g_pMI_Instruction;
MenuItem* g_pMI_Calibration;
MenuItem* g_pMI_Miss;
MenuItem* g_pMI_OK;
//���x���Z���N�g���
MenuItem* g_pMI_Level_Hard;
MenuItem* g_pMI_Level_Normal;
MenuItem* g_pMI_Level_Easy;
//�v���C�����I�����߂�
MenuItem* g_pMI_PlayNum_One;
MenuItem* g_pMI_PlayNum_Two;
//�I��
MenuItem* g_pMI_Exit;
//���j���[�A�C�e�����I�����ꂽ���ǂ���
BOOL g_SelectFlg = FALSE;
//���j���[�A�C�e�����ړ���Ԃ�
BOOL g_MoveModeFlg1 = FALSE;
BOOL g_MoveModeFlg2 = FALSE;
//OpenNI�֘A
XnCallbackHandle g_UserCallbacks; 
XnCallbackHandle g_CalibrationCallbacks;
XnCallbackHandle g_PoseCallbacks;
xn::PoseDetectionCapability g_PoseDet = user.GetPoseDetectionCap();
//__________________________________
//			�ǂ���
//__________________________________
NomoWall* g_pT_Wall;
NomoWall* g_pX_Wall;
NomoWall* g_pY_Wall;
NomoWall* g_pH_Wall;
NomoWall* g_pK_Wall;
NomoWall* g_pV_Wall;
NomoWall* g_pRKagi_Wall;
NomoWall* g_pLKagi_Wall;
NomoWall* g_pKune_Wall;
NomoWall* g_pRikishi_Wall;
NomoWall* g_pManji_Wall;
NomoWall* g_pGyakuManji_Wall;
NomoWall* g_pBaseball_Wall;
NomoWall* g_pMonsterBall_Wall;

NomoWall* g_pMO_Wall;
NomoWall* g_pZI_Wall;
NomoWall* g_pO_Wall;



//__________________________________
//			�T�E���h�֘A
//__________________________________
BOOL g_SoundFlg		= FALSE;
BOOL g_PlayBGMFlg	= FALSE;

//__________________________________
//			BouNinGen.cpp
//__________________________________
BouNinGen* g_pBNG;
//__________________________________
//		��ʐ؂�ւ��p�̃t���O
//__________________________________
//�g���b�L���O�J�n����
BOOL		g_TrackHandFlg = false;
//�L�����u���[�V�������t���O
BOOL		g_CalibrationMode = false;
//�L�����u���[�V�����~�X�t���O
BOOL		g_MissCalibrationFlg = false;
//OK�̕\��
BOOL		g_OKFlg		  = false;
//�Q�[����ʕ`��
BOOL		g_GameDrawFlg = false;
//���j���[��ʕ`��
BOOL		g_MenuDrawFlg = true;
//���C�����j���[��ʕ`��
BOOL		g_MainMenuDrawFlg = true;
//�Z���N�g���x����ʕ`��
BOOL		g_LevelDrawFlg = false;
//�v���C���[���I����ʕ`��
BOOL		g_PlayNumDrawFlg = false;
//�g�����W�V�����t���O
BOOL		g_StartTransitionFlg = FALSE;
BOOL		g_EndTransitionFlg = FALSE;

//__________________________________
//		�X���b�h�Ǘ�
//__________________________________
BOOL ExitNIThreadFlg = FALSE;
//__________________________________
//		��Փx�A�v���C���[��
//__________________________________
int		g_GAMELEVEL;
int		g_PLAYNUM;
//************************�I���***************************

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//�݂̒ǉ�

IplImage* camera;
xn::ImageGenerator image;
xn::UserGenerator user;

xn::SkeletonCapability skelton = user.GetSkeletonCap();

// �\�����
bool isShowImage;
bool isShowUser;
bool isShowSkelton;

//�ʉ߂��Ă邩�̃t���O
bool ALLisPass = true;
//�L�����u���[�V�����̃t���O
extern bool Calibration_flg = false;

//�ǂ̔ԍ�
int wall_number;

double movewall_ichi = 0;

//�݂̒ǉ������܂�
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//�Q�[�����I������
void CleanupExit()
{
	g_Context.Shutdown();

	exit (1);
}

#ifdef USE_GLUT

//�L�[�{�[�h����
void glutKeyboard (unsigned char key,int x, int y)
{
	switch (key)
	{
	case 27:
		// �I��
		CleanupExit();
	case'p':
		// �|�[�Y
		g_bPause = !g_bPause;
		break;
	case 'd':
		// �f�v�X�}�b�v�̕\���E��\��
		//g_bDrawDepthMap = !g_bDrawDepthMap;
		//pDrawer->SetDepthMap(g_bDrawDepthMap);
		break;
	case 'f':
		//g_bPrintFrameID = !g_bPrintFrameID;
		//g_pDrawer->SetFrameID(g_bPrintFrameID);
		break;
/*
	case 's':
		// �X���[�Y�ɂ��邩�ǂ���
		if (g_fSmoothing == 0)
			g_fSmoothing = 0.1;
		else 
			g_fSmoothing = 0;
		g_HandsGenerator.SetSmoothing(g_fSmoothing);
		break;
*/
	case 'e':
		// �Z�b�V�����̏I��
		g_pSessionManager->EndSession();
		break;
	}
}

static void Update(int value)
{
	if(g_GameDrawFlg == true){
	     GamePlay::game_update();
	}

	glutPostRedisplay();
	glutTimerFunc(WAIT_TIME, Update, value);
}

//y���W�̔��]
float MirrorYposition(float Ypos, float Hight){
	float fRet = 0;
	float Deff = Ypos - (Hight/2);
	
	fRet = (Hight/2) - Deff;
	return fRet;
}

//���X������
void glInit (int * pargc, char ** argv)
{
	glutInit(pargc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1280, 960);
	//glutInitWindowSize(GL_WIN_SIZE_X, GL_WIN_SIZE_Y);
	glutCreateWindow ("������������");
	//glutFullScreen();
	glutSetCursor(GLUT_CURSOR_NONE);
	//�J���[�o�b�t�@������
	glClearColor(1.0, 1.0, 1.0, 1.0);
	//�ˉe�ϊ�
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//���p�x�A�c����i�A�X�y�N�g�j�A�O�ʁA��ʁA�ݒ肷��
	gluPerspective(45.0, (float)GL_WIN_SIZE_Y/GL_WIN_SIZE_X, -3, 50.0);
	//���f���ϊ�
	glMatrixMode(GL_MODELVIEW);
	//�|���S���̕\�ʂ����`�悷��
	glCullFace(GL_BACK);
	//�e�R�[���o�b�N�֐��̓o�^
	glutKeyboardFunc(glutKeyboard);
	glutDisplayFunc(glutDisplay);

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);


	glEnableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

    glutTimerFunc(WAIT_TIME, Update, 0);
}
#endif
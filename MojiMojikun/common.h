#pragma once
#include <XnVFlowRouter.h>
#include <glut.h>
#include <XnVSessionManager.h>

//����2��ǉ�����  by��
#include "opencv/cv.h"
#include "opencv/highgui.h"

#include "PointDrawer.h"
#include "MenuItem.h"
#include "Macro.h"
#include "Nomotex.h"
#include "BMP.h"
#include "MenuIcon.h"
#include "BouNinGen.h"
#include "NomoWall.h"

//************************�I���***************************

//*********************************************************

//�@�@�@�@�@�@�@�@�@�O���[�o���ϐ�

//*********************************************************


//__________________________________
//				�@�F�X
//__________________________________

extern float g_fColor[][3];
extern int	 g_Count;
//__________________________________
//				Main.cpp
//__________________________________

// OpenNI �I�u�W�F�N�g
extern xn::Context g_Context;
extern xn::DepthGenerator g_DepthGenerator;
extern xn::HandsGenerator g_HandsGenerator;

// NITE �I�u�W�F�N�g
extern XnVSessionManager* g_pSessionManager;
extern XnVFlowRouter* g_pFlowRouter;


//�Z�b�V�����̏��
extern SessionState g_SessionState;
// �f�v�X�}�b�v�̕\���E��\���t���O
extern XnBool g_bDrawDepthMap;
extern XnBool g_bPrintFrameID;
// �X���[�W���O�̗L���t���O
extern XnFloat	 g_fSmoothing;
extern XnBool	 g_bPause;
extern XnBool	 g_bQuit;
//OpenNI�֘A
extern XnCallbackHandle g_UserCallbacks; 
extern XnCallbackHandle g_CalibrationCallbacks;
extern XnCallbackHandle g_PoseCallbacks;
extern xn::PoseDetectionCapability g_PoseDet;
//__________________________________
//			PointDrawer.cpp
//__________________________________

// ����g���b�L���O����I�u�W�F�N�g
extern MenuIcon*			g_pMenuIcon;
extern XnVPointDrawer* g_pDrawer;
extern NomoTex*			   g_pPointTexture;
extern NomoTex*			   g_pTitleTexture;
//History�̃T�C�Y�i3D�\���j
extern int g_3DHisBufSize;

//__________________________________
//			MenuItem.cpp
//__________________________________

// ���j���[�A�C�R���̃I�u�W�F�N�g
extern MenuItem* g_pMI_Start;
extern MenuItem* g_pMI_Level;
extern MenuItem* g_pMI_PlayNum;
extern MenuItem* g_pMI_Instruction;
extern MenuItem* g_pMI_Calibration;
extern MenuItem* g_pMI_Miss;
extern MenuItem* g_pMI_OK;
extern MenuItem* g_pMI_Exit;
//���x���Z���N�g���
extern MenuItem* g_pMI_Level_Hard;
extern MenuItem* g_pMI_Level_Normal;
extern MenuItem* g_pMI_Level_Easy;
//�v���C�����I�����߂�
extern MenuItem* g_pMI_PlayNum_One;
extern MenuItem* g_pMI_PlayNum_Two;
//���j���[�A�C�e�����I�����ꂽ���ǂ���
extern BOOL		 g_SelectFlg;
extern BOOL		 g_MoveModeFlg1;
extern BOOL		 g_MoveModeFlg2;

//__________________________________
//			�ǂ���
//__________________________________
extern NomoWall* g_pT_Wall;
extern NomoWall* g_pX_Wall;
extern NomoWall* g_pY_Wall;
extern NomoWall* g_pH_Wall;
extern NomoWall* g_pK_Wall;
extern NomoWall* g_pV_Wall;
extern NomoWall* g_pRKagi_Wall;
extern NomoWall* g_pLKagi_Wall;
extern NomoWall* g_pKune_Wall;
extern NomoWall* g_pRikishi_Wall;
extern NomoWall* g_pManji_Wall;
extern NomoWall* g_pGyakuManji_Wall;
extern NomoWall* g_pBaseball_Wall;
extern NomoWall* g_pMonsterBall_Wall;

extern NomoWall* g_pMO_Wall;
extern NomoWall* g_pZI_Wall;
extern NomoWall* g_pO_Wall;

//__________________________________
//			�T�E���h�֘A
//__________________________________
extern BOOL		 g_SoundFlg;
extern BOOL		 g_PlayBGMFlg;

//__________________________________
//			BouNinGen.cpp
//__________________________________
extern BouNinGen* g_pBNG;


//__________________________________
//		��ʐ؂�ւ��p�̃t���O
//__________________________________
//�g���b�L���O�J�n����
extern BOOL		g_TrackHandFlg;
//�L�����u���[�V�������t���O
extern BOOL		g_CalibrationMode;
//�L�����u���[�V�����~�X�t���O
extern BOOL		g_MissCalibrationFlg;
//OK�t���O
extern BOOL		g_OKFlg;
//�Q�[����ʕ`��
extern BOOL		g_GameDrawFlg;
//���j���[��ʕ`��
extern BOOL		g_MenuDrawFlg;
//���C�����j���[��ʕ`��
extern BOOL		g_MainMenuDrawFlg;
//�Z���N�g���x����ʕ`��
extern BOOL		g_LevelDrawFlg;
//�v���C���[���I����ʕ`��
extern BOOL		g_PlayNumDrawFlg;
//�g�����W�V�����t���O
extern BOOL		g_StartTransitionFlg;
extern BOOL		g_EndTransitionFlg;

//__________________________________
//		�X���b�h�Ǘ�
//__________________________________
extern BOOL ExitNIThreadFlg;

//__________________________________
//		��Փx�A�v���C���[��
//__________________________________
extern int		g_GAMELEVEL;
extern int		g_PLAYNUM;

//************************�I���***************************


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
//�݂̒ǉ�

extern IplImage* camera;
extern xn::ImageGenerator image;
extern xn::UserGenerator user;

extern xn::SkeletonCapability skelton;

// �\�����
extern bool isShowImage;
extern bool isShowUser;
extern bool isShowSkelton;

//�ʉ߂��Ă邩�̃t���O
extern bool ALLisPass;
//�L�����u���[�V�����̃t���O
extern bool Calibration_flg;
extern int wall_number;

extern double movewall_ichi;

//�݂̒ǉ������܂�
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


void CleanupExit();
float MirrorYposition(float Ypos, float Hight);
void glutDisplay (void);
void glutKeyboard (unsigned char key,int x, int y);
void glInit (int * pargc, char ** argv);
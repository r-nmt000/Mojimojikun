#include "Common.h"
#include <Mmsystem.h>
#include <Windows.h>
#include "NomoTex.h"
#include "MenuDisplay.h"

//GamePlay.h��ǉ��@��
#include "GamePlay.h"
#include "passage.h"


//*********************************************************
//						glutDisplay
//				�t���[�����ƂɌĂ΂��`��֐�
//*********************************************************
void glutDisplay (void)
{

	//if���Ŗ�����͂��@��
    if(g_GameDrawFlg != TRUE){
	     glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	     // Setup the OpenGL viewpoint
	     glMatrixMode(GL_PROJECTION);
	     //glPushMatrix();
	     glLoadIdentity();

	     //XnMapOutputMode mode;
	     //g_DepthGenerator.GetMapOutputMode(mode);
	     //���_�A����̐ݒ�
	     //glOrtho(left, right, bottom, top, near, far);
	     glOrtho(0, GL_WIN_SIZE_X/*mode.nXRes*/, 0/*mode.nYRes*/, GL_WIN_SIZE_Y, 0, 50.0);


	     //glDisable(GL_TEXTURE_2D);

	     if (!g_bPause)
	     {
		     //�L�l�N�g����̏��̍X�V
		    // g_Context.WaitOneUpdateAll(g_DepthGenerator);
#ifdef USE_POINTDRAWER
		     // Update NITE tree
		     g_pSessionManager->Update(&g_Context);
#else
			 //�g���b�L���O���������Ă�����
			 //���j���[�A�C�R���̍X�V nomoto
			 if( g_TrackHandFlg != FALSE ){
				 g_pMenuIcon->Update();
			 }
#endif
#ifdef USE_GLUT
		     //�Z�b�V�����̏�Ԃ�\��
		     //PrintSessionState(g_SessionState);
		     //���j���[��ʂ̕`��
		     DrawMenu();
			 //passage::passage_main ();
#endif
	     }

#ifdef USE_GLUT
	glutSwapBuffers();
#endif
    } else{
		  //Gemedisplay���ĂԂƃQ�[���X�^�[�g
		  GamePlay::Gamedisplay();
		  
	}
}


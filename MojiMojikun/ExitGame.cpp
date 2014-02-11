#include "ExitGame.h"
#include "common.h"
#include <stdlib.h>

//�������̏I������
void ExitMozio(XnCallbackHandle UserCallbacks, XnCallbackHandle CalibrationCallbacks, XnCallbackHandle PoseCallbacks, xn::PoseDetectionCapability PoseDet){
	UnregAndClearGameObject(UserCallbacks, CalibrationCallbacks, PoseCallbacks, PoseDet );
	ExitMoziThread();
	exit(0);
};
//�I�u�W�F�N�g�A�R�[���o�b�N�֐����X�̌㏈��
void UnregAndClearGameObject( XnCallbackHandle UserCallbacks, XnCallbackHandle CalibrationCallbacks, XnCallbackHandle PoseCallbacks, xn::PoseDetectionCapability PoseDet ){
// �o�^�����R�[���o�b�N���폜
		skelton.UnregisterCalibrationCallbacks( CalibrationCallbacks );
		user.UnregisterUserCallbacks( UserCallbacks );
		PoseDet.UnregisterFromPoseCallbacks( PoseCallbacks );
	

		//�I�u�W�F�N�g�̔j��
		delete g_pMI_Start;
		delete g_pMI_Level;	
		delete g_pMI_PlayNum;	
		delete g_pMI_Instruction;
		delete g_pMI_Calibration;
		delete g_pMI_Miss;
		delete g_pMI_OK;	
		delete g_pMI_Exit;
		//�Z���N�g���j���[�̃I�u�W�F�N�g
		delete g_pMI_Level_Hard;	
		delete g_pMI_Level_Normal;	
		delete g_pMI_Level_Easy;	
		//�v���C���[���I�����j���[�̃I�u�W�F�N�g
		delete g_pMI_PlayNum_One;	
		delete g_pMI_PlayNum_Two;	
		//�e�N�X�`��
		delete g_pTitleTexture;
		delete g_pPointTexture;
		//�ǂ���
        delete g_pT_Wall;
        delete g_pX_Wall;
        delete g_pY_Wall;
        delete g_pH_Wall;
        delete g_pK_Wall;
        delete g_pV_Wall;
        delete g_pRKagi_Wall;
        delete g_pLKagi_Wall;
        delete g_pKune_Wall;
        delete g_pRikishi_Wall;
        delete g_pManji_Wall;
        delete g_pGyakuManji_Wall;
        delete g_pBaseball_Wall;
        delete g_pMonsterBall_Wall;

        delete g_pMO_Wall;
        delete g_pZI_Wall;
        delete g_pO_Wall;
}
//�X���b�h�̏I��
void ExitMoziThread(){
	ExitNIThreadFlg = TRUE;
}
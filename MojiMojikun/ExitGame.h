#pragma once

#include <XnVSessionManager.h>

//�������̏I������
void ExitMozio(XnCallbackHandle UserCallbacks, XnCallbackHandle CalibrationCallbacks, XnCallbackHandle PoseCallbacks, xn::PoseDetectionCapability PoseDet);
//�I�u�W�F�N�g�A�R�[���o�b�N�֐����X�̌㏈��
void UnregAndClearGameObject( XnCallbackHandle UserCallbacks, XnCallbackHandle CalibrationCallbacks, XnCallbackHandle PoseCallbacks, xn::PoseDetectionCapability PoseDet );
//�X���b�h�̏I��
void ExitMoziThread();
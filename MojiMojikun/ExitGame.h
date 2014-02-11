#pragma once

#include <XnVSessionManager.h>

//もじおの終了処理
void ExitMozio(XnCallbackHandle UserCallbacks, XnCallbackHandle CalibrationCallbacks, XnCallbackHandle PoseCallbacks, xn::PoseDetectionCapability PoseDet);
//オブジェクト、コールバック関数諸々の後処理
void UnregAndClearGameObject( XnCallbackHandle UserCallbacks, XnCallbackHandle CalibrationCallbacks, XnCallbackHandle PoseCallbacks, xn::PoseDetectionCapability PoseDet );
//スレッドの終了
void ExitMoziThread();
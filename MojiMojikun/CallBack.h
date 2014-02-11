#pragma once
#include <iostream>
#include <stdexcept>


//#include <opencv/cv.h>
//#include <opencv/highgui.h>

#include <XnCppWrapper.h>
#include <XnVSessionManager.h>
#include <XnVWaveDetector.h>

#include "common.h"
#include "NomoTex.h"


//*********************************************************

//　　　　　　　　　コールバック関数

//*********************************************************
// セッションの開始を通知されるコールバック
void XN_CALLBACK_TYPE SessionStart(const XnPoint3D& pFocus, void* UserCxt)
{
  std::cout << "SessionStart" << std::endl;
}

// セッションの終了を通知されるコールバック
void XN_CALLBACK_TYPE SessionEnd(void* UserCxt)
{
  std::cout << "SessionEnd" << std::endl;
}

// ウェーブイベントを通知されるコールバック
void XN_CALLBACK_TYPE Wave(void *pUserCxt)
{
  std::cout << "Wave" << std::endl;
}

//検出ポイントがなくなったときのコールバック
void XN_CALLBACK_TYPE NoHands(void* UserCxt)
{
	if (g_SessionState != NOT_IN_SESSION)
	{


		printf("Quick refocus\n");
		g_SessionState = QUICK_REFOCUS;
	}
}


// ユーザー検出
void XN_CALLBACK_TYPE UserDetected(xn::UserGenerator& generator,
  XnUserID nId, void* pCookie)
{
  std::cout << "ユーザー検出:" << nId << " " <<
    generator.GetNumberOfUsers() << "人目" << std::endl;

  XnChar* pose = (XnChar*)pCookie;
  if (pose[0] != '¥0') {
    generator.GetPoseDetectionCap().StartPoseDetection(pose, nId);
  }
  else {
    generator.GetSkeletonCap().RequestCalibration(nId, TRUE);
  }
}

// ユーザー消失
void XN_CALLBACK_TYPE UserLost(xn::UserGenerator& generator,
  XnUserID nId, void* pCookie)
{
  std::cout << "ユーザー消失:" << nId << std::endl;
  //岸追加
  //Calibration_flg = false;
}

// ポーズ検出
void XN_CALLBACK_TYPE PoseDetected(xn::PoseDetectionCapability& capability,
  const XnChar* strPose, XnUserID nId, void* pCookie)
{
  std::cout << "ポーズ検出:" << strPose << " ユーザー:" << nId << std::endl;

  xn::UserGenerator* user = (xn::UserGenerator*)pCookie;
  user->GetPoseDetectionCap().StopPoseDetection(nId);
  user->GetSkeletonCap().RequestCalibration(nId, TRUE);
}

// ポーズ消失
void XN_CALLBACK_TYPE PoseLost(xn::PoseDetectionCapability& capability,
  const XnChar* strPose, XnUserID nId, void* pCookie)
{
  std::cout << "ポーズ消失:" << strPose << " ユーザー:" << nId << std::endl;
  //Calibration_flg = false;
}

// キャリブレーションの開始
void XN_CALLBACK_TYPE CalibrationStart(xn::SkeletonCapability& capability,
  XnUserID nId, void* pCookie)
{
	g_CalibrationMode = true;
	std::cout << "キャリブレーション開始。ユーザー:" << nId << std::endl;
}

// キャリブレーションの終了
void XN_CALLBACK_TYPE CalibrationEnd(xn::SkeletonCapability& capability,
  XnUserID nId, XnBool bSuccess, void* pCookie)
{
  xn::UserGenerator* user = (xn::UserGenerator*)pCookie;

  // キャリブレーション成功
  if (bSuccess) {
    std::cout << "キャリブレーション成功。ユーザー:" << nId << std::endl;
	//岸追加
	Calibration_flg = true;
	//キャリブレーションが成功したらメニュー画面を暗転からメニュー画面を表示
	//棒人間のUserIDもここで設定　nomoto
	g_TrackHandFlg = TRUE;
	g_OKFlg = TRUE;
	g_pMenuIcon->SetUserID(nId);
    user->GetSkeletonCap().StartTracking(nId);
	g_pBNG->SetUserID(nId);
	
  }
  // キャリブレーション失敗
  else {
    std::cout << "キャリブレーション失敗。ユーザー:" << nId << std::endl;
	Calibration_flg = false;
	g_CalibrationMode = false;
	g_MissCalibrationFlg = true;
  }
}


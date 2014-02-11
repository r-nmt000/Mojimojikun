#pragma once
// Windows の場合はReleaseコンパイルにすると
// 現実的な速度で動作します

class passage
{
/*private:
    const XnFloat Colors[][3];
	void XN_CALLBACK_TYPE UserDetected(xn::UserGenerator& generator,
  XnUserID nId, void* pCookie);
	void XN_CALLBACK_TYPE UserLost(xn::UserGenerator& generator,
  XnUserID nId, void* pCookie);
	void XN_CALLBACK_TYPE PoseDetected(xn::PoseDetectionCapability& capability,
  const XnChar* strPose, XnUserID nId, void* pCookie);
	void XN_CALLBACK_TYPE PoseLost(xn::PoseDetectionCapability& capability,
  const XnChar* strPose, XnUserID nId, void* pCookie);
	void XN_CALLBACK_TYPE CalibrationStart(xn::SkeletonCapability& capability,
  XnUserID nId, void* pCookie);
	void XN_CALLBACK_TYPE CalibrationEnd(xn::SkeletonCapability& capability,
  XnUserID nId, XnBool bSuccess, void* pCookie);
	inline XnRGB24Pixel xnRGB24Pixel( int r, int g, int b );
*/
public:
  static void passage_main ();
};


#include "passage.h"

#include <iostream>
#include <stdexcept>
#include <vector>

#include "opencv/cv.h"
#include "opencv/highgui.h"

#include "XnCppWrapper.h"
#include "common.h"

#ifndef SKELTONDRAWER_H_INCLUDE
#define SKELTONDRAWER_H_INCLUDE

// 設定ファイルのパス(環境に合わせて変更してください)
#if (XN_PLATFORM == XN_PLATFORM_WIN32)
const char* CONFIG_XML_PATH2 = "C:/Documents and Settings/Administrator/My Documents/Visual Studio 2010/Projects/MojiMojikun/MojiMojikun/SamplesConfig.xml";
#elif (XN_PLATFORM == XN_PLATFORM_MACOSX)
const char* CONFIG_XML_PATH2 = "../../../../../Data/SamplesConfig.xml";
#elif (XN_PLATFORM == XN_PLATFORM_LINUX_X86)
const char* CONFIG_XML_PATH2 = "../../../Data/SamplesConfig.xml";
#else
const char* CONFIG_XML_PATH2 = "Data/SamplesConfig.xml";
#endif


//Original Variable
char key;

    //初期設定のフラグ
	bool Capture_init_flg = true;

// ユーザーの色づけ
const XnFloat Colors[][3] =
{
  {1,1,1},    // ユーザーなし
  {0,1,1},  {0,0,1},  {0,1,0},
  {1,1,0},  {1,0,0},  {1,.5,0},
  {.5,1,0}, {0,.5,1}, {.5,0,1},
  {1,1,.5},
};



// RGBピクセルの初期化
inline XnRGB24Pixel xnRGB24Pixel( int r, int g, int b )
{
  XnRGB24Pixel pixel = { r, g, b };
  return pixel;
}

// （！）skelton.hをここにコピーする

class SkeltonDrawer
{
public:
  SkeltonDrawer( IplImage* camera, xn::SkeletonCapability& skelton, xn::DepthGenerator& depth, XnUserID player )
	  :camera_(camera), skelton_(skelton), depth_(depth), player_(player){ }

  // スケルトンを描画する
  void draw()
  {
    if (!skelton_.IsTracking(player_)) {
      throw std::runtime_error("トラッキングされていません");
    }

	bool HEADisPass = true,
		 NECKisPass = true,

		 LEFT_SHOULDERisPass = true,
		 LEFT_ELBOWisPass = true,
		 LEFT_HANDisPass = true,

		 RIGHT_SHOULDERisPass = true,
		 RIGHT_ELBOWisPass = true,
		 RIGHT_HANDisPass = true,

		 TORSOisPass = true,
	
		 LEFT_HIPisPass = true,
		 LEFT_KNEEisPass = true,
		 LEFT_FOOTisPass = true,

		 RIGHT_HIPisPass = true,
		 RIGHT_KNEEisPass = true,
		 RIGHT_FOOTisPass = true;
		
		 //ALLisPass = true;

	
    drawLine(XN_SKEL_HEAD, XN_SKEL_NECK);

    drawLine(XN_SKEL_NECK, XN_SKEL_LEFT_SHOULDER);
    drawLine(XN_SKEL_LEFT_SHOULDER, XN_SKEL_LEFT_ELBOW);
    drawLine(XN_SKEL_LEFT_ELBOW, XN_SKEL_LEFT_HAND);

    drawLine(XN_SKEL_NECK, XN_SKEL_RIGHT_SHOULDER);
    drawLine(XN_SKEL_RIGHT_SHOULDER, XN_SKEL_RIGHT_ELBOW);
    drawLine(XN_SKEL_RIGHT_ELBOW, XN_SKEL_RIGHT_HAND);

    drawLine(XN_SKEL_LEFT_SHOULDER, XN_SKEL_TORSO);
    drawLine(XN_SKEL_RIGHT_SHOULDER, XN_SKEL_TORSO);

    drawLine(XN_SKEL_TORSO, XN_SKEL_LEFT_HIP);
    drawLine(XN_SKEL_LEFT_HIP, XN_SKEL_LEFT_KNEE);
    drawLine(XN_SKEL_LEFT_KNEE, XN_SKEL_LEFT_FOOT);

    drawLine(XN_SKEL_TORSO, XN_SKEL_RIGHT_HIP);
    drawLine(XN_SKEL_RIGHT_HIP, XN_SKEL_RIGHT_KNEE);
    drawLine(XN_SKEL_RIGHT_KNEE, XN_SKEL_RIGHT_FOOT);

    drawLine(XN_SKEL_LEFT_HIP, XN_SKEL_RIGHT_HIP);
	

	//Original Code
	HEADisPass = calCoord(XN_SKEL_HEAD);
	NECKisPass = calCoord(XN_SKEL_NECK);

	LEFT_SHOULDERisPass = calCoord(XN_SKEL_LEFT_SHOULDER);
	LEFT_ELBOWisPass = calCoord(XN_SKEL_LEFT_ELBOW);
	LEFT_HANDisPass = calCoord(XN_SKEL_LEFT_HAND);

	RIGHT_SHOULDERisPass = calCoord(XN_SKEL_RIGHT_SHOULDER);
	RIGHT_SHOULDERisPass = calCoord(XN_SKEL_RIGHT_ELBOW);
	RIGHT_HANDisPass = calCoord(XN_SKEL_RIGHT_HAND);
	
	TORSOisPass = calCoord(XN_SKEL_TORSO);

	LEFT_HIPisPass = calCoord(XN_SKEL_LEFT_HIP);
	RIGHT_HIPisPass = calCoord(XN_SKEL_RIGHT_HIP);

	LEFT_KNEEisPass = calCoord(XN_SKEL_LEFT_KNEE);
	//LEFT_FOOTisPass = calCoord(XN_SKEL_LEFT_FOOT);

	RIGHT_KNEEisPass = calCoord(XN_SKEL_RIGHT_KNEE);
	//RIGHT_FOOTisPass = calCoord(XN_SKEL_RIGHT_FOOT);
	/*
	ALLisPass = HEADisPass && NECKisPass && 
		        LEFT_SHOULDERisPass && LEFT_ELBOWisPass && LEFT_HANDisPass && 
				RIGHT_SHOULDERisPass && RIGHT_SHOULDERisPass && RIGHT_HANDisPass && 
				TORSOisPass && LEFT_HIPisPass && RIGHT_HIPisPass && 
				LEFT_KNEEisPass && LEFT_FOOTisPass && 
				RIGHT_KNEEisPass && RIGHT_FOOTisPass;
*/
	if( !ALLisPass ) {
		cvLine(camera_,cvPoint(100, 100), cvPoint(500, 400), CV_RGB(0, 0, 0),10,CV_AA ,0);
		cvLine(camera_,cvPoint(500, 100), cvPoint(100, 400), CV_RGB(0, 0, 0),10,CV_AA ,0);
	}
		

	//End of Original Code

	//Original Code
	/*
	getCoord_SKEL_HEAD(XN_SKEL_HEAD);
	getCoord_SKEL_NECK(XN_SKEL_NECK);

	getCoord_SKEL_LEFT_SHOULDER(XN_SKEL_LEFT_SHOULDER);
	getCoord_SKEL_LEFT_ELBOW(XN_SKEL_LEFT_ELBOW);
	getCoord_SKEL_LEFT_HAND(XN_SKEL_LEFT_HAND);

	getCoord_SKEL_RIGHT_SHOULDER(XN_SKEL_RIGHT_SHOULDER);
	getCoord_SKEL_RIGHT_ELBOW(XN_SKEL_RIGHT_ELBOW);
	getCoord_SKEL_RIGHT_HAND(XN_SKEL_RIGHT_HAND);

	getCoord_SKEL_TORSO(XN_SKEL_TORSO);

	getCoord_SKEL_LEFT_HIP(XN_SKEL_LEFT_HIP);
	getCoord_SKEL_RIGHT_HIP(XN_SKEL_RIGHT_HIP);

	getCoord_SKEL_LEFT_KNEE(XN_SKEL_LEFT_KNEE);
	getCoord_SKEL_LEFT_FOOT(XN_SKEL_LEFT_FOOT);

	getCoord_SKEL_RIGHT_KNEE(XN_SKEL_RIGHT_KNEE);
	getCoord_SKEL_RIGHT_FOOT(XN_SKEL_RIGHT_FOOT);
	end of original program
	*/
    }

private:
	//通過判定を計算する。
	bool Calculator(XnPoint3D *pt) {

		bool condition[4] ={true, true, true, true};
		//int ch = 14;

		switch(wall_number){
		//switch(ch){
		case 0:
			con0(condition, pt);
			if( condition[0] && condition[1] && condition[2] && condition[3]) {
				return true;
			} else {
				return false;
			}
		case 1:
			con1(condition, pt);
			if( condition[0] && condition[1] && condition[2] && condition[3]) {
			    return true;
		    } else {
			    return false;
		    }
		case 2:
			con2(condition, pt);
		    if( condition[0] && condition[1] && condition[2] && condition[3]) {
			    return true;
		    } else {
			    return false;
		    }
		case 3:
			con3(condition, pt);
		    if( condition[0] && condition[1] && condition[2] && condition[3]) {
			    return true;
		    } else {
			    return false;
		    }
		case 4:
			con4(condition, pt);
		    if( condition[0] && condition[1] && condition[2] && condition[3]) {
			    return true;
		    } else {
			    return false;
		    }
		case 5:
			con5(condition, pt);	
			if( condition[0] && condition[1] && condition[2] && condition[3]) {
				return true;
			} else {
				return false;
			}
		case 6:
			con6(condition, pt);
			if( condition[0] && condition[1] && condition[2] && condition[3]) {
			    return true;
		    } else {
			    return false;
		    }
		case 7:
			con7(condition, pt);
		    if( condition[0] && condition[1] && condition[2] && condition[3]) {
			    return true;
		    } else {
			    return false;
		    }
		case 8:
			con8(condition, pt);
		    if( condition[0] && condition[1] && condition[2] && condition[3]) {
			    return true;
		    } else {
			    return false;
		    }
		case 9:
			con9(condition, pt);
		    if( condition[0] && condition[1] && condition[2] && condition[3]) {
			    return true;
		    } else {
			    return false;
		    }
		case 10:
			con10(condition, pt);
		    if( condition[0] && condition[1] && condition[2] && condition[3]) {
			    return true;
		    } else {
			    return false;
		    }
		case 11:
			con11(condition, pt);
		    if( condition[0] && condition[1] && condition[2] && condition[3]) {
			    return true;
		    } else {
			    return false;
		    }
		case 12:
			con12(condition, pt);
		    if( condition[0] && condition[1] && condition[2] && condition[3]) {
			    return true;
		    } else {
			    return false;
		    }
		case 13:
			con13(condition, pt);
		    if( condition[0] && condition[1] && condition[2] && condition[3]) {
			    return true;
		    } else {
			    return false;
		    }
		case 14:
			con14(condition, pt);
		    if( condition[0] && condition[1] && condition[2] && condition[3]) {
			    return true;
		    } else {
			    return false;
		    }

		}
	}
	//T字型
	void con0(bool *condition, XnPoint3D *pt){
		condition[0] = !(pt[0].X < 210 && pt[0].Y > 200);
		condition[1] = !(pt[0].X > 430 && pt[0].Y > 200);
	}
	/*
	//２次曲線
	void con1(bool *condition, XnPoint3D *pt){
		condition[0] = (pt[0].Y - pow((pt[0].X - 320) / 12, 2) > 0);
		//condition[1] = !(pt[0].X > 530 && pt[0].Y < 400);
	}
	*/
    //X字型 640*480
	void con1(bool *condition, XnPoint3D *pt){
		condition[0] = !(pt[0].X > 295 && pt[0].X < 345 && pt[0].Y < 120); //頭
		condition[1] = !(pt[0].X > 295 && pt[0].X < 345 && pt[0].Y > 360); //また下
		condition[2] = !(pt[0].X < 150 && pt[0].Y > 200 && pt[0].Y < 270);
		condition[3] = !(pt[0].X > 490 && pt[0].Y > 200 && pt[0].Y < 270);
	}
	//Y字型
	void con2(bool *condition, XnPoint3D *pt){
		condition[0] = !(pt[0].X < 210 && pt[0].Y > (20.0 / 23) * pt[0].X);
		condition[1] = !(pt[0].X > 430 && pt[0].Y > -1 * (20.0 / 23) * pt[0].X + 12800.0 / 23);
		condition[2] = !(pt[0].X > 295 && pt[0].X < 345 && pt[0].Y < 120);
	}
	//H字型
	void con3(bool *condition, XnPoint3D *pt){
		condition[0] = !(pt[0].X > 240 && pt[0].X < 400 && pt[0].Y < 200); //頭
		condition[1] = !(pt[0].X > 240 && pt[0].X < 400 && pt[0].Y > 320); //また下
		condition[2] = !(pt[0].X < 80 );
		condition[3] = !(pt[0].X > 560 );
	}
	//K字型
	void con4(bool *condition, XnPoint3D *pt){
		condition[0] = !(pt[0].Y > (20.0 / 46) * pt[0].X+300 && pt[0].X > 220); //また下
		condition[1] = !(pt[0].Y < -1*(20.0 / 46) * pt[0].X+240 && pt[0].X > 220); //あたま
		condition[2] = !(pt[0].X < 80 );
		condition[3] = !(pt[0].X > 360 && pt[0].Y > 200 && pt[0].Y < 270);
	}
	//V字型
	void con5(bool *condition, XnPoint3D *pt){
		condition[0] = !(pt[0].Y > 2 * pt[0].X ); //左
	    condition[1] = !(pt[0].Y > -2 * (pt[0].X-640)); //右
		condition[2] = !(pt[0].X > 295 && pt[0].X < 345 && pt[0].Y < 240);
		//condition[3] = (pt[0].Y > -2 * pt[0].X-200 || pt[0].Y>320 );
	}
	//右への鍵字型
	void con6(bool *condition, XnPoint3D *pt){
		condition[0] = !(pt[0].X > 80 && pt[0].X < 560 && pt[0].Y < 120); //頭
		condition[1] = !(pt[0].X > 220 && pt[0].X < 560 && pt[0].Y > 360); //下
		condition[2] = !(pt[0].X < 80 );
		condition[3] = !(pt[0].X > 560 );
	}
	//左への鍵字型
	void con7(bool *condition, XnPoint3D *pt){
		condition[0] = !(pt[0].X > 80 && pt[0].X < 560 && pt[0].Y < 120); //頭
		condition[1] = !(pt[0].X > 80 && pt[0].X < 420 && pt[0].Y > 360); //下
		condition[2] = !(pt[0].X < 80 );
		condition[3] = !(pt[0].X > 560 );
	}
	//なんかくねくねした形
	void con8(bool *condition, XnPoint3D *pt){
		condition[0] = !(pt[0].X > 320 && pt[0].X < 560 && pt[0].Y < 120); //頭
		condition[1] = !(pt[0].X > 80 && pt[0].X < 320 && pt[0].Y > 360); //下
		condition[2] = !(pt[0].X < 140 && pt[0].Y < 120);
		condition[3] = !(pt[0].X > 500 && pt[0].Y > 360);
	}
	//力士の四股
	void con9(bool *condition, XnPoint3D *pt){
		condition[0] = !(pt[0].X < 290 && pt[0].Y < 180) && !(pt[0].X > 350 && pt[0].Y < 180); //頭
		condition[1] = !(pt[0].X > 270 && pt[0].X < 370 && pt[0].Y > 350); //下
		condition[2] = !(pt[0].X > 370 && pt[0].Y > 230 && pt[0].Y < 250);
		condition[3] = !(pt[0].X > 240 && pt[0].Y < 230);
	}
	//風車っぽい形
	void con10(bool *condition, XnPoint3D *pt){
		condition[0] = !(pt[0].X < 320 && pt[0].Y > 350); //下
		condition[1] = !(pt[0].X > 320 && pt[0].Y <100); //上
		condition[2] = !(pt[0].X > 480 && pt[0].Y > 240 );
		condition[3] = !(pt[0].X < 160 && pt[0].Y < 240);
	}
	//逆風車っぽい形
	void con11(bool *condition, XnPoint3D *pt){
		condition[0] = !(pt[0].X < 320 && pt[0].Y < 100); //上
		condition[1] = !(pt[0].X > 320 && pt[0].Y >350); //下
		condition[2] = !(pt[0].X < 160 && pt[0].Y > 240 );
		condition[3] = !(pt[0].X > 480 && pt[0].Y < 240);
	}
	//野球しようぜ
	void con12(bool *condition, XnPoint3D *pt){
		condition[0] = !(pt[0].X < 240 ); //左
		condition[1] = !(pt[0].X < 260 && pt[0].Y >260 && pt[0].Y <280); //膝
		condition[2] = !(pt[0].X > 400 && pt[0].Y < 100 );
		condition[3] = !(pt[0].X > 420 && pt[0].Y > 240);
	}
	//ポケモンゲットだぜ!
	void con13(bool *condition, XnPoint3D *pt){
		condition[0] = !(pt[0].X < 120 && pt[0].Y < 300 && pt[0].Y > 180) && !(pt[0].X > 520 && pt[0].Y < 300 && pt[0].Y > 180);  //外円
		condition[1] = !(pt[0].X < 170 && pt[0].Y > 300) && !(pt[0].X < 170 && pt[0].Y < 180) && !(pt[0].X > 470 && pt[0].Y < 180) && !(pt[0].X > 470 && pt[0].Y > 300); 
		condition[2] = !(pt[0].X > 300 && pt[0].X < 340 && pt[0].Y < 260 && pt[0].Y > 220 );
		//condition[3] = !(pt[0].X > 420 && pt[0].Y > 240);
	}
	//動くかべ
	void con14(bool *condition, XnPoint3D *pt){
		condition[0] = !(pt[0].X < 80 );
		condition[1] = !(pt[0].X > 560 ); 
		condition[2] = !(pt[0].X < (movewall_ichi+2)*160+25 && pt[0].X > (movewall_ichi+2)*160-25 );
		//condition[3] = !(pt[0].X > 420 && pt[0].Y > 240);
	}
private:
	bool calCoord(XnSkeletonJoint eJoint)
	{
		// 各箇所の座標を取得する
		XnSkeletonJointPosition joint;
		skelton_.GetSkeletonJointPosition(player_, eJoint, joint);
		if (joint.fConfidence < 0.5) {
			return false;	
		}
		// 座標を変換する
		XnPoint3D pt[1] = { joint.position};
		depth_.ConvertRealWorldToProjective(1, pt, pt);
		//std::cout << "X axis:" << pt[0].X << "  " << "Y axis" << pt[0].Y << std::endl;
		if( Calculator(pt) ) {
			return true;
		} else {
			return false;
		}
	}

  // original program to Get coord
	/*
private:
	void getCoord(XnSkeletonJoint eJoint)
	{
	// 各箇所の座標を取得する
	XnSkeletonJointPosition joint;
	skelton_.GetSkeletonJointPosition(player_, eJoint, joint);
    if (joint.fConfidence < 0.5) {
      return;	
    }
	// 座標を変換する
    XnPoint3D pt[1] = { joint.position};
    depth_.ConvertRealWorldToProjective(1, pt, pt);
	std::cout << "RIGHT HAND of X axis:" << pt[0].X << "  " << "Y axis" << pt[0].Y << std::endl;
	}
	*/

private:
  // スケルトンの線を描画する
  void drawLine(XnSkeletonJoint eJoint1, XnSkeletonJoint eJoint2)
  {
    // 各箇所の座標を取得する
    XnSkeletonJointPosition joint1, joint2;
    skelton_.GetSkeletonJointPosition(player_, eJoint1, joint1);
    skelton_.GetSkeletonJointPosition(player_, eJoint2, joint2);
    if (joint1.fConfidence < 0.5 || joint2.fConfidence < 0.5) {
      return;
    }

    // 座標を変換する
    XnPoint3D pt[2] = { joint1.position, joint2.position };
    depth_.ConvertRealWorldToProjective(2, pt, pt);
    cvLine(camera_,cvPoint(pt[0].X, pt[0].Y), cvPoint(pt[1].X, pt[1].Y),
      CV_RGB(0, 0, 0),2,CV_AA ,0);
  }

private:

  IplImage* camera_;
  xn::SkeletonCapability& skelton_;
  xn::DepthGenerator& depth_;
  XnUserID player_;
};

#endif // #ifndef SKELTONDRAWER_H_INCLUDE
// （！）ここまでがコピーです。

void passage::passage_main ()
{

      // 画像データの取得
      xn::ImageMetaData imageMD;
      image.GetMetaData(imageMD);
	

      // ユーザーデータの取得
      xn::SceneMetaData sceneMD;
      user.GetUserPixels(0, sceneMD);
	  

      // カメラ画像の表示
      char* dest = camera->imageData;
      const xn::RGB24Map& rgb = imageMD.RGB24Map();
      for (int y = 0; y < imageMD.YRes(); ++y) {
        for (int x = 0; x < imageMD.XRes(); ++x) {
          // ユーザー表示
          XnLabel label = sceneMD(x, y);
          if (!isShowUser) {
            label = 0;
          }

          // カメラ画像の表示
          XnRGB24Pixel pixel = rgb(x, y);
          if (!isShowImage) {
            pixel = xnRGB24Pixel( 255, 255, 255 );
          }

          // 出力先に描画
          dest[0] = pixel.nRed   * Colors[label][0];
          dest[1] = pixel.nGreen * Colors[label][1];
          dest[2] = pixel.nBlue  * Colors[label][2];
          dest += 3;
		  
        }
      }

      // スケルトンの描画
      if (isShowSkelton) {
        XnUserID aUsers[15];
        XnUInt16 nUsers = 15;
        user.GetUsers(aUsers, nUsers);
        for (int i = 0; i < nUsers; ++i) {
          if (skelton.IsTracking(aUsers[i])) {
            SkeltonDrawer skeltonDrawer(camera, skelton,
              g_DepthGenerator, aUsers[i]);
            skeltonDrawer.draw();
          }
        }
      }


      ::cvCvtColor(camera, camera, CV_BGR2RGB);
      ::cvShowImage("KinectImage", camera);   //キャリブレーションのウィンドウの有無
	  //コメントアウトすると隠れます。

	  // キーイベント
      key = cvWaitKey(10);
      // 終了する
      if (key == 'q') {
        //break;
      }
      // 表示する/しないの切り替え
      else if (key == 'i') {
        isShowImage = !isShowImage;
      }
      else if (key == 'u') {
        isShowUser = !isShowUser;
      }
      else if (key == 's') {
        isShowSkelton = !isShowSkelton;
      }

}

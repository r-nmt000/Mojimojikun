#pragma once
#include <map>
#include <list>
#include <XnCppWrapper.h>
#include <XnVPointControl.h>
#pragma once
class MenuIcon
{
public:
	MenuIcon(XnUInt32 nHistorySize, xn::DepthGenerator depthGenerator);
	~MenuIcon(void);

	void SetUserID(XnUserID userid);
	void GetUserID(XnUserID userid);
	XnFloat* GetPositionBuffer();
	void OnPointUpdate();
	bool ComparePosition( XnFloat Str, XnFloat Des, XnFloat EMargin ) const;
	void DrawGage(int Current, int MaxBuf, float XPos, float YPos) const;
	bool SelectMenu(int MaxBuf, float XPos, float YPos) const;
	void DrawIconTexture(float Xpos, float Ypos);
	void DrawMenuIcon();
	void Update();

protected:
	// トラッキングする手の前の位置を覚えとく変数
	XnUInt32 m_nHistorySize;
	// previous positions per hand
	//　手が前にあった場所を示す。恐らく手が通った道を示すのに使われる
	std::map<XnUInt32, std::list<XnPoint3D> > m_History;
	// Source of the depth map
	xn::DepthGenerator m_DepthGenerator;
	//アイコン位置データを保存するバッファ
	XnFloat* m_pfPositionBuffer;
	//メニューアイコンを操作するユーザーのID
	XnUserID UserID;
	XnBool m_bDrawDM;
	XnBool m_bFrameID;
};


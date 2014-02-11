/*******************************************************************************
*                                                                              *
*   PrimeSense NITE 1.3 - Point Viewer Sample                                  *
*   Copyright (C) 2010 PrimeSense Ltd.                                         *
*                                                                              *
*******************************************************************************/
#pragma once
#ifndef XNV_POINT_DRAWER_H_
#define XNV_POINT_DRAWER_H_

#include <map>
#include <list>
#include <XnCppWrapper.h>
#include <XnVPointControl.h>

typedef enum
{
	IN_SESSION,
	NOT_IN_SESSION,
	QUICK_REFOCUS
} SessionState;

void PrintSessionState(SessionState eState);
/**
 * This is a point control, which stores the history of every point
 * It can draw all the points as well as the depth map.
 */
class XnVPointDrawer : public XnVPointControl
{
public:
	//コンストラクタ
	XnVPointDrawer(XnUInt32 nHistorySize, xn::DepthGenerator depthGenerator);
	//デストラクタ
	virtual ~XnVPointDrawer();

	/**
	 * Handle a new message.
	 * Calls other callbacks for each point, then draw the depth map (if needed) and the points
	 */
	void Update(XnVMessage* pMessage);

	/**
	 * Handle creation of a new point
	 */
	void OnPointCreate(const XnVHandPointContext* cxt);
	/**
	 * Handle new position of an existing point
	 */
	void OnPointUpdate(const XnVHandPointContext* cxt);
	/**
	 * Handle destruction of an existing point
	 */
	void OnPointDestroy(XnUInt32 nID);

	/**
	 * Draw the points, each with its own color.
	 */
	void Draw() const;

	BOOL ComparePosition( XnFloat Str, XnFloat Des, XnFloat EMargin ) const;

	//メニューを選択しているかどうかを判定
	BOOL SelectMenu(int MaxBuf, float XPos, float YPos) const;
	//選択中ゲージの表示
	void DrawGage(int Current, int MaxBuf, float XPos, float YPos)const;

	/**
	 * Change mode - should draw the depth map?
	 */
	void SetDepthMap(XnBool bDrawDM);
	/**
	 * Change mode - print out the frame id
	 */
	void SetFrameID(XnBool bFrameID);

	XnFloat* GetPositionBuffer();
protected:
	// トラッキングする手の前の位置を覚えとく変数
	XnUInt32 m_nHistorySize;
	// previous positions per hand
	//　手が前にあった場所を示す。恐らく手が通った道を示すのに使われる
	std::map<XnUInt32, std::list<XnPoint3D> > m_History;
	// Source of the depth map
	xn::DepthGenerator m_DepthGenerator;
	XnFloat* m_pfPositionBuffer;

	XnBool m_bDrawDM;
	XnBool m_bFrameID;
};

#endif

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
	//�R���X�g���N�^
	XnVPointDrawer(XnUInt32 nHistorySize, xn::DepthGenerator depthGenerator);
	//�f�X�g���N�^
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

	//���j���[��I�����Ă��邩�ǂ����𔻒�
	BOOL SelectMenu(int MaxBuf, float XPos, float YPos) const;
	//�I�𒆃Q�[�W�̕\��
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
	// �g���b�L���O�����̑O�̈ʒu���o���Ƃ��ϐ�
	XnUInt32 m_nHistorySize;
	// previous positions per hand
	//�@�肪�O�ɂ������ꏊ�������B���炭�肪�ʂ������������̂Ɏg����
	std::map<XnUInt32, std::list<XnPoint3D> > m_History;
	// Source of the depth map
	xn::DepthGenerator m_DepthGenerator;
	XnFloat* m_pfPositionBuffer;

	XnBool m_bDrawDM;
	XnBool m_bFrameID;
};

#endif

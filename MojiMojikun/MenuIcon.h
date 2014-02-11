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
	// �g���b�L���O�����̑O�̈ʒu���o���Ƃ��ϐ�
	XnUInt32 m_nHistorySize;
	// previous positions per hand
	//�@�肪�O�ɂ������ꏊ�������B���炭�肪�ʂ������������̂Ɏg����
	std::map<XnUInt32, std::list<XnPoint3D> > m_History;
	// Source of the depth map
	xn::DepthGenerator m_DepthGenerator;
	//�A�C�R���ʒu�f�[�^��ۑ�����o�b�t�@
	XnFloat* m_pfPositionBuffer;
	//���j���[�A�C�R���𑀍삷�郆�[�U�[��ID
	XnUserID UserID;
	XnBool m_bDrawDM;
	XnBool m_bFrameID;
};


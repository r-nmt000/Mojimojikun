#pragma once
#include <glut.h>
#include "Macro.h"



typedef struct POSITION{
	float mXPos;
	float mYPos;
} Position, *pPosition;

typedef struct _SIZE{
	float mVLen;
	float mSpace;
}Size;
class MenuItem
{
public:
	//�R���X�g���N�^
	//�������郁�j���[�A�C�e���i������j���w��
	MenuItem(const char* String, const float XPos, const float YPos, const float* Size );
	MenuItem(const char* String, const float XPos, const float YPos, const float mvXPos, const float mvYPos, const float* Size, const int Speed );
	MenuItem(const char* String, const float* fColor, const float XPos, const float YPos, const float* Size);
	//�f�X�g���N�^
	~MenuItem();
	//�F��ݒ�
	void SetColor(const float* fColor);

	//�������ݒ�
	void SetString(const char* String);
	//�����񍶏�̍��W��ݒ�
	void SetLUPosition( const float XPos, const float YPos );
	//������E���̍��W��ݒ�
	void SetRDPosition( const float XPos, const float YPos );
	//�ړ���̍��W���w��
	void SetMVPosition( const float XPos, const float YPos );
	//�����̑傫����ݒ�
	void SetSize( const float Length, const float Space );
	//�ړ��X�s�[�h�ݒ�
	void SetSpeed(const int Speed);
	//�ړ��X�s�[�h�擾
	int GetSpeed();
	//���[�u�t���O�ݒ�
	void SetMove( bool Flg );
	//������̕\���t���O��ݒ�
	void SetDrawable( bool Flg );
	//����t���O�ݒ�
	void SetSoundFlg( const bool Flg );
	//����t���O�擾
	bool GetSoundFlg();
	//�|�C���^�����j���[�A�C�e���̏�ɂ��邩����
	bool PointOnItem( float* m_pfPositionBuffer );
	//������𓮂���
	void Move( const float XDes, const float YDes, const bool UpDown, const bool LastStr );
	//�I�u�W�F�N�g�̕`��
	void Draw();
	//1������ݒ�
	void SetChar(const char Charactor);
	//��{�|���S���̕`��
	void SetBox(const int Col, const int Row, const float XPos, const float YPos, const float VLen);
	
protected:
	//�����̐F
	float m_Color[3];
	//������
	char m_String[128];
	//������
	int m_StrNum;
	//�����񍶏�̍��W
	Position m_LUPosition;
	//������E���̍��W
	Position m_RDPosition;
	//�����񍶏�̍��W�i�ړ���j
	Position m_MVPosition;
	//�����̑傫��
	Size m_Size;
	//�ړ��X�s�[�h
	float m_Speed;
	//�ړ�����
	float m_Distance;
	//�`�悷�邩�ۂ�
	bool m_Drawable;
	//�ړ������邩�ǂ���
	bool m_Moveable;
	//�����ԃt���O
	bool m_SoundFlg;
};
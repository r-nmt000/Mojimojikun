#pragma once

#pragma once
#include <Windows.h>
#include <stdlib.h>
#include "glut.h"

#define PICTURE_HEIGHT 480
#define PICTURE_WIDTH  640
#define DRAW_OFFSET_X -2
#define DRAW_OFFSET_Y 3
#define VIRTEX_LENGTH 0.00625
#define VIRTEX_FULL_LENGTH 4
//WALL_HEIGHT 1.5
//WALL_WIDTH    2


/*
//BITMAPFILEHEADER�\����
WORD    bfType; //�r�b�g�}�b�v��\���� :0x4D42
DWORD   bfSize; //�r�b�g�}�b�v�t�@�C���̃T�C�Y
WORD    bfReserved1;//�\�񂳂�Ă��� :0
WORD    bfReserved2;//�\�񂳂�Ă��� :0
DWORD   bfOffBits;//�r�b�g�񂪊i�[����Ă���ʒu��\��


//BITMAPINFOHEADER�\����
DWORD  biSize; //�\���̂̃T�C�Y
LONG   biWidth; //�r�b�g�}�b�v�̕�(�s�N�Z��)
LONG   biHeight; //�r�b�g�}�b�v�̍���(�s�N�Z��)
WORD   biPlanes; //���1
WORD   biBitCount; //1�s�N�Z���ӂ�̃r�b�g��
DWORD  biCompression;//���k�`�� �����k�Ȃ��BI_RGB(16,256�F�̏ꍇ) 
DWORD  biSizeImage;//�摜�̃o�C�g�� biCompression��BI_RGB�̏ꍇ��0�ł��悢  
LONG   biXPelsPerMeter;//X������1�s�N�Z���ӂ�̃��[�g���� 
LONG   biYPelsPerMeter;//Y������1�s�N�Z���ӂ�̃��[�g���� 
DWORD  biClrUsed;//�J���[�e�[�u���Ɋ܂܂��F�̐�(0�ꍇ�͂��̌^�̍ő�ɂȂ�) 
DWORD  biClrImportant; //�d�v�ȐF�̐� 0�̏ꍇ�͑S���d�v

*/
class NomoWall
{
public:
	NomoWall(CHAR* FileName);
	~NomoWall(void);
    BOOL Load(char*,HDC);
    void Draw(double ichi);
	void ConvertLittleToBigEndian(BYTE* pBits, int number);
	BYTE       pByte[PICTURE_HEIGHT][PICTURE_WIDTH];
private:
    void Free();
    BITMAPINFO *pBmpInfo;
    
    HBITMAP BMP;
    HANDLE m_hFile;
	HDC m_HDC;
    int used;

private:
	int Width(){return pBmpInfo->bmiHeader.biWidth;}
	int Height(){return pBmpInfo->bmiHeader.biHeight;}
    int Num(){return used;}
};


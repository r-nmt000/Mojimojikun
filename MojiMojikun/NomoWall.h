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
//BITMAPFILEHEADER構造体
WORD    bfType; //ビットマップを表す数 :0x4D42
DWORD   bfSize; //ビットマップファイルのサイズ
WORD    bfReserved1;//予約されている :0
WORD    bfReserved2;//予約されている :0
DWORD   bfOffBits;//ビット列が格納されている位置を表す


//BITMAPINFOHEADER構造体
DWORD  biSize; //構造体のサイズ
LONG   biWidth; //ビットマップの幅(ピクセル)
LONG   biHeight; //ビットマップの高さ(ピクセル)
WORD   biPlanes; //常に1
WORD   biBitCount; //1ピクセル辺りのビット数
DWORD  biCompression;//圧縮形態 無圧縮ならばBI_RGB(16,256色の場合) 
DWORD  biSizeImage;//画像のバイト数 biCompressionがBI_RGBの場合は0でもよい  
LONG   biXPelsPerMeter;//X方向の1ピクセル辺りのメートル数 
LONG   biYPelsPerMeter;//Y方向の1ピクセル辺りのメートル数 
DWORD  biClrUsed;//カラーテーブルに含まれる色の数(0場合はその型の最大になる) 
DWORD  biClrImportant; //重要な色の数 0の場合は全部重要

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


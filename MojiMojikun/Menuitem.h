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
	//コンストラクタ
	//生成するメニューアイテム（文字列）を指定
	MenuItem(const char* String, const float XPos, const float YPos, const float* Size );
	MenuItem(const char* String, const float XPos, const float YPos, const float mvXPos, const float mvYPos, const float* Size, const int Speed );
	MenuItem(const char* String, const float* fColor, const float XPos, const float YPos, const float* Size);
	//デストラクタ
	~MenuItem();
	//色を設定
	void SetColor(const float* fColor);

	//文字列を設定
	void SetString(const char* String);
	//文字列左上の座標を設定
	void SetLUPosition( const float XPos, const float YPos );
	//文字列右下の座標を設定
	void SetRDPosition( const float XPos, const float YPos );
	//移動先の座標を指定
	void SetMVPosition( const float XPos, const float YPos );
	//文字の大きさを設定
	void SetSize( const float Length, const float Space );
	//移動スピード設定
	void SetSpeed(const int Speed);
	//移動スピード取得
	int GetSpeed();
	//ムーブフラグ設定
	void SetMove( bool Flg );
	//文字列の表示フラグを設定
	void SetDrawable( bool Flg );
	//音鳴りフラグ設定
	void SetSoundFlg( const bool Flg );
	//音鳴りフラグ取得
	bool GetSoundFlg();
	//ポインタがメニューアイテムの上にあるか判定
	bool PointOnItem( float* m_pfPositionBuffer );
	//文字列を動かす
	void Move( const float XDes, const float YDes, const bool UpDown, const bool LastStr );
	//オブジェクトの描画
	void Draw();
	//1文字を設定
	void SetChar(const char Charactor);
	//基本ポリゴンの描画
	void SetBox(const int Col, const int Row, const float XPos, const float YPos, const float VLen);
	
protected:
	//文字の色
	float m_Color[3];
	//文字列
	char m_String[128];
	//文字数
	int m_StrNum;
	//文字列左上の座標
	Position m_LUPosition;
	//文字列右下の座標
	Position m_RDPosition;
	//文字列左上の座標（移動先）
	Position m_MVPosition;
	//文字の大きさ
	Size m_Size;
	//移動スピード
	float m_Speed;
	//移動距離
	float m_Distance;
	//描画するか否か
	bool m_Drawable;
	//移動させるかどうか
	bool m_Moveable;
	//音鳴り状態フラグ
	bool m_SoundFlg;
};
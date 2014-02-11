#include "Common.h"
#include <string.h>
#include <Windows.h>

#define CHARACTOR_DEPTH -5
static short PolygonTemplate[][5] =
{
	{ 510,   17,   17,   17,  510 }, /* A */
	{ 511,  273,  273,  273,  238 }, /* B */
	{ 254,  257,  257,  257,  198 }, /* C */
	{ 511,  257,  257,  130,  124 }, /* D */
	{ 511,  273,  273,  273,  273 }, /* E */
	{ 511,   17,   17,   17,    1 }, /* F */
	{ 254,  257,  257,  289,  230 }, /* G */
	{ 511,   16,   16,   16,  511 }, /* H */
	{   0,  257,  511,  257,    0 }, /* I */
	{ 192,  256,  256,  257,  255 }, /* J */
	{ 511,   16,   40,   68,  387 }, /* K */
	{ 511,  256,  256,  256,  256 }, /* L */
	{ 511,   12,   48,   12,  511 }, /* M */
	{ 511,    6,   56,  192,  511 }, /* N */
	{ 254,  257,  257,  257,  254 }, /* O */
	{ 511,   17,   17,   17,   14 }, /* P */
	{ 254,  257,  321,  385,  510 }, /* Q */
	{ 511,   17,   49,   81,  398 }, /* R */
	{ 198,  265,  273,  289,  198 }, /* S */
	{   1,    1,  511,    1,    1 }, /* T */
	{ 255,  256,  256,  256,  255 }, /* U */
	{  31,  224,  256,  224,   31 }, /* V */
	{ 127,  384,  112,  384,  127 }, /* W */
	{ 387,  108,   16,  108,  387 }, /* X */
	{   3,   12,  496,   12,    3 }, /* Y */
	{ 449,  289,  273,  265,  263 }, /* Z */
	{   0,    0,    0,    0,    0 }, /* �� */
};

MenuItem::MenuItem( const char* String, const float XPos, const float YPos, const float* Size ){
	float fColor[3] = {0, 0, 0.5};
	SetString( String );
	SetColor( fColor );
	SetLUPosition( XPos, YPos );
	SetSize( Size[0], Size[1] );
	m_StrNum	= 0;
	m_Speed		= 30;
	m_Drawable  = true;
	m_Moveable	= true;
	m_SoundFlg	= false;
}

MenuItem::MenuItem(const char* String, const float XPos, const float YPos,
					const float mvXPos, const float mvYPos, const float* Size, const int Speed ){

	float fColor[3] = {0, 0, 0.5};
	SetString( String );
	SetColor( fColor );
	SetLUPosition( XPos, YPos );
	SetMVPosition( mvXPos, mvYPos );
	SetSize( Size[0], Size[1] );
	m_StrNum	= 0;
	m_Speed		= Speed;
	m_Drawable  = true;
	m_Moveable	= true;
	m_SoundFlg	= false;
	if( (mvYPos - YPos) < 0 ){
		m_Distance = YPos-mvYPos;
	}
	else{
		m_Distance = mvYPos-YPos;
	}
}
MenuItem::~MenuItem(){};

MenuItem::MenuItem( const char* String, const float* fColor, const float XPos, const float YPos, const float* Size ){
	SetString( String );
	SetColor( fColor );
	SetLUPosition( XPos, YPos );
	SetSize( Size[0], Size[1] );
	m_StrNum	 = 0;
	m_Speed		 = 30;
	m_Drawable	 = true;
	m_Moveable	 = true;
	m_SoundFlg	 = false;
}

/*
    �������\�������`�|���S����`�悵�܂��B
*/
void MenuItem::SetBox(const int Col, const int Row, const float XPos, const float YPos, const float VLen)
{
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(XPos			+ Col * VLen, YPos		 - Row * VLen, CHARACTOR_DEPTH);
	glVertex3f(XPos			+ Col * VLen, YPos-VLen  - Row * VLen, CHARACTOR_DEPTH);
	glVertex3f(XPos+VLen	+ Col * VLen, YPos-VLen  - Row * VLen, CHARACTOR_DEPTH);
	glVertex3f(XPos+VLen	+ Col * VLen, YPos		 - Row * VLen, CHARACTOR_DEPTH);
	glEnd();
}

/*
    �����f�[�^���當���|���S����`�悵�܂��B
*/
void MenuItem::SetChar(const char Ch)
{
	int i, j;
	int Alphabet = Ch - 'A';
	if ( Ch == ' '){
		Alphabet = 26;
	}
	if (('A' <= Ch && Ch <= 'Z') || Ch == ' '){
		for (i = 0; i < 5; i++){
			for (j = 0; j < 9; j++){
				if ((PolygonTemplate[Alphabet][i] >> j) & 1){
					SetBox(i, j, m_LUPosition.mXPos, m_LUPosition.mYPos, m_Size.mVLen);
				}
			}
		}
	}
}

/*
    �啶���p������Ȃ镶�����`�悵�܂��B
*/

void MenuItem::Draw()
{
	const char *p = m_String;
	if( m_Drawable == true ){
		glPushMatrix();
		glColor3f(m_Color[RED], m_Color[GREEN], m_Color[BLUE]);
		//Draw���Ă΂�邽�ё�����̂ł����ŏ�����
		m_StrNum = 0;
		while (*p)
		{
			SetChar((int)*p++);
			glTranslatef(5*m_Size.mVLen+m_Size.mSpace, 0, 0);
			m_StrNum++;
		}
		//���������烁�j���[�A�C�e���̉E���̍��W�����߂�
		SetRDPosition( m_LUPosition.mXPos+m_Size.mVLen*5*m_StrNum+(m_StrNum-1)*m_Size.mSpace, m_LUPosition.mYPos-m_Size.mVLen*9 );
		glPopMatrix();
	}

}

//�\�����镶�����ݒ肵�܂�
void MenuItem::SetString(const char *str)
{
	strcpy( m_String, str );
}



 // ������`�悷��F��ݒ肵�܂��B

void MenuItem::SetColor(const float* fColor)
{
	m_Color[0]	 = fColor[0];
	m_Color[1]	 = fColor[1];
	m_Color[2]	 = fColor[2];
}


void MenuItem::SetDrawable( const bool Flg )
{
	m_Drawable = Flg;
}
//�����񍶏�̍��W��ݒ�
void MenuItem::SetLUPosition( const float XPos, const float YPos )
{
	m_LUPosition.mXPos = XPos;
	m_LUPosition.mYPos = YPos;
}

//������E���̍��W��ݒ�
void MenuItem::SetRDPosition( const float XPos, const float YPos )
{
	m_RDPosition.mXPos = XPos;
	m_RDPosition.mYPos = YPos;
}

//�ړ���̍��W���w��
void MenuItem::SetMVPosition( const float XPos, const float YPos )
{
	m_MVPosition.mXPos = XPos;
	m_MVPosition.mYPos = YPos;
}
//�����̃T�C�Y���w��
void MenuItem::SetSize( const float Length, const float Space ){
	m_Size.mVLen = Length;
	m_Size.mSpace = Space;
}


//�ړ��X�s�[�h�ݒ�
void MenuItem::SetSpeed(const int Speed){
	m_Speed = Speed;
}

//�ړ��X�s�[�h�擾
int MenuItem::GetSpeed(){
	return m_Speed;
}
//���[�u�t���O��ݒ�
void MenuItem::SetMove( bool Flg ){
	m_Moveable = Flg;
}
//����t���O�ݒ�
void MenuItem::SetSoundFlg( const bool Flg ){
	m_SoundFlg = Flg;
}

//����t���O�擾
bool MenuItem::GetSoundFlg( ){
	return m_SoundFlg;
}
//�|�C���^�����j���[�A�C�e���̏�ɂ��邩�ǂ�������
bool MenuItem::PointOnItem( float* m_pfPositionBuffer ){
	bool bRet = false;
	if( m_Drawable ){
		float PosBufX = m_pfPositionBuffer[0];
		float PosBufY = m_pfPositionBuffer[1];

		if( m_LUPosition.mXPos < PosBufX && PosBufX < m_RDPosition.mXPos ){
			if( m_RDPosition.mYPos < PosBufY && PosBufY < m_LUPosition.mYPos ){
				bRet = true;
			}
		}
	}
	return bRet;
}

//Str��Des���I�[�o�[�������ǂ���
bool CheckOverPosition( float Str, float Des, bool UpDown, float* Deff ){
	bool bRet = false;

	if(UpDown == UP){
		*Deff = Des - Str;
	}
	else if(UpDown == DOWN){
		*Deff = Str - Des;
	}

	if( *Deff <= 0){
		bRet = true;
	}
	return bRet;
}
int ChangeOfPace( float Deff, float Distance, bool UpDown, float Speed ){
	//�S�ړ������ƍ�������ړ����������߂�
	float Ratio = (Distance-Deff)/Distance;
	//���̊����ɂ���ăX�s�[�h��ω�������
	Speed = Speed - Speed*sin(Ratio*90*PI/180)/15;
	

	return Speed;
}

//��������w��̈ʒu�Ɉړ�������
//XDes�͍���Ƃ����g�p�����ǂ������[����Ƃ�
void MenuItem::Move(const float XDes, const float YDes, const bool UpDown, const bool LastStr ){
	float Deff = 0;
	if( m_Moveable == true ){
		float YStr = 0;
		if( UpDown == UP ){
			YStr = m_LUPosition.mYPos+m_Speed;
		}
		else if( UpDown == DOWN ){
			YStr = m_LUPosition.mYPos-m_Speed;
		}
		SetLUPosition( m_LUPosition.mXPos, YStr );
		if( CheckOverPosition( YStr, YDes, UpDown, &Deff ) == true ){
			m_Moveable = false;
			if( LastStr == true ){
				if( g_MoveModeFlg1 ){
					g_MoveModeFlg1 = false;
					g_MoveModeFlg2 = true;
				}
				else if( g_MoveModeFlg2  ){
					g_MoveModeFlg2 = false;
					if( g_MainMenuDrawFlg ){
						if( g_LevelDrawFlg || g_PlayNumDrawFlg ){
							g_MainMenuDrawFlg = false;
						}
					}
					else if( g_LevelDrawFlg ){
						g_LevelDrawFlg = false;
						g_MainMenuDrawFlg = true;
					}
					else if( g_PlayNumDrawFlg ){
						g_PlayNumDrawFlg = false;
						g_MainMenuDrawFlg = true;
					}
				}
			}
		}
		m_Speed = ChangeOfPace( Deff, m_Distance, UpDown, m_Speed );
		
	}
}
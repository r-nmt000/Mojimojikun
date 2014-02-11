#include "NomoWall.h"


#include "NomoWall.h"


NomoWall::NomoWall(CHAR* FileName)
{
    pBmpInfo=NULL;
	Load(FileName, m_HDC);
}


NomoWall::~NomoWall(void)
{
    Free();
}


void NomoWall::Free()
{
    //���蓖�Ă��������������������
    if(BMP)
    {
        DeleteObject(BMP);
        BMP=NULL;      
    }
    
    if(pBmpInfo)
    {
        free(pBmpInfo);
        pBmpInfo=NULL;
    }
}

void NomoWall::ConvertLittleToBigEndian(BYTE* pBits, int number){
	for(int i=(PICTURE_HEIGHT-1),ColIterator=0; 0<=i; i--,ColIterator++){
		for(int j=0,RowIterator=0; j<PICTURE_WIDTH; j++,RowIterator++){
			pByte[ColIterator][RowIterator] = *(pBits + (i*(PICTURE_WIDTH)+j));
		}
	}
}
BOOL NomoWall::Load(char*filename,HDC hdc)
{   	    
    int PSize;//�p���b�g�̈�̃T�C�Y
    int BitsSize;//�r�b�g�̈�̃T�C�Y
    int IPSize;//�C���t�H�w�b�_�[�ƃp���b�g�̈�����킹���T�C�Y
	BYTE* pBits;
    DWORD number;
    BITMAPFILEHEADER BmpFileHdr;
    BITMAPINFOHEADER BmpInfoHdr;


    Free();//���蓖�Ă��̈�̉��

    //�t�@�C�����J��
    m_hFile = CreateFileA(filename,GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
    if(m_hFile==INVALID_HANDLE_VALUE) return FALSE;
    //�t�@�C���w�b�_�[��ǂݍ���
    ReadFile(m_hFile,&BmpFileHdr,sizeof BmpFileHdr,&number,NULL);
    //�C���t�H�w�b�_�[��ǂݍ���
    ReadFile(m_hFile,&BmpInfoHdr,sizeof BmpInfoHdr,&number,NULL);
    
    
    //16�F��256�F�����T�|�[�g���܂���(�F�������ߑł����Ă܂�)
    switch (BmpInfoHdr.biBitCount)
    {

		case 8:
			used=256;
			break;
		case 4:
			used=16;
			break;
		default:
			CloseHandle(m_hFile);
			return FALSE;
    }

    //�p���b�g�̈�̃T�C�Y
    PSize=used*sizeof(RGBQUAD);

    //�C���t�H�w�b�_�[�ƁA�p���b�g�̃T�C�Y
    IPSize=sizeof(BITMAPINFOHEADER)+PSize;
    
    //�摜�̃r�b�g�̃T�C�Y
    BitsSize=BmpFileHdr.bfSize-BmpFileHdr.bfOffBits;
    
    //(�w�b�_�[�{�p���b�g)�̗̈���m��
    pBmpInfo=(LPBITMAPINFO)malloc(IPSize);
    memcpy(pBmpInfo,&BmpInfoHdr,sizeof(BITMAPINFOHEADER));//�w�b�_���R�s�[
    //�p���b�g��ǂݍ���
    ReadFile(m_hFile,((LPBYTE)pBmpInfo)+sizeof BITMAPINFOHEADER,PSize,&number,NULL);
    
    //CreateDIBSection���g��
    BMP=CreateDIBSection(hdc,pBmpInfo,DIB_RGB_COLORS,(VOID**)&pBits,0,0);

    //�r�b�g�̈ʒu�܂ŃV�[�N����
    SetFilePointer(m_hFile,BmpFileHdr.bfOffBits,NULL,FILE_BEGIN);

    //�r�b�g��ǂݍ���
    ReadFile(m_hFile,pBits,BitsSize,&number,NULL);
	//�o�b�t�@���烁���o�ϐ��̕��֕ϊ����ĕۑ�
	ConvertLittleToBigEndian(pBits, number);

    CloseHandle(m_hFile);
    return TRUE;
}

void SetWidePolygon(int Col, double ichi){
	//glColor3f( 0,1,1);
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(DRAW_OFFSET_X					, ichi, DRAW_OFFSET_Y					- Col * VIRTEX_LENGTH);
	glVertex3f(DRAW_OFFSET_X					, ichi, DRAW_OFFSET_Y-VIRTEX_LENGTH   - Col * VIRTEX_LENGTH);
	glVertex3f(DRAW_OFFSET_X+VIRTEX_FULL_LENGTH	, ichi, DRAW_OFFSET_Y-VIRTEX_LENGTH   - Col * VIRTEX_LENGTH);
	glVertex3f(DRAW_OFFSET_X+VIRTEX_FULL_LENGTH	, ichi, DRAW_OFFSET_Y					- Col * VIRTEX_LENGTH);
	glEnd();
}

void SetPolygon(int Col, int Row, double ichi, int Continuation){
	int StartRow = Row-Continuation+1;
	float Length = VIRTEX_LENGTH*Continuation;
	//glColor3f( 0,1,1);
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(DRAW_OFFSET_X		+ StartRow * VIRTEX_LENGTH, ichi, DRAW_OFFSET_Y					- Col * VIRTEX_LENGTH);
	glVertex3f(DRAW_OFFSET_X		+ StartRow * VIRTEX_LENGTH, ichi, DRAW_OFFSET_Y-VIRTEX_LENGTH   - Col * VIRTEX_LENGTH);
	glVertex3f(DRAW_OFFSET_X+Length	+ StartRow * VIRTEX_LENGTH, ichi, DRAW_OFFSET_Y-VIRTEX_LENGTH   - Col * VIRTEX_LENGTH);
	glVertex3f(DRAW_OFFSET_X+Length	+ StartRow * VIRTEX_LENGTH, ichi, DRAW_OFFSET_Y					- Col * VIRTEX_LENGTH);
	glEnd();
}

void NomoWall::Draw(double ichi)
{
	int Continuation = 0;
	for(int i=0; i<PICTURE_HEIGHT; i++){
		for(int j=0; j<PICTURE_WIDTH; j++){
			//�w�胁�������u���v(0x1111)��������`��
			
			if( pByte[i][j] != 0 ){
				Continuation++;
				if( PICTURE_WIDTH <= Continuation ){
					SetWidePolygon(i, ichi);
					Continuation = 0;
				}
				else if( j == (PICTURE_WIDTH-1) ){
					SetPolygon(i, j, ichi, Continuation);
					Continuation = 0;
				}
				
			}
			else{
				if(Continuation != 0){
					SetPolygon(i, j-1, ichi, Continuation);
					Continuation = 0;
				}
			}
		}
	}

}


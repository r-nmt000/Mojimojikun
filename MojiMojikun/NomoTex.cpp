#include "NomoTex.h"

GLuint NomoTex::TexNum[2] = {0};
NomoTex::NomoTex(char* FileName, int num)
{
	SetNum(num);
	Load(FileName);
}


NomoTex::~NomoTex(void)
{
	if(Data != NULL){
		free(Data);
	}
}


bool NomoTex::Load(char *FileName) {
 FILE *File;
 unsigned long size;// �C���[�W�̃o�C�g�T�C�Y
 unsigned long i;// �J�E���^
 unsigned short int planes;        //�f�o�C�X�ʐ�
 unsigned short int bpp;            // �s�N�Z����
 char temp;                         // �J���[�֌W��Ɨp
 //�t�@�C���I�[�v��
 if ((File = fopen(FileName, "rb"))==NULL){
  printf("�t�@�C��������܂���");
  return false;
 }
 //�r�b�g�}�b�v�̕��f�[�^�����ֈړ�
 fseek(File, 18, SEEK_CUR);
 //������ǂݍ���
 if ((i = fread(&sizeX, 4, 1, File)) != 1) {
  printf("�ǂݍ��݃G���[");
  return false;
 }
 //�c����ǂݍ���
 if ((i = fread(&sizeY, 4, 1, File)) != 1) {
  printf("�ǂݍ��݃G���[");
  return false;
 }
 //�摜�T�C�Y�̌v�Z
 size = sizeX * sizeY * 3;//�v���[������ǂݍ���
 if ((fread(&planes, 2, 1, File)) != 1) {   //bmp�́u1�v�ɂȂ�
  printf("�v���[�������ǂݍ��߂܂���");
  return false;
 }
 if (planes != 1) {
  printf("�v���[������1�ȊO�ł�");
  return false;
 }
 //�s�N�Z���l��ǂݍ���
 if ((i = fread(&bpp, 2, 1, File)) != 1) {
  printf("�r�b�g�����ǂ߂܂���");
  return false;
 }
 if (bpp != 24) {//24bpp�łȂ���΃G���[
   printf("24�r�b�g�摜�ł͂���܂���");
   return false;
  }
  //24�r�b�g��΂��āA�J���[�f�[�^(RGB)������
  fseek(File, 24, SEEK_CUR);    //�f�[�^�ǂݍ���
  Data = (char *) malloc(size);
  if (Data == NULL) {
   printf("���������m�ۂł��܂���");
   return false;
  }
  if ((i = fread(Data, size, 1, File)) != 1) {
   printf("�f�[�^���ǂ߂܂���");
   return false;
  }
  for (i=0;i<size;i+=3) { //bgr -> rgb
   temp = Data[i];
   Data[i] = Data[i+2];
   Data[i+2] = temp;
  }
  fclose(File);
  return true;
}

void NomoTex::SetNum(int num)
{
	Num = num;
}

void NomoTex::TexSet()
{
	 glEnable( GL_TEXTURE_2D );
	 glGenTextures( 1, &TexNum[Num] );
	 glBindTexture( GL_TEXTURE_2D, TexNum[Num] );
	 glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	 glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	 glTexImage2D( GL_TEXTURE_2D, 0, 3, sizeX, sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Data );
	 //glBindTexture( GL_TEXTURE_2D, 0 );

}

GLuint NomoTex::GetTexNum()
{
	return TexNum[Num];
}

void NomoTex::DeleteTex()
{
	glDeleteTextures( 1, &TexNum[Num] );
}
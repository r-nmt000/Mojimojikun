#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <glut.h>

class BMP
{
public:
  unsigned long sizeX;  //��
  unsigned long sizeY; //�c
  char *Data;  //�摜�f�[�^�i�[
  bool Load(char *filename);
  GLuint texture;
  void TexSet();
  BMP(char *FileName);

};


#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <glut.h>

#pragma once
class NomoTex
{
public:
	NomoTex(char* FileName, int num);
	~NomoTex(void);

	bool Load(char *filename);
	void SetNum(int num);
	void DeleteTex();
	GLuint GetTexNum();
	void TexSet();
private:
	unsigned long sizeX;  //‰¡
	unsigned long sizeY; //c
	char *Data;  //‰æ‘œƒf[ƒ^Ši”[
	static GLuint TexNum[2];
	int Num;

};


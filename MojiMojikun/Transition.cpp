#include "Transition.h"

void Menu_IncrementDarkTransition(float* Darkness){
	glDepthMask(GL_FALSE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//暗くする
	glBegin( GL_POLYGON );
		glColor4f(0, 0, 0, *Darkness);         
		glVertex3f( 0, 0, 0);  //左下
		glVertex3f( 640, 0, 0);  //右下
		glVertex3f( 640, 480, 0);  //右上
		glVertex3f(  0, 480, 0);  //左上
	glEnd();
	glDisable(GL_BLEND);
	glDepthMask(GL_TRUE);
	*Darkness += 0.01;
}

void Menu_DecrementDarkTransition(float* Darkness){
	glDepthMask(GL_FALSE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//明るくする
	glBegin( GL_POLYGON );
		glColor4f(0, 0, 0, *Darkness);         
		glVertex3f( 0, 0, 0);  //左下
		glVertex3f( 640, 0, 0);  //右下
		glVertex3f( 640, 480, 0);  //右上
		glVertex3f(  0, 480, 0);  //左上
	glEnd();
	glDisable(GL_BLEND);
	glDepthMask(GL_TRUE);
	*Darkness -= 0.01;
}

void Game_DecrementDarkTransition(float* Darkness){
	glDepthMask(GL_FALSE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//明るくする
	glBegin( GL_POLYGON );
		glColor4f(0, 0, 0, *Darkness);         
		glVertex3f( -10, 0, -10);  //左下
		glVertex3f( 10, 0, -10);  //右下
		glVertex3f( 10, 0, 10);  //右上
		glVertex3f(  -10, 0, 10);  //左上
	glEnd();
	glDisable(GL_BLEND);
	glDepthMask(GL_TRUE);
	*Darkness -= 0.005;
}

void Game_IncrementDarkTransition(float* Darkness){
	glDepthMask(GL_FALSE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//暗くする
	glBegin( GL_POLYGON );
		glColor4f(0, 0, 0, *Darkness);         
		glVertex3f( -10, 0, -10);  //左下
		glVertex3f( 10, 0, -10);  //右下
		glVertex3f( 10, 0, 10);  //右上
		glVertex3f(  -10, 0, 10);  //左上
	glEnd();
	glDisable(GL_BLEND);
	glDepthMask(GL_TRUE);
	*Darkness += 0.005;
}

#pragma once
#include <windows.h>
#include <mmsystem.h>

#include <iostream>
#include <glut.h>

//#include "common.h"
#include "BMP.h"
#include "Wall.h"

   //#define WAIT_TIME  ( 33 )     //フレームレート 30fps

class GamePlay
{
private:
   static void GameInit();
   static void idle();
   static void Road();
   static void Kabe();
   static void Sky();
   static void clash(int HP);
   static void mizubashira();
   static void ScoreBoard();
public:
   static void Gamedisplay();
   static void game_update();
};


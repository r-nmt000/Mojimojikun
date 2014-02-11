#pragma once
#include <glut.h>

class Wall
{
public:
	Wall(void);
	static void T_wall(double x, double y, double z);
	static void X_wall(double x, double y, double z);
	static void Y_wall(double x, double y, double z);
	static void H_wall(double x, double y, double z);
	static void K_wall(double x, double y, double z);

	static void V_wall(double x, double y, double z);
	static void KagiR_wall(double x, double y, double z);
	static void KagiL_wall(double x, double y, double z);
	static void Kune_wall(double x, double y, double z);
	static void Rikishi_wall(double x, double y, double z);

	static void Manji_wall(double x, double y, double z);
    static void GyakuManji_wall(double x, double y, double z);
    static void Baseball_wall(double x, double y, double z);
    static void Monsterball_wall(double x, double y, double z);
    static void Move_wall(double x, double y, double z, double s);
private:

};


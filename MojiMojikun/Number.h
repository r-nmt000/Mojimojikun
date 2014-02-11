#pragma once
#include "common.h"
void one(double x, double y, double z){
    float diffuse[]={1,1,1,1};

    diffuse[0] = 1.0; diffuse[1] = 0.5; diffuse[2] = 0.5;
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE  , diffuse);

    glPushMatrix();
    glTranslatef( x+1, y, z+1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x+1, y, z-1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();
}

void two(double x, double y, double z){
    float diffuse[]={1,1,1,1};

    diffuse[0] = 1.0; diffuse[1] = 0.5; diffuse[2] = 0.5;
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE  , diffuse);

    glPushMatrix();
    glTranslatef( x+1, y, z+1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x, y, z+2);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x, y, z);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x-1, y, z-1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x, y, z-2);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();
}

void three(double x, double y, double z){
    float diffuse[]={1,1,1,1};

    diffuse[0] = 1.0; diffuse[1] = 0.5; diffuse[2] = 0.5;
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE  , diffuse);

    glPushMatrix();
    glTranslatef( x, y, z+2);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x, y, z);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x, y, z-2);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x+1, y, z+1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x+1, y, z-1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();
}

void four(double x, double y, double z){
    float diffuse[]={1,1,1,1};

    diffuse[0] = 1.0; diffuse[1] = 0.5; diffuse[2] = 0.5;
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE  , diffuse);

    glPushMatrix();
    glTranslatef( x, y, z);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x-1, y, z+1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x+1, y, z+1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x+1, y, z-1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();
}

void five(double x, double y, double z){
    float diffuse[]={1,1,1,1};

    diffuse[0] = 1.0; diffuse[1] = 0.5; diffuse[2] = 0.5;
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE  , diffuse);

    glPushMatrix();
    glTranslatef( x, y, z+2);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x, y, z);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x, y, z-2);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x-1, y, z+1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x+1, y, z-1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();
}

void six(double x, double y, double z){
    float diffuse[]={1,1,1,1};

    diffuse[0] = 1.0; diffuse[1] = 0.5; diffuse[2] = 0.5;
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE  , diffuse);

    glPushMatrix();
    glTranslatef( x, y, z+2);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x, y, z);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x, y, z-2);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x-1, y, z+1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x-1, y, z-1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x+1, y, z-1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();
}

void seven(double x, double y, double z){
    float diffuse[]={1,1,1,1};

    diffuse[0] = 1.0; diffuse[1] = 0.5; diffuse[2] = 0.5;
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE  , diffuse);

    glPushMatrix();
    glTranslatef( x, y, z+2);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x-1, y, z+1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x+1, y, z+1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x+1, y, z-1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();
}

void eight(double x, double y, double z){
    float diffuse[]={1,1,1,1};

    diffuse[0] = 1.0; diffuse[1] = 0.5; diffuse[2] = 0.5;
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE  , diffuse);

    glPushMatrix();
    glTranslatef( x, y, z+2);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x, y, z);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x, y, z-2);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x-1, y, z+1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x+1, y, z+1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x-1, y, z-1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x+1, y, z-1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();
}

void nine(double x, double y, double z){
    float diffuse[]={1,1,1,1};

    diffuse[0] = 1.0; diffuse[1] = 0.5; diffuse[2] = 0.5;
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE  , diffuse);

    glPushMatrix();
    glTranslatef( x, y, z+2);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x, y, z);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x, y, z-2);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x-1, y, z+1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x+1, y, z+1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x+1, y, z-1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();
}

void zero(double x, double y, double z){
    float diffuse[]={1,1,1,1};

    diffuse[0] = 1.0; diffuse[1] = 0.5; diffuse[2] = 0.5;
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE  , diffuse);

    glPushMatrix();
    glTranslatef( x, y, z+2);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x, y, z-2);
    glScalef(2, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x-1, y, z+1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x+1, y, z+1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x-1, y, z-1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( x+1, y, z-1);
    glScalef(0.5, 0.5, 2);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();
}
#include "Wall.h"

#define WALL_WIDTH  2
#define WALL_HEIGHT 3

Wall::Wall(void)
{
}

void Wall::T_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 0.0, 1.0, 1.0); 
		glBegin( GL_POLYGON );       
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     -WALL_WIDTH, 0, WALL_HEIGHT);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, WALL_HEIGHT);  //右上
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     WALL_WIDTH, 0, WALL_HEIGHT);  //左上
            glVertex3f( WALL_WIDTH-0.5, 0, WALL_HEIGHT);  //右上
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );       
		    glVertex3f( -WALL_WIDTH+0.5, 0, WALL_HEIGHT-0.3);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, WALL_HEIGHT);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, WALL_HEIGHT);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, WALL_HEIGHT-0.3);  //右下
        glEnd();

		glBegin( GL_POLYGON );      
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, WALL_HEIGHT-1);  //左上
            glVertex3f( -WALL_WIDTH+1.5, 0, WALL_HEIGHT-1);  //右上
		    glVertex3f( -WALL_WIDTH+1.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );      
		    glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //左下
		    glVertex3f(  WALL_WIDTH-0.5, 0, WALL_HEIGHT-1);  //左上
            glVertex3f(  WALL_WIDTH-1.5, 0, WALL_HEIGHT-1);  //右上
		    glVertex3f(  WALL_WIDTH-1.5, 0, 0.0);  //右下
        glEnd();

		glPopMatrix();
}

void Wall::X_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

		glColor3f( 0.0, 1.0, 1.0); 
		glBegin( GL_POLYGON );            
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //右上
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );       
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );    
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右下
        glEnd();

		glBegin( GL_POLYGON );      
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左上
            glVertex3f( -WALL_WIDTH+1.5, 0, 1.4);  //右
        glEnd();

		glBegin( GL_POLYGON );     
	        glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //右下
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右上
            glVertex3f(  WALL_WIDTH-1.5, 0, 1.4);  //ひだり
        glEnd();

	    glBegin( GL_POLYGON );     
	        glVertex3f( -WALL_WIDTH+1.0, 0, 2.7);  //左上
		    glVertex3f(  WALL_WIDTH-1.0, 0, 2.7);  //右上
            glVertex3f(               0, 0, 2.0);  //下
        glEnd();

	    glBegin( GL_POLYGON );     
	        glVertex3f( -WALL_WIDTH+1.0, 0,   0);  //左上
		    glVertex3f(  WALL_WIDTH-1.0, 0,   0);  //右上
            glVertex3f(               0, 0, 1.0);  //下
        glEnd();

		glPopMatrix();


}

void Wall::Y_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 0.0, 1.0, 1.0); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //右上
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右下
        glEnd();

		glBegin( GL_POLYGON );     
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左上
            glVertex3f( -WALL_WIDTH+1.6, 0, 1.4);  //右上
            glVertex3f( -WALL_WIDTH+1.6, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );   
		    glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //左下
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //左上
            glVertex3f(  WALL_WIDTH-1.6, 0, 1.4);  //右上
            glVertex3f(  WALL_WIDTH-1.6, 0, 0.0);  //右下
        glEnd();

	    glBegin( GL_POLYGON );        
	        glVertex3f( -WALL_WIDTH+1.0, 0, 2.7);  //左上
		    glVertex3f(  WALL_WIDTH-1.0, 0, 2.7);  //右上
            glVertex3f(               0, 0, 2.0);  //下
        glEnd();

		glPopMatrix();

}

void Wall::H_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 0.0, 1.0, 1.0); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //右上
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右下
        glEnd();
		//上まで縁

	    glBegin( GL_POLYGON );     
	        glVertex3f( -WALL_WIDTH+1.25, 0,   0);  //左下
		    glVertex3f( -WALL_WIDTH+1.25, 0, 1.0);  //左上
            glVertex3f(  WALL_WIDTH-1.25, 0, 1.0);  //右上
            glVertex3f(  WALL_WIDTH-1.25, 0,   0);  //右下
        glEnd();

	    glBegin( GL_POLYGON );     
	        glVertex3f( -WALL_WIDTH+1.25, 0, 2.0);  //左下
		    glVertex3f( -WALL_WIDTH+1.25, 0, 2.7);  //左上
            glVertex3f(  WALL_WIDTH-1.25, 0, 2.7);  //右上
            glVertex3f(  WALL_WIDTH-1.25, 0, 2.0);  //右下
        glEnd();

		glPopMatrix();

}

void Wall::K_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 0.0, 1.0, 1.0); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //右上
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右下
        glEnd();
		//上まで縁

	    glBegin( GL_POLYGON );     
	        glVertex3f( -WALL_WIDTH+1.0, 0,   0);  //左上
		    glVertex3f( -WALL_WIDTH+1.0, 0, 1.2);  //左上
            glVertex3f(  WALL_WIDTH-1.0, 0, 0.0);  //右下
        glEnd();

	    glBegin( GL_POLYGON );     
	        glVertex3f( -WALL_WIDTH+1.0, 0, 2.7);  //左上
		    glVertex3f( -WALL_WIDTH+1.0, 0, 2.0);  //左下
            glVertex3f(  WALL_WIDTH-1.0, 0, 2.7);  //右上
        glEnd();

		glBegin( GL_POLYGON );     
	        glVertex3f(  WALL_WIDTH-1.8, 0, 1.5);  //左
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右上
            glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glPopMatrix();
}

void Wall::V_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 0.9, 0.9, 0.3); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //右上
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右下
        glEnd();
		//上まで縁

	    glBegin( GL_POLYGON );        
	        glVertex3f( -WALL_WIDTH+1.0, 0, 2.7);  //左上
		    glVertex3f(  WALL_WIDTH-1.0, 0, 2.7);  //右上
            glVertex3f(               0, 0, 1.0);  //下
        glEnd();

	    glBegin( GL_POLYGON );        
	        glVertex3f( -WALL_WIDTH+1.0, 0, 2.7);  //左上
		    glVertex3f(  WALL_WIDTH-1.0, 0, 2.7);  //右上
            glVertex3f(               0, 0, 1.0);  //下
        glEnd();

	    glBegin( GL_POLYGON );        
            glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左上
		    glVertex3f( -WALL_WIDTH+1.5, 0, 0.0);  //右下
            glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //下
        glEnd();

	    glBegin( GL_POLYGON );        
            glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //左上
		    glVertex3f(  WALL_WIDTH-1.5, 0, 0.0);  //右下
            glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //下
        glEnd();

		glPopMatrix();
}

void Wall::KagiR_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 0.9, 0.9, 0.3); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //右上
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右下
        glEnd();
		//上まで縁

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.0);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.5, 0, 0.0);  //左下
		    glVertex3f( -WALL_WIDTH+1.5, 0, 1.0);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 1.0);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glPopMatrix();
}

void Wall::KagiL_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 0.9, 0.9, 0.3); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //右上
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右下
        glEnd();
		//上まで縁

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.0);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.5, 0, 0.0);  //左下
		    glVertex3f(  WALL_WIDTH-1.5, 0, 1.0);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 1.0);  //右上
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //右下
        glEnd();

		glPopMatrix();
}

void Wall::Kune_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 0.9, 0.9, 0.3); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //右上
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右下
        glEnd();
		//上まで縁

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+2.0, 0, 2.0);  //左下
		    glVertex3f( -WALL_WIDTH+2.0, 0, 2.7);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.0);  //左上
            glVertex3f(  WALL_WIDTH-2.0, 0, 1.0);  //右上
		    glVertex3f(  WALL_WIDTH-2.0, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.0);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左上
            glVertex3f( -WALL_WIDTH+1.0, 0, 2.7);  //右上
		    glVertex3f( -WALL_WIDTH+1.0, 0, 2.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.0, 0, 0.0);  //左下
		    glVertex3f(  WALL_WIDTH-1.0, 0, 1.0);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 1.0);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glPopMatrix();
}

void Wall::Rikishi_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 0.9, 0.9, 0.3); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //右上
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右下
        glEnd();
		//上まで縁

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.2);  //左下
		    glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //左上
            glVertex3f(  WALL_WIDTH-1.75, 0, 3.0);  //右上
		    glVertex3f(  WALL_WIDTH-1.75, 0, 2.2);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.2);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //左上
            glVertex3f( -WALL_WIDTH+1.75, 0, 3.0);  //右上
		    glVertex3f( -WALL_WIDTH+1.75, 0, 2.2);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.0, 0, 0.0);  //左下
		    glVertex3f( -WALL_WIDTH+1.0, 0, 0.8);  //左上
            glVertex3f( -WALL_WIDTH+1.6, 0, 0.4);  //右上
		    glVertex3f( -WALL_WIDTH+1.6, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.0, 0, 0.0);  //左下
		    glVertex3f(  WALL_WIDTH-1.0, 0, 0.8);  //左上
            glVertex3f(  WALL_WIDTH-1.6, 0, 0.4);  //右上
		    glVertex3f(  WALL_WIDTH-1.6, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.6, 0, 0.0);  //左下
		    glVertex3f(  WALL_WIDTH-1.6, 0, 0.4);  //左上
            glVertex3f( -WALL_WIDTH+1.6, 0, 0.4);  //右上
		    glVertex3f( -WALL_WIDTH+1.6, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.2, 0, 2.2);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.2);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 1.5);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.2, 0, 1.8);  //左下
		    glVertex3f( -WALL_WIDTH+0.9, 0, 1.5);  //左上
            glVertex3f( -WALL_WIDTH+1.2, 0, 1.5);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.2, 0, 1.5);  //左下
		    glVertex3f(  WALL_WIDTH-1.2, 0, 1.7);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 1.7);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 1.5);  //右下
        glEnd();

		glPopMatrix();
}

void Wall::Manji_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 1.0, 0.2, 0.2); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //右上
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右下
        glEnd();
		//上まで縁

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+2.0, 0, 2.0);  //左下
		    glVertex3f( -WALL_WIDTH+2.0, 0, 2.7);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.0);  //左上
            glVertex3f(  WALL_WIDTH-2.0, 0, 1.0);  //右上
		    glVertex3f(  WALL_WIDTH-2.0, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.5);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左上
            glVertex3f( -WALL_WIDTH+1.5, 0, 2.7);  //右上
		    glVertex3f( -WALL_WIDTH+1.5, 0, 1.5);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.5, 0, 0.0);  //左下
		    glVertex3f(  WALL_WIDTH-1.5, 0, 1.5);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 1.5);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glPopMatrix();
}

void Wall::GyakuManji_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 1.0, 0.2, 0.2); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //右上
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右下
        glEnd();
		//上まで縁
		
		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-2.0, 0, 2.0);  //左下
		    glVertex3f(  WALL_WIDTH-2.0, 0, 2.7);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //右上
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.0);  //右下
        glEnd();
		
		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //左下
		    glVertex3f(  WALL_WIDTH-0.5, 0, 1.0);  //左上
            glVertex3f( -WALL_WIDTH+2.0, 0, 1.0);  //右上
		    glVertex3f( -WALL_WIDTH+2.0, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-0.5, 0, 1.5);  //左下
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //左上
            glVertex3f(  WALL_WIDTH-1.5, 0, 2.7);  //右上
		    glVertex3f(  WALL_WIDTH-1.5, 0, 1.5);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.5, 0, 0.0);  //左下
		    glVertex3f( -WALL_WIDTH+1.5, 0, 1.5);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 1.5);  //右上
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //右下
        glEnd();

		glPopMatrix();
}

void Wall::Baseball_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 1.0, 0.2, 0.2); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //右上
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右下
        glEnd();
		//上まで縁

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.2);  //左上
            glVertex3f( -WALL_WIDTH+1.5, 0, 1.2);  //右上
            glVertex3f( -WALL_WIDTH+1.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.5, 0, 0.0);  //左下
		    glVertex3f( -WALL_WIDTH+1.5, 0, 1.2);  //左上
            glVertex3f( -WALL_WIDTH+2.0, 0, 0.6);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.2);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左上
            glVertex3f( -WALL_WIDTH+1.5, 0, 2.7);  //右上
            glVertex3f( -WALL_WIDTH+1.5, 0, 1.2);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+2.0, 0, 2.2);  //左下
		    glVertex3f( -WALL_WIDTH+2.0, 0, 2.7);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右上
            glVertex3f(  WALL_WIDTH-0.5, 0, 2.2);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.5, 0, 0.0);  //左下
		    glVertex3f(  WALL_WIDTH-1.5, 0, 1.8);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 1.8);  //右上
            glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-2.0, 0, 1.2);  //左下
		    glVertex3f(  WALL_WIDTH-1.5, 0, 1.2);  //左上
            glVertex3f(  WALL_WIDTH-1.5, 0, 0.6);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-2.0, 0, 0.0);  //左下
		    glVertex3f(  WALL_WIDTH-1.5, 0, 0.0);  //左上
            glVertex3f(  WALL_WIDTH-1.5, 0, 0.6);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-2.0, 0, 1.2);  //左下
		    glVertex3f(  WALL_WIDTH-1.5, 0, 1.8);  //左上
            glVertex3f(  WALL_WIDTH-1.5, 0, 1.2);  //右上
        glEnd();

	    glPopMatrix();
}

void Wall::Monsterball_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 1.0, 0.2, 0.2); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //右上
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.8);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.8);  //右下
        glEnd();
		//上まで縁

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.75, 0, 0.0);  //左下
		    glVertex3f( -WALL_WIDTH+1.0, 0,  0.3);  //左上
            glVertex3f( -WALL_WIDTH+1.0, 0,  0.0);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.75, 0, 0.0);  //左下
		    glVertex3f(  WALL_WIDTH-1.0, 0,  0.3);  //左上
            glVertex3f(  WALL_WIDTH-1.0, 0,  0.0);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.0, 0, 0.3);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.0);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 0.3);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.0, 0, 0.3);  //左下
		    glVertex3f(  WALL_WIDTH-0.5, 0, 1.0);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 0.3);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.0, 0, 2.5);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.8);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 2.5);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.0, 0, 2.5);  //左下
		    glVertex3f(  WALL_WIDTH-0.5, 0, 1.8);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 2.5);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.75, 0, 2.8);  //左下
		    glVertex3f( -WALL_WIDTH+1.0, 0,  2.5);  //左上
            glVertex3f( -WALL_WIDTH+1.0, 0,  2.8);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.75, 0, 2.8);  //左下
		    glVertex3f(  WALL_WIDTH-1.0, 0,  2.5);  //左上
            glVertex3f(  WALL_WIDTH-1.0, 0,  2.8);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.3);  //左上
            glVertex3f( -WALL_WIDTH+1.0, 0, 0.3);  //右上
		    glVertex3f( -WALL_WIDTH+1.0, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //左下
		    glVertex3f(  WALL_WIDTH-0.5, 0, 0.3);  //左上
            glVertex3f(  WALL_WIDTH-1.0, 0, 0.3);  //右上
		    glVertex3f(  WALL_WIDTH-1.0, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.5);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.8);  //左上
            glVertex3f( -WALL_WIDTH+1.0, 0, 2.8);  //右上
		    glVertex3f( -WALL_WIDTH+1.0, 0, 2.5);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.5);  //左下
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.8);  //左上
            glVertex3f(  WALL_WIDTH-1.0, 0, 2.8);  //右上
		    glVertex3f(  WALL_WIDTH-1.0, 0, 2.5);  //右下
        glEnd();
		//上まで外円

		glPushMatrix();
	    glTranslatef(0, 0, 1.0);
		glScalef(0.3, 0.3, 0.3);
		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.75, 0, 0.0);  //左下
		    glVertex3f( -WALL_WIDTH+1.0, 0,  0.3);  //左上
            glVertex3f( -WALL_WIDTH+1.0, 0,  0.0);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.75, 0, 0.0);  //左下
		    glVertex3f(  WALL_WIDTH-1.0, 0,  0.3);  //左上
            glVertex3f(  WALL_WIDTH-1.0, 0,  0.0);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.0, 0, 0.3);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.0);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 0.3);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.0, 0, 0.3);  //左下
		    glVertex3f(  WALL_WIDTH-0.5, 0, 1.0);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 0.3);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.0, 0, 2.5);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.8);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 2.5);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.0, 0, 2.5);  //左下
		    glVertex3f(  WALL_WIDTH-0.5, 0, 1.8);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 2.5);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.75, 0, 2.8);  //左下
		    glVertex3f( -WALL_WIDTH+1.0, 0,  2.5);  //左上
            glVertex3f( -WALL_WIDTH+1.0, 0,  2.8);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.75, 0, 2.8);  //左下
		    glVertex3f(  WALL_WIDTH-1.0, 0,  2.5);  //左上
            glVertex3f(  WALL_WIDTH-1.0, 0,  2.8);  //右上
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.5, 0, 2.8);  //左下
		    glVertex3f( -WALL_WIDTH+1.5, 0, 2.9);  //左上
            glVertex3f(  WALL_WIDTH-1.5, 0, 2.9);  //右上
		    glVertex3f(  WALL_WIDTH-1.5, 0, 2.8);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.5, 0, 0.0);  //左下
		    glVertex3f( -WALL_WIDTH+1.5, 0, -0.1);  //左上
            glVertex3f(  WALL_WIDTH-1.5, 0, -0.1);  //右上
		    glVertex3f(  WALL_WIDTH-1.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.9);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.9);  //左上
            glVertex3f( -WALL_WIDTH+0.3, 0, 1.9);  //右上
		    glVertex3f( -WALL_WIDTH+0.3, 0, 0.9);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-0.5, 0, 0.9);  //左下
		    glVertex3f(  WALL_WIDTH-0.5, 0, 1.9);  //左上
            glVertex3f(  WALL_WIDTH-0.3, 0, 1.9);  //右上
		    glVertex3f(  WALL_WIDTH-0.3, 0, 0.9);  //右下
        glEnd();

	    glPopMatrix();
		//内側の円

		glBegin( GL_POLYGON );  
		    glVertex3f( -0.03, 0, 1.8);  //左下
		    glVertex3f( -0.03, 0, 3.0);  //左上
            glVertex3f(  0.03, 0, 3.0);  //右上
		    glVertex3f(  0.03, 0, 1.8);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  -0.03, 0, 0.0);  //左下
		    glVertex3f(  -0.03, 0, 1.0);  //左上
            glVertex3f(   0.03, 0, 1.0);  //右上
		    glVertex3f(   0.03, 0, 0.0);  //右下
        glEnd();

	    glPopMatrix();
}

void Wall::Move_wall(double x, double y, double z, double s)
{

		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 1.0, 0.2, 0.2); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //右上
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //左下
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //左上
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //右下
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //左下
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //左上
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //右上
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //右下
        glEnd();
		//上まで縁

		glPushMatrix();
		glTranslatef(s, 0, 0);
		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.7, 0, 0.0);  //左下
		    glVertex3f( -WALL_WIDTH+1.7, 0, 2.7);  //左上
            glVertex3f(  WALL_WIDTH-1.7, 0, 2.7);  //右上
		    glVertex3f(  WALL_WIDTH-1.7, 0, 0.0);  //右下
        glEnd();
        glPopMatrix();

	    glPopMatrix();
}
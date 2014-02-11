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
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     -WALL_WIDTH, 0, WALL_HEIGHT);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, WALL_HEIGHT);  //�E��
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     WALL_WIDTH, 0, WALL_HEIGHT);  //����
            glVertex3f( WALL_WIDTH-0.5, 0, WALL_HEIGHT);  //�E��
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );       
		    glVertex3f( -WALL_WIDTH+0.5, 0, WALL_HEIGHT-0.3);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, WALL_HEIGHT);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, WALL_HEIGHT);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, WALL_HEIGHT-0.3);  //�E��
        glEnd();

		glBegin( GL_POLYGON );      
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, WALL_HEIGHT-1);  //����
            glVertex3f( -WALL_WIDTH+1.5, 0, WALL_HEIGHT-1);  //�E��
		    glVertex3f( -WALL_WIDTH+1.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );      
		    glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //����
		    glVertex3f(  WALL_WIDTH-0.5, 0, WALL_HEIGHT-1);  //����
            glVertex3f(  WALL_WIDTH-1.5, 0, WALL_HEIGHT-1);  //�E��
		    glVertex3f(  WALL_WIDTH-1.5, 0, 0.0);  //�E��
        glEnd();

		glPopMatrix();
}

void Wall::X_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

		glColor3f( 0.0, 1.0, 1.0); 
		glBegin( GL_POLYGON );            
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //�E��
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );       
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );    
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
        glEnd();

		glBegin( GL_POLYGON );      
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
            glVertex3f( -WALL_WIDTH+1.5, 0, 1.4);  //�E
        glEnd();

		glBegin( GL_POLYGON );     
	        glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
            glVertex3f(  WALL_WIDTH-1.5, 0, 1.4);  //�Ђ���
        glEnd();

	    glBegin( GL_POLYGON );     
	        glVertex3f( -WALL_WIDTH+1.0, 0, 2.7);  //����
		    glVertex3f(  WALL_WIDTH-1.0, 0, 2.7);  //�E��
            glVertex3f(               0, 0, 2.0);  //��
        glEnd();

	    glBegin( GL_POLYGON );     
	        glVertex3f( -WALL_WIDTH+1.0, 0,   0);  //����
		    glVertex3f(  WALL_WIDTH-1.0, 0,   0);  //�E��
            glVertex3f(               0, 0, 1.0);  //��
        glEnd();

		glPopMatrix();


}

void Wall::Y_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 0.0, 1.0, 1.0); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //�E��
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
        glEnd();

		glBegin( GL_POLYGON );     
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
            glVertex3f( -WALL_WIDTH+1.6, 0, 1.4);  //�E��
            glVertex3f( -WALL_WIDTH+1.6, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );   
		    glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //����
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //����
            glVertex3f(  WALL_WIDTH-1.6, 0, 1.4);  //�E��
            glVertex3f(  WALL_WIDTH-1.6, 0, 0.0);  //�E��
        glEnd();

	    glBegin( GL_POLYGON );        
	        glVertex3f( -WALL_WIDTH+1.0, 0, 2.7);  //����
		    glVertex3f(  WALL_WIDTH-1.0, 0, 2.7);  //�E��
            glVertex3f(               0, 0, 2.0);  //��
        glEnd();

		glPopMatrix();

}

void Wall::H_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 0.0, 1.0, 1.0); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //�E��
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
        glEnd();
		//��܂ŉ�

	    glBegin( GL_POLYGON );     
	        glVertex3f( -WALL_WIDTH+1.25, 0,   0);  //����
		    glVertex3f( -WALL_WIDTH+1.25, 0, 1.0);  //����
            glVertex3f(  WALL_WIDTH-1.25, 0, 1.0);  //�E��
            glVertex3f(  WALL_WIDTH-1.25, 0,   0);  //�E��
        glEnd();

	    glBegin( GL_POLYGON );     
	        glVertex3f( -WALL_WIDTH+1.25, 0, 2.0);  //����
		    glVertex3f( -WALL_WIDTH+1.25, 0, 2.7);  //����
            glVertex3f(  WALL_WIDTH-1.25, 0, 2.7);  //�E��
            glVertex3f(  WALL_WIDTH-1.25, 0, 2.0);  //�E��
        glEnd();

		glPopMatrix();

}

void Wall::K_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 0.0, 1.0, 1.0); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //�E��
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
        glEnd();
		//��܂ŉ�

	    glBegin( GL_POLYGON );     
	        glVertex3f( -WALL_WIDTH+1.0, 0,   0);  //����
		    glVertex3f( -WALL_WIDTH+1.0, 0, 1.2);  //����
            glVertex3f(  WALL_WIDTH-1.0, 0, 0.0);  //�E��
        glEnd();

	    glBegin( GL_POLYGON );     
	        glVertex3f( -WALL_WIDTH+1.0, 0, 2.7);  //����
		    glVertex3f( -WALL_WIDTH+1.0, 0, 2.0);  //����
            glVertex3f(  WALL_WIDTH-1.0, 0, 2.7);  //�E��
        glEnd();

		glBegin( GL_POLYGON );     
	        glVertex3f(  WALL_WIDTH-1.8, 0, 1.5);  //��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
            glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glPopMatrix();
}

void Wall::V_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 0.9, 0.9, 0.3); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //�E��
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
        glEnd();
		//��܂ŉ�

	    glBegin( GL_POLYGON );        
	        glVertex3f( -WALL_WIDTH+1.0, 0, 2.7);  //����
		    glVertex3f(  WALL_WIDTH-1.0, 0, 2.7);  //�E��
            glVertex3f(               0, 0, 1.0);  //��
        glEnd();

	    glBegin( GL_POLYGON );        
	        glVertex3f( -WALL_WIDTH+1.0, 0, 2.7);  //����
		    glVertex3f(  WALL_WIDTH-1.0, 0, 2.7);  //�E��
            glVertex3f(               0, 0, 1.0);  //��
        glEnd();

	    glBegin( GL_POLYGON );        
            glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
		    glVertex3f( -WALL_WIDTH+1.5, 0, 0.0);  //�E��
            glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //��
        glEnd();

	    glBegin( GL_POLYGON );        
            glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //����
		    glVertex3f(  WALL_WIDTH-1.5, 0, 0.0);  //�E��
            glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //��
        glEnd();

		glPopMatrix();
}

void Wall::KagiR_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 0.9, 0.9, 0.3); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //�E��
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
        glEnd();
		//��܂ŉ�

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.0);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.5, 0, 0.0);  //����
		    glVertex3f( -WALL_WIDTH+1.5, 0, 1.0);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 1.0);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glPopMatrix();
}

void Wall::KagiL_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 0.9, 0.9, 0.3); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //�E��
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
        glEnd();
		//��܂ŉ�

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.0);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.5, 0, 0.0);  //����
		    glVertex3f(  WALL_WIDTH-1.5, 0, 1.0);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 1.0);  //�E��
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //�E��
        glEnd();

		glPopMatrix();
}

void Wall::Kune_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 0.9, 0.9, 0.3); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //�E��
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
        glEnd();
		//��܂ŉ�

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+2.0, 0, 2.0);  //����
		    glVertex3f( -WALL_WIDTH+2.0, 0, 2.7);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.0);  //����
            glVertex3f(  WALL_WIDTH-2.0, 0, 1.0);  //�E��
		    glVertex3f(  WALL_WIDTH-2.0, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.0);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
            glVertex3f( -WALL_WIDTH+1.0, 0, 2.7);  //�E��
		    glVertex3f( -WALL_WIDTH+1.0, 0, 2.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.0, 0, 0.0);  //����
		    glVertex3f(  WALL_WIDTH-1.0, 0, 1.0);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 1.0);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glPopMatrix();
}

void Wall::Rikishi_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 0.9, 0.9, 0.3); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //�E��
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
        glEnd();
		//��܂ŉ�

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.2);  //����
		    glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //����
            glVertex3f(  WALL_WIDTH-1.75, 0, 3.0);  //�E��
		    glVertex3f(  WALL_WIDTH-1.75, 0, 2.2);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.2);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //����
            glVertex3f( -WALL_WIDTH+1.75, 0, 3.0);  //�E��
		    glVertex3f( -WALL_WIDTH+1.75, 0, 2.2);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.0, 0, 0.0);  //����
		    glVertex3f( -WALL_WIDTH+1.0, 0, 0.8);  //����
            glVertex3f( -WALL_WIDTH+1.6, 0, 0.4);  //�E��
		    glVertex3f( -WALL_WIDTH+1.6, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.0, 0, 0.0);  //����
		    glVertex3f(  WALL_WIDTH-1.0, 0, 0.8);  //����
            glVertex3f(  WALL_WIDTH-1.6, 0, 0.4);  //�E��
		    glVertex3f(  WALL_WIDTH-1.6, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.6, 0, 0.0);  //����
		    glVertex3f(  WALL_WIDTH-1.6, 0, 0.4);  //����
            glVertex3f( -WALL_WIDTH+1.6, 0, 0.4);  //�E��
		    glVertex3f( -WALL_WIDTH+1.6, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.2, 0, 2.2);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.2);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 1.5);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.2, 0, 1.8);  //����
		    glVertex3f( -WALL_WIDTH+0.9, 0, 1.5);  //����
            glVertex3f( -WALL_WIDTH+1.2, 0, 1.5);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.2, 0, 1.5);  //����
		    glVertex3f(  WALL_WIDTH-1.2, 0, 1.7);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 1.7);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 1.5);  //�E��
        glEnd();

		glPopMatrix();
}

void Wall::Manji_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 1.0, 0.2, 0.2); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //�E��
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
        glEnd();
		//��܂ŉ�

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+2.0, 0, 2.0);  //����
		    glVertex3f( -WALL_WIDTH+2.0, 0, 2.7);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.0);  //����
            glVertex3f(  WALL_WIDTH-2.0, 0, 1.0);  //�E��
		    glVertex3f(  WALL_WIDTH-2.0, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.5);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
            glVertex3f( -WALL_WIDTH+1.5, 0, 2.7);  //�E��
		    glVertex3f( -WALL_WIDTH+1.5, 0, 1.5);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.5, 0, 0.0);  //����
		    glVertex3f(  WALL_WIDTH-1.5, 0, 1.5);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 1.5);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glPopMatrix();
}

void Wall::GyakuManji_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 1.0, 0.2, 0.2); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //�E��
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
        glEnd();
		//��܂ŉ�
		
		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-2.0, 0, 2.0);  //����
		    glVertex3f(  WALL_WIDTH-2.0, 0, 2.7);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //�E��
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.0);  //�E��
        glEnd();
		
		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //����
		    glVertex3f(  WALL_WIDTH-0.5, 0, 1.0);  //����
            glVertex3f( -WALL_WIDTH+2.0, 0, 1.0);  //�E��
		    glVertex3f( -WALL_WIDTH+2.0, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-0.5, 0, 1.5);  //����
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //����
            glVertex3f(  WALL_WIDTH-1.5, 0, 2.7);  //�E��
		    glVertex3f(  WALL_WIDTH-1.5, 0, 1.5);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.5, 0, 0.0);  //����
		    glVertex3f( -WALL_WIDTH+1.5, 0, 1.5);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 1.5);  //�E��
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //�E��
        glEnd();

		glPopMatrix();
}

void Wall::Baseball_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 1.0, 0.2, 0.2); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //�E��
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
        glEnd();
		//��܂ŉ�

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.2);  //����
            glVertex3f( -WALL_WIDTH+1.5, 0, 1.2);  //�E��
            glVertex3f( -WALL_WIDTH+1.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.5, 0, 0.0);  //����
		    glVertex3f( -WALL_WIDTH+1.5, 0, 1.2);  //����
            glVertex3f( -WALL_WIDTH+2.0, 0, 0.6);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.2);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
            glVertex3f( -WALL_WIDTH+1.5, 0, 2.7);  //�E��
            glVertex3f( -WALL_WIDTH+1.5, 0, 1.2);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+2.0, 0, 2.2);  //����
		    glVertex3f( -WALL_WIDTH+2.0, 0, 2.7);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
            glVertex3f(  WALL_WIDTH-0.5, 0, 2.2);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.5, 0, 0.0);  //����
		    glVertex3f(  WALL_WIDTH-1.5, 0, 1.8);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 1.8);  //�E��
            glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-2.0, 0, 1.2);  //����
		    glVertex3f(  WALL_WIDTH-1.5, 0, 1.2);  //����
            glVertex3f(  WALL_WIDTH-1.5, 0, 0.6);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-2.0, 0, 0.0);  //����
		    glVertex3f(  WALL_WIDTH-1.5, 0, 0.0);  //����
            glVertex3f(  WALL_WIDTH-1.5, 0, 0.6);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-2.0, 0, 1.2);  //����
		    glVertex3f(  WALL_WIDTH-1.5, 0, 1.8);  //����
            glVertex3f(  WALL_WIDTH-1.5, 0, 1.2);  //�E��
        glEnd();

	    glPopMatrix();
}

void Wall::Monsterball_wall(double x, double y, double z)
{
		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 1.0, 0.2, 0.2); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //�E��
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.8);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.8);  //�E��
        glEnd();
		//��܂ŉ�

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.75, 0, 0.0);  //����
		    glVertex3f( -WALL_WIDTH+1.0, 0,  0.3);  //����
            glVertex3f( -WALL_WIDTH+1.0, 0,  0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.75, 0, 0.0);  //����
		    glVertex3f(  WALL_WIDTH-1.0, 0,  0.3);  //����
            glVertex3f(  WALL_WIDTH-1.0, 0,  0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.0, 0, 0.3);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.0);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 0.3);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.0, 0, 0.3);  //����
		    glVertex3f(  WALL_WIDTH-0.5, 0, 1.0);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 0.3);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.0, 0, 2.5);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.8);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 2.5);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.0, 0, 2.5);  //����
		    glVertex3f(  WALL_WIDTH-0.5, 0, 1.8);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 2.5);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.75, 0, 2.8);  //����
		    glVertex3f( -WALL_WIDTH+1.0, 0,  2.5);  //����
            glVertex3f( -WALL_WIDTH+1.0, 0,  2.8);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.75, 0, 2.8);  //����
		    glVertex3f(  WALL_WIDTH-1.0, 0,  2.5);  //����
            glVertex3f(  WALL_WIDTH-1.0, 0,  2.8);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.3);  //����
            glVertex3f( -WALL_WIDTH+1.0, 0, 0.3);  //�E��
		    glVertex3f( -WALL_WIDTH+1.0, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-0.5, 0, 0.0);  //����
		    glVertex3f(  WALL_WIDTH-0.5, 0, 0.3);  //����
            glVertex3f(  WALL_WIDTH-1.0, 0, 0.3);  //�E��
		    glVertex3f(  WALL_WIDTH-1.0, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.5);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.8);  //����
            glVertex3f( -WALL_WIDTH+1.0, 0, 2.8);  //�E��
		    glVertex3f( -WALL_WIDTH+1.0, 0, 2.5);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.5);  //����
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.8);  //����
            glVertex3f(  WALL_WIDTH-1.0, 0, 2.8);  //�E��
		    glVertex3f(  WALL_WIDTH-1.0, 0, 2.5);  //�E��
        glEnd();
		//��܂ŊO�~

		glPushMatrix();
	    glTranslatef(0, 0, 1.0);
		glScalef(0.3, 0.3, 0.3);
		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.75, 0, 0.0);  //����
		    glVertex3f( -WALL_WIDTH+1.0, 0,  0.3);  //����
            glVertex3f( -WALL_WIDTH+1.0, 0,  0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.75, 0, 0.0);  //����
		    glVertex3f(  WALL_WIDTH-1.0, 0,  0.3);  //����
            glVertex3f(  WALL_WIDTH-1.0, 0,  0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.0, 0, 0.3);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.0);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 0.3);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.0, 0, 0.3);  //����
		    glVertex3f(  WALL_WIDTH-0.5, 0, 1.0);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 0.3);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.0, 0, 2.5);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.8);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 2.5);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.0, 0, 2.5);  //����
		    glVertex3f(  WALL_WIDTH-0.5, 0, 1.8);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 2.5);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.75, 0, 2.8);  //����
		    glVertex3f( -WALL_WIDTH+1.0, 0,  2.5);  //����
            glVertex3f( -WALL_WIDTH+1.0, 0,  2.8);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-1.75, 0, 2.8);  //����
		    glVertex3f(  WALL_WIDTH-1.0, 0,  2.5);  //����
            glVertex3f(  WALL_WIDTH-1.0, 0,  2.8);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.5, 0, 2.8);  //����
		    glVertex3f( -WALL_WIDTH+1.5, 0, 2.9);  //����
            glVertex3f(  WALL_WIDTH-1.5, 0, 2.9);  //�E��
		    glVertex3f(  WALL_WIDTH-1.5, 0, 2.8);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.5, 0, 0.0);  //����
		    glVertex3f( -WALL_WIDTH+1.5, 0, -0.1);  //����
            glVertex3f(  WALL_WIDTH-1.5, 0, -0.1);  //�E��
		    glVertex3f(  WALL_WIDTH-1.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.9);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 1.9);  //����
            glVertex3f( -WALL_WIDTH+0.3, 0, 1.9);  //�E��
		    glVertex3f( -WALL_WIDTH+0.3, 0, 0.9);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  WALL_WIDTH-0.5, 0, 0.9);  //����
		    glVertex3f(  WALL_WIDTH-0.5, 0, 1.9);  //����
            glVertex3f(  WALL_WIDTH-0.3, 0, 1.9);  //�E��
		    glVertex3f(  WALL_WIDTH-0.3, 0, 0.9);  //�E��
        glEnd();

	    glPopMatrix();
		//�����̉~

		glBegin( GL_POLYGON );  
		    glVertex3f( -0.03, 0, 1.8);  //����
		    glVertex3f( -0.03, 0, 3.0);  //����
            glVertex3f(  0.03, 0, 3.0);  //�E��
		    glVertex3f(  0.03, 0, 1.8);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f(  -0.03, 0, 0.0);  //����
		    glVertex3f(  -0.03, 0, 1.0);  //����
            glVertex3f(   0.03, 0, 1.0);  //�E��
		    glVertex3f(   0.03, 0, 0.0);  //�E��
        glEnd();

	    glPopMatrix();
}

void Wall::Move_wall(double x, double y, double z, double s)
{

		glPushMatrix();
	    glTranslatef(x, y, z);

	    glColor3f( 1.0, 0.2, 0.2); 
		glBegin( GL_POLYGON );         
		    glVertex3f(     -WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     -WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //�E��
		    glVertex3f( -WALL_WIDTH+0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );        
		    glVertex3f(     WALL_WIDTH, 0, 0.0);  //����
		    glVertex3f(     WALL_WIDTH, 0, 3.0);  //����
            glVertex3f( WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f( WALL_WIDTH-0.5, 0, 0.0);  //�E��
        glEnd();

		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+0.5, 0, 2.7);  //����
		    glVertex3f( -WALL_WIDTH+0.5, 0, 3.0);  //����
            glVertex3f(  WALL_WIDTH-0.5, 0, 3.0);  //�E��
		    glVertex3f(  WALL_WIDTH-0.5, 0, 2.7);  //�E��
        glEnd();
		//��܂ŉ�

		glPushMatrix();
		glTranslatef(s, 0, 0);
		glBegin( GL_POLYGON );  
		    glVertex3f( -WALL_WIDTH+1.7, 0, 0.0);  //����
		    glVertex3f( -WALL_WIDTH+1.7, 0, 2.7);  //����
            glVertex3f(  WALL_WIDTH-1.7, 0, 2.7);  //�E��
		    glVertex3f(  WALL_WIDTH-1.7, 0, 0.0);  //�E��
        glEnd();
        glPopMatrix();

	    glPopMatrix();
}
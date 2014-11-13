#include <GL/gl.h>
#include <GL/freeglut.h>
#include <math.h>
#include <iostream>

#include "Assignment3.h"

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f }; 
 
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f }; 

float x = -200;
int Increase = 1;
int angle = 0;

void Init()
{
    InitCallbacks();
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); 
    
    glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
 
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); 
}

void InitCallbacks()
{
    glutDisplayFunc(Render);
    glutReshapeFunc(Resize);
    glutIdleFunc(IdleFunc);
}

void DrawTetrahedrons()
{
    glColor3f(0, 0, 1);
    
    glPushMatrix();
        glTranslatef(x / 100, x / 100, -7);
        glRotatef(angle, 1, 1, 1);
        glScalef(1, 1, 1);
        glutSolidTetrahedron();
        
        if(Increase)
        	x++;
        else
        	x--;

        if(x == 200)
        	Increase = 0;
        else if(x == -200)
        	Increase = 1;
        angle = (angle + 1) % 360;

    glPopMatrix();
}

void DrawSector(int CenterX, int CenterY, int radius, int startAngle, int EndAngle)
{
	glColor3f(1, 1, 0);

	int step = 1;
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0, 0, -14);
	for(int i = 0; i <= 360; i += step)
	{
		glVertex3f(1 * cos(DegToTheta(i)), 1 * sin(DegToTheta(i)), -14);
	}
	glEnd();
}

void Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 0, 0);

    glBegin(GL_QUADS);
    	glVertex3f(-5, -5, -15);
    	glVertex3f(5, -5, -15);
    	glVertex3f(5, 5, -15);
    	glVertex3f(-5, 5, -15);
	glEnd();

	glColor3f(0, 1, 0);
	DrawSector(0, 0, 4, 0, 360);

    DrawTetrahedrons();
    glutSwapBuffers();
}

void Resize(int width, int height)
{
    const float ar = (float) width / (float) height; 
 
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0); 
 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void KeyPressFunc()
{
    
}

void MouseFunc(int button, int state, int x, int y)
{
    
}

void IdleFunc()
{
    glutPostRedisplay();
}
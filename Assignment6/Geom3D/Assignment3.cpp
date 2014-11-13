#include <GL/gl.h>
#include <GL/freeglut.h>

#include "Assignment3.h"

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f }; 
 
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f }; 

std::vector<Sphere> *sphereVec = 0;
std::vector<Cylinder> *cylinderVec = 0;
std::vector<Tetrahedron> *tetrahedronVec = 0;
std::vector<Cube> *cubeVec = 0;

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

void DrawSpheres()
{
    if(sphereVec == 0)
        return;
    for(std::vector<Sphere>::iterator i = sphereVec->begin(); i != sphereVec->end(); i++)
    {
        Sphere sphere = (*i);
        glColor3f(sphere.color[0], sphere.color[1], sphere.color[2]);
        
        glPushMatrix();
            glTranslatef(sphere.center[0], sphere.center[1], sphere.center[2]);
            glutSolidSphere(sphere.radius, sphere.latitude, sphere.longitude);
        glPopMatrix();
    }
}

void DrawCylinders()
{
    if(cylinderVec == 0)
        return;
    for(std::vector<Cylinder>::iterator i = cylinderVec->begin(); i != cylinderVec->end(); i++)
    {
        Cylinder cylinder = (*i);
        glColor3f(cylinder.color[0], cylinder.color[1], cylinder.color[2]);
        
        glPushMatrix();
            glTranslatef(cylinder.center[0], cylinder.center[1], cylinder.center[2]);
            glRotatef(-60, 0.5, 0.4, 0.8);
            glutSolidCylinder(cylinder.radius, cylinder.height, cylinder.slices, cylinder.stacks);
        glPopMatrix();
    }
}

void DrawTetrahedrons()
{
    if(tetrahedronVec == 0)
        return;
    for(std::vector<Tetrahedron>::iterator i = tetrahedronVec->begin(); i != tetrahedronVec->end(); i++)
    {
        Tetrahedron tetra = (*i);
        glColor3f(tetra.color[0], tetra.color[1], tetra.color[2]);
        
        glPushMatrix();
            glTranslatef(tetra.center[0], tetra.center[1], tetra.center[2]);
            glScalef(tetra.scale, tetra.scale, tetra.scale);
            glutWireTetrahedron();
        glPopMatrix();
    }
}

void DrawCubes()
{
    if(cubeVec == 0)
        return;
    for(std::vector<Cube>::iterator i = cubeVec->begin(); i != cubeVec->end(); i++)
    {
        Cube cube = (*i);
        glColor3f(cube.color[0], cube.color[1], cube.color[2]);
        
        glPushMatrix();
            glTranslatef(cube.center[0], cube.center[1], cube.center[2]);
            glutWireCube(cube.side);
        glPopMatrix();
    }
   
}

void Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 0, 0);
    DrawSpheres();
    DrawCylinders();
    DrawTetrahedrons();
    DrawCubes();
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

void SetSphereVector(std::vector<Sphere> *_sphereVec)
{
    sphereVec = _sphereVec;
}

void SetCylinderVector(std::vector<Cylinder> *_cylinderVec)
{
    cylinderVec = _cylinderVec;
}

void SetTetrahedronVector(std::vector<Tetrahedron> *_tetrahedronVec)
{
    tetrahedronVec = _tetrahedronVec;
}

void SetCubeVector(std::vector<Cube> *_cubeVec)
{
    cubeVec = _cubeVec;
}

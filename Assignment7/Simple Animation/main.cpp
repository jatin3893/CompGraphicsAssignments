#include <iostream>

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "Assignment3.h"

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(WindowWidth, WindowHeight);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow("Assignment 7");
    
    Init();
    glutMainLoop();
    return 0;
}

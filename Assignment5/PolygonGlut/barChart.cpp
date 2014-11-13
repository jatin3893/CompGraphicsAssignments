#include <GL/gl.h>
#include <GL/freeglut.h>

#include <iostream>

#define Window_Height 600
#define Window_Width 1200

void initWindow();
void initCallbacks();
void Render();
void GetInput();

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(Window_Width, Window_Height);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow("Bar Chart");

	initWindow();
	initCallbacks();

	glutMainLoop();
}

void initWindow()
{
	glClearColor(0, 0, 0, 0);
}

void initCallbacks()
{
	glutDisplayFunc(Render);
	glutIdleFunc(glutPostRedisplay);
}

void Render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glutSwapBuffers();
}

void MouseClicked(int button, int state, int x, int y)
{
	
}
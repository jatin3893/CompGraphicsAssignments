#include <GL/gl.h>
#include <GL/freeglut.h>
#include <GL/glu.h>

#include <iostream>
#include <math.h>

#define Window_Height 600
#define Window_Width 1200

#define BaseOffsetX 10
#define BaseOffsetY 10
#define PI 3.142
#define DegToTheta(i) PI * i / 180.0

float *BarChartData;
int BarCount = 10; // Change

void initWindow();
void initCallbacks();
void Render();
void GetInput();
void DrawAxes();
void DrawBarChart();
void DrawPieChart(int CenterX, int CenterY);
void DrawSector(int CenterX, int CenterY, int radius, int startAngle, int EndAngle);

int main(int argc, char **argv)
{
	std::cin >> BarCount;
	BarChartData = new float[BarCount];
	for(int i = 0; i < BarCount; i++)
		std::cin >> BarChartData[i];

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
	glOrtho(0, Window_Width, 0, Window_Height, -1, 1);
}

void initCallbacks()
{
	glutDisplayFunc(Render);
	glutIdleFunc(glutPostRedisplay);
}

void Render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	DrawAxes();
	DrawBarChart();
	DrawPieChart(Window_Width / 2, Window_Height / 2);
	glutSwapBuffers();
}

void DrawAxes()
{
	glBegin(GL_LINES);

	glColor3f(1, 0, 0);
	glVertex2f(BaseOffsetX, 0);
	glVertex2f(BaseOffsetX, Window_Height);

	glColor3f(0, 1, 0);
	glVertex2f(0, BaseOffsetY);
	glVertex2f(Window_Width, BaseOffsetY);

	glEnd();
}

void DrawBarChart()
{
	int i;
	for(i = 0; i < BarCount; i++)
	{
		glColor3f(i / (double)BarCount, 0.0, 1 - i / (double)BarCount);
		glBegin(GL_QUADS);
		glVertex2f(BaseOffsetX + i * 10, BaseOffsetY);
		glVertex2f(BaseOffsetX + (i + 0.8) * 10, BaseOffsetY);
		glVertex2f(BaseOffsetX + (i + 0.8) * 10, BaseOffsetY + BarChartData[i]);
		glVertex2f(BaseOffsetX + i * 10, BaseOffsetY + BarChartData[i]);
		glEnd();
	}
}

void DrawPieChart(int CenterX, int CenterY)
{
	float angle[BarCount + 1], sum = 0;
	angle[0] = 0;
	angle[BarCount] = 360;

	for(int i = 0; i < BarCount; i++)
	{
		sum += BarChartData[i];
	}
	for(int i = 1; i < BarCount; i++)
	{
		angle[i] = angle[i - 1] + (BarChartData[i - 1] / sum) * 360;
	}
	for(int i = 0; i < BarCount; i++)
	{
		glColor3f(i / (double)BarCount, 0, 1 - i / (double)BarCount);
		DrawSector(CenterX, CenterY, 100, angle[i], angle[i + 1]);
	}
}

void DrawSector(int CenterX, int CenterY, int radius, int startAngle, int EndAngle)
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(CenterX, CenterY);
	for(int i = startAngle; i < EndAngle; i++)
	{
		glVertex2f(CenterX + radius * cos(DegToTheta(i)), CenterY + radius * sin(DegToTheta(i)));
	}
	glEnd();

}

#include "Sky.h"

Sky::Sky()
{
    for(int i = 0; i < MaxStarsCount; i++)
    {
        StarsPosition[i][0] = rand() / (float)RAND_MAX * 20 - 10;
        StarsPosition[i][1] = rand() / (float)RAND_MAX * 10;
        StarsPosition[i][2] = rand() / (float)RAND_MAX * 20 - 10;
    }
}

Sky::~Sky()
{

}

void Sky::Render()
{
    if(isNight)
    {
        glColor3f(1, 1, 1);
        glPointSize(5);
        glBegin(GL_POINTS);
        for(int i = 0; i < MaxStarsCount; i++)
            glVertex3f(StarsPosition[i][0], StarsPosition[i][1], StarsPosition[i][2]);
        glEnd();
        glPointSize(1);
    }
}

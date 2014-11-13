#include "Fountain.h"

Fountain::Fountain()
{
    frame = 0;
    color = glm::vec3(rand() / (float)RAND_MAX, 0.5, rand() / (float)RAND_MAX);
    for(int j = 0; j < MaxSparks; j++)
    {
        sparkData[j][0] = rand() / (float)RAND_MAX * 0.05;
        sparkData[j][1] = rand() / (float)RAND_MAX * 0.1 + 0.4;
        sparkData[j][2] = rand() / (float)RAND_MAX * 0.05;
    }

    for(int j = 0; j < RepeatCount; j++)
        repeatRotations[j] = rand() / (float)RAND_MAX * 360;

}

Fountain::~Fountain()
{

}

void Fountain::Render()
{
    for(int j = 0; j < RepeatCount; j++)
    {
        float TempFrame = frame - j * 2;
        if(TempFrame < 0)
            continue;

        glPushMatrix();
        glRotatef(repeatRotations[j], 0, 1, 0);

        for(int i = 0; i < MaxSparks; i++)
        {
            float x = sparkData[i][0] * TempFrame;
            float y = sparkData[i][1] * TempFrame + gravity * TempFrame * TempFrame;
            float z = sparkData[i][2] * TempFrame;
            if(y <= 1)
                continue;

            switch((int)(rand() / (float)RAND_MAX * 7))
            {
            case 0:
                glColor3f(1, 0, 0);
                break;
            case 1:
                glColor3f(0, 1, 0);
                break;
            case 2:
                glColor3f(0, 0, 1);
                break;
            case 3:
                glColor3f(1, 1, 0);
                break;
            case 4:
                glColor3f(1, 0, 1);
                break;
            case 5:
                glColor3f(0, 1, 1);
                break;
            case 6:
                glColor3f(1, 1, 1);
                break;
            default:
                glColor3f(1, 0, 0);
                break;
            }

            glTranslatef(x, y, z);
            glutSolidSphere(0.1, 3, 3);
            glTranslatef(-x, -y, -z);
        }
        glPopMatrix();
    }
    glColor3f(color.x, color.y, color.z);
    glRotatef(90, -1, 0, 0);
    glutSolidCone(0.1, 0.35, 10, 10);

    frame += 0.2;
}

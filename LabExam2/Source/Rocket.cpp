#include "Rocket.h"

Rocket::Rocket()
{
    velocity = glm::vec3(rand() / (float)RAND_MAX * 0.05, rand() / (float)RAND_MAX * 0.1 + 0.4, rand() / (float)RAND_MAX * 0.05);
    position = glm::vec3(0, 0, 0);
    gravity = glm::vec3(0, -0.01, 0);
    color = glm::vec3(1, 1, 0);
    distance = 0;

    radius = rand() / (float)RAND_MAX * 0.05 + 0.05;
    Burst = false;

    for(int i = 0; i < MaxSubSphereCount; i++)
    {
        int theta = rand() / (float)RAND_MAX * 360;
        int phi = rand() / (float)RAND_MAX * 360;

        double sinT = sin(theta);
        double cosT = cos(theta);
        double sinP = sin(phi);
        double cosP = cos(phi);

        data[i][0] = sinT * cosP;
        data[i][1] = sinT * sinP;
        data[i][2] = cosT;
    }
}

Rocket::~Rocket()
{

}

void Rocket::Render()
{
    if(velocity.y < 0)
        Burst = true;
    if(!Burst)
    {
        position = position + velocity;
        velocity = velocity + gravity;
        glTranslatef(position.x, position.y, position.z);
        glColor3f(color.x, color.y, color.z);
        glutSolidSphere(radius, slices, stacks);
    }
    else if(distance < MaxDistance)
    {
        distance += 0.05;

        glColor3f(color.x, color.y, color.z);
        glTranslatef(position.x, position.y, position.z);
        for(int i = 0; i < MaxSubSphereCount; i++)
        {
            float colorX = data[i][0] > 0.5 ? data[i][0] : 1 - data[i][0];
            float colorY = data[i][1] > 0.5 ? data[i][1] : 1 - data[i][1];
            float colorZ = data[i][2] > 0.5 ? data[i][2] : 1 - data[i][2];

            glTranslatef(data[i][0] * distance, data[i][1] * distance - distance * 0.7, data[i][2] * distance);
            glColor3f(colorX, colorY, colorZ);
            glutSolidSphere(radius / 2, slices, stacks);
            glTranslatef(-data[i][0] * distance, -data[i][1] * distance + distance * 0.7, -data[i][2] * distance);
        }
        glPointSize(5);
        glColor3f(1, 1, 0);
        glBegin(GL_POINTS);
        for(int i = 0; i < 10; i++)
        {
            glVertex3f(rand() / (float)RAND_MAX * 2 * distance - distance, rand() / (float)RAND_MAX * 2 * distance - distance, rand() / (float)RAND_MAX * 2 * distance - distance);
        }
        glEnd();
        glPointSize(1);
    }
}

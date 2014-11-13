#ifndef ROCKET_H
#define ROCKET_H

#include "Object.h"

class Rocket: public Object
{
public:
    Rocket();
    ~Rocket();
    virtual void Render();
    glm::vec3 velocity;
    glm::vec3 position;
    glm::vec3 gravity;
    glm::vec3 color;

    bool Burst;
    float radius;
    static const int slices = 5;
    static const int stacks = 5;
    float distance;

    static const int MaxDistance = 5;
    static const int MaxSubSphereCount = 100;
    float data[MaxSubSphereCount][3];
};

#endif

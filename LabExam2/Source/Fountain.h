#ifndef FOUNTAIN_H
#define FOUNTAIN_H

#include "Object.h"

class Fountain: public Object
{
public:
    Fountain();
    ~Fountain();
    virtual void Render();
    glm::vec3 color;
    float frame;

    static const int MaxSparks = 5;
    static const float gravity = -0.01;
    static const int RepeatCount = 10;

    float sparkData[MaxSparks][3];
    float repeatRotations[RepeatCount];

};

#endif

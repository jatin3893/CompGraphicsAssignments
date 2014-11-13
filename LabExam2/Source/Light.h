#ifndef LIGHT_H
#define LIGHT_H

#include "Object.h"

class Light: public Object
{
public:
    Light();
    ~Light();
    virtual void Render();
};

#endif

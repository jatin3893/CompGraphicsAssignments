#ifndef Mountains_H
#define Mountains_H

#include "Object.h"

class Mountains: public Object
{
public:
    Mountains();
    ~Mountains();
    virtual void Render();
    int index;
};

#endif

#ifndef SKY_H
#define SKY_H

#include "Object.h"

class Sky: public Object
{
public:
    Sky();
    ~Sky();
    virtual void Render();
    static const int MaxStarsCount = 100;
    float StarsPosition[MaxStarsCount][3];
    bool isNight;
};

#endif

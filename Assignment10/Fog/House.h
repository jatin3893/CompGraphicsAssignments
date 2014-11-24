#ifndef HOUSE_H
#define HOUSE_H

#include "Object.h"

class House: public Object
{
public:
    House();
    ~House();
    virtual void Render();

    glm::vec3 colorTop;
    glm::vec3 colorBase;
    glm::vec3 colorDoor;
    float size;

    GLuint wallTexture;
    
    static const float BaseColor[7][3];
    static const float TopColor[7][3];

};

#endif

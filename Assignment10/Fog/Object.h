#ifndef OBJECT_H
#define OBJECT_H

#include <GL/gl.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

#include <iostream>
#include <vector>

class Object{
public:
    Object();
    ~Object();
    virtual void Render() = 0;
    glm::vec3 translate;
    glm::vec4 rotate;
    float angle;
};

#endif

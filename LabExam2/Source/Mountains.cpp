#include "Mountains.h"

Mountains::Mountains()
{
    index = rand() / (float) RAND_MAX * 3;
}

Mountains::~Mountains()
{

}

void Mountains::Render()
{
    glScalef(2, 1.8, 1);
    glRotatef(90, -1, 0, 0);
    glColor3f(0.4, 0.2, 0);

    switch(index)
    {
    case 0:
    glScalef(5, 5, 5);
    glutSolidIcosahedron();
    break;

    case 1:
        glScalef(2, 2, 2);
        glutSolidDodecahedron();
        break;

    case 2:
        glScalef(5, 5, 5);
        glutSolidOctahedron();
        break;
    }
}

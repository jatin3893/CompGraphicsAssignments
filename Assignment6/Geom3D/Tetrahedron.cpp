#include "Tetrahedron.h"
#include <cstdlib>

Tetrahedron::Tetrahedron(int scale, int cx, int cy, int cz)
{
    this->scale = scale;
    center[0] = cx; center[1] = cy; center[2] = cz;
    color[0] = (rand() % 100) / 100.0;
    color[1] = (rand() % 100) / 100.0;
    color[2] = 1 - color[0];
}

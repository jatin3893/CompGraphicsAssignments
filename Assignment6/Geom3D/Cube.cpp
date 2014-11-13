#include "Cube.h"
#include <cstdlib>

Cube::Cube(int side, int cx, int cy, int cz)
{
    this->side = side;
    center[0] = cx; center[1] = cy; center[2] = cz;
    color[0] = (rand() % 100) / 100.0;
    color[1] = (rand() % 100) / 100.0;
    color[2] = 1 - color[0];
}

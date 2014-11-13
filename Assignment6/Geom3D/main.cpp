#include <iostream>

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "Assignment3.h"

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(WindowWidth, WindowHeight);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow("3D Shapes");
    
    std::vector<Sphere> *sphereVec = new std::vector<Sphere>();
    std::vector<Cylinder> *cylinderVec = new std::vector<Cylinder>();
    std::vector<Tetrahedron> *tetrahedronVec = new std::vector<Tetrahedron>();
    std::vector<Cube> *cubeVec = new std::vector<Cube>();
    
    int N;
    double radius, height, cx, cy, cz, side;
    std::cin >> N;
    for(int i = 0; i < N; i++)
    {
        char c;
        std::cin >> c;
        switch(c){
        case 's':
        case 'S':
            std::cin >> radius >> cx >> cy >> cz;
            sphereVec->push_back(Sphere(radius, cx, cy, cz));
            break;
            
        case 'c':
        case 'C':
            std::cin >> radius >> height >> cx >> cy >> cz;
            cylinderVec->push_back(Cylinder(radius, height, cx, cy, cz));
        break;
        
        case 'b':
        case 'B':
            std::cin >> side >> cx >> cy >> cz;
            cubeVec->push_back(Cube(side, cx, cy, cz));
        break;
        
        case 't':
        case 'T':
            std::cin >> side >> cx >> cy >> cz;
            tetrahedronVec->push_back(Tetrahedron(side, cx, cy, cz));
        break;
        default:
            std::cout << "Invalid Input format";
            return -1;
        }
    }
    
    SetSphereVector(sphereVec);
    SetCylinderVector(cylinderVec);
    SetTetrahedronVector(tetrahedronVec);
    SetCubeVector(cubeVec);
    
    Init();
    glutMainLoop();
    return 0;
}

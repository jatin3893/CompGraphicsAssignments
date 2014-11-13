all: Geometries Main Assignment
	g++ -o Output main.o Sphere.o Cube.o Tetrahedron.o Cylinder.o Assignment3.o -lGL -lglut
    
Geometries: Sphere Cube Tetrahedron Cylinder

Main: main.cpp
	g++ -c main.cpp
    
Sphere: Sphere.cpp
	g++ -c Sphere.cpp
    
Cube: Cube.cpp
	g++ -c Cube.cpp
    
Tetrahedron: Tetrahedron.cpp
	g++ -c Tetrahedron.cpp

Cylinder: Cylinder.cpp
	g++ -c Cylinder.cpp
    
Assignment: Assignment3.cpp
	g++ -c Assignment3.cpp
    
Clean:
	rm -rf *.o Output


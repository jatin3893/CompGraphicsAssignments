#
#
# Compilation of the code requires libglm that was used for the vector calculations
# Can be installed in Ubuntu using 
# sudo apt-get install libglm-dev libglm-doc 
#
#

all: Main WindowManager Geometries
	g++ -o LabExam2 main.o WindowManager.o Object.o House.o Tree.o -lGL -lglut -lGLU
    
Main: main.cpp
	g++ -c main.cpp
    
WindowManager: WindowManager.cpp
	g++ -c WindowManager.cpp
    
Geometries: Object House Tree

Object: Object.cpp
	g++ -c Object.cpp

House: House.cpp
	g++ -c House.cpp

Tree: Tree.cpp
	g++ -c Tree.cpp

Clean:
	rm -rf *.o LabExam2


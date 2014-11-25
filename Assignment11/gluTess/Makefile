#
#
# Compilation of the code requires libglm that was used for the vector calculations
# Can be installed in Ubuntu using 
# sudo apt-get install libglm-dev libglm-doc 
#
#

all: Main WindowManager
	g++ -o A11 main.o WindowManager.o -lGL -lglut -lGLU -lSOIL -std=c++11
    
Main: main.cpp
	g++ -c main.cpp
    
WindowManager: WindowManager.cpp
	g++ -c WindowManager.cpp

Clean:
	rm -rf *.o A11


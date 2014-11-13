#include <iostream>
#include "WindowManager.h"

int main(int argc, char **argv)
{
	InitWindow(argc, argv);
	InitDisplay();
	InitCallbacks();
    InitScene();
	Loop();
}

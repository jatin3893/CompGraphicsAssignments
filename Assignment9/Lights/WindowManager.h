#include <GL/gl.h>
#include <GL/freeglut.h>

// Convenience Calls
void Loop();
void PreDisplayUpdate();

// Initialisations
void InitDisplay();
void InitWindow(int argc, char **argv);
void InitCallbacks();
void InitScene();

// Callbacks
void Mouse(int button, int state, int x, int y);
void Display();
void Idle();
void Reshape(int w, int h);
void MouseMotion(int x, int y);
void Keyboard(unsigned char button, int x, int y);
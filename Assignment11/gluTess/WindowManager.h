#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/freeglut.h>
#include <vector>

struct point{
    GLdouble data[3];
    point(int x, int y, int z)
    {
    	data[0] = x;
    	data[1] = y;
    	data[2] = z;
    }
};
typedef struct point point;

// Convenience Calls
void Loop();
void PreDisplayUpdate();
void loadTextures();

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

void DrawTessJ();
void DrawTessP();
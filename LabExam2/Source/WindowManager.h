#include <GL/gl.h>
#include <GL/freeglut.h>

// Convenience Calls
void Loop();
void PreDisplayUpdate();
void DrawCurvedRoad();

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

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//GLfloat light_position[] = { 5.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

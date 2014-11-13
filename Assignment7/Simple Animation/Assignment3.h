#define WindowHeight 600
#define WindowWidth 600
#define PI 3.142
#define DegToTheta(i) PI * i / 180.0

void Init();
void InitCallbacks();
void Render();
void Resize(int, int);
void KeyPressFunc();
void MouseFunc();
void IdleFunc();
void DrawSector(int CenterX, int CenterY, int radius, int startAngle, int EndAngle);
void DrawSquare();
void DrawPyramid();
void DrawCircles();
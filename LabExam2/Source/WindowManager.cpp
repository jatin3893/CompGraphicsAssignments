#include "WindowManager.h"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Geometries.h"
#include "Object.h"

#include <iostream>
#include <vector>

#define WindowWidth 1000
#define WindowHeight 700

std::vector<Object *> sceneObjects;

class WindowState{
public:
    glm::vec3 lastPos;
    glm::vec3 cameraPos;
    glm::vec3 rotationAxis;
    glm::quat rotation;
    float angularSpeed;
    glm::mat4 rotMatrix;
    float x, y, z;
    float time;

    WindowState()
    {
        cameraPos = glm::vec3(0, 5, 16.5);
    }
};

WindowState currentState;

void InitWindow(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(WindowWidth, WindowHeight);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Lab Exam");
}

void InitDisplay()
{
    //    glClearColor(0.0, 0.0, 0.1, 0.0);
    glClearColor(1, 1, 1, 0.0);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

Object *sky;

void InitScene()
{
    for(int i = 0; i < 8; i++)
    {
        Object *mountain = new Mountains();
        ((Mountains *)mountain)->translate = glm::vec3(-10 + i * (rand() / (float)RAND_MAX * 2 + 2.5), 0, -12 + rand() / (float)RAND_MAX * 2);
        sceneObjects.push_back(mountain);
    }

    Object *house1 = new House();
    ((House *)house1)->translate = glm::vec3(6, 0, 0);
    sceneObjects.push_back(house1);

    Object *house2 = new House();
    ((House *)house2)->translate = glm::vec3(8, 0, -1);
    sceneObjects.push_back(house2);

    Object *house3 = new House();
    ((House *)house3)->translate = glm::vec3(-6, 0, -1);
    sceneObjects.push_back(house3);

    Object *house4 = new House();
    ((House *)house4)->translate = glm::vec3(-2, 0, 5);
    sceneObjects.push_back(house4);

    Object *tree1 = new Tree();
    ((Tree *)tree1)->translate = glm::vec3(2, 0, 2);
    sceneObjects.push_back(tree1);

    Object *tree2 = new Tree();
    ((Tree *)tree2)->translate = glm::vec3(-2, 0, 2);
    sceneObjects.push_back(tree2);

    Object *tree3 = new Tree();
    ((Tree *)tree3)->translate = glm::vec3(5, 0, 1);
    sceneObjects.push_back(tree3);

    Object *tree4 = new Tree();
    ((Tree *)tree4)->translate = glm::vec3(1, 0, 1);
    sceneObjects.push_back(tree4);

    Object *tree5 = new Tree();
    ((Tree *)tree5)->translate = glm::vec3(-8, 0, -7);
    sceneObjects.push_back(tree5);

    Object *tree6 = new Tree();
    ((Tree *)tree6)->translate = glm::vec3(-4, 0, -2);
    sceneObjects.push_back(tree6);

    sky = new Sky();
    ((Sky *)sky)->translate = glm::vec3(0, 10, 0);
    sceneObjects.push_back(sky);
}

void InitCallbacks()
{
    glutMouseFunc(Mouse);
    glutDisplayFunc(Display);
    glutIdleFunc(Idle);
    glutReshapeFunc(Reshape);
    glutMotionFunc(MouseMotion);
    glutKeyboardFunc(Keyboard);
}

void Keyboard(unsigned char button, int x, int y)
{
    float step = 0.1;
    switch(button)
    {
    case 'w':
    case 'W':
        currentState.cameraPos.z -= step;
        break;
    case 's':
    case 'S':
        currentState.cameraPos.z += step;
        break;
    case 'X':
        currentState.x += step;
        break;
    case 'x':
        currentState.x -= step;
        break;
    case 'Y':
        currentState.y += step;
        break;
    case 'y':
        currentState.y -= step;
        break;
    case 'Z':
        currentState.z += step;
        break;
    case 'z':
        currentState.z -= step;
        break;
    case '1':
    {
        Object *rocket = new Rocket();
        ((Rocket *)rocket)->translate = glm::vec3(rand() / (float)RAND_MAX * 10 - 5, 0, rand() / (float)RAND_MAX * 10 - 5);
        sceneObjects.push_back(rocket);
    }
        break;
    case '2':
    {
        Object *fountain = new Fountain();
        int i = rand() / (float)RAND_MAX * 5;
        switch(i)
        {
        case 0:
            ((Fountain *)fountain)->translate = glm::vec3(-5 + rand() / (float)RAND_MAX * 4 - 2, 0, -5 + rand() / (float)RAND_MAX * 4 - 2);
            break;
        case 1:
            ((Fountain *)fountain)->translate = glm::vec3(-5 + rand() / (float)RAND_MAX * 4 - 2, 0, 5 + rand() / (float)RAND_MAX * 4 - 2);
            break;
        case 2:
            ((Fountain *)fountain)->translate = glm::vec3(5 + rand() / (float)RAND_MAX * 4 - 2, 0, 5 + rand() / (float)RAND_MAX * 4 - 2);
            break;
        case 3:
            ((Fountain *)fountain)->translate = glm::vec3(5 + rand() / (float)RAND_MAX * 4 - 2, 0, -5 + rand() / (float)RAND_MAX * 4 - 2);
            break;
        case 4:
            ((Fountain *)fountain)->translate = glm::vec3(0 + rand() / (float)RAND_MAX * 2 - 1, 0, 0 + rand() / (float)RAND_MAX * 2 - 1);
            break;
        }
        sceneObjects.push_back(fountain);
    }
    default:
        ;
    }
}

void MouseMotion(int x, int y)
{
}

void Reshape(int w, int h)
{
    // Set OpenGL viewport to cover whole widget
    glViewport(0, 0, w, h);

    // Calculate aspect ratio
    double aspect = (double)w / (double)(h ? h : 1);

    // Set near plane to 3.0, far plane to 7.0, field of view 45 degrees
    const double zNear = 0.1, zFar = 500.0, fov = 45.0;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov, aspect, zNear, zFar);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Mouse(int button, int state, int x, int y)
{
    switch(button)
    {
    case GLUT_LEFT_BUTTON:
        switch(state)
        {
        case GLUT_DOWN:
            currentState.lastPos = glm::vec3(x, y, 0);

            break;

        case GLUT_UP:
        {
            glm::vec3 diff = glm::vec3(x, y, 0) - currentState.lastPos;

            if(diff.x == 0 && diff.y == 0 && diff.z == 0)
                return;

            glm::vec3 n = glm::normalize(glm::vec3(diff.y, diff.x, 0.0));
            float acc = diff.length() / 5.0;
            currentState.rotationAxis = (currentState.rotationAxis * currentState.angularSpeed + n * acc);

            if(currentState.rotationAxis.length() != 0)
                glm::normalize(currentState.rotationAxis);
            currentState.angularSpeed += acc;
        }
            break;

        default:
            std::cout << "Unknown Mouse state for Left Button" << std::endl;
        }
        break;

    case GLUT_RIGHT_BUTTON:
        switch(state)
        {
        case GLUT_UP:
            break;

        case GLUT_DOWN:
            break;

        default:
            std::cout << "Unknown Mouse state for Right Button" << std::endl;
        }
        break;

    case GLUT_MIDDLE_BUTTON:
        switch(state)
        {
        case GLUT_UP:
            break;

        case GLUT_DOWN:
            break;

        default:
            std::cout << "Unknown Mouse state for Middle Button" << std::endl;
        }
        break;

    default:
        std::cout << "Unknown Mouse button pressed" << std::endl;
    }
}

void PreDisplayUpdate()
{
    // Decrease angular speed (friction)
    currentState.angularSpeed *= 0.95;

    // Stop rotation when speed goes below threshold
    if (currentState.angularSpeed < 0.01) {
        currentState.angularSpeed = 0.0;
    }

    // Update rotation
    currentState.rotation = glm::angleAxis(currentState.angularSpeed, currentState.rotationAxis) * currentState.rotation;
}

void DrawCurvedRoad()
{
    float baseHeight = 0.01;
    // Curved Road
    glColor3f(0.25, 0.25, 0.25);
    glBegin(GL_QUADS);
    glVertex3f(-10, baseHeight, -2);
    glVertex3f(0, baseHeight, -2);
    glVertex3f(0, baseHeight, -4);
    glVertex3f(-10, baseHeight, -4);
    glEnd();

    glPushMatrix();
    for(int i = 0; i <= 90; i++)
    {
        glBegin(GL_QUADS);
        glVertex3f(0, baseHeight, -2);
        glVertex3f(0.1, baseHeight, -2);
        glVertex3f(0.1, baseHeight, -4);
        glVertex3f(0, baseHeight, -4);
        glEnd();
        glRotatef(1, 0, -1, 0);
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6, 0, 0);
    for(int i = 0; i <= 90; i++)
    {
        glBegin(GL_QUADS);
        glVertex3f(-4, baseHeight, 0.1);
        glVertex3f(-2, baseHeight, 0.1);
        glVertex3f(-2, baseHeight, 0);
        glVertex3f(-4, baseHeight, 0);
        glEnd();
        glRotatef(1, 0, 1, 0);
    }
    glPopMatrix();

    glBegin(GL_QUADS);
    glVertex3f(6, baseHeight, 2);
    glVertex3f(6, baseHeight, 4);
    glVertex3f(10, baseHeight, 4);
    glVertex3f(10, baseHeight, 2);
    glEnd();

}

void Display()
{
    PreDisplayUpdate();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(currentState.cameraPos.x, currentState.cameraPos.y, currentState.cameraPos.z,
              currentState.cameraPos.x, currentState.cameraPos.y, currentState.cameraPos.z - 1,
              0, 1, 0);

    glTranslatef(currentState.x, currentState.y, currentState.z);

    //     Rotation of the entire scene wrt mouse movements
    glm::mat4 mat;
    mat = glm::toMat4(currentState.rotation);
    glMultMatrixf(glm::value_ptr(mat));

    // Base Field in Black
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(-10, 0, -10);
    glVertex3f(-10, 0, 10);
    glVertex3f(10, 0, 10);
    glVertex3f(10, 0, -10);
    glEnd();

    DrawCurvedRoad();

    currentState.time += 1;
    float Day = 200;

    if(currentState.time > 2 * Day)
        currentState.time -= (2 * Day);

    if(currentState.time > Day )
    {
        glClearColor(0, 0, 0.15, 0);
        ((Sky *)sky)->isNight = true;
        if(currentState.time < 1.25 * Day)
        {
            int x = floor(rand() / (float) RAND_MAX * 20);
            if(x <= 2 )
                Keyboard('1', 0, 0);
            else if(x == 3)
                Keyboard('2', 0, 0);
        }
    }
    else
    {
        glClearColor(1, 1, 0.85, 0);
        ((Sky *)sky)->isNight = false;
    }

    // Sun Moon Movements
    glPushMatrix();
    glRotatef(currentState.time / (2.0 * Day) * 360, 0, 0, 1);
    glPushMatrix();
    glTranslatef(15, 0, -15);
    glColor3f(1, 1, 0);
    glutSolidSphere(2, 20, 20);
    GLfloat light_position[] = { 5.0f, 5.0f, 5.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glTranslatef(-30, 0, 0);
    glColor3f(1, 1, 1);
    glutSolidSphere(2, 20, 20);
    glTranslatef(15, 0, +15);
    glPopMatrix();
    glPopMatrix();

    for(std::vector<Object *>::iterator i = sceneObjects.begin(); i != sceneObjects.end(); i++)
    {
        glPushMatrix();
        Object *obj = (Object *)(*i);
        glTranslatef(obj->translate.x, obj->translate.y, obj->translate.z);
        glRotatef(obj->rotate.x, obj->rotate.y, obj->rotate.z, obj->rotate.w);
        obj->Render();
        glPopMatrix();
    }

    glutSwapBuffers();
}

void Loop()
{
    glutMainLoop();
}

void Idle()
{
    glutPostRedisplay();
}

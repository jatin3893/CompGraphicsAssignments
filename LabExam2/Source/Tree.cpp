#include "Tree.h"

Tree::Tree()
{
    Initialise();
}

Tree::~Tree()
{

}

void Tree::Initialise()
{
    for(int branch = 0; branch < MaxBranch; branch++)
    {
        for(int i = 0; i < MaxDepth; i++)
        {
            data[branch][i][0] = rand() / (float)RAND_MAX * 90 - 45;
            data[branch][i][1] = rand() / (float)RAND_MAX * 2 - 1;
            data[branch][i][2] = rand() / (float)RAND_MAX * 2 - 1;
        }
    }
    for(int branch = 0; branch < MaxBranch; branch++)
    {
        for(int i = 0; i < MaxDepth; i++)
        {
            for(int leaf = 0; leaf < MaxLeaf; leaf++)
            {
                leafData[branch][i][leaf][0] = rand() / (float)RAND_MAX * height;
                leafData[branch][i][leaf][1] = rand() / (float)RAND_MAX * LeafWidth;
                leafData[branch][i][leaf][2] = rand() / (float)RAND_MAX * LeafWidth;
            }
        }
    }
}

void Tree::FractalTree(int branch, int depth, int x, int y, int z)
{
    if(depth < MaxDepth)
    {
        glColor3f(0.4, 0.2, 0);

        glRotatef(data[branch][depth][0], data[branch][depth][1], data[branch][depth][2], 0);
        glTranslatef(x, y, z - height);
        glutSolidCylinder(0.05, height, 5, 2);

        glPushMatrix();
        glRotatef(rand() / (float)RAND_MAX * 10, 0, rand() / (float)RAND_MAX, 0);
        for(int i = 0; i < MaxLeaf; i++)
        {
            glPushMatrix();
            glColor3f(0, rand()/(float)RAND_MAX * 0.5 + 0.5, 0);
            float pos = leafData[branch][depth][i][0];
            glTranslatef(leafData[branch][depth][i][1], leafData[branch][depth][i][2], -pos);
            glutSolidSphere(LeafWidth, 3, 2);
            glPopMatrix();
        }
        glPopMatrix();
        FractalTree(branch, depth + 1, x, y, z);
    }
}

void Tree::Render()
{
    glColor3f(0.4, 0.2, 0);

    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, -height);
    glutSolidCylinder(0.05, height, 5, 2);

    for(int i = 0; i < MaxBranch; i++)
    {
        glPushMatrix();
        FractalTree(i, 0, 0, height, 0);
        glPopMatrix();
    }
    glEnd();
}

#include "Tree.h"

Tree::Tree()
{
    height = 15;
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
            data[branch][i][0] = rand() / (float)RAND_MAX * 60 - 30;
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
                leafData[branch][i][leaf][3] = rand() / (float)RAND_MAX * 360;
            }
        }
    }
}

void Tree::DrawBranch()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, branchTexture);
    glColor4f(1, 1, 1, 1);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    for(int i = 0; i < 4; i++)
    {
        glRotatef(90, 0, 1, 0);
        glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-diameter, 0, diameter);

        glTexCoord2f(1, 0);
        glVertex3f(diameter, 0, diameter);

        glTexCoord2f(1, 1);
        glVertex3f(diameter, height, diameter);

        glTexCoord2f(0, 1);
        glVertex3f(-diameter, height, diameter);
        glEnd();
    }
    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    glTexCoord2f(0, 0);
    glVertex3f(-diameter, height, -diameter);
    glTexCoord2f(1, 0);
    glVertex3f(-diameter, height, diameter);
    glTexCoord2f(1, 1);
    glVertex3f(diameter, height, diameter);
    glTexCoord2f(0, 1);
    glVertex3f(diameter, height, -diameter);

    glNormal3f(0, -1, 0);
    glTexCoord2f(0, 0);
    glVertex3f(-diameter, height, -diameter);

    glTexCoord2f(1, 0);
    glVertex3f(diameter, height, -diameter);

    glTexCoord2f(1, 1);
    glVertex3f(diameter, height, diameter);

    glTexCoord2f(0, 1);
    glVertex3f(-diameter, height, diameter);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void Tree::FractalTree(int branch, int depth, int x, int y, int z)
{
    if(depth < MaxDepth)
    {
        glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, leafTexture);
        for(int i = 0; i < MaxLeaf; i++)
        {
            glPushMatrix();
            glColor4f(0.2, 1, 0.1, 1.0);
            float pos = leafData[branch][depth][i][0];
            glTranslatef(leafData[branch][depth][i][1], leafData[branch][depth][i][2], -pos);
            glRotatef(leafData[branch][depth][i][3], 0.5, 1, 0);

            glBegin(GL_QUADS);
                glTexCoord2f(0, 0);
                glVertex2f(0, 0);
                
                glTexCoord2f(1, 0);
                glVertex2f(0, 4);
                
                glTexCoord2f(1, 1);
                glVertex2f(4, 4);
                
                glTexCoord2f(0, 1);
                glVertex2f(4, 0);
            glEnd();
            
            glPopMatrix();
        }
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();

        glColor3f(0.4, 0.2, 0);

        glRotatef(data[branch][depth][0], data[branch][depth][1], data[branch][depth][2], 0);
        glTranslatef(x, y, z - height);
        DrawBranch();

        FractalTree(branch, depth + 1, x, y, z);
    }
}


void Tree::Render()
{
    glColor3f(0.4, 0.2, 0);

    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, -height);
    glutSolidCylinder(diameter, height, 5, 2);
    DrawBranch();

    for(int i = 0; i < MaxBranch; i++)
    {
        glPushMatrix();
        FractalTree(i, 0, 0, 0, 0);
        glPopMatrix();
    }
}

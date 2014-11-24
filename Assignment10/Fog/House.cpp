#include "House.h"
const float House::TopColor[7][3] = {
    255, 127, 36,
    210, 105, 30,
    205, 133, 63,
    142, 107, 35,
    255, 211, 155,
    140, 23, 23,
    31, 31, 31
};
const float House::BaseColor[7][3] = {
    120, 120, 120,
    187, 187, 187,
    210, 210, 210,
    250, 250, 250,
    238, 220, 120,
    255, 239, 213,
    234, 234, 174,
};

House::House()
{
    size = 20;

    int index1 = floor(rand() / (float)RAND_MAX * 7);
    int index2 = floor(rand() / (float)RAND_MAX * 7);
    int index3 = floor(rand() / (float)RAND_MAX * 7);

    index1 = 0;
    index3 = 5;
    colorTop = glm::vec3(TopColor[index1][0] / 255.0, TopColor[index1][1] / 255.0, TopColor[index1][2] / 255.0);
    colorBase = glm::vec3(BaseColor[index2][0] / 255.0, BaseColor[index2][1] / 255.0, BaseColor[index2][2] / 255.0);
    colorDoor = glm::vec3(TopColor[index3][0] / 255.0, TopColor[index3][1] / 255.0, TopColor[index3][2] / 255.0);
}

House::~House()
{

}

void House::Render()
{
    glTranslatef(0, size / 2, 0);
    glScalef(2, 1, 1);

	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, wallTexture);
    glColor3f(colorBase.x, colorBase.y, colorBase.z);
    glPushMatrix();
    for(int i = 0; i < 4; i++)
    {
    	glRotatef(90, 0, 1, 0);
    	glBegin(GL_QUADS);
    	glNormal3f(0, 0, 1);
		glTexCoord2f(0, 0);
		glVertex3f(-size / 2, -size / 2, size / 2);
		
		glTexCoord2f(1, 0);
		glVertex3f(size / 2, -size / 2, size / 2);
		
		glTexCoord2f(1, 1);
		glVertex3f(size / 2, size / 2, size / 2);
		
		glTexCoord2f(0, 1);
		glVertex3f(-size / 2, size / 2, size / 2);
		glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glColor3f(colorTop.x, colorTop.y, colorTop.z);
    glTranslatef(0, size / 2, 0);
    glRotatef(45, 1, 0, 0);
    glScalef(0.99 , 1 / sqrt(2), 1 / sqrt(2));
 	glPushMatrix();
    for(int i = 0; i < 4; i++)
    {
    	glRotatef(90, 0, 1, 0);
    	glNormal3f(0, 0, 1);
    	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-size / 2, -size / 2, size / 2);
		
		glTexCoord2f(1, 0);
		glVertex3f(size / 2, -size / 2, size / 2);
		
		glTexCoord2f(1, 1);
		glVertex3f(size / 2, size / 2, size / 2);
		
		glTexCoord2f(0, 1);
		glVertex3f(-size / 2, size / 2, size / 2);
		glEnd();
    }
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    for(int i = 0; i < 2; i++)
    {
		glRotatef(180, 1, 0, 0);
    	glNormal3f(0, 0, 1);
    	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-size / 2, -size / 2, size / 2);
		
		glTexCoord2f(1, 0);
		glVertex3f(size / 2, -size / 2, size / 2);
		
		glTexCoord2f(1, 1);
		glVertex3f(size / 2, size / 2, size / 2);
		
		glTexCoord2f(0, 1);
		glVertex3f(-size / 2, size / 2, size / 2);
		glEnd();
    }
    glPopMatrix();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glColor3f(colorDoor.x, colorDoor.y, colorDoor.z);
    glPushMatrix();
    glTranslatef(0, -size * 0.15, size / 2);
    glScalef(0.3, 1 , 0.1);
    glutSolidCube(size * 0.7);
    glPopMatrix();

}

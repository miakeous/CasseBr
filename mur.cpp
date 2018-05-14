#include "mur.h"

mur::mur(int X, int Z, int height, int width, QString rot, bool bas, QImage *imagemur)
{
    posX = X;
    posZ = Z;
    hauteur = height;
    largeur = width;
    tourne = rot;
    murbas = bas;

    tex = imagemur;
    glGenTextures(1, &m_TextureID);
    glBindTexture(GL_TEXTURE_2D, m_TextureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex->width(), tex->height(), 0, GL_RGBA , GL_UNSIGNED_BYTE, tex->bits());
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, m_TextureID);
}

void mur::display()
{
    glLoadIdentity();
    glPushMatrix();
    //glTranslatef(0,0, -10);
    glTranslatef(posX,posZ, 0);
    if(tourne=="droite"){ glRotatef(90,0,0,1);}else if(tourne == "gauche"){glRotatef(90,0,0,1);}
    rectangle(0,0,0,largeur,5,hauteur);

    glPopMatrix();

}

void mur::rectangle(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat profondeur, GLfloat hauteur, GLfloat taille){
    glPushMatrix();
    glColor3f(1,1,1);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex->width(), tex->height(), 0, GL_RGBA , GL_UNSIGNED_BYTE, tex->bits());
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glEnable(GL_TEXTURE_2D);


    glBegin(GL_POLYGON);
       glTexCoord2f(0,0);
       glVertex3f(posX,posY,posZ);
       glTexCoord2f(1,0);
       glVertex3f(posX,posY + largeur,posZ);
       glTexCoord2f(1,1);
       glVertex3f(posX,posY + largeur,posZ+hauteur);
       glTexCoord2f(0,1);
       glVertex3f(posX,posY ,posZ+hauteur);
    glEnd();

    glBegin(GL_POLYGON);
       glTexCoord2f(0,0);
       glVertex3f(posX+taille,posY,posZ);
       glTexCoord2f(1,0);
       glVertex3f(posX+taille,posY+ largeur,posZ);
       glTexCoord2f(1,1);
       glVertex3f(posX+taille,posY+ largeur,posZ+hauteur);
       glTexCoord2f(0,1);
       glVertex3f(posX+taille,posY,posZ+hauteur);
    glEnd();

    glBegin(GL_POLYGON);
       glTexCoord2f(0,0);
       glVertex3f(posX,posY,posZ);
       glTexCoord2f(1,0);
       glVertex3f(posX,posY,posZ+hauteur);
       glTexCoord2f(1,1);
       glVertex3f(posX+taille,posY,posZ+hauteur);
       glTexCoord2f(0,1);
       glVertex3f(posX+taille,posY,posZ);
    glEnd();

    glBegin(GL_POLYGON);
       glTexCoord2f(0,0);
       glVertex3f(posX,posY+largeur,posZ);
       glTexCoord2f(1,0);
       glVertex3f(posX,posY+largeur,posZ+hauteur);
       glTexCoord2f(1,1);
       glVertex3f(posX+taille,posY+largeur,posZ+hauteur);
       glTexCoord2f(0,1);
       glVertex3f(posX+taille,posY+largeur,posZ);
    glEnd();

    glBegin(GL_POLYGON);
       glTexCoord2f(0,0);
       glVertex3f(posX,posY,posZ);
       glTexCoord2f(1,0);
       glVertex3f(posX,posY+largeur,posZ);
       glTexCoord2f(1,1);
       glVertex3f(posX+taille,posY+largeur,posZ);
       glTexCoord2f(0,1);
       glVertex3f(posX+taille,posY,posZ);
    glEnd();

    glBegin(GL_POLYGON);
       glTexCoord2f(0,0);
       glVertex3f(posX,posY,posZ+hauteur);
       glTexCoord2f(1,0);
       glVertex3f(posX,posY+largeur,posZ+hauteur);
       glTexCoord2f(1,1);
       glVertex3f(posX+taille,posY+largeur,posZ+hauteur);
       glTexCoord2f(0,1);
       glVertex3f(posX+taille,posY,posZ+hauteur);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

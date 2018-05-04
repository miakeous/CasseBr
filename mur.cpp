#include "mur.h"

mur::mur(int X,int Z, int height, int width, QString rot)
{
    posX = X;
    posZ = Z;
    hauteur = height;
    largeur = width;
    tourne = rot;
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
    glColor3f(1,0.9,0);
    glBegin(GL_POLYGON);

       glVertex3f(posX,posY,posZ);
       glVertex3f(posX,posY + largeur,posZ);
       glVertex3f(posX,posY + largeur,posZ+hauteur);
       glVertex3f(posX,posY ,posZ+hauteur);
    glEnd();
    glBegin(GL_POLYGON);

       glVertex3f(posX+taille,posY,posZ);
       glVertex3f(posX+taille,posY+ largeur,posZ);
       glVertex3f(posX+taille,posY+ largeur,posZ+hauteur);
       glVertex3f(posX+taille,posY,posZ+hauteur);
    glEnd();
    glBegin(GL_POLYGON);

       glVertex3f(posX,posY,posZ);
       glVertex3f(posX,posY,posZ+hauteur);
       glVertex3f(posX+taille,posY,posZ+hauteur);
       glVertex3f(posX+taille,posY,posZ);
    glEnd();
    glBegin(GL_POLYGON);

       glVertex3f(posX,posY+largeur,posZ);
       glVertex3f(posX,posY+largeur,posZ+hauteur);
       glVertex3f(posX+taille,posY+largeur,posZ+hauteur);
       glVertex3f(posX+taille,posY+largeur,posZ);
    glEnd();
    glBegin(GL_POLYGON);

       glVertex3f(posX,posY,posZ);
       glVertex3f(posX,posY+largeur,posZ);
       glVertex3f(posX+taille,posY+largeur,posZ);
       glVertex3f(posX+taille,posY,posZ);
    glEnd();
    glBegin(GL_POLYGON);

       glVertex3f(posX,posY,posZ+hauteur);
       glVertex3f(posX,posY+largeur,posZ+hauteur);
       glVertex3f(posX+taille,posY+largeur,posZ+hauteur);
       glVertex3f(posX+taille,posY,posZ+hauteur);
    glEnd();
}

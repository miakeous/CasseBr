#include "brique.h"

Brique::Brique(float x,float y, float r, float v, float b,QString filename)
{
    //On définit sa position initiale
    posx = x;
    posy = y;

    //On définit la couleur de la brique
    couleur[0] = r;
    couleur[1] = v;
    couleur[2] = b;
    couleur[3] = 1.0;
    taille = 4;
    hauteur = 12;
    largeur = 4;
    //On importe une belle texture pour la brique
    //imgText =  QGLWidget::convertToGLFormat(QImage(filename));

     glEnable(GL_DEPTH_TEST);
     //glColor3f(couleur[0],couleur[1],couleur[2]);
}

Brique::~Brique()
 {
     // Destruction de la quadrique

     //gluDeleteQuadric(quadrique);

 }


void Brique::display(){

    glLoadIdentity();
    glPushMatrix();


    rectangle(0,0,0,taille,hauteur);
    //glMaterialfv(GL_FRONT,GL_AMBIENT,couleur);
    //glEnable(GL_TEXTURE_2D);
    //glBindTexture( GL_TEXTURE_2D, texture);
     //glColor3f(couleur[0],couleur[1],couleur[2]);


    //gluSphere(quadrique, 5, 50, 50);
    //glDisable(GL_TEXTURE_2D);
    glPopMatrix();

}


void Brique::rectangle(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat hauteur, GLfloat taille){

    glPopMatrix();
    glTranslatef(posx,posy+10,-10);
    glColor3f(couleur[0],couleur[1],couleur[2]);
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
    glPopMatrix();
}



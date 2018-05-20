#include "brique.h"
#include <QDebug>

Brique::Brique(float x,float y, float r, float v, float b,QString filename, QImage *image)
{
    //On définit sa position initiale
    posx = x;
    posy = y+10;

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
     tex = image;
     //tex = QGLWidget::convertToGLFormat(QImage(QString(":/pourbrique.jpg")));
     glGenTextures(1, &m_TextureID);
     glBindTexture(GL_TEXTURE_2D, m_TextureID);
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex->width(), tex->height(), 0, GL_RGBA , GL_UNSIGNED_BYTE, tex->bits());
     glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

     glBindTexture(GL_TEXTURE_2D, m_TextureID);

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

//    glPopMatrix();
    glPushMatrix();
    glTranslatef(posx,posy,-10);
    glColor3f(couleur[0],couleur[1],couleur[2]);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 800,533, 0, GL_RGBA , GL_UNSIGNED_BYTE, tex->bits());
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
       glColor3f(couleur[0], couleur[1], couleur[2]);
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
       glColor3f(couleur[0], couleur[1], couleur[2]);
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
       glColor3f(couleur[0], couleur[1], couleur[2]);
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
       glColor3f(couleur[0], couleur[1], couleur[2]);
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
       glColor3f(couleur[0], couleur[1], couleur[2]);
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
       glColor3f(couleur[0], couleur[1], couleur[2]);
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
int Brique::coteTouche(float posXboule, float posYboule)
{
    if(posXboule > posx && posXboule < posx+ 12 && posYboule > posy - 0.5 && posYboule < posy +0.5)
    {
        return 1 ; // on touche le bas
    }
    else
    {
        if(posXboule > posx && posXboule < posx+ 12 && posYboule > posy +4 - 0.5 && posYboule < posy +4 +0.5)
        {
            return 2; // on touche le haut
        }
        else
        {
           if(posYboule > posy && posYboule < posy +4 && posXboule > posx - 0.5 && posXboule < posx +0.5)
            {
                return 3; // on touche la gauche
            }
            else
                if(posYboule > posy && posYboule < posy +4 && posXboule > posx +12 - 0.5 && posXboule < posx +12 +0.5)
                {
                    return 4; // on touche la droite
                }
            else
                {
                    return 0; // on ne touche pas la brique
                }
        }
    }
}

int Brique::coteTouche(float posXboule, float posYboule)
{
    if(posXboule > posx && posXboule < posx+ 12 && posYboule > posy - 0.5 && posYboule < posy +0.5)
    {
        return 1 ; // on touche le bas
    }
    else
    {
        if(posXboule > posx && posXboule < posx+ 12 && posYboule > posy +4 - 0.5 && posYboule < posy +4 +0.5)
        {
            return 2; // on touche le haut
        }
        else
        {
            if(posYboule > posy && posYboule < posy +4 && posXboule > posx - 0.5 && posXboule < posx +0.5)
            {
                return 3; // on touche la gauche
            }
            else
                if(posYboule > posy && posYboule < posy +4 && posXboule > posx +12 - 0.5 && posXboule < posx +12 +0.5)
                {
                    return 4; // on touche la droite
                }
            else
                {
                    return 0; // on ne touche pas la brique
                }
        }
    }
}



#ifndef PALET_H
#define PALET_H
/*
//Pierre
#include "glu.h"
#include <GLUT/glut.h>
*/

#include <QDebug>
#include "mur.h"

//include Manon (Windows)
#include <GL/glu.h>
#include <GL/gl.h>


class Palet
{
public:
    Palet(float r, float v, float b,float tail);

    void display();
    void setPos(float x,mur *gauche,mur *droite);
    void setTaille(float x);
    float taille = 10;
    float getTaille(){return taille;}
    float getPosX(){return posx;}
    float getPosY(){return posy;}
public slots :

private:
    float posx= 0;
    float posy = -45;
    float posz = 20;

    float couleur[4];
    void rectangle(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat largeur, GLfloat hauteur);

};

#endif // PALET_H

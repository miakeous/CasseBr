#ifndef PALET_H
#define PALET_H
#include "glu.h"
#include <GLUT/glut.h>
#include <QDebug>

//include Manon (Windows)
/*
#include <GL/glu.h>
#include <GL/gl.h>
*/
class Palet
{
public:
    Palet(float r, float v, float b,float tail);

    void display();
    void setPos(float x);
    void setTaille(float x);
    float taille = 0;
    float getTaille(){return taille;}
    float getPosX(){return posx;}
public slots :

private:
    float posx= 0;
    float posy = 0;
    float posz = 20;

    float couleur[4];
    void rectangle(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat largeur, GLfloat hauteur);

};

#endif // PALET_H

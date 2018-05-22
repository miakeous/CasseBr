#ifndef PALET_H
#define PALET_H
/**/
//Pierre
#include "glu.h"
#include <GLUT/glut.h>


#include <QDebug>
#include "mur.h"

//include Manon (Windows)
//#include <GL/glu.h>
//#include <GL/gl.h>

#include "QGLWidget"
#include <QImage>


/*
 * La classe Palet gère les attributs d'un palet, son affichage et son déplacement
 * */

class Palet
{
public:
    Palet(float r, float v, float b,float tail, QImage *imagepalet);

    void display(); // affichage du palet

    void setPos(float x,mur *gauche,mur *droite); //set position palet
   //Taille palet
    void setTaille(float x);
    float getTaille(){return taille;}
    float taille = 25;
    float angleRenvoiBoule(int posXBoule); //angle de renvoi de la boule en fonction de la position d'arrivée de la boule sur le palet

    // getters sur les coordonnées du palet
    float getPosX(){return posx;}
    float getPosY(){return posy;}
    void reset();

public slots :

private:
    //coordonnées du palet
    float posx= 0;
    float posy = -45;
    float posz = 20;

    float inital;

    //couleur du palet
    float couleur[4];

    //sert à définir le pavé affiché dans display()
    void rectangle(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat largeur, GLfloat hauteur);

    // image et texture associées au palet
    GLuint m_TextureID = 0;
    QImage *tex;

};

#endif // PALET_H

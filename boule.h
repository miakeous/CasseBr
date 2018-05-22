#ifndef BOULE_H
#define BOULE_H
//Pierre

//#include "glu.h"
//#include <GLUT/glut.h>


// Manon
  #include <GL/glu.h>

#include <QImage>
#include <QGLWidget>


/*
 * La classe boule gère tout les attributs d'une boule, son affichage et son déplacement
 * */

class boule
{
public:
    //Constructeur qui prend en parametre la couleur de la boule
    boule(float r, float v, float b);

    // Affichage de la boule
    void display();

    //Fonction de position de la boule
    void setPosX(float x){posx = x;}
    void setPosZ(float z){posz = z;}

    //Retourne les positions de la boule
    float getPosX(){return posx;}
    float getPosZ(){return posz;}

    // Booleans qui permet de savoir si la boule est au dessus du palet ou non
    void setDepart(){posdepart=false;}
    bool posdepart = true;

    // l'angle de la trajectoire de la boule
    int angle = 45;
    int getAngle(){return angle;}
    void setAngle(int angles){angle = angles;}

    //Vitesse de la boule.
    float vitesseX =2 ;
    float vitesseY=1.11111;
    float getVitessex(){return vitesseX;}
    float getVitessey(){return vitesseY;}
    void setVitessex(float x){vitesseX =x;}
    void setVitessey(float y){vitesseY =y;}

private :
    //Quadradric pour la boule
    GLUquadric* quadrique =  gluNewQuadric();

    // Les positions de la boule
    float posx = 0;
    float posy = 0;
    float posz = 17.5;
    //Le tableau de couleur de la boule
    float couleur[4];
    //Les textures de la boule
    GLuint m_TextureID = 0;
    QImage tex;

};

#endif // BOULE_H

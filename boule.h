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
    boule(float r, float v, float b);

    void display(); // affiche la boule
    // setters et getters sur les attributs de position
    void setPosX(float x){posx = x;}
    void setPosZ(float z){posz = z;}
    float getPosX(){return posx;}
    float getPosZ(){return posz;}

    void setDepart(){posdepart=false;} // lance le déplacement de la boule
    bool posdepart = true;
    int angle = 45; // angle dans lequel se dirige la boule
    int getAngle(){return angle;}
    void setAngle(int angles){angle = angles;}

    //float getPosZ(){return posz;}

    // Attributs et getters / setters pour la vitesse
    float vitesseX =2 ;
    float vitesseY=1.11111;
    float getVitessex(){return vitesseX;}
    float getVitessey(){return vitesseY;}
    void setVitessex(float x){vitesseX =x;}
    void setVitessey(float y){vitesseY =y;}

private :
    // la quadrique pour l'affichage de la sphère
    GLUquadric* quadrique =  gluNewQuadric();

    //position de la sphère dans la scène
    float posx = 0;
    float posy = 0;
    float posz = 17.5;

    // couleur de la boule
    float couleur[4];

    // image et texture associée pour la boule
    GLuint m_TextureID = 0;
    QImage tex;

};

#endif // BOULE_H

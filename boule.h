#ifndef BOULE_H
#define BOULE_H
//Pierre
/*
#include "glu.h"
#include <GLUT/glut.h>
*/

// Manon
  #include <GL/glu.h>


class boule
{
public:
    boule(float r, float v, float b);

    void display();
    void setPosX(float x){posx = x;}
    void setPosZ(float z){posz = z;}
    float getPosX(){return posx;}
    float getPosZ(){return posz;}
    void setDepart(){posdepart=false;}
    bool posdepart = true;
    int angle = 45;
    int getAngle(){return angle;}
    void setAngle(int angles){angle = angles;}
    //float getPosZ(){return posz;}

private :
    GLUquadric* quadrique =  gluNewQuadric();

    float posx = 0;
    float posy = 0;
    float posz = 17.5;

    float couleur[4];
};

#endif // BOULE_H

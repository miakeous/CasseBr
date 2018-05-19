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


class Palet
{
public:
    Palet(float r, float v, float b,float tail, QImage *imagepalet);

    void display();
    void setPos(float x,mur *gauche,mur *droite);
    void setTaille(float x);
    float taille = 25;
    float angleRenvoiBoule(int posXBoule);
    float getTaille(){return taille;}
    float getPosX(){return posx;}
    float getPosY(){return posy;}
    void reset();

public slots :

private:
    float posx= 0;
    float posy = -45;
    float posz = 20;
    float inital;
    float couleur[4];
    void rectangle(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat largeur, GLfloat hauteur);

    // Identifiant de texture
    GLuint m_TextureID = 0;
    QImage *tex;

};

#endif // PALET_H

#ifndef BRIQUE_H
#define BRIQUE_H
/*
//include Pierre (Mac)

#include <QGLWidget>
#include "glu.h"
#include <GLUT/glut.h>
*/


//include Manon (Windows)
#include <QGLWidget>
#include <GL/glu.h>
#include <GL/gl.h>



#include <string>
#include <QImage>
#include  <QDebug>

class Brique
{
public:
    Brique(float x,float y, float r, float v, float b,QString filename, QImage *image);
    virtual ~Brique();
    void display();
    int hauteur =0;
    int largeur =0;
    int taille = 0;
    int getLargeur(){return hauteur;}
    int getTaille(){return taille;}
    int getCol(QString a){return posy/4;}
    GLfloat getColour(){return couleur[0];}
    int getPosx(){return posx;}
    int getPosz(){return posy;}

private :
    float posx = 0;
    float posy = 0;
    //GLUquadric* quadrique =  gluNewQuadric();
    float couleur[4];
    QImage *tex;
    GLuint m_TextureID = 0;
    void rectangle(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat hauteur, GLfloat taille);


};

#endif // BRIQUE_H

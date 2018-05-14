#ifndef MUR_H
#define MUR_H
/*
//include Pierre (mac)

#include "glu.h"
#include <GLUT/glut.h>

*/

//include Manon (windows)
#include <GL/glu.h>
#include <GL/gl.h>

#include <QDebug>
#include <QImage>

class mur
{
public:
    mur(int X, int Z, int height, int width, QString rot, bool bas, QImage *imagemur);
    void display();
    void rectangle(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat profondeur, GLfloat hauteur, GLfloat taille);
    int getPosx(){return posX;}
    int getPosz(){return posZ;}

private:
    int posX;
    int posZ;
    int hauteur;
    int largeur;
    bool murbas;
    QString tourne;
    QImage *tex;
    GLuint m_TextureID = 0;
};

#endif // MUR_H

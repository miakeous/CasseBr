#ifndef MUR_H
#define MUR_H

//include Pierre (mac)

#include "glu.h"
#include <GLUT/glut.h>



//include Manon (windows)
/*#include <GL/glu.h>
#include <GL/gl.h>
*/

#include <QDebug>

class mur
{
public:
    mur(int X, int Z, int height, int width, QString rot);
    void display();
    void rectangle(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat profondeur, GLfloat hauteur, GLfloat taille);
    int getPosx(){return posX;}
    int getPosz(){return posZ;}

private:
    int posX;
    int posZ;
    int hauteur;
    int largeur;
    QString tourne;
};

#endif // MUR_H

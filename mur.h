#ifndef MUR_H
#define MUR_H
/*
//include Pierre (mac)
*/
//#include "glu.h"
//#include <GLUT/glut.h>



//include Manon (windows)
#include <GL/glu.h>
#include <GL/gl.h>

#include <QDebug>
#include <QImage>


/*
 * La classe mur gère les attributs d'un mur et son affichage
 * */

class mur
{
public:
    mur(int X, int Z, int height, int width, QString rot, bool bas, QImage *imagemur);
    void display(); //fonction d'affichage du mur

    //sert à définir le pavé affiché dans display()
    void rectangle(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat profondeur, GLfloat hauteur, GLfloat taille);

    //getters sur la position
    int getPosx(){return posX;}
    int getPosz(){return posZ;}

private:
    // coordonnées du mur
    int posX;
    int posZ;

    //dimension du mur
    int hauteur;
    int largeur;

    // true si le mur est le mur du bas (celui qui nous enlève une vie si la boule le touche)
    bool murbas;
    QString tourne; // pour les murs horizontaux

    //image et texture associées au mur
    QImage *tex;
    GLuint m_TextureID = 0;
};

#endif // MUR_H

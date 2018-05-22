#ifndef BRIQUE_H
#define BRIQUE_H
/*
//include Pierre (Mac)
*/
//#include "glu.h"
//#include <GLUT/glut.h>



//include Manon (Windows)

#include <GL/glu.h>
#include <GL/gl.h>


#include <QGLWidget>
#include <string>
#include <QImage>
#include  <QDebug>

/*
 * La classe Brique gère tout les attributs d'une brique et son affichage
 * */

class Brique
{
public:
    Brique(float x,float y, float r, float v, float b,QString filename, QImage *image);
    virtual ~Brique();
    void display(); //affichage de la brique

    // dimension de la brique
    int hauteur =0;
    int largeur =0;
    int taille = 0;

    int getLargeur(){return hauteur;}
    int getTaille(){return taille;}

    // je sais pas à quoi ça sert :
    int getCol(QString a){return posy/4;}
    GLfloat getColour(){return couleur[0];}

    // getters sur la position de la brique
    int getPosx(){return posx;}
    int getPosz(){return posy;}

    //définit si la brique est touchée par la boule et sur quel côté
    int coteTouche(float posXboule, float posYboule);

private :
    //coordonnées de la brique
    float posx = 0;
    float posy = 0;

    //couleur à mélanger avec la texture
    float couleur[4];

    //image et texture associée
    QImage *tex;
    GLuint m_TextureID = 0;

    //sert à définir le pavé affiché dans display()
    void rectangle(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat hauteur, GLfloat taille);


};

#endif // BRIQUE_H

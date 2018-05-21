#ifndef MYWIDGET_H
#define MYWIDGET_H

/*On geres les imports ici vu qu'ils sont différents sous Window et Mac*/
//Pierre
#include "glu.h"
#include <GLUT/glut.h>


//include Manon (Windows)
//#include <GL/glu.h>
//#include <GL/gl.h>



#include <QApplication>
#include <QGLWidget>
#include "tableaujeux.h"

#include<stdio.h>
// Classe du Widget graphique 3D
class MyWidget : public QGLWidget
{
    Q_OBJECT
public:
    //Le controlleur du jeux
    TableauJeux *tableau;
    TableauJeux getTableau(){return *tableau;}
    void setTableau(TableauJeux *t);
    //Constructeur
    explicit MyWidget(QWidget * parent = nullptr);
    //Jcrois c'est useless
    void setPos(float x, float y, float z);

    //Jcrois c'est useless
    void update(){updateGL();}
    // Fonction qui être appelé par les slots de taille du Palet
    void setTaille(float x);

    //Fonction qui link notre clavier au passage de niveau.
    void levelup();
private :

    //Jcrois c'est useless
    float posx = 0;
    float posy = 0;
    float posz = 0;
    //Fonction GL
    void initializeGL();

     // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

signals:

public slots:
    // Les différents Slots qui sont utilisé pour gerer le jeux
    //Slots de taille de Palet
    void setTaillep();
    void setTaillem();
    void setTailleg();
    //Slot de Positions de Palet
    void setPosPaletg();
    void setPosPaletd();
    void setPosPalet();
    //Slots de Lanchement et arret du jeux.
    void setStart();
    void setStop();
};

#endif // MYWIDGET_H

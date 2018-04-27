#ifndef MYWIDGET_H
#define MYWIDGET_H

/*
//Pierre
#include "glu.h"
#include <GLUT/glut.h>
*/

//include Manon (Windows)
#include <QGLWidget>
#include <GL/glu.h>
#include <GL/gl.h>


#include <QApplication>
#include <QGLWidget>
#include "tableaujeux.h"

#include<stdio.h>

class MyWidget : public QGLWidget
{
    Q_OBJECT
public:
    TableauJeux *tableau;
    explicit MyWidget(QWidget * parent = nullptr);
    void setPos(float x, float y, float z);
    TableauJeux getTableau(){return *tableau;}

    void update(){updateGL();}
    void setTaille(float x);
    void setTableau(TableauJeux *t);
private :

    GLUquadric* quadrique =  gluNewQuadric();
    float posx = 0;
    float posy = 0;
    float posz = 0;

    void initializeGL();

     // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

signals:

public slots:
    void setTaillep();
    void setTaillem();
    void setTailleg();
    void setPosPaletg();
    void setPosPaletd();
    void setStart();
    void setStop();
};

#endif // MYWIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "opencv2/opencv.hpp"
#include <QTimer>
#include <QDebug>
#include <QGLWidget>
#include<QKeyEvent>
#include <cstdio>
#include <iostream>
#include "tableaujeux.h"

/**/
//Pierre
#include "glu.h"
#include <GLUT/glut.h>


//include Manon (Windows)

//#include <GL/glu.h>
//#include <GL/gl.h>


//#include <glwidget.h>

using namespace cv;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    //Controlleur du jeux
    TableauJeux *tableau;
    //interface Graphique
    Ui::Widget *ui;
    //Boolean de début de jeux
    bool started = false;
    //Mat match(Mat frame);
    //Les différentes matrices pour la reconnaissance visuel
    Mat frame1,frame2,frameRect1,frameRect2;
    Mat resultImage;
    //Mat templateImage;
    //Mat templateFinale;

    bool templi= false;

    double taillex = 100.;
    double distance = 0.;
    double tailley= 150.;
    // Gestion des rectangles de travail (les rectangles seront une partie de la matrice image)
    Rect *workingRect;
    Rect *templateRect;
    //Notre base pour le vecteur mouvement
    Point *workingCenter;
    QTimer *timer2;
    //Notre webcam
    VideoCapture * webCam_;
    //Taille de l'affichage Cam
    int frameWidth=(300);
    int frameHeight=200;

    int subImageWidth=100;
    int subImageHeight=100;
    int templateWidth=25;
    int templateHeight=25;

    float position = 0;

//    void match();
    //Gestion des touches pour passage de niveau a la main
protected:
    void keyPressEvent(QKeyEvent *event);
private slots :
    //Affichage de la caméra
    void affiche();
    //Fonction qui va detecter le mouvement
    void match();
    //Fonction qui gere les checkboxs pour la taille du palet (pas 2 de cochet en meme temps)
    void setTaille();
    void setTaille1();
    void setTaille2();

    //les différents signaux émis pour gerer le déplacement du palet et du jeux avec la reconnaissance visuel
    signals :
    void gauche();
    void droite();
    void start();
    void stop();


};

#endif // WIDGET_H

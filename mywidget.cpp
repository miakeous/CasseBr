#include "mywidget.h"
#include "ui_widget.h"

MyWidget::MyWidget(QWidget *parent) :
    QGLWidget(parent)
{
    // Reglage de la taille/position
    gluQuadricDrawStyle(quadrique, GLU_FILL);
    //


}


void MyWidget::initializeGL(){
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
    // Activation du zbuffer

    glEnable(GL_DEPTH_TEST);


}

void MyWidget::setTableau(TableauJeux *t){
    this->tableau = t;
}


void MyWidget::resizeGL(int w, int h){
      glViewport(0, 0, w, h);
      // Definition de la matrice de projection
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();

      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();

}
void MyWidget::paintGL(){


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-90,90,-50,50,-50,50);
    //glFrustum(-50,50,-50,50,-20,50);
    //gluLookAt(0,20,20,0,0,0,0,1,0);
    gluLookAt(0,0,30,0,0,0,0,1,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
   /* glPushMatrix();
        gluQuadricDrawStyle(quadrique, GLU_FILL);
        glColor3f(255,0,255);
        glTranslatef(posx+0,posy+0,posz+0);
        gluSphere(quadrique, 2.5, 50, 50);
    glPopMatrix();*/
    tableau->affiche();

}

void MyWidget::setPos(float x, float y, float z){
    posx = x;
    posy = y;
    posz = z;
    updateGL();
}

void MyWidget::setTaillep(){
   this->getTableau().setTaille(25.0);
    updateGL();
}
void MyWidget::setTaillem(){
   this->getTableau().setTaille(30.0);
    updateGL();
}
void MyWidget::setTailleg(){
   tableau->setTaille(150.0);
    updateGL();
}

void MyWidget::setPosPaletd(){
     //qDebug()<<"droite";
    this->getTableau().setPosPaletd();
    updateGL();
}
void MyWidget::setPosPalet(){
     //qDebug()<<"droite";
    this->getTableau().setPosPalet();
    updateGL();
}

void MyWidget::setPosPaletg(){
     //qDebug()<<"gauche";
    this->getTableau().setPosPaletg();
     updateGL();
}
void MyWidget::setStart(){
   //  qDebug()<<"start";
    this->getTableau().setStart();
     updateGL();
}
void MyWidget::setStop(){
   //  qDebug()<<"stop";
    this->getTableau().setStart();
     updateGL();
}


void MyWidget::levelup(){

    tableau->reset();
    updateGL();
}

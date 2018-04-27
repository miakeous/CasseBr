#include "brique.h"

Brique::Brique(float x,float y, float r, float v, float b,QString filename)
{
    //On définit sa position initiale
    posx = x;
    posy = y;

    //On définit la couleur de la brique
    couleur[0] = r;
    couleur[1] = v;
    couleur[2] = b;
    couleur[3] = 1.0;

    //On importe une belle texture pour la brique
    //imgText =  QGLWidget::convertToGLFormat(QImage(filename));

     glEnable(GL_DEPTH_TEST);
     //glColor3f(couleur[0],couleur[1],couleur[2]);

    //On définit les textures et on les active
    //glGenTextures( 1, &texture);
    //glBindTexture( GL_TEXTURE_2D, texture);
    //glTexImage2D( GL_TEXTURE_2D, 0, 3, imgText.width(), imgText.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, imgText.bits() );
    //glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    //glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    //gluQuadricTexture(quadrique, GL_TRUE);
   /* qDebug() << "Rouge";
    qDebug() << couleur[0];
    qDebug() << "Vert";
    qDebug() << couleur[1];
    qDebug() << "Bleu";
    qDebug() << couleur[2];*/


}
Brique::~Brique()
 {
     // Destruction de la quadrique

     //gluDeleteQuadric(quadrique);

 }


void Brique::display(){

    glLoadIdentity();
    glPushMatrix();


    rectangle(0,0,0);
    //glMaterialfv(GL_FRONT,GL_AMBIENT,couleur);
    //glEnable(GL_TEXTURE_2D);
    //glBindTexture( GL_TEXTURE_2D, texture);
     //glColor3f(couleur[0],couleur[1],couleur[2]);


    //gluSphere(quadrique, 5, 50, 50);
    //glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}


void Brique::rectangle(GLfloat posX, GLfloat posY, GLfloat posZ){
    int a = 9;
    int b = 3;
    int c = 3;

    glPopMatrix();
    glTranslatef(posx,40,posy -15 );
    glColor3f(couleur[0],couleur[1],couleur[2]);
    glBegin(GL_POLYGON);
    //    glColor3f(couleur[0],couleur[1],couleur[2]);
       glVertex3f(posX,posY,posZ);
       glVertex3f(posX,posY+ b,posZ);
       glVertex3f(posX,posY+ b,posZ+c);
       glVertex3f(posX,posY,posZ+c);
    glEnd();
    glBegin(GL_POLYGON);
      //  glColor3f(couleur[0],couleur[1],couleur[2]);
       glVertex3f(posX+a,posY,posZ);
       glVertex3f(posX+a,posY+ b,posZ);
       glVertex3f(posX+a,posY+ b,posZ+c);
       glVertex3f(posX+a,posY,posZ+c);
    glEnd();
    glBegin(GL_POLYGON);
        //glColor3f(couleur[0],couleur[1],couleur[2]);
       glVertex3f(posX,posY,posZ);
       glVertex3f(posX,posY,posZ+c);
       glVertex3f(posX+a,posY,posZ+c);
       glVertex3f(posX+a,posY,posZ);
    glEnd();
    glBegin(GL_POLYGON);
        //glColor3f(couleur[0],couleur[1],couleur[2]);
       glVertex3f(posX,posY+b,posZ);
       glVertex3f(posX,posY+b,posZ+c);
       glVertex3f(posX+a,posY+b,posZ+c);
       glVertex3f(posX+a,posY+b,posZ);
    glEnd();
    glBegin(GL_POLYGON);
      //  glColor3f(couleur[0],couleur[1],couleur[2]);
       glVertex3f(posX,posY,posZ);
       glVertex3f(posX,posY+b,posZ);
       glVertex3f(posX+a,posY+b,posZ);
       glVertex3f(posX+a,posY,posZ);
    glEnd();
    glBegin(GL_POLYGON);
      //  glColor3f(couleur[0],couleur[1],couleur[2]);
       glVertex3f(posX,posY,posZ+c);
       glVertex3f(posX,posY+b,posZ+c);
       glVertex3f(posX+a,posY+b,posZ+c);
       glVertex3f(posX+a,posY,posZ+c);
    glEnd();
    glPopMatrix();
}



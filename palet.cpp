#include "palet.h"

Palet::Palet(float r, float v, float b,float tail)
{
    taille= tail;
    couleur[0] = r;
    couleur[1] = v;
    couleur[2] = b;
    couleur[3] = 1.0;
    glEnable(GL_DEPTH_TEST);
}


void Palet::display(){

    glLoadIdentity();
    glPushMatrix();


    //glMaterialfv(GL_FRONT,GL_AMBIENT,couleur);
    //glEnable(GL_TEXTURE_2D);
    //glBindTexture( GL_TEXTURE_2D, texture);
     //glColor3f(couleur[0],couleur[1],couleur[2]);
   // qDebug()<< posx;
    rectangle(0,0,0,5,5);
    //gluSphere(quadrique, 5, 50, 50);
    //glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void Palet::rectangle(float posX, float posY, float posZ, float largeur, float hauteur){
    glPushMatrix();
    glTranslatef(posx,posy,40);
    glColor3f(couleur[0],couleur[1],couleur[2]);
    glBegin(GL_POLYGON);

       glVertex3f(posX,posY,posZ);
       glVertex3f(posX,posY+ largeur,posZ);
       glVertex3f(posX,posY+ largeur,posZ+hauteur);
       glVertex3f(posX,posY,posZ+hauteur);
    glEnd();
    glBegin(GL_POLYGON);

       glVertex3f(posX+taille,posY,posZ);
       glVertex3f(posX+taille,posY+ largeur,posZ);
       glVertex3f(posX+taille,posY+ largeur,posZ+hauteur);
       glVertex3f(posX+taille,posY,posZ+hauteur);
    glEnd();
    glBegin(GL_POLYGON);

       glVertex3f(posX,posY,posZ);
       glVertex3f(posX,posY,posZ+hauteur);
       glVertex3f(posX+taille,posY,posZ+hauteur);
       glVertex3f(posX+taille,posY,posZ);
    glEnd();
    glBegin(GL_POLYGON);

       glVertex3f(posX,posY+largeur,posZ);
       glVertex3f(posX,posY+largeur,posZ+hauteur);
       glVertex3f(posX+taille,posY+largeur,posZ+hauteur);
       glVertex3f(posX+taille,posY+largeur,posZ);
    glEnd();
    glBegin(GL_POLYGON);

       glVertex3f(posX,posY,posZ);
       glVertex3f(posX,posY+largeur,posZ);
       glVertex3f(posX+taille,posY+largeur,posZ);
       glVertex3f(posX+taille,posY,posZ);
    glEnd();
    glBegin(GL_POLYGON);

       glVertex3f(posX,posY,posZ+hauteur);
       glVertex3f(posX,posY+largeur,posZ+hauteur);
       glVertex3f(posX+taille,posY+largeur,posZ+hauteur);
       glVertex3f(posX+taille,posY,posZ+hauteur);
    glEnd();
    glPopMatrix();
}


void Palet::setPos(float x,mur *gauche,mur *droite){
    //qDebug()<< "on rentre dans le setPos";
    if(this->posx>=0){
        //Remplacer 49 par position mur droite
        bool t =(this->posx+x)+this->getTaille()<= droite->getPosx()-1.75;
       // qDebug()<<(this->posx+x)+this->getTaille();
        //qDebug()<< "droite";
        //qDebug()<< droite->getPosx();
        //qDebug()<< gauche->getPosz();
        if(t){

            this->posx+=x;
        }

    }
    else
    {
        //Remplacer -49 par position mur gauche
        if(this->posx+x>= gauche->getPosx()){
            this->posx+=x;
        }
    }


    //qDebug()<< this->posx;

   //

}

void Palet::setTaille(float x)
{

    this->taille = x;
    //updateGL();
   // qDebug() << taille;
}



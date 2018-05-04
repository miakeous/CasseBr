#include "tableaujeux.h"

TableauJeux::TableauJeux()
{
    pause = false;
    palet = new Palet(0,255,255,10);
   // Brique *t = new Brique(10.0,-10.0,1.0,0,0,"");
    //m_Brique.push_back(t);
    for(int i=1 ;i <5; i++){
        for(int j=-5;j<5;j++){
            float v2 = rand() % 255 + 1;
            float v3 = rand() % 255 + 1;
            float v4 = rand() % 255 + 1;


            //m_Brique.push_back(new Brique(float(j*5),float(i*10),v2/255,v3/255,v4/255,"") );

        }
    }
    myball = new boule(255,0,255);
    gauche = new mur(-80,-50,100,3, "gauche");
    droit = new mur(80,-50,100,3,"droite");
    haut = new mur(-80,47,160,3,"");
    //m_Mur.push_back(gauche);
    //m_Mur.push_back(droit);
   // m_Mur.push_back(haut);


}


void TableauJeux::affiche(){
    int i = 0;

        Brique *red = new Brique(-40,-20,1,0,0,"");
        red->display();

        if(myball->posdepart) // posdepart équivaut à posé sur le palet
          {
              myball->setPosX(palet->getPosX()+palet->getTaille()/2);
              myball->setPosZ(palet->getPosY()+5);
          }
    if(start==true){
            myball->setDepart();
            //myball->setPosX(myball->getPosX()+1);
           // myball->setPosZ(myball->getPosZ()+1);
            collisionl();
            //myball->setPosX(myball->getPosZ());
    }


     palet->display();
     myball->display();
     gauche->display();
     droit->display();
     haut->display();

    //qDebug()<<  palet->getTaille();
    while ( i < m_Brique.size() )
    {
          //  m_Brique[i]->display();
            i++ ;
    }
    i=0;



}

void TableauJeux::reset(){
    for(int i=11 ;i > 8; i--){
        for(int j=-5;j<5;j++){
            float v2 = rand() % 255 + 1;
            float v3 = rand() % 255 + 1;
            float v4 = rand() % 255 + 1;
            m_Brique.push_back(new Brique(float(j*5),float(i*4),v2,v3,v4,""));

        }
    }
}


void TableauJeux::setTaille(float x){
    this->palet->setTaille(x);

}

void TableauJeux::setPosPaletd(){
    //qDebug() << this->pause;
    if(this->pause==false){
        this->palet->setPos(-2,gauche,droit);
    }


}
void TableauJeux::setPosPaletg(){
    if(this->pause==false){
        this->palet->setPos(2,gauche,droit);
    }

}
void TableauJeux::setStart(){
   // qDebug()<< start;
    start = true;
}
void TableauJeux::setStop(){
    this->start = false;
}

int TableauJeux::collisionl(){
    float posx = myball->getPosX();
    float posz = myball->getPosZ();
    int angle = myball->getAngle();
    float newposx = 0;
    float newposy = 0;
    int newangle = angle;
    qDebug()<< angle;
    qDebug()<< posx;
    qDebug()<< posz;
     if(this->pause==false){
   if(droit->getPosx()-/*+ taille*/7<=posx){
       qDebug()<<"Mur de droite";
       if(angle<0){
           newangle = angle - 90;
       }else
           newangle = angle + 90;

   }
   if(gauche->getPosx()+/*+*/10>=posx){
      // qDebug()<<"Mur de gauche";
       if(angle<0){
           newangle = angle + 90;
       }else
           newangle = angle - 90;
   }
   if((posz)>= 45){
      // qDebug()<<"Mur du haut";
      // newposy=1;
       if(angle==90){
           newangle = angle - 180;
       }else{
            newangle = angle - 90;
       }
       }
   else if(posz<=-45){
        //Ajouté player.looselife(); une fois fait
       qDebug()<< "loose";
       myball->setPosX(0);
       myball->setPosZ(-20);
       myball->setAngle(-90);
       posx=0;
       posz=-20;
       newangle =-90;
       pause=true;


   }
   int i=0;
   while(m_Brique.size()>i){
       if(posx > + m_Brique[i].getLargeur())
       i++;

   }
    // converting degrees to radians
    double x = newangle*3.14159/180;

   //qDebug()<< 1.111111*sin(x);
   myball->setPosX(posx+2*cos(x));
   myball->setPosZ(posz+1.111111*sin(x));
   myball->setAngle(newangle);

}
}




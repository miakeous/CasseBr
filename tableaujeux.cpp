#include "tableaujeux.h"

TableauJeux::TableauJeux()
{
    pause = false;

    imagePalet =  QGLWidget::convertToGLFormat(QImage(QString(":/pourpalet.jpg")));
    imageBrique = QGLWidget::convertToGLFormat(QImage(QString(":/pourbrique.jpg")));
    imageMur = QGLWidget::convertToGLFormat(QImage(QString(":/pourmur.jpg")));
    imageMurBas = QGLWidget::convertToGLFormat(QImage(QString(":/pourmurbas.jpg")));
    palet = new Palet(0,255,255,15, &imagePalet);
    player->initnbvie();
    for(int i=1 ;i <6; i++){
        for(int j=-5;j<5;j++){
            float v2 = rand() % 255 + 1;
            float v3 = rand() % 255 + 1;
            float v4 = rand() % 255 + 1;

            m_Brique.push_back(new Brique(float(j*13),float(i*5),v2/255,v3/255,v4/255,"", &imageBrique) );

        }
    }

    myball = new boule(255,0,255);
    gauche = new mur(-78,-50,100,3, "gauche", false, &imageMur);
    gauche2 = new mur(-82,-50,100,3, "gauche", false, &imageMur);
    droit = new mur(78,-50,100,3,"droite", false, &imageMur);
    droit2 = new mur(82,-50,100,3,"droite", false, &imageMur);
    haut = new mur(-78,47,156,3,"", false, &imageMur);
    bas = new mur(-78,-50,156,2,"", true, &imageMurBas);



}


void TableauJeux::affiche(){
    int i = 0;

       // Brique *red = new Brique(-40,-20,1,0,0,"");
       // red->display();
    if(player->getnbboules()!=0){

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
     gauche2->display();
     droit->display();
     droit2->display();
     haut->display();
     bas->display();

    //qDebug()<<  palet->getTaille();
    while ( i < m_Brique.size() )
    {
           m_Brique[i]->display();
            i++ ;
    }
    i=0;
    }




}

void TableauJeux::reset(){
    for(int i=11 ;i > 8; i--){
        for(int j=-5;j<5;j++){
            float v2 = rand() % 255 + 1;
            float v3 = rand() % 255 + 1;
            float v4 = rand() % 255 + 1;
            //m_Brique.push_back(new Brique(float(j*5),float(i*4),v2,v3,v4,""));

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
void TableauJeux::setPosPalet(){
    //qDebug() << this->pause;
    if(this->pause==false){
        this->palet->setPos(0,gauche,droit);
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
     newangle = angle%360;
     if(this->pause==false){
        if(droit->getPosx()-/*+ taille*/7<posx){
            qDebug()<<"Mur de droite";

                newangle = angle + 90;

        }
        if(gauche->getPosx()+/*+*/5>posx){
       qDebug()<<"Mur de gauche";

           newangle = angle + 90;
}
   if((posz)> 45){
      // qDebug()<<"Mur du haut";
      // newposy=1;
       if(angle==90){
           newangle = angle - 180;
       }else{
               newangle = angle + 90;

       }
       }
   else if(posz<=-50){
        //Ajouté player.looselife(); une fois fait
       player->losevie();
       qDebug()<< "loose";
       myball->setPosX(0);
       myball->setPosZ(-20);
       myball->setAngle(-90);
       posx=0;
       posz=-20;
       newangle =-90;
       palet->reset();
       pause=true;


   }
   //Collision Palet
   if(posz +1.25 <= palet->getPosY()+5){
         qDebug()<< "Position Palet";
       qDebug()<< posz+1.25;
        qDebug()<< palet->getPosY()+5;
        if(posx -1.25<= palet->getPosX()+palet->getTaille() && posx +1.25 >= palet->getPosX() ){
            newangle = palet->angleRenvoiBoule(posx);
        }


   }


    //Collision Brique

   for(int i =0; i<m_Brique.size();i++){
        //qDebug() << i;
       float haut =m_Brique[i]->getPosz() + (m_Brique[i]->getTaille()/2) ;
       float bas = m_Brique[i]->getPosz() - (m_Brique[i]->getTaille()/2);
       float gauche =m_Brique[i]->getPosx() + (m_Brique[i]->getLargeur()/2) ;
       float droitre = m_Brique[i]->getPosx() - (m_Brique[i]->getLargeur()/2-2);
       if((posx - 1.25 <=  m_Brique[i]->getPosx() + (m_Brique[i]->getLargeur()/2)) && (posx+1.25 >=  m_Brique[i]->getPosx() - (m_Brique[i]->getLargeur()/2-2)) ){

           if((posz -1.25 <=  m_Brique[i]->getPosz() + (m_Brique[i]->getTaille()/2)) && (posz+1.25 >=  m_Brique[i]->getPosz() - (m_Brique[i]->getTaille()/2)) ){
                 // Ajout de player.gagnePoint();
               player->incrementerpoints(1);
           if(angle<=0){

                qDebug() << "position1";
                qDebug() << i;
                qDebug() << posx;
                qDebug() << posz;
                qDebug() << m_Brique[i]->getPosx() + (m_Brique[i]->getLargeur()/2);
                qDebug() << m_Brique[i]->getPosz() + (m_Brique[i]->getTaille()/2);
                qDebug() << m_Brique[i]->getPosx() - (m_Brique[i]->getLargeur()/2);
                qDebug() << m_Brique[i]->getPosz() - (m_Brique[i]->getTaille()/2);
                qDebug()<< "brique par la droite ";
                newangle = angle + 90;
                m_Brique.erase(m_Brique.begin() + (i));
               break;


           }else{
               qDebug() << "position2";
               qDebug() << i;
               qDebug() << posx;
               qDebug() << posz;
               qDebug()<< m_Brique[i]->getPosx() + (m_Brique[i]->getLargeur()/2);
               qDebug() << m_Brique[i]->getPosz() + (m_Brique[i]->getTaille()/2);
               qDebug()<< m_Brique[i]->getPosx() - (m_Brique[i]->getLargeur()/2);
               qDebug() << m_Brique[i]->getPosz() - (m_Brique[i]->getTaille()/2);
               qDebug()<< "brique par la droite ";
               newangle = angle + 90;
               m_Brique.erase(m_Brique.begin() + (i));
               break;



           }
           }
       }




   }
    // converting degrees to radians
    double x = newangle*3.14159/180;

   //qDebug()<< 1.111111*sin(x);
   myball->setPosX(posx+2*cos(x));
   myball->setPosZ(posz+1.111111*sin(x));
   myball->setAngle(newangle);


}
}




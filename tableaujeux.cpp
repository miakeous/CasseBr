#include "tableaujeux.h"

TableauJeux::TableauJeux()
{
    pause = false;

    imagePalet =  QGLWidget::convertToGLFormat(QImage(QString(":/pourpalet.jpg")));
    imageBrique = QGLWidget::convertToGLFormat(QImage(QString(":/pourbrique.jpg")));
    imageMur = QGLWidget::convertToGLFormat(QImage(QString(":/pourmur.jpg")));
    imageMurBas = QGLWidget::convertToGLFormat(QImage(QString(":/pourmurbas.jpg")));
    palet = new Palet(0,255,255,25, &imagePalet);
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
    //qDebug()<< player->getnbboules();
    //qDebug() << (player->getnbboules()!=0 || m_Brique.size()!= 0);
    if(player->getnbboules()!=0 && m_Brique.size()!= 0){

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

    qDebug()<<  m_Brique.size();
    while ( i < m_Brique.size() )
    {
           m_Brique[i]->display();
            i++ ;
    }
    i=0;
    }else if(m_Brique.size()== 0){

        reset();

    }




}

void TableauJeux::reset(){
    pause=true;
    player->incrementerniveau();
  qDebug()<< m_Brique.size();
 if(m_Brique.size()!=0)
     m_Brique.clear();
 qDebug()<< m_Brique.size();
    for(int i=1 ;i <6; i++){

        for(int j=-5;j<5;j++){
            float v2 = rand() % 255 + 1;
            float v3 = rand() % 255 + 1;
            float v4 = rand() % 255 + 1;
            float affiche = rand()%100;
            if(affiche > 75){
                qDebug()<< "on ajoute";
                qDebug()<<affiche;
                m_Brique.push_back(new Brique(float(j*13),float(i*5),v2/255,v3/255,v4/255,"", &imageBrique) );
            }

        }
    }
    //updateGl();
    myball->setPosX(0);
    myball->setPosZ(-20);
    myball->setAngle(-90);

    palet->reset();

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
     newangle = angle%180;
     if(this->pause==false){
        if(droit->getPosx()-/*+ taille*/7<posx +1.25){
        //    qDebug()<<"Mur de droite";
          //  qDebug()<<posx+1.25;
            if(angle<=90 && angle >=0 ){
                newangle = angle + (90-angle)*2;
            }
            if(angle>=-90 && angle <=0 ){
                newangle = angle -(angle+90)*2;
            }



        }
        if(gauche->getPosx()+/*+*/5>posx-1.25){
          //   qDebug()<<"Mur de gauche";
           //  qDebug()<<posx-1.25;
       if(angle >= 90 && angle <= 180){
               newangle = angle - (angle-90)*2;
       }
       if(angle <= -90 && angle >= -180){
               newangle = angle - (angle+90)*2;
       }


}
   if((posz+1.25)> 45){
      // qDebug()<<"Mur du haut";
      // newposy=1;
       if(angle<=90 && angle >=0 ){
           newangle = -angle;
       }
       if(angle<=180 && angle >=90 ){
           newangle = -angle;
       }
}
   else if(posz<=-55){
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
   if(posz -1.25 <= palet->getPosY()+5){
         qDebug()<< "Position Palet";
       qDebug()<< posz+1.25;
        qDebug()<< palet->getPosY()+5;
        if(posx -1.25<= palet->getPosX()+palet->getTaille() && posx +1.25 >= palet->getPosX() ){
            newangle = palet->angleRenvoiBoule(posx);
        }


   }


    //Collision Brique
    double angleCal = angle*3.14159/180;
   for(int i =0; i<m_Brique.size();i++){
        //qDebug() << i;
       float haut =m_Brique[i]->getPosz() + (m_Brique[i]->getTaille()/2) ;
       float bas = m_Brique[i]->getPosz() - (m_Brique[i]->getTaille()/2);
       float gauche =m_Brique[i]->getPosx() + (m_Brique[i]->getLargeur()/2) ;
       float droitre = m_Brique[i]->getPosx() - (m_Brique[i]->getLargeur()/2-2);
       int valeur =m_Brique[i]->coteTouche(posx+1.25*cos(angleCal),posz+1.25*sin(angleCal));
       //qDebug()<< valeur;
       switch(valeur){
       case 0: break;
       case 1: qDebug()<< "On touche bas";
           if(angle<=90 && angle >=0 ){
               newangle = -angle;
           }
           if(angle<=180 && angle >=90 ){
               newangle = -angle;
           }
           player->incrementerpoints(1);
           m_Brique.erase(m_Brique.begin() + (i));
           break;
       case 2: qDebug()<< "On touche Haut";
           if(angle>=-90 && angle <=0 ){
               newangle = -angle;
           }
           if(angle>=-180 && angle <=-90 ){
               newangle = -angle;
           }
           player->incrementerpoints(1);
           m_Brique.erase(m_Brique.begin() + (i));
           break;
       case 3: qDebug()<< "On touche gauche";
           if(angle<=90 && angle >=0 ){
               newangle = angle + (90-angle)*2;
           }
           if(angle>=-90 && angle <=0 ){
               newangle = angle -(angle+90)*2;
           }
           player->incrementerpoints(1);
           m_Brique.erase(m_Brique.begin() + (i));
           break;
       case 4: qDebug()<< "On touche droite";
           if(angle >= 90 && angle <= 180){
               newangle = angle - (angle-90)*2;
       }
       if(angle <= -90 && angle >= 180){
               newangle = angle - (angle+90)*2;

       }
       player->incrementerpoints(1);
       m_Brique.erase(m_Brique.begin() + (i));break;

       }

       /*if(posx + 1.25*cos(angleCal) <=  m_Brique[i]->getPosx() + (m_Brique[i]->getLargeur())){
           if((posx+1.25*cos(angleCal) >=  m_Brique[i]->getPosx())){
               if((posz +1.25*sin(angleCal) <=  m_Brique[i]->getPosz() + (m_Brique[i]->getTaille())) && (posz+1.25*sin(angleCal) >=  m_Brique[i]->getPosz()) ){
                   // face droite
                   qDebug()<<"On touche la partie droite ";
                   if(angle >= 90 && angle <= 180){
                           newangle = angle - (angle-90)*2;
                   }
                   if(angle <= -90 && angle >= 180){
                           newangle = angle - (angle+90)*2;

                   }
                   player->incrementerpoints(1);
                   m_Brique.erase(m_Brique.begin() + (i));
                     break;
               }
           }
       }
        if((posx+1.25*cos(angleCal) >=  m_Brique[i]->getPosx())){
            if(posx+ 1.25*cos(angleCal) <=  m_Brique[i]->getPosx() + (m_Brique[i]->getLargeur())){
               if((posz +1.25*sin(angleCal) <=  m_Brique[i]->getPosz() + (m_Brique[i]->getTaille())) && (posz+1.25*sin(angleCal) >=  m_Brique[i]->getPosz()) ){
                   //face gauche
                   qDebug()<<"On touche la partie gauche ";
                   if(angle<=90 && angle >=0 ){
                       newangle = angle + (90-angle)*2;
                   }
                   if(angle>=-90 && angle <=0 ){
                       newangle = angle -(angle+90)*2;
                   }
                   player->incrementerpoints(1);
                   m_Brique.erase(m_Brique.begin() + (i));
                   break;
               }
           }
       }
        if((posz+ 1.25*sin(angleCal) <=  m_Brique[i]->getPosz() + (m_Brique[i]->getTaille()))){
            if(posz+1.25*sin(angleCal) >=  m_Brique[i]->getPosz()){
                if((posx +1.25*cos(angleCal) <=  m_Brique[i]->getPosx() + (m_Brique[i]->getLargeur())) && (posx+1.25*cos(angleCal)>=  m_Brique[i]->getPosx()) ){
                    //haut
                    qDebug()<<"On touche la partie haute ";
                    if(angle>=-90 && angle <=0 ){
                        newangle = -angle;
                    }
                    if(angle>=-180 && angle <=-90 ){
                        newangle = -angle;
                    }
                    player->incrementerpoints(1);
                    m_Brique.erase(m_Brique.begin() + (i));
                    break;
                }
            }
        }
        if(posz+1.25*sin(angleCal) >=  m_Brique[i]->getPosz()){
            if(posz +1.25*sin(angleCal) <=  m_Brique[i]->getPosz() + (m_Brique[i]->getTaille())){
                if((posx +1.25*cos(angleCal) <=  m_Brique[i]->getPosx() + (m_Brique[i]->getLargeur())) && (posx+1.25*cos(angleCal) >=  m_Brique[i]->getPosx() ) ){
                    //bas
                    qDebug()<<"On touche la partie basse ";
                    if(angle<=90 && angle >=0 ){
                        newangle = -angle;
                    }
                    if(angle<=180 && angle >=90 ){
                        newangle = -angle;
                    }
                    player->incrementerpoints(1);
                    m_Brique.erase(m_Brique.begin() + (i));
                    break;
                }
            }
        }*/





      /* if((posx - 1.25 <=  m_Brique[i]->getPosx() + (m_Brique[i]->getLargeur()/2)) && (posx+1.25 >=  m_Brique[i]->getPosx() - (m_Brique[i]->getLargeur()/2-2)) ){

           if((posz -1.25 <=  m_Brique[i]->getPosz() + (m_Brique[i]->getTaille()/2)) && (posz+1.25 >=  m_Brique[i]->getPosz() - (m_Brique[i]->getTaille()/2)) ){
                 // Ajout de player.gagnePoint();
               player->incrementerpoints(1);
               m_Brique.erase(m_Brique.begin() + (i));
               if(angle<90 && angle >0 ){
                   newangle = angle + (90-angle)*2;
               }
               if(angle > 90 && angle < 180){
                       newangle = angle - (angle-90)*2;

               }
               if(angle>-90 && angle <0 ){
                   newangle = angle -(angle+90)*2;
               }
               if(angle < -90 && angle > 180){
                       newangle = angle + (angle+90)*2;

               }

           }
       }


        if((posz -1.25 <=  m_Brique[i]->getPosz() + (m_Brique[i]->getTaille()/2)) && (posz+1.25 >=  m_Brique[i]->getPosz() - (m_Brique[i]->getTaille()/2)) ){
            if((posx - 1.25 <=  m_Brique[i]->getPosx() + (m_Brique[i]->getLargeur()/2)) && (posx+1.25 >=  m_Brique[i]->getPosx() - (m_Brique[i]->getLargeur()/2-2)) ){
                 // Ajout de player.gagnePoint();
                qDebug() << "laaaaa";
               player->incrementerpoints(1);
               m_Brique.erase(m_Brique.begin() + (i));
               if(angle<90 && angle >0 ){
                   newangle = angle - (90-angle)*2;
               }
               if(angle > 90 && angle < 180){
                       newangle = angle + (angle-90)*2;

               }
               if(angle>-90 && angle <0 ){
                   newangle = angle +(angle+90)*2;
               }
               if(angle < -90 && angle > 180){
                       newangle = angle - (angle+90)*2;

               }
               break;
           }
       }*/






   }
    // converting degrees to radians
    double x = newangle*3.14159/180;

   //qDebug()<< 1.111111*sin(x);
   myball->setPosX(posx+2*cos(x));
   myball->setPosZ(posz+1.111111*sin(x));
   myball->setAngle(newangle);


}
}




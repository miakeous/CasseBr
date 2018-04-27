#include "tableaujeux.h"

TableauJeux::TableauJeux()
{
    pause = false;
    palet = new Palet(0,255,255,10);
    /*
    Brique *t = new Brique(10.0,-10.0,1.0,0,0,"");
    m_Brique.push_back(t);*/
    for(int i=1 ;i <6; i++){
        for(int j=-5;j<5;j++){
            float v2 = rand() % 255 + 1;
            float v3 = rand() % 255 + 1;
            float v4 = rand() % 255 + 1;


            m_Brique.push_back(new Brique(float(j*10),float(i*7-7),v2/255,v3/255,v4/255,"") );

        }
    }
    myball = new boule(255,0,255);
    gauche = new mur(-30,-20,100,3, false);
        droit = new mur(27,-20,100,3,false);
        haut = new mur(-30,-20,60,3,true);


}


void TableauJeux::affiche(){
    int i = 0;

        if(myball->posdepart) // posdepart équivaut à posé sur le palet
          {
              myball->setPosX(palet->getPosX()+palet->getTaille()/2);
          }
    if(start==true){
            myball->setDepart();
            //myball->setPosX(myball->getPosX()+1);
            myball->setPosZ(myball->getPosZ()-1);
    }



     palet->display();
     myball->display();
     gauche->display();
       droit->display();
       haut->display();

    //qDebug()<<  palet->getTaille();
    while ( i < m_Brique.size() )
    {
            m_Brique[i]->display();
            i++ ;
    }


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
    qDebug() << this->pause;
    if(this->pause==false){
        this->palet->setPos(-2);
    }


}
void TableauJeux::setPosPaletg(){
    if(this->pause==false){
        this->palet->setPos(2);
    }

}
void TableauJeux::setStart(){
    qDebug()<< start;
    start = true;
}
void TableauJeux::setStop(){
    this->start = false;
}

/*int TableauJeux::collisionLateral(Boule myball,std::vector<Brique *> m_Brique){
    foreach (Brique b, m_Brique) {
        if()

    }

}*/



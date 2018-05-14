#ifndef TABLEAUJEUX_H
#define TABLEAUJEUX_H
#include "brique.h"
#include "QDebug"
#include "boule.h"
#include "mur.h"
#include "palet.h"
#include <cmath>
class TableauJeux
{
public:
    TableauJeux();
    Palet *palet ;
    boule *myball;
    bool start  ;
    bool pause ;
    void reset();
    void affiche();
    Palet getPalet(){return *palet;}
    void setTaille(float x);
    void setPosPaletd();
    void setPosPaletg();
    void setStart();
    void setStop();
    bool getStart(){return this->start;}
    void setPause(bool t){pause = t;};
private:
    int collisionl();
    mur *gauche;
    mur *gauche2;
    mur *droit;
    mur *droit2;
    mur *haut;
    mur *bas;
    std::vector<Brique *> m_Brique;
    std::vector<mur *> m_Mur;
    QImage imageBrique;
    QImage imagePalet;
    QImage imageMur;
    QImage imageMurBas;

 private slots:
    void looselife();
    signals:
    void loose();
};

#endif // TABLEAUJEUX_H

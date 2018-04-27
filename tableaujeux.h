#ifndef TABLEAUJEUX_H
#define TABLEAUJEUX_H
#include "brique.h"
#include "QDebug"
#include "boule.h"
#include "mur.h"
#include "palet.h"
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
private :
    mur *gauche;
    mur *droit;
    mur *haut;
    std::vector<Brique *> m_Brique;
};

#endif // TABLEAUJEUX_H

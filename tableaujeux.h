#ifndef TABLEAUJEUX_H
#define TABLEAUJEUX_H
#include "brique.h"
#include "QDebug"
#include "boule.h"
#include "mur.h"
#include "palet.h"
#include <cmath>
#include "joueur.h"
//Cette classe est la classe controlleur du jeux.
class TableauJeux
{

public:
    //Constructeur
    TableauJeux();
    // object Palet
    Palet *palet ;
     // object Boule
    boule *myball;

    bool start  ;
    bool pause ;
    //Fonction qui va gerer le changement de niveau
    void reset();
    // Fonction qui va gerer l'affichage du jeux
    void affiche();
    //GETTER SETTER
    Palet getPalet(){return *palet;}
    void setTaille(float x);
    void setPosPaletd();
    void setPosPaletg();
    void setPosPalet();
    void setStart();
    void setStop();
    bool getStart(){return this->start;}
    void setPause(bool t){pause = t;};
    joueur getJoueur(){return *player;}
    //Fonction qui va augmenter la vitesse de la boule en fonction du niveau du player
    void setVitesse(int niveau);
private:
    //Fonction qui va gerer les collisions
    int collisionl();
    //Elements graphique
    mur *gauche;
    mur *gauche2;
    mur *droit;
    mur *droit2;
    mur *haut;
    mur *bas;
    std::vector<Brique *> m_Brique;
    std::vector<mur *> m_Mur;
    //Elements de Texture
    QImage imageBrique;
    QImage imagePalet;
    QImage imageMur;
    QImage imageMurBas;
    //Joueur
    joueur *player = new joueur();;
 private slots:
    void looselife();
    signals:
    void loose();
};

#endif // TABLEAUJEUX_H

#ifndef JOUEUR_H
#define JOUEUR_H


class joueur
{
public:
    joueur();
    int getpoints(){return points;}
    void incrementerpoints(int pointsenplus){points = points + pointsenplus;}

    void losevie(){nbboulesrestantes--;}
    int getnbboules(){return nbboulesrestantes;}
    void initnbvie(){nbboulesrestantes = 3;}

    void incrementerniveau(){niveau++;}
    int getniveau(){return niveau;}

private :
    int niveau = 1;
    int points = 0;
    int nbboulesrestantes = 3;
};

#endif // JOUEUR_H

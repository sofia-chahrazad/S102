#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED
#include"Personnage.h"
#include"Niveau.h"
class Ennemi {
    Personnage _perso;
public:
        Ennemi(Image img, int x, int y, int skin_x, int skin_y, Direction d = BAS);
        void dessiner()const;
        void avancer(Niveau n);
        ///getters
        int getX()const;
        int getY()const;
        void randDirection();
};

#endif // ENNEMI_H_INCLUDED

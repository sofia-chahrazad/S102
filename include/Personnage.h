#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED
#include <iostream>
#include "Image.h"

enum Direction { BAS = 0, GAUCHE = 1, DROITE = 2, HAUT = 3 };

class Personnage {

    Image* _image;
    int _x;
    int _y;
    int _skin_x;
    int _skin_y;
    Direction _dir;

public:
    Personnage();
    Personnage(Image& img, int x, int y, int skin_x, int skin_y, Direction d = BAS);

    void dessiner() const;

    void regarderDroite();
    void regarderGauche();
    void regarderHaut();
    void regarderBas();
};

#endif

#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED
#include <iostream>
#include "Image.h"
#include"Niveau.h"

enum Direction { BAS = 0, GAUCHE = 1, DROITE = 2, HAUT = 3 };

class Personnage {

    Image _image;
    int _x;
    int _y;
    int _skin_x;
    int _skin_y;
    Direction _dir;
    int _animation;

public:
    Personnage();
    Personnage(Image img, int x, int y, int skin_x, int skin_y, Direction d = BAS);

    void dessiner() const;

    void regarderDroite();
    void regarderGauche();
    void regarderHaut();
    void regarderBas();
    void deplacer(int dx, int dy);
    bool peutBougerVers(Direction d, Niveau n)const;
    //getters les accesseurs
    Direction getDirection()const;
    int getX()const;
    int getY()const;
    /// les setter
    void setsX(int );
    void setDirection(Direction d);

    void inverserDirection();
    void mettreAjourAnimation();
};

#endif

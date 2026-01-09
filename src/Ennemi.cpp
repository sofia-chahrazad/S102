#include <iostream>
#include "Image.h"
#include "Ennemi.h"
#include "Personnage.h"


Ennemi::Ennemi(Image img, int x, int y, int skin_x, int skin_y, Direction d )
{
    _perso = Personnage( img,  x,  y,  skin_x,  skin_y,  d );
}
void Ennemi::dessiner()const
{
    _perso.dessiner();
}
void Ennemi::avancer(Niveau n)
{

    if(!_perso.peutBougerVers(_perso.getDirection(), n)){
                _perso.inverserDirection();
            }

    switch(_perso.getDirection()){
        case DROITE:
            _perso.deplacer(1,0);
            break;
        case GAUCHE:
            _perso.deplacer(-1,0);
            break;
        case BAS:
            _perso.deplacer(0,1);
            break;
        case HAUT:
            _perso.deplacer(0,-1);
            break;
    }
};
///getters
int Ennemi::getX()const{
    return _perso.getX();
}
int Ennemi::getY()const{
    return _perso.getY();
}

void Ennemi::randDirection(){
    int nombre = rand() % 4;
    Direction d = Direction(nombre);
    _perso.setDirection(d);
}

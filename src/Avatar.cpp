#include <iostream>
#include "Image.h"
#include "Avatar.h"
#include "Personnage.h"
#include "Niveau.h"

Avatar::Avatar(Image img, int x, int y, int skin_x, int skin_y, Direction d ){
    _perso = Personnage( img,  x,  y,  skin_x,  skin_y,  d );
}
void Avatar::dessiner(){
    _perso.dessiner();
}
void Avatar::allerDroite(Niveau n){
    if(_perso.peutBougerVers(DROITE, n)){
            _perso.deplacer(1,0);
            _perso.regarderDroite();
    }

};
void Avatar::allerGauche(Niveau n){
    if(_perso.peutBougerVers(GAUCHE, n)){
        _perso.deplacer(-1,0);
        _perso.regarderGauche();
    }

};
void Avatar::allerHaut(Niveau n){
if(_perso.peutBougerVers(HAUT, n)){
    _perso.deplacer(0,-1);
    _perso.regarderHaut();}

};
void Avatar::allerBas(Niveau n){
if(_perso.peutBougerVers(BAS, n)){
    _perso.deplacer(0,1);
    _perso.regarderBas();
    }

};

bool Avatar::touche(const Ennemi& e){
    return (_perso.getX()== e.getX() && _perso.getY()==e.getY());
}


void Avatar::mettreAjourAnimation(){
    _perso.mettreAjourAnimation();
}

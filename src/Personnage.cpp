#include"Personnage.h"
#include<iostream>
#include"Image.h"
#include"Moteur.h"
using namespace std;
Personnage::Personnage(Image i, int x,int y,int skinx,int skiny,Direction dir){
    _image = i;
    _x = x;
    _y = y;
    _dir =dir;
    _skin_x = skinx;
    _skin_y = skiny;
    _animation = 0;
};
Personnage::Personnage(){
};
void Personnage::dessiner()const{
    if(_animation%4 ==0){
        _image.dessiner(_x*TAILLE_CASE,_y*TAILLE_CASE,(_skin_x)*TAILLE_CASE,(_dir+_skin_y)*TAILLE_CASE,TAILLE_CASE,TAILLE_CASE);
    }else if(_animation%4==1){
        _image.dessiner(_x*TAILLE_CASE,_y*TAILLE_CASE,(_skin_x+1)*TAILLE_CASE,(_dir+_skin_y)*TAILLE_CASE,TAILLE_CASE,TAILLE_CASE);
    }else if(_animation%4==2){
        _image.dessiner(_x*TAILLE_CASE,_y*TAILLE_CASE,(_skin_x+2)*TAILLE_CASE,(_dir+_skin_y)*TAILLE_CASE,TAILLE_CASE,TAILLE_CASE);
    }else{
        _image.dessiner(_x*TAILLE_CASE,_y*TAILLE_CASE,(_skin_x+1)*TAILLE_CASE,(_dir+_skin_y)*TAILLE_CASE,TAILLE_CASE,TAILLE_CASE);

    }



}

void Personnage::regarderDroite(){
    _dir = DROITE;
}
void Personnage::regarderGauche(){
    _dir = GAUCHE;
}
void Personnage::regarderHaut(){
    _dir = HAUT;
}
void Personnage::regarderBas(){
    _dir = BAS;
}

void Personnage::deplacer(int dx, int dy){
    _x = _x + dx;
    _y = _y+dy;
}

bool Personnage::peutBougerVers(Direction d, Niveau n){
    switch(d){
        case DROITE:
            return _x!=9 && n.caseEstLibre(_x+1,_y);
            break;
        case GAUCHE:
            return _x!=0 && n.caseEstLibre(_x-1,_y);
            break;
        case BAS:
            return _y!=7 && n.caseEstLibre(_x,_y+1);
            break;
        case HAUT:
            return _y!=0 && n.caseEstLibre(_x,_y-1);;
            break;
    }
}
/// les getters les accesseurs
Direction Personnage::getDirection()const{
    return _dir;
};
int Personnage::getX()const{
    return _x;
}
int Personnage::getY()const{
    return _y;
}
void Personnage::inverserDirection(){
    switch(_dir){
        case DROITE:
            _dir = GAUCHE;
            break;
        case GAUCHE:
            _dir =DROITE;
            break;
        case BAS:
            _dir = HAUT;
            break;
        case HAUT:
            _dir = BAS;
            break;
    }
}

void Personnage::mettreAjourAnimation(){
    _animation++;
}

void Personnage::setDirection(Direction d){
    _dir = d;
}

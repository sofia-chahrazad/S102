#include"Dictionnaire.h"
#include<iostream>
#include"Tuile.h"
#include<fstream>
#include<string>
#include"Objet.h"
using namespace std;

Objet::Objet(Image img,const string & nomTuile, Dictionnaire& d ,int x,  int y):_x(x),_y(y){
    _image = Image(img);
    d.recherche(nomTuile,_tuile);

}
void Objet::afficher()const{
    _tuile.afficher();
    cout<<" cordonnee x: "<<_x<<" cordonner y : "<<_y;
}

void Objet::dessiner()const{
    _image.dessiner(_x*TAILLE_CASE,_y*TAILLE_CASE,_tuile.getX()*TAILLE_CASE,_tuile.getY()*TAILLE_CASE,TAILLE_CASE,TAILLE_CASE);
}

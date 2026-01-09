#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include"Image.h"
#include"Tuile.h"
#include"Dictionnaire.h"
class Objet{
    Image _image;
    int _x;
    int _y;
    Tuile _tuile;
    public:
    Objet(Image img ,const string & nomTuile, Dictionnaire& d,int x=0,  int y=0);
    void dessiner()const;
    void afficher()const;;
    Tuile getTuile()const {return _tuile;};
    int getX()const{return _x;};
    int getY()const{return _y;}
    void cacher(){_tuile.cacher();};

};

#endif // OBJET_H_INCLUDED

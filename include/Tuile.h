#ifndef TUILE_H_INCLUDED
#define TUILE_H_INCLUDED
#include<iostream>
#include<string>
using namespace std;
class Tuile{
    int _xsprite;
    int _ysprite;
    string _name;
    string _propriete;
    public:
    Tuile(int x = 0 ,  int y = 0, const string& name = "default", const string& p = "default_propriete" ):_xsprite(x),_ysprite(y),_name(name),_propriete(p){};
    void afficher()const;

    string getName()const{return _name;};
    int getX()const{return _xsprite;};
    int getY()const{return _ysprite;};
    string getPropriete()const{return _propriete;};
    void setPropriete(const string &prop){_propriete = prop;};
    void cacher(){setPropriete("cache");};
};

#endif // TUILE_H_INCLUDED

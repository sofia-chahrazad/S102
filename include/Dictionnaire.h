#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED
#include<vector>
#include<string>
#include"Tuile.h"

class Dictionnaire{
    vector<Tuile> _lesTuiles;
    public:
    Dictionnaire( ifstream&);
    void afficher()const;
    bool recherche(const string & val, Tuile& t);
};

#endif // DICTIONNAIRE_H_INCLUDED

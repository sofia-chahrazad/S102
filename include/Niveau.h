#ifndef NIVEAU_H
#define NIVEAU_H
#include"Objet.h"
#include<vector>
#include"Image.h"
#include"Dictionnaire.h"
#include<string>
#include<fstream>



class Niveau
{

    vector<Objet> _lesObjets;
    int _bonus;
    public:
        Niveau( Image&,  Dictionnaire&,  ifstream& nom_fichier);
        void dessiner()const;
        void afficher()const;
        bool caseEstLibre(int ,int)const;
        int getBonus()const {return _bonus;};
        void testerBonusEtPrendre(int x , int y);
        int indiceObjet(int x,int y ,const string& prop)const;
        bool gagne()const{return _bonus==0;}

};

#endif // NIVEAU_H

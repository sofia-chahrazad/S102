#include "Niveau.h"
#include<fstream>
#include<string>
#include"Tuile.h"
#include"Objet.h"
using namespace std;

Niveau::Niveau( Image& img,  Dictionnaire& d,  ifstream& in)
{
    //istream nom_fichier;
    _bonus = 0;
    int nbLignes;
    in>>nbLignes;
    string tuileName;
    int cordx,cordy;
    for(int i = 1 ; i<=nbLignes;i++){
        in>>tuileName;
        in>>cordx;
        in>>cordy;
        Objet obj(img,tuileName,d,cordx,cordy);
        if(obj.getTuile().getPropriete()=="bonus"){
            _bonus++;
        }
        _lesObjets.push_back(obj);

    }
}
void Niveau::afficher()const{

    for(int i = 0 ; i<_lesObjets.size();i++){
        _lesObjets[i].afficher();
        cout<<endl;
    }

}
void Niveau::dessiner()const{

   for(int i = 0 ; i<_lesObjets.size();i++){
        if(_lesObjets[i].getTuile().getPropriete()!="cache"){
            _lesObjets[i].dessiner();
        }
    }
}
bool Niveau::caseEstLibre(int x,int y )const{
    return indiceObjet(x,y,"solide") ==-1;
}
void Niveau::testerBonusEtPrendre(int x,int y){
    int ind =indiceObjet(x,y,"bonus");
    if(ind > -1){
        _lesObjets[ind].cacher();
        _bonus--;
        cout<<endl<<"une piece a ete prise"<<endl;
    }
}


int Niveau::indiceObjet(int x,int y ,const string& prop)const{
    int res = -1;
    int i = 0;
    bool trouve=false;
    while(i<_lesObjets.size()&& !trouve){
        if(_lesObjets[i].getX()==x && _lesObjets[i].getY()==y){
            if(_lesObjets[i].getTuile().getPropriete()==prop) {
                res = i;
                trouve = true;
            }
        }
        i++;
    }
    return res;
}

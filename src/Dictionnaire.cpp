#include"Dictionnaire.h"
#include<iostream>
#include"Tuile.h"
#include<fstream>
#include<string>

using namespace std;
Dictionnaire::Dictionnaire(ifstream&in){

    int nbtuiles;
    int x,y;
    in>>nbtuiles;
    string name,prop;
    cout<<nbtuiles;
    for(int i = 0 ;i<nbtuiles;i++){
        in>>name>>x>>y>>prop;
        Tuile t(x,y,name,prop);
        _lesTuiles.push_back(t);
    }
}
void Dictionnaire::afficher()const{
    for(int i = 0 ; i<_lesTuiles.size();i++){
        _lesTuiles[i].afficher();
        cout<<endl;
    }
}
///binary search
bool Dictionnaire::recherche(const string & val, Tuile& t)const{
    int ind = -1, d= 0 ,f = _lesTuiles.size()-1 ,m ;
    bool tr = false;
    while(!tr && d<=f){
        m = (d+f)/2;
        tr = (val == _lesTuiles[m].getName());
        if(tr){
            ind = m ;
        }else if(val< _lesTuiles[m].getName() ){
            f = m-1;
        }else{
            d = m+1;
        }
    }
    if(tr)
        t = _lesTuiles[ind];
    return tr;
}

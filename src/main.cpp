#include <vector>
#include<exception>
#include "Moteur.h"
#include "Image.h"
#include <cstdlib>
#include <cstdlib>
#include <ctime>




class Blob{
    Image _img;
    int _posX;
    int _posY;
    bool _dirX;
    bool _dirY;
public:
    Blob();
    Blob(const Image& img,bool dirX  ,bool dirY ){
        _img = img;
        _dirX= dirX;
        _dirY = dirY;
        _posX=rand()%145;
        _posY = rand()%113;
    }
    void dessiner(){
        _img.dessiner(_posX,_posY);
    }
    void bouger(){
        if(_posY==112){
            _dirY = false;
        }if(_posY ==0){
            _dirY = true;
        }
        if(_posX==144){
            _dirX = false;
        }if(_posX==0){
            _dirX = true;
        }
        if(_dirY)_posY++;
        else _posY--;

        if(_dirX) _posX++;
        else _posX--;

    }


};

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
    // Initialisation du jeu
    Moteur moteur("Mon super jeu vidéo");

    // TODO: charger images, creer personnages, etc.
    srand(time(nullptr));

    Image fond;
    Image coffref;
    Image coffreo;
    bool etat_coffre = false;
    int x=1,y=1;
    bool dirY = true;
    bool dirX = true;
    vector<Blob> blobs;
    try
    {
        fond = Image(moteur, "assets/fond.png");
        coffref = Image(moteur,"assets/coffre_ferme.png");
        coffreo = Image(moteur,"assets/coffre_ouvert.png");
    }catch(exception e){
        cerr<<e.what();
    }
    Blob b1(coffref,true,true);

    bool quitter = false;

    // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
    // (en general, 60 fois par seconde)
    while (!quitter)
    {
        // I. Gestion des evenements
        Evenement evenement = moteur.evenementRecu();
        while (evenement != AUCUN)
        {
            switch (evenement)
            {
            // QUITTER = croix de la fenetre ou Echap
            case QUITTER_APPUYE:
                quitter = true;
                break;
            // TODO: gerer les autres evenements
            case ESPACE_APPUYE:
                etat_coffre = true;
                blobs.push_back(Blob(coffref,true,true));
                break;
            case ESPACE_RELACHE:
                etat_coffre = false;
                break;
            default:
                break;
            }

            evenement = moteur.evenementRecu();

        }

        // II. Mise à jour de l'état du jeu

        // TODO: faire bouger vos personnages, etc.

        // III. Generation de l'image à afficher

        moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir

        // TODO: afficher vos personnages, objets, etc.;
        fond.dessiner(0,0);
        if(etat_coffre){
            coffreo.dessiner(x,y);

        }else{
            coffref.dessiner(x,y);
        }
        for(int i = 0 ; i<blobs.size();i++){
            blobs[i].dessiner();
        }
        for(int i = 0 ; i<blobs.size();i++){
            blobs[i].bouger();
        }
        if(y==112){
            dirY = false;
        }if(y ==0){
            dirY = true;
        }
        if(x==144){
            dirX = false;
        }if(x==0){
            dirX = true;
        }
        if(dirY){
            y++;
        }else{
            y--;
        }
        if(dirX) x++;
        else x--;

        /*
          Affiche l'image en se cadencant sur la frequence de
          rafraichissement de l'ecran (donc va en general mettre le
          programme en pause jusqu'a ce que l'ecran soit rafraichi). En
          general, 60 images fois par seconde, mais ca peut dependre du
          materiel
        */
        moteur.finaliserRendu();
    }

    return 0;
}

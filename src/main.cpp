#include <vector>
#include<exception>
#include "Moteur.h"
#include "Image.h"
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Personnage.h"
#include "Avatar.h"
#include "Ennemi.h"
#include "Dictionnaire.h"
#include "Objet.h"
#include "Niveau.h"


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

    int direction_perssonage = 0  ;
    int position_animation = 0;
    Image fond;
    Image coffref;
    Image coffreo;
    Image toutpersons;
    Image lesObjects;
    Image gameOver;
    Image bravo;
    ifstream entree;
    Tuile t;
    entree.open("assets/dictionnaire.txt");
    Dictionnaire dictionnaire(entree);
    cout<<endl;
    dictionnaire.afficher();
    cout<<endl;
    dictionnaire.recherche("Troudfgs",t);
    cout<<endl;
    t.afficher();
    cout<<endl;
    ifstream niveau_fichier;
    niveau_fichier.open("assets/niveau.txt");


    //bool etat_coffre = false;
    //int x=1,y=1;
    //bool dirY = true;
    //bool dirX = true;
    //vector<Blob> blobs;

    fond = Image(moteur, "assets/fond.png");
    //coffref = Image(moteur,"assets/coffre_ferme.png");
    //coffreo = Image(moteur,"assets/coffre_ouvert.png");
    toutpersons =Image(moteur,"assets/personnages.png");
    lesObjects = Image(moteur,"assets/objets.png");
    gameOver = Image(moteur,"assets/gameover.png");
    bravo = Image(moteur,"assets/bravo.png");
    Niveau niveau1(lesObjects,dictionnaire,niveau_fichier);
    cout<<endl<<"the bonus in this level are === "<<niveau1.getBonus()<<endl;

    Blob b1(coffref,true,true);
    Avatar personnage_simple= Avatar(toutpersons,1,2,3,0,BAS);
    Ennemi ennemi1 = Ennemi(toutpersons,5,2,10,0,BAS);
    Ennemi ennemi2 = Ennemi(toutpersons,01,5,1,4,DROITE);




    bool quitter = false;

    // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
    // (en general, 60 fois par seconde)
    while (!quitter)
    {
        // I. Gestion des evenements
        Evenement evenement = moteur.evenementRecu();
        niveau1.testerBonusEtPrendre(personnage_simple.getX(),personnage_simple.getY());


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
                //etat_coffre = true;
                //blobs.push_back(Blob(coffref,true,true));
                break;
            case ESPACE_RELACHE:
                //etat_coffre = false;
                break;
            case DROITE_APPUYE:
                personnage_simple.allerDroite(niveau1);
                break;
            case GAUCHE_APPUYE:
                personnage_simple.allerGauche(niveau1);
                break;
            case HAUT_APPUYE:
                personnage_simple.allerHaut(niveau1);
                break;
            case BAS_APPUYE:
                personnage_simple.allerBas(niveau1);
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
        niveau1.dessiner();


        if(moteur.animationsAmettreAjour()){
            ennemi1.randDirection();
            ennemi2.randDirection();
            ennemi1.avancer(niveau1);
            ennemi2.avancer(niveau1);
            personnage_simple.mettreAjourAnimation();

        }

        ennemi1.dessiner();
        ennemi2.dessiner();
        personnage_simple.dessiner();



        if(personnage_simple.touche(ennemi1)||personnage_simple.touche(ennemi2)||niveau1.gagne()){
            moteur.attendre(1);
            moteur.initialiserRendu();
            if(niveau1.gagne()){

                bravo.dessiner(32,48);
            }else{
                gameOver.dessiner(32,48);
            }
            moteur.finaliserRendu();
            moteur.attendre(4);

            quitter = true;

        }

        //personnage_simple.dessiner(5,0);
        /*
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
        */

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

#ifndef AVATAR_H_INCLUDED
#define AVATAR_H_INCLUDED
#include"Personnage.h"
#include"Ennemi.h"
#include"Niveau.h"
class Avatar {
    Personnage _perso;
public:
        Avatar(Image img, int x, int y, int skin_x, int skin_y, Direction d = BAS);
        void dessiner();
        void allerDroite(Niveau n);
        void allerGauche(Niveau n);
        void allerHaut(Niveau n);
        void allerBas(Niveau n);
        void regarderDroite();
        void regarderGauche();
        void regarderHaut();
        void regarderBas();
        bool touche(const Ennemi& e)const;
        void mettreAjourAnimation();
        int getX()const{return _perso.getX();}
        int getY()const{return _perso.getY();}


};


#endif // AVATAR_H_INCLUDED

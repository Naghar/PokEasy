#ifndef P_RENCONTRE_H_INCLUDED
#define P_RENCONTRE_H_INCLUDED

    #include "p_espece.h"

    #define MAX_NIVEAU 100
    #define MIN_NIVEAU 1

    typedef struct _rencontre {
        unsigned int r_ID_espece;
        unsigned int r_niveau_min, r_niveau_max;
    } *Rencontre;

    typedef struct _chainon_rencontre {
        Rencontre cr_chainon;
        struct _chainon_rencontre* cr_suivant;
    } *ChainonRencontre;

    typedef struct _liste_rencontres {
        ChainonRencontre lr_premier;
        unsigned int taille_liste;
    } *ListeRencontres;

    Rencontre creerRencontre (int ID_espece, int niveau_min, int niveau_max);
    void initRencontre (Rencontre r, int ID_espece, int niveau_min, int niveau_max);
    void supprRencontre (Rencontre r);

    ChainonRencontre creerChainonRencontre (Rencontre chainon, ChainonRencontre suivant);
    void initChainonRencontre (ChainonRencontre cr, Rencontre chainon, ChainonRencontre suivant);
    void supprChainonRencontre (ChainonRencontre cr);

    ListeRencontres creerListeRencontres (ChainonRencontre premier, int taille);
    void initListeRencontres (ListeRencontres lr, ChainonRencontre premier, int taille);
    void supprListeRencontres (ListeRencontres lr);

    void ajoutRencontre (ListeRencontres* lr, Rencontre nouvelle_rencontre);

#endif

#ifndef P_ROUTE_H_INCLUDED
#define P_ROUTE_H_INCLUDED

    #include "p_rencontre.h"

    typedef struct _route {
        String r_nom;
        ListeRencontres r_rencontres;
    } *Route;

    Route creerRoute (String nom, ListeRencontres rencontres);
    void initRoute (Route r, String nom, ListeRencontres rencontres);
    void supprRoute (Route r);

    Route lireRencontres (String nom_route);

#endif

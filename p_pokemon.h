#ifndef P_POKEMON_H_INCLUDED
#define P_POKEMON_H_INCLUDED

    #include "p_route.h"

    typedef enum _genre { MALE = 0, FEMELLE = 1 } Genre;

    typedef struct _pokemon {
        String p_nom;
        Espece p_espece;
        Genre p_genre;
        int p_niveau;
        Stats p_stats_tot, p_stats_actu, p_IV, p_EV;
    } _pokemon, *Pokemon;

    Pokemon generePokemon (int ID_espece, int niveau);
    Pokemon rencontreAleatoire (String nom_route);

    _pokemon initPokemon (String nom, _espece e, Genre g, int niveau, _stats tot, _stats actu, _stats IV, _stats EV);
    Pokemon creerPokemon (_pokemon pokemon);
    void supprPokemon (Pokemon p);

    String serializePokemon (Pokemon p);
    int deserializePokemon (Pokemon *p, String s);

#endif

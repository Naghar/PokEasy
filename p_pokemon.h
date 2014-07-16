/******************** #HEADER **************************************************
 *	@name		p_pokemon.h
 *	@source		p_pokemon.c
 *	@desc		A Pokemon is a unique instance from a species
 *				The player uses a team of Pokemon to beat the game
 *
 *	@function	wildEncounter,
 *				randPokemon,
 *				initPokemon,
 *				newPokemon,
 *				delPokemon,
 *				serializePokemon,
 *				unserializePokemon
 *
 *	@global		None
 *
 *	@constant	None
 *
 *	@macro		None
 *
 *	@depend		p_road.h
 ******************************************************************************/

#ifndef P_POKEMON_H_INCLUDED
#define P_POKEMON_H_INCLUDED

	#include "p_road.h"

	typedef enum _genre { MALE = 0, FEMELLE = 1 } Genre;

	typedef struct _pokemon {
		String p_nom;
		Species p_species;
		Genre p_genre;
		int p_niveau;
		Stats p_stats_tot, p_stats_actu, p_IV, p_EV;
	} _pokemon, *Pokemon;

	Pokemon generePokemon (int ID_espece, int niveau);
	Pokemon rencontreAleatoire (String nom_route);

	_pokemon initPokemon (String nom, _espece e, Genre g, int niveau, _stats tot, _stats actu, _stats IV, _stats EV);
	Pokemon newPokemon (_pokemon pokemon);
	void delPokemon (Pokemon p);

	String serializePokemon (Pokemon p);
	int unserializePokemon (Pokemon *p, String s);

#endif

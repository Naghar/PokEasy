/******************** #HEADER **************************************************
 *	@name		p_species.h
 *	@source		p_species.c
 *	@desc		Pokemon from a same species share their base characteristics
 *				(e.g. every Charmander).
 *
 *	@function	loadSpecies,
 *				initSpecies,
 *				newSpecies,
 *				delSpecies,
 *				serializeSpecies,
 *				unserializeSpecies,
 *				getBaseHP,
 *				getBaseSpd,
 *				getBaseAtk,
 *				getBaseDef,
 *				getBaseSpA,
 *				getBaseSpD
 *
 *	@global		species_list,
 *				species_number
 *
 *	@constant	MIN_SPECIES_ID
 *
 *	@macro		None
 *
 *	@depend		p_stats.h
 ******************************************************************************/

#ifndef p_species_H_INCLUDED
#define p_species_H_INCLUDED

	#include "p_stats.h"

	#define MIN_ID_ESPECE 0

	typedef struct _espece {
		int e_ID;
		String e_nom;
		Stats e_stats_base;
	} _espece, *Species;

	extern Species* species_list;
	extern int species_number;

	void* loadSpecies ();

	_espece initSpecies (int ID, String nom, _stats stats_base);
	Species newSpecies (_espece espece);
	void delSpecies (Species e);

	String serializeSpecies (Species e);
	int unserializeSpecies (Species *e, String str);

	unsigned int getHPBase (Species e);
	unsigned int getSpdBase (Species e);
	unsigned int getAtkBase (Species e);
	unsigned int getDefBase (Species e);
	unsigned int getASpBase (Species e);
	unsigned int getDSpBase (Species e);

#endif

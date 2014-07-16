/******************** #HEADER **************************************************
 *	@name		p_encounter.h
 *	@source		p_encounter.c
 *	@desc		Encounters are random events happening while exploring a road.
 *
 *	@function	initEncounter,
 *				newEncounter,
 *				delEncounter,
 *				serializeEncounter,
 *				unserializeEncounter
 *
 *	@constant	MIN_LEVEL,
 *				MAX_LEVEL
 *
 *	@global		None
 *
 *	@macro		None
 *
 *	@depend		p_species.h
 ******************************************************************************/

#ifndef p_encounter_H_INCLUDED
#define p_encounter_H_INCLUDED

	#include "p_species.h"

	#define MAX_NIVEAU 100
	#define MIN_NIVEAU 1

	typedef struct _rencontre {
		int r_ID_espece;
		int r_niveau_min, r_niveau_max;
	} _rencontre, *Encounter;

	typedef struct _chainon_rencontre {
		Encounter cr_chainon;
		struct _chainon_rencontre *cr_suivant;
	} _chainon_rencontre, *ChainonEncounter;

	_rencontre initEncounter (int ID_espece, int niveau_min, int niveau_max);
	Encounter newEncounter (_rencontre rencontre);
	void delEncounter (Encounter r);
	
	String serializeEncounter (Encounter r);
	int unserializeEncounter (Encounter *r, String str);

	void ajoutEncounter (ChainonEncounter *premier_chainon, _rencontre nouvelle_rencontre);
	void delChainonEncounter (ChainonEncounter chainon);
	ChainonEncounter copieChainonEncounter (ChainonEncounter chainon);

#endif

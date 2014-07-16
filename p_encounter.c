/******************** #SOURCE **************************************************
 *	@name		p_encounter.c
 *	@header		p_encounter.h
 *	@desc		Encounters are random events happening while exploring a road.
 *
 *	@function	$header
 *
 *	@global		$header
 *
 *	@depend		None
 *
 *	@stream		None
 ******************************************************************************/

#include "p_encounter.h"

_rencontre initEncounter (int ID_espece, int niveau_min, int niveau_max)
{
	_rencontre r;
	
	r.r_ID_espece = ID_espece;
	r.r_niveau_min = niveau_min;
	r.r_niveau_max = niveau_max;
	
	return r;
}

Encounter newEncounter (_rencontre rencontre)
{
	Encounter r = NULL;
	r = malloc(sizeof(*r));
	CHECK_NULL(r)

	if (rencontre.r_ID_espece < 0 || rencontre.r_ID_espece > species_number) rencontre.r_ID_espece = 0;
	if (rencontre.r_niveau_min < MIN_NIVEAU || rencontre.r_niveau_min > MAX_NIVEAU) rencontre.r_niveau_min = MIN_NIVEAU;
	if (rencontre.r_niveau_max < rencontre.r_niveau_min || rencontre.r_niveau_max > MAX_NIVEAU) rencontre.r_niveau_max = MAX_NIVEAU;

	*r = rencontre;

	return r;
}

void delEncounter (Encounter r)
{
	free(r);
	r = 0;
}

String serializeEncounter (Encounter r)
{
	String str = NULL;

	CHECK_NULL(r)printf("%d %d %d", r->r_ID_espece, r->r_niveau_min, r->r_niveau_max);
	str = sprintfSized("%d(%d@%d)", r->r_ID_espece, r->r_niveau_min, r->r_niveau_max);
	CHECK_NULL(str)

	return str;
}

int unserializeEncounter (Encounter *r, String str)
{
	_rencontre rencontre;
	int size = 0;

	CHECK_NULL(str)
	sscanf(str, "%d(%d@%d)%n", &rencontre.r_ID_espece, &rencontre.r_niveau_min, &rencontre.r_niveau_max, &size);

	if (size > 0)
		*r = newEncounter(rencontre);

	return size;
}

void ajoutEncounter (ChainonEncounter *premier_chainon, _rencontre nouvelle_rencontre)
{
	ChainonEncounter cr = NULL;
	cr = malloc(sizeof(*cr));
	CHECK_NULL(cr)

	cr->cr_chainon = newEncounter(nouvelle_rencontre);
	cr->cr_suivant = *premier_chainon;
	*premier_chainon = cr;
}

void delChainonEncounter (ChainonEncounter chainon)
{
	CHECK_NULL(chainon)

	if (chainon->cr_suivant) delChainonEncounter (chainon->cr_suivant);
	
	free(chainon);
	chainon = NULL_POINTER;
}

ChainonEncounter copieChainonEncounter (ChainonEncounter chainon)
{
	ChainonEncounter copie = NULL;
	
	while (chainon)
	{
		ajoutEncounter(&copie, *(chainon->cr_chainon));
		chainon = chainon->cr_suivant;
	}
	
	return copie;
}

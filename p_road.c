/******************** #SOURCE **************************************************
 *	@name		p_road.c
 *	@header		p_road.h
 *	@desc		A road can connect to cities or other roads.
 *				The player can fight NPC, encounter wild pokemon or find items.
 *
 *	@function	$header
 *
 *	@global		$header
 *
 *	@depend		None
 *
 *	@stream		data_encounters.dat
 ******************************************************************************/

#include "p_road.h"

Road *roads_list = NULL;
int roads_number = 0;

void* loadRoads ()
{
	FILE* f_rencontres = NULL;
	String line = NULL;

	f_rencontres = fopen("data_encounters.dat", "r");

	line = fgetsSizing(f_rencontres);
	free(line);
	line = fgetsSizing(f_rencontres);
	free(line);

	while ((line = fgetsSizing(f_rencontres)) != NULL)
	{
		roads_list = realloc(roads_list, (roads_number + 1) * sizeof(*roads_list));
		unserializeRoad(&roads_list[roads_number], line);
		roads_number++;

		free(line);
	}

	fclose(f_rencontres);
	return NULL;
}

_route initRoad (int ID, String nom, ChainonEncounter premiere_rencontre)
{
	_route r;

	r.r_ID = ID;
	r.r_nom = newString(nom);
	r.r_premiere_rencontre = copieChainonEncounter(premiere_rencontre);

	return r;
}

Road newRoad (_route route)
{
	Road r = NULL;
	r = (Road) malloc(sizeof(*r));
	CHECK_NULL(r)

	if (route.r_ID < MIN_ID_ROUTE || route.r_ID > roads_number) route.r_ID = MIN_ID_ROUTE;
	if (route.r_nom == NULL) route.r_nom = "Undefined";

	*r = route;

	return r;
}

void delRoad (Road r)
{
	CHECK_NULL(r)
	delString(r->r_nom);
	delChainonEncounter(r->r_premiere_rencontre);
	free(r);
	r = NULL_POINTER;
}

String serializeRoad (Road r)
{
	String str = NULL, str_rencontre = NULL, str_liste_rencontres = NULL;
	ChainonEncounter chainon = r->r_premiere_rencontre;

	CHECK_NULL(r)

	str_liste_rencontres = serializeEncounter(chainon->cr_chainon);

	chainon = chainon->cr_suivant;

	while (chainon)
	{
		str_rencontre = serializeEncounter(chainon->cr_chainon);
		str_liste_rencontres = realloc(str_liste_rencontres, (strlen(str_rencontre) + strlen(str_liste_rencontres) + 1)
															* sizeof(*str_liste_rencontres));
		strcat(str_liste_rencontres, str_rencontre);
		free(str_rencontre);

		chainon = chainon->cr_suivant;
	}

	str = sprintfSized("%d|%s|%s", r->r_ID, str_liste_rencontres, r->r_nom);
	CHECK_NULL(str)

	return str;
}

int unserializeRoad (Road *r, String str)
{
	_route route;
	Encounter rencontre = NULL;
	int buf_size, size = 0;

	route.r_premiere_rencontre = NULL;
	CHECK_NULL(str)

	sscanf(str + size, "%d|%n", &route.r_ID, &buf_size);
	size += buf_size;

	while ((buf_size = unserializeEncounter(&rencontre, str + size)) > 0)
	{
		size += (buf_size + 1); /* +1 pour le ";" separateur */
		ajoutEncounter(&(route.r_premiere_rencontre), *rencontre);
		free(rencontre);
	}

	route.r_nom = newString(str + size);

	*r = newRoad(route);

	return size;
}

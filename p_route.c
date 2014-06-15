#include "p_route.h"

Route *liste_routes = NULL;
int nbr_routes = 0;

void startRoutes ()
{
	FILE* f_rencontres = NULL;
	String line = NULL;

	f_rencontres = fopen("rencontres.dat", "r");

	while ((line = fgetsSizing(f_rencontres)) != NULL)
	{
		liste_routes = realloc(liste_routes, (nbr_routes + 1) * sizeof(*liste_routes));
		deserializeRoute(&liste_routes[nbr_routes], line);
		nbr_routes++;

		free(line);
	}

	fclose(f_rencontres);
}

_route initRoute (int ID, String nom, ChainonRencontre premiere_rencontre)
{
	_route r;

	r.r_ID = ID;
	r.r_nom = creerString(nom);
	r.r_premiere_rencontre = copieChainonRencontre(premiere_rencontre);

	return r;
}

Route creerRoute (_route route)
{
	Route r = NULL;
	r = (Route) malloc(sizeof(*r));
	CHECK_NULL(r)

	if (route.r_ID < MIN_ID_ROUTE || route.r_ID > nbr_routes) route.r_ID = MIN_ID_ROUTE;
	if (route.r_nom == NULL) route.r_nom = "Undefined";

	*r = route;

	return r;
}

void supprRoute (Route r)
{
	CHECK_NULL(r)
	supprString(r->r_nom);
	supprChainonRencontre(r->r_premiere_rencontre);
	free(r);
	r = NULL_POINTER;
}

String serializeRoute (Route r)
{
	String str = NULL, str_rencontre = NULL, str_liste_rencontres = NULL;
	ChainonRencontre chainon = r->r_premiere_rencontre;

	CHECK_NULL(r)
	
	str_liste_rencontres = serializeRencontre(chainon->cr_chainon);
	chainon = chainon->cr_suivant;

	while (chainon)
	{
		str_rencontre = serializeRencontre(chainon->cr_chainon);
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

int deserializeRoute (Route *r, String str)
{
	_route route;
	Rencontre rencontre = NULL;
	int buf_size, size = 0;

	CHECK_NULL(str)

	sscanf(str + size, "%d|%n", &route.r_ID, &buf_size);
	size += buf_size;

	while ((buf_size = deserializeRencontre(&rencontre, str + size)) > 0)
	{
		size += (buf_size + 1); /* +1 pour le ";" separateur */
		ajoutRencontre(&(route.r_premiere_rencontre), *rencontre);
		free(rencontre);
	}

	route.r_nom = creerString(str + size);

	*r = creerRoute(route);

	return size;
}

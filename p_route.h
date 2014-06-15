#ifndef P_ROUTE_H_INCLUDED
#define P_ROUTE_H_INCLUDED

	#include "p_rencontre.h"

	#define MIN_ID_ROUTE 0

	typedef struct _route {
		int r_ID;
		String r_nom;
		ChainonRencontre r_premiere_rencontre;
	} _route, *Route;
	
	extern Route* liste_routes;
	extern int nbr_routes;

	void startRoutes ();

	_route initRoute (int ID, String nom, ChainonRencontre premiere_rencontre);
	Route creerRoute (_route route);
	void supprRoute (Route r);

	String serializeRoute (Route r);
	int deserializeRoute (Route *r, String str);

#endif

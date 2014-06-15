#ifndef P_RENCONTRE_H_INCLUDED
#define P_RENCONTRE_H_INCLUDED

	#include "p_espece.h"

	#define MAX_NIVEAU 100
	#define MIN_NIVEAU 1

	typedef struct _rencontre {
		int r_ID_espece;
		int r_niveau_min, r_niveau_max;
	} _rencontre, *Rencontre;

	typedef struct _chainon_rencontre {
		Rencontre cr_chainon;
		struct _chainon_rencontre *cr_suivant;
	} _chainon_rencontre, *ChainonRencontre;

	_rencontre initRencontre (int ID_espece, int niveau_min, int niveau_max);
	Rencontre creerRencontre (_rencontre rencontre);
	void supprRencontre (Rencontre r);
	
	String serializeRencontre (Rencontre r);
	int deserializeRencontre (Rencontre *r, String str);

	void ajoutRencontre (ChainonRencontre *premier_chainon, _rencontre nouvelle_rencontre);
	void supprChainonRencontre (ChainonRencontre chainon);
	ChainonRencontre copieChainonRencontre (ChainonRencontre chainon);

#endif

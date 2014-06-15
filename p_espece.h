#ifndef P_ESPECE_H_INCLUDED
#define P_ESPECE_H_INCLUDED

	#include "p_stats.h"

	#define MIN_ID_ESPECE 0

	typedef struct _espece {
		int e_ID;
		String e_nom;
		Stats e_stats_base;
	} _espece, *Espece;

	extern Espece* liste_especes;
	extern int nbr_especes;

	void startEspeces ();

	_espece initEspece (int ID, String nom, _stats stats_base);
	Espece creerEspece (_espece espece);
	void supprEspece (Espece e);

	String serializeEspece (Espece e);
	int deserializeEspece (Espece *e, String str);

	unsigned int getVieBase (Espece e);
	unsigned int getVitBase (Espece e);
	unsigned int getAttBase (Espece e);
	unsigned int getDefBase (Espece e);
	unsigned int getASpBase (Espece e);
	unsigned int getDSpBase (Espece e);

#endif

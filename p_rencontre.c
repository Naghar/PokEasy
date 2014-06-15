#include "p_rencontre.h"

_rencontre initRencontre (int ID_espece, int niveau_min, int niveau_max)
{
	_rencontre r;
	
	r.r_ID_espece = ID_espece;
	r.r_niveau_min = niveau_min;
	r.r_niveau_max = niveau_max;
	
	return r;
}

Rencontre creerRencontre (_rencontre rencontre)
{
	Rencontre r = NULL;
	r = malloc(sizeof(*r));
	CHECK_NULL(r)

	if (rencontre.r_ID_espece < 0 || rencontre.r_ID_espece > nbr_especes) rencontre.r_ID_espece = 0;
	if (rencontre.r_niveau_min < MIN_NIVEAU || rencontre.r_niveau_min > MAX_NIVEAU) rencontre.r_niveau_min = MIN_NIVEAU;
	if (rencontre.r_niveau_max < rencontre.r_niveau_min || rencontre.r_niveau_max > MAX_NIVEAU) rencontre.r_niveau_max = MAX_NIVEAU;

	*r = rencontre;

	return r;
}

void supprRencontre (Rencontre r)
{
	free(r);
	r = 0;
}

String serializeRencontre (Rencontre r)
{
	String str = NULL;

	CHECK_NULL(r)
	str = sprintfSized("%d(%d@%d)", r->r_ID_espece, r->r_niveau_min, r->r_niveau_max);
	CHECK_NULL(str)

	return str;
}

int deserializeRencontre (Rencontre *r, String str)
{
	_rencontre rencontre;
	int size = 0;

	CHECK_NULL(str)
	sscanf(str, "%d(%d@%d)%n", &rencontre.r_ID_espece, &rencontre.r_niveau_min, &rencontre.r_niveau_max, &size);
	*r = creerRencontre(rencontre);

	return size;
}

void ajoutRencontre (ChainonRencontre *premier_chainon, _rencontre nouvelle_rencontre)
{
	ChainonRencontre cr = NULL;
	cr = malloc(sizeof(*cr));
	CHECK_NULL(cr)

	cr->cr_chainon = creerRencontre(nouvelle_rencontre);
	cr->cr_suivant = *premier_chainon;
}

void supprChainonRencontre (ChainonRencontre chainon)
{
	CHECK_NULL(chainon)

	if (chainon->cr_suivant) supprChainonRencontre (chainon->cr_suivant);
	
	free(chainon);
	chainon = NULL_POINTER;
}

ChainonRencontre copieChainonRencontre (ChainonRencontre chainon)
{
	ChainonRencontre copie = NULL;
	
	while (chainon)
	{
		ajoutRencontre(&copie, *(chainon->cr_chainon));
		chainon = chainon->cr_suivant;
	}
	
	return copie;
}

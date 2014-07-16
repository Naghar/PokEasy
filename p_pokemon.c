/******************** #SOURCE **************************************************
 *	@name		p_pokemon.c
 *	@header		p_pokemon.h
 *	@desc		A Pokemon is a unique instance from a species.
 *				The player uses a team of Pokemon to beat the game.
 *
 *	@function	$header
 *
 *	@global		$header
 *
 *	@depend		None
 *
 *	@stream		None
 ******************************************************************************/

#include "p_pokemon.h"
/*
Pokemon rencontreAleatoire(String nom_route)
{
	Pokemon p = NULL;
	Road r = NULL;
	ListeEncounters lr_read = NULL;
	unsigned int alea, i = 0, niveau_alea, niveau_min, niveau_max, ID_alea;

	r = lireEncounters(nom_route);
	CHECK_NULL_ERROR(r)

	alea = rand() % r->r_rencontres->taille_liste;

	lr_read = r->r_rencontres;
	CHECK_NULL_ERROR(lr_read)

	while (i < alea && lr_read != NULL)
	{
		lr_read->lr_premier = lr_read->lr_premier->cr_suivant;
		i++;
	}

	niveau_min = lr_read->lr_premier->cr_chainon->r_niveau_min;
	niveau_max = lr_read->lr_premier->cr_chainon->r_niveau_max;
	niveau_alea = niveau_min + rand() % (niveau_max - niveau_min);
	ID_alea = lr_read->lr_premier->cr_chainon->r_ID_espece;

	delRoad(r);
printf("=> %d\n", ID_alea);
	p = generePokemon(ID_alea, niveau_alea);
	return p;
}

Pokemon generePokemon (int ID_espece, int niveau)
{
	Pokemon p = NULL;
	Genre g;
	struct _espece e;
	struct _stats EV, IV, tot, actu;

	int c_HP, c_spd, c_atk, c_def, c_SpA, c_SpD;
	float stat_multiplier;

	e = lireCaracteristiques(ID_espece);
	g = rand() % 2;

	EV = newStats(0, 0, 0, 0, 0, 0);

	for (i = 0; i < 6; i++)
		r_IV[i] = 1 + rand() % 30;
	IV = newStats(r_IV[0], r_IV[1], r_IV[2], r_IV[3], r_IV[4], r_IV[5]);

	stat_multiplier = (float)niveau / MAX_NIVEAU;

	c_HP = r_IV[0] + getHPBase(e) * stat_multiplier;
	c_spd = r_IV[1] + getSpdBase(e) * stat_multiplier;
	c_atk = r_IV[2] + getAtkBase(e) * stat_multiplier;
	c_def = r_IV[3] + getDefBase(e) * stat_multiplier;
	c_SpA = r_IV[4] + getASpBase(e) * stat_multiplier;
	c_SpD = r_IV[5] + getDSpBase(e) * stat_multiplier;

	tot = newStats(c_HP, c_spd, c_atk, c_def, c_SpA, c_SpD);
	actu = newStats(c_HP, c_spd, c_atk, c_def, c_SpA, c_SpD);

	p = newPokemon(e->e_nom, e, g, niveau, tot, actu, IV, EV);

	delSpecies(e);
	delStats(EV);
	delStats(IV);
	delStats(tot);
	delStats(actu);

	return p;
}

_pokemon initPokemon (String nom, _espece e, Genre g, int niveau, _stats tot, _stats actu, _stats IV, _stats EV)
{
	_pokemon p;

	p.p_nom = newString(nom);
	p.p_species = newSpecies(e);
	p.p_genre = g;
	p.p_niveau = niveau;
	p.p_stats_tot = newStats(tot);
	p.p_stats_actu = newStats(actu);
	p.p_IV = newStats(IV);
	p.p_EV = newStats(EV);

	return p;
}

Pokemon newPokemon (_pokemon pokemon)
{
	Pokemon p = NULL;
	p = malloc(sizeof(*p));
	CHECK_NULL(p)

	if (pokemon.p_niveau < 0 || pokemon.p_niveau > MAX_NIVEAU) pokemon.p_niveau = MIN_NIVEAU;
	if (pokemon.p_nom == NULL) pokemon.p_nom = "Undefined";

	*p = pokemon;

	return p;
}

void delPokemon (Pokemon p)
{
	delString(p->p_nom);
	delSpecies(p->p_species);
	delStats(p->p_stats_tot);
	delStats(p->p_stats_actu);
	delStats(p->p_IV);
	delStats(p->p_EV);
	free(p);
	p = 0;
}

String serializePokemon (Pokemon p)
{
	String str = NULL, str_s_tot = NULL, str_s_actu = NULL, str_s_IV = NULL, str_s_EV = NULL;

	CHECK_NULL(p)
	str_s_tot = serializeStats(p->p_stats_tot);
	str_s_actu = serializeStats(p->p_stats_actu);
	str_s_IV = serializeStats(p->p_IV);
	str_s_EV = serializeStats(p->p_EV);

	str = sprintfSized("%d [%s] %s", e->e_ID, str_stats, e->e_nom);
	free(str_stats);
	CHECK_NULL(str)

	return str;
}

int unserializePokemon (Pokemon *p, String s)
{
	_espece espece;
	int buf_size, size = 0;

	CHECK_NULL(str)
	sscanf(str + size, "%d [%n", &espece.e_ID, &buf_size);
	size += buf_size;
	buf_size = unserializeStats(&(espece.e_stats_base), str + size);
	size += buf_size;
	sscanf(str + size, "] %n", &buf_size);
	size += buf_size;
	espece.e_nom = newString(str + size);
	*e = newSpecies(espece);

	return size;
}
*/

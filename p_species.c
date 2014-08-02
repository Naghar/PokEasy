/******************** #SOURCE **************************************************
 *	@name		p_species.c
 *	@header		p_species.h
 *	@desc		Pokemon from a same species share their base characteristics
 *				(e.g. every Charmander).
 *
 *	@function	$header
 *
 *	@global		$header
 *
 *	@depend		None
 *
 *	@stream		data_species.dat
 ******************************************************************************/

#include "p_species.h"

Species *species_list = NULL;
int species_number = 0;

void* loadSpecies ()
{
	FILE* f_stats_especes = NULL;
	String line = NULL;

	f_stats_especes = fopen("data_species.dat", "r");

	line = fgetsSizing(f_stats_especes);
	free(line);
	line = fgetsSizing(f_stats_especes);
	free(line);

	while ((line = fgetsSizing(f_stats_especes)) != NULL)
	{
		species_list = realloc(species_list, (species_number + 1) * sizeof(*species_list));
		unserializeSpecies(&species_list[species_number], line);
		species_number++;

		free(line);
	}

	fclose(f_stats_especes);
	return NULL;
}

_espece initSpecies (int ID, String nom, _stats stats_base)
{
	_espece e;

	e.e_ID = ID;
	e.e_nom = newString(nom);
	e.e_stats_base = newStats(stats_base);

	return e;
}

Species newSpecies (_espece espece)
{
	Species e = NULL;
	e = malloc(sizeof(*e));
	CHECK_NULL(e)

	if (espece.e_ID < MIN_ID_ESPECE || espece.e_ID > species_number) espece.e_ID = MIN_ID_ESPECE;
	if (espece.e_nom == NULL) espece.e_nom = "Undefined";
	if (espece.e_stats_base == NULL) espece.e_stats_base = newStats(initStats(0, 0, 0, 0, 0, 0));

	*e = espece;

	return e;
}

void delSpecies (Species e)
{
	CHECK_NULL(e)
	delString(e->e_nom);
	delStats(e->e_stats_base);
	free(e);
	e = NULL_POINTER;
}

String serializeSpecies (Species e)
{
	String str = NULL, str_stats = NULL;

	CHECK_NULL(e)
	str_stats = serializeStats(e->e_stats_base);
	str = sprintfSized("%d|[%s]|%s", e->e_ID, str_stats, e->e_nom);
	free(str_stats);
	CHECK_NULL(str)

	return str;
}

int unserializeSpecies (Species *e, String str)
{
	_espece espece;
	int buf_size, size = 0;

	CHECK_NULL(str)

	sscanf(str + size, "%d|[%n", &espece.e_ID, &buf_size);
	size += buf_size;
	buf_size = unserializeStats(&(espece.e_stats_base), str + size);
	size += buf_size;
	sscanf(str + size, "]|%n", &buf_size);
	size += buf_size;
	espece.e_nom = newString(str + size);

	*e = newSpecies(espece);

	return size;
}

unsigned int getHPBase (Species e)
{
	CHECK_NULL(e)
	CHECK_NULL(e->e_stats_base)
	return e->e_stats_base->s_HP;
}

unsigned int getSpdBase (Species e)
{
	CHECK_NULL(e)
	CHECK_NULL(e->e_stats_base)
	return e->e_stats_base->s_spd;
}

unsigned int getAtkBase (Species e)
{
	CHECK_NULL(e)
	CHECK_NULL(e->e_stats_base)
	return e->e_stats_base->s_atk;
}

unsigned int getDefBase (Species e)
{
	CHECK_NULL(e)
	CHECK_NULL(e->e_stats_base)
	return e->e_stats_base->s_def;
}

unsigned int getASpBase (Species e)
{
	CHECK_NULL(e)
	CHECK_NULL(e->e_stats_base)
	return e->e_stats_base->s_SpA;
}

unsigned int getDSpBase (Species e)
{
	CHECK_NULL(e)
	CHECK_NULL(e->e_stats_base)
	return e->e_stats_base->s_SpD;
}

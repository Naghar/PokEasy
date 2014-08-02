/******************** #APPLICATION *********************************************
 *	@name	PokEasy                                                            *
 *                                                                             *
 *	@link	https://github.com/Naghar/PokEasy                                  *
 *                                                                             *
 *	@author	Naghar (Rémi Godbille),                                            *
 *			VaubanParty (Yassine Badache)                                      *
 *                                                                             *
 *	@desc	Command-line game based on the main Pokemon game series.           *
 ******************************************************************************/

/******************** #SOURCE **************************************************
 *	@name		main.c
 *	@header		None
 *
 *	@desc		Loads the required data, then launches the game.
 *
 *	@function	main
 *
 *	@depend		!time.h,
 *				p_road.h
 *
 *	@stream		None
 ******************************************************************************/

#include <time.h>
#include "p_road.h"

int main()
{
	int i = 0, j = 0;
	pthread_t t_species, t_roads;

	pthread_create (&t_species, NULL, loadSpecies, NULL);
	pthread_create (&t_roads, NULL, loadRoads, NULL);

	pthread_join (t_species, NULL);

	while (i < species_number)
	{
		printf("%d : %s\n", i, serializeSpecies(species_list[i]));
		i++;
	}

	pthread_join (t_roads, NULL);

	while (j < roads_number)
	{
		printf("%d : %s\n", j, serializeRoad(roads_list[j]));
		j++;
	}

	return EXIT_SUCCESS;
}

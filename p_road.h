/******************** #HEADER **************************************************
 *	@name		p_road.h
 *	@source		p_road.c
 *	@desc		A road can connect to cities or other roads.
 *				The player can fight NPC, encounter wild pokemon or find items.
 *
 *	@function	loadRoads,
 *				initRoad,
 *				newRoad,
 *				delRoad,
 *				serializeRoad,
 *				unserializeRoad
 *
 *	@global		roads_list,
 *				roads_number
 *
 *	@constant	MIN_ROAD_ID
 *
 *	@macro		None
 *
 *	@depend		p_encounter.h
 ******************************************************************************/

#ifndef p_road_H_INCLUDED
#define p_road_H_INCLUDED

	#include "p_encounter.h"

	#define MIN_ID_ROUTE 0

	typedef struct _route {
		int r_ID;
		String r_nom;
		ChainonEncounter r_premiere_rencontre;
	} _route, *Road;
	
	extern Road* roads_list;
	extern int roads_number;

	void loadRoads ();

	_route initRoad (int ID, String nom, ChainonEncounter premiere_rencontre);
	Road newRoad (_route route);
	void delRoad (Road r);

	String serializeRoad (Road r);
	int unserializeRoad (Road *r, String str);

#endif

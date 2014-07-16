/******************** #HEADER **************************************************
 *	@name		p_stats.h
 *	@source		p_stats.c
 *	@desc		There are six main stats.
 *				Health (HP), Speed (Spd), Atkack (Atk), Defense (Def), 
 *				Special Atkack (SpA), Special Defense (SpD).
 *
 *	@function	initStats,
 *				newStats,
 *				delStats,
 *				serializeStats,
 *				unserializeStats
 *
 *	@constant	MIN_BASE_STAT,
 *				MAX_BASE_STAT,
 *				MAX_BASE_HP
 *
 *	@global		None
 *
 *	@macro		None
 *
 *	@depend		types.h
 ******************************************************************************/

#ifndef P_STATS_H_INCLUDED
#define P_STATS_H_INCLUDED

	#include "types.h"

	#define MIN_STAT_BASE 1
	#define MAX_HP_BASE 300
	#define MAX_STAT_BASE 200

	typedef struct _stats {
		int s_HP, s_spd, s_atk, s_def, s_SpA, s_SpD;
	} _stats, *Stats;


	_stats initStats (int HP, int spd, int atk, int def, int SpA, int SpD);
	Stats newStats (_stats stats);
	void delStats (Stats s);

	String serializeStats (Stats s);
	int unserializeStats (Stats *s, String str);

#endif

/******************** #SOURCE **************************************************
 *	@name		p_stats.c
 *	@header		p_stats.h
 *	@desc		There are six main stats.
 *				Health (HP), Speed (Spd), Atkack (Atk), Defense (Def), 
 *				Special Atkack (SpA), Special Defense (SpD).
 *
 *	@function	$header
 *
 *	@global		$header
 *
 *	@depend		None
 *
 *	@stream		None
 ******************************************************************************/

#include "p_stats.h"

_stats initStats (int HP, int spd, int atk, int def, int SpA, int SpD)
{
	_stats s;

	s.s_HP = HP;
	s.s_spd = spd;
	s.s_atk = atk;
	s.s_def = def;
	s.s_SpA = SpA;
	s.s_SpD = SpD;

	return s;
}

Stats newStats (_stats stats)
{
	Stats s = NULL;
	s = malloc(sizeof(*s));
	CHECK_NULL(s)

	if (stats.s_HP < 0 || stats.s_HP > MAX_HP_BASE) stats.s_HP = MIN_STAT_BASE;
	if (stats.s_spd < 0 || stats.s_spd > MAX_STAT_BASE) stats.s_spd = MIN_STAT_BASE;
	if (stats.s_atk < 0 || stats.s_atk > MAX_STAT_BASE) stats.s_atk = MIN_STAT_BASE;
	if (stats.s_def < 0 || stats.s_def > MAX_STAT_BASE) stats.s_def = MIN_STAT_BASE;
	if (stats.s_SpA < 0 || stats.s_SpA > MAX_STAT_BASE) stats.s_SpA = MIN_STAT_BASE;
	if (stats.s_SpD < 0 || stats.s_SpD > MAX_STAT_BASE) stats.s_SpD = MIN_STAT_BASE;

	*s = stats;

	return s;
}

void delStats (Stats s)
{
	CHECK_NULL(s)
	free(s);
	s = NULL_POINTER;
}

String serializeStats (Stats s)
{
	String str = NULL;

	CHECK_NULL(s)
	str = sprintfSized("%d;%d;%d;%d;%d;%d", s->s_HP, s->s_spd, s->s_atk, s->s_def, s->s_SpA, s->s_SpD);
	CHECK_NULL(str)

	return str;
}

int unserializeStats (Stats *s, String str)
{
	_stats stats;
	int size = 0;

	CHECK_NULL(str)
	sscanf(str, "%d;%d;%d;%d;%d;%d%n", &stats.s_HP, &stats.s_spd, &stats.s_atk, &stats.s_def, &stats.s_SpA, &stats.s_SpD, &size);
	*s = newStats(stats);
	CHECK_NULL(*s)

	return size;
}

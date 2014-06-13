#include "p_stats.h"

_stats initStats (int vie, int vit, int att, int def, int aSp, int dSp)
{
    _stats s;

    s.s_vie = vie;
    s.s_vit = vit;
    s.s_att = att;
    s.s_def = def;
    s.s_aSp = aSp;
    s.s_dSp = dSp;

    return s;
}

Stats creerStats (_stats stats)
{
    Stats s = NULL;
    s = malloc(sizeof(*s));
    CHECK_NULL(s)

    if (stats.s_vie < 0 || stats.s_vie > MAX_VIE_BASE) stats.s_vie = MIN_STAT_BASE;
    if (stats.s_vit < 0 || stats.s_vit > MAX_STAT_BASE) stats.s_vit = MIN_STAT_BASE;
    if (stats.s_att < 0 || stats.s_att > MAX_STAT_BASE) stats.s_att = MIN_STAT_BASE;
    if (stats.s_def < 0 || stats.s_def > MAX_STAT_BASE) stats.s_def = MIN_STAT_BASE;
    if (stats.s_aSp < 0 || stats.s_aSp > MAX_STAT_BASE) stats.s_aSp = MIN_STAT_BASE;
    if (stats.s_dSp < 0 || stats.s_dSp > MAX_STAT_BASE) stats.s_dSp = MIN_STAT_BASE;

    *s = stats;

    return s;
}

void supprStats (Stats s)
{
    CHECK_NULL(s)
    s->s_vie = 0;
    s->s_vit = 0;
    s->s_att = 0;
    s->s_def = 0;
    s->s_aSp = 0;
    s->s_dSp = 0;

    free(s);
    s = 0;
}

String serializeStats (Stats s)
{
    String str = NULL;

    CHECK_NULL(s)
    str = sprintfSized("%d %d %d %d %d %d", s->s_vie, s->s_vit, s->s_att, s->s_def, s->s_aSp, s->s_dSp);
    CHECK_NULL(str)

    return str;
}

int deserializeStats (Stats *s, String str)
{
    _stats stats;
    int size;

    CHECK_NULL(str)
    sscanf(str, "%d %d %d %d %d %d%n", &stats.s_vie, &stats.s_vit, &stats.s_att, &stats.s_def, &stats.s_aSp, &stats.s_dSp, &size);
    *s = creerStats(stats);
    CHECK_NULL(*s)

    return size;
}

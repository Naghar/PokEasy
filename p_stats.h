#ifndef P_STATS_H_INCLUDED
#define P_STATS_H_INCLUDED

    #include "types.h"

    #define MAX_VIE_BASE 300
    #define MAX_STAT_BASE 200
    #define MIN_STAT_BASE 1

    typedef struct _stats {
        int s_vie, s_vit, s_att, s_def, s_aSp, s_dSp;
    } _stats, *Stats;


    _stats initStats (int vie, int vit, int att, int def, int aSp, int dSp);
    Stats creerStats (_stats stats);
    void supprStats (Stats s);

    String serializeStats (Stats s);
    int deserializeStats (Stats *s, String str);

#endif

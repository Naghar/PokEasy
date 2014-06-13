#include "p_espece.h"

Espece *liste_especes = NULL;
int nbr_especes = 0;

void startEspeces ()
{
    FILE* f_stats_especes = NULL;
    String line = NULL;

    f_stats_especes = fopen("especes.txt", "r");

    line = fgetsSizing(f_stats_especes);
    free(line);
    line = fgetsSizing(f_stats_especes);
    free(line);

    for(;;)
    {
        if ((line = fgetsSizing(f_stats_especes)) != NULL)
        {
            nbr_especes++;
            liste_especes = realloc(liste_especes, (nbr_especes + 1) * sizeof(*liste_especes));
            deserializeEspece(&liste_especes[nbr_especes], "2 [260 30 60 90 60 60] Carapuce");
            printf("%d -> %s (%d)\n", nbr_especes, line, strcmp(line, serializeEspece(liste_especes[nbr_especes])));

            free(line);
        }
    }

    fclose(f_stats_especes);
}

_espece initEspece (int ID, String nom, _stats stats_base)
{
    _espece e;

    e.e_ID = ID;
    e.e_nom = creerString(nom);
    e.e_stats_base = creerStats(stats_base);

    return e;
}

Espece creerEspece (_espece espece)
{
    Espece e = NULL;
    e = malloc(sizeof(*e));
    CHECK_NULL(e)

    if (espece.e_ID < 0 || espece.e_ID > nbr_especes) espece.e_ID = MIN_ID;
    if (espece.e_nom == NULL) espece.e_nom = "Undefined";
    if (espece.e_stats_base == NULL) espece.e_stats_base = creerStats(initStats(0, 0, 0, 0, 0, 0));

    *e = espece;

    return e;
}

void supprEspece (Espece e)
{
    supprString(e->e_nom);
    supprStats(e->e_stats_base);
    free(e);
    e = 0;
}

String formateAjuste (const char* fmt, ...)
{
    va_list ap;
    size_t str_size;
    char* str = NULL;

    va_start(ap, fmt);
        str_size = vsnprintf (str, 0, fmt, ap);
        str = malloc(str_size + 1);
        vsnprintf(str, str_size + 1, fmt, ap);
    va_end(ap);

    return (String) str;
}

String serializeEspece (Espece e)
{
    String str = NULL, str_stats = NULL;

    CHECK_NULL(e)
    str_stats = serializeStats(e->e_stats_base);
    str = sprintfSized("%d [%s] %s", e->e_ID, str_stats, e->e_nom);
    free(str_stats);
    CHECK_NULL(str)

    return str;
}

int deserializeEspece (Espece *e, String str)
{
    _espece espece;
    int buf_size, size = 0;

    CHECK_NULL(str)
    sscanf(str + size, "%d [%n", &espece.e_ID, &buf_size);
    size += buf_size;
    buf_size = deserializeStats(&(espece.e_stats_base), str + size);
    size += buf_size;
    sscanf(str + size, "] %n", &buf_size);
    size += buf_size;
    espece.e_nom = creerString(str + size);
    *e = creerEspece(espece);

    return size;
}

unsigned int getVieBase (Espece e)
{
    CHECK_NULL(e)
    CHECK_NULL(e->e_stats_base)
    return e->e_stats_base->s_vie;
}

unsigned int getVitBase (Espece e)
{
    CHECK_NULL(e)
    CHECK_NULL(e->e_stats_base)
    return e->e_stats_base->s_vit;
}

unsigned int getAttBase (Espece e)
{
    CHECK_NULL(e)
    CHECK_NULL(e->e_stats_base)
    return e->e_stats_base->s_att;
}

unsigned int getDefBase (Espece e)
{
    CHECK_NULL(e)
    CHECK_NULL(e->e_stats_base)
    return e->e_stats_base->s_def;
}

unsigned int getASpBase (Espece e)
{
    CHECK_NULL(e)
    CHECK_NULL(e->e_stats_base)
    return e->e_stats_base->s_aSp;
}

unsigned int getDSpBase (Espece e)
{
    CHECK_NULL(e)
    CHECK_NULL(e->e_stats_base)
    return e->e_stats_base->s_dSp;
}

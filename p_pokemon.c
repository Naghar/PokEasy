#include "p_pokemon.h"
/*
Pokemon rencontreAleatoire(String nom_route)
{
    Pokemon p = NULL;
    Route r = NULL;
    ListeRencontres lr_read = NULL;
    unsigned int alea, i = 0, niveau_alea, niveau_min, niveau_max, ID_alea;

    r = lireRencontres(nom_route);
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

    supprRoute(r);
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

    int c_vie, c_vit, c_att, c_def, c_aSp, c_dSp;
    float stat_multiplier;

    e = lireCaracteristiques(ID_espece);
    g = rand() % 2;

    EV = creerStats(0, 0, 0, 0, 0, 0);

    for (i = 0; i < 6; i++)
        r_IV[i] = 1 + rand() % 30;
    IV = creerStats(r_IV[0], r_IV[1], r_IV[2], r_IV[3], r_IV[4], r_IV[5]);

    stat_multiplier = (float)niveau / MAX_NIVEAU;

    c_vie = r_IV[0] + getVieBase(e) * stat_multiplier;
    c_vit = r_IV[1] + getVitBase(e) * stat_multiplier;
    c_att = r_IV[2] + getAttBase(e) * stat_multiplier;
    c_def = r_IV[3] + getDefBase(e) * stat_multiplier;
    c_aSp = r_IV[4] + getASpBase(e) * stat_multiplier;
    c_dSp = r_IV[5] + getDSpBase(e) * stat_multiplier;

    tot = creerStats(c_vie, c_vit, c_att, c_def, c_aSp, c_dSp);
    actu = creerStats(c_vie, c_vit, c_att, c_def, c_aSp, c_dSp);

    p = creerPokemon(e->e_nom, e, g, niveau, tot, actu, IV, EV);

    supprEspece(e);
    supprStats(EV);
    supprStats(IV);
    supprStats(tot);
    supprStats(actu);

    return p;
}

_pokemon initPokemon (String nom, _espece e, Genre g, int niveau, _stats tot, _stats actu, _stats IV, _stats EV)
{
    _pokemon p;

    p.p_nom = creerString(nom);
    p.p_espece = creerEspece(e);
    p.p_genre = g;
    p.p_niveau = niveau;
    p.p_stats_tot = creerStats(tot);
    p.p_stats_actu = creerStats(actu);
    p.p_IV = creerStats(IV);
    p.p_EV = creerStats(EV);

    return p;
}

Pokemon creerPokemon (_pokemon pokemon)
{
    Pokemon p = NULL;
    p = malloc(sizeof(*p));
    CHECK_NULL(p)

    if (pokemon.p_niveau < 0 || pokemon.p_niveau > MAX_NIVEAU) pokemon.p_niveau = MIN_NIVEAU;
    if (pokemon.p_nom == NULL) pokemon.p_nom = "Undefined";

    *p = pokemon;

    return p;
}

void supprPokemon (Pokemon p)
{
    supprString(p->p_nom);
    supprEspece(p->p_espece);
    supprStats(p->p_stats_tot);
    supprStats(p->p_stats_actu);
    supprStats(p->p_IV);
    supprStats(p->p_EV);
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

int deserializePokemon (Pokemon *p, String s)
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
*/

#include "p_rencontre.h"
/*
Rencontre creerRencontre (int ID_espece, int niveau_min, int niveau_max)
{
    Rencontre r = NULL;
    r = (Rencontre) malloc(sizeof(struct _rencontre));

    CHECK_NULL_ERROR(r)

    initRencontre(r, ID_espece, niveau_min, niveau_max);

    return r;
}

void initRencontre (Rencontre r, int ID_espece, int niveau_min, int niveau_max)
{
    CHECK_NULL_ERROR(r)

    if (ID_espece < 0 || ID_espece > NBR_ESPECES) ID_espece = 1;
    if (niveau_min < 0 || niveau_min > MAX_NIVEAU) niveau_min = 1;
    if (niveau_max < niveau_min || niveau_max > MAX_NIVEAU) niveau_max = MAX_NIVEAU;

    r->r_ID_espece = ID_espece;
    r->r_niveau_min = niveau_min;
    r->r_niveau_max = niveau_max;
}

void supprRencontre (Rencontre r)
{
    free(r);
}

ChainonRencontre creerChainonRencontre (Rencontre chainon, ChainonRencontre suivant)
{
    ChainonRencontre cr = NULL;
    cr = (ChainonRencontre) malloc(sizeof(struct _chainon_rencontre));

    CHECK_NULL_ERROR(cr)

    initChainonRencontre(cr, chainon, suivant);

    return cr;
}

void initChainonRencontre (ChainonRencontre cr, Rencontre chainon, ChainonRencontre suivant)
{
    CHECK_NULL_ERROR(cr)

    cr->cr_chainon = NULL;
    cr->cr_chainon = creerRencontre(chainon->r_ID_espece, chainon->r_niveau_min, chainon->r_niveau_max);

    cr->cr_suivant = suivant;

    CHECK_NULL_ERROR(cr->cr_chainon)
}

void supprChainonRencontre (ChainonRencontre cr)
{
    if (cr->cr_suivant)
        supprChainonRencontre(cr->cr_suivant);

    supprRencontre(cr->cr_chainon);
    free(cr);
}

ListeRencontres creerListeRencontres (ChainonRencontre premier, int taille)
{
    ListeRencontres lr = NULL;
    lr = (ListeRencontres) malloc(sizeof(ChainonRencontre));

    CHECK_NULL_ERROR(lr)

    initListeRencontres(lr, premier, taille);

    return lr;
}

void initListeRencontres (ListeRencontres lr, ChainonRencontre premier, int taille)
{
    CHECK_NULL_ERROR(lr)

    if (taille < 0)
    {
        if (premier == NULL) taille = 0;
        else taille = 1;
    }

    lr->lr_premier = premier;
    lr->taille_liste = taille;
}

void supprListeRencontres (ListeRencontres lr)
{
    supprChainonRencontre(lr->lr_premier);
    free(lr);
}

void ajoutRencontre (ListeRencontres* lr, Rencontre nouvelle_rencontre)
{
    ChainonRencontre cr = NULL;
    cr = creerChainonRencontre(nouvelle_rencontre, (*lr)->lr_premier);
    (*lr)->lr_premier = cr;
    (*lr)->taille_liste++;
}
*/

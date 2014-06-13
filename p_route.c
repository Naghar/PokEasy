#include "p_route.h"
/*
Route lireRencontres (String nom_route)
{
    Route r = NULL;
    FILE* fichier_rencontres = NULL;
    String r_nom_route = NULL;
    ListeRencontres lr = NULL;
    Rencontre r_rencontre = NULL;
    Boolean trouve = FALSE;
    int scan_ok = 0;

    fichier_rencontres = fopen("rencontres.txt", "r");
    CHECK_NULL_ERROR(fichier_rencontres)

    r_nom_route = malloc(32 * sizeof(char));
    CHECK_NULL_ERROR(r_nom_route)

    lr = creerListeRencontres(NULL, 0);
    CHECK_NULL_ERROR(lr)

    r_rencontre = malloc(sizeof(struct _rencontre));
    CHECK_NULL_ERROR(r_rencontre)

    while (!trouve && fgets(r_nom_route, 32, fichier_rencontres))
    {
        r_nom_route[strlen(r_nom_route) - 1] = '\0';
        if (strcmp(nom_route, r_nom_route) == 0)
            trouve = TRUE;
    }

    if (!trouve)
    {
        puts("La route n'existe pas");
        exit(EXIT_FAILURE);
    }

    do {
        scan_ok = fscanf(fichier_rencontres, "%u %u %u", &r_rencontre->r_ID_espece, &r_rencontre->r_niveau_min, &r_rencontre->r_niveau_max);
        if (scan_ok > 0) ajoutRencontre(&lr, r_rencontre);
    } while ( scan_ok > 0 && !feof(fichier_rencontres) );

    fclose(fichier_rencontres);
    free(nom_route);
    free(r_rencontre);

    r = creerRoute(nom_route, lr);

    CHECK_NULL_ERROR(r)

    return r;
}

Route creerRoute (String nom, ListeRencontres rencontres)
{
    Route r = NULL;
    r = (Route) malloc(sizeof(struct _route));

    CHECK_NULL_ERROR(r)

    initRoute(r, nom, rencontres);

    return r;
}

void initRoute (Route r, String nom, ListeRencontres rencontres)
{
    CHECK_NULL_ERROR(r)

    if (nom == NULL) nom = "Undefined";

    r->r_nom = NULL;
    r->r_nom = creerString(nom);

    r->r_rencontres = NULL;
    r->r_rencontres = rencontres;

    CHECK_NULL_ERROR(r->r_nom)
    CHECK_NULL_ERROR(r->r_rencontres)
}

void supprRoute (Route r)
{
    supprString(r->r_nom);
    supprListeRencontres(r->r_rencontres);
    free(r);
}
*/

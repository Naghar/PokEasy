#include <time.h>
#include "p_espece.h"

int main()
{
    int i = 0;

	startEspeces();
	while (i < nbr_especes)
	{
		printf("%d : %s\n", i, serializeEspece(liste_especes[i]));
		i++;
	}

    return 0;
}

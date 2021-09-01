#include "geffe.h"


int main(int argc, char **argv)
{
	int suite = 0;
	printf("Saisir la taille de la suite : \n");
	scanf("%d", &suite);

	initialisation_lfsr();
	afficher();
	
	printf("\n la suite chiffrante : ( ");
	for(int i=0; i<suite; ++i)
	{
		printf("%d ", combinaison_non_lin());
	}
	printf(" ) \n");	
	return 0;
}

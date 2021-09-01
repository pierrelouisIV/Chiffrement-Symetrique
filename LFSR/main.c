#include "lfsr16.h"


int main(int argc, char **argv)
{
	uint16_t * S;
	int nb;
	int mode = 0;
	printf("Choisissez votre Mode : \n [ 1 ] -> mode aléatoire \n [ 2 ] -> mode manuel \n");
	scanf("%d", &mode);
	if (mode == 1)
	{
		printf("---Mode aléatoire---\n");
		init_aleatoire();
	}
	else if (mode == 2)
	{
		int c, v;
		printf("Saisissez coefficient puis vecteur initial (de 0 à 2¹⁶) : \n");
		scanf("%d", &c);
		scanf("%d", &v);
		printf("---Mode manuel---\n");
		init_manuelle(c, v);
	}
	
	printf("Saisissez la taille de la suite chiffrante : \n");
	scanf("%d", &nb);
	system("clear");
	S = malloc(sizeof(uint16_t) * nb);	// mémoire
	afficher_coeffs();
	afficher_vecteur();
	
	int moyenne = 0;
	float var = 0;
	for(int i=0; i<nb; ++i)
	{
		S[i] = decalage_vecteur();
		printf("i = %d ->%x \n",i, S[i]);
		moyenne += S[i];
	}
	printf("\n");
	
	// stats :
	printf("Moyenne = %d\n", moyenne/nb);
	for(int i=0; i<nb; ++i)
	{
		var += pow(S[i]-moyenne, 2);
	}
	printf("Variance = %1f\n", var/nb);
	printf("Ecart-type = %f\n", sqrt(var/nb));
	
	// Libération de la mémoire :
	free(S);
	return 0;
}

#include "geffe.h"

#define MAX 22
#define L1 19
#define L2 22
#define L3 17
//
int LFSR1[L1] = {0};
int LFSR2[L2] = {0};
int LFSR3[L3] = {0};

//
void initialisation_lfsr()
{
	time_t t;
	srand((unsigned) time(&t));
	int a, b, c;
	for(int i=0; i<MAX; ++i)
	{
		a = rand() % 2;
		b = rand() % 2;
		c = rand() % 2;
		if(i < L1) LFSR1[i] = a;
		if(i < L2) LFSR2[i] = b;
		if(i < L3) LFSR3[i] = c;
	}
}

//
int decalage_lfsr1()
{
	int nouveau = ((LFSR1[18] ^ LFSR1[16]) ^ LFSR1[5]) ^ LFSR1[1]; 	// le XOR
	int tmp, tmp2;
	tmp = LFSR1[0];
	for(int i=1; i<L1; ++i)
	{
		tmp2 = LFSR1[i];
		LFSR1[i] = tmp;
		tmp = tmp2;
	}
	LFSR1[0] = nouveau;
	return tmp;
}

//
int decalage_lfsr2()
{
	int nouveau = (LFSR2[13] ^ LFSR2[5]) ^ LFSR2[1]; 	// le XOR
	int tmp, tmp2;
	tmp = LFSR2[0];
	for(int i=1; i<L2; ++i)
	{
		tmp2 = LFSR2[i];
		LFSR2[i] = tmp;
		tmp = tmp2;
	}
	LFSR2[0] = nouveau;
	return tmp;
}

//
int decalage_lfsr3()
{
	int nouveau = ((LFSR3[11] ^ LFSR3[9]) ^ LFSR3[3]) ^ LFSR3[0]; 	// le XOR
	int tmp, tmp2;
	tmp = LFSR3[0];
	for(int i=1; i<L3; ++i)
	{
		tmp2 = LFSR3[i];
		LFSR3[i] = tmp;
		tmp = tmp2;
	}
	LFSR3[0] = nouveau;
	return tmp;
}


//
int combinaison_non_lin()
{
	int x1, x2, x3;
	x1 = decalage_lfsr1();
	x2 = decalage_lfsr2();
	x3 = decalage_lfsr3();
	return ((x1 & x2) ^ ((1 | x2) & x3));
}


// affichage
void afficher()
{
	printf("\n LFSR1 : \n [");
	for(int i=0; i<L1; ++i)
	{
		printf(" %d ", LFSR1[i]);
	}
	printf(" ]\n");
	
	printf("\n LFSR2 : \n [");
	for(int i=0; i<L2; ++i)
	{
		printf(" %d ", LFSR2[i]);
	}
	printf(" ]\n");
	
	printf("\n LFSR3 : \n [");
	for(int i=0; i<L3; ++i)
	{
		printf(" %d ", LFSR3[i]);
	}
	printf(" ]\n");
}

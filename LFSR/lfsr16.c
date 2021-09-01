#include "lfsr16.h"

// Variables globales :
uint16_t coeffs;
uint16_t vecteur;


// initialisation avec le "hasard" :
void init_aleatoire()
{
	init_coeffs();
	init_vec();
}


//
void init_coeffs()
{
	time_t t;
	srand((unsigned) time(&t));
	uint16_t alea = 0 + rand() % (0xffff + 1 - 0);
	coeffs = alea;
}

// initialisation vecteur initiale :
void init_vec()
{
	time_t t;
	srand((unsigned) time(&t));
	uint16_t alea = 1 + rand() % (0xffff + 1 - 1);
	vecteur = alea;
}

// paramètres choisis à la main :
void init_manuelle(uint16_t c, uint16_t v)
{
	coeffs = c;
	vecteur = v;
}



//
uint16_t xor_r15()
{
	uint16_t res = coeffs & vecteur;
	res = (res >> 15) ^ 
	      ((res & 0x4000) >> 14) ^
	      ((res & 0x2000) >> 13) ^
	      ((res & 0x1000) >> 12) ^
	      ((res & 0x0800) >> 11) ^
	      ((res & 0x0400) >> 10) ^
	      ((res & 0x0200) >>  9) ^
	      ((res & 0x0100) >>  8) ^
	      ((res & 0x0080) >>  7) ^
	      ((res & 0x0040) >>  6) ^
	      ((res & 0x0020) >>  5) ^
	      ((res & 0x0010) >>  4) ^
	      ((res & 0x0008) >>  3) ^
	      ((res & 0x0004) >>  2) ^
	      ((res & 0x0002) >>  1) ^
	      (res & 0x00001);
	return res;
}

//
uint16_t decalage_vecteur()
{
	uint16_t s = vecteur & 0x0001;	// le bit de sortie
	vecteur = (vecteur >> 1) | (xor_r15() << 15);
	return s;
}




// affichage :
void afficher_coeffs()
{
	printf("coefficient : %x\n", coeffs);
}

void afficher_vecteur()
{
	printf("vecteur initial : %x\n", vecteur);
}


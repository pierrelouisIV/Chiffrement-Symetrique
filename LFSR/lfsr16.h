#ifndef H_LFSR16
#define H_LFSR16

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// structure sur 16 bits :
typedef unsigned short uint16_t;

// initialisation  :
void init_aleatoire();
void init_coeffs();
void init_vec();

void init_manuelle(uint16_t c, uint16_t v);


// calcul du registre Si+m :
uint16_t xor_r15();

uint16_t decalage_vecteur();

//affichage :
void afficher_coeffs();
void afficher_vecteur();

#endif

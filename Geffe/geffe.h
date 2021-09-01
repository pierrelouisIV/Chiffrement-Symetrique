#ifndef H_GEFFE
#define H_GEFFE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// initialisation des trois LFSR :
void initialisation_lfsr();

//
int decalage_lfsr1();
int decalage_lfsr2();
int decalage_lfsr3();

//
int combinaison_non_lin();

// affichage
void afficher();

#endif

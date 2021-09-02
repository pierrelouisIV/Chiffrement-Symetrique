#include "cipher.h"
#include <stdio.h>
#include <stdlib.h>

#define taille_F 8
#define taille_K 3

// la fonction de filtrage F
int F[taille_F] = {0, 0, 0, 1, 1, 0, 1, 0};

// La clef K
uint16_t K[3] = {0};

// Les LFSR
uint16_t LFSR1 = 0x0000;
uint16_t LFSR2 = 0x0000;
uint16_t LFSR3 = 0x0000;

// Les coefficients de rétroaction
uint16_t CF1 = 0x0093;  // <=> (0000000010010011) base 2
uint16_t CF2 = 0x0883;  // <=> (0000100010000011) --
uint16_t CF3 = 0x002D;  // <=> (0000000000101101) --

// nombre de tours :
int n = 0;

// on demande la taille souhaité
void init_n()
{
    printf("  Veuillez entrez la taille de la suite chiffrante : ");
    scanf("%d", &n);
}


// On initialise les 3 clefs k0, k1, k2 :
void init_K()
{
    printf(" Veuillez saisir trois chiffres compris entre 0 et 65 535 \n");
    printf("k0 : ");
    scanf("%d",&K[0]);
    printf("k1 : ");
    scanf("%d",&K[1]);
    printf("k2 : ");
    scanf("%d",&K[2]);
}

// On initialise la fonction F : {0,1}³ -> {0,1}
// (initialisation falcutative)
void init_F(int * tableau)
{
    F[0] = tableau[0];
    F[1] = tableau[4]; 
    F[2] = tableau[2]; 
    F[3] = tableau[6]; 
    F[4] = tableau[1]; 
    F[5] = tableau[5]; 
    F[6] = tableau[3];
    F[7] = tableau[7];
}

// Elle prend en entrée 3 bits et en sortie un bit
int fonction_F(int x0, int x1, int x2)
{
    int x0_x1_x2;
    x0_x1_x2 = (x0 << 2 | x1 << 1 | x2);
    return F[x0_x1_x2];
}

// Initialisation des LFSR avec la clef K
void init_LFSR()
{
    LFSR1 = K[0];
    LFSR2 = K[1];
    LFSR3 = K[2];
}

// LFSR 1
int LFSR_1()
{
    // on sépare le CF1 en 4 masques et on XOR les bits du LFSR :
    int bit_15 = ((LFSR1 & 0x0001) 
            ^ ((LFSR1 & 0x0002) >> 1)
            ^ ((LFSR1 & 0x0010) >> 4)
            ^ ((LFSR1 & 0x0080) >> 7));

    int bit_s = LFSR1 & 0x0001;
    //printf("\n bit_15 du LFSR1 = %d\n", bit_15);
    LFSR1 = (LFSR1 >> 1) | (bit_15 << 15);
    //printf("valeur du lfsr1 = (%d)base10 = (%x)base16 \n", LFSR1, LFSR1);
    return bit_s;
}

// LFSR 2
int LFSR_2()
{
    // On sépare le CF2 en 4 masques :
    int bit_15 = ((LFSR2 & 0x0001)
            ^ ((LFSR2 & 0x0002) >> 1)
            ^ ((LFSR2 & 0x0080) >> 7)
            ^ ((LFSR2 & 0x0800) >> 11));

    // On récupère le bit de poid faible
    int bit_s = LFSR2 & 0x0001;
    //printf("bit_15 du LFSR2 = %d\n", bit_15);
    // On met à jour le LFSR :
    LFSR2 = (LFSR2 >> 1) | (bit_15 << 15);
    //printf("valeur du LFSR2 = (%d)base10 = (%x)base16 \n", LFSR2, LFSR2);
    return bit_s;
}

// LFSR 3
int LFSR_3()
{
    // On sépare le CF3 en 4 masques :
    int bit_15 = ((LFSR3 & 0x0001)
            ^ ((LFSR3 & 0x0004) >> 2)
            ^ ((LFSR3 & 0x0008) >> 3)
            ^ ((LFSR3 & 0x0020) >> 5));

    // On récupère le bit de poid faible
    int bit_s = LFSR3 & 0x0001;
    //printf("bit_15 du LFSR3 = %d\n", bit_15);
    // On met à jour le LFSR :
    LFSR3 = (LFSR3 >> 1) | (bit_15 << 15);
    //printf("valeur du LFSR3 = (%d)base10 = (%x)base16 \n", LFSR3, LFSR3);
    return bit_s;
}


// avec le nb de tours n, la fonction produite la suite chiffrante
int produire_suite()
{
    init_n();
    init_K();
    init_LFSR();
    for(int i = 0; i< n; ++i)
    {
        printf(" %d ", i);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", fonction_F(LFSR_1(), LFSR_2(), LFSR_3()));
    }
    printf("\n");
    return 1;
}
#ifndef H_CIPHER
#define H_CIPHER

// la structure d'un LFSR de 16 bits :
typedef unsigned short uint16_t;

// nb de tours 
void init_n();

// la clef K
void init_K();

// la fonction F :
void init_F(int * tableau);
int fonction_F(int x0, int x1, int x2);

// fonctions des trois LFSR :
void init_LFSR();

int LFSR_1();
int LFSR_2();
int LFSR_3();

// fonction de chiffrement pour produire la suite chiffrante
int produire_suite();


#endif
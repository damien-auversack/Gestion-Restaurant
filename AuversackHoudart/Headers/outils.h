#ifndef DEF_outils
#define DEF_outils
//différentes fonctions utilisées pour simplifié d'autres fonctions

int estReserve(int , int);
const char* nomMenuChoisi(int);
void remplaceMenuTable(int , int , int);
void selectTable(int , int);
int rechercheTableLibre(int , int );
int remplaceNonReserveTable(int , char[], int , int , int );
int modifTableSuppRes(int , int );
void viderBuffer();
void modifierService(int, int);
void modifierFonction(int, char[]);
void modifierNomEmploye(int, char[]);

#endif

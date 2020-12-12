#ifndef DEF_structures
#define DEF_structures
//récupères les différentes structures utilisées dans le code

typedef struct Table {
	int nbPlaceMax;
	
	int estReserveMatin;
	char nomMatin[21];
	int nbPersonneMatin;
	int numMenuMatin;
	
	int estReserveSoir;
	char nomSoir[21];
	int nbPersonneSoir;
	int numMenuSoir;
	
	struct Table *suivant;
}Table;

typedef struct Menu {
	char nom[21];
	float prix;
	char description[60];
	
	struct Menu *suivant;
}Menu;

typedef struct Employe {
	char nom[21];
	int service;
	char fonction[21];
	struct Employe *suivant;
}Employe;

#endif

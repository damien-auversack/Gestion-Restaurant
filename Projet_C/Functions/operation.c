#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/structures.h"

int estReserve(int service, int numTable) {
	
	int n=0, i;

	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/Table.dat", "r");

	Table *deb, *courant, *suivant;
	courant=malloc(sizeof(Table));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {
		courant->estReserveMatin = 0;
		strcpy(courant->nomMatin, "");
		courant->nbPersonneMatin = 0;
		courant->numMenuMatin = 0;
		
		courant->estReserveSoir = 0;
		strcpy(courant->nomSoir, "");
		courant->nbPersonneSoir = 0;
		courant->numMenuSoir = 0;
		
		fscanf(fdat,"%d",&courant->estReserveMatin);
		if(courant->estReserveMatin == 1) {
			fscanf(fdat,"%s",&courant->nomMatin);
			fscanf(fdat,"%d",&courant->nbPersonneMatin);
			fscanf(fdat,"%d",&courant->numMenuMatin);
			
		}

		fscanf(fdat,"%d",&courant->estReserveSoir);
		if(courant->estReserveSoir == 1) {
			fscanf(fdat,"%s",&courant->nomSoir);
			fscanf(fdat,"%d",&courant->nbPersonneSoir);
			fscanf(fdat,"%d",&courant->numMenuSoir);
		}
		fscanf(fdat,"%d",&courant->nbPlaceMax);
		
		suivant=malloc(sizeof(Table));
		courant->suivant=suivant;
		n++;
		courant=suivant;
		
	}

	//Placer Null au suivant du derni�re �l�ment + lib�rer l'espace de suivant
	courant=deb;
	for(i=1;i<n;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;		
		
	courant=deb;
		
	// Recherche
	for(i=1;i<=n;i++) {		
	
		if(service==1 && i==numTable) {
			if(courant->estReserveMatin == 1) {
				fclose(fdat);
				return 1;
			}
			
		}
		else if(service==2 && i==numTable) {
			if(courant->estReserveSoir == 1) {
				fclose(fdat);
				return 1;
			}
			
		}
		
		
		courant=courant->suivant;
	}
	fclose(fdat);
	return 0;

}

const char* nomMenuChoisi(int numMenu) {
	static char nomMenuChoisi[21];
	
	int n=0, i, j;
	FILE *fdat;
	fdat = fopen("Data/Menu.dat", "r");

	Menu *deb, *courant, *suivant;
	courant=malloc(sizeof(Menu));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {
		fscanf(fdat,"%s",&courant->nom);
		fscanf(fdat,"%5f",&courant->prix);
		fscanf(fdat,"%s",&courant->description);
		suivant=malloc(sizeof(Menu));
		courant->suivant=suivant;
		n++;
		courant=suivant;
	}

	//Placer Null au suivant du derni�re �l�ment + lib�rer l'espace de suivant
	courant=deb;
	for(i=1;i<n;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;	
		
	courant=deb;
		
	for(i=1;i<=n;i++) {
		
		for(j=0; j<strlen(courant->description); j++) {
			if(courant->description[j] == '_') {
				courant->description[j] = ' ';
			}
		}
		
		if(i==numMenu) {
			strcpy(nomMenuChoisi, courant->nom);
		}
		courant=courant->suivant;
	}
	
	
	free(courant);
	free(suivant);	
	fclose(fdat);	
	return nomMenuChoisi;
}

void remplaceMenuTable(int numMenu, int numTable, int service) {
	
	int n=0, i;

	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/Table.dat", "r");
	fdatTmp = fopen("Data/Table.tmp", "w");

	Table *deb, *courant, *suivant;
	courant=malloc(sizeof(Table));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {
		courant->estReserveMatin = 0;
		strcpy(courant->nomMatin, "");
		courant->nbPersonneMatin = 0;
		courant->numMenuMatin = 0;
		
		courant->estReserveSoir = 0;
		strcpy(courant->nomSoir, "");
		courant->nbPersonneSoir = 0;
		courant->numMenuSoir = 0;
		
		fscanf(fdat,"%d",&courant->estReserveMatin);
		if(courant->estReserveMatin == 1) {
			fscanf(fdat,"%s",&courant->nomMatin);
			fscanf(fdat,"%d",&courant->nbPersonneMatin);
			fscanf(fdat,"%d",&courant->numMenuMatin);
			
		}

		fscanf(fdat,"%d",&courant->estReserveSoir);
		if(courant->estReserveSoir == 1) {
			fscanf(fdat,"%s",&courant->nomSoir);
			fscanf(fdat,"%d",&courant->nbPersonneSoir);
			fscanf(fdat,"%d",&courant->numMenuSoir);
		}
		fscanf(fdat,"%d",&courant->nbPlaceMax);
		
		suivant=malloc(sizeof(Table));
		courant->suivant=suivant;
		n++;
		courant=suivant;
		
	}

	//Placer Null au suivant du derni�re �l�ment + lib�rer l'espace de suivant
	courant=deb;
	for(i=1;i<n;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;		
		
	courant=deb;
		
	// Ecriture
	for(i=1;i<=n;i++) {		
		fprintf(fdatTmp, "%d ", courant->estReserveMatin);
		if(courant->estReserveMatin==1) {
			if(numTable==i && service==1) {
				courant->numMenuMatin = numMenu;
			}
			fprintf(fdatTmp, "%s %d %d ", courant->nomMatin, courant->nbPersonneMatin, courant->numMenuMatin);
		}
		
		fprintf(fdatTmp, "%d", courant->estReserveSoir);
		if(courant->estReserveSoir==1) {
			if(numTable==i && service==2) {
				courant->numMenuSoir = numMenu;
			}
			fprintf(fdatTmp, " %s %d %d", courant->nomSoir, courant->nbPersonneSoir, courant->numMenuSoir);
		}
		fprintf(fdatTmp, " %d", courant->nbPlaceMax);
		if(i!=n) {
			fprintf(fdatTmp, "\n");
		}
		courant=courant->suivant;
	}
		
	fclose(fdat);
	fclose(fdatTmp);
	remove("Data/Table.dat");		
	rename("Data/Table.tmp", "Data/Table.dat");
	
}

void selectTable(int numTable, int service) {
	
	int nbPlaceMaxSelect;
	int reserveSelect;
	char nomPersonneSelect[21];
	int nbPersonneSelect;
	int numMenuSelect;
		
	// Traitement table
	int nTable=0, i, j;
	FILE *fdat;
	fdat = fopen("Data/Table.dat", "r");

	Table *deb, *courant, *suivant;
	courant=malloc(sizeof(Table));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {
		
		// Initialisation
		courant->estReserveMatin = 0;
		strcpy(courant->nomMatin, "");
		courant->nbPersonneMatin = 0;
		courant->numMenuMatin = 0;
		
		courant->estReserveSoir = 0;
		strcpy(courant->nomSoir, "");
		courant->nbPersonneSoir = 0;
		courant->numMenuSoir = 0;
		
		fscanf(fdat,"%d",&courant->estReserveMatin);
		if(courant->estReserveMatin == 1) {
			fscanf(fdat,"%s",&courant->nomMatin);
			fscanf(fdat,"%d",&courant->nbPersonneMatin);
			fscanf(fdat,"%d",&courant->numMenuMatin);
			
		}

		fscanf(fdat,"%d",&courant->estReserveSoir);
		if(courant->estReserveSoir == 1) {
			fscanf(fdat,"%s",&courant->nomSoir);
			fscanf(fdat,"%d",&courant->nbPersonneSoir);
			fscanf(fdat,"%d",&courant->numMenuSoir);
		}
		fscanf(fdat,"%d",&courant->nbPlaceMax);
		
		suivant=malloc(sizeof(Table));
		courant->suivant=suivant;
		nTable++;
		courant=suivant;
	}

	//Placer Null au suivant du derni�re �l�ment + lib�rer l'espace de suivant
	courant=deb;
	for(i=1;i<nTable;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;	
		
	courant=deb;	
	// Affichage
	for(i=1;i<=nTable;i++) {
		if(i==numTable) {
			if(service==1) {
				nbPlaceMaxSelect = courant->nbPlaceMax;
				reserveSelect = courant->estReserveMatin;
				strcpy(nomPersonneSelect, courant->nomMatin);				
				numMenuSelect = courant->numMenuMatin;
				nbPersonneSelect = courant->nbPersonneMatin;
			}
			else if(service==2) {
				nbPlaceMaxSelect = courant->nbPlaceMax;
				reserveSelect = courant->estReserveSoir;
				strcpy(nomPersonneSelect, courant->nomSoir);
				numMenuSelect = courant->numMenuSoir;
				nbPersonneSelect = courant->nbPersonneSoir;
			}
			
		}
		courant=courant->suivant;
	}
	
	free(courant);
	free(suivant);	
	fclose(fdat);
	
	
	// Affichage	

	if(service==1) {
		printf("\n");
		printf("   |Table|\n");
		printf("   --------------------------------------------------------------------------------\n");
		printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
		printf("   --------------------------------------------------------------------------------\n");
		printf("   |     %d     |      %2d       |    %-3s    |   %-10s |      %d     |     %d    |\n",numTable, nbPlaceMaxSelect, (reserveSelect ? "Oui":"Non"), nomPersonneSelect, nbPersonneSelect, numMenuSelect);
		printf("   --------------------------------------------------------------------------------\n\n");
		
	}
	else if(service==2) {
		printf("\n");
		printf("   |Table|\n");
		printf("   --------------------------------------------------------------------------------\n");
		printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
		printf("   --------------------------------------------------------------------------------\n");
		printf("   |     %d     |      %2d       |    %-3s    |   %-10s |      %d     |     %d    |\n",numTable, nbPlaceMaxSelect, (reserveSelect ? "Oui":"Non"), nomPersonneSelect, nbPersonneSelect, numMenuSelect);
		printf("   --------------------------------------------------------------------------------\n\n");
	}
	

}

void FaireAddition(int tableAddition, int service) {
	float sommeAddition;
	
	int nbPlaceMaxSelect;
	int reserveSelect;
	char nomPersonneSelect[21];
	int nbPersonneSelect;
	int numMenuSelect;
	
	char nomMenuSelect[21];
	float prixSelect;
	char descriptionSelect[40];
	
	// Traitement table
	int nTable=0, nMenu=0, i, j;
	FILE *fdat;
	fdat = fopen("Data/Table.dat", "r");

	Table *deb, *courant, *suivant;
	courant=malloc(sizeof(Table));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {
		
		// Initialisation
		courant->estReserveMatin = 0;
		strcpy(courant->nomMatin, "");
		courant->nbPersonneMatin = 0;
		courant->numMenuMatin = 0;
		
		courant->estReserveSoir = 0;
		strcpy(courant->nomSoir, "");
		courant->nbPersonneSoir = 0;
		courant->numMenuSoir = 0;
		
		fscanf(fdat,"%d",&courant->estReserveMatin);
		if(courant->estReserveMatin == 1) {
			fscanf(fdat,"%s",&courant->nomMatin);
			fscanf(fdat,"%d",&courant->nbPersonneMatin);
			fscanf(fdat,"%d",&courant->numMenuMatin);
			
		}

		fscanf(fdat,"%d",&courant->estReserveSoir);
		if(courant->estReserveSoir == 1) {
			fscanf(fdat,"%s",&courant->nomSoir);
			fscanf(fdat,"%d",&courant->nbPersonneSoir);
			fscanf(fdat,"%d",&courant->numMenuSoir);
		}
		fscanf(fdat,"%d",&courant->nbPlaceMax);
		
		suivant=malloc(sizeof(Table));
		courant->suivant=suivant;
		nTable++;
		courant=suivant;
	}

	//Placer Null au suivant du derni�re �l�ment + lib�rer l'espace de suivant
	courant=deb;
	for(i=1;i<nTable;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;	
		
	courant=deb;	
	// Affichage
	for(i=1;i<=nTable;i++) {
		if(i==tableAddition) {
			if(service==1) {
				nbPlaceMaxSelect = courant->nbPlaceMax;
				reserveSelect = courant->estReserveMatin;
				strcpy(nomPersonneSelect, courant->nomMatin);				
				numMenuSelect = courant->numMenuMatin;
				nbPersonneSelect = courant->nbPersonneMatin;
			}
			else if(service==2) {
				nbPlaceMaxSelect = courant->nbPlaceMax;
				reserveSelect = courant->estReserveSoir;
				strcpy(nomPersonneSelect, courant->nomSoir);
				numMenuSelect = courant->numMenuSoir;
				nbPersonneSelect = courant->nbPersonneSoir;
			}
			
		}
		courant=courant->suivant;
	}
	
	free(courant);
	free(suivant);	
	fclose(fdat);
	
	// Traitement Menu
	FILE *fdat2;
	fdat2 = fopen("Data/Menu.dat", "r");

	Menu *deb2, *courant2, *suivant2;
	courant2=malloc(sizeof(Menu));
	deb2=courant2;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {
		fscanf(fdat2,"%s",&courant2->nom);
		fscanf(fdat2,"%5f",&courant2->prix);
		fscanf(fdat2,"%s",&courant2->description);
		suivant2=malloc(sizeof(Menu));
		courant2->suivant=suivant2;
		nMenu++;
		courant2=suivant2;
	}

	//Placer Null au suivant du derni�re �l�ment + lib�rer l'espace de suivant
	courant2=deb2;
	for(i=1;i<nMenu;i++) {
		courant2=courant2->suivant;
	}
	courant2->suivant=NULL;	
		
	courant2=deb2;
		
	// Affichage	

	for(i=1;i<=nMenu;i++) {
			
		if(i==numMenuSelect) {
			for(j=0; j<strlen(courant2->description); j++) {
				if(courant2->description[j] == '_') {
					courant2->description[j] = ' ';
				}
			}
			strcpy(nomMenuSelect, courant2->nom);
			prixSelect = courant2->prix;
			strcpy(descriptionSelect, courant2->description);
		}
		
		courant2=courant2->suivant;
	}
	
	if(tableAddition>nTable || tableAddition<=0 || reserveSelect==0) {
		goto erreurTailleTable;
	}
	
	sommeAddition = prixSelect * nbPersonneSelect;
	system("cls");	
	if(service==1) {
		
		printf("   |Table|\n");
		printf("   --------------------------------------------------------------------------------\n");
		printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
		printf("   --------------------------------------------------------------------------------\n");
		printf("   |     %d     |      %2d       |    %-3s    |   %-10s |      %d     |     %d    |\n",tableAddition, nbPlaceMaxSelect, (reserveSelect ? "Oui":"Non"), nomPersonneSelect, nbPersonneSelect, numMenuSelect);
		printf("   --------------------------------------------------------------------------------\n\n");
		printf("   |Menu|\n");	
		printf("   ------------------------------------------------------------------------------\n");
		printf("   |  N  |     Nom      |     Prix (Euro)  |         Description                |\n");
		printf("   ------------------------------------------------------------------------------\n");
		printf("   |  %d  |  %-10s  |      %5.2f       |  %-25s         |\n",numMenuSelect, nomMenuSelect, prixSelect, descriptionSelect);
		printf("   ------------------------------------------------------------------------------\n");
		
	}
	else if(service==2) {
		printf("   |Table|\n");
		printf("   --------------------------------------------------------------------------------\n");
		printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
		printf("   --------------------------------------------------------------------------------\n");
		printf("   |     %d     |      %2d       |    %-3s    |   %-10s |      %d     |     %d    |\n",tableAddition, nbPlaceMaxSelect, (reserveSelect ? "Oui":"Non"), nomPersonneSelect, nbPersonneSelect, numMenuSelect);
		printf("   --------------------------------------------------------------------------------\n\n");
		printf("   |Menu|\n");	
		printf("   ------------------------------------------------------------------------------\n");
		printf("   |  N  |     Nom      |     Prix (Euro)  |         Description                |\n");
		printf("   ------------------------------------------------------------------------------\n");
		printf("   |  %d  |  %-10s  |      %5.2f       |  %-25s         |\n",numMenuSelect, nomMenuSelect, prixSelect, descriptionSelect);
		printf("   ------------------------------------------------------------------------------\n");
	}
	
	printf("\n   L'addition de la table %d est de %5.2f Euro \n\n", tableAddition, sommeAddition);
	erreurTailleTable:
	free(courant2);
	free(suivant2);	
	fclose(fdat2);	
	
}

void changerCommander() {
	int service;
	int numTable;
	int numMenuChoisi;
	
	afficherChangerCommande();
	recupTableReserveMidi();
	recupTableReserveSoir();
	
	printf("   Service (Midi=1/Soir=2) : ");
	scanf("%d", &service);
	erreurTableNonReserve:
	system("cls");
	
	afficherChangerCommande();
	if(service==1) {		
		recupTableReserveMidi();
		printf("   Numero de votre table : ");
		scanf("%d", &numTable);
		if(estReserve(1, numTable)==0) {
			goto erreurTableNonReserve;
		}
		erreurIndexNumMenuMidi:
		system("cls");
		afficherChangerCommande();
		selectTable(numTable, 1);
		printf("   |Menu|");
		recupMenu();
		printf("   Quel menu voulez vous ? : ");
		scanf("%d", &numMenuChoisi);
		if(numMenuChoisi<=0 || numMenuChoisi > compterMenu()) {
			goto erreurIndexNumMenuMidi;
		}
		printf("\n");
		remplaceMenuTable(numMenuChoisi, numTable, service);
		printf("   Vous avez choisi le menu : %s\n\n", nomMenuChoisi(numMenuChoisi));
	}
	else if(service==2) {
		recupTableReserveSoir();
		printf("   Numero de votre table : ");
		scanf("%d", &numTable);
		if(estReserve(2, numTable)==0) {
			goto erreurTableNonReserve;
		}
		erreurIndexNumMenuSoir:
		system("cls");
		afficherChangerCommande();
		selectTable(numTable, 2);
		printf("   |Menu|");
		recupMenu();
		printf("   Quel menu voulez vous ? : ");
		scanf("%d", &numMenuChoisi);
		if(numMenuChoisi<=0 || numMenuChoisi > compterMenu()) {
			goto erreurIndexNumMenuSoir;
		}
		printf("\n");
		remplaceMenuTable(numMenuChoisi, numTable, service);
		printf("   Vous avez choisi le menu : %s\n\n", nomMenuChoisi(numMenuChoisi));
	}
	
	
}

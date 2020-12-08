#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	char description[40];
	
	struct Menu *suivant;
}Menu;

int compterMenu() {
		int n=0, i, j;
	FILE *fdat;
	fdat = fopen("Data/Menu.dat", "r");

	Menu *deb, *courant, *suivant;
	courant=malloc(sizeof(Menu));
	deb=courant;

	// Lecture + Construction de ma liste chainée
	while(!feof(fdat)) {
		fscanf(fdat,"%s",&courant->nom);
		fscanf(fdat,"%5f",&courant->prix);
		fscanf(fdat,"%s",&courant->description);
		suivant=malloc(sizeof(Menu));
		courant->suivant=suivant;
		n++;
		courant=suivant;
	}

	//Placer Null au suivant du dernière élément + libérer l'espace de suivant
	courant=deb;
	for(i=1;i<n;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;	
		
	courant=deb;
	
	free(courant);
	free(suivant);	
	fclose(fdat);	
	return n;
}

int compterTable() {
	int n=0, i;
	FILE *fdat;
	fdat = fopen("Data/Table.dat", "r");

	Table *deb, *courant, *suivant;
	courant=malloc(sizeof(Table));
	deb=courant;

	// Lecture + Construction de ma liste chainée
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
		n++;
		courant=suivant;
	}	

	//Placer Null au suivant du dernière élément + libérer l'espace de suivant
	courant=deb;
	for(i=1;i<n;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;	
	
	free(courant);
	free(suivant);	
	fclose(fdat);
	
	return n;
}

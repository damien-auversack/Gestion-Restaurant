#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Table {
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

void recupTables() {
	
	int n=0, i;
	FILE *fdat;
	fdat = fopen("Data/Table.dat", "r");

	Table *deb, *courant, *suivant;
	courant=malloc(sizeof(Table));
	deb=courant;

	// Lecture + Construction de ma liste chainée
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
		
	courant=deb;	
	// Affichage
	printf("\n");
	printf("   |Matin|\n");	
	printf("   ----------------------------------------------------------------\n");
	printf("   | Num table |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
	printf("   ----------------------------------------------------------------\n");
	for(i=1;i<=n;i++) {
		printf("   |     %d     |    %-3s    |   %-10s |      %d     |     %d    |\n",i, (courant->estReserveMatin==1 ? "Oui":"Non"), courant->nomMatin, courant->nbPersonneMatin, courant->numMenuMatin);
		courant=courant->suivant;
	}
	printf("   ----------------------------------------------------------------\n");
	printf("\n");
	
	courant=deb;	
	// Affichage
	
	printf("   |Soir|\n");	
	printf("   ----------------------------------------------------------------\n");
	printf("   | Num table |  Reserve  |     Nom      |  nb Pers.  | Num menu | \n");
	printf("   ----------------------------------------------------------------\n");
	for(i=1;i<=n;i++) {
		printf("   |     %d     |    %-3s    |   %-10s |      %d     |     %d    |\n",i, (courant->estReserveSoir==1) ? "Oui":"Non", courant->nomSoir, courant->nbPersonneSoir, courant->numMenuSoir);
		courant=courant->suivant;
	}
	printf("   ----------------------------------------------------------------\n");
	printf("\n");
	
	free(courant);
	free(suivant);	
	fclose(fdat);	
	
}

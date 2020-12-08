#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/structures.h"

void recupTables() {
	
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
		
	courant=deb;	
	// Affichage
	printf("\n");
	printf("   |Midi|\n");	
	printf("   --------------------------------------------------------------------------------\n");
	printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
	printf("   --------------------------------------------------------------------------------\n");
	for(i=1;i<=n;i++) {
		printf("   |     %d     |      %2d       |    %-3s    |   %-10s |      %d     |     %d    |\n",i, courant->nbPlaceMax, (courant->estReserveMatin==1 ? "Oui":"Non"), courant->nomMatin, courant->nbPersonneMatin, courant->numMenuMatin);
		courant=courant->suivant;
	}
	printf("   --------------------------------------------------------------------------------\n");
	printf("\n");
	
	courant=deb;	
	// Affichage
	
	printf("   |Soir|\n");	
	printf("   --------------------------------------------------------------------------------\n");
	printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
	printf("   --------------------------------------------------------------------------------\n");
	for(i=1;i<=n;i++) {
		printf("   |     %d     |      %2d       |    %-3s    |   %-10s |      %d     |     %d    |\n",i,courant->nbPlaceMax, (courant->estReserveSoir==1) ? "Oui":"Non", courant->nomSoir, courant->nbPersonneSoir, courant->numMenuSoir);
		courant=courant->suivant;
	}
	printf("   --------------------------------------------------------------------------------\n");
	printf("\n");
	
	free(courant);
	free(suivant);	
	fclose(fdat);	
	
}

void recupMenu() {
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
		
	// Affichage	
	printf("\n");	
	printf("   ------------------------------------------------------------------------------\n");
	printf("   |  N  |     Nom      |     Prix (Euro)  |         Description                |\n");
	printf("   ------------------------------------------------------------------------------\n");
	for(i=1;i<=n;i++) {
		
		for(j=0; j<strlen(courant->description); j++) {
			if(courant->description[j] == '_') {
				courant->description[j] = ' ';
			}
		}
		
		printf("   |  %d  |  %-10s  |      %5.2f       |  %-25s         |\n",i, courant->nom, courant->prix, courant->description);
		courant=courant->suivant;
	}
	printf("   ------------------------------------------------------------------------------\n");
	printf("\n");
	
	free(courant);
	free(suivant);	
	fclose(fdat);	
}

void recupEmployes() {
	int n=0, i;
	FILE *fdat;
	fdat = fopen("Data/Employes.dat", "r");

	Employe *deb, *courant, *suivant;
	courant=malloc(sizeof(Employe));
	deb=courant;

	// Lecture + Construction de ma liste chainée
	while(!feof(fdat)) {
		fscanf(fdat,"%s",&courant->nom);
		fscanf(fdat,"%d",&courant->service);
		fscanf(fdat,"%s",&courant->fonction);
		
		suivant=malloc(sizeof(Employe));
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
	printf("   Service - Midi : 12h00-15h00 - Soir : 18h00-23h00");	
	printf("\n");	
	printf("   ----------------------------------------------------\n");
	printf("   |  N  |     Nom      |   Service   |   Fonction    |\n");
	printf("   ----------------------------------------------------\n");
	for(i=1;i<=n;i++) {
		printf("   |  %d  |   %-10s |    %-6s   |   %-10s  |\n",i, courant->nom, (courant->service==1)?"Midi":(courant->service==2)?"Soir":"Aucun", courant->fonction);
		courant=courant->suivant;
	}
	printf("   ----------------------------------------------------\n");
	printf("\n");
	
	free(courant);
	free(suivant);	
	fclose(fdat);
}

void recupAdditionMidi() {
		
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
		
	courant=deb;	
	// Affichage
	printf("\n");
	printf("   |Midi|\n");	
	printf("   --------------------------------------------------------------------------------\n");
	printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
	printf("   --------------------------------------------------------------------------------\n");
	for(i=1;i<=n;i++) {
		printf("   |     %d     |      %2d       |    %-3s    |   %-10s |      %d     |     %d    |\n",i, courant->nbPlaceMax, (courant->estReserveMatin==1 ? "Oui":"Non"), courant->nomMatin, courant->nbPersonneMatin, courant->numMenuMatin);
		courant=courant->suivant;
	}
	printf("   --------------------------------------------------------------------------------\n");
	printf("\n");
	
	free(courant);
	free(suivant);	
	fclose(fdat);	
	
}

void recupAdditionSoir() {
	
	
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
	
	courant=deb;	
	// Affichage
	
	printf("   |Soir|\n");	
	printf("   --------------------------------------------------------------------------------\n");
	printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
	printf("   --------------------------------------------------------------------------------\n");
	for(i=1;i<=n;i++) {
		printf("   |     %d     |      %2d       |    %-3s    |   %-10s |      %d     |     %d    |\n",i,courant->nbPlaceMax, (courant->estReserveSoir==1) ? "Oui":"Non", courant->nomSoir, courant->nbPersonneSoir, courant->numMenuSoir);
		courant=courant->suivant;
	}
	printf("   --------------------------------------------------------------------------------\n");
	printf("\n");
	
	free(courant);
	free(suivant);	
	fclose(fdat);	
	
}

void recupTableReserveMidi() {
	
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
		
	courant=deb;	
	// Affichage
	printf("\n");
	printf("   |Midi|\n");	
	printf("   --------------------------------------------------------------------------------\n");
	printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
	printf("   --------------------------------------------------------------------------------\n");
	for(i=1;i<=n;i++) {
		if(courant->estReserveMatin==1) {
			printf("   |     %d     |      %2d       |    %-3s    |   %-10s |      %d     |     %d    |\n",i, courant->nbPlaceMax, (courant->estReserveMatin==1 ? "Oui":"Non"), courant->nomMatin, courant->nbPersonneMatin, courant->numMenuMatin);			
		}
		courant=courant->suivant;
	}
	printf("   --------------------------------------------------------------------------------\n");
	printf("\n");
	
	free(courant);
	free(suivant);	
	fclose(fdat);	
}

void recupTableReserveSoir() {
	
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
	
	courant=deb;	
	// Affichage
	printf("\n");
	printf("   |Soir|\n");	
	printf("   --------------------------------------------------------------------------------\n");
	printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
	printf("   --------------------------------------------------------------------------------\n");
	for(i=1;i<=n;i++) {
		if(courant->estReserveSoir==1) {
			printf("   |     %d     |      %2d       |    %-3s    |   %-10s |      %d     |     %d    |\n",i,courant->nbPlaceMax, (courant->estReserveSoir==1) ? "Oui":"Non", courant->nomSoir, courant->nbPersonneSoir, courant->numMenuSoir);
		
		}
		courant=courant->suivant;
	}
	printf("   --------------------------------------------------------------------------------\n");
	printf("\n");
	
	free(courant);
	free(suivant);	
	fclose(fdat);	
}

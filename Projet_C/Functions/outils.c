#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/structures.h"

int estReserve(int service, int numTable) {//Retourne un entier qui permet de savoir si la table est réservée ou non
	
	int n=0, i;

	FILE *fdat, *fdatTmp;
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

const char* nomMenuChoisi(int numMenu) {//Retourne le nom d'un menu précis
	static char nomMenuChoisi[21];
	
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

void remplaceMenuTable(int numMenu, int numTable, int service) {//change le menu d'une table précise
	
	int n=0, i;

	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/Table.dat", "r");
	fdatTmp = fopen("Data/Table.tmp", "w");

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

void selectTable(int numTable, int service) {//affiche une table précise
	
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
		nTable++;
		courant=suivant;
	}

	//Placer Null au suivant du dernière élément + libérer l'espace de suivant
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

int rechercheTableLibre(int service, int nbPersonne) {//recherche toutes les tables libres dans la liste des tables
	
	int n=0, i;

	FILE *fdat, *fdatTmp;
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
		
	// Recherche
	for(i=1;i<=n;i++) {		
	
		if(service==1 && nbPersonne<=courant->nbPlaceMax) {
			if(courant->estReserveMatin == 0) {
				fclose(fdat);
				return i;
			}			
		}
		else if(service==2 && nbPersonne<=courant->nbPlaceMax) {
			if(courant->estReserveSoir == 0) {
				fclose(fdat);
				return i;
			}		
		}	
		courant=courant->suivant;
	}
	fclose(fdat);
	return 0;
}

void remplaceNonReserveTable(int numTable, char nom[], int nbPersonne, int numMenu, int service) {//Effectue la réservation sur base des données entrée par l'utilisateur qui lui sont envoyées
		
	int n=0, i;

	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/Table.dat", "r");
	fdatTmp = fopen("Data/Table.tmp", "w");

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
	// Ecriture
	for(i=1;i<=n;i++) {	
				
		if(courant->estReserveMatin==1) {
			fprintf(fdatTmp, "%d ", courant->estReserveMatin);
			fprintf(fdatTmp, "%s %d %d ", courant->nomMatin, courant->nbPersonneMatin, courant->numMenuMatin);
			
		}
				
		if(courant->estReserveMatin==0) {
			if(numTable==i && service==1) {
				courant->estReserveMatin = 1;
				courant->nbPersonneMatin = nbPersonne;
				strcpy(courant->nomMatin, nom);
				courant->numMenuMatin = numMenu;
				fprintf(fdatTmp, "%d ", courant->estReserveMatin);
				fprintf(fdatTmp, "%s %d %d ", courant->nomMatin, courant->nbPersonneMatin, courant->numMenuMatin);
			}
			else {
				fprintf(fdatTmp, "%d ", courant->estReserveMatin);
			}
		}
			
		if(courant->estReserveSoir==1) {
			fprintf(fdatTmp, "%d ", courant->estReserveSoir);
			fprintf(fdatTmp, "%s %d %d", courant->nomSoir, courant->nbPersonneSoir, courant->numMenuSoir);		
		}
			
		if(courant->estReserveSoir==0) {
			if(numTable==i && service==2) {
				courant->estReserveSoir = 1;
				courant->nbPersonneSoir = nbPersonne;
				strcpy(courant->nomSoir, nom);
				courant->numMenuSoir = numMenu;
				fprintf(fdatTmp, "%d ", courant->estReserveSoir);
				fprintf(fdatTmp, "%s %d %d", courant->nomSoir, courant->nbPersonneSoir, courant->numMenuSoir);
			}
			else {
				fprintf(fdatTmp, "%d", courant->estReserveSoir);
			}		
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

void modifTableSuppRes(int service, int numTable) {//supprime une réservation sur une table précise
	int n=0, i;

	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/Table.dat", "r");
	fdatTmp = fopen("Data/Table.tmp", "w");

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
	// Ecriture
	for(i=1;i<=n;i++) {	
	
		if(courant->estReserveMatin==1) {
			if(i==numTable && service == 1) {
				courant->estReserveMatin=0;
				courant->nbPersonneMatin=0;
				strcpy(courant->nomMatin, "");
				courant->numMenuMatin = 0;	
			}			
		}
		
		fprintf(fdatTmp, "%d ", courant->estReserveMatin);		
		if(courant->estReserveMatin==1) {
			fprintf(fdatTmp, "%s %d %d ", courant->nomMatin, courant->nbPersonneMatin, courant->numMenuMatin);
		}
	
		if(courant->estReserveSoir==1) {
			if(i==numTable && service == 2) {
				courant->estReserveSoir=0;
				courant->nbPersonneSoir=0;
				strcpy(courant->nomSoir, "");
				courant->numMenuSoir = 0;	
			}			
		}
		
		fprintf(fdatTmp, "%d ", courant->estReserveSoir);		
		if(courant->estReserveSoir==1) {
			fprintf(fdatTmp, "%s %d %d", courant->nomSoir, courant->nbPersonneSoir, courant->numMenuSoir);
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

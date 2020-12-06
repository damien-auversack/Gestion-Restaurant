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

void supprimerTable() {
	
	int n=0, i, nTable=1, tableEntre;

	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/Table.dat", "r");
	fdatTmp = fopen("Data/Table.tmp", "w");
	
	recupTables();
	
	printf("   Supprimer une table : ");
	scanf("%d", &tableEntre);

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
		if(tableEntre != nTable) {
			suivant=malloc(sizeof(Table));
			courant->suivant=suivant;
			n++;
			courant=suivant;
		}
		nTable++;
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
			fprintf(fdatTmp, "%s %d %d ", courant->nomMatin, courant->nbPersonneMatin, courant->numMenuMatin);
		}
		
		fprintf(fdatTmp, "%d", courant->estReserveSoir);
		if(courant->estReserveSoir==1) {
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

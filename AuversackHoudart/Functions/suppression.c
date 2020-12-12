#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/structures.h"

void supprimerTable() { //supprime une table de la liste de tables
	
	int n=0, i, nTable=1, tableEntre;

	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/Table.dat", "r");
	fdatTmp = fopen("Data/Table.tmp", "w");
	afficherTablesSimple();
	recupTables();
	
	printf("   Supprimer une table : ");
	scanf("%d", &tableEntre);

	Table *deb, *courant, *suivant;
	courant=malloc(sizeof(Table));
	deb=courant;

	// Lecture + Construction de ma liste chainée
	while(!feof(fdat)) {
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
				
	// Ecriture
	if(compterTable()!=0) {
		courant=deb;

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
	}
		
	fclose(fdat);
	fclose(fdatTmp);
	if(compterTable()!=0) {
		remove("Data/Table.dat");		
		rename("Data/Table.tmp", "Data/Table.dat");
	}	
}

void supprimerMenu() { //Supprime un menu de la liste des menus
	int n=0, i, nMenu=1, menuEntre;
	
	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/Menu.dat", "r");
	fdatTmp = fopen("Data/Menu.tmp", "w");
	afficherMenuSimple();
	recupMenu();
	
	printf("   Supprimer un Menu : ");
	scanf("%d", &menuEntre);
	
	Menu *deb, *courant, *suivant;
	courant=malloc(sizeof(Menu));
	deb=courant;

	// Lecture + Construction de ma liste chainée
	while(!feof(fdat)) {
		fscanf(fdat,"%s",&courant->nom);
		fscanf(fdat,"%5f",&courant->prix);
		fscanf(fdat,"%s",&courant->description);
		if(menuEntre != nMenu) {
			suivant=malloc(sizeof(Menu));
			courant->suivant=suivant;
			n++;
			courant=suivant;
		}	
		nMenu++;	
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
		fprintf(fdatTmp, "%s %5.2f %s", courant->nom, courant->prix, courant->description);
		if(i!=n) {
			fprintf(fdatTmp, "\n");
		}
		courant=courant->suivant;
	}
		
	fclose(fdat);
	fclose(fdatTmp);
	remove("Data/Menu.dat");		
	rename("Data/Menu.tmp", "Data/Menu.dat");
}

void supprimerEmploye() {//supprime un employé de la liste	
	
	int n=0, i, nEmploye=1, employeEntre, testDigit;
	
	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/Employes.dat", "r");
	fdatTmp = fopen("Data/Employes.tmp", "w");
	system("cls");
	afficherGestionPersonnelSimple();
	recupEmployes();
	
	printf("   Supprimer un Employe : ");
	testDigit = scanf("%d", &employeEntre);
	
	Employe *deb, *courant, *suivant;
	courant=malloc(sizeof(Employe));
	deb=courant;

	// Lecture + Construction de ma liste chainée
	while(!feof(fdat)) {
		fscanf(fdat,"%s",&courant->nom);
		fscanf(fdat,"%d",&courant->service);
		fscanf(fdat,"%s",&courant->fonction);
		if(employeEntre != nEmploye) {
			suivant=malloc(sizeof(Employe));
			courant->suivant=suivant;
			n++;
			courant=suivant;
		}	
		nEmploye++;	
	}
	
	//Placer Null au suivant du dernière élément + libérer l'espace de suivant
	courant=deb;
	for(i=1;i<n;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;	
		
	courant=deb;	
	if(compterEmploye()!=0) {	
		// Ecriture
		for(i=1;i<=n;i++) {		
			fprintf(fdatTmp, "%s %d %s", courant->nom, courant->service, courant->fonction);
			if(i!=n) {
				fprintf(fdatTmp, "\n");
			}
			courant=courant->suivant;
		}
	} 	
	fclose(fdat);
	fclose(fdatTmp);
	if(compterEmploye()!=0) {
		remove("Data/Employes.dat");		
		rename("Data/Employes.tmp", "Data/Employes.dat");
	}
}

void supprimerReservation() { //Permet de supprimer une reservation sur une table
	
	int service, numTable, modifOk=0;
	erreurIndexService://gestion d'erreur
	system("cls");	
	afficherReservation();	
	recupTableReserveMidi();
	recupTableReserveSoir();
	
	printf("   Aviez-vous reserve a midi(1) ou au soir(2) ? ");
	scanf("%d", &service);
	if(service==1 && compterTableReservMatin()!=0) {
		erreurIndexNumTableMidi://gestion d'erreur
		system("cls");	
		afficherReservation();	
		recupTableReserveMidi();
		
		printf("   Quelle table aviez-vous reserve ? ");
		scanf("%d", &numTable);
		if(numTable<=0 || numTable > compterTable()) {
			viderBuffer();
			goto erreurIndexNumTableMidi;
		}
		modifOk = modifTableSuppRes(1, numTable);
		if(modifOk==1) {
			printf("\n   Suppression reussie !\n\n");
		}
		else {
			printf("\n   La reservation n\'existe pas !\n\n");
		}
	} 
	else if(service==2 && compterTableReservSoir()!=0) {
		erreurIndexNumTableSoir://gestion d'erreur
		system("cls");	
		afficherReservation();	
		recupTableReserveSoir();
		
		printf("   Quelle table aviez-vous reserve ? ");
		scanf("%d", &numTable);
		if(numTable<=0 || numTable > compterTable()) {
			viderBuffer();
			goto erreurIndexNumTableSoir;
		}
		modifOk = modifTableSuppRes(2, numTable);
		if(modifOk==1) {
			printf("\n   Suppression reussie !\n\n");
		}
		else {
			printf("\n   La reservation n\'existe pas !\n\n");
		}
	}
	else{
		viderBuffer();
		goto erreurIndexService;
	}
}

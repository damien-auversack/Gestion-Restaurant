#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/structures.h"

void ajouterTable() { //permet d'ajouter une table a la liste

	int testDigit=0, j;
	Table table;
	
	FILE *fdat;
	fdat = fopen("Data/Table.dat", "a");

	erreurIndiceNbPlaceMax: //gestion d'erreur
	// Ajout table
	system("cls");
	afficherTablesSimple();
	recupTables();
	printf("   Nombres de places a table : ");	
	testDigit = scanf("%d", &table.nbPlaceMax);
	if(table.nbPlaceMax<=0 || testDigit==0) {
		viderBuffer();
		goto erreurIndiceNbPlaceMax;
	}
	
	erreurEstReserveMatin: //gestion d'erreur
	system("cls");
	afficherTablesSimple();
	recupTables();	
	printf("   Table reserve le matin(oui=1/non=0) : ");	
	testDigit = scanf("%d", &table.estReserveMatin);
	if( (table.estReserveMatin != 0 && table.estReserveMatin != 1) || testDigit==0 ) {
		viderBuffer();
		goto erreurEstReserveMatin;
	}

	if(table.estReserveMatin==1) {
		
		system("cls");	
		afficherTablesSimple();
		recupTables();		
		printf("   Nom de la reservation : ");
		viderBuffer();
		fgets(table.nomMatin, 12, stdin);
		// remplace les ' ' par des '_' dans la chaine de caracteres
		for(j=0; j<strlen(table.nomMatin); j++) {
			if(table.nomMatin[j] == ' ') {
				table.nomMatin[j] = '_';
			}
			if(table.nomMatin[j] == '\n') {
				table.nomMatin[j] = '\0';
			}
		}
		
		erreurNbPlaceMaxMatin: //gestion d'erreur
		
		system("cls");	
		afficherTablesSimple();	
		recupTables();		
		printf("   Nombre de personne a table : ");
		testDigit = scanf("%d", &table.nbPersonneMatin);
				
		if(table.nbPersonneMatin > table.nbPlaceMax || table.nbPersonneMatin<=0 || testDigit==0) {
			viderBuffer();
			goto erreurNbPlaceMaxMatin;
		}
		
		erreurNumMenuMatin: //gestion d'erreur
		
		system("cls");	
		afficherTablesSimple();	
		recupTables();		
		printf("   Numero du menu choisi : ");
		testDigit = scanf("%d", &table.numMenuMatin);
		
		if(table.numMenuMatin<=0 || table.numMenuMatin>compterMenu() || testDigit==0) {
			viderBuffer();
			goto erreurNumMenuMatin;
		}
	}
	erreurEstReserveSoir: //gestion d'erreur
	system("cls");
	afficherTablesSimple();
	recupTables();
	printf("   Table reserve le soir(oui=1/non=0) : ");
	testDigit = scanf("%d", &table.estReserveSoir);
	if( (table.estReserveSoir != 0 && table.estReserveSoir != 1) || testDigit==0 ) {
		viderBuffer();
		goto erreurEstReserveSoir;
	}
	
	if(table.estReserveSoir==1) {
		
		system("cls");
		afficherTablesSimple();	
		recupTables();		
		printf("   Nom de la reservation : ");
		viderBuffer();
		fgets(table.nomSoir, 12, stdin);
		// remplace les ' ' par des '_' dans la chaine de caracteres
		for(j=0; j<strlen(table.nomSoir); j++) {
			if(table.nomSoir[j] == ' ') {
				table.nomSoir[j] = '_';
			}
			if(table.nomSoir[j] == '\n') {
				table.nomSoir[j] = '\0';
			}
		}
		
		erreurNbPlaceMaxSoir: //gestion d'erreur
		
		system("cls");	
		afficherTablesSimple();	
		recupTables();		
		printf("   Nombre de personne a table : ");
		testDigit = scanf("%d", &table.nbPersonneSoir);
		
		if(table.nbPersonneSoir > table.nbPlaceMax || table.nbPersonneSoir<=0 || testDigit==0) {
			viderBuffer();
			goto erreurNbPlaceMaxSoir;
		}
		
		erreurNumMenuSoir: //gestion d'erreur
			
		system("cls");	
		afficherTablesSimple();	
		recupTables();
				
		printf("   Numero du menu choisi : ");
		testDigit = scanf("%d", &table.numMenuSoir);
		
		if(table.numMenuSoir<=0 || table.numMenuSoir>compterMenu() || testDigit==0) {
			viderBuffer();
			goto erreurNumMenuSoir;
		}
		
	}
	if(compterTable()!=0) {
		fprintf(fdat, "\n");
	}	
	fprintf(fdat, "%d ", table.estReserveMatin);
	if(table.estReserveMatin==1) {
		table.nbPersonneSoir = table.numMenuSoir = 0;
		fprintf(fdat, "%12s %d %d ", table.nomMatin, table.nbPersonneMatin, table.numMenuMatin);
	}
	
	fprintf(fdat, "%d", table.estReserveSoir);
	if(table.estReserveSoir==1) {
		table.nbPersonneMatin = table.numMenuMatin = 0;
		fprintf(fdat, " %12s %d %d", table.nomSoir, table.nbPersonneSoir, table.numMenuSoir);
	}
	fprintf(fdat, " %d", table.nbPlaceMax);
	fclose(fdat);	
}

void ajouterMenu() { //permet d'ajouter un menu
	int j, erreurAvecEspace=0;
	Menu menu;
	
	FILE *fdat;
	fdat = fopen("Data/Menu.dat", "a");
	afficherMenuSimple();
	recupMenu();
	
	printf("   Nom du Menu : ");
	
	viderBuffer();
	fgets(menu.nom, 12, stdin);
	// remplace les ' ' par des '_' dans la chaine de caracteres
	for(j=0; j<strlen(menu.nom); j++) {
		if(menu.nom[j] == ' ') {
			erreurAvecEspace=1;
			menu.nom[j] = '_';
		}
		if(menu.nom[j] == '\n') {
			menu.nom[j] = '\0';
		}
	}
	
	if(erreurAvecEspace==1) {
		viderBuffer();
	}
		
	system("cls");
	afficherMenuSimple();
	recupMenu();	
	printf("   Prix du Menu : ");
		
	scanf("%5f", &menu.prix);
	system("cls");
	afficherMenuSimple();
	recupMenu();
	printf("   Description du Menu : ");
	viderBuffer();
	fgets(menu.description, 34, stdin);

	// remplace les ' ' par des '_' dans la chaine de caracteres
	for(j=0; j<strlen(menu.description); j++) {
		if(menu.description[j] == ' ') {
			menu.description[j] = '_';
		}
		if(menu.description[j] == '\n') {
			menu.description[j] = '\0';
		}
	}
	
	if(compterMenu()!=0) {
		fprintf(fdat, "\n");
	}
	
	fprintf(fdat, "%s %5.2f %s", menu.nom, menu.prix, menu.description);
	
	fclose(fdat);	
}

void ajouterEmploye() {
	int j, testDigit;
	Employe employe;
	
	FILE *fdat;
	fdat = fopen("Data/Employes.dat", "a");
	
	afficherGestionPersonnelSimple();
	recupEmployes();
		
	printf("   Nom de l'employe : ");
	
	viderBuffer();
	fgets(employe.nom, 12, stdin);
	// remplace les ' ' par des '_' dans la chaine de caracteres
	for(j=0; j<strlen(employe.nom); j++) {
		if(employe.nom[j] == ' ') {
			employe.nom[j] = '_';
		}
		if(employe.nom[j] == '\n') {
			employe.nom[j] = '\0';
		}
	}
	erreurServiceEmploye:
	system("cls");
	afficherGestionPersonnelSimple();
	recupEmployes();	
	printf("   Service de l'employe midi(1), soir(2) : ");
	testDigit = scanf("%1d", &employe.service);
	if(testDigit==0 || (employe.service != 1 && employe.service != 2)) {
		viderBuffer();
		goto erreurServiceEmploye;
	}
	
	system("cls");
	afficherGestionPersonnelSimple();
	recupEmployes();
	printf("   Fonction de l'employe : ");
	viderBuffer();
	fgets(employe.fonction, 15, stdin);

	// remplace les ' ' par des '_' dans la chaine de caracteres
	for(j=0; j<strlen(employe.fonction); j++) {
		if(employe.fonction[j] == ' ') {
			employe.fonction[j] = '_';
		}
		if(employe.fonction[j] == '\n') {
			employe.fonction[j] = '\0';
		}
	}

	if(compterEmploye()!=0) {
		fprintf(fdat, "\n");
	}

	fprintf(fdat, "%s %d %s", employe.nom, employe.service, employe.fonction);
	
	fclose(fdat);	
	
}

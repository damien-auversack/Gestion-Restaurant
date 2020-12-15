#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/AuversackHoudart_structures.h"

int estReserve(int service, int numTable) { //Retourne un entier qui permet de savoir si la table est reservee ou non
	
	int n=0, i;

	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/AuversackHoudart_Table.dat", "r");

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

const char* nomMenuChoisi(int numMenu) { //Retourne le nom d'un menu precis
	static char nomMenuChoisi[21];
	
	int n=0, i, j;
	FILE *fdat;
	fdat = fopen("Data/AuversackHoudart_Menu.dat", "r");

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
		
		for(j=0; j<strlen(courant->nom); j++) {
			if(courant->nom[j] == '_') {
				courant->nom[j] = ' ';
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

void remplaceMenuTable(int numMenu, int numTable, int service) { //change le menu d'une table precise
	
	int n=0, i;

	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/AuversackHoudart_Table.dat", "r");
	fdatTmp = fopen("Data/AuversackHoudart_Table.tmp", "w");

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
	remove("Data/AuversackHoudart_Table.dat");		
	rename("Data/AuversackHoudart_Table.tmp", "Data/AuversackHoudart_Table.dat");	
}

void selectTable(int numTable, int service) { //affiche une table precise
	
	int nbPlaceMaxSelect, reserveSelect, nbPersonneSelect, numMenuSelect, nTable=0, i, j;
	char nomPersonneSelect[21];
		
	// Traitement table
	FILE *fdat;
	fdat = fopen("Data/AuversackHoudart_Table.dat", "r");

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
		printf("   |     %d     |      %2d       |    %-3s    |  %-12s|      %d     |     %d    |\n",numTable, nbPlaceMaxSelect, (reserveSelect ? "Oui":"Non"), nomPersonneSelect, nbPersonneSelect, numMenuSelect);
		printf("   --------------------------------------------------------------------------------\n\n");		
	}
	else if(service==2) {
		printf("\n");
		printf("   |Table|\n");
		printf("   --------------------------------------------------------------------------------\n");
		printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
		printf("   --------------------------------------------------------------------------------\n");
		printf("   |     %d     |      %2d       |    %-3s    |  %-12s|      %d     |     %d    |\n",numTable, nbPlaceMaxSelect, (reserveSelect ? "Oui":"Non"), nomPersonneSelect, nbPersonneSelect, numMenuSelect);
		printf("   --------------------------------------------------------------------------------\n\n");
	}
}

void selectEmploye(int numEmploye) { //affiche un employe precis

	int serviceSelect, nEmploye=0, i, j;
	char nomEmployeSelect[21], nomFonctionSelect[15];
		
	// Traitement table
	FILE *fdat;
	fdat = fopen("Data/AuversackHoudart_Employes.dat", "r");

	Employe *deb, *courant, *suivant;
	courant=malloc(sizeof(Employe));
	deb=courant;

	// Lecture + Construction de ma liste chainée
	while(!feof(fdat)) {
		
		// Initialisation
		strcpy(courant->nom, "");
		courant->service = 0;
		strcpy(courant->fonction, "");
		
		fscanf(fdat,"%s",&courant->nom);
		fscanf(fdat,"%d",&courant->service);
		fscanf(fdat,"%s",&courant->fonction);
					
		suivant=malloc(sizeof(Employe));
		courant->suivant=suivant;
		nEmploye++;
		courant=suivant;
	}

	//Placer Null au suivant du dernière élément + libérer l'espace de suivant
	courant=deb;
	for(i=1;i<nEmploye;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;	
		
	courant=deb;	
	// Affichage
	for(i=1;i<=nEmploye;i++) {
		if(i==numEmploye) {	
			strcpy(nomEmployeSelect, courant->nom);
			serviceSelect = courant->service;
			strcpy(nomFonctionSelect, courant->fonction);					
		}
		courant=courant->suivant;
	}
	
	free(courant);
	free(suivant);	
	fclose(fdat);
		
	// Affichage	

	printf("\n");
	printf("   Service - Midi : 12h00-15h00 - Soir : 18h00-23h00");	
	printf("\n");
	printf("\n");
	printf("   |Employe|\n");	
	printf("   ----------------------------------------------------\n");
	printf("   |  N  |     Nom      |   Service   |   Fonction    |\n");
	printf("   ----------------------------------------------------\n");
	printf("   |  %d  |   %-10s |    %-6s   |   %-10s  |\n",numEmploye, nomEmployeSelect, (serviceSelect==1)?"Midi":(serviceSelect==2)?"Soir":"Aucun", nomFonctionSelect);	
	printf("   ----------------------------------------------------\n");
	printf("\n");
}

int rechercheTableLibre(int service, int nbPersonne) { //recherche toutes les tables libres dans la liste des tables
	
	int n=0, i;

	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/AuversackHoudart_Table.dat", "r");

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

int remplaceNonReserveTable(int numTable, char nom[], int nbPersonne, int numMenu, int service) { //Effectue la reservation sur base des donnees entree par l'utilisateur qui lui sont envoyees
		
	int n=0, i, reservOk=0;

	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/AuversackHoudart_Table.dat", "r");
	fdatTmp = fopen("Data/AuversackHoudart_Table.tmp", "w");

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
				reservOk = 1;
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
				reservOk = 1;
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
	remove("Data/AuversackHoudart_Table.dat");		
	rename("Data/AuversackHoudart_Table.tmp", "Data/AuversackHoudart_Table.dat");	
	return reservOk;
}

int modifTableSuppRes(int service, int numTable) { //supprime une reservation sur une table precise
	int n=0, i, modifOk=0;

	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/AuversackHoudart_Table.dat", "r");
	fdatTmp = fopen("Data/AuversackHoudart_Table.tmp", "w");

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
				modifOk=1;
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
				modifOk=1;
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
	remove("Data/AuversackHoudart_Table.dat");		
	rename("Data/AuversackHoudart_Table.tmp", "Data/AuversackHoudart_Table.dat");	
	return modifOk;
}

void viderBuffer() {//vide le buffer, aide principalement à la gestion d'erreur lorsque des lettres sont entrée à la place des chiffres
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void modifierService(int numEmploye, int newService) {//modifie le service d'un employé
	int n=0, i;
	
	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/AuversackHoudart_Employes.dat", "r");
	fdatTmp = fopen("Data/AuversackHoudart_Employes.tmp", "w");
	
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
		
	// Ecriture
	for(i=1;i<=n;i++) {	
		if(i==numEmploye) {
			courant->service = newService;
		}
		fprintf(fdatTmp, "%s %d %s", courant->nom, courant->service, courant->fonction);
		if(i!=n) {
			fprintf(fdatTmp, "\n");
		}
		courant=courant->suivant;
	}
		
	fclose(fdat);
	fclose(fdatTmp);
	remove("Data/AuversackHoudart_Employes.dat");		
	rename("Data/AuversackHoudart_Employes.tmp", "Data/AuversackHoudart_Employes.dat");
}

void modifierFonction(int numEmploye, char nomFonction[]) {//modifie la fonction d'un employé
	int n=0, i;
	
	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/AuversackHoudart_Employes.dat", "r");
	fdatTmp = fopen("Data/AuversackHoudart_Employes.tmp", "w");
	
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
		
	// Ecriture
	for(i=1;i<=n;i++) {	
		if(i==numEmploye) {
			strcpy(courant->fonction, nomFonction);
		}
		fprintf(fdatTmp, "%s %d %s", courant->nom, courant->service, courant->fonction);
		if(i!=n) {
			fprintf(fdatTmp, "\n");
		}
		courant=courant->suivant;
	}
		
	fclose(fdat);
	fclose(fdatTmp);
	remove("Data/AuversackHoudart_Employes.dat");		
	rename("Data/AuversackHoudart_Employes.tmp", "Data/AuversackHoudart_Employes.dat");
}

void modifierNomEmploye(int numEmploye, char nomEmploye[]) {//modifie le nom de l'employé
	int n=0, i;
	
	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/AuversackHoudart_Employes.dat", "r");
	fdatTmp = fopen("Data/AuversackHoudart_Employes.tmp", "w");
	
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
		
	// Ecriture
	for(i=1;i<=n;i++) {	
		if(i==numEmploye) {
			strcpy(courant->nom, nomEmploye);
		}
		fprintf(fdatTmp, "%s %d %s", courant->nom, courant->service, courant->fonction);
		if(i!=n) {
			fprintf(fdatTmp, "\n");
		}
		courant=courant->suivant;
	}
		
	fclose(fdat);
	fclose(fdatTmp);
	remove("Data/AuversackHoudart_Employes.dat");		
	rename("Data/AuversackHoudart_Employes.tmp", "Data/AuversackHoudart_Employes.dat");
}

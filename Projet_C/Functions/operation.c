#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/structures.h"

void FaireAddition(int tableAddition, int service) { //calcule l'addition d'une table en fonction de son menu
		
	int nbPlaceMaxSelect, reserveSelect, nbPersonneSelect, numMenuSelect;
	float sommeAddition, prixSelect;
	char nomPersonneSelect[21], nomMenuSelect[21], descriptionSelect[40];
	
	// Traitement table
	int nTable=0, nMenu=0, i, j;
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

	// Lecture + Construction de ma liste chainée
	while(!feof(fdat)) {
		fscanf(fdat2,"%s",&courant2->nom);
		fscanf(fdat2,"%5f",&courant2->prix);
		fscanf(fdat2,"%s",&courant2->description);
		suivant2=malloc(sizeof(Menu));
		courant2->suivant=suivant2;
		nMenu++;
		courant2=suivant2;
	}

	//Placer Null au suivant du dernière élément + libérer l'espace de suivant
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
	
	//affichage de l'addition d'une table
	sommeAddition = prixSelect * nbPersonneSelect;
	system("cls");	
	printf("\n");
	printf("   ********************************************");
	printf("\n");
	printf("                 _     _ _ _   _             \n");
	printf("        /\\      | |   | (_) | (_)            \n");
	printf("       /  \\   __| | __| |_| |_ _  ___  _ __  \n");
	printf("      / /\\ \\ / _` |/ _` | | __| |/ _ \\| '_ \\ \n");
	printf("     / ____ \\ (_| | (_| | | |_| | (_) | | | |\n");
	printf("    /_/    \\_\\__,_|\\__,_|_|\\__|_|\\___/|_| |_|\n");
	printf("\n");
	printf("   ********************************************");
	printf("\n");
	printf("\n");
	if(service==1) {
		
		printf("   |Table|\n");
		printf("   --------------------------------------------------------------------------------\n");
		printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
		printf("   --------------------------------------------------------------------------------\n");
		printf("   |     %d     |      %2d       |    %-3s    |  %-12s|      %d     |     %d    |\n",tableAddition, nbPlaceMaxSelect, (reserveSelect ? "Oui":"Non"), nomPersonneSelect, nbPersonneSelect, numMenuSelect);
		printf("   --------------------------------------------------------------------------------\n\n");
		printf("   |Menu|\n");	
		printf("   ------------------------------------------------------------------------------\n");
		printf("   |  N  |     Nom      |     Prix (Euro)  |         Description                |\n");
		printf("   ------------------------------------------------------------------------------\n");
		printf("   |  %d  |  %-12s|      %5.2f       |  %-34s|\n",numMenuSelect, nomMenuSelect, prixSelect, descriptionSelect);
		printf("   ------------------------------------------------------------------------------\n");
		
	}
	else if(service==2) {
		printf("   |Table|\n");
		printf("   --------------------------------------------------------------------------------\n");
		printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
		printf("   --------------------------------------------------------------------------------\n");
		printf("   |     %d     |      %2d       |    %-3s    |  %-12s|      %d     |     %d    |\n",tableAddition, nbPlaceMaxSelect, (reserveSelect ? "Oui":"Non"), nomPersonneSelect, nbPersonneSelect, numMenuSelect);
		printf("   --------------------------------------------------------------------------------\n\n");
		printf("   |Menu|\n");	
		printf("   ------------------------------------------------------------------------------\n");
		printf("   |  N  |     Nom      |     Prix (Euro)  |         Description                |\n");
		printf("   ------------------------------------------------------------------------------\n");
		printf("   |  %d  |  %-12s|      %5.2f       |  %-34s|\n",numMenuSelect, nomMenuSelect, prixSelect, descriptionSelect);
		printf("   ------------------------------------------------------------------------------\n");
	}
	printf("\n   |Addition|\n");
	printf("   ------------------------------------------------\n");
	printf("   |  L'addition de la table %d est de %5.2f Euro  |\n", tableAddition, sommeAddition);
	printf("   ------------------------------------------------\n");
	
	erreurTailleTable: //gestion d'erreur
	
	free(courant2);
	free(suivant2);	
	fclose(fdat2);		
}

void changerCommande() { //permet de changer le menu commander par une table en utilisant remplaceMenuTable
	int service, numTable, numMenuChoisi;
	
	erreurIndexService: //gestion d'erreur
	
	system("cls");	
	afficherChangerCommande();
	recupTableReserveMidi();
	recupTableReserveSoir();
	
	printf("   Service (Midi=1/Soir=2) : ");
	scanf("%d", &service);
	if(service != 1 && service != 2) {
		viderBuffer();
		goto erreurIndexService;
	}
	if(service == 1 && compterTableReservMatin()==0) {
		viderBuffer();
		goto erreurIndexService;
	}
	if(service == 2 && compterTableReservSoir()==0) {
		viderBuffer();
		goto erreurIndexService;
	}

	erreurTableNonReserve: //gestion d'erreur
	system("cls");
	
	afficherChangerCommande();
	if(service==1) {		
		recupTableReserveMidi();
		printf("   Numero de votre table : ");
		scanf("%d", &numTable);
		if(estReserve(1, numTable)==0) {
			viderBuffer();
			goto erreurTableNonReserve;
		}
		erreurIndexNumMenuMidi: //gestion d'erreur
		system("cls");
		afficherChangerCommande();
		selectTable(numTable, 1);
		printf("   |Menu|");
		recupMenu();
		printf("   Quel menu voulez vous ? : ");
		scanf("%d", &numMenuChoisi);
		if(numMenuChoisi<=0 || numMenuChoisi > compterMenu()) {
			viderBuffer();
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
			viderBuffer();
			goto erreurTableNonReserve;
		}
		erreurIndexNumMenuSoir: //gestion d'erreur
		system("cls");
		afficherChangerCommande();
		selectTable(numTable, 2);
		printf("   |Menu|");
		recupMenu();
		printf("   Quel menu voulez vous ? : ");
		scanf("%d", &numMenuChoisi);
		if(numMenuChoisi<=0 || numMenuChoisi > compterMenu()) {
			viderBuffer();
			goto erreurIndexNumMenuSoir;
		}
		printf("\n");
		remplaceMenuTable(numMenuChoisi, numTable, service);
		printf("   Vous avez choisi le menu : %s\n\n", nomMenuChoisi(numMenuChoisi));
	}	
}

void faireReservation() { //Permet de reserver une table libre
	int service, nbPersonne, numMenu;
	char nom[21];
	
	erreurIndexService: //gestion d'erreur
		
	system("cls");	
	afficherReservation();	
	recupTableLibreMidi();
	recupTableLibreSoir();
	
	printf("\n");
	printf("   Service (Midi=1/Soir=2) : ");
	scanf("%d", &service);
	if(service != 1 && service != 2) {
		viderBuffer();
		goto erreurIndexService;
	}
	
	system("cls");
	afficherReservation();	
	
	if(service==1) {
		recupTableLibreMidi();
		printf("   Nom de la reservation : ");
		scanf("%s", &nom);
		
		erreurIndexnbPersonne: //gestion d'erreur
		
		system("cls");
		afficherReservation();	
		recupTableLibreMidi();
		printf("   Nombre de personnes : ");
		scanf("%d", &nbPersonne);
		if(nbPersonne<=0) {
			viderBuffer();
			goto erreurIndexnbPersonne;
		}
		
		erreurIndexNumMenuMidi: //gestion d'erreur
		
		system("cls");
		afficherReservation();	
		recupTableLibreMidi();
		printf("   |Menu|");
		recupMenu();
		printf("   Numero du menu : ");
		scanf("%d", &numMenu);
		if(numMenu<=0 || numMenu > compterMenu()) {
			viderBuffer();
			goto erreurIndexNumMenuMidi;
		}
		remplaceNonReserveTable(rechercheTableLibre(1, nbPersonne), nom, nbPersonne, numMenu, 1);
	}
	else if(service==2) {
		recupTableLibreSoir();
		printf("   Nom de la reservation : ");
		scanf("%s", &nom);
		
		system("cls");
		afficherReservation();	
		recupTableLibreSoir();
		printf("   Nombre de personnes : ");
		scanf("%d", &nbPersonne);
		
		erreurIndexNumMenuSoir: //gestion d'erreur
		
		system("cls");
		afficherReservation();	
		recupTableLibreSoir();
		printf("   |Menu|");
		recupMenu();
		printf("   Numero du menu : ");
		scanf("%d", &numMenu);
		if(numMenu<=0 || numMenu > compterMenu()) {
			viderBuffer();
			goto erreurIndexNumMenuSoir;
		}
		remplaceNonReserveTable(rechercheTableLibre(2, nbPersonne), nom, nbPersonne, numMenu, 2);
	}
}

void modifierEmploye() {
	
	int numEmploye, choixModif, serviceModif, testDigit;	
	char fonctionModif[21], nomModif[21];
	
	erreurSelectEmploye:
	system("cls");
	
	afficherGestionPersonnelSimple();
	recupEmployes();
	printf("   Selectionner un employe : ");
	testDigit = scanf("%d", &numEmploye);
	if(testDigit==0 || numEmploye<=0 || numEmploye>compterEmploye()) {
		viderBuffer();
		goto erreurSelectEmploye;
	}
	erreurChoixModif:
	system("cls");
	afficherGestionPersonnelSimple();
	selectEmploye(numEmploye);
	
	printf("   1. Modifier le nom\n");
	printf("   2. Modifier le service\n");
	printf("   3. Modifier la fonction\n\n");
	printf("   Choix : ");
	testDigit = scanf("%d", &choixModif);
	if(testDigit==0 || choixModif<=0 || choixModif>3) {
		viderBuffer();
		goto erreurChoixModif;
	}
	if(choixModif==1) {
		system("cls");
		afficherGestionPersonnelSimple();
		selectEmploye(numEmploye);
		printf("   Nom de l\'employe : ");
		scanf("%s", &nomModif);
		//Modifier le nom de l'employe
		modifierNomEmploye(numEmploye, nomModif);
		printf("\n\n   Modification reussie !");
	}
	else if(choixModif==2) {
		erreurServiceModif:
		system("cls");
		afficherGestionPersonnelSimple();
		selectEmploye(numEmploye);
		printf("   Service du midi(1), service du soir(2) : ");
		testDigit = scanf("%d", &serviceModif);
		if(testDigit==0 || serviceModif<=0 || serviceModif>2) {
			viderBuffer();
			goto erreurServiceModif;
		}
		//Modifier Service
		modifierService(numEmploye, serviceModif);
		printf("\n\n   Modification reussie !");
	}
	else if(choixModif==3) {
		system("cls");
		afficherGestionPersonnelSimple();
		selectEmploye(numEmploye);
		printf("   Nom de la fonction : ");
		scanf("%s", &fonctionModif);
		//Modifier fonction
		modifierFonction(numEmploye, fonctionModif);
		printf("\n\n   Modification reussie !");
	}
	else {
		
	}
	
}

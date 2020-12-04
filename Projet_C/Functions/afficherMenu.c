#include <stdio.h>
#include <stdlib.h>

typedef struct Menu {
	char nom[21];
	struct Menu *suivant;
}Menu;

void afficherMenu() {
	int n=0, i;
	FILE *fdat;
	fdat = fopen("Data/Menu.dat", "r");

	Menu *deb, *courant, *suivant;
	courant=malloc(sizeof(Menu));
	deb=courant;

	// Lecture + Construction de ma liste chainée
	while(!feof(fdat)) {
		fscanf(fdat,"%s",&courant->nom);
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
	printf("Menu des plats\n");
	printf("**************\n");
	for(i=1;i<=n;i++) {
		printf("%d : %s\n",i, courant->nom);
		courant=courant->suivant;
	}
	
	free(courant);
	free(suivant);	
	fclose(fdat);	
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Menu {
	char nom[21];
	struct Menu *suivant;
}Menu;

void supprimerMenu() {
	int n=0, i, nMenu=1, menuEntre;
	
	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/Menu.dat", "r");
	fdatTmp = fopen("Data/Menu.tmp", "w");
	
	recupMenu();
	
	printf("   Supprimer un Menu : ");
	scanf("%d", &menuEntre);
		
	Menu *deb, *courant, *suivant;
	courant=malloc(sizeof(Menu));
	deb=courant;

	// Lecture + Construction de ma liste chainée
	while(!feof(fdat)) {
		fscanf(fdat,"%s",&courant->nom);
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
		fprintf(fdatTmp, "%s", courant->nom);
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

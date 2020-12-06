#include <stdio.h>
#include <stdlib.h>

typedef struct Menu {
	char nom[21];
}Menu;

void ajouterMenu() {
	Menu menu;
	
	FILE *fdat;
	fdat = fopen("Data/Menu.dat", "a");
	
	recupMenu();
	
	printf("   Ajouter un Menu : ");
	scanf("%s", &menu.nom);
	
	fprintf(fdat, "\n%s", menu.nom);
	
	fclose(fdat);	
}

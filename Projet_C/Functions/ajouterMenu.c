#include <stdio.h>

void ajouterMenu() {
	char menu[21];
	
	FILE *fdat;
	fdat = fopen("Data/Menu.dat", "a");
	
	printf("Ajouter un Menu : ");
	scanf("%s", &menu);
	
	fprintf(fdat, "\n%s", menu);
	
	fclose(fdat);	
}

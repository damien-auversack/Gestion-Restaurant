#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers/affichage.h"
#include "Headers/ajout.h"
#include "Headers/suppression.h"
#include "Headers/recuperation.h"
#include "Headers/operation.h"
#include "Headers/compter.h"

main() {
	// Paramètre Fenêtre
		system("title Gestion Restaurant");	// Défini un titre à ma fenêtre
		system("mode con: cols=110 lines=40"); // Défini la taille de ma fenêtre	
	// Fin Paramètre Fenêtre
	
	int choix=0;
	int choixGestionPersonnel=0;
	int choixServices=0;
	int choixMenu=0;
	int choixTables=0;
	int choixAddition=0;
	int tableAddition=0;
	
	while(1) { // Ecran Principal
		system("cls");	
		afficherEcranPrincipal();	
		scanf("%d", &choix);			
		
		switch(choix) {
			case 1: // Gestion du personnel
				while(1) {
					system("cls");	
					afficherGestionPersonnel();
					scanf("%d", &choixGestionPersonnel);
					if(choixGestionPersonnel==0) break;
				}			
				break;
				
			case 2: // Services
				while(1) {
					system("cls");	
					afficherServices();
					scanf("%d", &choixServices);
					switch(choixServices) {
						case 1:
							break;
						case 2: // Services -> 2. Changer ma commande				
							system("cls");							
							changerCommande();
							system("pause");														
							break;
						case 3: // Services -> 3. Addition
							while(1) {
								system("cls");
								afficherAddition();
								scanf("%d", &choixAddition);
								switch(choixAddition) {
									case 1: 								
										system("cls");
										afficherAdditionMidi();
										scanf("%d", &tableAddition);
										FaireAddition(tableAddition, 1);
										system("pause");												
										break;
									case 2: 								
										system("cls");
										afficherAdditionSoir();
										scanf("%d", &tableAddition);	
										FaireAddition(tableAddition, 2);	
										system("pause");		
										break;
								}
								if(choixAddition==0) break;
							}
							break;
						case 4: // Services -> 4. Gestion des tables
							while(1) {
								system("cls");
								afficherTables();
								scanf("%d", &choixTables);
								switch(choixTables) {
									case 1: // ajouter Table
										system("cls");
										//ajouterTable();
										break;
									case 2: // supprimer Table
										system("cls");
										//supprimerTable();
										break;
								}
								if(choixTables==0) break;
							}
							break;
						case 5: // Services -> 5. Gestion du menu
							while(1) {
								system("cls");
								afficherMenu();
								scanf("%d", &choixMenu);
								switch(choixMenu) {
									case 1: // ajouter Menu
										system("cls");
										ajouterMenu();
										break;
									case 2: // supprimer Menu
										system("cls");
										supprimerMenu();
										break;
								}
								if(choixMenu==0) break;
							}						
							break;	
					}
					if(choixServices==0) break;
				}
				break;
		}
		if(choix==0) break;
	}
	
}

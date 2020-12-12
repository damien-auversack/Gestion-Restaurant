#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers/AuversackHoudart_affichage.h"
#include "Headers/AuversackHoudart_ajout.h"
#include "Headers/AuversackHoudart_suppression.h"
#include "Headers/AuversackHoudart_recuperation.h"
#include "Headers/AuversackHoudart_operation.h"
#include "Headers/AuversackHoudart_compter.h"

main() {
	// Paramètre Fenêtre
		system("title Gestion Restaurant");	// Défini un titre à ma fenêtre
		system("mode con: cols=120 lines=50"); // Défini la taille de ma fenêtre	
	// Fin Paramètre Fenêtre
	
	int choix=0, choixGestionPersonnel=0, choixServices=0, choixMenu=0, choixTables=0, choixAddition=0, tableAddition=0, choixReservation=0, testDigit;
	
	while(1) { // Ecran Principal
		erreurEcranPrincipal://gestion d'erreur
		system("cls");	
		afficherEcranPrincipal();	
		testDigit = scanf("%d", &choix);			
		if(testDigit==0) {
			viderBuffer();
			goto erreurEcranPrincipal;
		}
		switch(choix) {
			case 1: // Gestion du personnel
				while(1) {
					erreurGestionPersonnel://gestion d'erreur
					system("cls");	
					afficherGestionPersonnel();
					testDigit = scanf("%d", &choixGestionPersonnel);
					if(testDigit==0) {
						viderBuffer();
						goto erreurGestionPersonnel;
					}	
					switch(choixGestionPersonnel) {
						case 1:
							system("cls");
							ajouterEmploye();
							break;
						case 2:
							system("cls");
							supprimerEmploye();
							break;
						case 3:
							system("cls");
							if(compterEmploye()!=0) {
								modifierEmploye();
								system("pause");	
							}							
							break;	
					}			
					if(choixGestionPersonnel==0) break;
				}			
				break;
				
			case 2: // Services
				while(1) {
					erreurServices://gestion d'erreur
					system("cls");	
					afficherServices();
					testDigit = scanf("%d", &choixServices);
					if(testDigit==0) {
						viderBuffer();
						goto erreurServices;
					}
					switch(choixServices) {
						case 1: // Services -> 1. Faire une reservation	
							while(1) {
								erreurReservationOptions://gestion d'erreur
								system("cls");
								afficherReservationOptions();
								
								testDigit = scanf("%d", &choixReservation);
								if(testDigit==0) {
									viderBuffer();
									goto erreurReservationOptions;
								}
								switch(choixReservation) {
									case 1:
										system("cls");	
										faireReservation();
										system("pause");
										break;
									case 2:
										system("cls");	
										if(compterTableReservMatin()!=0 || compterTableReservSoir()!=0) {
											supprimerReservation();
											system("pause");	
										}
										break;
								}
								if(choixReservation==0) break;																	
							}
							break;																								
						case 2: // Services -> 2. Changer ma commande				
							system("cls");		
							if(compterTableReservSoir()!=0 || compterTableReservSoir()!=0) {
								changerCommande();
								system("pause");
							}																			
							break;
						case 3: // Services -> 3. Addition
							while(1) {
								erreurChoixAddition://gestion d'erreur
								system("cls");
								afficherAddition();
								testDigit = scanf("%d", &choixAddition);
								if(testDigit==0) {
									viderBuffer();
									goto erreurChoixAddition;
								}
								switch(choixAddition) {
									case 1: 			
										erreurAdditionMidi://gestion d'erreur				
										system("cls");
										afficherAdditionMidi();
										testDigit = scanf("%d", &tableAddition);
										if(testDigit==0) {
											viderBuffer();
											goto erreurAdditionMidi;
										}
										FaireAddition(tableAddition, 1);
										system("pause");												
										break;
									case 2: 	
										erreurAdditionSoir://gestion d'erreur							
										system("cls");
										afficherAdditionSoir();
										testDigit = scanf("%d", &tableAddition);
										if(testDigit==0) {
											viderBuffer();
											goto erreurAdditionSoir;
										}
										FaireAddition(tableAddition, 2);	
										system("pause");		
										break;
								}
								if(choixAddition==0) break;
							}
							break;
						case 4: // Services -> 4. Gestion des tables
							while(1) {
								erreurAfficherTables://gestion d'erreur
								system("cls");
								afficherTables();
								testDigit = scanf("%d", &choixTables);
								if(testDigit==0) {
									viderBuffer();
									goto erreurAfficherTables;
								}
								switch(choixTables) {
									case 1: // ajouter Table
										system("cls");
										if(compterMenu()!=0) {
											ajouterTable();	
										}	
										break;
									case 2: // supprimer Table
										system("cls");
										if(compterTable()!=0) {
											supprimerTable();
										}				
										break;
								}
								if(choixTables==0) break;
							}
							break;
						case 5: // Services -> 5. Gestion du menu
							while(1) {
								erreurAfficherMenu://gestion d'erreur
								system("cls");
								afficherMenu();
								testDigit = scanf("%d", &choixMenu);
								if(testDigit==0) {
									viderBuffer();
									goto erreurAfficherMenu;
								}
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
					}//retour au menu principal
					if(choixServices==0) break;
					
				}//sortie du menu de gestion
				break;
		}
		if(choix==0) break;
	}
	
}

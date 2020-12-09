#include <stdio.h>
#include <stdlib.h>

void afficherEcranPrincipal() { //gestion restaurant + options
	printf("\n");
	printf("   *********************************************************************************************");
	printf("\n");
	printf("       _____           _   _               _____           _                              _  \n");
	printf("      / ____|         | | (_)             |  __ \\         | |                            | |  \n");
	printf("     | |  __  ___  ___| |_ _  ___  _ __   | |__) |___  ___| |_ __ _ _   _ _ __ __ _ _ __ | |_ \n");
	printf("     | | |_ |/ _ \\/ __| __| |/ _ \\| '_ \\  |  _  // _ \\/ __| __/ _` | | | | '__/ _` | '_ \\| __|\n");
	printf("     | |__| |  __/\\__ \\ |_| | (_) | | | | | | \\ \\  __/\\__ \\ || (_| | |_| | | | (_| | | | | |_ \n");
	printf("      \\_____|\\___||___/\\__|_|\\___/|_| |_| |_|  \\_\\___||___/\\__\\__,_|\\__,_|_|  \\__,_|_| |_|\\__|\n");
	printf("\n");
	printf("   *********************************************************************************************");
	printf("\n");
	printf("\n");
	printf("   1. Gestion du personnel\n");
	printf("   2. Services\n");
	printf("\n");
	printf("   0. Quitter\n");
	printf("\n");
	printf("   Choix : ");
}

void afficherGestionPersonnel() { //gestion du personnel + options
	printf("\n");
	printf("   ******************************************************************************************************");
	printf("\n");
	printf("       _____           _   _                   _                                                    _\n");
	printf("      / ____|         | | (_)                 | |                                                  | |\n");
	printf("     | |  __  ___  ___| |_ _  ___  _ __     __| |_   _   _ __   ___ _ __ ___  ___  _ __  _ __   ___| |\n");
	printf("     | | |_ |/ _ \\/ __| __| |/ _ \\| '_ \\   / _` | | | | | '_ \\ / _ \\ '__/ __|/ _ \\| '_ \\| '_ \\ / _ \\ |\n");
	printf("     | |__| |  __/\\__ \\ |_| | (_) | | | | | (_| | |_| | | |_) |  __/ |  \\__ \\ (_) | | | | | | |  __/ |\n");
	printf("      \\_____|\\___||___/\\__|_|\\___/|_| |_|  \\__,_|\\__,_| | .__/ \\___|_|  |___/\\___/|_| |_|_| |_|\\___|_|\n");
	printf("                                                        | |                                           \n");
	printf("                                                        |_|                                           \n");
	printf("\n");
	printf("   ******************************************************************************************************");
	printf("\n");
	
	recupEmployes();

	printf("   1. Ajouter un employe\n");
	printf("   2. Supprimer un employe\n");
	printf("   3. Modifier l\'horaire d\'un employe\n");
	printf("\n");
	printf("   0. Retour\n");
	printf("\n");
	printf("   Choix : ");
}

void afficherMenu() { //gestion des menus + options
	printf("\n");
	printf("   ********************************************************************************************");
	printf("\n");
	printf("       _____           _   _                   _                                           \n");
	printf("      / ____|         | | (_)                 | |                                           \n");
	printf("     | |  __  ___  ___| |_ _  ___  _ __     __| | ___  ___   _ __ ___   ___ _ __  _   _ ___ \n");
	printf("     | | |_ |/ _ \\/ __| __| |/ _ \\| '_ \\   / _` |/ _ \\/ __| | '_ ` _ \\ / _ \\ '_ \\| | | / __|\n");
	printf("     | |__| |  __/\\__ \\ |_| | (_) | | | | | (_| |  __/\\__ \\ | | | | | |  __/ | | | |_| \\__ \\\n");
	printf("      \\_____|\\___||___/\\__|_|\\___/|_| |_|  \\__,_|\\___||___/ |_| |_| |_|\\___|_| |_|\\__,_|___/\n");
	printf("\n");
	printf("   ********************************************************************************************");
	printf("\n");
	
	recupMenu();
	
	printf("   1. Ajouter un menu\n");
	printf("   2. Supprimer un menu\n");
	printf("\n");
	printf("   0. Retour\n");
	printf("\n");
	printf("   Choix : ");	
}

void afficherServices() { //services + options
	printf("\n");
	printf("   ********************************************");
	printf("\n");
	printf("       _____                 _              \n");
	printf("      / ____|               (_)              \n");
	printf("     | (___   ___ _ ____   ___  ___ ___  ___ \n");
	printf("      \\___ \\ / _ \\ '__\\ \\ / / |/ __/ _ \\/ __|\n");
	printf("      ____) |  __/ |   \\ V /| | (_|  __/\\__ \\\n");
	printf("     |_____/ \\___|_|    \\_/ |_|\\___\\___||___/\n");
	printf("\n");
	printf("   ********************************************");
	printf("\n");
	printf("\n");
	printf("   1. Reservation\n");
	printf("   2. Changer ma Commande\n");
	printf("   3. Addition\n");
	printf("   4. Gestion des tables\n");
	printf("   5. Gestion des menus\n");
	printf("\n");
	printf("   0. Retour\n");
	printf("\n");
	printf("   Choix : ");	
}

void afficherTables() { //gestion des tables + options
	printf("\n");
	printf("   ***************************************************************************************");
	printf("\n");
	printf("      _____           _   _                   _             _        _     _           \n");
	printf("     / ____|         | | (_)                 | |           | |      | |   | |          \n");
	printf("    | |  __  ___  ___| |_ _  ___  _ __     __| | ___  ___  | |_ __ _| |__ | | ___  ___ \n");
	printf("    | | |_ |/ _ \\/ __| __| |/ _ \\| '_ \\   / _` |/ _ \\/ __| | __/ _` | '_ \\| |/ _ \\/ __|\n");
	printf("    | |__| |  __/\\__ \\ |_| | (_) | | | | | (_| |  __/\\__ \\ | || (_| | |_) | |  __/\\__ \\\n");
	printf("     \\_____|\\___||___/\\__|_|\\___/|_| |_|  \\__,_|\\___||___/  \\__\\__,_|_.__/|_|\\___||___/\n");
	printf("\n");
	printf("   ***************************************************************************************");
	printf("\n");
	
	recupTables();
	
	printf("   1. Ajouter une table\n");
	printf("   2. Supprimer une table\n");
	printf("\n");
	printf("   0. Retour\n");
	printf("\n");
	printf("   Choix : ");	
}

void afficherAddition() { //addition + options
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
	printf("   1. Faire l'addition (Service du midi)\n");
	printf("   2. Faire l'addition (Service du soir)\n");
	printf("\n");
	printf("   0. Retour\n");
	printf("\n");
	printf("   Choix : ");	
}

void afficherAdditionMidi() { //addition pour le midi
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
	recupAdditionMidi();
	printf("\n");
	printf("   Faire l'addition de la table : ");
}

void afficherAdditionSoir() { //addition pour le soir
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
	recupAdditionSoir();
	printf("\n");
	printf("   Faire l'addition de la table : ");
}

void afficherChangerCommande() { //changer commande
	printf("\n");
	printf("   ****************************************************************************************************");
	printf("\n");
	printf("     _____ _                                    _____                                          _      \n");
	printf("    / ____| |                                  / ____|                                        | |     \n");
	printf("   | |    | |__   __ _ _ __   __ _  ___ _ __  | |     ___  _ __ ___  _ __ ___   __ _ _ __   __| | ___ \n");
	printf("   | |    | '_ \\ / _` | '_ \\ / _` |/ _ \\ '__| | |    / _ \\| '_ ` _ \\| '_ ` _ \\ / _` | '_ \\ / _` |/ _ \\\n");
	printf("   | |____| | | | (_| | | | | (_| |  __/ |    | |___| (_) | | | | | | | | | | | (_| | | | | (_| |  __/\n");
	printf("    \\_____|_| |_|\\__,_|_| |_|\\__, |\\___|_|     \\_____\\___/|_| |_| |_|_| |_| |_|\\__,_|_| |_|\\__,_|\\___|\n");
	printf("                              __/ |                                                                   \n");
	printf("                             |___/                                                                    \n");
	printf("\n");
	printf("   ****************************************************************************************************");
	printf("\n");	
}

void afficherReservation() { //reservation
	printf("\n");
	printf("   **********************************************************");
	printf("\n");
	printf("    _____                                _   _             \n");
	printf("   |  __ \\                              | | (_)            \n");
	printf("   | |__) |___  ___  ___ _ ____   ____ _| |_ _  ___  _ __  \n");
	printf("   |  _  // _ \\/ __|/ _ \\ '__\\ \\ / / _` | __| |/ _ \\| '_ \\ \n");
	printf("   | | \\ \\  __/\\__ \\  __/ |   \\ V / (_| | |_| | (_) | | | |\n");
	printf("   |_|  \\_\\___||___/\\___|_|    \\_/ \\__,_|\\__|_|\\___/|_| |_|\n");
	printf("\n");
	printf("   **********************************************************");
	printf("\n");
	
}

void afficherReservationOptions() { //reservation + options
	printf("\n");
	printf("   **********************************************************");
	printf("\n");
	printf("    _____                                _   _             \n");
	printf("   |  __ \\                              | | (_)            \n");
	printf("   | |__) |___  ___  ___ _ ____   ____ _| |_ _  ___  _ __  \n");
	printf("   |  _  // _ \\/ __|/ _ \\ '__\\ \\ / / _` | __| |/ _ \\| '_ \\ \n");
	printf("   | | \\ \\  __/\\__ \\  __/ |   \\ V / (_| | |_| | (_) | | | |\n");
	printf("   |_|  \\_\\___||___/\\___|_|    \\_/ \\__,_|\\__|_|\\___/|_| |_|\n");
	printf("\n");
	printf("   **********************************************************");
	printf("\n");
	printf("\n");	
	printf("   1. Faire une reservation\n");
	printf("   2. Supprimer une reservation\n");
	printf("\n");
	printf("   0. Retour\n");
	printf("\n");
	printf("   Choix : ");	
	
}


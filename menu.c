/*
 * menu.c
 *
 *  Created on: 22 oct 2021
 *      Author: Leonel
 */


int menu()
{
	int opcion;
		system("cls");

		printf("   ***                     *** 	\n");
		printf("----------------------------------\n");
		printf("  1) \n");
		printf("  2) \n");
		printf("  3) \n");
		printf("  4) \n");
		printf("  5) \n");
		printf("  6) \n");
		printf("  7) \n");
		printf("  8) \n");
		printf("  9) \n");
		printf("  20) Salir\n");

		getInt("Por favor elija una opcion: ", "ERROR. Por favor elija una opcion: ", &opcion);

	return opcion;
}

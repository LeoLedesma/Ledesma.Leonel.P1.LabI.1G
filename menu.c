#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "entradas.h"
char menu()
{
	char opcion;
		system("cls");

		printf("    ***    SERVICIOS DE VUELO LEDESMA    *** 	\n");
		printf("------------------------------------------------\n");
		printf("  A) ALTA AVION\n");
		printf("  B) MODIFICAR AVION\n");
		printf("  C) BAJA AVION\n");
		printf("  D) LISTAR AVIONES\n");
		printf("  E) LISTAR AEROLINEAS\n");
		printf("  F) LISTAR TIPOS\n");
		printf("  G) LISTAR DESTINOS\n");
		printf("  H) ALTA VUELO\n");
		printf("  I) LISTAR VUELOS\n");
		printf("  Z) Salir\n");

		utn_getCaracter(&opcion, "Por favor seleccione una opcion: ", "ERROR. Por favor seleccione una opcion (solo letras): ", 'A', 'z', 100);
		opcion = toupper(opcion);

	return opcion;
}

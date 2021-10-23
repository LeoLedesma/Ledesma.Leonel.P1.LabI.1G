#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "aerolinea.h"
#include "avion.h"
#include "destino.h"
#include "fecha.h"
#include "tipo.h"
#include "vuelo.h"

#include "entradas.h"

#define TAM_A 5
#define TAM_T 4
#define TAM_D 4


int main(void)
{
    int opcion;
	char seguir = 's';
	int nextId=0;
	int nextIdBis=0;

	eAerolinea aerolineas[TAM_A] = {
				{1000, "Lan"},
				{1001, "Iberia"},
				{1002, "Norwegian"},
				{1003, "American"},
				{1004, "Austral"}
		};

	eTipos tipos [TAM_S] =
		{
				{5000, "Jet"},
				{5001, "Helice"},
				{5002, "Planeador"},
				{5003, "Carga"}
		};

		eDestino destinos [TAM_T] =
		{
		    {20000, "Calafate", 22250},
		    {20001, "Miami", 103000},
		    {20002, "Madrid", 84400},
		    {20003, "Amsterdam", 95600},
		}


	do{

			opcion = menu();
			switch(opcion)
			{
			case A: //ALTA

				break;
			case B: //MODIFICAR

				break;

			case C: //BAJA

				break;

			case D: //LISTAR AVIONES ORDENADOS

				break;

			case E: //LISTAR AEROLINEAS

				break;
            case F: //listar tipos
                break;
			case G: //LISTAR DESTINOS

				break;
			case H: //ALTA VUELO

				break;
			case I: //LISTAR VUELOS

				break;

			case Z://salir

				seguir = getConfirmation("Esta seguro que desea salir? (s/n): ", "ERROR: Esta seguro que desea salir? (s/n): ");
				seguir = tolower (seguir);
						break;

			}



			system("pause");
		}while(seguir=='s');






	return EXIT_SUCCESS;
}

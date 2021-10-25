#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "menu.h"
#include "aerolinea.h"
#include "avion.h"
#include "destino.h"
#include "fecha.h"
#include "tipo.h"
#include "vuelo.h"
#include "entradas.h"

#include "dataWarehouse.h"

#define TAM_AV 50
#define TAM_V 50
#define TAM_AE 5
#define TAM_T 4
#define TAM_D 4


int main(void)
{
    char opcion;
    char salir = 'n';
    int nextIdVuelos=1;

    int contadorAviones=0;
    int contadorVuelos=0;

    eAvion aviones[TAM_AV];
    eVuelo vuelos[TAM_V];

    eAerolinea aerolineas[TAM_AE] =
    {
        {1000, "Lan"},
        {1001, "Iberia"},
        {1002, "Norwegian"},
        {1003, "American"},
        {1004, "Austral"}
    };

    eTipo tipos [TAM_T] =
    {
        {5000, "Jet"},
        {5001, "Helice"},
        {5002, "Planeador"},
        {5003, "Carga"}
    };

    eDestino destinos [TAM_D] =
    {
        {20000, "Calafate", 22250},
        {20001, "Miami", 103000},
        {20002, "Madrid", 84400},
        {20003, "Amsterdam", 95600},
    };

    if(!inicializarAviones(aviones, TAM_AV))
    {
        printf("Hubo un error al inicializar");

    }

    if(!inicializarVuelos(vuelos, TAM_V))
    {
        printf("Hubo un error al inicializar");

    }

    hardcodearAviones(aviones, TAM_AV, 8);
    contadorAviones=8;

    hardcodearVuelos(vuelos, TAM_V, 8, &nextIdVuelos);

    do
    {

        opcion = menu();
        switch(opcion)
        {
        case 'A': //ALTA AVION
            system("cls");
            if(!altaAviones(aviones, TAM_AV, aerolineas, TAM_AE, tipos, TAM_T))
            {

            }
            else
            {
                contadorAviones++;
            }

            break;
        case 'B': //MODIFICAR
            modificarAvion(aviones, TAM_AV, aerolineas, TAM_AE, tipos, TAM_T);


            break;

        case 'C': //BAJA
            system("cls");
            if(bajaAviones(aviones, TAM_AV, aerolineas, TAM_AE, tipos, TAM_T)==1)
            {
            printf("Avion dado de baja con exito!!\n");
            contadorAviones--;
            }else
            {

            }






            break;

        case 'D': //LISTAR AVIONES ORDENADOS
            system("cls");
            if(contadorAviones>0)
            {
                if(!mostrarAviones(aviones, TAM_AV, aerolineas, TAM_AE, tipos, TAM_T))
                {
                    printf("Ocurrio un error al mostrar.\n");
                }
            }
            else
            {
                printf("Primero debe carcar un avion para poder mostrarlos.\n");
            };

        break;

    case 'E': //LISTAR AEROLINEAS
        system("cls");
        mostrarAerolineas(aerolineas, TAM_AE);

        break;
    case 'F': //listar tipos
        system("cls");
        mostrarTipos(tipos, TAM_T);
        break;
    case 'G': //LISTAR DESTINOS
        system("cls");
        mostrarDestinos(destinos, TAM_D);

        break;
    case 'H': //ALTA VUELO
        system("cls");
        if(!altaVuelo(vuelos, TAM_V, aviones, TAM_AV, tipos, TAM_T, aerolineas, TAM_AE, destinos, TAM_D, &nextIdVuelos))
        {
            printf("No se pudo cargar el vuelo con exito.\n");

        }
        else
        {
            contadorVuelos++;
        }

        break;
    case 'I': //LISTAR VUELOS
        system("cls");
        if(contadorVuelos>0)
        {
            if(!mostrarVuelos(vuelos, TAM_V, aviones, TAM_AV, destinos, TAM_D))
            {
                printf("Ocurrio un error al mostrar los vuelos\n.");

            }

        }


        break;

    case 'Z'://salir

        salir = getConfirmation("Esta seguro que desea salir? (s/n): ", "ERROR: Esta seguro que desea salir? (s/n): ");
        salir = tolower (salir);
        break;
    default:
        printf("Opcion incorrecta, intente nuevamente.\n");
        break;


    }



    system("pause");
}while(salir!='s');

return EXIT_SUCCESS;
}

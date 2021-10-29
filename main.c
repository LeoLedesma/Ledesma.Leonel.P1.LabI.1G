#include "menu.h"

#define TAM_AV 50 //tamanio lista aviones
#define TAM_V 50 //tamanioo lista vuelos
#define TAM_AE 5 //tamanio lista aerolineas
#define TAM_T 4 //tamanio lista tipos
#define TAM_D 4 //tamanio lista destinos
#define TAM_P 5 //tamanio lista pilotos

int main(void)
{
    int nextIdVuelos=1;

    eAvion aviones[TAM_AV];
    eVuelo vuelos[TAM_V];

    ePiloto pilotos[TAM_P] =
    {
        {1, "Manuel", 'm'},
        {2, "Micaela", 'f'},
        {3, "Rodrigo", 'm'},
        {4, "Florencia", 'f'},
        {5, "Joaquin", 'm'}
    };

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
        printf("Hubo un error al inicializar aviones.\n");
    }
    if(!inicializarVuelos(vuelos, TAM_V))
    {
        printf("Hubo un error al inicializar vuelos. \n");
    }

    menuPrincipal(aviones, TAM_AV, aerolineas, TAM_AE, tipos, TAM_T, vuelos, TAM_V, destinos, TAM_D, &nextIdVuelos, pilotos, TAM_P);

    return EXIT_SUCCESS;
}

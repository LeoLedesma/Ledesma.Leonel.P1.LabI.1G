#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"



char nombres[10][20] = {
    "Juan",
    "Pedro",
    "Sofia",
    "Miguel",
    "Valentina",
    "Camila",
    "Andrea",
    "Luis",
    "Diego",
    "Analia"
};

char sexos[10] = {
    'm',
    'm',
    'f',
    'm',
    'f',
    'f',
    'f',
    'm',
    'm',
    'f'
};

int idMarcas[10]={1000, 1000, 1002, 1001, 1003, 1003, 1004, 1001, 1002, 1004};

int idColores[10]={5000, 5000, 5003, 5002, 5004, 5001, 5003, 5004, 5001, 5000};

char cajas[10]= {'m', 'a', 'm', 'a', 'm','m','a','m', 'm', 'a'};

int edades[10] = {50,50,28,32,45,29,39,23,28,27};

float alturas[10] = {1.64, 1.67, 1.9, 1.78, 1.75, 1.7, 1.65, 1.73, 1.69, 1.68};

int idLocalidades[10] = {1001,1002,1000,1001,1001,1003,1004,1002,1004,1001};

char paises[10][20] ={
		{"Albania"},
		{"Russia"},
		{"Slovenia"},
		{"United Kingdom"},
		{"Indonesia"},
		{"Estados Unidos"},
		{"Netherlands"},
		{"Sweden"},
		{"China"},
		{"China"}
};


int dias [20] = {20, 30, 28, 12, 14, 14, 16, 10, 26, 23, 10, 30, 25, 10, 20, 12, 14, 5, 20, 20};
int meses [20] = {10, 12, 1, 5, 9, 10, 10, 9, 8, 2, 12, 10, 9, 4, 12, 10, 12, 11, 10, 10 };
int anios [20] = {2020, 2020, 2020, 2021, 2020, 2021, 2021, 2021, 2021, 2021, 2020, 2021, 2020, 2021, 2020, 2020, 2021, 2020, 2020, 2021};

int idAviones[10] = {50,75,28,32,45,29,39,23,28,27};
int idAerolineas[10] = {1000, 1001, 1002, 1001, 1000, 1004, 1003, 1000, 1004, 1001};
int idTipos[10] = {5000,5000,5002,5000,5000,5003,5000,5003,5002,5003};
int capacidades[10] = {100, 150, 11, 300, 143, 251, 120, 122, 15, 299};
int idPilotos[10] = {1, 2, 1, 4, 4, 3, 2, 1, 2, 1};

//vuelos

int destinos[20] = {20001, 20002, 20000, 20003, 20000, 20001, 20003, 20002,20003, 20001, 20001, 20002, 20000, 20003, 20000, 20001, 20003, 20002,20003, 20001};

int idAvionesVuelos[20] = {50,75,28,32,45,29,39,23,28,27, 50, 75, 28, 32, 45, 75, 23, 50, 50, 28};




int hardcodearAviones(eAvion aviones[], int tamAV, int cantidad, int* pContadorAviones)
{
    int contador = -1;

    if (aviones != NULL && tamAV > 0 && cantidad >= 0 && cantidad <= tamAV && pContadorAviones!=NULL) {
        contador = 0;

        for (int i = 0; i < cantidad; i++){

        	aviones[i].id = idAviones[i];
        	(*pContadorAviones)++;

            aviones[i].idAerolinea = idAerolineas[i];
            aviones[i].idTipo = idTipos[i];
            aviones[i].capacidad = capacidades[i];
            aviones[i].idPiloto = idPilotos[i];




            aviones[i].isEmpty = 0;


            contador++;

        }
    }

    return contador;
}

int hardcodearVuelos(eVuelo vuelos[], int tamV, int cantidad, int* pId, int* pContadorVuelos)
{
    int contador = -1;

    if (vuelos != NULL && tamV > 0 && cantidad >= 0 && cantidad <= tamV && pId!=NULL && pContadorVuelos!=NULL)
        {
        contador = 0;

        for (int i = 0; i < cantidad; i++)
            {

        	vuelos[i].id = *pId;
        	(*pId)++;
        	(*pContadorVuelos)++;

            vuelos[i].idAvion = idAvionesVuelos[i];
            vuelos[i].idDestino = destinos[i];
            vuelos[i].fecha.dia = dias[i];
            vuelos[i].fecha.mes = meses[i];
            vuelos[i].fecha.anio = anios[i];

            vuelos[i].isEmpty = 0;
            contador++;

        }
    }


    return contador;
}







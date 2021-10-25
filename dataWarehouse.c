#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"
#include "avion.h"
#include "vuelo.h"


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


int dias [10] = {4, 30, 28, 12, 14, 14, 16, 10, 26, 23};
int meses [10] = {10, 12, 1, 5, 9, 10, 15, 9, 8, 2};
int anios [10] = {1994, 1985, 1966, 2002, 2002, 1994, 1996, 1969, 1980, 1999};

int idAviones[10] = {50,75,28,32,45,29,39,23,28,27};
int idAerolineas[10] = {1000, 1001, 1002, 1001, 1000, 1004, 1003, 1000, 1004, 1001};
int idTipos[10] = {5000,5000,5002,5000,5001,5003,5000,5003,5002,5003};
int capacidades[10] = {100, 150, 11, 300, 143, 251, 120, 122, 15, 299};

//vuelos

int destinos[10] = {20001, 20002, 20000, 20003, 20000, 20001, 20003, 20002,20003, 20001};


//Funcion para hardcodear personas
//Si no entro pq hubo un problema, devuelvo -1
//


int hardcodearAviones(eAvion aviones[], int tamAV, int cantidad)
{
    int contador = -1;

    if (aviones != NULL && tamAV > 0 && cantidad >= 0 && cantidad <= tamAV) {
        contador = 0;

        for (int i = 0; i < cantidad; i++){

        	aviones[i].id = idAviones[i];


            aviones[i].idAerolinea = idAerolineas[i];
            aviones[i].idTipo = idTipos[i];
            aviones[i].capacidad = capacidades[i];



            aviones[i].isEmpty = 0;


            contador++;

        }
    }


    return contador;
}

int hardcodearVuelos(eVuelo vuelos[], int tamV, int cantidad, int* pId)
{
    int contador = -1;

    if (vuelos != NULL && tamV > 0 && cantidad >= 0 && cantidad <= tamV && pId!=NULL)
        {
        contador = 0;

        for (int i = 0; i < cantidad; i++)
            {

        	vuelos[i].id = *pId;
        	(*pId)++;

            vuelos[i].idAvion = idAviones[i];
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







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

int dia [10] = {4, 30, 28, 12, 14, 14, 16, 10, 26, 23};
int mes [10] = {10, 12, 1, 5, 9, 10, 15, 9, 8, 2}
int anio [10] = {1994, 1985, 1966, 2002, 2002, 1994, 1996, 1969, 1980, 1999};



//Funcion para hardcodear personas
//Si no entro pq hubo un problema, devuelvo -1
//

/*
int hardcodearAutos(eStruct structs[], int tamA, int cantidad, int* pId){
    int contador = -1;

    if (autos != NULL && tamA > 0 && cant >= 0 && cantidad <= tamA && pId != NULL) {
        contador = 0;

        for (int i = 0; i < cantidad; i++){

        	structs[i].id = *pId;

            (*pId)++;

            structs[i].otroId = idMarcas[i];


            structs[i].isEmpty = 0;


            contador++;

        }
    }


    return contador;
}



*/




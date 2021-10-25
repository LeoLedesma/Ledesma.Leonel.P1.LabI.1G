#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#include "entradas.h"
#include "destino.h"
#include "fecha.h"

#ifndef VUELO_H_
#define VUELO_H_

#define TRUE 1
#define FALSE 0

typedef struct
{
	int id;
	int idAvion;
	int idDestino;
	eFecha fecha;
	int isEmpty;

}eVuelo;


#endif /* VUELO_H_ */
int inicializarVuelos(eVuelo vuelos[], int tamV);
int buscarLibreVuelo(eVuelo vuelos[], int tamV);
int altaVuelo(eVuelo vuelos[], int tamV, eAvion aviones[], int tamAV, eTipo tipos [], int tamT, eAerolinea aerolineas[], int tamAE, eDestino destinos[], int tamD, int* pIdVuelo);
void mostrarVuelo(eVuelo unVuelo, eAvion aviones[], int  tamAV, eDestino destinos[], int tamD);
int mostrarVuelos(eVuelo vuelos[], int tamV, eAvion aviones[], int  tamAV, eDestino destinos[], int tamD);



#include "aerolinea.h"
#include "tipo.h"


#ifndef AVION_H_
#define AVION_H_

typedef struct
{
	int id;
	int idAerolinea;
	int idTipo;
	int capacidad;

	int isEmpty;

}eAvion;


#endif /* AVION_H_ */

int inicializarAviones(eAvion aviones[], int tamA);
int buscarLibreAviones(eAvion aviones[], int tamA);
int mostrarAvion(eAvion unAvion, eAerolinea aerolineas[], int tamAE, eTipo tipos[], int tamT);
int mostrarAviones(eAvion aviones[], int tamAV, eAerolinea aerolineas[], int tamAE, eTipo tipos[], int tamT);
int altaAviones(eAvion aviones[], int tamAV, eAerolinea aerolineas[], int tamAE, eTipo tipos[], int tamT);
int bajaAviones(eAvion aviones[], int tamAV, eAerolinea aerolineas[], int tamAE, eTipo tipos[], int tamT);
int modificarAvion(eAvion aviones[], int tamAV, eAerolinea aerolineas[], int tamAE, eTipo tipos[], int tamT);
int ordenarAviones(eAvion aviones[], int tamA, eAerolinea aerolineas[], int tamAE);




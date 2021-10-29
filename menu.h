#ifndef MENU_H_
#define MENU_H_


#include "aerolinea.h"
#include "avion.h"
#include "destino.h"
#include "fecha.h"
#include "tipo.h"
#include "vuelo.h"
#include "entradas.h"


#include "dataWarehouse.h"

#endif /* MENU_H_ */

/// @brief Menu principal del ABM
///
/// @param aviones Puntero a lista de aviones.
/// @param tamAv Tamanio de la lista.
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamamio de la lista aerolineas.
/// @param tipos Puntero a lista de tipos.
/// @param tamT Tamanio de la lista tipos.
/// @param vuelos Puntero a lista de vuelos
/// @param tamV Tamanio de la lista.
/// @param destinos Puntero a lista destinos.
/// @param tamD Tamanio de la lista destinos.
/// @param pNextIdVuelos Puntero al siguiente ID vuelo (autoincremental).
/// @return (0) si ocurrio algun error y (1) si salio bien.
int menuPrincipal (eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, eTipo tipos[], int tamT, eVuelo vuelos[], int tamV, eDestino destinos[], int tamD, int* pNextIdVuelos, ePiloto pilotos[], int tamP);

/// @brief Pide al usuario que eliga una opcion.
///
/// @return Retorna la opcion alfabetica que el usuario haya ingresado.
char menuOpciones();

/// @brief Menu principal de la seccion informes
///
/// @param aviones Puntero a lista de aviones.
/// @param tamAv Tamanio de la lista.
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamamio de la lista aerolineas.
/// @param tipos Puntero a lista de tipos.
/// @param tamT Tamanio de la lista tipos.
/// @param vuelos Puntero a lista de vuelos
/// @param tamV Tamanio de la lista.
/// @param destinos Puntero a lista destinos.
/// @param tamD Tamanio de la lista destinos.
/// @param contadorAviones Cantidad de aviones cargados.
/// @param contadorVuelos Cantidad de vuelos cargados.
/// @return (0) si ocurrio algun error y (1) si salio bien.
int menuInformes(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, eTipo tipos[], int tamT, eVuelo vuelos[], int tamV, eDestino destinos[], int tamD, int contadorAviones, int contadorVuelos, ePiloto pilotos[], int tamP);

/// @brief Pide al usuario que eliga una opcion.
///
/// @return Retorna la opcion numerica que el usuario haya ingresado.
int menuOpcionesInformes();



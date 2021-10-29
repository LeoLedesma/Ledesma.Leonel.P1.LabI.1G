#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED

#include "avion.h"
#include "vuelo.h"



#endif // DATAWAREHOUSE_H_INCLUDED

/// @brief Hace una carga de datos en la lista aviones para simular datos reales.
///
/// @param aviones Puntero a lista de aviones
/// @param tamAV Tamanio de la lista aviones.
/// @param cantidad Cantidad de aviones a cargar
/// @param contAviones Puntero al contador de aviones
/// @return (-1) si ocurrio un error o la cantidad de aviones cargados correctamente.
int hardcodearAviones(eAvion aviones[], int tamAV, int cantidad, int* pContAviones);

/// @brief Hace una carga de datos en la lista vuelos para simular datos reales.
///
/// @param vuelos Puntero a lista de aviones
/// @param tamV Tamanio de la lista aviones
/// @param cantidad Cantidad de vuelos a cargar
/// @param pId Puntero
/// @param cantidadVuelos
/// @return (-1) si ocurrio un error o la cantidad de aviones cargados correctamente.
int hardcodearVuelos(eVuelo vuelos[], int tamV, int cantidad, int* pId, int* pCantidadVuelos);

#ifndef DESTINO_H_
#define DESTINO_H_

#include "entradas.h"

typedef struct
{
	int id;
	char descripcion[26];
	float precio;

}eDestino;

#endif /* DESTINO_H_ */

/// @brief Carga la descripcion de un destino determinado en "descripcionDestino"-
///
/// @param id ID del destino.
/// @param destinos Puntero a lista de destinos.
/// @param tamD Tamanio de la lista destinos.
/// @param descripcionDestino Descripcion a ser cargada
/// @return (0) si ocurrio un error o no se encontro la aerolinea y (1) si cargo correctamente.
int cargarDescripcionDestinos(int id, eDestino destinos[], int tamD, char descripcionDestino[]);

/// @brief Muestra individualmente un destino en un indice en particular.
///
/// @param unDestino Destino a mostrar.
void mostrarDestino(eDestino unDestino);

/// @brief Despliega una lista con todas los destinos.
///
/// @param destinos Puntero a lista de destinos.
/// @param tamD Tamanio de la lista destinos.
/// @return (0) si ocurrio un error y (1) si pudo mostrar correctamente.
int mostrarDestinos(eDestino destinos[], int tamD);

/// @brief Valida que el IDrecibido sea de un destino existente.
///
/// @param idRecibido
/// @param destinos Puntero a lista de destinos.
/// @param tamD Tamanio de la lista destinos.
/// @return (0) si ocurrio un error o (1) si el ID es valido.
int validarIdDestino(int idRecibido, eDestino destinos[], int tamD);

/// @brief Devuelve el precio de un destino con un ID en particular
///
/// @param idDestino
/// @param destinos Puntero a lista de destinos.
/// @param tamD Tamanio de la lista destinos.
/// @return (-1) si ocurrio un error o el precio del destino.
float cargarPrecioDestino(int idDestino, eDestino destinos[], int tamD);



#ifndef TIPO_H_
#define TIPO_H_

#include "entradas.h"

typedef struct
{
	int id;
	char descripcion[21];

}eTipo;



#endif /* TIPO_H_ */



/// @brief Carga la descripcion de un tipo determinado en "descripcionTipo"
///
/// @param id ID del tipo.
/// @param tipos Puntero a lista de tipos.
/// @param tamT Tamanio de lista tipos
/// @param descripcionTipo Descripcion a ser cargada
/// @return (0) si ocurrio un error o no se encontro la aerolinea y (1) si cargo correctamente.
int cargarDescripcionTipo(int id, eTipo tipos[], int tamT, char descripcionTipo[]);

/// @brief Muestra individualmente un tipo en un indice en particular.
///
/// @param unTipo Tipo a mostrar.
void mostrarTipo(eTipo unTipo);

/// @brief Despliega una lista con todos los tipos.
///
/// @param tipos Puntero a lista de tipos.
/// @param tamT Tamanio de lista tipos
/// @return (0) si ocurrio un error y (1) si pudo mostrar correctamente.
int mostrarTipos(eTipo tipos[], int tamT);

/// @brief Valida que el IDrecibido sea de un tipo existente.
///
/// @param idRecibido
/// @param tipos Puntero a lista de tipos.
/// @param tamT Tamanio de lista tipos
/// @return (0) si ocurrio un error o (1) si el ID es valido.
int validarIdTipo(int idRecibido, eTipo tipos[], int tamT);


/// @brief Le pide al usuario que ingrese un ID de tipo
///
/// @param mensaje Mensaje principal de pedido de dato.
/// @param mensajeError Mensaje de error de pedido de dato.
/// @param idIngresado Variable donde va a ser guardada a traves de puntero.
/// @param intentos Cantidad de intentos que tiene el usuario.
/// @param tipos Puntero a lista de tipos.
/// @param tamT Tamanio de lista tipos
/// @return (0) si ocurrio un error o (1) si se pudo cargar correctamente.
int pedirIdTipo(char mensaje[], char mensajeError[], int* idIngresado, int intentos, eTipo tipos[], int tamT);




#ifndef AEROLINEA_H_
#define AEROLINEA_H_

#include "entradas.h"

typedef struct
{
	int id;
	char descripcion[21];

}eAerolinea;



#endif /* AEROLINEA_H_ */



/// @brief Carga la descripcion de una aerolinea determinada en "descripcionAerolinea"
///
/// @param id ID de la aerolinea
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamanio de la lista aerolineas.
/// @param descripcionAerolinea Descripcion a ser cargada
/// @return (0) si ocurrio un error o no se encontro la aerolinea y (1) si cargo correctamente.
int cargarDescripcionAerolinea(int id, eAerolinea aerolineas[], int tamAe, char descripcionAerolinea[]);

/// @brief Muestra individualmente una aerolinea en un indice en particular.
///
/// @param unaAerolinea Aerolinea a mostrar
void mostrarAerolinea(eAerolinea unaAerolinea);

/// @brief Despliega una lista con todas las aerolineas.
///
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamanio de la lista aerolineas.
/// @return (0) si ocurrio un error y (1) si pudo mostrar correctamente.
int mostrarAerolineas(eAerolinea aerolineas[], int tamAe);

/// @brief Valida que el IDrecibido sea de una aerolinea existente.
///
/// @param idRecibido
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamanio de la lista aerolineas.
/// @return (0) si ocurrio un error y (1) si el ID es valido
int validarIdAerolinea(int idRecibido, eAerolinea aerolineas[], int tamAe);

/// @brief Le pide al usuario que ingrese un ID de aerolinea
///
/// @param mensaje Mensaje principal de pedido de dato.
/// @param mensajeError Mensaje de error de pedido de dato.
/// @param idIngresado Variable donde va a ser guardada a traves de puntero.
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamA Tamanio de la lista aerolineas.
/// @return (0) si ocurrio un error o no se ingreso ID correctamente, (1) si salio bien.
int pedirIdAerolinea(char mensaje[], char mensajeError[], int* pIdIngresado, int intentos, eAerolinea aerolineas[], int tamA);

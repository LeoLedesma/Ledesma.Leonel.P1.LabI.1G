#ifndef AVION_H_
#define AVION_H_

#include "tipo.h"
#include "entradas.h"
#include "aerolinea.h"
#include "tipo.h"
#include "piloto.h"

typedef struct
{
	int id;
	int idAerolinea;
	int idTipo;
	int idPiloto;
	int capacidad;

	int isEmpty;

}eAvion;


#endif /* AVION_H_ */


/// @brief Inicializa en isEmpty en TRUE/VACIO para habilitarlos a cargar
///
/// @param aviones Puntero a lista de aviones.
/// @param tamAv Tamanio de la lista.
/// @return (0) si ocurrio un error o (1) si salio bien.
int inicializarAviones(eAvion aviones[], int tamAv);

/// @brief Busca la primer posicion libre/vacia.
///
/// @param aviones Puntero a lista de aviones.
/// @param tamAv Tamanio de la lista.
/// @return (-1) si ocurrio un error o el indice donde se encuentra.
int buscarLibreAviones(eAvion aviones[], int tamAv);

/// @brief Busca el indice de un avion con id en particular.
///
/// @param aviones Puntero a lista de aviones.
/// @param tamAv Tamanio de la lista.
/// @param idRecibido Id del avion a buscar.
/// @return (-1) si ocurrio un error o el indice donde se encuentra.
int buscarAvionId(eAvion aviones[], int tamAv, int idRecibido);

/// @brief Muestra individualmente un avion en un indice en particular.
///
/// @param unAvion Avion a mostrar
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamanio de la lista aerolineas.
/// @param tipos Puntero a lista de tipos.
/// @param tamT Tamanio de la lista tipos.
/// @param pilotos Puntero a lista de pilotos.
/// @param tamP tamanio de lista pilotos
void mostrarAvion(eAvion unAvion, eAerolinea aerolineas[], int tamAe, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);

/// @brief Despliega una lista con todos los aviones que esten cargados.
///
/// @param aviones Puntero a lista de aviones.
/// @param tamAv Tamanio de la lista aviones.
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamaio de la lista aerolineas.
/// @param tipos Puntero a lista de tipos.
/// @param tamT Tamanio de la lista tipos.
/// @param pilotos Puntero a lista de pilotos.
/// @param tamP tamanio de lista pilotos
/// @return (-1) si ocurrio un error y (1) si salio bien.
int mostrarAviones(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);

/// @brief Permite dar de alta un avion.
///
/// @param aviones Puntero a lista de aviones.
/// @param tamAv Tamanio de la lista aviones.
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamanio de la lista aerolineas.
/// @param tipos Puntero a lista de tipos.
/// @param tamT Tamanio de la lista tipos.
/// @param pilotos Puntero a lista de pilotos.
/// @param tamP tamanio de lista pilotos
/// @return (-1) si ocurrio un error o (1) si se dio de alta con exito.
int altaAviones(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);

/// @brief Permite dar de baja un avion.
///
/// @param aviones Puntero a lista de aviones.
/// @param tamAv Tamanio de la lista aviones.
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamanio de la lista aerolineas.
/// @param tipos Puntero a lista de tipos.
/// @param tamT Tamanio de la lista tipos.
/// @param pilotos Puntero a lista de pilotos.
/// @param tamP tamanio de lista pilotos
/// @return (-1) si ocurrio un error o no se dio de baja (1) si resulto satisfactorio.
int bajaAviones(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);

/// @brief Permite modificar un avion que este cargado.
///
/// @param aviones Puntero a lista de aviones.
/// @param tamAv Tamanio de la lista aviones.
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamanio de la lista aerolineas.
/// @param tipos Puntero a lista de tipos.
/// @param tamT Tamanio de la lista tipos.
/// @param pilotos Puntero a lista de pilotos.
/// @param tamP tamanio de lista pilotos
/// @return (-1) si ocurrio un error, (0) si no se modifico ninguno o (1) si se modifico un avion.
int modificarAvion(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);

/// @brief Ordena los aviones por aerolinea y capacidad de forma ascendente
///
/// @param aviones Puntero a lista de aviones.
/// @param tamAv Tamanio de la lista aviones.
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamanio de la lista aerolineas.
/// @return (0) si ocurrio un error y (1) si salio bien.
int ordenarAviones(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe);

/// @brief Carga en "descripcion" el nombre de la aerolinea que tenga el avion.
///
/// @param aviones Puntero a lista de aviones.
/// @param tamAv Tamanio de la lista aviones.
/// @param idAvionRecibido ID del avion
/// @param descripcion Descripcion a ser cargada
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamanio de la lista aerolineas.
/// @return (0) si ocurrio un error o no encontro el id. (1) si salio bien.
int cargarDescripcionAerolineaAvion(eAvion aviones[], int tamAv, int idAvionRecibido, char descripcion[], eAerolinea aerolineas[], int tamAe);

/// @brief Muestra en pantalla una barra necesaria para mostrar aviones correctamente.
void graficoListaAviones();

//---------------- informes



int mostrarAvionesTipoSeleccionado(eAvion aviones[], int tamAv, eTipo tipos[], int tamT, eAerolinea aerolineas[], int tamAe, ePiloto pilotos[], int tamP);

int mostrarAvionesAerolineaSeleccionada(eAvion aviones[], int tamAv, eTipo tipos[], int tamT, eAerolinea aerolineas[], int tamAe, ePiloto pilotos[], int tamP);

int mostrarAvionesPorAerolinea(eAvion aviones[], int tamAv, eTipo tipos[], int tamT, eAerolinea aerolineas[], int tamAe, ePiloto pilotos[], int tamP);

int porcentajeAvionesJetAerolinea(eAerolinea aerolineas[], int tamAe, eAvion aviones[], int tamAv);

int aerolineasMayorCapacidad(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe);

int aerolineaMenosAviones(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe);

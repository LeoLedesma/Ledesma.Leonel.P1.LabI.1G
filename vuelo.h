#ifndef VUELO_H_
#define VUELO_H_

#include "entradas.h"
#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#include "entradas.h"
#include "destino.h"
#include "fecha.h"
#include "piloto.h"


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
/// @brief Inicializa en isEmpty en TRUE/VACIO para habilitarlos a cargar
///
/// @param vuelos Puntero a lista de vuelos
/// @param tamV Tamanio de la lista.
/// @return (0) si ocurrio un error o (1) si salio bien.
int inicializarVuelos(eVuelo vuelos[], int tamV);

/// @brief Busca la primer posicion libre/vacia.
///
/// @param vuelos Puntero a lista de vuelos
/// @param tamV Tamanio de la lista.
/// @return (-1) si ocurrio un error o el indice donde se encuentra.
int buscarLibreVuelo(eVuelo vuelos[], int tamV);

/// @brief Busca el indice de un avion con id en particular.
///
/// @param vuelos Puntero a lista de vuelos
/// @param tamV Tamanio de la lista.
/// @param aviones Puntero a lista de aviones.
/// @param tamAv Tamanio de la lista.
/// @param tipos Puntero a lista de tipos.
/// @param tamT Tamanio de la lista tipos.
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamamio de la lista aerolineas.
/// @param destinos Puntero a lista destinos.
/// @param tamD Tamanio de la lista destinos.
/// @param pIdVuelo Puntero al siguiente ID vuelo (autoincremental)
/// @return (0) si ocurrio un error o (1) si se cargo correctamente.
int altaVuelo(eVuelo vuelos[], int tamV, eAvion aviones[], int tamAv, eTipo tipos [], int tamT, eAerolinea aerolineas[], int tamAe, eDestino destinos[], int tamD, int* pIdVuelo, ePiloto pilotos[], int tamP);

/// @brief Muestra individualmente un vuelo en un indice en particular.
///
/// @param unVuelo Vuelo a mostrar
/// @param aviones Puntero a lista de aviones.
/// @param tamAv Tamanio de la lista aviones.
/// @param destinos Puntero a lista destinos.
/// @param tamD Tamanio de la lista destinos.
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamamio de la lista aerolineas.
void mostrarVuelo(eVuelo unVuelo, eAvion aviones[], int  tamAv, eDestino destinos[], int tamD, eAerolinea aerolineas [], int tamAe);

/// @brief Despliega una lista con todos los aviones que esten cargados.
///
/// @param vuelos Puntero a lista de vuelos
/// @param tamV Tamanio de la lista.
/// @param aviones Puntero a lista de aviones.
/// @param tamAv Tamanio de la lista.
/// @param destinos Puntero a lista destinos.
/// @param tamD Tamanio de la lista destinos.
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamamio de la lista aerolineas.
/// @return (-1) si ocurrio un error y (1) si salio bien.
int mostrarVuelos(eVuelo vuelos[], int tamV, eAvion aviones[], int  tamAv, eDestino destinos[], int tamD, eAerolinea aerolineas [], int tamAe);

/// @brief Muestra en pantalla la estructura necesaria para mostrar vuelos correctamente.
void graficoListaVuelos();


/// @brief Pide seleccionar un avion y muestra todos los vuelos que hizo el mismo.
///
/// @param vuelos Puntero a lista de vuelos
/// @param tamV Tamanio de la lista.
/// @param aviones Puntero a lista de aviones.
/// @param tamAv Tamanio de la lista.
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamamio de la lista aerolineas.
/// @param tipos Puntero a lista de tipos.
/// @param tamT Tamanio de la lista tipos.
/// @param destinos Puntero a lista destinos.
/// @param tamD Tamanio de la lista destinos.
/// @param pilotos Puntero a lista de pilotos.
/// @param tamP tamanio de lista pilotos
/// @return (0) si ocurrio un error y (1) si salio bien
int mostrarVuelosAvion(eVuelo vuelos[], int tamV, eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, eTipo tipos[], int tamT, eDestino destinos[], int tamD, ePiloto pilotos[], int tamP);


/// @brief
///
/// @param vuelos Puntero a lista de vuelos
/// @param tamV Tamanio de la lista.
/// @param aviones Puntero a lista de aviones.
/// @param tamAv Tamanio de la lista.
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamamio de la lista aerolineas.
/// @param tipos Puntero a lista de tipos.
/// @param tamT Tamanio de la lista tipos.
/// @param destinos Puntero a lista destinos.
/// @param tamD Tamanio de la lista destinos.
/// @param pilotos Puntero a lista de pilotos.
/// @param tamP tamanio de lista pilotos
/// @return (0) si ocurrio un error y (1) si salio bien
int mostrarSumaViajesAvion(eVuelo vuelos[], int tamV, eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, eTipo tipos[], int tamT, eDestino destinos[], int tamD, ePiloto pilotos[], int tamP);


/// @brief Pide que se seleccione un destino y muestra todos los vuelos a ese destino
///
/// @param destinos Puntero a lista destinos.
/// @param tamD Tamanio de la lista destinos.
/// @param vuelos Puntero a lista de vuelos
/// @param tamV Tamanio de la lista.
/// @param aviones Puntero a lista de aviones.
/// @param tamAv Tamanio de la lista.
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamamio de la lista aerolineas.
/// @param pilotos Puntero a lista de pilotos.
/// @param tamP tamanio de lista pilotos
/// @return (0) si ocurrio un error y (1) si salio bien
int mostrarVueloDeUnDestino(eDestino destinos[], int tamD, eVuelo vuelos[], int tamV, eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, ePiloto pilotos[], int tamP);


/// @brief Pide que se elija una fecha y muestra todos los vuelos a ese destino.
///
/// @param destinos Puntero a lista destinos.
/// @param tamD Tamanio de la lista destinos.
/// @param vuelos Puntero a lista de vuelos
/// @param tamV Tamanio de la lista.
/// @param aviones Puntero a lista de aviones.
/// @param tamAv Tamanio de la lista.
/// @param aerolineas Puntero a lista de aerolineas.
/// @param tamAe Tamamio de la lista aerolineas.
/// @param pilotos Puntero a lista de pilotos.
/// @param tamP tamanio de lista pilotos
/// @return (0) si ocurrio un error y (1) si salio bien
int viajesEnUnaFecha(eDestino destinos[], int tamD, eVuelo vuelos[], int tamV, eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, ePiloto pilotos[], int tamP);









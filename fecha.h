#ifndef FECHA_H_
#define FECHA_H_

#include "entradas.h"

typedef struct
{
	int dia;
	int mes;
	int anio;

}eFecha;

#endif /* FECHA_H_ */

/// @brief Le pide al usuario que ingrese una fecha y la valida.
///
/// @param unaFecha Puntero a una fecha
/// @return (0) si ingreso una fecha invalida o (1) si es valida.
int pedirFecha(eFecha* unaFecha);

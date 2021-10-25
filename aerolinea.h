/*
 * aerolinea.h
 *
 *  Created on: 22 oct 2021
 *      Author: Leonel
 */

#ifndef AEROLINEA_H_
#define AEROLINEA_H_

typedef struct
{
	int id;
	char descripcion[21];

}eAerolinea;



#endif /* AEROLINEA_H_ */

int cargarDescripcionAerolinea(int id, eAerolinea aerolineas[], int tamA, char descripcionAerolinea[]);

void mostrarAerolinea(eAerolinea unaAerolinea);

int mostrarAerolineas(eAerolinea aerolineas[], int tamAE);

int validarIdAerolinea(int idRecibido, eAerolinea aerolineas[], int tamAE);

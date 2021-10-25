/*
 * destino.h
 *
 *  Created on: 22 oct 2021
 *      Author: Leonel
 */

#ifndef DESTINO_H_
#define DESTINO_H_

typedef struct
{
	int id;
	char descripcion[26];
	float precio;

}eDestino;

#endif /* DESTINO_H_ */

int cargarDescripcionDestinos(int id, eDestino destinos[], int tamD, char descripcionDestino[]);
void mostrarDestino(eDestino unDestino, eDestino destinos[], int tamD);
int mostrarDestinos(eDestino destinos[], int tamD);
int validarIdDestino(int idRecibido, eDestino destinos[], int tamD);

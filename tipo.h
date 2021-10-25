/*
 * tipo.h
 *
 *  Created on: 22 oct 2021
 *      Author: Leonel
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct
{
	int id;
	char descripcion[21];

}eTipo;



#endif /* TIPO_H_ */


int cargarDescripcionTipo(int id, eTipo tipos[], int tamT, char descripcionTipo[]);
void mostrarTipo(eTipo unTipo);
int mostrarTipos(eTipo tipos[], int tamT);
int validarIdTipo(int idRecibido, eTipo tipos[], int tamT);



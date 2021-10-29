#ifndef PILOTO_H_INCLUDED
#define PILOTO_H_INCLUDED

#include "entradas.h"

typedef struct
{
    int id;
    char nombre[21];
    char sexo;

}ePiloto;




#endif // PILOTO_H_INCLUDED

int validarIdPiloto(int idRecibido, ePiloto pilotos[], int tamP);

void mostrarPiloto(ePiloto unPiloto);

int mostrarPilotos(ePiloto pilotos[], int tamP);

int cargarNombrePiloto(int idPiloto, ePiloto pilotos[], int tamP, char nombrePiloto[]);

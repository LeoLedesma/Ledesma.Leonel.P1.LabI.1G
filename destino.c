#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destino.h"


int cargarDescripcionDestinos(int id, eDestino destinos[], int tamD, char descripcionDestino[])
{
	int todoOk=0;

	if(destinos!=NULL && tamD>0)
	{
		for(int i=0; i<tamD; i++)
		{
			if(destinos[i].id==id)
			{
				strcpy(descripcionDestino, destinos[i].descripcion);
				todoOk=1;
				break;

			}
		}
	}
	return todoOk;
}

void mostrarDestino(eDestino unDestino, eDestino destinos[], int tamD)
{
    char descripcionDestino[26];

    cargarDescripcionDestinos(unDestino.id, destinos, tamD, descripcionDestino);

	printf("%d       %-10s     %.2f  \n", unDestino.id, descripcionDestino, unDestino.precio);

}

int mostrarDestinos(eDestino destinos[], int tamD)
{
	int todoOk = 0;

	if(destinos!=NULL && tamD>0)
	{
		printf("             *** Destinos ***      \n");
		printf("--------------------------------------------\n");
        printf("  ID         NOMBRE         PRECIO   \n");
		printf("--------------------------------------------\n");

		for(int i = 0; i<tamD; i++)
		{
			mostrarDestino(destinos[i], destinos, tamD);

		}
		todoOk = 1;

	}
	return todoOk;
}


int validarIdDestino(int idRecibido, eDestino destinos[], int tamD)
{
    int todoOk = 0;

    if (idRecibido > 0 && destinos != NULL && tamD > 0){
        for ( int i = 0; i < tamD; i++) {
            if (destinos[i].id == idRecibido){
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}





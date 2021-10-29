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

void mostrarDestino(eDestino unDestino)
{

  printf("%d       %-10s     %.2f  \n", unDestino.id, unDestino.descripcion, unDestino.precio);

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
			mostrarDestino(destinos[i]);

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

float cargarPrecioDestino(int idDestino, eDestino destinos[], int tamD)
{
    float precio=-1;

    if(destinos!=NULL && tamD>0 && validarIdDestino(idDestino, destinos, tamD))
    {

        for(int i = 0; i<tamD; i++)
        {
            if(idDestino==destinos[i].id)
            {
                precio=destinos[i].precio;
            }

        }



    }


    return precio;
}




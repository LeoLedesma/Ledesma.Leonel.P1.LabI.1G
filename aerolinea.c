#include <stdio.h>
#include <stdlib.h>
#include "aerolinea.h"


int cargarDescripcionAerolinea(int id, eAerolinea aerolineas[], int tamA, char descripcionAerolinea[])
{
	int todoOk=0;

	if(aerolineas!=NULL && tamA>0)
	{
		for(int i=0; i<tamA; i++)
		{
			if(aerolineas[i].id==id)
			{
				strcpy(descripcionAerolinea, aerolineas[i].descripcion);
				todoOk=1;
				break;

			}
		}
	}
	return todoOk;
}
void mostrarAerolinea(eAerolinea unaAerolinea)
{

	printf("%d       %s\n", unaAerolinea.id, unaAerolinea.descripcion);

}

int mostrarAerolineas(eAerolinea aerolineas[], int tamAE)
{
	int todoOk = 0;

	if(aerolineas!=NULL && tamAE>0)
	{
		printf("      *** Aerolineas ***      \n");
		printf("------------------------------\n");
        printf("  ID             NOMBRE   \n");
		printf("------------------------------\n");

		for(int i = 0; i<tamAE; i++)
		{
			mostrarAerolinea(aerolineas[i]);

		}
		todoOk = 1;

	}
	return todoOk;
}


int validarIdAerolinea(int idRecibido, eAerolinea aerolineas[], int tamAE)
{ int todoOk = 0;

    if (idRecibido > 0 && aerolineas != NULL && tamAE > 0){
        for ( int i = 0; i < tamAE; i++) {
            if (aerolineas[i].id == idRecibido){
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}




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



#include <stdio.h>
#include <stdlib.h>
#include "avion.h"

#define TRUE 1
#define FALSE 0

int inicializarAviones(eAvion aviones[], int tamA)
{
	int todoOk = 0;

	if(aviones!=NULL && tamA>0)
	{

		for(int i=0; i<tamA; i++)
		{
			aviones[i].isEmpty = TRUE;
			todoOk=1;
		}
	}

	return todoOk;
}

int buscarLibreAviones(eAvion aviones[], int tamA)
 {
	int index = -1;

	if (aviones != NULL && tamA > 0) {

		for (int i = 0; i < tamA; i++) {
			if(aviones[i].isEmpty == TRUE)
			{
				index=i;
				break;
			}

		}
	}

	return index;
}

int mostrarAviones()
{
	int todoOk = 0;
	int flag = 1;

if()
{
	todoOk=1;

	printf("             ***   Lista  ***\n");
	printf("------------------------------------------------\n");
	printf("                 \n");
	printf("------------------------------------------------\n");


	for(int i=0; i<tamA; i++)
	{
		if([i].isEmpty==FALSE)
		{
			mostrarestructura();
			flag=0;

		}
	}
	if(flag)
	{
		printf("No se pudieron mostrar estructuras.\n");
	}
}



return todoOk;
}

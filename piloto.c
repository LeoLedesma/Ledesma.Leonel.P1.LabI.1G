#include "piloto.h"


int cargarNombrePiloto(int idPiloto, ePiloto pilotos[], int tamP, char nombrePiloto[])
{
	int todoOk=0;

	if(pilotos!=NULL && tamP>0)
	{
		for(int i=0; i<tamP; i++)
		{
			if(pilotos[i].id==idPiloto)
			{
				strcpy(nombrePiloto, pilotos[i].nombre);
				todoOk=1;
				break;

			}
		}
	}
	return todoOk;
}

int validarIdPiloto(int idRecibido, ePiloto pilotos[], int tamP)
{
    int todoOk = 0;

    if (idRecibido > 0 && pilotos != NULL && tamP > 0){
        for ( int i = 0; i < tamP; i++) {
            if (pilotos[i].id == idRecibido){
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}

void mostrarPiloto(ePiloto unPiloto)
{

	printf("%d       %s\n", unPiloto.id, unPiloto.nombre);

}

int mostrarPilotos(ePiloto pilotos[], int tamP)
{
	int todoOk = 0;

	if(pilotos!=NULL && tamP>0)
	{
		printf("      *** Pilotos ***      \n");
		printf("------------------------------\n");
        printf("  ID             NOMBRE   \n");
		printf("------------------------------\n");

		for(int i = 0; i<tamP; i++)
		{
			mostrarPiloto(pilotos[i]);

		}
		todoOk = 1;

	}
	return todoOk;
}

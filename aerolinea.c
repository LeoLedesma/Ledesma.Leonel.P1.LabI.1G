#include "aerolinea.h"


int cargarDescripcionAerolinea(int id, eAerolinea aerolineas[], int tamAe, char descripcionAerolinea[])
{
	int todoOk=0;

	if(aerolineas!=NULL && tamAe>0)
	{
		for(int i=0; i<tamAe; i++)
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

int mostrarAerolineas(eAerolinea aerolineas[], int tamAe)
{
	int todoOk = 0;

	if(aerolineas!=NULL && tamAe>0)
	{
		printf("      *** Aerolineas ***      \n");
		printf("------------------------------\n");
        printf("  ID             NOMBRE   \n");
		printf("------------------------------\n");

		for(int i = 0; i<tamAe; i++)
		{
			mostrarAerolinea(aerolineas[i]);

		}
		todoOk = 1;

	}
	return todoOk;
}

int validarIdAerolinea(int idRecibido, eAerolinea aerolineas[], int tamAe)
{
    int todoOk = 0;

    if (idRecibido > 0 && aerolineas != NULL && tamAe > 0){
        for ( int i = 0; i < tamAe; i++) {
            if (aerolineas[i].id == idRecibido){
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}

int pedirIdAerolinea(char mensaje[], char mensajeError[], int* pIdIngresado, int intentos, eAerolinea aerolineas[], int tamA)
{
    int todoOk=0;
    int auxId;

    if(mensaje!=NULL && mensajeError!=NULL && pIdIngresado!=NULL && intentos>0 && aerolineas!=NULL && tamA>0)
    {
        getInt(mensaje, mensajeError, &auxId);

        while(!validarIdAerolinea(auxId, aerolineas, tamA)&& intentos>0)
        {
            printf("ERROR. ID invalido, le quedan %d intentos. ", intentos);
            intentos--;
            getInt(mensaje, mensajeError, pIdIngresado);
        }

        if(intentos>0)
        {
            *pIdIngresado=auxId;
            todoOk=1;
        }

    }

    return todoOk;
}



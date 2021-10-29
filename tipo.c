#include "tipo.h"


int cargarDescripcionTipo(int id, eTipo tipos[], int tamT, char descripcionTipo[])
{
    int todoOk=0;

    if(tipos!=NULL && tamT>0)
    {
        for(int i=0; i<tamT; i++)
        {
            if(tipos[i].id==id)
            {
                strcpy(descripcionTipo, tipos[i].descripcion);
                todoOk=1;
                break;

            }
        }
    }
    return todoOk;
}

void mostrarTipo(eTipo unTipo)
{

    printf("%d       %s\n", unTipo.id, unTipo.descripcion);

}

int mostrarTipos(eTipo tipos[], int tamT)
{
    int todoOk = 0;

    if(tipos!=NULL && tamT>0)
    {
        printf("      *** Tipos ***      \n");
        printf("------------------------------\n");
        printf("  ID             Tipo   \n");
        printf("------------------------------\n");

        for(int i = 0; i<tamT; i++)
        {
            mostrarTipo(tipos[i]);

        }
        todoOk = 1;

    }
    return todoOk;
}

int validarIdTipo(int idRecibido, eTipo tipos[], int tamT)
{
    int todoOk = 0;

    if (idRecibido > 0 && tipos != NULL && tamT > 0)
    {
        for ( int i = 0; i < tamT; i++)
        {
            if (tipos[i].id == idRecibido)
            {
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}

int pedirIdTipo(char mensaje[], char mensajeError[], int* idIngresado, int intentos, eTipo tipos[], int tamT)
{
    int todoOk=0;
    if(mensaje!=NULL && mensajeError!=NULL && idIngresado!=NULL && intentos>0 && tipos!=NULL && tamT>0)
    {
        getInt( mensaje, mensajeError, idIngresado);

        while(!validarIdTipo(*idIngresado, tipos, tamT)&& intentos>0)
        {
            printf("ERROR. ID invalido, le quedan %d intentos. ", intentos);
            intentos--;
            getInt(mensaje, mensajeError, idIngresado);
        }

        if(intentos>0)
        {
            todoOk=1;
        }

    }

    return todoOk;
}

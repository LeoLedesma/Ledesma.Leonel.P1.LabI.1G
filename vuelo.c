#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vuelo.h"
#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#include "entradas.h"
#include "destino.h"

#define TRUE 1
#define FALSE 0

int inicializarVuelos(eVuelo vuelos[], int tamV)
{
    int todoOk = 0;

    if(vuelos!=NULL && tamV>0)
    {

        for(int i=0; i<tamV; i++)
        {
            vuelos[i].isEmpty = TRUE;
            todoOk=1;
        }
    }


    return todoOk;
}

int buscarLibreVuelo(eVuelo vuelos[], int tamV)
{
    int indice = -1;

    if (vuelos != NULL && tamV > 0)
    {
        for (int i = 0; i < tamV; i++)
        {
            if (vuelos[i].isEmpty == TRUE)
            {
                indice = i;
                break;

            }

        }

    }

    return indice;
}


int altaVuelo(eVuelo vuelos[], int tamV, eAvion aviones[], int tamAV, eTipo tipos [], int tamT, eAerolinea aerolineas[], int tamAE, eDestino destinos[], int tamD, int* pIdVuelo)
{
    int todoOk=0;
    int indice;

    eVuelo unVuelo;

    if(vuelos!=NULL && tamV>0 &&  aviones!=NULL &&  tamAV>0 && tipos!=NULL && tamT>0 && aerolineas!=NULL && tamAE>0 && destinos!=NULL && tamD>0)
    {
        indice = buscarLibreVuelo(vuelos, tamV);

        if(indice==-1)
        {
            printf("No hay lugar para cargar nuevos vuelos. Dirigiendose al menu principal.\n");
        }
        else
        {
            printf("                         *** Alta vuelos ***\n");
            printf("-----------------------------------------------------------------------\n\n");
            unVuelo.id = *pIdVuelo;
            (*pIdVuelo)++;

            mostrarAviones(aviones, tamAV, aerolineas, tamAE, tipos, tamT);

            getInt("\nIngrese el id del avion a iniciar el vuelo: ",
                   "ERROR. Ingrese el id del avion a iniciar el vuelo: (solo numeros) ",
                   &unVuelo.idAvion);

            while (buscarAvionId(aviones, tamAV, unVuelo.idAvion) == -1)
            {

                getInt("\nERROR ID INVALIDA. Ingrese el id del avion a iniciar el vuelo: ",
                       "ERROR. Ingrese el id del avion a iniciar el vuelo: (solo numeros) ",
                       &unVuelo.idAvion);
            }

            mostrarDestinos(destinos, tamD);
            getInt("\nIngrese el id del destino a viajar: ",
                   "ERROR. Ingrese el id del destino a viajar: (solo numeros) ",
                   &unVuelo.idDestino);

            while (!validarIdDestino(unVuelo.idDestino, destinos, tamD))
            {

                getInt(	"\nERROR ID INVALIDA. Ingrese el id del destino a viajar: ",
                        "ERROR. Ingrese el id del destino a viajar: (solo numeros) ",
                        &unVuelo.idDestino);
            }

            getInt("Ingrese dia: ", "ERROR: Ingrese dia: (solo numeros)",
                   &unVuelo.fecha.dia);
            while (unVuelo.fecha.dia < 1 || unVuelo.fecha.dia > 31)
            {
                getInt("ERROR. Ingrese dia valido: ",
                       "ERROR: Ingrese dia valido: (solo numeros)",
                       &unVuelo.fecha.dia);
            }
            getInt("Ingrese mes: ", "ERROR: Ingrese mes: (solo numeros)",
                   &unVuelo.fecha.mes);
            while (unVuelo.fecha.mes < 1 || unVuelo.fecha.mes > 12)
            {
                getInt("ERROR. Ingrese mes valido: ",
                       "ERROR: Ingrese mes valido: (solo numeros)",
                       &unVuelo.fecha.mes);
            }
            getInt("Ingrese anio: ", "ERROR: Ingrese anio: (solo numeros)",
                   &unVuelo.fecha.anio);
            while (unVuelo.fecha.anio < 0 || unVuelo.fecha.anio > 9999)
            {
                getInt("ERROR. Ingrese anio valido: ",
                       "ERROR: Ingrese anio valido: (solo numeros)",
                       &unVuelo.fecha.anio);
            }

            unVuelo.isEmpty=FALSE;
            vuelos[indice] = unVuelo;
            todoOk=1;
            printf("Vuelo cargado con exito!!\n");

        }







    }





    return todoOk;
}

void mostrarVuelo(eVuelo unVuelo, eAvion aviones[], int  tamAV, eDestino destinos[], int tamD)
{
    char descripcionDestino[20];

    cargarDescripcionDestinos(unVuelo.idDestino, destinos, tamD, descripcionDestino);

    printf("%4d       %4d   %10s   %02d/%02d/%04d\n",
           unVuelo.id,
           unVuelo.idAvion,
           descripcionDestino,
           unVuelo.fecha.dia,
           unVuelo.fecha.mes,
           unVuelo.fecha.anio);


}

int mostrarVuelos(eVuelo vuelos[], int tamV, eAvion aviones[], int  tamAV, eDestino destinos[], int tamD)
{
    int todoOk=0;
    if(vuelos!=NULL && tamV>0 &&  aviones!=NULL &&  tamAV>0 && destinos!=NULL && tamD>0)
    {
        printf("          *** Vuelos ***\n");
        printf("------------------------------------------\n");
        printf("Id Vuelo   Id avion   Destino   Fecha \n");

        printf("------------------------------------------\n");
        for (int i = 0; i<tamV; i++)
        {
            todoOk=1;

            if(vuelos[i].isEmpty==FALSE)
            {
                mostrarVuelo(vuelos[i],  aviones,  tamAV,  destinos, tamD);

            }




        }







    }


    return todoOk;
}

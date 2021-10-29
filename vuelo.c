#include "vuelo.h"


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


int altaVuelo(eVuelo vuelos[], int tamV, eAvion aviones[], int tamAv, eTipo tipos [], int tamT, eAerolinea aerolineas[], int tamAe, eDestino destinos[], int tamD, int* pIdVuelo, ePiloto pilotos[], int tamP)
{
    int todoOk=0;
    int indice;
    int fechaValida;

    eVuelo unVuelo;

    if(vuelos!=NULL && tamV>0 &&  aviones!=NULL &&  tamAv>0 && tipos!=NULL && tamT>0 && aerolineas!=NULL && tamAe>0 && destinos!=NULL && tamD>0)
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

            mostrarAviones(aviones, tamAv, aerolineas, tamAe, tipos, tamT, pilotos, tamP);

            getInt("\nIngrese el id del avion a iniciar el vuelo: ",
                   "ERROR. Ingrese el id del avion a iniciar el vuelo: (solo numeros) ",
                   &unVuelo.idAvion);

            while (buscarAvionId(aviones, tamAv, unVuelo.idAvion) == -1)
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

            fechaValida = pedirFecha(&unVuelo.fecha);

            while(!fechaValida)
            {
                printf("Fecha invalida! Intente nuevamente \n");
                fechaValida = pedirFecha(&unVuelo.fecha);
            }

                unVuelo.isEmpty=FALSE;
                vuelos[indice] = unVuelo;
                todoOk=1;
                printf("Vuelo cargado con exito!!\n");



        }

    }
    return todoOk;
}

void mostrarVuelo(eVuelo unVuelo, eAvion aviones[], int  tamAv, eDestino destinos[], int tamD, eAerolinea aerolineas [], int tamAe)
{
    char descripcionDestino[26];
    char descripcionAerolinea[21];

    cargarDescripcionAerolineaAvion(aviones, tamAv, unVuelo.idAvion, descripcionAerolinea, aerolineas, tamAe);
    cargarDescripcionDestinos(unVuelo.idDestino, destinos, tamD, descripcionDestino);

    printf("%4d       %4d       %-10s   %-10s   %02d/%02d/%04d\n",
           unVuelo.id,
           unVuelo.idAvion,
           descripcionAerolinea,
           descripcionDestino,
           unVuelo.fecha.dia,
           unVuelo.fecha.mes,
           unVuelo.fecha.anio);


}

int mostrarVuelos(eVuelo vuelos[], int tamV, eAvion aviones[], int  tamAv, eDestino destinos[], int tamD, eAerolinea aerolineas [], int tamAe)
{
    int todoOk=0;
    if(vuelos!=NULL && tamV>0 &&  aviones!=NULL &&  tamAv>0 && destinos!=NULL && tamD>0)
    {
        printf("                 *** Vuelos ***\n");
        printf("-------------------------------------------------------------\n");
        printf("Id Vuelo   Id avion   Aerolinea    Destino         Fecha \n");
        printf("--------------------------------------------------------------\n");
        for (int i = 0; i<tamV; i++)
        {
            todoOk=1;

            if(vuelos[i].isEmpty==FALSE)
            {
                mostrarVuelo(vuelos[i],  aviones,  tamAv,  destinos, tamD, aerolineas, tamAe);

            }
        }
    }


    return todoOk;
}

void graficoListaVuelos()
{
    printf("-------------------------------------------------------------\n");
    printf("Id Vuelo   Id avion   Aerolinea    Destino         Fecha \n");
    printf("--------------------------------------------------------------\n");



}

//--------- informes

int mostrarVuelosAvion(eVuelo vuelos[], int tamV, eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, eTipo tipos[], int tamT, eDestino destinos[], int tamD, ePiloto pilotos[], int tamP)
{
    int todoOk = 0;
    int idIngresado;
    int intentos=3;

    if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAe>0 && tipos!=NULL && tamT>0 && vuelos!=NULL && tamV>0 && destinos!=NULL && tamD>0 && pilotos!=NULL && tamP>0)
    {
        system("cls");
        todoOk=1;

        mostrarAviones(aviones, tamAv, aerolineas, tamAe, tipos, tamT, pilotos, tamD);

        getInt("Por favor seleccione el ID del avion que quiere mostrar: ", "ERROR. Seleccione el ID del avion que quiere mostrar: (sin numeros)", &idIngresado);

        while(buscarAvionId(aviones, tamAv, idIngresado)==-1 && intentos>0)
        {
            printf("ERROR. ID invalido, le quedan %d intentos. ", intentos);
            intentos--;
            getInt("Por favor seleccione el ID del avion que quiere mostrar: ", "ERROR. Seleccione el ID del avion que quiere mostrar: (sin numeros)", &idIngresado);
        }

        if(intentos>0)
        {
            printf("   *** Vuelos del avion con id: %d ***\n", idIngresado);
            graficoListaVuelos();
            for(int i = 0; i<tamV; i++)
            {
                if(!vuelos[i].isEmpty && vuelos[i].idAvion==idIngresado)
                {
                    mostrarVuelo(vuelos[i], aviones, tamAv, destinos, tamD, aerolineas, tamAe);

                }

            }

        }
    }


    return todoOk;
}



int mostrarSumaViajesAvion(eVuelo vuelos[], int tamV, eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, eTipo tipos[], int tamT, eDestino destinos[], int tamD, ePiloto pilotos[], int tamP)
{
    int todoOk = 0;
    float acumuladoPrecio=0;
    int intentos=3;
    int idIngresado;
    int flag=0;


    if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAe>0 && tipos!=NULL && tamT>0 && vuelos!=NULL && tamV>0 && destinos!=NULL && tamD>0 && pilotos!=NULL && tamP>0)
    {
        system("cls");
        todoOk=1;

        mostrarAviones(aviones, tamAv, aerolineas, tamAe, tipos, tamT, pilotos, tamP);

        getInt("Por favor seleccione el ID del avion que quiere mostrar: ", "ERROR. Seleccione el ID del avion que quiere mostrar: (sin numeros)", &idIngresado);

        while(buscarAvionId(aviones, tamAv, idIngresado)==-1 && intentos>0)
        {
            printf("ERROR. ID invalido, le quedan %d intentos. ", intentos);
            intentos--;
            getInt("Por favor seleccione el ID del avion que quiere mostrar: ", "ERROR. Seleccione el ID del avion que quiere mostrar: (sin numeros)", &idIngresado);
        }

        if(intentos>0)
        {

            for(int i = 0; i<tamV; i++)
            {
                if(!vuelos[i].isEmpty && vuelos[i].idAvion==idIngresado)
                {

                    acumuladoPrecio+=cargarPrecioDestino(vuelos[i].idDestino, destinos, tamD);
                    flag=1;
                }
            }

            if(flag)
            {
                printf("El dinero ganado total del avion fue: %.2f.\n", acumuladoPrecio);
            }

        }



    }



    return todoOk;
}

int mostrarVueloDeUnDestino(eDestino destinos[], int tamD, eVuelo vuelos[], int tamV, eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, ePiloto pilotos[], int tamP)
{
    int todoOk=0;
    int intentos=3;
    int idIngresado;
    char descripcionDestino[26];
    int flag=0;
    if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAe>0 && vuelos!=NULL && tamV>0 && destinos!=NULL && tamD>0 && pilotos!=NULL && tamP>0)
    {
        todoOk=1;
        system("cls");


        mostrarDestinos(destinos, tamD);

        getInt("Por favor seleccione el ID del destino que quiere mostrar: ", "ERROR. Seleccione el ID del destino que quiere mostrar: (sin numeros)", &idIngresado);

        while(!validarIdDestino(idIngresado, destinos, tamD) && intentos>0)
        {
            printf("ERROR. ID invalido, le quedan %d intentos. ", intentos);
            intentos--;
            getInt("Por favor seleccione el ID del destino que quiere mostrar: ", "ERROR. Seleccione el ID del destino que quiere mostrar: (sin numeros)", &idIngresado);
        }

        if(intentos>0)
        {
            system("cls");
            cargarDescripcionDestinos(idIngresado, destinos, tamD, descripcionDestino);
            printf("*** Vuelos a %s *** \n", descripcionDestino);
            graficoListaVuelos();
            for(int i=0; i<tamV; i++)
            {
                if(!vuelos[i].isEmpty && vuelos[i].idDestino==idIngresado)
                {

                    mostrarVuelo(vuelos[i], aviones, tamAv, destinos, tamD, aerolineas, tamAe);
                    flag=1;
                }



            }

            if(!flag)
            {
                system("cls");
                printf("No hay vuelos a %s registrados.\n", descripcionDestino);

            }


        }



    }
    return todoOk;
}

int viajesEnUnaFecha(eDestino destinos[], int tamD, eVuelo vuelos[], int tamV, eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, ePiloto pilotos[], int tamP)
{
    int todoOk=0;
    eFecha unaFecha;
    int flag=0;
    int fechaValida;

    if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAe>0 && vuelos!=NULL && tamV>0 && destinos!=NULL && tamD>0 && pilotos!=NULL && tamP>0)
    {
        printf("ingrese una fecha para mostrar los viajes: \n");

        fechaValida = pedirFecha(&unaFecha);

        while(!fechaValida)
        {
            printf("Fecha invalida! Intente nuevamente \n");
            fechaValida = pedirFecha(&unaFecha);
        }

            system("cls");
            printf("  *** Vuelos del %2d/%2d/%2d ***\n", unaFecha.dia, unaFecha.mes, unaFecha.anio);
            graficoListaVuelos();
            for(int i=0; i<tamV; i++)
            {
                if(!vuelos[i].isEmpty && vuelos[i].fecha.dia==unaFecha.dia &&
                        vuelos[i].fecha.mes==unaFecha.mes &&
                        vuelos[i].fecha.anio == unaFecha.anio)
                {
                    mostrarVuelo(vuelos[i], aviones, tamAv, destinos, tamD, aerolineas, tamAe);
                    flag=1;
                }



            }

            if(!flag)
            {
                printf("No hay vuelos en esa fecha.\n");
            }




    }

    return todoOk;
}

#include "avion.h"


#define TRUE 1
#define FALSE 0
#define INTENTOS 3



int inicializarAviones(eAvion aviones[], int tamAv)
{
    int todoOk = 0;

    if(aviones!=NULL && tamAv>0)
    {

        for(int i=0; i<tamAv; i++)
        {
            aviones[i].isEmpty = TRUE;
            todoOk=1;
        }
    }

    return todoOk;
}

int buscarLibreAviones(eAvion aviones[], int tamAv)
{
    int index = -1;

    if (aviones != NULL && tamAv > 0)
    {

        for (int i = 0; i < tamAv; i++)
        {
            if(aviones[i].isEmpty == TRUE)
            {
                index=i;
                break;
            }

        }
    }

    return index;
}

void mostrarAvion(eAvion unAvion, eAerolinea aerolineas[], int tamAe, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP)
{

if(aerolineas!=NULL && tamAe>0 && tipos!=NULL && tamT>0 && pilotos!=NULL && tamP>0)
{
    char descripcionAerolinea[21];
    char descripcionTipo[21];
    char nombrePiloto[21];

    cargarDescripcionAerolinea(unAvion.idAerolinea, aerolineas, tamAe, descripcionAerolinea);
    cargarDescripcionTipo(unAvion.idTipo, tipos, tamT, descripcionTipo);
    cargarNombrePiloto(unAvion.idPiloto, pilotos, tamP, nombrePiloto);

    printf("%4d   %-10s       %-10s     %03d         %-10s\n", unAvion.id, descripcionAerolinea, descripcionTipo, unAvion.capacidad, nombrePiloto);
}

}

int mostrarAviones(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP)
{

    int todoOk = -1;
    int flag = 1;

    if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAe>0 && tipos!=NULL && tamT>0 && pilotos!=NULL && tamP>0)
    {
        todoOk=1;
        printf("             ***   Lista de aviones ***\n");
        printf("------------------------------------------------------------\n");
        printf("Id     Aerolinea          Tipo        Capacidad     Piloto\n");
        printf("-------------------------------------------------------------\n");


        ordenarAviones(aviones, tamAv, aerolineas, tamAe);

        for(int i=0; i<tamAv; i++)
        {
            if(aviones[i].isEmpty==FALSE)
            {
                mostrarAvion(aviones[i], aerolineas, tamAe, tipos, tamT, pilotos, tamP);
                flag=0;

            }
        }
        if(flag)
        {
            printf("No se pudieron mostrar aviones.\n");
        }



    }




    return todoOk;
}


int buscarAvionId(eAvion aviones[], int tamAv, int idRecibido)
{
    int indice = -1;

    if (aviones != NULL && tamAv > 0)
    {
        for (int i = 0; i < tamAv; i++)
        {
            if (!aviones[i].isEmpty && aviones[i].id == idRecibido)
            {
                indice = i;
                break;

            }

        }

    }

    return indice;
}

int altaAviones(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP)
{
    int todoOk = -1;
    int indice;
    int intentos=INTENTOS;
    eAvion auxAvion;

    if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAe>0 && tipos!=NULL && tamT>0 && pilotos!=NULL && tamP>0 && pilotos!=NULL && tamP>0)
    {


        indice = buscarLibreAviones(aviones, tamAv);
        if(indice==-1) //
        {
            printf("No hay espacio para cargar\n");

        }
        else
        {
            printf("   *** Alta de aviones***\n");
            printf("--------------------------\n");



            //PIDO
            getInt("Ingrese el id del avion: ", "ERROR. ingrese el id del avion. (Solo numeros): ", &auxAvion.id);

            while(buscarAvionId(aviones, tamAv, auxAvion.id)!=-1 && intentos>0)
            {
                printf("Le quedan %d intentos", intentos);
                intentos--;
                getInt("ERROR EL ID YA EXISTE, intente nuevamente con otro id: ", "ERROR. ingrese el id del avion. (Solo numeros): ", &auxAvion.id);

            }

            mostrarAerolineas(aerolineas, tamAe);

            getInt("\nIngrese el id de la aerolinea: ", "ERROR. Ingrese el id de la aerolinea. (Solo numeros): ", &auxAvion.idAerolinea);

            while(!validarIdAerolinea(auxAvion.idAerolinea, aerolineas, tamAe))
            {
                getInt("\nID Invalido. Ingrese el id de la aerolinea valido: ", "ERROR. el id de la aerolinea. (Solo numeros): ", &auxAvion.idAerolinea);


            }

            mostrarTipos(tipos, tamT);
            getInt("\nIngrese el id del tipo: ", "ERROR. el id del tipo. (Solo numeros): ", &auxAvion.idTipo);

            while(!validarIdTipo(auxAvion.idTipo, tipos, tamT))
            {
                getInt("\nID Invalido. Ingrese el id del tipo valido: ", "ERROR. Ingrese el id del tipo (Solo numeros): ", &auxAvion.idTipo);

            }

            getInt("\nIngrese la capacidad del avion: ", "ERROR.Ingrese la capacidad del avion. (Solo numeros): ", &auxAvion.capacidad);

            while(auxAvion.capacidad<10 || auxAvion.capacidad>300)
            {
                getInt("\nCAPACIDAD INVALIDA. Ingrese la capacidad del avion: (10-300) ", "ERROR. Ingrese la capacidad del avion. (Solo numeros): ", &auxAvion.capacidad);

            }

            mostrarPilotos(pilotos, tamP);
            getInt("\nIngrese el id del piloto: ", "ERROR.Ingrese la capacidad del avion. (Solo numeros): ", &auxAvion.idPiloto);

            while(!validarIdPiloto(auxAvion.idPiloto, pilotos, tamP))
            {
                getInt("\n ID PILOTO INVALIDO. Ingrese el id del piloto: ",  "ERROR.Ingrese la capacidad del avion. (Solo numeros): ", &auxAvion.idPiloto);
            }

            auxAvion.isEmpty=FALSE;
            aviones[indice]=auxAvion;

            printf("Avion cargado con exito!!\n");
            todoOk=1;
        }
    }




    return todoOk;
}

int bajaAviones(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP)
{
    int todoOk=-1;
    int idIngresado;
    int indice;
    char confirmacion;
    eAvion auxAviones[1];

    if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAe>0 && tipos!=NULL && tamT>0 && pilotos!=NULL && tamP>0)
    {
        system("cls");
        printf("    *** Baja Aviones ***\n");
        printf("--------------------------\n");

        //muestro
        mostrarAviones(aviones, tamAv, aerolineas, tamAe, tipos, tamT, pilotos, tamP);

        //pido id
        getInt("Ingrese ID del avion a dar de baja: ", "\nError, ID invalido, reingrese ID del avion a dar de baja: ", &idIngresado);
        indice = buscarAvionId(aviones, tamAv, idIngresado); //busco si el id existe.

        if (indice == -1)
        {
            printf("El id ingresado no existe.\n");
        }
        else
        {

            auxAviones[0] = aviones[indice];

            mostrarAviones(auxAviones, 1, aerolineas, tamAe, tipos, tamT, pilotos, tamP);

            confirmacion = getConfirmation("Los datos son los correctos? (s/n):", "ERROR. Los datos son los correctos? (s/n): ");

            /*
                 utn_getCaracter(&confirmacion, "Los datos son los correctos? (s/n): ", "ERROR. Los datos son los correctos? (s/n): ", 'A', 'z',1);
                 confirmacion = tolower(confirmacion);

                 while(confirmacion!='s' && confirmacion!='n')
                 {
                     utn_getCaracter(&confirmacion, "Los datos son los correctos? (s/n): ", "ERROR. Los datos son los correctos? (s/n): ", 'A', 'z',1);
                     confirmacion = tolower(confirmacion);
                 }*/

            if(confirmacion=='s')
            {
                auxAviones[0].isEmpty = 1;
                aviones[indice] = auxAviones[0];

                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada. Volviendo al menu principal.\n");
                todoOk=0;
            }
        }
    }
    return todoOk;
}

int modificarAvion(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP)
{
    int todoOk = -1;
    int indice;
    int opcion;
    int seguir = 'n';
    int confirmacion;
    int idIngresado;
    int auxIdTipo;
    int auxCapacidad;

    eAvion auxAviones[1];

    if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAe>0 && tipos!=NULL && tamT>0 && pilotos!=NULL && tamP>0)
    {

        system("cls");
        printf("           *** Modificacion Aviones***\n");
        printf("-----------------------------------------------------\n\n");



        //muestro y pido
        mostrarAviones(aviones, tamAv, aerolineas, tamAe, tipos, tamT, pilotos, tamP);

        getInt("\nIngrese id del avion a modificar: ", "ERROR. Ingrese el id del avion a modificar (solo numeros): ", &idIngresado);


        indice = buscarAvionId(aviones, tamAv, idIngresado); //valido que exista

        if (indice == -1) //no existe y salgo
        {
            printf("No existe el ID ingresado. Dirigiendose al menu principal\n");
            todoOk = 0;
        }
        else
        {
            system("cls");
            auxAviones[0] = aviones[indice];

            mostrarAviones(auxAviones, 1, aerolineas, tamAe, tipos, tamT, pilotos, tamP);
            confirmacion = getConfirmation(
                               "\nEl avion mostrado es el correcto? (s/n): ",
                               "ERROR. El avion mostrado es el correcto? (s/n): ");
            confirmacion = tolower(confirmacion);

            if (confirmacion == 's')
            {
                auxAviones[0] = aviones[indice];
                do
                {



                    system("cls");
                    printf("           *** Modificacion Aviones***\n");
                    printf("-----------------------------------------------------\n\n");


                    printf("Que desea modificar de \n");
                    mostrarAviones(auxAviones, 1, aerolineas, tamAe, tipos, tamT, pilotos, tamP);

                    printf("\n1) Tipo\n");
                    printf("2) Capacidad\n");
                    printf("3) Salir\n");

                    getInt("Por favor seleccione una opcion: ",	"Por favor seleccione una opcion: (solo numeros)", &opcion);

                    switch (opcion)
                    {
                    case 1:
                        mostrarTipos(tipos, tamT);


                        if(pedirIdTipo("Por favor seleccione el id del nuevo tipo: ", "ERROR. Por favor seleccione el id del nuevo tipo: (solo numeros)", &auxIdTipo, INTENTOS, tipos, tamT))
                        {
                            aviones[indice].idTipo = auxIdTipo;
                            todoOk = 1;

                        }


                        break;
                    case 2:
                        getInt("Por favor ingrese la nueva capacidad del avion: ", "ERROR. Por favor ingrese la neuva capacidad del avion (solo numeros): ", &auxCapacidad);
                        while(auxCapacidad<10 || auxCapacidad>300)
                        {
                            getInt("Capacidad invalida. Por favor ingrese la nueva capacidad del avion: (10-300)",	"ERROR: Por favor ingrese la nueva capacidad del avion (10-300) (solo numeros)", &auxCapacidad);

                        }

                        aviones[indice].capacidad = auxCapacidad;


                        todoOk = 1;
                        break;
                    case 3:
                        printf("Saliendo al menu principal\n");
                        todoOk = 0;
                        break;
                    default:
                        printf("ERROR. Entrada incorrecta, intente nuevamente");
                        seguir='s';
                        break;
                    }

                }
                while(seguir!='n');


            }

        }


    }
    return todoOk;
}


int ordenarAviones(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe)
{
    int todoOk=0;
    char descripcionAerolineaI[21];
    char descripcionAerolineaJ[21];

    eAvion auxAvion;

    if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAe>0)
    {

        for (int i = 0; i < tamAv - 1; i++)
        {


            for (int j = i + 1; j < tamAv; j++)
            {

                cargarDescripcionAerolinea(aviones[i].idAerolinea, aerolineas, tamAe, descripcionAerolineaI);
                cargarDescripcionAerolinea(aviones[j].idAerolinea, aerolineas, tamAe, descripcionAerolineaJ);

                if(strcmp(descripcionAerolineaI, descripcionAerolineaJ)>0 ||
                        (strcmp(descripcionAerolineaI, descripcionAerolineaJ)==0 && aviones[i].capacidad > aviones[j].capacidad))
                {
                    auxAvion = aviones[i];
                    aviones[i] = aviones[j];
                    aviones[j] = auxAvion;

                }

            }

        }



        todoOk=1;
    }


    return todoOk;
}

int cargarDescripcionAerolineaAvion(eAvion aviones[], int tamAv, int idAvionRecibido, char descripcion[], eAerolinea aerolineas[], int tamAe)
{
    int todoOk = 0;

    char descAerolinea[21];

    if (idAvionRecibido > 0 && aviones != NULL && tamAv > 0 && aerolineas!=NULL && tamAe>0)
    {

        for (int i = 0; i < tamAv; i++)
        {
            if (aviones[i].id == idAvionRecibido)
            {
                cargarDescripcionAerolinea(aviones[i].idAerolinea, aerolineas, tamAe, descAerolinea);
                strcpy(descripcion, descAerolinea);
                todoOk=1;
                break;

            }
        }
    }

    return todoOk;
}




void graficoListaAviones()
{
        printf("------------------------------------------------------------\n");
        printf("Id     Aerolinea          Tipo        Capacidad     Piloto\n");
        printf("-------------------------------------------------------------\n");


}




//INFORMES

int mostrarAvionesAerolineaSeleccionada(eAvion aviones[], int tamAv, eTipo tipos[], int tamT, eAerolinea aerolineas[], int tamAe, ePiloto pilotos[], int tamP)
{
    int todoOk=0;
    int idAerolineaRecibido;
    int intentos=3;
    char descripcionAerolinea[21];
    int flag = 0;

    if(aviones!=NULL && tamAv>0 && tipos!=NULL && tamT>0 && pilotos!=NULL && tamP>0)
    {
        todoOk=1;
        system("cls");

        mostrarAerolineas(aerolineas, tamAe);

        getInt("Por favor seleccione el ID de la aerolinea que quiere mostrar: ", "ERROR. Seleccione el ID de la aerolinea que quiere mostrar (sin numeros)", &idAerolineaRecibido);

        while(!validarIdAerolinea(idAerolineaRecibido, aerolineas, tamAe)&& intentos>0)
        {
            printf("ERROR. ID invalido, le quedan %d intentos. ", intentos);
            intentos--;
            getInt("Por favor seleccione el ID de la aerolinea que quiere mostrar: ", "ERROR. Seleccione el ID de la aerolinea que quiere mostrar (sin numeros)", &idAerolineaRecibido);
        }

        if(intentos>0) //Si logro ingresar un ID valido, entra.
        {
            system("cls");
            cargarDescripcionAerolinea(idAerolineaRecibido, aerolineas, tamAe, descripcionAerolinea);
            printf("    ***Lista de aviones de aerolinea %s*** \n", descripcionAerolinea);

            graficoListaAviones();

            for(int i = 0; i<tamAv; i++)
            {
                if(aviones[i].idAerolinea==idAerolineaRecibido && !aviones[i].isEmpty)
                {
                    mostrarAvion(aviones[i], aerolineas, tamAe, tipos, tamT, pilotos, tamP);
                    flag=1;
                }
            }

            if(!flag)
            {
                system("cls");
                printf("No hay ningun avion de la aerolinea %s.\n", descripcionAerolinea);
            }

        }
        else
        {
            printf("Cantidad de reintetos superado. Dirigiendose al menu principal.\n");
        }

    }
    return todoOk;
}

int mostrarAvionesTipoSeleccionado(eAvion aviones[], int tamAv, eTipo tipos[], int tamT, eAerolinea aerolineas[], int tamAe, ePiloto pilotos[], int tamP)
{
    int todoOk=0;
    int idTipoRecibido;
    int retornoTipo;
    char descripcionTipo[21];
    int flag = 0;

    if(aviones!=NULL && tamAv>0 && tipos!=NULL && tamT>0 && pilotos!=NULL && tamP>0)
    {
        todoOk=1;
        system("cls");

        mostrarTipos(tipos, tamT);

        retornoTipo = pedirIdTipo("Por favor seleccione el ID del tipo que quiere mostrar: ", "ERROR. Seleccione el ID del tipo que quiere mostrar (sin numeros): ", &idTipoRecibido, INTENTOS, tipos, tamT);

        if(retornoTipo) //Si logro ingresar un ID valido, entra.
        {
            system("cls");
            cargarDescripcionTipo(idTipoRecibido, tipos, tamT, descripcionTipo);
            printf("    ***Lista de aviones del tipo %s*** \n", descripcionTipo);
            graficoListaAviones();



            for(int i = 0; i<tamAv; i++)
            {
                if(aviones[i].idTipo==idTipoRecibido && !aviones[i].isEmpty)
                {
                    mostrarAvion(aviones[i], aerolineas, tamAe, tipos, tamT, pilotos, tamP);
                    flag=1;
                }
            }

            if(!flag)
            {
                system("cls");
                printf("No hay ningun avion del tipo %s.\n", descripcionTipo);
            }

        }
        else
        {
            printf("Cantidad de reintetos superado. Dirigiendose al menu principal.\n");
        }

    }
    return todoOk;
}

int mostrarAvionesPorAerolinea(eAvion aviones[], int tamAv, eTipo tipos[], int tamT, eAerolinea aerolineas[], int tamAe, ePiloto pilotos[], int tamP)
{
    int todoOk=0;
    int flag;
    char descripcionAerolinea[21];
    if(aviones!=NULL && tamAv>0 && tipos!=NULL && tamT>0 && aerolineas!=NULL && tamAe>0 && pilotos!=NULL && tamP)
    {
        system("cls");
        todoOk=1;

        for(int i = 0; i<tamT; i++)
        {
            flag=0;
            cargarDescripcionAerolinea(aviones[i].idAerolinea, aerolineas, tamAv, descripcionAerolinea);
            printf("\n\nAviones de la aerolinea %s: \n", descripcionAerolinea);
            graficoListaAviones();
            for(int j = 0; j<tamAv; j++)
            {

                if(!aviones[j].isEmpty && aviones[j].idAerolinea==aerolineas[i].id)
                {
                    mostrarAvion(aviones[j], aerolineas, tamAe, tipos, tamT, pilotos, tamP);
                    flag=1;
                }



            }
            if(flag!=1)
            {

                printf("\nNo se encontro ningun avion de la aerolinea %s\n", descripcionAerolinea);


            }
        }
    }
    return todoOk;
}


int porcentajeAvionesJetAerolinea(eAerolinea aerolineas[], int tamAe, eAvion aviones[], int tamAv)
{
    int todoOk=0;
    int idAerolinea;
    int contadorAvionesAerolinea=0;
    int contadorJet;
    float porcentaje;
    char descripcionAerolinea[21];
    int idValido;


    if(aerolineas!=NULL && tamAe>0 && aviones!=NULL && tamAv>0)
    {
        todoOk=1;
         system("cls");

        mostrarAerolineas(aerolineas, tamAe);

        idValido = pedirIdAerolinea("\nPor favor ingrese el ID de la aerolinea que quiera saber el porcentaje de aviones JET: ", "Por favor ingrese el ID de la aerolinea que quiera saber el porcentaje de aviones JET (solo numeros): ", &idAerolinea, INTENTOS, aerolineas, tamAe);
        if(idValido)
        {

            cargarDescripcionAerolinea(idAerolinea, aerolineas, tamAe, descripcionAerolinea);



            for(int i=0; i<tamAv; i++)
            {
                if(!aviones[i].isEmpty && idAerolinea==aviones[i].idAerolinea)
                {
                    contadorAvionesAerolinea++;
                    if(aviones[i].idTipo==5000) //id de jet: 5000
                    {
                        contadorJet++;
                    }
                }
            }

            if(contadorAvionesAerolinea!=0)
            {
                porcentaje = (float) contadorJet*100/contadorAvionesAerolinea;
                printf("El porcentaje de aviones JET de %s es de: %.2f.\n", descripcionAerolinea, porcentaje);
            }

        }
        else
        {

            printf("Intentos agotados. Dirigiendose al menu principal.\n");
        }
    }




    return todoOk;
}

int aerolineasMayorCapacidad(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe)
{
    int todoOk = 0;
    int capacidadMaxima;
    int banderaCapacidad = 0;
    int acumuladorCapacidad[tamAe];

    if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAe>0)
    {
         system("cls");
        for(int i=0; i<tamAe; i++) //for aerolineas
        {
            acumuladorCapacidad[i]=0;

            for(int j=0; j<tamAv; j++) //for aviones
            {
                if(!aviones[j].isEmpty && aviones[j].idAerolinea==aerolineas[i].id)
                {
                    acumuladorCapacidad[i]+= aviones[j].capacidad;
                }
            }
        }


        for(int i=0; i<tamAe; i++) //busco mayor acumulador
        {

            if(banderaCapacidad==0 || acumuladorCapacidad[i]>=capacidadMaxima)
            {
                capacidadMaxima=acumuladorCapacidad[i];
                                banderaCapacidad=1;
            }

        }

        if(banderaCapacidad) //valido que haya llegado hasta este punto
        {
            printf("    ***Lista de aerolineas con mayor capacidad: (%d pasajeros) ***\n", capacidadMaxima);

            for(int j = 0; j<tamAe; j++) //busco que tengan la misma cantidad
            {
                if(acumuladorCapacidad[j]==capacidadMaxima)
                {
                    printf("%d. %s\n", (j+1), aerolineas[j].descripcion);

                }
            }


            todoOk=1;
        }


    }

 return todoOk;


}


int aerolineaMenosAviones(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe)
{
    int todoOk=0;
    int contadorAviones[tamAe];
    int banderaMinimo=0;
    int minimoAviones;

    if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAe>0)
    {
         system("cls");

       for(int i=0; i<tamAe;i++) //aerolineas
       {
           contadorAviones[i]=0;
           for(int j=0; j<tamAv; j++) //aviones
           {
               if(!aviones[j].isEmpty && aviones[j].idAerolinea==aerolineas[i].id)
               {
                   contadorAviones[i]++;
               }

           }

       }

       for(int i = 0; i<tamAe; i++) //busco minimo
            {
                if(banderaMinimo==0 || minimoAviones>contadorAviones[i])
                {
                    minimoAviones=contadorAviones[i];
                    banderaMinimo=1;
                }
            }


             printf("    ***Lista de aerolineas con menos aviones ***\n");

            for(int j = 0; j<tamAe; j++) //busco que tengan la misma cantidad
            {
                if(contadorAviones[j]==minimoAviones)
                {
                    printf("%d. %s\n", (j+1), aerolineas[j].descripcion);

                }
            }

    }


    return todoOk;
}

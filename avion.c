#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#include "entradas.h"



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

    if (aviones != NULL && tamA > 0)
    {

        for (int i = 0; i < tamA; i++)
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

int mostrarAvion(eAvion unAvion, eAerolinea aerolineas[], int tamAE, eTipo tipos[], int tamT)
{
    int todoOk=1;
    char descripcionAerolinea[20];
    char descripcionTipo[20];

    cargarDescripcionAerolinea(unAvion.idAerolinea, aerolineas, tamAE, descripcionAerolinea);
    cargarDescripcionTipo(unAvion.idTipo, tipos, tamT, descripcionTipo);

    printf("%4d      %-10s       %-10s     %03d\n", unAvion.id, descripcionAerolinea, descripcionTipo, unAvion.capacidad);


    return todoOk;
}

int mostrarAviones(eAvion aviones[], int tamAV, eAerolinea aerolineas[], int tamAE, eTipo tipos[], int tamT)
{

    int todoOk = -1;
    int flag = 1;

    if(aviones!=NULL && tamAV>0 && aerolineas!=NULL && tamAE>0 && tipos!=NULL && tamT>0)
    {
        todoOk=1;
        printf("             ***   Lista de aviones ***\n");
        printf("-----------------------------------------------------\n");
        printf("Id        Aerolinea            Tipo        Capacidad\n");
        printf("-----------------------------------------------------\n");


        ordenarAviones(aviones, tamAV, aerolineas, tamAE);

        for(int i=0; i<tamAV; i++)
        {
            if(aviones[i].isEmpty==FALSE)
            {
                mostrarAvion(aviones[i], aerolineas, tamAE, tipos, tamT);
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


int buscarAvionId(eAvion aviones[], int tamAV, int idRecibido)
{
    int indice = -1;

    if (aviones != NULL && tamAV > 0)
    {
        for (int i = 0; i < tamAV; i++)
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

int altaAviones(eAvion aviones[], int tamAV, eAerolinea aerolineas[], int tamAE, eTipo tipos[], int tamT)
{
    int todoOk = -1;
    int indice;
    int intentos=3;
    eAvion auxAvion;

    if(aviones!=NULL && tamAV>0 && aerolineas!=NULL && tamAE>0 && tipos!=NULL && tamT>0)
    {


        indice = buscarLibreAviones(aviones, tamAV);
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

            while(buscarAvionId(aviones, tamAV, auxAvion.id)!=-1 && intentos>0)
            {
                printf("Le quedan %d intentos", intentos);
                intentos--;
                getInt("ERROR EL ID YA EXISTE, intente nuevamente con otro id: ", "ERROR. ingrese el id del avion. (Solo numeros): ", &auxAvion.id);

            }




            mostrarAerolineas(aerolineas, tamAE);

            getInt("\nIngrese el id de la aerolinea: ", "ERROR. Ingrese el id de la aerolinea. (Solo numeros): ", &auxAvion.idAerolinea);

            while(!validarIdAerolinea(auxAvion.idAerolinea, aerolineas, tamAE))
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

            auxAvion.isEmpty=FALSE;
            aviones[indice]=auxAvion;

            printf("Avion cargado con exito!!\n");
            todoOk=1;
        }
    }




    return todoOk;
}

int bajaAviones(eAvion aviones[], int tamAV, eAerolinea aerolineas[], int tamAE, eTipo tipos[], int tamT)
{
    int todoOk=-1;
    int idIngresado;
    int indice;
    char confirmacion;
    eAvion auxAviones[1];

    if(aviones!=NULL && tamAV>0 && aerolineas!=NULL && tamAE>0 && tipos!=NULL && tamT>0)
    {
        system("cls");
        printf("    *** Baja Aviones ***\n");
        printf("--------------------------\n");

        //muestro
        mostrarAviones(aviones, tamAV, aerolineas, tamAE, tipos, tamT);

        //pido id
        getInt("Ingrese ID del avion a dar de baja: ", "\nError, ID invalido, reingrese ID del avion a dar de baja: ", &idIngresado);
        indice = buscarAvionId(aviones, tamAV, idIngresado); //busco si el id existe.

        if (indice == -1)
        {
            printf("El id ingresado no existe.\n");
        }
        else
        {

         auxAviones[0] = aviones[indice];

         mostrarAviones(auxAviones, 1, aerolineas, tamAE, tipos, tamT);

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
            }else
            {
                printf("Baja cancelada. Volviendo al menu principal.\n");
                todoOk=0;
            }
        }
    }
     return todoOk;
}

    int modificarAvion(eAvion aviones[], int tamAV, eAerolinea aerolineas[], int tamAE, eTipo tipos[], int tamT)
    {
        int todoOk = -1;
        int indice;
        int opcion;
        int confirmacion;
        int idIngresado;
        int auxIdTipo;
        int auxIdCapacidad;

        eAvion auxAviones[1];

        if(aviones!=NULL && tamAV>0 && aerolineas!=NULL && tamAE>0 && tipos!=NULL && tamT>0)
        {

            system("cls");
            printf("         *** Modificacion Aviones***\n");
            printf("-----------------------------------\n");

            //muestro y pido
            mostrarAviones(aviones, tamAV, aerolineas, tamAE, tipos, tamT);

            getInt("\nIngrese id del avion a modificar: ", "ERROR. Ingrese el id del avion a modificar (solo numeros): ", &idIngresado);


            indice = buscarAvionId(aviones, tamAV, idIngresado); //valido que exista

            if (indice == -1) //no existe y salgo
            {
                printf("No existe el ID ingresado. Dirigiendose al menu principal\n");
                todoOk = 0;
            }
            else
            {
                auxAviones[0] = aviones[indice];
                mostrarAviones(auxAviones, 1, aerolineas, tamAE, tipos, tamT);
                confirmacion = getConfirmation(
                                   "El avion mostrado es el correcto? (s/n): ",
                                   "ERROR. El avion mostrado es el correcto? (s/n): ");
                confirmacion = tolower(confirmacion);

                if (confirmacion == 's')
                {
                    auxAviones[0] = aviones[indice];
                    system("cls");
                    printf("   *** Modificacion de aviones***\n");
                    printf("-----------------------------------------------\n");

                    printf("Que desea modificar de \n");
                    mostrarAviones(auxAviones, 1, aerolineas, tamAE, tipos, tamT);

                    printf("\n1) Tipo\n");
                    printf("2) Capacidad\n");
                    printf("3) Salir\n");

                    getInt("Por favor seleccione una opcion: ",	"Por favor seleccione una opcion: (solo numeros)", &opcion);

                    switch (opcion)
                    {
                    case 1:
                        mostrarTipos(tipos, tamT);
                        getInt("Por favor seleccione el id del nuevo tipo: ",	"ERROR. Por favor seleccione el id del nuevo tipo: (solo numeros)", &auxIdTipo);
                        while(!validarIdTipo(auxIdTipo, tipos, tamT))
                        {
                            getInt("ID INVALIDO. Por favor seleccione el id del nuevo tipo: ",	"ERROR: Por favor seleccione el id del nuevo tipo:", &auxIdTipo);

                        }


                        todoOk = 1;
                        break;
                    case 2:
                        getInt("Por favor ingrese la nueva capacidad del avion: ", "ERROR. Por favor ingrese la neuva capacidad del avion (solo numeros): ", &auxIdCapacidad);
                        while(auxIdCapacidad<10 || auxIdCapacidad>300)
                        {
                            getInt("Capacidad invalida. Por favor ingrese la nueva capacidad del avion: (10-300)",	"ERROR: Por favor ingrese la nueva capacidad del avion (10-300) (solo numeros)", &auxIdCapacidad);

                        }


                        todoOk = 1;
                        break;
                    case 3:
                        printf("Saliendo al menu principal\n");
                        todoOk = 0;
                        break;
                    }

                }

            }


        }
        return todoOk;
    }


    int ordenarAviones(eAvion aviones[], int tamAV, eAerolinea aerolineas[], int tamAE)
    {
        int todoOk=0;
        char descripcionAerolineaI[20];
        char descripcionAerolineaJ[20];

        eAvion auxAvion;

        if(aviones!=NULL && tamAV>0 && aerolineas!=NULL && tamAE>0)
        {

            for (int i = 0; i < tamAV - 1; i++)
            {

                for (int j = i + 1; j < tamAV; j++)
                {
                    cargarDescripcionAerolinea(aviones[i].idAerolinea, aerolineas, tamAE, descripcionAerolineaI);
                    cargarDescripcionAerolinea(aviones[j].idAerolinea, aerolineas, tamAE, descripcionAerolineaJ);


                    if(strcmp(descripcionAerolineaI, descripcionAerolineaJ)>0 || (strcmp(descripcionAerolineaI, descripcionAerolineaJ)==0 && aviones[i].capacidad > aviones[j].capacidad))
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

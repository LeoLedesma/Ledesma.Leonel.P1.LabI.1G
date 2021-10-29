#include "menu.h"


int menuPrincipal (eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, eTipo tipos[], int tamT, eVuelo vuelos[], int tamV, eDestino destinos[], int tamD, int* pNextIdVuelos, ePiloto pilotos[], int tamP)
{
    int todoOk=0;
    int opcion;
    char salir = 'n';
    int contadorAviones = 0;
    int contadorVuelos = 0;

    if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAe>0 && tipos!=NULL && tamT>0 && vuelos!=NULL && tamV>0 && destinos!=NULL && tamD>0 && pNextIdVuelos>0 && pilotos!=NULL && tamP>0 )
    {
        hardcodearAviones(aviones, tamAv, 10, &contadorAviones);
        hardcodearVuelos(vuelos, tamV, 20, pNextIdVuelos, &contadorVuelos);

        todoOk = 1;

        do
        {
               opcion = menuOpciones();


            switch(opcion)
            {
            case 'A': //ALTA AVION
                system("cls");
                if(!altaAviones(aviones, tamAv, aerolineas, tamAe, tipos, tamT, pilotos, tamP))
                {

                }
                else
                {
                    (contadorAviones)++;
                }

                break;
            case 'B': //MODIFICAR
                modificarAvion(aviones, tamAv, aerolineas, tamAe, tipos, tamT, pilotos, tamP);

                break;

            case 'C': //BAJA
                system("cls");
                if(bajaAviones(aviones, tamAv, aerolineas, tamAe, tipos, tamT, pilotos, tamP)==1)
                {
                    printf("Avion dado de baja con exito!!\n");

                    (contadorAviones)--;

                }
                else
                {

                }
                break;

            case 'D': //LISTAR AVIONES ORDENADOS
                system("cls");
                if(contadorAviones>0)
                {
                    if(!mostrarAviones(aviones, tamAv, aerolineas, tamAe, tipos, tamT, pilotos, tamP))
                    {
                        printf("Ocurrio un error al mostrar.\n");
                    }
                }
                else
                {
                    printf("Primero debe cargar un avion para poder mostrarlos.\n");
                };

                break;

            case 'E': //LISTAR AEROLINEAS
                system("cls");
                mostrarAerolineas(aerolineas, tamAe);

                break;
            case 'F': //listar tipos
                system("cls");
                mostrarTipos(tipos, tamT);
                break;
            case 'G': //LISTAR DESTINOS
                system("cls");
                mostrarDestinos(destinos, tamD);

                break;
            case 'H': //ALTA VUELO
                system("cls");
                if(contadorAviones>0)
                {
                    if(!altaVuelo(vuelos, tamV, aviones, tamAv, tipos, tamT, aerolineas, tamAe, destinos, tamD, pNextIdVuelos, pilotos, tamP))
                    {
                        printf("No se pudo cargar el vuelo con exito.\n");

                    }
                    else
                    {
                        contadorVuelos++;
                    }
                }
                else
                {
                    printf("Primero debe dar de alta un avion.\n");
                }


                break;
            case 'I': //LISTAR VUELOS
                system("cls");
                if(contadorVuelos>0)
                {
                    if(!mostrarVuelos(vuelos, tamV, aviones, tamAv, destinos, tamD, aerolineas, tamAe))
                    {
                        printf("Ocurrio un error al mostrar los vuelos\n.");

                    }

                }
                else
                {
                    printf("Primero debe dar de alta un vuelo para mostrar.\n");
                }


                break;
            case 'J': //Menu informes
                menuInformes(aviones, tamAv, aerolineas, tamAe, tipos, tamT, vuelos, tamV, destinos, tamD, contadorAviones, contadorVuelos, pilotos, tamP);
                break;
            case 'Z'://salir

                salir = getConfirmation("Esta seguro que desea salir? (s/n): ", "ERROR: Esta seguro que desea salir? (s/n): ");
                salir = tolower (salir);
                break;
            default:
                printf("Opcion incorrecta, intente nuevamente.\n");
                break;


            }



            system("pause");
        }
        while(salir!='s');

    }

    return todoOk;
}

char menuOpciones()
{
    char opcion;
    system("cls");

    printf("    ***    SERVICIOS DE VUELO LEDESMA    *** 	\n");
    printf("------------------------------------------------\n");
    printf("  A) ALTA AVION\n");
    printf("  B) MODIFICAR AVION\n");
    printf("  C) BAJA AVION\n");
    printf("  D) LISTAR AVIONES\n");
    printf("  E) LISTAR AEROLINEAS\n");
    printf("  F) LISTAR TIPOS\n");
    printf("  G) LISTAR DESTINOS\n");
    printf("  H) ALTA VUELO\n");
    printf("  I) LISTAR VUELOS\n");
    printf("  J) MENU DE INFORMES\n");
    printf("  Z) Salir\n");

    utn_getCaracter(&opcion, "Por favor seleccione una opcion: ", "ERROR. Por favor seleccione una opcion (solo letras): ", 'A', 'z', 100);
    opcion = toupper(opcion);

    return opcion;
}

int menuInformes(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAe, eTipo tipos[], int tamT, eVuelo vuelos[], int tamV, eDestino destinos[], int tamD, int contadorAviones, int contadorVuelos, ePiloto pilotos[], int tamP)
{
    int todoOk=0;
    int opcion;
    char salir='s';


    if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAe>0 && tipos!=NULL && tamT>0 && vuelos!=NULL && tamV>0 && destinos!=NULL && tamD>0)
    {
        todoOk=1;

        do
        {

            system("cls");
            printf("    *** Menu de informes ***\n");
            printf("------------------------------\n");

            opcion = menuOpcionesInformes();



            switch(opcion)
            {
            case 1:
                if(contadorAviones>0)
                {
                    mostrarAvionesAerolineaSeleccionada(aviones, tamAv, tipos, tamT, aerolineas, tamAe, pilotos, tamP);
                }else
                {
                    printf("Primero debe cargar un avion para poder mostrar este informe.\n");
                    salir='s';
                }

                break;
            case 2:
                if(contadorAviones>0)
                {
                   mostrarAvionesTipoSeleccionado(aviones, tamAv, tipos, tamT, aerolineas, tamAe, pilotos, tamP);
                }else
                {
                    printf("Primero debe cargar un avion para poder mostrar este informe.\n");
                    salir='s';
                }

                break;
            case 3:
                if(contadorAviones>0)
                {
                    porcentajeAvionesJetAerolinea(aerolineas, tamAe, aviones, tamAv);
                }else
                {
                    printf("Primero debe cargar un avion para poder mostrar este informe.\n");
                    salir='s';
                }
                break;
            case 4:
                if(contadorAviones>0)
                {
                mostrarAvionesPorAerolinea(aviones, tamAv, tipos, tamT, aerolineas, tamAe, pilotos, tamP);
                }else
                {
                    printf("Primero debe cargar un avion para poder mostrar este informe.\n");
                    salir='s';
                }
                break;
            case 5:
                if(contadorAviones>0)
                {
                aerolineasMayorCapacidad(aviones, tamAv, aerolineas, tamAe);
                }else
                {
                    printf("Primero debe cargar un avion para poder mostrar este informe.\n");
                    salir='s';
                }
                break;

            case 6:
                if(contadorAviones>0)
                {
                aerolineaMenosAviones(aviones, tamAv, aerolineas, tamAe);
                }else
                {
                    printf("Primero debe cargar un avion para poder mostrar este informe.\n");
                    salir='s';
                }
                break;
            case 7:
                if(contadorAviones>0)
                {
                mostrarVuelosAvion(vuelos, tamV, aviones, tamAv, aerolineas, tamAe, tipos, tamT, destinos, tamD, pilotos, tamP);
                }else
                {
                    printf("Primero debe cargar un avion para poder mostrar este informe.\n");
                    salir='s';
                }
                break;

            case 8: //Vuelos
                if(contadorVuelos>0)
                {
                     mostrarSumaViajesAvion(vuelos, tamV, aviones, tamAv, aerolineas, tamAe, tipos, tamT, destinos, tamD, pilotos, tamP);
                }else
                {
                     printf("Primero debe cargar un vuelo para poder mostrar este informe.\n");
                    salir='s';
                }

                break;
            case 9:
                if(contadorVuelos>0)
                {
                mostrarVueloDeUnDestino(destinos, tamD, vuelos, tamV, aviones, tamAv, aerolineas, tamAe, pilotos, tamP);
                }else
                {
                     printf("Primero debe cargar un vuelo para poder mostrar este informe.\n");
                    salir='s';
                }
                break;
            case 10:
                if(contadorVuelos>0)
                {
                    viajesEnUnaFecha(destinos, tamD, vuelos, tamV, aviones, tamAv, aerolineas, tamAe, pilotos, tamP);
                }else
                {
                     printf("Primero debe cargar un vuelo para poder mostrar este informe.\n");
                    salir='s';
                }
                break;

            case 0:
                salir = getConfirmation("Esta seguro que desea salir? (s/n): ", "ERROR: Esta seguro que desea salir? (s/n): ");
                salir = tolower (salir);
                break;
            default:
                printf("Opcion invalida! intente nuevamente!");
                break;
            }


        }while(salir!='s');

    }


    return todoOk;
}

int menuOpcionesInformes()
{
    int opcion;

    printf("1. Mostrar aviones de la aerolinea seleccionada por el usuario.\n");
    printf("2. Mostrar aviones de un tipo seleccionado.\n");
    printf("3. Informar Promedio de aviones jet sobre el total de aviones de una aerolinea\n");
    printf("4. Mostrar un listado de los aviones separados por aerolínea.\n");
    printf("5. Informar la o las aerolineas que pueden transportar mas pasajeros (mayor acumulador de capacidades de sus aviones)\n");
    printf("6. Mostrar la aerolinea con menor cantidad de aviones.\n");
    printf("7. Pedir un avion y mostrar todos los vuelos que hizo el mismo.\n");
    printf("8. Pedir un avion e informar la suma de los precios (costo) de todos los vuelos que realizo.\n");
    printf("9. Pedir un destino y mostrar los aviones que volaron a ese destino y en que fecha. \n");
    printf("10. Pedir una fecha y mostrar todos los vuelos realizados en la misma.\n");
    printf("0. Salir al menu principal.\n");


    getInt("Por favor ingrese una opcion: ", "ERROR. Por favor ingrese una opcion (solo numeros): ", &opcion);

    return opcion;
}



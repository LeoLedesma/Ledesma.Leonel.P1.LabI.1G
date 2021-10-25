#include "entradas.h"


//----------------ENTRADA DE DATOS---------------

int getString(char mensaje[], char mensajeError[], char entrada[], int tam)
{
    int todoOk = -1;
    char auxString[100];

    if(mensaje!=NULL && mensajeError!=NULL && entrada!=NULL && tam>0)
    {
        printf("%s", mensaje);
        fflush (stdin);
        gets(auxString);

        while(strlen(auxString)>tam-1 || !isString(auxString))
        {
            printf("%s", mensajeError);
            fflush (stdin);
            gets(auxString);
        }

        strcpy(entrada, auxString);
        todoOk=0;
    }

    return todoOk;
}

int getFloat(char mensaje[], char mensajeError[], float* entrada )
{
    int todoOk = -1;
    char auxString[100];

    if(mensaje!=NULL && mensajeError!=NULL && entrada!=NULL)
    {
        printf("%s", mensaje);
        fflush (stdin);
        gets(auxString);

        while(!isFloat(auxString))
        {
            printf("%s", mensajeError);
            fflush (stdin);
            gets(auxString);
        }

        *entrada = atof(auxString);

        todoOk=0;
    }
    return todoOk;
}

int getInt(char mensaje[], char mensajeError[], int* entrada)
{
    int todoOk = 0;
    char auxString[100];

    fflush(stdin);
    if(mensaje!=NULL && mensajeError!=NULL && entrada!=NULL)
    {
        printf("%s", mensaje);
        fflush (stdin);
        gets(auxString);


        while(!isInt(auxString))
        {
            printf("%s", mensajeError);
            fflush (stdin);
            gets(auxString);

        }

        *entrada = atoi(auxString);


        todoOk=1;

    }

    return todoOk;
}

char getConfirmation (char mensaje[], char mensajeError[])
{
    int todoOk = 1;
    char caracterIngresado;
    char error[] = {"ERROR. Solo puedes ingresar letras. Intenta nuevamente: " };

    utn_getCaracter(&caracterIngresado, mensaje, error, 'A', 'z', 1);

    while (caracterIngresado != 's' &&  caracterIngresado != 'S' &&
            caracterIngresado != 'n' && caracterIngresado != 'N')
    {
        utn_getCaracter(&caracterIngresado, mensajeError, error, 'A', 'z', 1);
    }

    caracterIngresado=tolower(caracterIngresado);

    return caracterIngresado;
}

//-------------VALIDACIONES

int isString (char string[])
{
    int todoOk = 1;
    int stringTam = strlen(string);

    if(string!=NULL)
    {

        for(int i = 0; i<stringTam; i++)
        {
            if((!isalpha(string[i]) && string[i]!= ' '))
            {

                todoOk = 0;

                break;
            }

        }

    }

    return todoOk;
}


int isFloat(char entrada[]) //15000
{
    int todoOk = 1;
    int banderaPunto = 0;
    int stringTam = strlen(entrada);

    for(int i=0; i<stringTam ; i++)
    {
        if(entrada[i]=='.')
        {
            banderaPunto++;
        }

        if((!isdigit(entrada[i]) && entrada[i]!='.') || banderaPunto>1)
        {
            todoOk = 0;
            break;
        }

    }


    return todoOk;
}


int isInt(char entrada[])
{
    int todoOk = 1;
    int stringTam = strlen(entrada);


    if (isdigit(entrada[0]) || (entrada[0]== '-' && stringTam > 1))
    {

        for(int i = 1; i < stringTam; i++)
        {

            if (!isdigit(entrada[i]))
            {
                todoOk = 0;
                break;
            }
        }
    }
    else
    {
        todoOk = 0;
    }


    return todoOk;
}

//-------------MODIFICACIONES
int toUpperFirstLetterPhrase(char string [], int len)
{
    int todoOk=0;


    if(string!=NULL && len>0)
    {
        todoOk=1;
        strlwr(string);

        string[0]=toupper(string[0]);

        for(int i = 0; i<len; i++)
        {
            if(string[i] == ' ')
            {
                string[i+1] = toupper(string[i+1]);
            }
        }
    }

    return todoOk;
}


int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos){
    int retorno = 0;
    char auxChar;

    if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){

        do {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%c", &auxChar);

            if (auxChar >= minimo && auxChar <= maximo){
                *pResultado = auxChar;
                retorno = 1;//salio tod0 bien
                break;

            }
            printf("%s", mensajeError);
            reintentos--;

        } while (reintentos >= 0);

    }

    return retorno;
}









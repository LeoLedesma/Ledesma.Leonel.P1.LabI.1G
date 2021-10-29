#include "fecha.h"

int pedirFecha(eFecha* unaFecha)
{
    int fechaValida=0;
    eFecha auxFecha;

     getInt("Ingrese dia: ", "ERROR: Ingrese dia: (solo numeros)",
                   &auxFecha.dia);
     getInt("Ingrese mes: ", "ERROR: Ingrese mes: (solo numeros)",
                   &auxFecha.mes);
     getInt("Ingrese anio: ", "ERROR: Ingrese anio: (solo numeros)",
                   &auxFecha.anio);


           switch(auxFecha.mes)
           {
            case  1 :
            case  3 :
            case  5 :
            case  7 :
            case  8 :
            case 10 :
            case 12 : if ( auxFecha.dia >= 1 && auxFecha.dia <= 31 ) //meses con 31 dias
                        {
                            fechaValida = 1;

                        }


                      break;

            case  4 :
            case  6 :
            case  9 :
            case 11 : if ( auxFecha.dia >= 1 && auxFecha.dia <= 30 ) //meses con 30 dias
                         {
                            fechaValida = 1;

                        }
                      break;

            case  2 : if ( (auxFecha.anio % 4 == 0 && auxFecha.anio % 100 != 0) || (auxFecha.anio % 400 == 0) ) //es bisiesto
                      {
                          if ( auxFecha.dia >= 1 && auxFecha.dia <= 29 )
                              {
                            fechaValida = 1;

                        }
                      }
                      else
                          if ( auxFecha.dia >= 1 && auxFecha.dia <= 28 ) //no es bisiesto
                              {
                            fechaValida = 1;

                        }
           }

           if(fechaValida)
           {
               *unaFecha=auxFecha;
           }


           return fechaValida;
}

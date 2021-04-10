#include "utn.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;
    int retorno = 0;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<= maximo && reintentos>=0) // valido los parametros que recibo
    {
        do
        {
            printf("%s", mensaje);
            scanf("%d", &bufferInt);
            if(bufferInt>=minimo && bufferInt<=maximo)
            {
                *pResultado = bufferInt;
                retorno=1;
                break;
            }

            printf("%s", mensajeError);
            reintentos--;


        }while(reintentos>=0);
    }
    return retorno;

}

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
    int retorno = 0;
    char bufferChar;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<= maximo && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%c", &bufferChar);
            if(bufferChar>=minimo && bufferChar<=maximo)
            {
                *pResultado = bufferChar;
                retorno=1;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }

        }while(reintentos>=0);
    }

    return retorno;

}

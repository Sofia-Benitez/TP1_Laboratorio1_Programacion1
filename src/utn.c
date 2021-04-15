/*
 * utn.c
 *
 *  Created on: Apr 15, 2021
 *      Author: sofia
 */


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

            if(scanf("%d", &bufferInt)==1)
            {
                if(bufferInt>=minimo && bufferInt<=maximo)
                {
                    *pResultado = bufferInt;
                    retorno=1;
                    break;
                }
            }
            fflush(stdin);

            printf("%s", mensajeError);
            reintentos--;


        }while(reintentos>=0);
    }
    return retorno;

}


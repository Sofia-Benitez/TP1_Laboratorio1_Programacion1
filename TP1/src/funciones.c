/*
 * funciones.c
 *
 *  Created on: Apr 15, 2021
 *      Author: sofia
 */



#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>



int menuPrincipal(int flagUno, int flagDos, int primerOperando, int segundoOperando)
{
        printf("\n   ****Menu de opciones**** \n");
        if(flagUno!=1)
        {
            printf("1. Ingresar 1er operando (A=x)\n");
        }
        else
        {
            printf("1. Ingresar 1er operando (A=%d)\n", primerOperando);
        }

        if(flagDos!=1)
        {
            printf("2. Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("2. Ingresar 2do operando (B=%d)\n", segundoOperando);
        }

        printf("3. Calcular todas las operaciones\n");
        printf("\t a) Calcular la suma (A+B)\n");
        printf("\t b) Calcular la resta (A-B)\n");
        printf("\t c) Calcular la division (A/B)\n");
        printf("\t d) Calcular la multiplicacion (A*B)\n");
        printf("\t e) Calcular el factorial (A!)\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n");

    return 0;
}


int suma(int numero1, int numero2)
{
    int resultado;
    resultado = numero1 + numero2;
    return resultado;
}


int resta(int numero1,int numero2)
{
    int resultado;
    resultado= numero1 - numero2;
    return resultado;
}



int division(int numero1, int numero2, float* resultado)
{
    int todoOk = 0;

    if(numero2 != 0 && resultado!=NULL)
    {
        *resultado= (float) numero1/numero2;
        todoOk=1;
    }

    return todoOk;
}


int multiplicacion(int numero1, int numero2)
{
    int resultado;
    resultado = numero1 * numero2;
    return resultado;
}


int factorial(int numero, int* resultadoFactorial)
{
    int todoOk = 0;
    int fact = 1;

    if(numero>=0 && numero <=10 && resultadoFactorial!=NULL)
    {

        for(int i=1; i<= numero; i++)
        {
            fact *= i;
            *resultadoFactorial = fact;
        }

        todoOk=1;

    }

    if(numero>10)
    {
        todoOk=-1;
    }

    return todoOk;
}

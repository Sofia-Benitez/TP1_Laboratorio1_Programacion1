
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


int menuPrincipal()
{
        printf("\n   ****Menu de opciones**** \n");
        printf("1. Ingresar 1er operando (A=x)\n");
        printf("2. Ingresar 2do operando (B=y)\n");
        printf("3. Calcular todas las operaciones\n");
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
    float
    if(numero2 != 0 && resultado!=NULL)
    {
        *resultado= (float) numero1/numero2;
    }


    return todoOk;
}

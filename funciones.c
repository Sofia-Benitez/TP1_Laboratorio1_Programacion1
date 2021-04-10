
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

/** \brief suma de dos operandos
 *
 * \param numero1 int  primer operando
 * \param numero2 int  segundo operando
 * \return int        resultado de la operacion
 *
 */
int suma(int numero1, int numero2)
{
    int resultado;
    resultado = numero1 + numero2;
    return resultado;
}

/** \brief resta de dos operandos. Al primer operando se le sustrae el segundo
 *
 * \param numero1 int   primer operando
 * \param numero2 int   segundo operando
 * \return int          resultado de la operacion
 *
 */
int resta(int numero1,int numero2)
{
    int resultado;
    resultado= numero1 - numero2;
    return resultado;
}

/** \brief realiza la division de dos operandos y Devuelve 0 si no es posible realizar la division y 1 si es posible.
 *
 * \param numero1 int    primer operando
 * \param numero2 int    segundo operando
 * \param resultado float*   puntero del resultado de la operacion
 * \return int        retorna 0 si la division no se puede realizar porque el puntero es null o el segundo operando es 0 y retorna 1 si la division se puede realizar
 *
 */
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

/** \brief multiplicacion de dos operandos
 *
 * \param numero1 int    primer operando
 * \param numero2 int    segundo operando
 * \return int            resultado de la operacion
 *
 */
int multiplicacion(int numero1, int numero2)
{
    int resultado;
    resultado = numero1 * numero2;
    return resultado;
}

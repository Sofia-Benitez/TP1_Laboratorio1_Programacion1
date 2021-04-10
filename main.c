#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "funciones.h"

int main()
{
    int opcion=0;
    int operando1;
    int operando2;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    int divisionOk;
    float resultadoDivision;
    int resultadoFactorialA;
    int resultadoFactorialB;
    int flagMenu = 0;
    int flagMenuDos = 0;
    int flagCalculos = 0;


    do
    {
        system("cls");
        menuPrincipal(flagMenu, flagMenuDos, operando1, operando2);
        utn_getNumero(&opcion, "\nSeleccione una opcion: \n", "No es una opcion valida", 1,5,2);
        switch(opcion)
        {
        case 1:
            flagMenu = utn_getNumero(&operando1, "\nIngrese el operando 1: \n", "No es un numero valido",-32768,32767,2);
            break;
        case 2:
            flagMenuDos = utn_getNumero(&operando2, "\nIngrese el operando 2: \n", "No es u numero valido",-32768,32767,2);
            break;
        //calculos
        case 3:
            if(flagMenu==0 || flagMenuDos ==0)
            {
                printf("Todavia no ingreso los operandos. No se puede calcular.\n");
            }
            else
            {
                printf("Los calculos se realizaron correctamente \n");
                flagCalculos=1;

                resultadoSuma = suma(operando1,operando2);

                resultadoResta= resta(operando1, operando2);

                divisionOk = division(operando1, operando2, &resultadoDivision);

                resultadoMultiplicacion = multiplicacion(operando1, operando2);


            }
            break;
        //muestro resultados
        case 4:
            if(flagCalculos==1)
            {
                printf("El resultado de la suma  es %d \n", resultadoSuma);

                printf("El resultado de la resta es %d \n" , resultadoResta);

                if(divisionOk==1)
                {
                    printf("El resultado de la division es %.2f \n", resultadoDivision);
                }
                else
                {
                    printf("No es posible dividir por 0");
                }

                printf("El resultado de la multiplicacion es %d \n" , resultadoMultiplicacion);

            }
            else
            {
                printf("Antes de mostrar los resultados se deben realizar los calculos \n");
            }

            break;
        case 5:
            printf("Salio de la calculadora\n");

        }
    system("pause");
    }
    while(opcion!=5);




    return 0;
}

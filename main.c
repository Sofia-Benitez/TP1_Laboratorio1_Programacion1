#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "funciones.h"

int main()
{
    int opcion=0;
    int resultado;
    int operando1;
    int operando2;
    char opcionOperacion;
    int resultadoDivision;


    do
    {
        menuPrincipal();
        utn_getNumero(&opcion, "\nSeleccione una opcion \n", "No es una opcion valida", 1,5,2);
        switch(opcion)
        {
        case 1:
            utn_getNumero(&operando1, "\nIngrese el operando 1 \n", "No es un numero valido", -9000,9000,2);
            break;
        case 2:
            utn_getNumero(&operando2, "\nIngrese el operando 2 \n", "No es u numero valido", -9000,9000,2);
            break;
        case 3:
            printf("Ingrese una opcion");
            printf("\t a) Calcular la suma (A+B)\n");
            printf("\t b) Calcular la resta (A-B)\n");
            printf("\t c) Calcular la division (A/B)\n");
            printf("\t d) Calcular la multiplicacion (A*B)\n");
            printf("\t e) Calcular el factorial (A!)\n");
            fflush(stdin);
            utn_getCaracter(&opcionOperacion, "Ingrese una opcion\n", "ERROR\n", 65,122,2);
            printf("%c\n", opcionOperacion);
            switch(opcionOperacion)
            {
            case 'a':
                resultado = suma(operando1,operando2);
                printf("El resultado es %d", resultado);
                break;
            case 'b':
                resultado= resta(operando1, operando2);
                printf("El resultado es %d", resultado);
                break;
            case 'c':
                resultadoDivision = division(operando1, operando2, &resultado);
                break;
            case 'd':
                printf("MULTIP");
                break;
            case 'e':
                printf("Factorial");
                break;
            default:
                break;
            }
            break;
        case 4:
            printf("El resultado es %d", resultado);
            break;

        }
    }
    while(opcion!=5);




    return 0;
}

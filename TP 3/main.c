#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    char continua;
    char path[100];
    int nextId=1;

    //instancio un linkedlist
    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados==NULL)
    {
        printf("No se pudo crear el linkedlist");
        exit(1);
    }

    do{
        menu();
        utn_getNumero(&option, "Ingrese una opcion: ", "Error. Ingrese una opcion: ", 1, 10, 3);
        switch(option)
        {
            case 1:
                printf("Ingrese path (.csv): ");
                fflush(stdin);
                gets(path);
                if(controller_loadFromText(path,listaEmpleados))
                {
                    buscarMayorID(listaEmpleados, &nextId);
                    printf("Cantidad de empleados en la nomina:  %d \n", ll_len(listaEmpleados));
                }
                else
                {
                    printf("Error");
                }

                break;
            case 2:
                printf("Ingrese path (.bin): ");
                fflush(stdin);
                gets(path);
                if(controller_loadFromBinary(path, listaEmpleados))
                {
                    buscarMayorID(listaEmpleados, &nextId);
                    printf("Cantidad de empleados en la nomina:  %d \n", ll_len(listaEmpleados));
                }
                else
                {
                    printf("Error");
                }

                break;
            case 3:
                //alta empleado
                if(controller_addEmployee(listaEmpleados, nextId))
                {
                    printf("Alta correcta\n");
                    buscarMayorID(listaEmpleados, &nextId);
                }
                else
                {
                    printf("Error. No se ha podido realizar el alta del empleado\n");
                }
                break;
            case 4:
                if(controller_editEmployee(listaEmpleados))
                {
                    printf("Modificacion realizada\n");
                }
                else
                {
                    printf("Hubo un problema al realizar la modificacion\n");
                }
                break;
            case 5:
                if(controller_removeEmployee(listaEmpleados))
                {
                     printf("empleado eliminado\n");
                }
                else
                {
                     printf("No es posible eliminar empleados\n");
                     printf("Cantidad de empleados en la nomina: %d \n", ll_len(listaEmpleados));
                }
                break;
            case 6:
                //listar

                if(controller_ListEmployee(listaEmpleados)==0)
                {
                    printf("No hay empleados para mostrar\n");
                }
                break;
            case 7:
                if(controller_sortEmployee(listaEmpleados))
                {
                    printf("Ordenamiento exitoso\n");
                }
                else
                {
                    printf("No es posible realizar el ordenamiento\n");
                }
                break;
            case 8:
                printf("Ingrese path (.csv): ");
                fflush(stdin);
                gets(path);
                if(controller_saveAsText(path, listaEmpleados))
                {
                    printf("El archivo se ha guardado con exito\n");
                }
                else
                {
                    printf("No se guardara el archivo\n");
                }
                break;
            case 9:
                printf("Ingrese path (.bin): ");
                fflush(stdin);
                gets(path);
                if(controller_saveAsBinary(path, listaEmpleados))
                {
                    printf("Archivo guardado con exito\n");
                }
                else
                {
                    printf("No se guardara el archivo\n");
                }
                break;
            case 10:
                printf("Programa finalizado\n");
                break;
        }


        system("PAUSE");
        system("cls");


    }while(option != 10);
    return 0;
}









/*
 ============================================================================
 Name        : TP2.c
 Author      : Sofia Benitez
 Version     :
 Copyright   : Your copyright notice
 Description : ABM empleados
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#define LEN 1000


int main(void) {
	int nextId=1;//arranca de este valor
	    int opcionMenuPrincipal;
	    int opcionInformes;
	    int idBaja;
	    int flagAlta=0;

	    setbuf(stdout,NULL);

	    sEmployee arrayEmployees[LEN];
	    initEmployees(arrayEmployees, LEN);

	    do
	    {

	        menu();
	        utn_getNumero(&opcionMenuPrincipal, "\nSeleccione una opcion: ", "No es una opcion valida.\n", 1,6,2);
	        switch(opcionMenuPrincipal)
	        {
	            case 1:
	                //alta
	                if(addEmployee(arrayEmployees, LEN, &nextId))
	                {
	                   printf("Alta exitosa\n");
	                   flagAlta=1;
	                }
	                else
	                {
	                    printf("Hubo un problema al dar de alta al empleado\n");
	                }
	                break;
	            case 2:
	                //modificacion
	                if(flagAlta)
	                {
	                    modifyEmployee(arrayEmployees, LEN);
	                }
	                else
	                {
	                    printf("Para poder realizar una modificacion primero debe cargar un empleado.\n");
	                }
	                break;
	            case 3:
	                //baja
	                if(flagAlta)
	                {

	                    printf("       Baja de empleados\n");
	                    printEmployees(arrayEmployees, LEN);
	                    utn_getNumero(&idBaja, "Ingrese el id del empleado que desea dar de baja: ", "Error. Id incorrecto\n", 1, 1000, 2);
	                    removeEmployee(arrayEmployees, LEN, idBaja);
	                }
	                else
	                {
	                    printf("Para poder realizar una baja primero debe cargar un empleado.\n");
	                }

	                break;
	            case 4:
	                //listar
	                printEmployees(arrayEmployees, LEN);
	                break;
	            case 5:
	                //informes
	            if(flagAlta)
	            {
	                menuInformes();
	                utn_getNumero(&opcionInformes, "Ingrese una opcion: ", "Error. Opcion invalida. \n", 1, 3, 3);

	                    switch(opcionInformes)
	                    {
	                    case 1:
	                        sortEmployees(arrayEmployees, LEN, 1);
	                        printEmployees(arrayEmployees, LEN);
	                        break;
	                    case 2:
	                        sortEmployees(arrayEmployees, LEN, 2);
	                        printEmployees(arrayEmployees, LEN);
	                        break;
	                    case 3:
	                        sueldosTotalesYPromedio(arrayEmployees, LEN);
	                        printEmployees(arrayEmployees, LEN);
	                        break;
	                    }
	                }
	                else
	                {
	                    printf("Para poder realizar un informe primero debe cargar un empleado.\n");
	                }

	                break;

	        }




	    }while(opcionMenuPrincipal!=6);

	return EXIT_SUCCESS;
}

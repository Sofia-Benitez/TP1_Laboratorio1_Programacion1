#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char buffer[10][1000];
    int cant;
    int todoOk=0;
    Employee* auxEmployee=NULL;

    if(pFile!=NULL)
    {
        fscanf(pFile, "%[^,], %[^,], %[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);//lectura fantasma del encabezado
        do
        {
            cant = fscanf(pFile, "%[^,], %[^,], %[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cant<4)
            {
                break;
            }
            auxEmployee=employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
            ll_add(pArrayListEmployee, auxEmployee);//busca lugar y agrega al empleado al linkedlist
        }
        while(!feof(pFile));
        todoOk=1;
    }


    return todoOk;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    //usar el new empleado sin param
     int cant;
     int todoOk=0;
     Employee* auxEmployee;

    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            auxEmployee=employee_new();
            if(auxEmployee!=NULL)
            {
                cant =  fread(auxEmployee, sizeof(Employee), 1, pFile);
                if(cant==1)
                {
                    ll_add(pArrayListEmployee, auxEmployee);
                    auxEmployee=NULL;
                    todoOk=1;
                }
                else
                {
                    break;
                }
            }
        }
    }



    return todoOk;
}

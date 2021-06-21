#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "utn.h"


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmployee;
    newEmployee = employee_new();

    if(newEmployee!=NULL)
    {
        if(!(employee_setId(newEmployee, atoi(idStr))&&
             employee_setNombre(newEmployee, nombreStr)&&
             employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr))&&
            employee_setSueldo(newEmployee, atoi(sueldoStr))))
        {
            free(newEmployee);
            newEmployee=NULL;
        }
    }

    return newEmployee;
}

Employee* employee_new()
{
    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));

    return newEmployee;
}

Employee* employee_create(int id)
{

    char auxNombre[20];
    char auxHorasTrabajadas[20];
    char auxSueldo[20];

    Employee* newEmployee=NULL;  ///auxiliar

    system("cls");
    printf("Alta empleado\n\n");
    printf("ID: %d\n", id);


    utn_getStringNombre(auxNombre, "Ingrese el nombre del empleado: ", "Error, ingrese un nombre valido\n",51, 3);

    utn_getStringNumerica(auxHorasTrabajadas, "Ingrese las horas trabajadas del empleado: ", "Error\n", 3);

    utn_getStringNumerica(auxSueldo, "Ingrese el sueldo del empleado: ", "Error\n", 3);


    newEmployee=employee_new();

    employee_setId(newEmployee, id);
    employee_setNombre(newEmployee, auxNombre);
    employee_setHorasTrabajadas(newEmployee, atoi(auxHorasTrabajadas));
    employee_setSueldo(newEmployee, atoi(auxSueldo));


    return newEmployee;
}


int employee_setId(Employee* this,int id)
{
    int todoOk=0;
    if(this!=NULL && id>0)
    {
        this->id = id;
        todoOk=1;
    }
    return todoOk;
}
int employee_getId(Employee* this,int* id)
{
    int todoOk=0;
    if(id!=NULL && this!=NULL)
    {
        *id = this->id;///obtengo el dato de legajo y lo guardo en la direccion de memoria del puntero a legajo
        todoOk=1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk=0;
    if(this!=NULL && nombre!=NULL  && strlen(nombre)>0 && strlen(nombre)<20)
    {
        strcpy(this->nombre, nombre);
        todoOk=1;
    }
    return todoOk;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk=0;
    if(nombre!=NULL && this!=NULL)
    {
       strcpy(nombre, this->nombre);
        todoOk=1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk=0;
    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk=0;
    if(horasTrabajadas!=NULL && this!=NULL)
    {
        *horasTrabajadas= this->horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk=0;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo = sueldo;
        todoOk=1;
    }
    return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk=0;
    if(sueldo!=NULL && this!=NULL)
    {
        *sueldo= this->sueldo;
        todoOk=1;
    }
    return todoOk;
}

int mostrarEmpleado(Employee* e)
{
    int todoOk=0;
    int id;
    char nombre[50];
    int horas;
    int sueldo;

    if(e!=NULL){
        if(employee_getId(e, &id) &&
           employee_getNombre(e, nombre) &&
           employee_getHorasTrabajadas(e, &horas) &&
           employee_getSueldo(e, &sueldo))
        {
            printf("ID: %d    Nombre: %s    Horas trabajadas: %d     Sueldo: %d \n", id, nombre, horas, sueldo);
        }
        else
        {
            printf("No se pudo mostrar el empleado\n");
        }
        todoOk=1;
    }
    return todoOk;

}

int buscarMayorID(LinkedList* pArrayListEmployee, int* id)
{
    int todoOk=0;
    Employee* auxEmployee;
    int mayor;
    int auxId;
    int len;

    len=ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        for(int i=0; i<len; i++)
        {
            auxEmployee=(Employee*) ll_get(pArrayListEmployee, i);
            employee_getId(auxEmployee, &auxId);
            if(i==0 || auxId > mayor)
            {
                mayor=auxId;
            }
        }

        *id= mayor + 1;
    }
        todoOk=1;

        return todoOk;
}

int employee_IndexById(LinkedList* pArrayListEmployee, int id)
{
    int index;
    int auxId;
    Employee* auxEmployee;

    if(pArrayListEmployee!=NULL)
    {
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmployee=ll_get(pArrayListEmployee,i);
            employee_getId(auxEmployee, &auxId);
            if(auxId==id)
            {
                index=i;
            }
        }
        return index;
    }
    else
    {
        return -1;
    }

}

int employee_CompareNombre(void* a, void* b)
{
    int retorno = 0;
    Employee* emp1=NULL;
    Employee* emp2=NULL;

    if(a!=NULL && b!=NULL)
    {
        emp1= (Employee*) a;
        emp2= (Employee*) b;
        retorno=strcmp(emp1->nombre, emp2->nombre);
    }

    return retorno;

}

int employee_CompareSueldo(void* a, void* b)
{
    int retorno = 0;
    Employee* emp1=NULL;
    Employee* emp2=NULL;

    if(a!=NULL && b!=NULL)
    {
        emp1= (Employee*) a;
        emp2= (Employee*) b;
        if(emp1->sueldo> emp2->sueldo)
        {
            retorno=1;
        }else if(emp1->sueldo < emp2->sueldo)
        {
            retorno=-1;
        }
    }

    return retorno;

}


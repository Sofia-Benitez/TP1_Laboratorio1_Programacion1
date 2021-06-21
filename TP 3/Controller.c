#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief imprime un menu de opciones
 *
 * \param void
 * \return void
 *
 */
void menu(void)
{
    printf("***************************************************************************\n");
    printf("*                             MENU                                        *\n");
    printf("* 1. Cargar los datos de los empleados desde un archivo de texto (.csv)   *\n");
    printf("* 2. Cargar los datos de los empleados desde un archivo binario  (.bin)   *\n");
    printf("* 3. Alta de empleado                                                     *\n");
    printf("* 4. Modificar datos de empleado                                          *\n");
    printf("* 5. Baja de empleado                                                     *\n");
    printf("* 6. Listar empleados                                                     *\n");
    printf("* 7. Ordenar empleados                                                    *\n");
    printf("* 8. Guardar los datos de los empleados en un archivo de texto (.csv)     *\n");
    printf("* 9. Guardar los datos de los empleados en un archivo binario  (.bin)     *\n");
    printf("* 10. SALIR                                                               *\n");
    printf("***************************************************************************\n");

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    char confirm='s';
    int index;
    int len;
    len=ll_len(pArrayListEmployee);

    FILE* f = fopen(path, "r");
    if(f==NULL)
    {
        printf("No se puede abrir el archivo\n");
        system("pause");
        exit(1);
    }
    else
    {
        if(len>0)
        {
            printf("Si carga los datos de este archivo se sobrescribiran los empleados existentes. Desea confirmar?(s): ");
            fflush(stdin);
            scanf("%c", &confirm);

        }

        if(confirm=='s')
        {
            //borro los empleados existentes
            for(int i=1; i<=len; i++)
            {
                index = employee_IndexById(pArrayListEmployee, i);
                ll_remove(pArrayListEmployee, index);
            }

            if(parser_EmployeeFromText(f, pArrayListEmployee))
            {
                printf("El archivo se leyo exitosamente\n");
                todoOk=1;
            }
        }

    }

    fclose(f);
    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    char confirm;
    int index;
    int len;

    len=ll_len(pArrayListEmployee);


    FILE* f = fopen(path, "rb");
    if(f==NULL)
    {
        printf("No se puede abrir el archivo\n");
        exit(1);
    }
    else
    {
        printf("El archivo se leyo exitosamente\n");

        if(ll_len(pArrayListEmployee)>0)
        {
            printf("Si carga los datos de este archivo se sobrescribiran los empleados existentes. Desea confirmar?(s): ");
            fflush(stdin);
            scanf("%c", &confirm);

        }

        if(confirm=='s' || ll_len(pArrayListEmployee)==0)
        {
            for(int i=1; i<=len; i++)
            {
                index = employee_IndexById(pArrayListEmployee, i);
                ll_remove(pArrayListEmployee, index);
            }

            parser_EmployeeFromBinary(f, pArrayListEmployee);

            todoOk=1;
        }

    }

    fclose(f);

    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int id)
{
    int todoOk=0;
    Employee* newEmployee;

    newEmployee=employee_create(id);

    if(newEmployee!=NULL)
    {
        ll_add(pArrayListEmployee, newEmployee);
        todoOk=1;
    }

    return todoOk;

}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int opcion;
    char nuevoNombre[51];
    int nuevoSueldo;
    int nuevasHoras;
    int idIngresado;
    int index;
    Employee* auxEmployee;

    if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)>0)
    {
            system("cls");
            printf(" ******** Modificacion de empleados ********\n");
            controller_ListEmployee(pArrayListEmployee);
            printf("\nSeleccione el id del empleado que desea modificar: ");
            scanf("%d", &idIngresado);

            index=employee_IndexById(pArrayListEmployee, idIngresado);
            if(index==-1)
            {
                printf("Empleado inexistente\n");
            }
            else
            {
                auxEmployee=ll_get(pArrayListEmployee, index);
                mostrarEmpleado(auxEmployee);
                printf("1. Modificar nombre\n");
                printf("2. Modificar horas trabajadas\n");
                printf("3. Modificar salario\n");
                utn_getNumero(&opcion, "Ingrese el campo que desea modificar: ", "Error.\n", 1, 3, 3);


                switch(opcion)
                {
                    case 1:
                        utn_getStringNombre(nuevoNombre, "Ingrese el nuevo nombre: ", "Error\n", 51, 3);
                        employee_setNombre(auxEmployee, nuevoNombre);
                        printf("Nombre modificado con exito\n");
                        break;
                    case 2:
                        utn_getNumero(&nuevasHoras, "Ingrese la cantidad de horas trabajadas: ", "Error\n", 0, 50000, 3);
                        employee_setHorasTrabajadas(auxEmployee, nuevasHoras);
                        printf("Horas trabajadas modificadas con exito\n");
                        break;
                    case 3:
                        utn_getNumero(&nuevoSueldo, "Ingrese el nuevo sueldo: ", "Error\n", 0, 90000, 3);
                        employee_setSueldo(auxEmployee, nuevoSueldo);
                        printf("Horas trabajadas modificadas con exito\n");
                        break;
                }
            }

            todoOk=1;

        }

    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int index;
    int idIngresado;


        if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)>0)
        {
            controller_ListEmployee(pArrayListEmployee);
            printf("Seleccione el id del empleado que desea eliminar: ");
            scanf("%d", &idIngresado);

            index=employee_IndexById(pArrayListEmployee, idIngresado);
            if(index==-1)
            {
                printf("Empleado inexistente\n");
            }
            else
            {
                ll_remove(pArrayListEmployee, index);
            }

            todoOk=1;

        }
    return todoOk;
}



/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    if(pArrayListEmployee!=NULL)
    {
        if(ll_len(pArrayListEmployee)>0)
        {
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                mostrarEmpleado((Employee*) ll_get(pArrayListEmployee, i));
            }
            todoOk=1;
        }
    }
    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int todoOk=0;
    int len;
    len=ll_len(pArrayListEmployee);

    printf("Ingrese 1 para ordenar por nombre y 2 para ordenar por sueldo: ");
    scanf("%d", &opcion);

    if(pArrayListEmployee!=NULL && len>0)
    {
        if(opcion==1)
        {
            printf("Ordenando. Aguarde por favor\n");
            ll_sort(pArrayListEmployee, employee_CompareNombre, 1);
            printf("Ordenanamiento finalizado\n");
        }

        if(opcion==2)
        {
            printf("Ordenando. Aguarde por favor\n");
            ll_sort(pArrayListEmployee, employee_CompareSueldo, 1);
            printf("Ordenanamiento finalizado\n");
        }
        todoOk=1;
    }


    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    ///escribir un archivo de texto
    Employee* auxEmployee;
    int auxId;
    char auxNombre[20];
    int auxHorasTrabajadas;
    int auxSueldo;
    char confirm='s';
    int todoOk=0;

    FILE* f = fopen(path, "w");
    if(f==NULL)
    {
        printf("No se puede escribir el archivo");
        exit(1);
    }
    else
    {
        printf("El archivo %s existe. Desea sobrescribirlo?: (si=s) ", path);
        fflush(stdin);
        scanf("%c", &confirm);
        if(confirm=='s')
        {
            fprintf(f, "legajo, nombre, sexo, sueldo\n");

            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmployee=ll_get(pArrayListEmployee, i);
                if(employee_getId(auxEmployee, &auxId)&&
                        employee_getNombre(auxEmployee, auxNombre)&&
                        employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas) &&
                        employee_getSueldo(auxEmployee, &auxSueldo))
                {
                    fprintf(f, "%d, %s, %d, %d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
                }
            }
            todoOk=1;
        }
    }
    fclose(f);
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
     Employee* auxEmployee;
     int todoOk=0;
     char confirm='s';
     FILE* f;

    f = fopen(path, "rb");
    if(f!=NULL)
    {
        printf("Cuidado! El archivo ya existe. Desea sobreescribirlo? (s=si): ");
        fflush(stdin);
        scanf("%c", &confirm);
    }
    fclose(f);


    if(confirm=='s')
    {
        f = fopen(path, "wb");
        if(f==NULL)
        {
            printf("No se pudo escribir el archivo\n");
            exit(1);
        }
        else
        {
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
            auxEmployee=ll_get(pArrayListEmployee, i);
            fwrite(auxEmployee, sizeof(Employee), 1, f);

            }
        }

        fclose(f);

        todoOk=1;
    }


    return todoOk;
}


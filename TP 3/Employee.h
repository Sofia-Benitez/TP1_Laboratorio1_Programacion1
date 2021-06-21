#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"

typedef struct{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief funcion que busca lugar en memoria para crear una estructura del tipo Employee
 *
 * \return Employee*  devuelve un lugar en la memoria para una estructura Employee
 *
 */
Employee* employee_new();
/** \brief funcion que crea un empleado con parametros
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*   devuelve una estructura Employee cargada por datos por parametros
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
/** \brief funcion que crea un empleado pidiendole al usuario los datos y pasando el id por referencia
 *
 * \param id int
 * \return Employee*   devuelve un empleado cargado
 *
 */
Employee* employee_create(int id);


int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief funcion que muestra un empleado del tipo estructura Employee
 *
 * \param e Employee*
 * \return int
 *
 */
int mostrarEmpleado(Employee* e);
/** \brief funcion que recorre el array buscando el numero de id mas grande y actualiza el siguiente id en el main
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int*
 * \return int
 *
 */
int buscarMayorID(LinkedList* pArrayListEmployee, int* id);
/** \brief funcion que busca el index de un empleado segun su id
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return int    devuelve el indice del empleado seleccionado o -1 si no lo encuentra
 *
 */
int employee_IndexById(LinkedList* pArrayListEmployee, int id);

//coparisions
int employee_CompareNombre(void* a, void* b);
int employee_CompareSueldo(void* a, void* b);


#endif // employee_H_INCLUDED

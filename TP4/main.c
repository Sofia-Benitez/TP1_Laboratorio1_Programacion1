#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

typedef struct{
    int id;
    char nombre[128];
    int grado;
    int edad;
}eAlumno;

int alumno_setId(eAlumno* this,int id);
int alumno_getId(eAlumno* this,int* id);
int alumno_setNombre(eAlumno* this,char* nombre);
int alumno_getNombre(eAlumno* this,char* nombre);
int alumno_setGrado(eAlumno* this,int grado);
int alumno_getGrado(eAlumno* this,int* grado);
int alumno_setEdad(eAlumno* this,int edad);
int alumno_getEdad(eAlumno* this,int* edad);


//int cargarDesdeTexto(char* path, LinkedList* pLista);
//eAlumno* alumno_newParametros(char* idStr,char* nombreStr,char* gradoStr, char* edadStr);
int mostrarAlumno(eAlumno* a);
int listarAlumnos(LinkedList* lista);
int alumno_CompareNombre(void* a, void* b);


int main()
{
    int len;
    //char path[20]= "datos.csv";

    ///instancio un LinkedList utilizando ll_newLinkedList
    LinkedList* lista = ll_newLinkedList();

    ///agrego alumnos a la lista con ll_add
    eAlumno a1 = {1, "Lily", 5, 10};
    ll_add(lista, &a1);

    eAlumno a2 = {2, "Carlitos", 2, 6};
    ll_add(lista, &a2);

    eAlumno a3 = {3, "Tommy", 4, 8};
    ll_add(lista, &a3);

    eAlumno a4 = {4, "Angelica", 7, 12};
    ll_add(lista, &a4);

    eAlumno a5 = {5, "Phili", 5, 10};
    ll_add(lista, &a5);

    eAlumno a6 = {6, "Pi", 5, 9};
    ll_add(lista, &a6);

    ///muestro la cantidad de elementos en el LL////////////////////////////////////////////////////////
    len=ll_len(lista);
    printf("Cantidad de elementos en la lista: %d\n", len);

    printf("\n\n");
    ///muestro todos los alumnos de la lista///////////////////////////////////////////////////////////
    printf("Lista inicial\n");
    listarAlumnos(lista);

    printf("\n\n");
    ///clono la lista original con ll_clone/////////////////////////////////////////////////////////////

    LinkedList* lista2 = NULL;

    lista2 = ll_clone(lista);
    printf("Lista clonada\n");
    listarAlumnos(lista2);

    printf("\n\n");
    ///creo un nuevo alumno y lo agrego en la lista con ll_push////////////////////////////////////////////

    eAlumno a7 = {7, "Riley", 1, 5};
    ll_push(lista, 4, &a7);
    printf("Lista despues de un push\n");
    listarAlumnos(lista);

    printf("\n\n");
    ///saco un alumno con ll_pop//////////////////////////////////////////////////////////////////////////

    eAlumno* aux;
    aux = (eAlumno*) ll_pop(lista, 1);
    printf("Alumno eliminado con pop\n");
    mostrarAlumno(aux);
    printf("\n\n");
    printf("Lista despues de un pop\n");
    listarAlumnos(lista);



    printf("\n\n");
    ///inserto un alumno con ll_set en el indice 2/////////////////////////////////////////////////////
    eAlumno a8 = {8, "Arnold", 6, 10};
    ll_set(lista, 2, &a8);
    printf("Lista despues de un set en el indice 2\n");
    listarAlumnos(lista);

    printf("\n\n");
    ///elimino un alumno con ll_remove///////////////////////////////////////////////////////////////////
    ll_remove(lista, 5);
    printf("Lista despues de remover al alumno en el indice 5\n");
    listarAlumnos(lista);


    printf("\n\n");
    ///pregunto si la lista esta vacia con ll_isEmpty/////////////////////////////////////////////////////

        if(!ll_isEmpty(lista))
        {
            printf("Lista con elementos\n");
        }
        else
        {
            printf("lista vacia\n");
        }

    printf("\n\n");
    ///busco el indice de un alumno con ll_indexOf////////////////////////////////////////////////////////
    int i= ll_indexOf(lista, &a3);
    printf("Indice obtenido: %d \n", i);


    printf("\n\n");
    ///busco un alumno en particular con ll_get y lo muestro/////////////////////////////////////////////
     printf("Alumno ubicado en el indice %d:\n", i);
    mostrarAlumno((eAlumno*) ll_get(lista, i));



    printf("\n\n");
    ///busco si la lista 1 contiene un elemento con ll_contains//////////////////////////////////////////
    if(ll_contains(lista, &a3))
    {
        printf("La lista original contiene al elemento\n");
    }
    else
    {
         printf("La lista original no contiene al elemento\n");
    }


    printf("\n\n");
    ///busco si las listas contienen los mismos elementos con ll_containsAll //////////////////////////////////////

    if(ll_containsAll(lista2, lista))
    {
         printf("Las listas contienen los mismos elementos\n");
    }
    else
    {
         printf("Las listas no contienen los mismos elementos\n");
    }


    printf("\n\n");
    ///creo una sublista desde la lista2 con ll_sublist////////////////////////////////////////////////////////////

    LinkedList* sublista = NULL;
    sublista = ll_subList(lista2, 2, 4);
    printf("Sublista de la lista2 con los elementos del indice 2 al 4\n");
    listarAlumnos(sublista);


    printf("\n\n");
    ///ordeno los elementos de la lista2 por nombre alfabeticamente//////////////////////////////////////////////////////

    ll_sort(lista2, alumno_CompareNombre, 0);
    printf("Lista 2 ordenada alfabeticamente\n");
    listarAlumnos(lista2);



    ///elimino todos los elementos de la lista///////////////////////////////////////////////////////////
    ll_clear(lista);
    listarAlumnos(lista);



    ///elimino el linkedlist/////////////////////////////////////////////////////////////////////////////
    if(!(ll_deleteLinkedList(lista)))
    {
        printf("lista eliminada\n");
    }

    return 0;
}



//setters y getters

int alumno_setId(eAlumno* this,int id)
{
    int todoOk=0;
    if(this!=NULL && id>0)
    {
        this->id = id;
        todoOk=1;
    }
    return todoOk;
}
int alumno_getId(eAlumno* this,int* id)
{
    int todoOk=0;
    if(id!=NULL && this!=NULL)
    {
        *id = this->id;///obtengo el dato de legajo y lo guardo en la direccion de memoria del puntero a legajo
        todoOk=1;
    }
    return todoOk;
}

int alumno_setNombre(eAlumno* this,char* nombre)
{
    int todoOk=0;
    if(this!=NULL && nombre!=NULL  && strlen(nombre)>0 && strlen(nombre)<20)
    {
        strcpy(this->nombre, nombre);
        todoOk=1;
    }
    return todoOk;
}
int alumno_getNombre(eAlumno* this,char* nombre)
{
    int todoOk=0;
    if(nombre!=NULL && this!=NULL)
    {
       strcpy(nombre, this->nombre);
        todoOk=1;
    }
    return todoOk;
}

int alumno_setGrado(eAlumno* this,int grado)
{
    int todoOk=0;
    if(this!=NULL && grado>0)
    {
        this->grado = grado;
        todoOk=1;
    }
    return todoOk;
}
int alumno_getGrado(eAlumno* this,int* grado)
{
    int todoOk=0;
    if(grado!=NULL && this!=NULL)
    {
        *grado= this->grado;
        todoOk=1;
    }
    return todoOk;
}

int alumno_setEdad(eAlumno* this,int edad)
{
    int todoOk=0;
    if(this!=NULL && edad>0 && edad<20)
    {
        this->edad = edad;
        todoOk=1;
    }
    return todoOk;
}
int alumno_getEdad(eAlumno* this,int* edad)
{
    int todoOk=0;
    if(edad!=NULL && this!=NULL)
    {
        *edad= this->edad;
        todoOk=1;
    }
    return todoOk;
}


int mostrarAlumno(eAlumno* a)
{
    int todoOk=0;
    int id;
    char nombre[50];
    int grado;
    int edad;

        if(a!=NULL){

        alumno_getId(a, &id);
        alumno_getNombre(a, nombre);
        alumno_getGrado(a, &grado);
        alumno_getEdad(a, &edad);

        printf(" %d     %10s          %d           %d \n", id, nombre, grado, edad);
        }
        else
        {
            printf("No se pudo mostrar el alumno\n");
        }

        todoOk=1;

    return todoOk;

}

int listarAlumnos(LinkedList* lista)
{
    int todoOk=0;
    if(lista!=NULL)
    {

        if(ll_len(lista)>0)
        {
            printf("  ID        Nombre      Grado        Edad\n");
            for(int i=0; i<ll_len(lista); i++)
            {
                mostrarAlumno((eAlumno*) ll_get(lista, i));
            }
            todoOk=1;
        }
        else
        {
            printf("lista vacia\n");
        }
    }
    return todoOk;
}

int alumno_CompareNombre(void* a, void* b)
{
    int retorno = 0;
    eAlumno* a1=NULL;
    eAlumno* a2=NULL;
    char nombre1[20];
    char nombre2[20];

    if(a!=NULL && b!=NULL)
    {
        a1= (eAlumno*) a;
        a2= (eAlumno*) b;
        alumno_getNombre(a1, nombre1);
        alumno_getNombre(a2, nombre2);
        retorno=strcmp(nombre1, nombre2);
    }

    return retorno;

}

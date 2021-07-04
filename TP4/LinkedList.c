#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    ///busco espacio para el LL en memoria dinamica
    LinkedList* this= (LinkedList*) malloc(sizeof(LinkedList));

    ///inicializo los elementos de la estructura LinkedList
    if(this!=NULL)
    {
        this->pFirstNode=NULL;
        this->size=0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux=this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* node = NULL;

    if(this!= NULL && nodeIndex>=0 && nodeIndex<ll_len(this))
    {
        node=this->pFirstNode;///direccion del primer vagon

        ///si solo existe la locomotora
        while(nodeIndex>0)
        {
            node=node->pNextNode;
            nodeIndex--;//restar el indice
        }
    }
    return node;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* node = NULL;//nodo que se va a crear
    Node* nodeAux = NULL;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
    {
        node = (Node*) malloc(sizeof(Node));//espacio para un nodo

        if(node!=NULL)
        {
            node->pElement=pElement;//nodo apunta a su carga (llego por parametro)
            node->pNextNode=getNode(this, nodeIndex);//el nodo apunta al que estaba antes
            if(nodeIndex==0)
            {
                this->pFirstNode=node;//si el indice es 0 el nodo apunta al primero, se engancha de este
            }
            else
            {
                nodeAux=getNode(this, nodeIndex-1);//si ya habia algun nodo el nuevo nodo se engancha del anterior
                nodeAux->pNextNode=node;
            }
            this->size++;
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        ///devuelve 0 addNode si puede agregar el nodo.
        returnAux=addNode(this, ll_len(this), pElement);//en ll_len porque es la ultima posicion

    }

    return returnAux;
}

/** \brief obtiene un puntero al elemento del nodo indicado por el indice
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode=NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        auxNode=getNode(this, index);//obtengo el nodo del indice que me pasan
        if(auxNode!=NULL)
        {
            returnAux=auxNode->pElement;
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)//suelta la carga anterior pero no la borra.
{
    int returnAux = -1;
    Node* auxNode = NULL;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        auxNode=getNode(this, index);
        if(auxNode!=NULL)
        {
            auxNode->pElement=pElement;
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* actual=NULL;//aux del nodo actual para obtener su indice
    Node* anterior=NULL;
    Node* aux=NULL;
    ///del elemento que quiero remover hay que enganchar el pNextNode al de atras. El pnodo puede ser el LL o un nodo.
    ///la dir de memoria del nodo anterior la tiene el nodo que quiero borrar (pNextNode)
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        actual=getNode(this, index);
        if(actual!=NULL)
        {
            if(index==0)//vagon a linkedlist
            {
                aux= this->pFirstNode;//guardo el elemento que voy a eliminar
                this->pFirstNode=actual->pNextNode;//tengo la direccion de memoria del vagon 0, puedo acceder al next node de ese vagon. copio ne la locomotora la direccion del primer vagon
            }
            else///otro nodo
            {
                anterior=getNode(this, index-1);///puntero al vagon de adelante
                if(anterior!=NULL)
                {
                    aux=anterior->pNextNode;
                    anterior->pNextNode=actual->pNextNode;//hago que le vagon de adelante apunte al que este atras
                }
            }
            free(aux);//libero la memoria del aux
            this->size--;///descuento el tamanio del LL
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        while(ll_len(this)!=0)//si hay nodos remuevo el primero
        {
            ll_remove(this,0);///siempre va borrando el 0 porque cuando se van borrando cambian de indice
        }
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(!(ll_clear(this)))
        {
            free(this);
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        for(int i=0; i<ll_len(this); i++)
        {
            if(pElement==ll_get(this,i))//busco el nodo correspondiente en el LL
            {
                returnAux=i;///guardo el indice del elemento pasado por parametro
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int tam;

    if(this!=NULL)
    {
        tam=ll_len(this);
        returnAux=1;

        if(tam>0)
        {
            returnAux=0;///si la lista no esta vacia
        }

    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this, index, pElement);///add noce en un indice especifico
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
         returnAux=ll_get(this, index);//el get nos devuelve el nodo que queremos sacar y lo guardo en un aux
         if(ll_remove(this, index))
         {
             returnAux=NULL;
         }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux=0;
        if(ll_indexOf(this, pElement)>=0)///si existe el indice del elemento / !=-1
        {
            returnAux=1;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int tam;
    tam=ll_len(this2);//tam del segundo array. lo recorro para preguntar si esta en el primero

    if(this!=NULL && this2!=NULL)
    {
        returnAux=1;//si estan todos los elementos
        for(int i=0; i<tam; i++)//busco si falta alguno
        {
            if(!ll_contains(this, ll_get(this2, i)))//si uno no esta ya no los contiene a todos
            {
                returnAux=0;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if(this!=NULL && from>=0 && to>=from && to <=ll_len(this))
    {
        cloneArray= ll_newLinkedList();
        if(cloneArray!=NULL)
        {
            for(int i=from; i<to; i++)//desde from a to sin incluirlo
            {
                ll_add(cloneArray, ll_get(this, i));//en clonearray voy cargando lo que obtengo con el get
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    cloneArray = ll_subList(this, 0, ll_len(this));///sublist con todos los elementos,de 0 a len
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)///en la llamada es el compare sin parentesis
{
    int returnAux =-1;
    int tam;
    void* auxI=NULL;
    void* auxJ=NULL;

    if(this!=NULL && pFunc!=NULL && order >=0 && order <=1)
    {
        tam=ll_len(this);
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                auxI= ll_get(this, i);//tomo el elemento en cada iteracion. guardada la direccion de las cargas
                auxJ=ll_get(this, j);//carga del vagon del indice j
                if((pFunc(auxI, auxJ)<0 && order) || (pFunc(auxI, auxJ)>0 && !order))//las dos situaciones en las que se swapea
                {
                    //swap
                    ll_set(this, i, auxJ);//en el indice i le guardo la carga del j
                    ll_set(this, j, auxI);
                }

            }
        }
        returnAux=0;
    }

    return returnAux;

}


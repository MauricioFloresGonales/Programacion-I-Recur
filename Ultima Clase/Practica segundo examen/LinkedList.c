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
    LinkedList* lista= NULL;

    lista = (LinkedList*) malloc(sizeof(LinkedList));

    if(lista!=NULL)
    {
        lista -> pFirstNode = NULL;
        lista ->size = 0;
    }

    return lista;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* lista)
{
    int returnAux = -1;
    if(lista!=NULL)
    {
        returnAux = lista->size;
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
static Node* getNode(LinkedList* lista, int nodeIndex)
{
    Node* pNodo = NULL;
    int len = ll_len(lista);
    int i;

    if(lista!=NULL && nodeIndex<len && nodeIndex>-1)
    {
        pNodo = lista->pFirstNode;

        for(i=0; i<nodeIndex; i++)
        {
            pNodo = pNodo->pNextNode;
        }
    }
    return pNodo;
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
static int addNode(LinkedList* lista, int nodeIndex,void* pElement)
{
    Node* anterior = NULL;
    Node* nuevo = NULL;
    int returnAux = -1;
    int len;

    if(lista!=NULL)
    {
        len = ll_len(lista);

        if(nodeIndex>-1 && len>=nodeIndex)
        {
            nuevo = (Node*)malloc(sizeof(Node));
            nuevo->pElement = pElement;

            if(lista->pFirstNode == NULL)
            {
                lista->pFirstNode = nuevo;
                nuevo->pNextNode = NULL;
            }
            else
            {
                if(nodeIndex == 0)
                {
                    nuevo->pNextNode = lista->pFirstNode;
                    lista->pFirstNode = nuevo;
                }
                else
                {
                    anterior = getNode(lista,nodeIndex-1);
                    nuevo->pNextNode = anterior->pNextNode;
                    anterior->pNextNode = nuevo;
                }
            }

            lista->size++;
        }

        returnAux=0;
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
int ll_add(LinkedList* lista, void* pElement)
{
    int returnAux = -1;
    int len;

    if(lista!=NULL)
    {
        returnAux=addNode(lista,ll_len(lista),pElement);//Que pasa si agrego un elemento a la mitad de la lista?? esto aria que mi lista se ingrementara por uno??
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    Node* pNode = NULL;
    void* retorno = NULL;
    if(this != NULL && index >-1 && index<ll_len(this))
    {
        pNode = getNode(this,index);
        retorno = pNode->pElement;
    }

    return retorno;
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
int ll_set(LinkedList* this, int index,void* pElement)
{
    Node* nuevo = NULL;
    Node* anterior = NULL;//free(pNode);Tendria que liberar la dirreccion de memoria del nodo que ya no tengo enlazado??
    int len;
    int returnAux = -1;

    if(this!=NULL)
    {
        len = ll_len(this);

        if(index>-1 && len>index)
        {
            nuevo = (Node*)malloc(sizeof(Node));
            nuevo->pElement = pElement;

            if(this->pFirstNode == NULL)
            {
                addNode(this,index,pElement);
            }
            else
            {
                if(index == 0)
                {
                    nuevo->pNextNode = this->pFirstNode->pNextNode;
                    free(this->pFirstNode);
                    this->pFirstNode = nuevo;
                }
                else
                {
                    anterior = getNode(this,index-1);
                    nuevo->pNextNode = anterior->pNextNode->pNextNode;
                    free(anterior->pNextNode);
                    anterior->pNextNode = nuevo;
                }
            }
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
    Node* pNode = NULL;
    Node* anterior = NULL;
    int returnAux = -1;
    int len;

    if(this!=NULL)
    {
        len = ll_len(this);

        if(index>-1 && len>index)
        {
            pNode = getNode(this,index);
            if(index==0)
            {
                this->pFirstNode = pNode->pNextNode;
                free(pNode);
                this->size--;
            }
            else
            {
                anterior = getNode(this,index-1);
                anterior->pNextNode = pNode->pNextNode;
                free(pNode);
                this->size--;
            }
            returnAux = 0;
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
    Node* pNodo = NULL;
    int returnAux = -1;
    int len;
    int i;

    if(this!=NULL)
    {
        len = ll_len(this);
        for(i=len; i>0; i--)
        {
            if(i==0)
            {
                pNodo = getNode(this,i);
                this->pFirstNode = NULL;
                this->size = 0;
            }
            else
            {
                pNodo = getNode(this,i);
                this->size--;
            }
            free(pNodo);
        }
        returnAux = 0;
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
        if(ll_clear(this)==0)
        {

            free(this);

        }
        returnAux = 0;
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
    Node* pNodo;
    int returnAux = -1;
    int i;
    int len;

    if(this!=NULL)
    {
        len = ll_len(this);
        for(i=0; i<len; i++)
        {
            pNodo = getNode(this,i);
            if(pNodo->pElement == pElement)
            {
                returnAux = i;
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
    if(this!=NULL)
    {
        if(ll_len(this)>0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
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
    int returnAux = -1;
    int len;
    if(this!=NULL)
    {
        len = ll_len(this);

        if(index>-1 && len>=index)
        {
            returnAux = addNode(this,index,pElement);
        }
    }
    return returnAux;
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
    int len;
    if(this!=NULL)
    {
        len = ll_len(this);

        if(index>-1 && len>=index)
        {
            returnAux = ll_get(this,index);
            ll_remove(this,index);

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
    int returnAux =-1;
    if(this!=NULL)
    {
        if(ll_indexOf(this,pElement)!=-1)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
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
    Node* pNodo = NULL;
    int returnAux = -1;
    int len;
    int i;
    if(this!=NULL && this2!=NULL)
    {
        len=ll_len(this2);
        for(i=0; i<len; i++)
        {
            pNodo = ll_get(this2,i);
            if((ll_contains(this,pNodo))==0)
            {
                returnAux = 0;
                break;
            }
        }

        if(returnAux!=0)
        {
            returnAux = 1;
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
    Node* pNodo = NULL;
    int len;
    int i;

    if(this!=NULL)
    {
        len=ll_len(this);
        if(from>-1&& to>from && from<len && to<=len)
        {
            cloneArray = ll_newLinkedList();
            for(i=from; i<to; i++)
            {
                pNodo = ll_get(this,i);
                ll_add(cloneArray,pNodo);
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
    int len;
    if(this!=NULL)
    {
        len = ll_len(this);
        cloneArray = ll_subList(this,0,len);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int comp;
    void* aux;
    int returnAux =-1;
    int len;
    int i;
    int j;

    if(this!=NULL && pFunc!=NULL && (order==1 || order==0))
    {
        len = ll_len(this);
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                comp = pFunc(ll_get(this,i),ll_get(this,j));
                if(order == 1 && comp == 1)
                {
                    aux = ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,aux);

                }
                else
                {
                    if(order == 0 && comp == -1)
                    {
                        aux = ll_get(this,j);
                        ll_set(this,j,ll_get(this,i));
                        ll_set(this,i,aux);
                    }

                }
            }
        }
        returnAux = 0;
    }
    return returnAux;
}

LinkedList* filter(LinkedList* this,int (*fn)(void*pElement))
{
    LinkedList* returnAux = NULL;
    int resultado;
    int len;
    void* aux;
    int i;

    if(this!=NULL && fn!=NULL)
    {
        len = ll_len(this);
        for(i=0;i<len;i++)
        {
            aux=ll_get(this,i);
            resultado = fn(aux);
            returnAux = ll_newLinkedList();
            if(resultado == 1)
            {
                ll_add(returnAux,aux);
            }
        }
    }
    return returnAux;
}


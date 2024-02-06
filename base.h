// Jorge Vazquez
// Last update: 2024-05-02

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Alum
{
    char apPat[20];
    char apMat[20];
    char name[20];
} Talum;

typedef struct Nodo
{
    Talum alum;
    struct Nodo *sig; // Apuntador al siguiente nodo
} Nodo;

typedef struct Lista
{
    Nodo *ini; // inicio o cabeza
    int longi; // longitud de la lista
} Lista;

// Esta funcion crea un nodo con los datos de un alumno y lo retorna
Nodo *crearNodo(Talum *alum)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));  // Reservar memoria para el nodo
    strncpy(nuevo->alum.apPat, alum->apPat, 20); // Copiar el apellido paterno
    strncpy(nuevo->alum.apMat, alum->apMat, 20);
    strncpy(nuevo->alum.name, alum->name, 20);
    nuevo->sig = NULL; // El nodo apunta a NULL
    return nuevo;
}

// Esta funcion destruye un nodo
void destruirNodo(Nodo *nodo)
{
    free(nodo);
}

// Esta funcion inserta un nodo al principio de la lista
void insertarPrincipio(Lista *lista, Talum *alum)
{
    Nodo *nuevo = crearNodo(alum);
    nuevo->sig = lista->ini; // El nuevo nodo apunta al inicio
    lista->ini = nuevo;      // El inicio de la lista es el nuevo nodo
    lista->longi++;          // Aumentar la longitud de la lista
}

// Esta funcion inserta un nodo al final de la lista
void insertarFinal(Lista *lista, Talum *alum)
{
    Nodo *nuevo = crearNodo(alum);
    if (lista->ini == NULL) // Si la lista esta vacia
    {
        lista->ini = nuevo;
    }
    else
    {
        Nodo *ptr = lista->ini; // Apuntador al inicio
        while (ptr->sig)        // Mientras el apuntador al siguiente nodo no sea NULL
        {
            ptr = ptr->sig; // Avanzar al siguiente nodo
        }
        ptr->sig = nuevo; // El ultimo nodo apunta al nuevo nodo
    }
    lista->longi++;
}

// Esta funcion inserta un nodo en una posicion especifica de la lista
void insertarMedio(int n, Lista *lista, Talum *alum)
{
    Nodo *nuevo = crearNodo(alum);
    if (lista->ini == NULL) // Si la lista esta vacia
    {
        lista->ini = nuevo;
    }
    else
    {
        Nodo *ptr = lista->ini; // Apuntador al inicio
        int posi = 0;
        while (posi < n && ptr->sig) // Mientras el apuntador al siguiente nodo no sea NULL
        {
            ptr = ptr->sig; // Avanzar al siguiente nodo
            posi++;
        }
        nuevo->sig = ptr->sig; // El nuevo nodo apunta al siguiente nodo
        ptr->sig = nuevo;      // El ultimo nodo apunta al nuevo nodo
    }
    lista->longi++;
}

// Esta funcion buscar el nodo en la posicion n de la lista
Talum *buscar(int n, Lista *lista)
{
    if (lista->ini == NULL)
    {
        return NULL;
    }
    else
    {
        Nodo *ptr = lista->ini;
        int posi = 0;
        while (posi < n && ptr->sig)
        {
            ptr = ptr->sig;
            posi++;
        }
        if (posi == n) // Si se encontro el nodo
        {
            return &ptr->alum; // Retornar el nodo
        }
        else
        {
            return NULL;
        }
    }
}

// Esta funcion devuelve la longitud de la lista
int contar(Lista *lista)
{
    return lista->longi;
}

// Esta funcion elimina el nodo al principio de la lista
void eliminarInicio(Lista *lista)
{
    if (lista->ini)
    {
        Nodo *eliminar = lista->ini;  // Apuntador al nodo a eliminar
        lista->ini = lista->ini->sig; // El inicio de la lista es el siguiente nodo
        destruirNodo(eliminar);       // Liberar memoria
        lista->longi--;               // Disminuir la longitud de la lista
    }
}

// Esta funcion elimina el nodo al final de la lista
void elimnarUltimo(Lista *lista)
{
    if (lista->ini) // Si la lista no esta vacia
    {
        if (lista->ini->sig) // Si la lista tiene mas de un nodo
        {
            Nodo *ptr = lista->ini;
            while (ptr->sig->sig) // Mientras el siguiente nodo no sea el ultimo
            {
                ptr = ptr->sig;
            }
            Nodo *eliminar = ptr->sig; // Apuntador al nodo a eliminar
            ptr->sig = NULL;
            destruirNodo(eliminar);
            lista->longi--;
        }
        else // Si la lista tiene un solo nodo
        {
            Nodo *elimnado = lista->ini;
            lista->ini = NULL;
            destruirNodo(elimnado);
            lista->longi--;
        }
    }
}

// Esta funcion elimina el nodo en la posicion n de la lista
void elimnarElementos(int n, Lista *lista)
{
    if (lista->ini)
    {
        if (n == 0) // Si se quiere eliminar el primer nodo
        {
            Nodo *eliminado = lista->ini;
            lista->ini = lista->ini->sig;
            destruirNodo(eliminado);
            lista->longi--;
        }
        else if (n < lista->longi) // Si se quiere eliminar un nodo en medio de la lista se tiene que recorrer la lista
        {
            Nodo *ptr = lista->ini;
            int posi = 0;
            while (posi < (n - 1)) // Mientras el apuntador al siguiente nodo no sea NULL
            {
                ptr = ptr->sig;
                posi++;
            }
            Nodo *eliminado = ptr->sig;
            ptr->sig = eliminado->sig;
            destruirNodo(eliminado);
            lista->longi--;
        }
    }
}
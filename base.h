// Jorge Vazquez
// Last update: 2024-05-02

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Alum{
    char name[20];
    char especie[20];
    int edad;
    char sexo[20];
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

Nodo *crearNodo(Talum *alum);
void destruirNodo(Nodo *nodo);
void insertarPrincipio(Lista *lista, Talum *alum);
void insertarFinal(Lista *lista, Talum *alum);
void insertarMedio(int n, Lista *lista, Talum *alum);
Talum *buscar(int n, Lista *lista);
int contar(Lista *lista);
void eliminarInicio(Lista *lista);
void elimnarUltimo(Lista *lista);
void elimnarElementos(int n, Lista *lista);
int validar(char msg[], int ri, int rf);

// Esta funcion crea un nodo con los datos de una mascota y lo retorna
Nodo *crearNodo(Talum *alum)
{
    char cadena[50];
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));  // Reservar memoria para el nodo
    
    fflush(stdin);
    gets(cadena);
    strncpy(nuevo->alum.name, cadena, sizeof(cadena)); // Copiar el nombre

    printf("Ingrese la especie de la mascota: ");
    fflush(stdin);
    gets(cadena);
    strncpy(nuevo->alum.especie, cadena, sizeof(cadena));
    
    printf("Ingrese el sexo de la mascota: "); 
    fflush(stdin);
    gets(cadena);
    strncpy(nuevo->alum.sexo , cadena, sizeof(cadena)); 
    
    nuevo->alum.edad = validar("Ingrese la edad de la mascota: ", 0, 100);
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
    printf("%s", nuevo->alum.name);
    printf("%s", nuevo->alum.especie); //! ESTOY PROBANDO ESTO
    printf("%d", nuevo->alum.edad);     //! EL ERROR ES QUE NO PUEDE BUSCAR
    printf("%s", nuevo->alum.sexo);
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

int validar(char msg[], int ri, int rf)
{
    char cadena[50];
    int op;

    do
    {
        printf("%s", msg);
        fflush(stdin);
        gets(cadena);
        op = atoi(cadena); //Convierte la cadena a un numero
    } while (op < ri || op > rf); //Valida que este dentro de los rangos

    return op;
}
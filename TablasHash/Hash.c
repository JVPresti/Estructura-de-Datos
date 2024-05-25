#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANO_TABLA 10

// Estructura de un nodo en la tabla hash
typedef struct Nodo
{
    int clave;
    int valor;
    struct Nodo *siguiente;
} Nodo;

// Estructura de la tabla hash
typedef struct
{
    Nodo *lista[TAMANO_TABLA];
} TablaHash;

// Función para crear un nuevo nodo
Nodo *crearNodo(int clave, int valor)
{
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->clave = clave;
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para inicializar la tabla hash
void inicializarTablaHash(TablaHash *tabla)
{
    for (int i = 0; i < TAMANO_TABLA; i++)
    {
        tabla->lista[i] = NULL;
    }
}

// Función de hash
unsigned int hash(int clave)
{
    return (clave * 2654435761) % TAMANO_TABLA;
}

// Función para insertar un nuevo elemento en la tabla hash
void insertarElemento(TablaHash *tabla, int clave, int valor)
{
    int indice = hash(clave);
    Nodo *nuevoNodo = crearNodo(clave, valor);
    if (tabla->lista[indice] == NULL)
    {
        tabla->lista[indice] = nuevoNodo;
    }
    else
    {
        Nodo *actual = tabla->lista[indice];
        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
    printf("Elemento insertado: Clave = %d, Valor = %d\n", clave, valor);
}

// Función para buscar un elemento en la tabla hash
Nodo *buscarElemento(TablaHash *tabla, int clave)
{
    int indice = hash(clave);
    Nodo *actual = tabla->lista[indice];
    while (actual != NULL)
    {
        if (actual->clave == clave)
        {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

// Función para eliminar un elemento de la tabla hash
void eliminarElemento(TablaHash *tabla, int clave)
{
    int indice = hash(clave);
    Nodo *actual = tabla->lista[indice];
    Nodo *anterior = NULL;
    while (actual != NULL && actual->clave != clave)
    {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual == NULL)
    {
        printf("Elemento no encontrado.\n");
        return;
    }
    if (anterior == NULL)
    {
        tabla->lista[indice] = actual->siguiente;
    }
    else
    {
        anterior->siguiente = actual->siguiente;
    }
    free(actual);
    printf("Elemento eliminado: Clave = %d\n", clave);
}

// Función para actualizar un elemento de la tabla hash
void actualizarElemento(TablaHash *tabla, int clave, int nuevoValor)
{
    Nodo *nodo = buscarElemento(tabla, clave);
    if (nodo != NULL)
    {
        nodo->valor = nuevoValor;
        printf("Elemento actualizado: Clave = %d, Nuevo Valor = %d\n", clave, nuevoValor);
    }
    else
    {
        printf("Elemento no encontrado.\n");
    }
}

// Función para listar todos los elementos de la tabla hash
void listarTablaHash(TablaHash *tabla)
{
    for (int i = 0; i < TAMANO_TABLA; i++)
    {
        Nodo *actual = tabla->lista[i];
        printf("Indice %d: ", i);
        while (actual != NULL)
        {
            printf("(Clave: %d, Valor: %d) -> ", actual->clave, actual->valor);
            actual = actual->siguiente;
        }
        printf("NULL\n");
    }
}

int main()
{
    TablaHash tabla;
    inicializarTablaHash(&tabla);
    int op, clave, valor;

    do
    {
        printf("\n--- Menu ---\n");
        printf("1. Insertar un nuevo elemento\n");
        printf("2. Buscar un elemento\n");
        printf("3. Eliminar un elemento\n");
        printf("4. Actualizar un elemento\n");
        printf("5. Listar la tabla hash\n");
        printf("6. Salir\n");
        op = validar("Selecciona una opcion", 1, 6);
        switch (op)
        {
        case 1:
            printf("Ingrese la clave: ");
            scanf("%d", &clave);
            printf("Ingrese el valor: ");
            scanf("%d", &valor);
            insertarElemento(&tabla, clave, valor);
            system("pause");
            break;
        case 2:
            printf("Ingrese la clave: ");
            scanf("%d", &clave);
            Nodo *nodo = buscarElemento(&tabla, clave);
            if (nodo != NULL)
            {
                printf("Elemento encontrado: Clave = %d, Valor = %d\n", nodo->clave, nodo->valor);
            }
            else
            {
                printf("Elemento no encontrado.\n");
            }
            system("pause");
            break;
        case 3:
            printf("Ingrese la clave: ");
            scanf("%d", &clave);
            eliminarElemento(&tabla, clave);
            system("pause");
            break;
        case 4:
            printf("Ingrese la clave: ");
            scanf("%d", &clave);
            printf("Ingrese el nuevo valor: ");
            scanf("%d", &valor);
            actualizarElemento(&tabla, clave, valor);
            system("pause");
            break;
        case 5:
            listarTablaHash(&tabla);
            system("pause");
            break;
        case 6:
            printf("Saliendo...\n");
            system("pause");
            break;
        default:
            printf("Opción no válida.\n");
            system("pause");
        }
    } while (op != 6);

    return 0;
}

// Funcion para validar que la opcion ingresada este dentro de un rango
int validar(char msg[], int ri, int rf)
{
    char cadena[50];
    int op;

    do
    {
        printf("%s", msg);
        fflush(stdin);
        gets(cadena);
        op = atoi(cadena); // Convierte la cadena a un numero
    } while (op < ri || op > rf); // Valida que este dentro de los rangos

    return op;
}
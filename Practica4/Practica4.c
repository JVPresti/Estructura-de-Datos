#include <stdio.h>
#include <stdlib.h>

// Estructura de un nodo del árbol
typedef struct Nodo
{
    int valor;
    struct Nodo *izquierda;
    struct Nodo *derecha;
} Nodo;

// Función para crear un nuevo nodo
Nodo *crearNodo(int valor)
{
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo en el árbol
Nodo *insertarNodo(Nodo *raiz, int valor)
{
    if (raiz == NULL)
    {
        return crearNodo(valor);
    }
    if (valor < raiz->valor)
    {
        raiz->izquierda = insertarNodo(raiz->izquierda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->derecha = insertarNodo(raiz->derecha, valor);
    }
    return raiz;
}

// Función para buscar un nodo en el árbol
Nodo *buscarNodo(Nodo *raiz, int valor)
{
    if (raiz == NULL || raiz->valor == valor)
    {
        return raiz;
    }
    if (valor < raiz->valor)
    {
        return buscarNodo(raiz->izquierda, valor);
    }
    return buscarNodo(raiz->derecha, valor);
}

// Función para encontrar el nodo con el valor mínimo
Nodo *minimoValorNodo(Nodo *nodo)
{
    Nodo *actual = nodo;
    while (actual && actual->izquierda != NULL)
    {
        actual = actual->izquierda;
    }
    return actual;
}

// Función para eliminar un nodo del árbol
Nodo *eliminarNodo(Nodo *raiz, int valor)
{
    if (raiz == NULL)
        return raiz;
    if (valor < raiz->valor)
    {
        raiz->izquierda = eliminarNodo(raiz->izquierda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->derecha = eliminarNodo(raiz->derecha, valor);
    }
    else
    {
        if (raiz->izquierda == NULL)
        {
            Nodo *temp = raiz->derecha;
            free(raiz);
            return temp;
        }
        else if (raiz->derecha == NULL)
        {
            Nodo *temp = raiz->izquierda;
            free(raiz);
            return temp;
        }
        Nodo *temp = minimoValorNodo(raiz->derecha);
        raiz->valor = temp->valor;
        raiz->derecha = eliminarNodo(raiz->derecha, temp->valor);
    }
    return raiz;
}

// Funciones de recorrido del árbol
void recorridoInOrden(Nodo *raiz)
{
    if (raiz != NULL)
    {
        recorridoInOrden(raiz->izquierda);
        printf("%d ", raiz->valor);
        recorridoInOrden(raiz->derecha);
    }
}

void recorridoPreOrden(Nodo *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->valor);
        recorridoPreOrden(raiz->izquierda);
        recorridoPreOrden(raiz->derecha);
    }
}

void recorridoPostOrden(Nodo *raiz)
{
    if (raiz != NULL)
    {
        recorridoPostOrden(raiz->izquierda);
        recorridoPostOrden(raiz->derecha);
        printf("%d ", raiz->valor);
    }
}

// Función para contar el número de nodos
int contarNodos(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    return 1 + contarNodos(raiz->izquierda) + contarNodos(raiz->derecha);
}

// Función para calcular la profundidad del árbol
int profundidadArbol(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    int profundidadIzquierda = profundidadArbol(raiz->izquierda);
    int profundidadDerecha = profundidadArbol(raiz->derecha);
    if (profundidadIzquierda > profundidadDerecha)
    {
        return profundidadIzquierda + 1;
    }
    else
    {
        return profundidadDerecha + 1;
    }
}

// Función para verificar si el árbol está balanceado
int estaBalanceado(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return 1;
    }
    int profundidadIzquierda = profundidadArbol(raiz->izquierda);
    int profundidadDerecha = profundidadArbol(raiz->derecha);
    if (abs(profundidadIzquierda - profundidadDerecha) <= 1 && estaBalanceado(raiz->izquierda) && estaBalanceado(raiz->derecha))
    {
        return 1;
    }
    return 0;
}

// Función para modificar el valor de un nodo
void modificarNodo(Nodo *raiz, int valorViejo, int valorNuevo)
{
    Nodo *nodo = buscarNodo(raiz, valorViejo);
    if (nodo != NULL)
    {
        nodo->valor = valorNuevo;
    }
    else
    {
        printf("Nodo con valor %d no encontrado.\n", valorViejo);
    }
}

int main()
{
    Nodo *raiz = NULL;
    int op, valor, valorViejo, valorNuevo;

    do
    {
        printf("\n--- Menu ---\n");
        printf("1. Insertar nodo\n");
        printf("2. Buscar nodo\n");
        printf("3. Eliminar nodo\n");
        printf("4. Recorrer árbol (InOrden)\n");
        printf("5. Recorrer árbol (PreOrden)\n");
        printf("6. Recorrer árbol (PostOrden)\n");
        printf("7. Contar nodos\n");
        printf("8. Calcular profundidad\n");
        printf("9. Verificar si el árbol está balanceado\n");
        printf("10. Modificar nodo\n");
        printf("11. Salir\n");
        op = validar("Seleccione una opcion: ", 1, 11);
        switch (op)
        {
        case 1:
            printf("Ingrese el valor a insertar: ");
            scanf("%d", &valor);
            raiz = insertarNodo(raiz, valor);
            break;
        case 2:
            printf("Ingrese el valor a buscar: ");
            scanf("%d", &valor);
            if (buscarNodo(raiz, valor) != NULL)
            {
                printf("Nodo encontrado.\n");
            }
            else
            {
                printf("Nodo no encontrado.\n");
            }
            break;
        case 3:
            printf("Ingrese el valor a eliminar: ");
            scanf("%d", &valor);
            raiz = eliminarNodo(raiz, valor);
            break;
        case 4:
            printf("Recorrido InOrden: ");
            recorridoInOrden(raiz);
            printf("\n");
            break;
        case 5:
            printf("Recorrido PreOrden: ");
            recorridoPreOrden(raiz);
            printf("\n");
            break;
        case 6:
            printf("Recorrido PostOrden: ");
            recorridoPostOrden(raiz);
            printf("\n");
            break;
        case 7:
            printf("Número de nodos: %d\n", contarNodos(raiz));
            break;
        case 8:
            printf("Profundidad del árbol: %d\n", profundidadArbol(raiz));
            break;
        case 9:
            if (estaBalanceado(raiz))
            {
                printf("El árbol está balanceado.\n");
            }
            else
            {
                printf("El árbol no está balanceado.\n");
            }
            break;
        case 10:
            printf("Ingrese el valor del nodo a modificar: ");
            scanf("%d", &valorViejo);
            printf("Ingrese el nuevo valor: ");
            scanf("%d", &valorNuevo);
            modificarNodo(raiz, valorViejo, valorNuevo);
            break;
        case 11:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción no válida.\n");
        }
    } while (op != 11);

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
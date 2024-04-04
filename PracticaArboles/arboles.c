#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo{
    int dato;
    struct nodo *izq;
    struct nodo *der;
} Nodo;

// Funcion para crear un nodo para el arbol
struct nodo *crearNodo(int dato){
    struct nodo *nuevo = (struct nodo *)malloc(sizeof(struct nodo));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

// Funcion para insertar un nodo en un arbol binario con recursividad
void insertar(struct nodo *arbol, int dato){
    if (arbol == NULL){
        arbol = crearNodo(dato);
    }
    else{
        if (dato < arbol->dato){ // Si el dato es menor que el dato del nodo actual se pasa a la izquierda 
            if (arbol->izq == NULL){
                arbol->izq = crearNodo(dato);
            }
            else{
                insertar(arbol->izq, dato);
            }
        }
        else{ // Si el dato es mayor que el dato del nodo actual se pasa a la derecha
            if (arbol->der == NULL){
                arbol->der = crearNodo(dato);
            }
            else{
                insertar(arbol->der, dato);
            }
        }
    }
}

// Funcion para imprimir el arbol en postOrden
void postOrden(struct nodo *arbol){
    if (arbol != NULL){
        postOrden(arbol->izq);
        postOrden(arbol->der);
        printf("%d\n", arbol->dato);
    }
}

// Funcion para imprimir el arbol en preOrden
void preOrden(struct nodo *arbol){
    if (arbol != NULL){
        printf("%d\n", arbol->dato);
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

// Funcion para imprimir el arbol en inOrden
void inOrden(struct nodo *arbol){
    if (arbol != NULL){
        inOrden(arbol->izq);
        printf("%d\n", arbol->dato);
        inOrden(arbol->der);
    }
}

int main(){

    int datos[8]= {8, 3, 1, 20, 5, 10, 7, 4};
    int n=8;
    struct nodo *arbol = crearNodo(datos[0]);

    for(int i=1; i<n; i++){
        insertar(arbol, datos[i]);
    }

    printf("\nArbol en postOrden:\n");
    postOrden(arbol);

    printf("\nArbol en preOrden:\n");
    preOrden(arbol);

    printf("\nArbol en inOrden:\n");
    inOrden(arbol);

    //imprimirArbol(arbol, 0);
    return 0;
}


/*
 Funcion para imprimir el arbol de manera informal
void imprimirArbol(struct nodo *arbol, int nivel){
    if(arbol == NULL){
        return;
    }

    for (int i = 0; i < nivel; i++)
        printf(i == nivel - 1 ? "|-" : "  ");
    printf("%d\n", arbol->dato);

    imprimirArbol(arbol->izq, nivel + 1);
    imprimirArbol(arbol->der, nivel + 1);
}
*/


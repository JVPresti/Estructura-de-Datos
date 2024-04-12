#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

//Conocer la altura de un arbol
int altura(struct nodo *arbol){
    if(arbol == NULL){
        return 0;
    }
    int alturaIzq = altura(arbol->izq);
    int alturaDer = altura(arbol->der);
    return alturaIzq > alturaDer ? alturaIzq + 1 : alturaDer + 1;
}

//Contar el numero de hojas de un arbol
int contarHojas(struct nodo *arbol){
    if(arbol == NULL){
        return 0;
    }
    if(arbol->izq == NULL && arbol->der == NULL){ //Esto significa que es una hoja
        return 1;
    }
    return contarHojas(arbol->izq) + contarHojas(arbol->der); //Suma de las hojas de la izquierda y derecha
}

//Codigo para saber si un arbol esta completo o no
bool esCompleto(struct nodo *arbol){
    if(arbol == NULL){
        return true;
    }
    if(arbol->izq == NULL && arbol->der == NULL){
        return true;
    }
    if(arbol->izq != NULL && arbol->der != NULL){
        return esCompleto(arbol->izq) && esCompleto(arbol->der);
    }
    return false;
}

//Codigo para saber si un arbol esta lleno o no
bool esLleno(struct nodo *arbol){
    if(arbol == NULL){
        return true;
    }
    if(arbol->izq == NULL && arbol->der == NULL){ //Esto significa que es una hoja
        return true;
    }
    if(arbol->izq != NULL && arbol->der != NULL){ //Si tiene dos hijos
        return esLleno(arbol->izq) && esLleno(arbol->der); //Se llama recursivamente a los hijos
    }
    return false; //Retona falso si no tiene dos hijos o sea que no es lleno
}

//Codigo para saber si un arbol esta balanceado o no
bool esBalenceado(struct nodo *arbol){
    if(arbol == NULL)
        return true;
    int alturaIzq = altura(arbol->izq);
    int alturaDer = altura(arbol->der);
    if(abs(alturaIzq - alturaDer) <= 1)
        return esBalenceado(arbol->izq) && esBalenceado(arbol->der);

    return false;
}


int main(){

    int datos[9]= {8, 3, 1, 20, 5, 10, 7, 4, 7};
    int n=9;
    struct nodo *arbol = crearNodo(datos[0]);

    for(int i=1; i<n; i++){
        insertar(arbol, datos[i]);
    }

    /*printf("La altura del arbol es %d\n", altura(arbol));

    printf("El numero de hojas del arbol es %d\n", contarHojas(arbol));

    printf("El arbol es ");
    bool lleno = esLleno(arbol);
    printf(lleno ? "lleno\n" : "no lleno\n");


    //imprimirArbol(arbol, 0);*/
    printf("El arbol es ");
    bool completo = esCompleto(arbol);
    printf(completo ? "completo\n" : "incompleto\n");

    printf("El aeblol es ");
    bool balanceado = esBalenceado(arbol);
    printf(balanceado ? "balanceado\n" : "no balanceado\n");


    return 0;
}

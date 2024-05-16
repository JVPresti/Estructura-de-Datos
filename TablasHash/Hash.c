//Programa para crear tablas hash de 50 elementos con listas enlazadas para las colisiones
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

typedef struct nodo{
    char* clave;
    char* valor;
}Nodo;

typedef struct hash{
    Nodo** item;
    int indice;
    int size;
}Hash;

//Prototipos de funciones
void inicializaTabla(int tabla[SIZE]);
int funcionHash(int tabla[SIZE], char* clave);
void insertar(int tabla[SIZE], char* clave, char* valor);


//Funcion para inicializar la tabla hash con valores nulos  
Nodo* crearNodo(char* clave, char* valor){
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->clave = (char*)malloc(strlen(clave)+1);
    nuevoNodo->valor = (char*)malloc(strlen(valor)+1);
    strcpy(nuevoNodo->clave, clave);
    strcpy(nuevoNodo->valor, valor);

    return nuevoNodo;
}

//Funcion para crear la tabla hash con listas enlazadas para las colisiones 
Hash* crearTabla(int size){
    Hash* tabla= (Hash*)malloc(sizeof(Hash));
    tabla->size = size;
    tabla->indice = 0;
    tabla->item = (Nodo**)calloc(tabla->size, sizeof(Nodo*)); 

    for (int i = 0; i< tabla->size; i++)
        tabla->item[i] = NULL;

    return tabla;  
}

//Funcon para liberar la memoria de un nodo
void freeNodo(Nodo* nodo){
    free(nodo->clave);
    free(nodo->valor);
    free(nodo);
}

//Funcion para liberar la memoria de la tabla hash
void freeTabla(Hash* tabla){
    for (int i = 0; i< tabla->size; i++){
        Nodo* nodo = tabla->item[i];

        if(nodo != NULL)
            freeNodo(nodo);
    }
    free(tabla->item);
    free(tabla);
}

//Funcion para imprimir la tabla hash
void imprimirTabla(Hash* tabla){
    printf("------------Tabla Hash------------\n");
    for (int i = 0; i< tabla->size; i++){
        if(tabla->item[i] != NULL)
            printf("Indice: %d, Clave: %s, Valor: %s\n", i, tabla->item[i]->clave, tabla->item[i]->valor);
    }
    printf("----------------------------------\n");
}

//Funcion para insertar un nodo en la tabla hash
void insertar(Hash* tabla, char* clave, char* valor){
    int indice = funcionHash(tabla->size, clave);
    Nodo* nuevoNodo = crearNodo(clave, valor);

    if(tabla->item[indice] == NULL){
        tabla->item[indice] = nuevoNodo;
    }
}

int main(){
    Nodo* tabla = crearTabla(50);
    insertar(tabla, "1", "Hola");
    imprimirTabla(tabla);

    return 0;
}
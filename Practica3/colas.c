//Debe incluir insertar, eliminar, mostrar, tener limite y crear
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct nodo {
    int dato;
    struct nodo *sig;
} nodo;

typedef struct cola {
    nodo *ini;
    nodo *final;
    int limite;
} cola;


void crearCola();
void insertar(cola *c, int dato);
void eliminar(cola *c);
void mostrar(cola *c);
void limite(cola *c);

int main(){
    int op, dato;
    bool creado = false;
    cola *c;
    c->limite=MAX;
    

    do{
        printf("\t\n MENU\n");
        printf("1.- Crear cola\n");
        printf("2.- Insertar elemento\n");
        printf("3.- Eliminar elemento\n");
        printf("4.- Mostrar cola\n");
        printf("5.- Limite de la cola\n");
        printf("6.- Salir\n");
        op = validar("Seleccione una opcion: ", 1, 6);

        switch(op){
            case 1:
                if(creado == true){
                    printf("La cola ya ha sido creada\n");
                    system("pause");
                    break;
                }
                printf("La cola ha sido creada con exito\n");
                crearCola();
                system("pause");
                creado = true;
                break;
            case 2:
                printf("Insertar elemento\n");
                if(creado == false){
                    printf("Primero debe crear la cola\n");
                    system("pause");
                    break;
                }
                if(c->limite==0){
                    printf("La cola esta llena\n");
                    system("pause");
                    break;
                }
                dato = validar("Ingrese un numero del 1 al 100: ", 1, 100);
                insertar(c, dato);
                printf("\nProceso exitoso\n");
                system("pause");
                break;
            case 3:
                printf("Eliminar elemento\n");
                if(creado == false){
                    printf("Primero debe crear la cola\n");
                    system("pause");
                    break;
                }
                if(c->limite==MAX){
                    printf("La cola esta vacia\n");
                    system("pause");
                    break;
                }
                printf("\nElemento eliminado\n");
                eliminar(c);
                system("pause");
                break;
            case 4:
                printf("Mostrar cola\n");
                if(creado == false){
                    printf("Primero debe crear la cola\n");
                    system("pause");
                    break;
                }
                if(c->limite==MAX){
                    printf("La cola esta vacia\n");
                    system("pause");
                    break;
                }
                printf("\nElementos de la cola\n");
                mostrar(c);
                system("pause");
                break;
            case 5:
                printf("Limite de la cola\n");
                if(creado == false){
                    printf("Primero debe crear la cola\n");
                    system("pause");
                    break;
                }
                limite(c);
                system("pause");
                break;
            case 6:
                printf("\nAdios...");
                break;
        }
    }while(op!=6);

    return 0;
}

// Funcion para crear una cola (reservar espacio)
void crearCola(){
    cola *c = (cola*)malloc(sizeof(cola));
    c->ini = NULL;
    c->final = NULL;
}

// Funcion para insertar un elemento a una cola (push)
void insertar(cola *c, int dato){
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->sig = NULL;
    if(c->ini == NULL){
        c->ini = nuevo;
    }else{
        c->final->sig = nuevo;
    }
    c->final = nuevo;
    c->limite--;
}

// Funcion para eliminar un elemento de una pila (pop)
void eliminar(cola *c){
    nodo *aux;
    if(c->ini == NULL){
        printf("La cola esta vacia\n");
    }else{
        aux = c->ini;
        c->ini = c->ini->sig;
        free(aux);
    }
    c->limite++;
}

// Funcion para mostrar los elementos de una cola
void mostrar(cola *c){
    nodo *aux;
    aux = c->ini;
    while(aux != NULL){
        printf("%d\n", aux->dato);
        aux = aux->sig;
    }
}

// Funcion para validar que la pila no supere un limite de elementos
void limite(cola *c){
    if(c->limite==0){
        printf("La cola esta llena\n");
    }
    else if(c->limite==MAX){
        printf("La cola esta vacia\n");
    }
    else{
        printf("La cola tiene %d espacios\n", c->limite);
    }

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
        op = atoi(cadena);        // Convierte la cadena a un numero
    } while (op < ri || op > rf); // Valida que este dentro de los rangos

    return op;
}
// Jorge Vazquez
// OnlyCodes

#include "base.h"

void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int op;
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->ini = NULL;
    lista->longi = 0;
    Talum *alum;
    // lista->ini = NULL;
    do
    {
        system("cls");
        printf("\t MENU \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Imprimir pila\n");
        printf("4. Estado de la pila\n");
        printf("5. Tamaño de la pila\n");
        printf("6. Vaciar la pila\n");
        printf("7. Salir\n");
        fflush(stdin);
        op = validar("Seleccione una opcion: ", 1, 7);
        switch (op)
        {
        case 1:
            printf("Push\n");
            insertarFinal(lista, alum);
            system("pause");
            break;
        case 2:
            printf("Pop\n");
            eliminarUltimo(lista);
            system("pause");
            break;
        case 3:
            printf("Imprimir Pila\n");
            imprimirLista(lista);
            system("pause");
            break;
        case 4:
            printf("Estado de la pila\n");
            estadoPila(lista);
            system("pause");
            break;
        case 5:
            printf("Tamano de la pila\n");
            sizePila(lista);
            system("pause");
            break;
        case 6:
            printf("Vaciar la pila\n");
            vaciarPila(lista);
            system("pause");
            break;
        case 7:
            printf("Adios....\n");
            break;
        }
    } while (op != 7);
    free(lista);
}

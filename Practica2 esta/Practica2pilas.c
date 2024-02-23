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
    Talum *alum, *busca;
    // lista->ini = NULL;
    do
    {
        system("cls");
        printf("\t MENU \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Imprimir pila\n");
        printf("4. Estado de la pila\n");
        printf("5. Salir\n");
        fflush(stdin);
        op = validar("Seleccione una opcion: ", 1, 5);
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
            printf("Imprimir lista\n");
            imprimirLista(lista);
            system("pause");
            break;
        case 4:
            printf("Estado de la pila\n");
            estadoPila(lista);
            system("pause");
            break;
        case 5:
            printf("Adios...\n");
            break;
        }
    } while (op != 5);
    free(lista);
}

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
        printf("1. Insertar mascota al inicio\n");
        printf("2. Insertar mascota en una posicion\n");
        printf("3. Insertar mascota al final\n");
        printf("4. Eliminar mascota al inicio\n");
        printf("5. Eliminar mascota en una posicion\n");
        printf("6. Eliminar mascota al final\n");
        printf("7. Imprimir lista\n");
        printf("8. Salir\n");
        fflush(stdin);
        op = validar("Seleccione una opcion: ", 1, 8);
        switch (op)
        {
        case 1:
            printf("Insertar mascota al inicio\n");
            alum = (Talum *)malloc(sizeof(Talum)); // Reservar memoria para el alumno
            insertarPrincipio(lista, alum);
            printf("Mascota insertada con exito\n");
            system("pause");
            break;
        case 2:
            int longitud = lista->longi;
            int posi = 0;
            printf("Insertar mascota en una posicion\n");
            posi = validar("Ingrese la posicion: ", 0, longitud);
            insertarMedio(posi, lista, alum);
            printf("Mascota insertada con exito\n");
            system("pause");
            break;
        case 3:
            printf("Insertar mascota al final\n");
            insertarFinal(lista, alum);
            system("pause");
            break;
        case 4:
            printf("Eliminar mascota al inicio\n");
            eliminarInicio(lista);
            system("pause");
            break;
        case 5:
            int ndelete = 0;
            int longit = lista->longi;
            printf("Eliminar mascota en una posicion\n");
            ndelete = validar("Ingrese la posicion a eliminar: ", 0, longit);
            eliminarElementos(ndelete, lista);
            system("pause");
            break;
        case 6:
            printf("Eliminar mascota al final\n");
            eliminarUltimo(lista);
            system("pause");
            break;
        case 7:
            printf("Imprimir lista\n");
            imprimirLista(lista);
            system("pause");
            break;
        case 8:
            printf("Adios...\n");
            break;
        }

    } while (op != 8);
    free(lista);
}

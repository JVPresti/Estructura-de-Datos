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
        printf("\t MENU \n");
        printf("1. Insertar mascota al inicio\n");
        printf("2. Insertar mascota en una posicion\n");
        printf("3. Insertar mascota al final\n");
        printf("4. Eliminar mascota al inicio\n");
        printf("5. Eliminar mascota en una posicion\n");
        printf("6. Eliminar mascota al final\n");
        printf("7. Salir\n");
        op = validar("Seleccione una opcion: ", 1, 7);
        switch (op)
        {
        case 1:
            //! NO ME DEJA AGREGAR 2 VECES AL INICIO, PROBABLEMENTE PORQUE ME FALTA UNA CONDICION
            printf("Insertar mascota al inicio\n");
            alum = (Talum *)malloc(sizeof(Talum)); // Reservar memoria para el alumno
            insertarPrincipio(lista, alum);
            printf("Mascota insertada con exito\n");
            break;
        case 2:
            int longitud = lista->longi;
            int posi = 0;
            printf("Insertar mascota en una posicion\n");
            posi = validar("Ingrese la posicion: ", 1, longitud);
            insertarMedio(posi, lista, alum);
            printf("Mascota insertada con exito\n");
            break;
        case 3:
            printf("Insertar mascota al final\n");
            break;
        case 4:
            printf("Eliminar mascota al inicio\n");
            break;
        case 5:
            printf("Eliminar mascota en una posicion\n");
            break;
        case 6:
            printf("Eliminar mascota al final\n");
            break;
        case 7:
            printf("Salir\n");
            break;
        }

    } while (op != 7);
    free(lista);
}

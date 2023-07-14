#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    FILE *archivo = fopen("videojuegos.txt", "a+");

    if (archivo == NULL) {
        printf("Error, no se puede abrir el archivo.\n");
        return 1;
    }

    int opcion;

    do {
        printf("Menu:\n");
        printf("1. Ver Videojuegos\n");
        printf("2. Ingresar Videojuegos\n");
        printf("3. Modificar Informacion del videojuego\n");
        printf("4. Eliminar Videojuego\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                verproductos(archivo);
                break;
            case 2:
                ingresarPr(archivo);
                break;
            case 3:
                modificarPr(archivo);
                break;
            case 4:
                eliminarPr(archivo);
                break;
            case 0:
                printf("Cerrando Inventario.\n");
                break;
            default:
                printf("Opcion no válida.\n");
                break;
        }
    } while (opcion != 0);

    fclose(archivo);

 return 0;
}
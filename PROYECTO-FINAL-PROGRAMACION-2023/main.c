#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    FILE *archivo = fopen("videojuegos.txt", "a+");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
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
                verProductos(archivo);
                break;
            case 2:
                ingresarProducto(archivo);
                break;
            case 3:
                modificarProducto(archivo);
                break;
            case 4:
                eliminarProducto(archivo);
                break;
            case 0:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida.\n");
                break;
        }
    } while (opcion != 0);

    fclose(archivo);

 return 0;
}
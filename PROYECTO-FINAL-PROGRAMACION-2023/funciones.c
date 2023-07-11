#include <stdio.h>
#include <string.h>
#include "funciones.h"

void verProductos(FILE *archivo) {
    printf("Videojuegos:\n");
    char nombre[50];
    char descripcion[100];
    int cantidad;
    float precio;

    rewind(archivo);

    while (fscanf(archivo, "%s %s %d %f", nombre, descripcion, &cantidad, &precio) == 4) {
        printf("Nombre: %s\n", nombre);
        printf("Descripción: %s\n", descripcion);
        printf("Cantidad: %d\n", cantidad);
        printf("Precio: %.2f\n", precio);
        printf("\n");
    }
}

void ingresarProducto(FILE *archivo) {
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n\n");
        return;
    }

    printf("Ingrese el nombre del videojuego: ");
    char nombre[50];
    scanf("%s", nombre);

    printf("Ingrese la descripcion del videojuego: ");
    char descripcion[100];
    scanf("%s", descripcion);

    printf("Ingrese la cantidad del videojuego: ");
    int cantidad;
    scanf("%d", &cantidad);

    printf("Ingrese el precio del videojuego: ");
    float precio;
    scanf("%f", &precio);

    FILE *archivoVideojuegos = fopen("videojuegos.txt", "a");
    if (archivoVideojuegos == NULL) {
        printf("Error al abrir el archivo de videojuegos.\n\n");
        return;
    }

    fprintf(archivoVideojuegos, "%s %s %d %.2f\n", nombre, descripcion, cantidad, precio);
    fclose(archivoVideojuegos);

    printf("Videojuego ingresado correctamente.\n\n");
}

void modificarProducto(FILE *archivo) {
    printf("Ingrese el nombre del videojuego a modificar: ");
    char nombre[50];
    scanf("%s", nombre);

    char nuevoNombre[50];
    printf("Ingrese el nuevo nombre del videojuego: ");
    scanf("%s", nuevoNombre);

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error al abrir el archivo temporal.\n");
        return;
    }

    char tempNombre[50];
    char descripcion[100];
    int cantidad;
    float precio;
    int encontrado = 0;

    while (fscanf(archivo, "%s %s %d %f", tempNombre, descripcion, &cantidad, &precio) == 4) {
        if (strcmp(tempNombre, nombre) == 0) {
            encontrado = 1;
            strcpy(tempNombre, nuevoNombre); // Actualizar el nombre del videojuego
            printf("Ingrese la nueva descripcion del videojuego: ");
            scanf("%s", descripcion);
            printf("Ingrese la nueva cantidad del videojuego: ");
            scanf("%d", &cantidad);
            printf("Ingrese el nuevo precio del videojuego: ");
            scanf("%f", &precio);
        }

        fprintf(tempFile, "%s %s %d %.2f\n", tempNombre, descripcion, cantidad, precio);
    }

    fclose(archivo);
    fclose(tempFile);

    if (encontrado) {
        remove("videojuegos.txt");
        rename("temp.txt", "videojuegos.txt");
        printf("Videojuego modificado correctamente.\n\n");
    } else {
        remove("temp.txt");
        printf("Videojuego no encontrado.\n\n");
    }

    archivo = fopen("videojuegos.txt", "a+");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
}

void eliminarProducto(FILE *archivo) {
    printf("Ingrese el nombre del videojuego a eliminar: ");
    char nombre[50];
    scanf("%s", nombre);

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error al abrir el archivo temporal.\n");
        return;
    }

    char tempNombre[50];
    char descripcion[100];
    int cantidad;
    float precio;
    int encontrado = 0;

    while (fscanf(archivo, "%s %s %d %f", tempNombre, descripcion, &cantidad, &precio) == 4) {
        if (strcmp(tempNombre, nombre) == 0) {
            encontrado = 1;
            continue;
        }

        fprintf(tempFile, "%s %s %d %.2f\n", tempNombre, descripcion, cantidad, precio);
    }

    fclose(archivo);
    fclose(tempFile);

    if (encontrado) {
        remove("videojuegos.txt");
        rename("temp.txt", "videojuegos.txt");
        printf("Videojuego eliminado correctamente.\n\n");
    } else {
        remove("temp.txt");
        printf("Videojuego no encontrado.\n\n");
    }

    archivo = fopen("videojuegos.txt", "a+");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
       return;
    }
}
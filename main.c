#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_PRODUCTOS 10

int main() {
    char nombres[MAX_PRODUCTOS][50];
    float precios[MAX_PRODUCTOS];
    int nump;

    printf("Ingrese el numero de productos (maximo %d): ", MAX_PRODUCTOS);
    scanf("%d", &nump);

    if (nump > MAX_PRODUCTOS) {
        printf("Numero de productos excede el máximo permitido.\n");
        return 0;
    }

    fflush(stdin);

    ingresarDatos(nombres, precios, nump);

    float total = calcularPrecioTotal(precios, nump);
    printf("El precio total del inventario es: %.2f\n", total);

    int* indices = encontrarExtremos(precios, nump);
    printf("Producto mas caro: %s con un precio de %.2f\n", nombres[indices[0]], precios[indices[0]]);
    printf("Producto mas barato: %s con un precio de %.2f\n", nombres[indices[1]], precios[indices[1]]);


    float promedio = calcularPrecioPromedio(precios, nump);
    printf("El precio promedio es: %.2f\n", promedio);

    char nombreBuscado[50];
    printf("Ingrese el nombre del producto que desea buscar: ");
    fgets(nombreBuscado, 50, stdin);

    float precioBuscado = buscarProductoPorNombre(nombres, precios, nump, nombreBuscado);
    if (precioBuscado != -1) {
        printf("El precio del producto %s es: %.2f\n", nombreBuscado, precioBuscado);
    } else {
        printf("Producto no encontrado.\n");
    }

    return -1;
}

#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_PRODUCTOS 10

int main() {
  char nombres[MAX_PRODUCTOS][50];  
  float precios[MAX_PRODUCTOS];         
  int cantidades[MAX_PRODUCTOS];    
  int nump;              


    while (1) {
        printf("Ingrese el numero de productos (maximo %d): ", MAX_PRODUCTOS);
        scanf("%d", &nump);

        if (nump > MAX_PRODUCTOS) {
            printf("Numero de productos excede el maximo permitido.\n");
            printf("Ingrese 1 para intentarlo de nuevo o 0 para salir del programa: ");
            int opcion;
            scanf("%d", &opcion);

            if (opcion == 0) {
                printf("Saliendo del programa...\n");
                return 0;
            }
        } else {
            break;
        }
    }

    fflush(stdin);
    ingresarDatos(nombres, precios, cantidades, nump);  

    float total = calcularPrecioTotal(precios, cantidades, nump); 
    printf("El precio total del inventario es: %.2f\n", total);

    int indiceMasCaro = encontrarMasCaro(precios, nump);
    int indiceMasBarato = encontrarMasBarato(precios, nump);
    printf("Producto mas caro: %s con un precio de %.2f\n", nombres[indiceMasCaro], precios[indiceMasCaro]);
    printf("Producto mas barato: %s con un precio de %.2f\n", nombres[indiceMasBarato], precios[indiceMasBarato]);

    float promedio = calcularPrecioPromedio(precios, cantidades, nump); 
    printf("El precio promedio es: %.2f\n", promedio);

      int opcion = 1; 

    while (opcion != 0) {
        printf("\n Desea buscar un producto por nombre? Ingrese 1 para buscar o 0 para salir: ");
        scanf("%d", &opcion);
        fflush(stdin);

        if (opcion == 1) {
            char nombreBuscado[50];
            printf("Ingrese el nombre del producto que desea buscar: ");
            fgets(nombreBuscado, 50, stdin);

            float precioBuscado = buscarProductoPorNombre(nombres, precios, nump, nombreBuscado);
            if (precioBuscado != -1) {
                printf("El precio del producto %s es: %.2f\n", nombreBuscado, precioBuscado);
            } else {
                printf("Producto no encontrado.\n");
            }
        } else if (opcion == 0) {
            printf("Saliendo del programa...\n");
        } else {
            printf("Opcion no valida. Intente nuevamente.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
#include "funciones.h"

int ingresarDatos(char nombres[][50], float precios[], int nump) {
    for (int i = 0; i < nump; i++) {
        printf("Ingrese el nombre del producto %d:", i + 1);
        fgets(nombres[i], 50, stdin); 

        printf("Ingrese el precio del producto %d: ", i + 1);
    
        while (scanf("%f", &precios[i]) != 1) { 
            printf("Error: debe ingresar un numero valido para el precio. Intente nuevamente.\n");
            fflush(stdin);
            printf("Ingrese el precio del producto %d: ", i + 1);
        }
        
        fflush(stdin);        
    }
    return nump;
}

float calcularPrecioTotal(float precios[], int nump) {
    float total = 0.0;
    for (int i = 0; i < nump; i++) {
        total += precios[i];
    }
    return total;
}

int encontrarMasCaro(float precios[], int nump) {
    int indiceMasCaro = 0;  

    for (int i = 1; i < nump; i++) {
        if (precios[i] > precios[indiceMasCaro]) {
            indiceMasCaro = i; 
        }
    }

    return indiceMasCaro; 
}

int encontrarMasBarato(float precios[], int nump) {
    int indiceMasBarato = 0; 

    for (int i = 1; i < nump; i++) {
        if (precios[i] < precios[indiceMasBarato]) {
            indiceMasBarato = i;  
        }
    }

    return indiceMasBarato; 
}

float calcularPrecioPromedio(float precios[], int nump) {
    return calcularPrecioTotal(precios, nump) / nump;
}

float buscarProductoPorNombre(char nombres[][50], float precios[], int nump, char nombreBuscado[]) {
    for (int i = 0; i < nump; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            return precios[i];
        }
    }
    return -1;  
}

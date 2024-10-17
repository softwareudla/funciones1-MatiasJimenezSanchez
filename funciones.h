#define FUNCIONES_H

int ingresarDatos(char nombres[][50], float precios[], int nump);
float calcularPrecioTotal(float precios[], int nump);
int* encontrarExtremos(float precios[], int nump);
float calcularPrecioPromedio(float precios[], int nump);
float buscarProductoPorNombre(char nombres[][50], float precios[], int nump, char nombreBuscado[]);



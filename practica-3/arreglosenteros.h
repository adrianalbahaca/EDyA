#ifndef __ARREGLOS_ENTEROS_H__
#define __ARREGLOS_ENTEROS_H__

typedef struct _ArregloEnteros {
    int *direccion;
    int capacidad;
} ArregloEnteros;

// Funciones a crear
ArregloEnteros* arreglo_enteros_crear(int capacidad);

void arreglo_enteros_destruir(ArregloEnteros *arreglo);

int arreglo_enteros_leer(ArregloEnteros *arreglo, int pos);

void arreglo_enteros_escribir(ArregloEnteros *arreglo, int pos);

int arreglo_enteros_capacidad(ArregloEnteros *arreglo);

void arreglo_enteros_imprimir(ArregloEnteros *arreglo);

#endif
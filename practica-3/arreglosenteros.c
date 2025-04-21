#include <stdlib.h>
#include "arreglosenteros.h"

ArregloEnteros* arreglo_enteros_crear(int capacidad){
    ArregloEnteros *temp = malloc(sizeof(ArregloEnteros));
    int arreglo[capacidad];
    temp->direccion = arreglo;
    temp->capacidad = capacidad;
    return temp;
}

void arreglo_enteros_destruir(ArregloEnteros *arreglo) {
    free(arreglo);
}

int arreglo_enteros_leer(ArregloEnteros *arreglo, int pos) {
    return arreglo->direccion[pos];
}

void arreglo_enteros_escribir(ArregloEnteros *arreglo, int pos, int dato) {
    if ((pos + 1) > arreglo->capacidad) {
        return;
    }
    else {
        arreglo->direccion[pos] = dato;
        return;
    }
}

int arreglo_enteros_capacidad(ArregloEnteros *arreglo) {
    return arreglo->capacidad;
}

void arreglo_enteros_imprimir(ArregloEnteros *arreglo) {
    for(int i = 0; i < arreglo->capacidad; i++) {
        printf(arreglo->direccion[i]);
    }
}

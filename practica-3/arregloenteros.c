#include "arregloenteros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Crear un arreglo de enteros con una cierta capacidad
ArregloEnteros* arreglo_enteros_crear(int capacidad) {
    ArregloEnteros *nodo = malloc(sizeof(ArregloEnteros));

    int *arreglo = calloc(capacidad, sizeof(int));
    
    nodo->direccion = arreglo;
    nodo->capacidad = capacidad;
    return nodo; 
}

// Destruir un arreglo de enteros
void arreglo_enteros_destruir(ArregloEnteros *arreglo) {
    free(arreglo);
    return;
}

int arreglo_enteros_leer(ArregloEnteros *arreglo, int pos) {
    if (pos < 0 || pos > (arreglo->capacidad - 1)) {
        return 0;
    }
    else {
        return (arreglo->direccion[pos]);
    }
}

void arreglo_enteros_escribir(ArregloEnteros *arreglo, int pos, int dato) {
    if(arreglo == NULL || pos < 0) {
        return;
    }
    else if(pos >= arreglo->capacidad) {
        arreglo_enteros_ajustar(arreglo, (pos + 1));
        arreglo->direccion[pos] = dato;
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
    for(int i = 0; i < (arreglo->capacidad); i++) {
        printf("/ %d /", (arreglo->direccion[i]));
    }
    puts("");
    return;
}

void arreglo_enteros_ajustar(ArregloEnteros *arreglo, int capacidad) {
    // Crear nuevo arreglo de enteros
    int *nuevoArreglo = realloc((arreglo->direccion), capacidad * sizeof(int));

    arreglo->direccion = nuevoArreglo;
    arreglo->capacidad = capacidad;

    return;

}
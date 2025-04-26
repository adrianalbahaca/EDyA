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
    free(arreglo->direccion);
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

void arreglo_enteros_insertar(ArregloEnteros *arreglo, int pos, int dato) {
    // Ajustar el tamaño del arreglo con la función hecha
    arreglo->direccion = realloc(arreglo->direccion, (arreglo->capacidad + 1) * sizeof(int));

    // Mover los elementos a la derecha
    for(int i = (arreglo->capacidad); i > pos; i--) {
        arreglo->direccion[i] = arreglo->direccion[i + 1];
    }

    // Agregar elemento en la posición deseada
    arreglo->direccion[pos] = dato;
    arreglo->capacidad = (arreglo->capacidad + 1);
}

void arreglo_enteros_eliminar(ArregloEnteros *arreglo, int pos) {
    // Mover los elementos a la izquierda
    for(int i = pos; i < (arreglo->capacidad); i++) {
        arreglo->direccion[i] = arreglo->direccion[i + 1];
    }

    // Cambiar capacidad del arreglo
    arreglo->capacidad = (arreglo->capacidad) - 1;
    arreglo->direccion = realloc(arreglo->direccion, (arreglo->capacidad) * sizeof(int));
}
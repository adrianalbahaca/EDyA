#include "pila.h"
#include "arregloenteros.h"
#include <stdlib.h>

// Crear una pila nueva
Pila* pila_crear(int capacidad) {
    // Crear arreglo de enteros
    ArregloEnteros *arreglo = arreglo_enteros_crear(capacidad);

    // Asignar espacio para la pila
    Pila *pila = malloc(sizeof(Pila));

    pila->arr = arreglo;
    pila->ultimo = 0;
    return pila;
}

// Destruir una pila
void pila_destruir(Pila *pila) {
    // Liberar el arreglo de enteros
    arreglo_enteros_destruir(pila->arr);

    // Liberar pila en sí
    free(pila);
    return;
}

// Verificar que una pila esté vacía
int pila_es_vacia(Pila *pila) {
    return pila == NULL;
}

// Retornar el primer elemento de la pila, sin eliminarlo
int pila_tope(Pila *pila) {
    return pila->arr->direccion[0];
}

// Insertar un elemento en el tope de la lista
void pila_apilar(Pila *pila, int dato) {
    // Si no hay suficiente espacio, ajusta el arreglo para que tenga el doble del espacio
    if(pila->ultimo = (pila->arr->capacidad - 1)) {
        arreglo_enteros_ajustar(pila->arr, (pila->arr->capacidad * 2));
    }

    // Mover elementos a la derecha
    for(int i = pila->ultimo; i > 0; i--) {
        pila->arr->direccion[i] = pila->arr->direccion[i - 1];
    }

    // Colocar elemento en la pila
    pila->arr->direccion[0] = dato;
    
    return;
}


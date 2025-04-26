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
    pila->ultimo = -1;
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
    // Si la pila está vacía
    if((pila->ultimo == -1)) {
        pila->ultimo = 0;
        pila->arr->direccion[0] = dato;
        return;
    }
    else { // Sino
        
        // Si la pila estará llena, duplicarle el tamaño
        if(((pila->ultimo + 1) == pila->arr->capacidad)) {
            arreglo_enteros_ajustar(pila->arr, (pila->arr->capacidad * 2));
        }

        // Mover los elementos a la derecha
        for(int i = pila->ultimo; i >= 0; i--) {
            pila->arr->direccion[i + 1] = pila->arr->direccion[i];
        }
        // Anotar el dato en la pila
        pila->arr->direccion[0] = dato;
        pila->ultimo++;
        return;
    }
}

// Desapilar un elemento de la lista
void pila_desapilar(Pila *pila) {
    // Para desapilarlo, será nada más eliminar el primer elemento del arreglo
    arreglo_enteros_eliminar(pila->arr, 0);
    return;
}

// Imprimir los elementos de la lista
void pila_imprimir(Pila *pila) {
    // Se usa la función de imprimir el arreglo para ver todos los elementos
    arreglo_enteros_imprimir(pila->arr);
}
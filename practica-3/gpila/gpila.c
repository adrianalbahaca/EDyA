#include "gpila.h"
#include "glist.h"
#include "contacto.h"
#include <stdlib.h>

// Crear una pila
Pila pila_crear() {
    // Retornar un puntero vacío
    return NULL;
}

// Destruir una pila
void pila_destruir(Pila pila, FuncionDestructora destruir) {
    // Como la pila es una lista, se toma la función de destruir, y se destruye como una lista
    glist_destruir(pila, (FuncionDestructora)destruir);
    return;
}

// Determinar si una pila es vacía
int pila_es_vacía(Pila pila) {
    return (pila == NULL);
}

// Leer el archivo en el tope de la lista
void pila_tope(Pila pila, FuncionVisitante visitar) {
    visitar(pila->data);
    return;
}

// Apilar un elemento en la pila
Pila pila_apilar(Pila pila, void *dato, FuncionCopia copiar) {
    pila = glist_agregar_inicio(pila, dato, (FuncionCopia) copiar);
    return pila;
}

// Desapilar un elemento de la pila
Pila pila_desapilar(Pila pila, FuncionDestructora destruir) {
    Pila temp = pila;
    pila = pila->next;
    temp->next = NULL;
    glist_destruir(temp, (FuncionDestructora)destruir);
    return pila;
}

// Imprimir los elementos de una pila
void pila_imprimir(Pila pila, FuncionVisitante imprimir) {
    glist_recorrer(pila, (FuncionVisitante)imprimir);
    return;
}
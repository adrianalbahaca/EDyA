#include "sglist.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Retornar una lista vacía
SGList sglist_crear() {
    return NULL;
}

// Destruir una lista
void sglist_destruir(SGList lista, FuncionDestructora destruir) {
    SGNodo *nodoAEliminar;
    while(lista != NULL) {
        nodoAEliminar = lista;
        lista = lista->sig;
        destruir(nodoAEliminar->dato);
        free(nodoAEliminar);
    }
}

// Determinar si una lista es vacía
int sglist_vacia(SGList lista) {
    return lista == NULL;
}

// Recorrer la lista con una función visitante
void sglist_recorrer(SGList lista, FuncionVisitante f) {
    for(SGList temp = lista; temp != NULL; temp = temp->sig) {
        f(temp->dato);
    }
}

// TODO: Insertar un elemento a la lista, manteniendo el orden
SGList sglist_insertar(SGList lista, void *data, FuncionCopia copiar, FuncionComparadora comparar) {
    // Crear nodo nuevo
    SGList nodo = malloc(sizeof(SGNodo));
    assert(nodo != NULL);

    // Agregar datos al nodo
    nodo->dato = copiar(data);

    if (lista == NULL) { // Si la lista está vacía, sólo retornar el nodo
        lista = nodo;
        nodo->sig = NULL;
        return lista;
    }
    else if(comparar(lista, nodo) < 0) { // Sino, se ve si va en el principio de la lista
        nodo->sig = lista;
        return nodo;
    }
    else { // Sino, se recorre hasta colocar en el medio o al final
        SGList temp = lista->sig;
        SGList ant = lista;
        while(temp != NULL) {
            if(comparar(temp, nodo) < 0) {
                ant->sig = nodo;
                nodo->sig = temp;
                return lista;
            }

            temp = temp->sig;
            ant = ant->sig;
        }

        // Si se llegó al final, añadir y ya está
        ant->sig = nodo;
        nodo->sig = temp;
        return lista;
    }
}

// TODO: Buscar y conseguir un elemento a la lista
int sglist_buscar(SGList lista, void *data, FuncionComparadora comparar) {
    // Usar un loop para conseguir el nodo que se busca
    for(SGNodo *temp = lista; temp != NULL; temp = temp->sig) {
        if(comparar(temp, data)) {
            return 1;
        }
    }
    return 0;
}

// TODO: Construir una lista ordenada a partir de un arreglo
SGList sglist_arr(void **arreglo, FuncionComparadora comparar, FuncionCopia copiar) {
    
}
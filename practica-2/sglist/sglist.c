#include "sglist.h"
#include <assert.h>
#include <stdlib.h>

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
    for(SGNodo *temp = lista; temp != NULL; temp = temp->sig) {
        f(temp->dato);
    }
}

// TODO: Insertar un elemento a la lista, manteniendo el orden
SGList sglist_insertar(SGList lista, FuncionCopia copiar, FuncionComparadora comparar, void *data) {
    SGNodo *temp = malloc(sizeof(SGNodo));
    assert(temp);
    temp->dato = copiar(data);

    // Si la lista es vacía, retornar nada más el puntero
    if (lista == NULL) {
        return temp;
    }

    // Si la comparación es True para el primer elemento de la lista, añadir al inicio
    if(comparar(lista->sig, temp)) {
        temp->sig = lista;
        return temp;
    }

    // Sino, añadir en el medio
    for(SGNodo *l = lista; l != NULL; l = l->sig) {
        if(comparar(l->sig, temp)) {
            temp->sig = l->sig;
            l->sig = temp;
            return lista;
        }
    }

    // Sino, añadir al final
    SGNodo *final = lista;
    for(;final->sig != NULL; final = final->sig);
    final->sig = temp;
    temp->sig = NULL;
    return lista;

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
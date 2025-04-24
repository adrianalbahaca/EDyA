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
    SGList temp = malloc(sizeof(SGNodo));
    assert(temp != NULL);
    temp->dato = copiar(data);

    // TODO: Agregar datos a la función nueva sin causar seg faults o perder orden con la función comparadora
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
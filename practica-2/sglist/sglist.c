#include "sglist.h"
#include <stdlib.h>

// Retornar una lista vacía
SGList sglist_crear() {
    return NULL;
}

// Destruir una lista
SGList sglist_destruir(SGList lista, FuncionDestructora destruir) {
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

// TODO: Insertar un elemento a la lista, manteniendo en el hombre
SGList sglist_insertar(SGList lista, FuncionCopia copiar, FuncionComparadora comparar) {
    
}

// TODO: Buscar y conseguir un elemento a la lista
int sglist_buscar(SGList lista, FuncionComparadora comparar) {

}

// TODO: Construir una lista ordenada a partir de un arreglo
SGList sglist_arr(void **arreglo, FuncionComparadora comparar, FuncionCopia copiar) {
    
}
#include <stdlib.h>
#include "cdlist.h"

CDList cdlist_crear() {
    return NULL;
}

void cdlist_destruir(CDList lista) {
    // Si la lista está vacía, sólo liberar los lista
    if (lista->sig == lista) {
        free(lista);
    }
    else { // Sino, borrar cada nodo hasta llegar a uno solo
        lista->ant->sig = NULL;
        lista->ant = NULL;
        for(CDList temp = lista; lista != NULL; temp = lista) {
            lista = lista->sig;
            free(temp);
        }
        free(lista);
    }
    return;
}

CDList cdlist_agregar_inicio(CDList lista, int dato) {
    CDNodo* temp = malloc(sizeof(CDNodo));
    if(temp == NULL) {
        return lista;
    }

    temp->dato = dato;

    if(lista == NULL) {
        // Nodo se conecta en sí
        temp->sig = temp;
        temp->ant = temp;
        return temp;
    }
    else {
        // Conectar nodos de los extremos de las listas
        temp->sig = lista;
        temp->ant = lista->ant;

        lista->ant->sig = temp;
        lista->ant = temp;
    }
    lista = temp;
    return lista;
}


// Ahora, la parte importante: Recorrer esta lista
void cdlist_recorrer(CDList lista, funcionVisitante f, CDListOrdenDeRecorrido r) {
    if(r == CDLIST_RECORRIDO_HACIA_ADELANTE) {
        f(lista->dato);
        for(CDList temp = lista->sig; temp != lista; temp = temp->sig) {
            f(temp->dato);
        }
    }
    else if (r == CDLIST_RECORRIDO_HACIA_ATRAS){
        f(lista->ant->dato);
        for(CDList temp = lista->ant->ant; temp != lista->ant; temp = temp->ant) {
            f(temp->dato);
        }
    }
    return;
}
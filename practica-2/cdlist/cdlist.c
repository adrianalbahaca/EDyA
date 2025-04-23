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

CDList cdlist_agregar_final(CDList lista, int dato) {
    CDNodo *temp = malloc(sizeof(CDNodo));
    if(temp == NULL) {
        return lista;
    }
    
    temp->dato = dato;
    if(lista == NULL) {
        temp->sig = temp;
        temp->ant = temp;
        lista = temp;
    }
    else {
        lista->ant->sig = temp;
        temp->ant = lista->ant;
        lista->ant = temp;
        temp->sig = lista;
    }
    return lista;
}

// Ahora, la parte importante: Recorrer esta lista
void cdlist_recorrer(CDList lista, funcionVisitante f, CDListOrdenDeRecorrido r) {
    if(r == CDLIST_RECORRIDO_HACIA_ADELANTE) {
        CDList temp = lista;
        do {
            f(temp->dato);
        } while(temp != lista);
    }
    else if (r == CDLIST_RECORRIDO_HACIA_ATRAS){
        CDList temp = lista->ant;
        do {
            f(temp->dato);
        } while(temp != lista->ant);
    }
    return;
}
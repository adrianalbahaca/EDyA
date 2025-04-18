#include <stdlib.h>
#include "dlist.h"

DList* dlist_crear_puntos() {
    // Reservar espacio en memoria para los puntos y retornar
    DList *puntos = malloc(sizeof(DList));
    return puntos;
}

DNodo* dlist_crear(DList **puntos) {
    // Apuntar a NULL y retornar lo mismo
    DNodo *temp = NULL;
    (*puntos)->primero = temp;
    (*puntos)->ultimo = temp;
    return temp;
}

void dlist_destruir(DNodo *lista, DList *puntos) {
    // Mientras la lista tenga contenido, ir liberandolas una a una
    DNodo *eliminar;
    while(lista != NULL) {
        eliminar = lista;
        lista = lista->sig;
        free(eliminar);
    }

    free(puntos);
    return;
}

int dlist_vacia(DNodo *lista) {
    return lista == NULL;
}

DList* dlist_agregar_inicio (DList *puntos, int dato) {
    // Crear nodo y agregarle dato
    DNodo* temp = malloc(sizeof(DNodo));
    if(temp == NULL) {
        return puntos;
    }

    // Ajustar el temp
    temp->dato = dato;
    temp->sig = puntos->primero;
    temp->ant = NULL;
    if(puntos->primero != NULL) {
        puntos->primero->ant = temp;
    }
    if(puntos->ultimo == NULL) {
        puntos->ultimo = temp;
    }
    puntos->primero = temp;
    return puntos;
}

DList* dlist_agregar_final (DList *puntos, int dato) {
    // Crear un nuevo nodo
    DNodo *temp = malloc(sizeof(DNodo));
    if(temp == NULL) {
        return puntos;
    }

    // Ajustar el nodo acorde
    temp->dato = dato;
    temp->sig = NULL;
    temp->ant = puntos->ultimo;
    if(puntos->ultimo != NULL) {
        puntos->ultimo->sig = temp;
    }
    if(puntos->primero == NULL) {
        puntos->primero = temp;
    }
    puntos->ultimo = temp;
    return puntos;
}

void dlist_recorrer(DList *puntos, funcionVisitante f, DListOrdenDeRecorrido r) {
    if (r == DLIST_RECORRIDO_HACIA_ADELANTE) {
        for(DNodo *temp = puntos->primero; temp != NULL; temp = temp->sig) {
            f(temp->dato);
        }
    }
    else if (r == DLIST_RECORRIDO_HACIA_ATRAS) {
        for(DNodo *temp = puntos->ultimo; temp != NULL; temp = temp->ant) {
            f(temp->dato);
        }
    }
}
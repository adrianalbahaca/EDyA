#include <stdlib.h>
#include "cdlist.h"

CDList* cdlist_crear_puntos() {
    CDList *temp = malloc(sizeof(CDList));
    temp->primero = NULL;
    temp->ultimo = NULL;
    return temp;
}

CDNodo* cdlist_crear(CDList **puntos) {
    CDNodo *temp = NULL;
    (*puntos)->primero = temp;
    (*puntos)->ultimo = temp;
    return temp;
}

void cdlist_destruir(CDNodo *lista, CDList *puntos) {
    CDNodo *nodoAEliminar;
    CDList *puntosAEliminar = puntos;
}

CDList* cdlist_agregar_inicio(CDList* puntos, int dato) {
    CDNodo* nuevoNodo = malloc(sizeof(CDNodo));
    nuevoNodo->dato = dato;
    if(puntos->primero == NULL && puntos->ultimo == NULL) {
        nuevoNodo->ant = nuevoNodo;
        nuevoNodo->sig = nuevoNodo;
        puntos->primero = nuevoNodo;
        puntos->ultimo = nuevoNodo;
        return puntos;
    }
    else {
        nuevoNodo->sig = puntos->primero;
        puntos->primero->ant = nuevoNodo;
        puntos->ultimo->sig = nuevoNodo;
        nuevoNodo->ant = puntos->ultimo;
        puntos->primero = nuevoNodo;
        return puntos;
    }
}

CDList* cdlist_agregar_final(CDList *puntos, int dato) {
    CDNodo *nuevoNodo = malloc(sizeof(CDNodo));
    nuevoNodo->dato = dato;
    if(puntos->primero == NULL && puntos->ultimo == NULL) {
        nuevoNodo->sig = nuevoNodo;
        nuevoNodo->ant = nuevoNodo;
        puntos->primero = nuevoNodo;
        puntos->ultimo = nuevoNodo;
        return puntos;
    }
    else {
        nuevoNodo->ant = puntos->ultimo;
        puntos->ultimo->sig = nuevoNodo;
        puntos->primero->ant = nuevoNodo;
        nuevoNodo->sig = puntos->primero;
        puntos->ultimo = nuevoNodo;
        return puntos;
    }
}
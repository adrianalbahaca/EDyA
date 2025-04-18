#include "slist-punto.h"
#include <stdio.h>
#include <stdlib.h>

SNodo* slist_crear(SList **puntos) {
    SNodo *temp = NULL;
    (*puntos)->primero = temp;
    (*puntos)->ultimo = temp;
    return temp;
}

void slist_agregar_inicio(SNodo **lista, SList **puntos, int dato) {
    SNodo *temp = malloc(sizeof(SNodo));
    temp->dato = dato;
    if((*puntos)->ultimo == NULL && (*puntos)->primero == NULL) {
        temp->sig = *lista;
        (*puntos)->ultimo = temp;
        (*puntos)->primero = temp;
        *lista = temp;
        return;
    }
    else {
        temp->sig = (*puntos)->primero;
        (*puntos)->primero = temp;
        *lista = temp;
        return;
    }
}

void slist_agregar_final(SNodo **lista, SList **puntos, int dato) {
    SNodo *temp = malloc(sizeof(SNodo));
    temp->dato = dato;
    if((*puntos)->primero == NULL && (*puntos)->ultimo == NULL) {
        temp->sig = *lista;
        (*puntos)->primero = temp;
        (*puntos)->ultimo = temp;
        *lista = temp;
        return;
    }
    else {
        temp->sig = NULL;
        (*puntos)->ultimo->sig = temp;
        (*puntos)->ultimo = temp;
        return;
    }
}

void slist_recorrer(SNodo *lista, FuncionVisitante visit) {
    for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
      visit(nodo->dato);
}

void slist_destruir(SNodo *lista) {
    SNodo *nodoAEliminar;
    while (lista != NULL) {
      nodoAEliminar = lista;
      lista = lista->sig;
      free(nodoAEliminar);
    }
    return;
}
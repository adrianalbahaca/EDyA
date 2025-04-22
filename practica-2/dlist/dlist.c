#include <stdlib.h>
#include "dlist.h"

DList* dlist_crear() {
    // Reservar espacio en memoria para los puntos y retornar
    DList *puntos = malloc(sizeof(DList));
    puntos->primero = NULL;
    puntos->ultimo = puntos->primero;
    return puntos;
}

void dlist_destruir(DList *puntos) {
    // Si la lista está vacía, sólo eliminar puntos
    if (puntos->primero == NULL && puntos->ultimo == NULL) {
        free(puntos);
    }
    else { // Sino, ir nodo por nodo, separarlo de la lista y eliminarlo
        puntos->ultimo = puntos->ultimo->sig;
        for(DNodo *temp = puntos->primero; puntos->primero != NULL; temp = puntos->primero) {
            puntos->primero = puntos->primero->sig;
            free(temp);
        }
        free(puntos);
    }
    return;
}

int dlist_vacia(DList *puntos) {
    return (puntos->primero == NULL && puntos->ultimo == NULL);
}

DList* dlist_agregar_inicio (DList *puntos, int dato) {
    // Crear nodo y agregarle dato
    DNodo* temp = malloc(sizeof(DNodo));
    if(temp == NULL) {
        return puntos;
    }

    // Colocar dato en el coso
    temp->dato = dato;
    
    // Si la lista está vacía, entonces
    if(puntos->primero == NULL && puntos->ultimo == NULL) {
        temp->sig = NULL;
        temp->ant = NULL;
        puntos->primero = temp;
        puntos->ultimo = temp;
    }
    else { // Sino, ajustar acorde
        puntos->primero->ant = temp;
        temp->sig = puntos->primero;
        temp->ant = NULL;
        puntos->primero = temp;
    }
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
    
    // Si la lista está vacía, agregar el nodo
    if (puntos->primero == NULL && puntos->ultimo == NULL) {
        temp->sig = NULL;
        temp->ant = NULL;
        puntos->primero = temp;
        puntos->ultimo = temp;
    }
    else { // Sino, ajustar punteros acorde
        puntos->ultimo->sig = temp;
        temp->ant = puntos->ultimo;
        temp->sig = NULL;
        puntos->ultimo = temp;
    }
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
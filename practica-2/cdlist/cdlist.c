#include <stdlib.h>
#include "cdlist.h"

CDList* cdlist_crear() {
    CDList *temp = malloc(sizeof(CDList));
    temp->primero = NULL;
    temp->ultimo = temp->primero;
    return temp;
}

void cdlist_destruir(CDList *puntos) {
    // Si la lista está vacía, sólo liberar los puntos
    if (puntos->primero == NULL && puntos->ultimo == NULL) {
        free(puntos);
    }
    else { // Sino, borrar cada nodo hasta llegar a uno solo
        for(CDNodo *temp = puntos->primero; puntos->primero != NULL & puntos->ultimo != NULL; temp = puntos->primero) {
            if(temp->sig = temp) {
                puntos->primero = NULL;
                puntos->ultimo = NULL;
                free(temp);
            }
            else {
                puntos->primero = temp->sig;
                puntos->ultimo->sig = puntos->primero;
                temp->sig = NULL;
                puntos->primero->ant = puntos->ultimo;
                temp->ant = NULL;
                free(temp);
            }
        }
        free(puntos);
    }
    return;
}

CDList* cdlist_agregar_inicio(CDList* puntos, int dato) {
    CDNodo* temp = malloc(sizeof(CDNodo));
    if(temp == NULL) {
        return puntos;
    }

    temp->dato = dato;

    if(puntos->primero == NULL && puntos->ultimo == NULL) {
        // Nodo se conecta en sí
        temp->sig = temp;
        temp->ant = temp;

        // Puntos apunta a ese nodo
        puntos->primero = temp;
        puntos->ultimo = temp;
    }
    else {
        // Conectar nodos de los extremos de las listas
        puntos->primero->ant = NULL;
        puntos->ultimo->sig = NULL;

        // Conectar nodo nuevo a la lista
        temp->sig = puntos->primero;
        puntos->primero->ant = temp;
        puntos->primero = temp;

        // Reconectar ciclo
        puntos->primero->ant = puntos->ultimo;
        puntos->ultimo->sig = puntos->primero;

    }
    return puntos;
}

CDList* cdlist_agregar_final(CDList *puntos, int dato) {
    CDNodo *temp = malloc(sizeof(CDNodo));
    if(temp == NULL) {
        return puntos;
    }
    
    temp->dato = dato;
    if(puntos->primero == NULL && puntos->ultimo == NULL) {
        // Apuntar ambos punteros del nodo a sí mismo
        temp->sig = temp;
        temp->ant = temp;

        // Apuntar puntos al nodo
        puntos->primero = temp;
        puntos->ultimo = temp;
    }
    else {
        // Apuntar los punteros siguientes
        puntos->ultimo->sig = temp;
        puntos->primero->ant = temp;

        // Apuntar los punteros del nodo nuevo
        temp->ant = puntos->ultimo;
        temp->sig = puntos->primero;

        puntos->ultimo = temp;
    }

    return puntos;
}

// Ahora, la parte importante: Recorrer esta lista
void cdlist_recorrer(CDList *puntos, funcionVisitante f, CDListOrdenDeRecorrido r) {
    if(r == CDLIST_RECORRIDO_HACIA_ADELANTE) {
        CDNodo *temp = puntos->primero;

        do {
            f(temp->dato);
            temp = temp->sig;
        } while (temp != puntos->primero);
    }
    else if (r == CDLIST_RECORRIDO_HACIA_ATRAS){
        CDNodo *temp = puntos->ultimo;

        do {
            f(temp->dato);
            temp = temp->sig;
        } while(temp != puntos->ultimo);
    }
    return;
}
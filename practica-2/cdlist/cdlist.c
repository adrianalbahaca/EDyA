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
        // Conectar nodos diguientes
        puntos->ultimo->sig = temp;
        temp->sig = puntos->primero;

        // Conectar nodos anteriores
        puntos->primero->ant = temp;
        temp->ant = puntos->ultimo;

        // Cambiar extremos
        puntos->primero = temp;
    }
    return puntos;
}

CDList* cdlist_agregar_final(CDList *puntos, int dato) {
    CDNodo *nuevoNodo = malloc(sizeof(CDNodo));
    nuevoNodo->dato = dato;
    if(puntos->primero == NULL && puntos->ultimo == NULL) {
        // Apuntar ambos punteros del nodo a sí mismo
        nuevoNodo->sig = nuevoNodo;
        nuevoNodo->ant = nuevoNodo;

        // Apuntar puntos al nodo
        puntos->primero = nuevoNodo;
        puntos->ultimo = nuevoNodo;
    }
    else {

    }

    return puntos;
}
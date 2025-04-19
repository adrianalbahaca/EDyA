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
    
}
#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

static void imprimir_entero(int dato) {
    printf("%d->", dato);
}

int main(void) {
    DList *puntos = dlist_crear();

    puntos = dlist_agregar_inicio(puntos, 5);
    puntos = dlist_agregar_inicio(puntos, 4);
    puntos = dlist_agregar_inicio(puntos, 7);
    dlist_recorrer(puntos, imprimir_entero, DLIST_RECORRIDO_HACIA_ADELANTE);
    puts("NULL");

    dlist_destruir(puntos);
    return 0;
}
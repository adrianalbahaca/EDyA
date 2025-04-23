#include <stdio.h>
#include "cdlist.h"

void imprimir_entero(int dato) {
    printf("%d<->", dato);
    return;
}

int main(void) {
    CDList *puntos = cdlist_crear();

    puntos = cdlist_agregar_inicio(puntos, 5);
    puntos = cdlist_agregar_inicio(puntos, 6);

    cdlist_recorrer(puntos, imprimir_entero, CDLIST_RECORRIDO_HACIA_ADELANTE);
    puts("NULL");
    cdlist_recorrer(puntos, imprimir_entero, CDLIST_RECORRIDO_HACIA_ATRAS);
    puts("NULL");

    cdlist_destruir(puntos);
    return 0;
}
#include <stdio.h>
#include "cdlist.h"

void imprimir_entero(int dato) {
    printf("%d<->", dato);
    return;
}

int main(void) {
    CDList lista = cdlist_crear();
    lista = cdlist_agregar_inicio(lista, 7);
    lista = cdlist_agregar_inicio(lista, 5);

    cdlist_recorrer(lista, imprimir_entero, CDLIST_RECORRIDO_HACIA_ADELANTE);
    puts("");
    cdlist_recorrer(lista, imprimir_entero, CDLIST_RECORRIDO_HACIA_ATRAS);
    puts("");

    cdlist_destruir(lista);
    return 0;
}
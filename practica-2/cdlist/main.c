#include <stdio.h>
#include "cdlist.h"

void imprimir_entero(int dato) {
    printf("%d<->", dato);
    return;
}

int main(void) {
    CDList lista = cdlist_crear();
    lista = cdlist_agregar_final(lista, 5);
    lista = cdlist_agregar_inicio(lista, 7);
    lista = cdlist_agregar_final(lista, 8);

    cdlist_recorrer(lista, imprimir_entero, CDLIST_RECORRIDO_HACIA_ADELANTE);
    cdlist_recorrer(lista, imprimir_entero, CDLIST_RECORRIDO_HACIA_ATRAS);
    
    cdlist_destruir(lista);
    return 0;
}
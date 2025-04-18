#include <stdio.h>
#include <stdlib.h>
#include "slist-punto.h"

static void imprimir_entero(int dato) {
    printf("%d->", dato);
}

int main(void) {
    // Crear listas y puntos
    SList *puntos = malloc(sizeof(SList));
    SNodo *lista = slist_crear(&puntos);
    slist_recorrer(lista, imprimir_entero);
    puts("NULL");

    // Agregar al principio
    slist_agregar_inicio(&lista, &puntos, 6);
    slist_agregar_inicio(&lista, &puntos, 7);
    slist_recorrer(lista, imprimir_entero);
    puts("NULL");
    printf("Datos en puntos: %d %d\n", puntos->primero->dato, puntos->ultimo->dato);

    // Agregar al final
    slist_agregar_final(&lista, &puntos, 8);
    slist_agregar_final(&lista, &puntos, 9);
    slist_recorrer(lista, imprimir_entero);
    puts("NULL");
    printf("Datos en puntos: %d %d\n", puntos->primero->dato, puntos->ultimo->dato);

    slist_destruir(lista);
    free(puntos);
    return 0;
}
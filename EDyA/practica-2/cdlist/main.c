#include <stdio.h>
#include "cdlist.h"

int main(void) {
    CDList *puntos = cdlist_crear_puntos();
    CDNodo *lista = cdlist_crear(&puntos);

    puntos = cdlist_agregar_inicio(puntos, 5);
    puntos = cdlist_agregar_inicio(puntos, 7);
    return 0;
}
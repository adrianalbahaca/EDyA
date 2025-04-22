#include <stdio.h>
#include "cdlist.h"

int main(void) {
    CDList *puntos = cdlist_crear();

    puntos = cdlist_agregar_inicio(puntos, 5);

    cdlist_destruir(puntos);
    return 0;
}
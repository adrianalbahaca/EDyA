#include <stdio.h>
#include "arregloenteros.h"

int main(void) {
    ArregloEnteros *arreglo = arreglo_enteros_crear(9);

    arreglo_enteros_escribir(&arreglo, 0, 3);
    arreglo_enteros_escribir(&arreglo, 8, 4);

    arreglo_enteros_imprimir(arreglo);

    arreglo_enteros_destruir(arreglo);
    return 0;
}
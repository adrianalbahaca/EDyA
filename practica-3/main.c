#include <stdio.h>
#include "arregloenteros.h"

int main(void) {
    ArregloEnteros *arreglo = arreglo_enteros_crear(7);
    arreglo_enteros_imprimir(arreglo);
    
    arreglo_enteros_insertar(arreglo, 2, 9);
    arreglo_enteros_imprimir(arreglo);

    arreglo_enteros_eliminar(arreglo, 5);
    arreglo_enteros_imprimir(arreglo);

    arreglo_enteros_destruir(arreglo);

    return 0;
}
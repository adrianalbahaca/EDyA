#include <stdio.h>
#include "pila.h"
#include "arregloenteros.h"

int main(void) {
    Pila *pila = pila_crear(3);

    pila_apilar(pila, 5);
    pila_apilar(pila, 0);
    pila_apilar(pila, 9);
    pila_apilar(pila, 10);
    pila_imprimir(pila);

    pila_desapilar(pila);
    pila_imprimir(pila);

    pila_destruir(pila);

    return 0;
}
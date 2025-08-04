#include <stdio.h>
#include "funciones-1.h"

/**
 * Final 24-7-2024. Lista con cant. de menores
 * Uso de estructuras: AVL
 * Algoritmos: En librería
 */

int main(void) {
    /**
     * Para probar estos elementos, se va a crear dos arrays distintos
     */
    int arr1[10] = {60, 30, 100, 56, 1, 45, 7, 10, 20, 413};
    
    for (int i = 0; i < 10; i++) {
        insertar_elem();
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenamiento.h"

int main(void) {
    // Inicialización de números aleatorios
    int n = 1000000;
    srand(time(NULL));
    int *arreglo = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        arreglo[i] = rand() % (n + 1);
    }

    // Ordenamiento de elementos
    quick_sort_lomuto(arreglo, 0, n);
    
    for(int i = 0; i < n; i++) {
        printf("%d->", arreglo[i]);
    }
    puts("");
    return 0;
}
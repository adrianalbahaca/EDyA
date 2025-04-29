#include "garray.h"
#include <stdlib.h>

GArray list_to_array(GList lista, FuncionCopia copiar) {
    // TODO: Hacer una función que copia los elementos de una lista hasta pegarlos
    // Crear un contador que cuenta cuantos elementos hay en la lista
    int longitud = 0;
    for(GList temp = lista; temp != NULL; temp = temp->next) {
        longitud++;
    }

    // Alocar un array con el espacio necesario
    GArray arreglo = malloc(sizeof(void*) * (longitud));

    // Copiar cada elemento de la lista al arreglo
    GList temp = lista;
    for(int i = 0; i < longitud; i++) {
        arreglo[i] = copiar(temp->data);
        temp = temp->next;
    }

    return arreglo;
}
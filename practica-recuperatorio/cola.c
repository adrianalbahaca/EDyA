#include <stdlib.h>
#include <stdio.h>
#include "cola.h"

Cola cola_crear(FuncionCopia copy, FuncionDestructora destroy, int capacidad) {
    // Crear cola en sí
    Cola cola = malloc(sizeof(Cola));

    // Inicializar arreglo
    cola->datos = (void**)malloc(capacidad * sizeof(void*));

    // Inicializar variables y guardar funciones
    cola->capacidad = capacidad;
    cola->eliminar = cola->agregar = cola->tamano = 0;
    cola->copy = copy;
    cola->destroy = destroy;

    return cola;
}

int cola_vacia (Cola cola) {
    return (cola->tamano == 0);
}

int cola_llena(Cola cola) {
    return (cola->tamano == cola->capacidad);
}

Cola cola_encolar(Cola cola, void *dato) {
    // Si la cola está llena, no hacer nada
    if(cola_llena(cola)) {
        printf("La cola está llena. No se puede añadir el elemento\n");
    } else { // Sino, agregar elemento a la cola
        cola->datos[cola->agregar] = cola->copy(dato);
        cola->agregar = (cola->agregar + 1) % cola->capacidad;
        cola->tamano++;
    }

    return cola;
}

Cola cola_desencolar(Cola cola) {
    if(cola_vacia(cola)) {
        printf("La cola está vacía. No hay nada a desencolar\n");
        return cola;
    } else {
        cola->eliminar = (cola->eliminar + 1) % cola->capacidad;
        cola->tamano--;
        return cola;
    }
}

void cola_destruir(Cola cola) {
    free(cola->datos);
    free(cola);
}
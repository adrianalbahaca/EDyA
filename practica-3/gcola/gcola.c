#include "gcola.h"
#include "glist.h"
#include <stdlib.h>

// Crear una cola vacía
GCola* cola_crear() {
    GCola *cola = malloc(sizeof(GCola));
    cola->primero = NULL;
    cola->ultimo = NULL;
    return cola;
}

void cola_destruir(GCola *cola, FuncionDestructora destruir) {
    cola->ultimo = NULL;
    glist_destruir(cola->primero, (FuncionDestructora)destruir);
    free(cola);
    return;
}

// Determinar si una cola es vacía
int cola_es_vacia(GCola *cola) {
    return (cola->primero == NULL && cola->ultimo == NULL);
}

// Mostrar el inicio de una cola, sin eliminarlo
void cola_inicio(GCola *cola, FuncionVisitante visitar) {
    visitar(cola->primero->data);
    return;
}

// Encolar un elemento en la cola
GCola* cola_encolar(GCola *cola, void* dato, FuncionCopia copiar) {
    if(cola_es_vacia(cola)) {
        cola->primero = glist_agregar_inicio(cola->primero, dato, (FuncionCopia)copiar);
        cola->ultimo = cola->primero;
    }
    else {
        cola->primero = glist_agregar_inicio(cola->primero, dato, (FuncionCopia)copiar);
    }
    return cola;
}

// Desencolar un elemento de la cola
GCola* cola_desencolar(GCola *cola, FuncionDestructora destruir) {
    if(cola_es_vacia(cola)) { // Si la cola está vacía
        return cola;
    }
    else if(cola->primero == cola->ultimo) { // Si la cola solo tiene un elemento
        GList temp = cola->primero;
        cola->primero = NULL;
        cola->ultimo = NULL;
        glist_destruir(temp, (FuncionDestructora)destruir);
    }
    else { // Si tiene más de un elemento
        GList penultimo = cola->primero;
        for(;penultimo->next != cola->ultimo; penultimo = penultimo->next);
        penultimo->next = NULL;
        glist_destruir(cola->ultimo, (FuncionDestructora)destruir);
        cola->ultimo = penultimo;
    }
    return cola;
}

// Imprimir una cola
void cola_imprimir(GCola *cola, FuncionVisitante visitar) {
    glist_recorrer(cola->primero, (FuncionVisitante)visitar);
}
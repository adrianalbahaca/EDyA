#ifndef __G_COLA_H__
#define __G_COLA_H__
#include "glist.h"

// Definición de estructuras
typedef struct _GCola {
    GList primero;
    GList ultimo;
} GCola;

/**
 * Crear una cola
 */
GCola* cola_crear();

/**
 * Destruir una cola
 */
void cola_destruir(GCola *cola, FuncionDestructora destruir);

/**
 * Determinar si una cola es vacía
 */
int cola_es_vacia(GCola *cola);

/**
 * Mostrar el inicio de la cola, sin eliminar el elemento
 */
void cola_inicio(GCola *cola, FuncionVisitante visitar);

/**
 * Enqueue un elemento
 */
GCola* cola_encolar(GCola *cola, void *dato, FuncionCopia copiar);

/**
 * Dequeue un elemento
 */
GCola* cola_desencolar(GCola *cola, FuncionDestructora destruir);

/**
 * Imprimir los elementos de una cola
 */
void cola_imprimir(GCola *cola, FuncionVisitante visitar);

#endif /* __G_COLA_H__*/
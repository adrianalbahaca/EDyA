#ifndef __G_PILA_H__
#define __G_PILA_H__
#include "glist.h"

// Definición de estructura
typedef GList Pila;

/**
 * Crear una pila con una cierta capacidad
 */
Pila pila_crear();

/**
 * Destruir una pila con una cierta capacidad
 */
void pila_destruir(Pila pila, FuncionDestructora destruir);

/**
 * Determinar si una pila está vacía
 */
int pila_es_vacía(Pila pila);

/**
 * Determinar el tope de una pila
 */
void pila_tope(Pila pila, FuncionVisitante visitar);

/**
 * Apilar un elemento en la pila
 */
Pila pila_apilar(Pila pila, void *dato, FuncionCopia copiar);

/**
 * Desapilar un elemento de la pila
 */
Pila pila_desapilar(Pila pila, FuncionDestructora destruir);

/**
 * Imprimir los elementos de la lista
 */
void pila_imprimir(Pila pila, FuncionVisitante imprimir);

#endif /* __G_PILA_H__ */
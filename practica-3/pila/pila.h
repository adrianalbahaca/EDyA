#ifndef __PILA_H__
#define __PILA_H__
#include "arregloenteros.h"

// Estructura de dato a usar
typedef struct _Pila{
    ArregloEnteros *arr;
    int ultimo;
} Pila;

/**
 * Crear una pila con cierta capacidad
 */
Pila* pila_crear(int capacidad);

/**
 * Destruir una pila
 */
void pila_destruir (Pila *pila);

/**
 * Determinar si una pila es vacía
 */
int pila_es_vacia(Pila *pila);

/**
 * Retorna el elemento del tope de la pila, sin eliminarlo
 */
int pila_tope(Pila *pila);

/**
 * Insertar un elemento en la pila. Si no hay espacio, aumentar la capacidad del arreglo al doble
 */
void pila_apilar(Pila *pila, int dato);

/**
 * Desapilar el elemento en el tope de la pila
 */
void pila_desapilar(Pila *pila);

/**
 * Mostrar cada elemento de la lista
 */
void pila_imprimir(Pila *pila);

#endif /* __PILA_H__ */
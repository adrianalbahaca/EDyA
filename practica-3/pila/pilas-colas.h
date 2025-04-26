#ifndef __PILAS_COLAS_H__
#define __PILAS_COLAS_H__
#include "arreglosenteros.h"

// Estructura de datos
struct _Pila {
    ArregloEnteros *arr;
    int ultimo;
};
typedef struct _Pila *Pila;


#endif
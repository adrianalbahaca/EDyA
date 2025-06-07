#ifndef __COLA_PRIORIDAD__
#define __COLA_PRIORIDAD__

#include "BinaryHeap.h"

typedef struct {
    int prioridad;
    void *dato;
} Cola_Elemento;

typedef  BHeap colaPrioridad;

colaPrioridad cola_prioridad_crear(FuncionCopiadora copy, FuncionDestructora destroy);

void cola_prioridad_destruir(colaPrioridad cola);

void cola_prioridad_recorrer(colaPrioridad cola, FuncionVisitante visit);

int cola_prioridad_es_vacia(colaPrioridad cola);

void* cola_prioridad_maximo(colaPrioridad cola);

void cola_prioridad_eliminar_maximo(colaPrioridad cola);

void cola_prioridad_insertar(void* dato, int prioridad);

#endif
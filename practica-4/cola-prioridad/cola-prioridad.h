#ifndef __COLA_PRIORIDAD__
#define __COLA_PRIORIDAD__

#define RIGHT(i) (2 * (i + 1))
#define LEFT(i) ((2 * i) + 1)
#define PARENT(i) ((i-1)/2)

#define QUEUE_SIZE 1024

typedef int (*FuncionComparadora) (void* dato1, void* dato2);
typedef void* (*FuncionCopiadora) (void* dato);
typedef void (*FuncionDestructora) (void* dato);
typedef void (*FuncionVisitante) (void* dato);

typedef struct {
    int prioridad;
    void *dato;
} Cola_Elemento;

typedef struct _BHeap {
    Cola_Elemento *arr;
    int capacidad;
    int ultimo;
    FuncionCopiadora copy;
    FuncionDestructora destroy;
} *BHeap;

typedef  BHeap colaPrioridad;

colaPrioridad cola_prioridad_crear(FuncionCopiadora copy_elemento, FuncionDestructora destroy_elemento);

void cola_prioridad_recorrer(colaPrioridad cola, FuncionVisitante visit);

void cola_prioridad_destruir(colaPrioridad cola);

int cola_prioridad_es_vacia(colaPrioridad cola);

void* cola_prioridad_maximo(colaPrioridad cola);

void cola_prioridad_eliminar_maximo(colaPrioridad cola);

void cola_prioridad_insertar(void* dato, int prioridad);

#endif
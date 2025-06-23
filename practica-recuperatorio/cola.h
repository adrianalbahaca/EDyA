#ifndef __COLA_GENERAL__
#define __COLA_GENERAL__

typedef void (*FuncionDestructora)(void *dato);
typedef void *(*FuncionCopia)(void *dato);

typedef struct _Cola {
    void **datos;
    int capacidad;
    int agregar;
    int eliminar;
    int tamano;
    FuncionCopia copy;
    FuncionDestructora destroy;
} Cola;

typedef Cola* Cola;

Cola cola_crear(FuncionCopia copy, FuncionDestructora destroy, int capacidad);

int cola_vacia(Cola cola);

int cola_llena(Cola cola);

Cola cola_encolar(Cola cola, void *dato);

Cola cola_desencolar(Cola cola);

void cola_destruir(Cola cola);

#endif /* __COLA_GENERAL__ */
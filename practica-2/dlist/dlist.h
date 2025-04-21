#ifndef __DLIST_H__
#define __DLIST_H__

// Definir estructuras
typedef struct _DNodo {
    int dato;
    struct _DNodo *sig;
    struct _DNodo *ant;
} DNodo;

typedef struct {
    DNodo *primero;
    DNodo *ultimo;
} DList;

typedef enum {
    DLIST_RECORRIDO_HACIA_ADELANTE,
    DLIST_RECORRIDO_HACIA_ATRAS
} DListOrdenDeRecorrido;

typedef void (*funcionVisitante) (int dato);

// Definir funciones básicas

// Crear punteros a extremos de la lista vacío
DList* dlist_crear_puntos();

// Crear lista vacía
DNodo* dlist_crear(DList **puntos);

// Destruir lista y puntos
void dlist_destruir(DNodo *lista, DList *puntos);

// Chequear si la lista está vacía
int dlist_vacia(DNodo* lista);

// Agregar un elemento al principio
DList* dlist_agregar_inicio(DList *puntos, int dato);

// Agregar elemento al final
DList* dlist_agregar_final(DList *puntos, int dato);

void dlist_recorrer(DList *puntos, funcionVisitante f, DListOrdenDeRecorrido direccion);

#endif
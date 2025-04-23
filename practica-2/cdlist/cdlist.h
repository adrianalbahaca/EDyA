#ifndef __CDLIST_H__
#define __CDLIST_H__

// Definición de elementos
typedef struct _DNodo {
    int dato;
    struct _DNodo *sig;
    struct _DNodo *ant;
} CDNodo;

typedef CDNodo* CDList;

typedef enum {
    CDLIST_RECORRIDO_HACIA_ADELANTE,
    CDLIST_RECORRIDO_HACIA_ATRAS
} CDListOrdenDeRecorrido;

typedef void (*funcionVisitante) (int dato);

// Definición de funciones
// Creación
CDList cdlist_crear();

// Destrucción
void cdlist_destruir(CDList lista);

// Agregar
CDList cdlist_agregar_inicio(CDList lista, int dato);
CDList cdlist_agregar_final(CDList lista, int dato);

// Recorrer
 void cdlist_recorrer(CDList lista, funcionVisitante f, CDListOrdenDeRecorrido r);

#endif
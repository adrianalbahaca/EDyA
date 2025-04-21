#ifndef __CDLIST_H__
#define __CDLIST_H__

// Definición de elementos
typedef struct _DNodo {
    int dato;
    struct _DNodo *sig;
    struct _DNodo *ant;
} CDNodo;

typedef struct {
    CDNodo *primero;
    CDNodo *ultimo;
} CDList;

typedef enum {
    CDLIST_RECORRIDO_HACIA_DELANTE,
    CDLIST_RECORRIDO_HACIA_ATRAS
} CDListOrdenDeRecorrido;

typedef void (*funcionVisitante) (int dato);

// Definición de funciones
// Creación
CDList* cdlist_crear_puntos();
CDNodo* cdlist_crear(CDList **p);

// Destrucción
void cdlist_destruir(CDNodo *lista, CDList *puntos);

// Agregar
CDList* cdlist_agregar_inicio(CDList *puntos, int dato);
CDList* cdlist_agregar_final(CDList *puntos, int dato);

// Recorrer
void cdlist_recorrer(CDList *puntos, funcionVisitante f, CDListOrdenDeRecorrido r);

#endif
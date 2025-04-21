#ifndef __SLISTP_H__
#define __SLISTP_H__

#include <stddef.h>

// Definición de estructuras
typedef struct _SNodo {
    int dato;
    struct _SNodo *sig;
} SNodo;

typedef struct SList {
    SNodo *primero;
    SNodo *ultimo;
} SList;

typedef void (*FuncionVisitante) (int dato);

// Definición de funciones
SNodo* slist_crear(SList **puntos);
void slist_agregar_inicio(SNodo **lista, SList **puntos, int dato);
void slist_agregar_final(SNodo **lista, SList **puntos, int dato);
void slist_recorrer(SNodo *lista, FuncionVisitante visit);
void slist_destruir(SNodo *lista);

#endif /*__SLISTP_H__*/
#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>
#include <stdbool.h>

typedef void (*FuncionVisitante) (int dato);
typedef int (*FuncionComp) (int dato1, int dato2);

typedef struct _SNodo {
  int dato;
  struct _SNodo *sig;
} SNodo;

typedef SNodo *SList;

/**
 * Devuelve una lista vacía.
 */
SList slist_crear();

/**
 * Destruccion de la lista.
 */
void slist_destruir(SList lista);

/**
 * Determina si la lista es vacía.
 */
int slist_vacia(SList lista);

/**
 * Agrega un elemento al final de la lista.
 */
SList slist_agregar_final(SList lista, int dato);

/**
 * Agrega un elemento al inicio de la lista.
 */
SList slist_agregar_inicio(SList lista, int dato);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void slist_recorrer(SList lista, FuncionVisitante visit);

// Longitud de una lista
int slist_longitud(SList lista);

// Concatenar dos listas
SList slist_concatenar(SList lista1, SList lista2);

// Verifica si contiene un dato
int slist_contiene(SList lista, int dato);

// Devuelve el índice en el cual está un dato. Si no está, devuelve -1
int slist_indice(SList lista, int dato);

// Inserta un elemento en una posición arbitraria
SList slist_insertar(SList lista, int indice, int dato);

// Elimina un elemento de una posición arbitraria
void slist_eliminar(SList *lista, int dato);

// Devuelve una lista nueva con elementos iguales, ind. de su posición, de dos listas
SList slist_interseca(SList lista1, SList lista2);

// Devuelve una lista nueva con elementos comunes, usando una función, ind. de su posición
SList slist_interseca_custom(SList lista1, SList lista2, FuncionComp cond);

// Ordena una lista de acuerdo al criterio de una función (Regresa lo que retorna strcmp())
SList slist_ordenar(SList lista, FuncionComp comp);

// Voltea una lista
SList slist_reverso(SList lista);

// Intercala los elementos de una lista dentro de otra
SList slist_intercalar(SList lista1, SList lista2);

// Parte una lista a la mitad (n/2 si es par, (n/2)+1 si es impar) y retorna la seg. mitad si no es vacía
SList slist_partir (SList lista);

#endif /* __SLIST_H__ */

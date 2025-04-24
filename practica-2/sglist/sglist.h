#ifndef __SGLIST_H__
#define __SGLIST_H__

// Definición de funciones a usar
typedef void (*FuncionDestructora)(void *dato);
typedef void *(*FuncionCopia)(void *dato);
typedef void (*FuncionVisitante)(void *dato);
typedef int (*FuncionComparadora) (void *dato);

// Definición de estructura
typedef struct _SGNodo {
    void *dato;
    struct _SGNodo *sig;
} SGNodo;

typedef SGNodo* SGList;

/**
 * Crear una lista general ordenada vacía
 */
SGList sglist_crear();

/**
 * Destruir la lista
 */
void sglist_destruir(SGList lista, FuncionDestructora destruir);

/**
 * Devolver si la lista está vacía
 */
int sglist_vacia(SGList lista);

/**
 * Recorrer por la lista con una función visitante
 */
void sglist_recorrer(SGList lista, FuncionVisitante f);

/**
 * Insertar un nodo, manteniendo el orden de la lista
 */
SGList sglist_insertar(SGList lista, FuncionCopia copiar, FuncionComparadora comparar);

/**
 * Buscar un elemento de una lista
 */
int sglist_buscar(SGList lista, FuncionComparadora comparar);

/**
 * Construir una lista ordenada a partir de un arreglo de elementos
 */
SGList sglist_arr(void ** arreglo, FuncionComparadora comparar, FuncionCopia copiar);

#endif
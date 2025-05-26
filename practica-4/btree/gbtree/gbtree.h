#ifndef __G_BTREE_H__
#define __G_BTREE_H__

typedef struct _GBTNodo {
    void *data;
    struct _GBTNodo *left;
    struct _GBTNodo *right;
} GBTNodo;

typedef GBTNodo *GBTree;

typedef enum {
  BTREE_RECORRIDO_IN,
  BTREE_RECORRIDO_PRE,
  BTREE_RECORRIDO_POST
} BTreeOrdenDeRecorrido;

typedef void (*FuncionVisitante)(void *dato);
typedef void *(*FuncionCopia)(void *dato);
typedef void (*FuncionDestructora)(void *dato);
typedef int (*Predicado)(void *dato);
typedef int (*FuncionComparadora)(void *dato1, void *dato2);

/**
 * Devolver un árbol vacío
 */
GBTree gbtree_crear();

/**
 * Destrucción del árbol
 */
void gbtree_destruir(GBTree arbol, FuncionDestructora destruir);

/**
 * Indicar si el árbol es vacío
 */
int gbtree_empty(GBTree arbol);

/**
 * Unir dos árboles
 */
GBTree gbtree_unir(void *dato, GBTree left, GBTree right, FuncionCopia copiar);

/**
 * Recorrer árbol (Algoritmo DFS)
 */
void gbtree_recorrer(GBTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit);

#endif /* __G_BTREE__ */
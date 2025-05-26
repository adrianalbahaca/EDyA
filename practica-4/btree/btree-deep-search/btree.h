#ifndef __BTREE_H__
#define __BTREE_H__

typedef void (*FuncionVisitante)(int dato);
typedef void (*FuncionVisitanteExtra)(int dato, void *extra);

typedef enum {
  BTREE_RECORRIDO_IN,
  BTREE_RECORRIDO_PRE,
  BTREE_RECORRIDO_POST
} BTreeOrdenDeRecorrido;

typedef struct _BTNodo *BTree;

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear();

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo);

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo);

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right);

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit);

/**
 * Cantidad de nodos en el arbol
 */
int btree_nnodos(BTree arbol);

/**
 * Buscar un elemento y retornar 1 si lo encuentra. Si no está, retornar 0
 */
int btree_buscar(BTree arbol, int dato);

/**
 * Copiar un arbol
 */
BTree btree_copiar(BTree arbol);

/**
 * Altura de un arbol
 */
int btree_altura(BTree arbol);

/**
 * Cantidad de nodos en una cierta profundidad
 */
int btree_nnodos_profundidad(BTree arbol, int prof);

/**
 * Profundidad de un dato. Si no está, retornar -1
 */
int btree_profundidad(BTree arbol, int dato);

/**
 * Sumar todos los elementos
 */
int btree_sumar(BTree arbol);

/**
 * Recorrer nodos de un arbol y aplicar una función
 */
void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitanteExtra visit, void *dato);

#endif /* __BTREE_H__ */

#include "btree.h"
#include <assert.h>
#include <stdlib.h>

struct _BTNodo {
  int dato;
  struct _BTNodo *left;
  struct _BTNodo *right;
};

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear() { return NULL; }

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo) {
  if (nodo != NULL) {
    btree_destruir(nodo->left);
    btree_destruir(nodo->right);
    free(nodo);
  }
}

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo) { return nodo == NULL; }

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right) {
  BTree nuevoNodo = malloc(sizeof(struct _BTNodo));
  assert(nuevoNodo != NULL);
  nuevoNodo->dato = dato;
  nuevoNodo->left = left;
  nuevoNodo->right = right;
  return nuevoNodo;
}

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit) {
  if(btree_empty(arbol)) {
    return;
  }
  switch(orden) {
    case BTREE_RECORRIDO_PRE:
      visit(arbol->dato);
      btree_recorrer(arbol->left, orden, (FuncionVisitante)visit);
      btree_recorrer(arbol->right, orden, (FuncionVisitante)visit);
      break;
    case BTREE_RECORRIDO_POST:
      btree_recorrer(arbol->left, orden, (FuncionVisitante)visit);
      btree_recorrer(arbol->right, orden, (FuncionVisitante)visit);
      visit(arbol->dato);
      break;
    case BTREE_RECORRIDO_IN:
      btree_recorrer(arbol->left, orden, (FuncionVisitante)visit);
      visit(arbol->dato);
      btree_recorrer(arbol->right, orden, (FuncionVisitante)visit);
      break;
    default:
  }
  return;
}
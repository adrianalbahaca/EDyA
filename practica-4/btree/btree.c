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

int btree_nnodos(BTree arbol) {
  // Retornar la cantidad de nodos en el arbol
  // Caso base: Punto nulo del arbol
  if(btree_empty(arbol)) {
    return 0;
  }

  // Paso inductivo: Contar elemento del árbol
  else {
    int i = 0;
    i += btree_nnodos(arbol->left);
    i += btree_nnodos(arbol->right);
    return i;
  }
}

int btree_buscar(BTree arbol, int dato) {
  // Caso base 1: Se consigue el dato
  if(arbol->dato == dato) {
    return 1;
  }

  // Caso base 2: Se llega a una hoja
  else if(btree_empty(arbol)) {
    return 0;
  }

  // Buscar a la izquierda
  if(btree_buscar(arbol->left, dato)) {
    return 1;
  }

  // Buscar a la derecha
  if(btree_buscar(arbol->right, dato)) {
    return 1;
  }
}

BTree btree_copiar(BTree arbol) {
  // Caso base: Nodo hoja
  if(arbol->left == NULL && arbol->right == NULL) {
    return btree_unir(arbol->dato, btree_crear(), btree_crear());
  }

  // Paso inductivo: Unir subarbol izquierdo y derecho
  else {
    BTree l = btree_copiar(arbol->left);
    BTree r = btree_copiar(arbol->right);
    return btree_unir(arbol->dato, l, r);
  }
}

int btree_altura(BTree arbol) {
  
}

int btree_nnodos_profundidad(BTree arbol, int prof) {
  // Retorna la cant. de nodos en una cierta profundidad
}

int btree_profundidad(BTree arbol, int dato) {
  // Retorna la profundidad de donde está el dato. Si no está, retorna -1
}

int btree_sumar(BTree arbol) {
  // Suma todos los elementos de un arbol
}
#include "btree.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

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

/**
 * Cantidad de nodos en un árbol
 */
int btree_nnodos(BTree arbol) {
  // Retornar la cantidad de nodos en el arbol
  // Caso base: Punto nulo del arbol
  if(arbol == NULL) {
    return 0;
  }

  // Paso inductivo: Contar elemento del árbol
  else {
    return (1 + (btree_nnodos(arbol->left)) + (btree_nnodos(arbol->right)));
  }
}

/**
 * Buscar elemento int en un arbol binario
 */
int btree_buscar(BTree arbol, int dato) {
  // Caso base 1: El arbol es vacio
  if (btree_empty(arbol)) {
    return 0;
  }
  // Caso base 2: Se consigue el dato
  if(arbol->dato == dato) {
    return 1;
  }
  // Paso inductivo: Buscar en los subárboles
  else {
    return btree_buscar(arbol->left, dato) || btree_buscar(arbol->right, dato);
  }
}

/**
 * Copiar un arbol en otro nuevo
 */
BTree btree_copiar(BTree arbol) {
  // Caso base: Árbol vacío
  if (btree_empty(arbol)) {
    return NULL;
  }
  // Paso inductivo: Unir árboles
  else {
    BTree left = btree_copiar(arbol->left);
    BTree right = btree_copiar(arbol->right);
    return (btree_unir(arbol->dato, left, right));
  }
  
}

/**
 * Altura de un árbol
 */
int btree_altura(BTree arbol) {
  // Caso base: árbol vacío
  if(btree_empty(arbol)) {
    return 0;
  }

  // Paso inductivo: Recorrer las ramas y retornar el que sea mayor
  int left = btree_altura(arbol->left);
  int right = btree_altura(arbol->right);
  if (left > right) {
    return (left + 1);
  }
  else {
    return (right + 1);
  }
}

/**
 * Profundidad de un nodo
 */
int btree_nnodos_profundidad(BTree arbol, int prof) {
  // Retorna la cant. de nodos en una cierta profundidad
  // Caso base: Profundidad 0
  if(prof == 0) {
    return 1;
  }
  // Caso base 2: Árbol vacío
  else if (btree_empty(arbol)) {
    return 0;
  }
  // Caso recursivo: Calcular cant. de nodos
  else {
    int nodos_left = btree_nnodos_profundidad(arbol->left, (prof - 1));
    int nodos_right = btree_nnodos_profundidad(arbol->right, (prof - 1));
    return (nodos_left + nodos_right);
  }
}

/**
 * Profundidad de un árbol
 */
int btree_profundidad(BTree arbol, int dato) {
  // Retorna la profundidad de donde está el dato. Si no está, retorna -1
  // Caso base: Se encuentra el dato
  if (arbol->dato == dato) {
    return 0;
  }
  // Caso base 2: Árbol vacío
  if(btree_empty(arbol)) {
    return -1;
  }
  // Paso inductivo: Calcular la profundidad en los subarboles
  else {
    return (btree_profundidad(arbol->left, dato) + btree_profundidad(arbol->right, dato) + 1);
  }
}

/**
 * Sumar todos los elementos de un arbol
 */
int btree_sumar(BTree arbol) {
  // Suma todos los elementos de un arbol
  // Caso base: Árbol vacío
  if (btree_empty(arbol)) {
    return 0;
  }
  else {
    int left = btree_sumar(arbol->left);
    int right = btree_sumar(arbol->right);
    return (arbol->dato + left + right);
  }
}

// Toda esta mierda es recursiva lol
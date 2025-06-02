#include "bstree.h"
#include <assert.h>
#include <stdlib.h>

/**
 * Estructura del nodo del arbol de busqueda binaria.
 * Tiene un puntero al dato (dato),
 * un puntero al nodo raiz del subarbol izquierdo (izq),
 * y un puntero al nodo raiz del subarbol derecho (der).
 */
struct _BST_Nodo {
  void *dato;
  struct _BST_Nodo *izq, *der;
};

/**
 * bstee_crear: Retorna un arbol de busqueda binaria vacio
 */
BSTree bstee_crear() { return NULL; }

/**
 * bstree_destruir: Destruye el arbol y sus datos
 */
void bstree_destruir(BSTree raiz, FuncionDestructora destr) {
  if (raiz != NULL) {
    bstree_destruir(raiz->izq, destr);
    bstree_destruir(raiz->der, destr);
    destr(raiz->dato);
    free(raiz);
  }
};

/**
 * bstree_buscar: Retorna 1 si el dato se encuentra y 0 en caso
 * contrario
 */
int bstree_buscar(BSTree raiz, void *dato, FuncionComparadora comp) {
  if (raiz == NULL)
    return 0;
  else if (comp(dato, raiz->dato) == 0) // raiz->dato == dato
    return 1;
  else if (comp(dato, raiz->dato) < 0) // dato < raiz->dato
    return bstree_buscar(raiz->izq, dato, comp);
  else // raiz->dato < dato
    return bstree_buscar(raiz->der, dato, comp);
}

/**
 * bstree_insertar: Inserta un dato no repetido en el arbol, manteniendo la
 * propiedad del arbol de busqueda binaria
 */
BSTree bstree_insertar(BSTree raiz, void *dato, FuncionCopiadora copia,
                       FuncionComparadora comp) {
  if (raiz == NULL) { // insertar el dato en un nuevo nodo
    struct _BST_Nodo *nuevoNodo = malloc(sizeof(struct _BST_Nodo));
    assert(nuevoNodo != NULL);
    nuevoNodo->dato = copia(dato);
    nuevoNodo->izq = nuevoNodo->der = NULL;
    return nuevoNodo;
  } else if (comp(dato, raiz->dato) < 0) // dato < raiz->dato
    raiz->izq = bstree_insertar(raiz->izq, dato, copia, comp);
  else if (comp(dato, raiz->dato) > 0) // raiz->dato < dato
    raiz->der = bstree_insertar(raiz->der, dato, copia, comp);
  // si el dato ya se encontraba, no es insertado
  return raiz;
}

/**
 * bstree_recorrer: Recorrido DSF del arbol
 */
void bstree_recorrer(BSTree raiz, BSTreeRecorrido orden,
                     FuncionVisitanteExtra visita, void *extra) {
  if (raiz != NULL) {
    if (orden == BTREE_RECORRIDO_PRE)
      visita(raiz->dato, extra);
    bstree_recorrer(raiz->izq, orden, visita, extra);
    if (orden == BTREE_RECORRIDO_IN)
      visita(raiz->dato, extra);
    bstree_recorrer(raiz->der, orden, visita, extra);
    if (orden == BTREE_RECORRIDO_POST)
      visita(raiz->dato, extra);
  }
}

BSTree bstree_minimo(BSTree arbol) {
  BSTree actual = arbol;
  while ((actual != NULL) && (actual->izq != NULL)) {
    actual = actual->izq;
  }
  return actual;
}

BSTree bstree_eliminar(BSTree arbol, void *dato, FuncionComparadora compara,
                        FuncionDestructora destruir) {
  if (arbol == NULL) { // Caso base: arbol vacío
    return arbol;
  }
  else if (compara(arbol->dato, dato) > 0) { // Paso recursivo: arbol->dato > dato
    arbol->izq = bstree_eliminar(arbol->izq, dato, (FuncionComparadora)compara, (FuncionDestructora)destruir);
  }
  else if (compara(arbol->dato, dato) < 0) { // Paso recursivo: arbol->dato < dato
    arbol->der = bstree_eliminar(arbol->der, dato, (FuncionComparadora)compara, (FuncionDestructora)destruir);
  }
  else { // Paso recursivo: arbol->dato == dato
    if (arbol->izq == NULL) { // Caso 1: Sólo tiene un hijo o ninguno
      BSTree nodo = arbol->der;
      // Borrar nodo
      destruir(arbol->dato);
      free(arbol);
      return nodo;
    }
    else if (arbol->der == NULL) {
      BSTree nodo = arbol->izq;
      // Borrar nodo
      destruir(arbol->dato);
      free(arbol);
      return nodo;
    }
    else { // Caso 2: Tiene a sus dos hijos
      BSTree nodo = bstree_minimo(arbol->der);
      arbol->dato = nodo->dato;
      arbol->der = bstree_eliminar(arbol->der, dato, (FuncionComparadora)compara, (FuncionDestructora)destruir);
    }
  }
  return arbol;
}

int bstree_validar(BSTree arbol, void *min, void *max, FuncionComparadora compara) {
  if (arbol == NULL) {
    return 1;
  }
  else if(min != NULL && compara(arbol->dato, min) <= 0) {
    return 0;
  }
  else if(max != NULL && compara(arbol->dato, max) >= 0) {
    return 0;
  }

  return (bstree_validar(arbol->izq, min, arbol->dato, (FuncionComparadora)compara) &&
          bstree_validar(arbol->der, arbol->dato, max, (FuncionComparadora)compara));
}
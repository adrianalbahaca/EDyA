#include "gbtree.h"
#include <stdlib.h>

/**
 * Devolver un árbol vacío
 */
GBTree gbtree_crear() {
    return NULL;
}

/**
 * Destrucción de un árbol
 */
void gbtree_destruir(GBTree arbol, FuncionDestructora destruir) {
    if (arbol != NULL) {
        gbtree_destruir(arbol->left, (FuncionDestructora)destruir);
        gbtree_destruir(arbol->right, (FuncionDestructora)destruir);
        destruir(arbol->data);
        free(arbol);
    }
}

/**
 * Indicar si el árbol es vacío
 */
int gbtree_empty(GBTree arbol) {
    return (arbol == NULL);
}

/**
 * Unir dos árboles
 */
GBTree gbtree_unir(void *dato, GBTree left, GBTree right, FuncionCopia copiar) {
    GBTree nuevoNodo = malloc(sizeof(GBTree));
    assert(nuevoNodo != NULL);
    nuevoNodo->data = copiar(dato);
    nuevoNodo->left = left;
    nuevoNodo->right = right;
    return nuevoNodo;
}

/**
 * Recorrer un árbol (Algoritmo DFS)
 */
void gbtree_recorrer(GBTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit) {
    if(gbtree_empty(arbol)) {
        return;
    }
    else {
        switch(orden) {
            case BTREE_RECORRIDO_IN:
                gbtree_recorrer(arbol->left, orden, (FuncionVisitante)visit);
                visit(arbol->data);
                gbtree_recorrer(arbol->right, orden, (FuncionVisitante)visit);
                break;
            case BTREE_RECORRIDO_POST:
                gbtree_recorrer(arbol->left, orden, (FuncionVisitante)visit);
                gbtree_recorrer(arbol->right, orden, (FuncionVisitante)visit);
                visit(arbol->data);
                break;
            case BTREE_RECORRIDO_PRE:
                visit(arbol->data);
                gbtree_recorrer(arbol->left, orden, (FuncionVisitante)visit);
                gbtree_recorrer(arbol->right, orden, (FuncionVisitante)visit);
                break;
        }
    }
}
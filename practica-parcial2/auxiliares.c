#include "auxiliares.h"
#include <stdlib.h>

BTree* btree_crear_arbol(FuncionComparadora comp, FuncionDestructora destroy,
                        Predicado pred, FuncionCopia copy) {
    BTree *arbol = malloc(sizeof(BTree));
    arbol->raiz = NULL;
    arbol->copy = copy;
    arbol->destroy = destroy;
    arbol->pred = pred;
    arbol->comp = comp;
    return arbol;
}

BNodo* btree_crear_nodo(void* dato, FuncionCopia copy) {
    BNodo* nodo = malloc(sizeof(BNodo));
    nodo->left = NULL;
    nodo->right = NULL;
    nodo->dato = copy(dato);
    return nodo;
}
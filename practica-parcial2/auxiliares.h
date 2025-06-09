#ifndef __AUXILIARES__
#define __AUXILIARES

typedef void (*FuncionVisitante)(void *dato);
typedef void *(*FuncionCopia)(void *dato);
typedef void (*FuncionDestructora)(void *dato);
typedef int (*Predicado)(void *dato);
typedef int (*FuncionComparadora)(void *dato1, void *dato2);

typedef struct _BNodo {
    void* dato;
    struct _BNodo *left;
    struct _BNodo *right;
} BNodo;

typedef struct _BTree {
    BNodo *raiz;
    FuncionComparadora comp;
    FuncionDestructora destroy;
    Predicado pred;
    FuncionCopia copy;
} BTree;

BTree btree_crear_arbol(FuncionComparadora comp, FuncionDestructora destroy, Predicado pred, FuncionCopia copy);

BNodo* btree_crear_nodo(void* dato, FuncionCopia copy);

BNodo* btree_insertar(void* dato, BNodo* raiz, FuncionCopia copy);

void btree_destruir(BTree* arbol);

#endif
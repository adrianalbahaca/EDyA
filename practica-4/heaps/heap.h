#ifndef __B_HEAP__
#define __B_HEAP__

typedef int (*FuncionComparadora)(void*, void*);

typedef struct _BHeap {
    void **arr;
    int capacidad;
    int ultimo;
} *BHeap;



#endif
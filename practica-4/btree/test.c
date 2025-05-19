#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

static void imprimir_entero(int data) {
  printf("%d->", data);
}

int main() {
  BTree ll = btree_unir(1, btree_crear(), btree_crear());
  BTree l = btree_unir(2, ll, btree_crear());
  BTree r = btree_unir(3, btree_crear(), btree_crear());
  BTree m = btree_unir(4, l, r);
  BTree raiz = btree_unir(5, btree_crear(), m);

  // Test de recorrido
  printf("Inorder: ");
  btree_recorrer(raiz, BTREE_RECORRIDO_IN, (FuncionVisitante)imprimir_entero);
  puts("");
  printf("Posorder: ");
  btree_recorrer(raiz, BTREE_RECORRIDO_POST, (FuncionVisitante)imprimir_entero);
  puts("");
  printf("Preorder: ");
  btree_recorrer(raiz, BTREE_RECORRIDO_PRE, (FuncionVisitante)imprimir_entero);
  puts("");

  // Test de cant. de nodos
  printf("El árbol tiene %d nodos\n", btree_nnodos(raiz));

  // Test de búsqueda
  int si = btree_buscar(raiz, 2);
  int no = btree_buscar(raiz, 10);
  printf("%d %d\n", si, no);

  // Test de copia
  BTree raiz2 = btree_copiar(raiz);
  printf("Segundo Árbol: ");
  btree_recorrer(raiz2, BTREE_RECORRIDO_PRE, (FuncionVisitante)imprimir_entero);
  puts("");
  btree_destruir(raiz2);

  // Test de altura
  printf("La altura del árbol 1 es: %d\n", btree_altura(raiz));
  
  btree_destruir(raiz);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

static void imprimir_entero(int dato) {
  printf("%d->", dato);
}

static int div_3(int dato1, int dato2) {
  return (dato1 % dato2 == 0);
}

static int mayor(int dato1, int dato2) {
  return(dato2 > dato1);
}

int main(void) {
  printf("Manejo de lista\n");
  int opcion = 0;
  while(opcion != -1) {
    SList lista1 = slist_crear();
    SList lista2 = slist_crear();
    slist_recorrer(lista1, imprimir_entero);
    puts("NULL");
    slist_recorrer(lista2, imprimir_entero);
    puts("NULL");

    // Mostrar opciones
    printf("------------------------------------\n");
    printf("1. Verificar si la lista es vacía\n");
    printf("2. Agregar un elemento al final\n");
    printf("3. Agregar un elemento al inicio\n");
    printf("4. Determinar el largo de la lista\n");
    printf("5. Concatenar ambas listas\n");
    printf("6. Verificar si la lista contiene un dato\n");
    printf("7. Mostrar el índice de un dato de la lista\n");
    printf("8. Insertar un elemento en la lista\n");
    printf("9. Eliminar un elemento de una lista\n");
    printf("10. Intersección entre dos listas\n");
    printf("11. Ordenar las listas\n");
    printf("12. Invertir las listas\n");
    printf("13. Intercalación entre listas\n");
    printf("14. Partir la lista en dos pedazos\n");
    printf("-1. Salir y destruir las listas\n");
    printf("Elija una opción (-1;14): ");

    // TODO: Ponerme a pensar en todos los casos posibles y aplicar respectivamente XD
    switch(opcion) {
      case 1:
        if(slist_vacia(lista1)) {
          printf("La primera lista está vacía\n");
        }
        if (slist_vacia(lista2)) {
          printf("La segunda lista está vacía\n");
        }
        break;
      case 2:
        int p = 0, d;
        printf("Qué dato quiere guardar?: ");
        scanf("%d", &d);
        while (p == 0) {
          printf("En cuál lista quiere guardar el dato?: ");
          scanf("%d", &p);
          switch(p) {
            case 1:
              lista1 = slist_agregar_final(lista1, d);
              break;
            case 2:
              lista2 = slist_agregar_final(lista2, d);
              break;
            default:
              printf("No es una opción correcta. Pruebe nuevamente\n");
              p = 0;
          }
        }
      case 3:
      int p = 0, d;
      printf("Qué dato quiere guardar?: ");
      scanf("%d", &d);
      while (p == 0) {
        printf("En cuál lista quiere guardar el dato?: ");
        scanf("%d", &p);
        switch(p) {
          case 1:
            lista1 = slist_agregar_inicio(lista1, d);
            break;
          case 2:
            lista2 = slist_agregar_inicio(lista2, d);
            break;
          default:
            printf("No es una opción correcta. Pruebe nuevamente\n");
            p = 0;
        }
      }
      case 4:
      int l = -1;
      while (l == -1) {
        printf("De cuál lista quiere determinar el largo?: ");
        scanf("%d", &l);
        switch(l) {
          case 1:
            l = slist_longitud(lista1);
            printf("El largo de la lista 1 es: %d", l);
            break;
          case 2:
            l = slist_longitud(lista2);
            printf("El largo de la lista 2 es: %d", l);
            break;
          default:
            printf("No es una opción correcta. Intente de nuevo\n");
            l = 0;
            break;
        }
      }
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 11:
      case 12:
      case 13:
      case 14:
    }
  }
  return 0;
}

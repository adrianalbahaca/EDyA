#include "slist.h"
#include <stdlib.h>

// Esta función crea una lista vacía
SList slist_crear() {
  return NULL;
}

// Esta función destruye una lista vacía o con elementos
void slist_destruir(SList lista) {
  SNodo *nodoAEliminar;
  while (lista != NULL) {
    nodoAEliminar = lista;
    lista = lista->sig;
    free(nodoAEliminar);
  }
}

// Esta función indica si la lista es vacía
int slist_vacia(SList lista) {
  return lista == NULL;
}

// Esta función agrega elementos al final de la lista. Consume algo de tiempo
SList slist_agregar_final(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;

  if (lista == NULL)
    return nuevoNodo;

  SList nodo = lista;
  for (;nodo->sig != NULL;nodo = nodo->sig);
  /* ahora 'nodo' apunta al ultimo elemento en la lista */

  nodo->sig = nuevoNodo;
  return lista;
}

// Esta función agrega un elemento al principio de una lista dada. Menos costoso
SList slist_agregar_inicio(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista;
  return nuevoNodo;
}

// Esta función recorre una lista entera y le aplica una función a un elemento de la lista
void slist_recorrer(SList lista, FuncionVisitante visit) {
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}

// A partir de aquí es mi código
// Práctica 2: Listas / Parte 1: Listas simplemente enlazadas

// Ejercicio 2:
// a. Longitud de una lista (Recursiva porque me siento loco XD)
int slist_longitud(SList lista){

  // Si la lista ingresada es vacía, retornar 0
  if(lista == NULL) {
    return 0;
  }
  // Sino, sumarle uno a la invocación inductiva
  else {
    return slist_longitud(lista->sig) + 1;
  }
}

// b. Concatenar listas
SList slist_concatenar(SList lista1, SList lista2) {

  // Si la primera lista está vacía, entonces solo retorna la segunda lista
  if (lista1 == NULL) return lista2;

  // Inicializar variables
  SList temp = lista1;

  // Sino, recorrer la lista hasta llegar al final y luego concatenar la segunda lista a la primera
  for(;temp->sig != NULL; temp = temp->sig);
  temp->sig = lista2;
  return lista1;
}

// c. Verifica si hay un dato en la lista (Recursiva)
int slist_contiene(SList lista, int dato) {

  // Si se llegó al dato, retornar true
  if (lista == NULL) {
    return 0;
  }
  // Sino, si se llegó al final, retornar falso
  else if(lista->dato == dato) {
    return 1;
  }
  // Sino, hacer el paso inductivo
  else {
    return slist_contiene(lista->sig, dato);
  }
}

// d. Retorna el índice de donde está el producto
int slist_indice(SList lista, int dato) {

  // Primero, si la lista está vacía, retornar un mensaje
  if(lista == NULL) {
    return -1;
  }
  // Si la lista tiene la variable
  else if(slist_contiene(lista, dato)) {

    int i = 0;
    SList temp = lista;
    
    // Mientras el siguiente elemento exista
    while(temp->sig != NULL) {

      // Si se consigue el dato, frenar
      if(temp->dato == dato) break;

      //Sino, se suma y se continua con el resto de la lista
      i++; 
      temp = temp->sig;
    }

    // Retornar resultado
    return i;
  }
  else {

    // Si no existe, retorna resultado
    return -1;
  }
}

// e. Insertar un elemento en el índice dado
SList slist_insertar(SList lista, int indice, int dato) {

  // Primero, si la lista está vacía, retornar nada más el elemento
  if (lista == NULL) {
    SList n = malloc(sizeof(SList));
    n->dato = dato;
    n->sig = NULL;
    return n;
  }

  // Recorrer la lista hasta llegar al valor
  SList temp = lista;
  for(int i = 0; i != indice; i++) {
    temp = temp->sig;
  }

  // Seleccionar el siguiente nodo
  SList temp2 = temp->sig;

  // Crear el nodo a añadir
  SList nuevoNodo = malloc(sizeof(SNodo));
  if (nuevoNodo == NULL) {
    return lista;
  }
  nuevoNodo->dato = dato;

  // Hacer el intercambio
  temp->sig = nuevoNodo;
  nuevoNodo->sig = temp2;

  // Retornar lista
  return lista;

}

// f. Eliminar un elemento de la lista
void slist_eliminar(SList *lista, int dato) {

  SList temp = *lista;

  // Si la lista está vacía, o no tiene el elemento, retornar la lista
  if(*lista == NULL || slist_contiene(*lista, dato) == 0) {
    return;
  }

  // Recorrer la lista hasta llegar al penúltimo elemento
  for(;temp->sig->dato != dato; temp = temp->sig);

  // Seleccionar el elemento a eliminar y el siguiente
  SList eliminar = temp->sig;
  SList temp2 = eliminar->sig;

  // Eliminar el nodo
  temp->sig = temp2;
  free(eliminar);
}

// g. Crear una lista nueva con los elementos buscados
SList slist_interseca(SList lista1, SList lista2) {
  // Si alguna de las listas es nula, se retorna una lista vacía
  if(lista1 == NULL || lista2 == NULL) {
    return NULL;
  }

  // Inicialización de nueva lista
  SList resultado = slist_crear();

  for(SList temp = lista1; temp != NULL; temp = temp->sig) {
    if(slist_contiene(lista2, temp->dato)) {
      resultado = slist_agregar_final(resultado, temp->dato);
    }
  }

  return resultado;
}

// h. Crear una lista nueva a partir de una condición pre-hecha
SList slist_interseca_custom(SList lista1, SList lista2, FuncionComp comp) {
  // Si alguna de las listas es nula, entonces retornar una lista vacía
  if(lista1 == NULL || lista2 == NULL) {
    return NULL;
  }

  // Crear lista nueva
  SList resultado = slist_crear();
  SList temp1 = lista1;
  SList temp2 = lista2;

  // Recorrer la lista
  do {
    // Recorrer de alguna forma dato por dato en la lista2 y comparar con dato en lista1
    do {
      // Si se cumple la funcion comparante, meter el dato en la lista resultado
      if(comp(temp1->dato, temp2->dato)) {
        resultado = slist_agregar_final(resultado, temp1->dato);
        break;
      }

      // Ir por el siguiente dato en temp2
      temp2 = temp2->sig;
    } while(temp2 != NULL);

    // Resetear el temp2 al principio
    temp2 = lista2;

    // Usar el siguiente elemento de temp1
    temp1 = temp1->sig;
  } while(temp1 != NULL);

  return resultado;
}

// i. Ordenar una lista
SList slist_ordenar(SList lista, FuncionComp comp) {
  // Si la lista es vacia, retornar lista vacia
  if (lista == NULL) {
    return NULL;
  }

  // Se usará ordenamiento por selección
  // Inicialización de elementos
  SList ordenado = slist_crear();
  int temp;

  do {
    temp = lista->dato;
    for(SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig) {
      if(comp(temp, nodo->dato) && !slist_contiene(ordenado, nodo->dato)) {
        temp = nodo->dato;
      }
    }

    ordenado = slist_agregar_final(ordenado, temp);
  } while (slist_longitud(lista) != slist_longitud(ordenado));

  return ordenado;
}

// j. Voltear una lista
SList slist_reverso(SList lista) {
  // Crear variables
  SList temp = lista;

  // Si la lista está vacía, retornar una lista vacía
  if(lista == NULL) {
    return NULL;
  }

  SList resultado = slist_crear();
  // Hasta que la lista esté vacía
  do {
    // Recorrer la lista hasta llegar al final
    for(;temp->sig == NULL; temp = temp->sig);

    // Guardar el último elemento en la lista nueva
    resultado = slist_agregar_final(resultado, temp->dato);
    
    // Retornar al principio
    temp = lista;
  } while(temp != NULL);
}

SList slist_intercalar(SList lista1, SList lista2) {
  // Casos especiales
  if (lista1 == NULL && lista2 == NULL) {
    return slist_crear();
  }
  else if (lista1 == NULL) {
    return lista2;
  }
  else if (lista2 == NULL) {
    return lista1;
  }

  // Armar una lista nueva que vamos a retornar
  SList intercalado = slist_crear();

  /*
    TODO: Hacer un loop que guarde elementos en la nueva lista de forma intercalada
    Si se llega a vaciar alguna de las listas dadas, guardar el resto de los elementos de
    la otra lista
  */

  // Ver cual lista es la más larga para saber qué hacer
  if (slist_longitud(lista1) > slist_longitud(lista2)) {
    SList temp = lista1;
    for(SList nodo = lista2; nodo != NULL; nodo = nodo->sig) {
      intercalado = slist_agregar_final(intercalado, temp->dato);
      intercalado = slist_agregar_final(intercalado, nodo->dato);
      temp = temp->sig;
    }

    while(temp != NULL) {
      intercalado = slist_agregar_final(intercalado, temp->dato);
      temp = temp->sig;
    }
  }
  else if(slist_longitud(lista1) == slist_longitud(lista2)) {
    for(SList nodo1 = lista1, nodo2 = lista2; nodo1 != NULL & nodo2 != NULL; nodo1 = nodo1->sig, nodo2 = nodo2->sig) {
      intercalado = slist_agregar_final(intercalado, nodo1->dato);
      intercalado = slist_agregar_final(intercalado, nodo2->dato);
    }
  }
  else {
    SList temp = lista2;
    for(SList nodo = lista1; nodo != NULL; nodo = nodo->sig) {
      intercalado = slist_agregar_final(intercalado, nodo->dato);
      intercalado = slist_agregar_final(intercalado, temp->dato);
      temp = temp->sig;
    }

    while(temp != NULL) {
      intercalado = slist_agregar_final(intercalado, temp->dato);
      temp = temp->sig;
    }
  }

  return intercalado;
}

SList slist_partir(SList lista) {
  /*
    TODO: Recorrer la lista con dos punteros, romper la lista en dos, liberar la
    primera mitad y retornar la segunda
  */

  // Verificar el largo de la lista e inicializar valores
  SList temp = lista, medio = lista;
  int l = slist_longitud(lista);

  // Si la lista es par
  if ((l % 2) == 0) {

    // Moverse hasta un paso antes de la mitad de la lista
    for(int i = 1; i < (l / 2); i++) {
      temp = temp->sig;
      medio = medio->sig;
    }

    // Ir un paso adelante con medio
    medio = medio->sig;

    // Hacer que el temp no apunte a nada
    temp->sig = NULL;
    temp = temp->sig;

    return medio;
  }
  else { // De lo contrario
    // Recorrer hasta llegar a la mitad de l+1
    for(int i = 1; i < ((l + 1) / 2); i++) {
      temp = temp->sig;
      medio = medio->sig;
    }

    // Ir un paso adelante con medio y quitarlo de la lista
    medio = medio->sig;
    temp->sig = NULL;
    temp = temp->sig;

    return medio;
  }
}
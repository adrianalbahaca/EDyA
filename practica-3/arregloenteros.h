#ifndef __ARREGLOS_ENTEROS_H__
#define __ARREGLOS_ENTEROS_H__

// Definición de estructuras
typedef struct {
    int* direccion;
    int capacidad;
} ArregloEnteros;

/**
 * Crear una estructura de arreglo de enteros
 */
ArregloEnteros* arreglo_enteros_crear(int capacidad);

/**
 * Destruir una estructura de arreglo de enteros
 */
void arreglo_enteros_destruir(ArregloEnteros *arreglo);

/**
 * Leer un elemento de un arreglo en una cierta posición
 */

 int arreglo_enteros_leer(ArregloEnteros *arreglo, int pos);

 /**
  * Escribir un elemento a un arreglo de elementos
  */
 void arreglo_enteros_escribir(ArregloEnteros *arreglo, int pos, int dato);

 /**
  * Devolver la capacidad de un arreglo de enteros
  */
 int arreglo_enteros_capacidad(ArregloEnteros *arreglo);

 /**
  * Imprimir los elementos de un arreglo
  */
 void arreglo_enteros_imprimir(ArregloEnteros *arreglo);

 /**
  * Ajustar el tamaño del arreglo. Si el tamaño nuevo es menor que el viejo, truncar el contenido
  */
 void arreglo_enteros_ajustar(ArregloEnteros *arreglo, int capacidad);

#endif /* __ARREGLO_ENTEROS_H__*/
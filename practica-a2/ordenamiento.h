#ifndef __ORDENAMIENTO__
#define __ORDENAMIENTO__

// Para esta práctica, se van a usar arreglos de enteros

/**
 * Búsqueda binaria en arreglo de enteros
 */
int binary_search(int arr[], int length, int v);

/**
 * Insertion sort con arreglo
 */
void insertion_sort(int arr[], int length);

/**
 * Merge Sort de un arreglo (mierda)
 */
void merge_sort(int arr[], int inicio, int fin);

/**
 * Quick Sort con esquema de Lometo
 */
void quick_sort_lomuto(int arr[], int inicio, int fin);

/**
 * Mediana de un arreglo de enteros
 */
int mediana(int arr[]);

#endif
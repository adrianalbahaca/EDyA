#include <stdlib.h>
#include <string.h>
#include "ordenamiento.h"

#define COTA 10

// Funcion de intercambio
void swap(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

/**
 * Búsqueda binaria: Empezar en el medio del algoritmo y luego
 * buscar si el elemento visto es menor o igual, o mayor del elemento
 * del índice
 */
int binary_search(int arr[], int length, int v) {
    int inicio = 0;
    int final = length - 1;

    while (inicio <= final) {
        int medio = (inicio + (final - inicio)) / 2;
        if (arr[medio] == v) {
            return 1;
        }
        else if(arr[medio] > v) {
            final = medio - 1;
        }
        else {
            inicio = medio + 1;
        }
    }

    return 0;
}

/**
 * Insertion Sort con arreglos enteros
 */
void insertion_sort(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if(arr[i] < arr[j]) {
                arr[i] = arr[j];
            }
        }
    }
}

// Función auxiliar: Merge

void Merge(int arr[], int inicio, int medio, int fin) {
    int i = inicio;
    int j = medio + 1;
    int k = 0;
    int B[(fin - inicio + 1)];
    while(i <= medio && j <= fin) {
        if (arr[i] <= arr[j]) {
            B[k] = arr[i];
            i++;
        }
        else {
            B[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= medio) {
        B[k] = arr[i];
        i++;
        k++;
    }
    while (j <= fin) {
        B[k] = arr[j];
        j++;
        k++;
    }
    for(int m = 0; m < k; m++) {
        arr[inicio + m] = B[m];
    }
}

void merge_sort(int arr[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        merge_sort(arr, inicio, medio);
        merge_sort(arr, medio + 1, fin);
        Merge(arr, inicio, medio, fin);
    }
}

/**
 * Quick Sort, eligiendo el pivote con la partición de Lomuto
 */

 int part_lomuto(int arr[], int inicio, int fin) {
    int pivote = arr[fin];
    int i = inicio - 1;
    int aux;
    for (int j = inicio; j < fin; j++) {
        if (arr[j] <= pivote) {
            i++;
            //swap(arr[i], arr[j])
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
    }
    //swap(arr[i + 1], arr[fin])
    aux = arr[i + 1];
    arr[i + 1] = arr[fin];
    arr[fin] = aux;
    return i + 1;
 }

void quick_sort_lomuto(int arr[], int inicio, int fin) {
    if (fin < COTA) {
        insertion_sort(arr, fin);
    }
    if(inicio < fin) {
        int pivote = part_lomuto(arr, inicio, fin);
        quick_sort_lomuto(arr, inicio, pivote - 1);
        quick_sort_lomuto(arr, pivote + 1, fin);
    }
}
#include <stdio.h>

void bubble_sort(float arreglo[], int longitud);
float mediana(float *arreglo, int longitud);

int main() {
    // Recibir elementos en un array
    printf("Esta función recibe un array y calcula su mediana. Por ejemplo:\n");

    // Ejemplos de mediana
    float arr1[] = {-1.0, 2.2, 2.9, 3.1, 3.5};
    float arr2[] = {-1.0, 2.2, 2.9, 3.1};
    for(int i = 0; i < (sizeof(arr1) / sizeof(arr1[0])); i++) {
        printf("%.2f; ", arr1[i]);
    }
    printf("\n");
    for(int i = 0; i < (sizeof(arr2) / sizeof(arr2[0])); i++) {
        printf("%.2f; ", arr2[i]);
    }
    printf("\n");

    // Invocar la función a construir
    int tamaño1 = sizeof(arr1) / sizeof(arr1[0]);
    int tamaño2 = sizeof(arr2) / sizeof(arr2[0]);
    float med1 = mediana(arr1, tamaño1);
    float med2 = mediana(arr2, tamaño2);

    // Mostrar los resultados
    printf("La mediana del primer array es: %.2f\n", med1);
    printf("La mediana del segundo array es: %.2f\n", med2);
    
}

void bubble_sort(float arreglo[], int longitud) {
    // Ordenar el array usando el bubble sort
    for(int iter = 0; iter < longitud - 1; iter++) {
        for(int i = 0; i < longitud - iter - 1; i++) {
            if(arreglo[i] > arreglo [i + 1]) {
                float aux = arreglo[i];
                arreglo[i] = arreglo[i + 1];
                arreglo[i + 1] = aux;
            }
        }
    }
}

float mediana(float *arreglo, int longitud) {
    // TODO: Hacer una función que calcule la mediana de un array sin ordenar

    // Ordernar los archivos de menor a mayor
    bubble_sort(arreglo, longitud);
    
    // Si el archivo tiene una longitud impar
    if(longitud % 2 != 0) {
        // Sacar el punto medio del arreglo
        return arreglo[longitud / 2];
    } // De lo contrario
    else {
        // Calcular el promedio entre uno antes de la mitad y el otro después de la mitad
        float promedio = (arreglo[(longitud / 2) - 1] + arreglo[longitud / 2]) / 2.0;

        // Retornar el resultado
        return promedio;
    }
}
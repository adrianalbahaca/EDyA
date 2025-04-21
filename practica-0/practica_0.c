#include <stdio.h>
#include <string.h>

void direccion_de_cosos(void);
void set_first(int *);
void set_int(int*);
void swap(int*, int*);

int main(void) {
    // Create menu of options for each item in the practice
    printf("Practica 0: Repaso de C\n");

    int option = 0;

    do {
        printf("Menú de ítems: \n");
        printf("1. Dirección de un int y de un caracter de un string\n");
        printf("2. Cambiar a 0 el primer elemento de un arreglo\n");
        printf("3. Es un entero distinto a cero, o no?\n");
        printf("4. Cambio de valor de variables\n");
        printf("-1. Salir\n");
        printf("Elija una opción <1 - 4>: ");

        // Obtener un valor y revisar si es un int o no
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            direccion_de_cosos();
            break;

        case 2:
            /// Declarar array como quisiera
            int numeros[] = {25, 30, 2, 0};

            // Indicar el input
            printf("Esta función cambiará el primer numero de un array de ints\n");
            for (int i = 0; i < (sizeof(numeros)/sizeof(numeros[1])); i++) {
                printf("%d; ", numeros[i]);
            }
            printf("\n");

            // Cambiar valor
            set_first(numeros);

            // Indicar el resultado
            for (int i = 0; i < (sizeof(numeros)/sizeof(numeros[1])); i++) {
                printf("%d; ", numeros[i]);
            }
            printf("\n");
            break;

        case 3:
            // Declarar int
            int l = 13;
            printf("Esta función toma un entero, y lo cambia a 1 si es distinto a cero. El int dado es %d\n", l);

            // Pasar el puntero del valor y cambiarlo acorde a las condiciones
            int* pl = &l;
            set_int(pl);

            // Indicar el resultado
            printf("Ahora, el entero vale: %d\n", l);
            break;

        case 4:
            // Recibir variables
            int a, b;
            printf("Elija la primera y segunda variable: ");
            scanf("%d %d", &a, &b);
            printf("Las variables elegidas son: a: %d, b: %d \n", a, b);

            // Invocar función de cambio
            swap(&a, &b);

            // Mostrar el cambio
            printf("Mire el intercambio: a: %d, b: %d\n", a, b);

            break;

        case -1:
            printf("Nos vemos!\n");
            break;
        
        default:
            printf("Síntax inválido");
            break;
        }
    } while(option != -1);
}

// Resolución de cada ejercicio

void direccion_de_cosos(void) {
    int a = 10;
    char *s = "Pene";

    printf("Esta función muestra la dirección de un entero y un string en memoria\n");

    printf("Dirección del entero: %p\n", &a);
    printf("Dirección del principio del string: %p\n", &s);
    return;
}

void set_first(int* numeros) {
    // Recibo: Puntero al principio de un array
    
    *numeros = 0;
    return;
}

void set_int(int* pa) {
    if (*pa == 0) {
        *pa = 0;
    }
    else {
        *pa = 1;
    }
    return;
}

void swap(int *a, int *b) {
    // Crear un valor intermedio para hacer el intercambio
    int x = *a;
    *a = *b;
    *b = x;

    return;
}
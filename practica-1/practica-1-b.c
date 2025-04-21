#include <stdio.h>
#include <stdlib.h>

int string_len(char *c);
void string_reverse(char *s);

int main(void) {
    // Práctica 1: Ejercicio 2
    int opcion, cant;
    printf("Ejercicio 2: Opciones de los ítems\n");
    
    // Ir caso por caso
    do {
        printf("------------------------------------------\n");
        printf("1. Longitud de una cadena\n");
        printf("2. Invertir una cadena\n");
        printf("3. Concatenar cadenas\n");
        printf("4. Comparar cadenas\n");
        printf("5. Subcadena de una cadena\n");
        printf("-1. Salir\n");
        printf("Elija una opción (1-5; -1): ");
        scanf("%d", &opcion);

        // Opciones
        switch (opcion)
        {
        case 1:
            int length = 0;
            printf("Esta función recibe una cadena y devuelve el largo del mismo\n");
            printf("Escriba una cadena: ");
            scanf("%s", s);
            length = string_len(s);
            printf("El largo del string es: %d\n", length);
            break;

        case 2:
            printf("Esta función toma un string y lo 'voltea'\n");
            printf("Escriba una cadena: ");
            scanf("%s", s);
            string_reverse(s);
            printf("El resultado es: %s\n", s);
            break;

        case 3:
            printf("Esta función toma dos string y los concatena en algún punto\n");
            printf("Escriba la primera cadena: ");
            scanf("%s", s);
            printf("Escriba el segundo caracter: ");
            scanf("%s", t);
            printf("Las palabras a concatenar son %s y %s\n", s, t);
            break;

        case 4:
            /* */
            break;

        case 5:
            /* */
            break;
        
        default:
            printf("Nos vemos!\n");
            break;
        }
    } while(opcion != -1);

    return 0;
}

int string_len(char *c) {
    // TODO: Escribir una función que calcule el largo del string
    int len = 0;
    for(int i = 0; c[i] != '\0'; i++){
        len++;
    }
    return len;
}

void string_reverse(char *s) {
    // TODO: Hacer una función que voltee el string completamente
    int l = string_len(s);
    l--;
    char t; // Carácter temporal

    for(int i = 0; i < l; i++) {
        t = s[l];
        s[l] = s[i];
        s[i] = t;
        l--;
    }

}
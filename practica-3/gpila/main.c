#include "gpila.h"
#include "contacto.h"
#include <stdio.h>

int main(void) {
    // Muestra de lista de contactos
    Contacto *contactos[4];
    contactos[0] = contacto_crear("Pepe Argento", "3412695452", 61);
    contactos[1] = contacto_crear("Moni Argento", "3412684759", 60);
    contactos[2] = contacto_crear("Coqui Argento", "3415694286", 32);
    contactos[3] = contacto_crear("Paola Argento", "3416259862", 29);

    // Crear una lista
    Pila pila = pila_crear();

    for(int i = 0; i < 4; i++) {
        pila = pila_apilar(pila, contactos[i], (FuncionCopia)contacto_copia);
        contacto_destruir(contactos[i]);
        pila_imprimir(pila, (FuncionVisitante)contacto_imprimir);
        printf("----\n");
    } 

    printf("Tope de la pila:\n");
    pila_tope(pila, (FuncionVisitante)contacto_imprimir);
    printf("----\n");

    printf("Tope de la pila:\n");
    pila = pila_desapilar(pila, (FuncionDestructora)contacto_destruir);
    pila_tope(pila, (FuncionVisitante)contacto_imprimir);
    printf("----\n");

    // Revertir una pila
    pila = lista_invertir(pila, (FuncionCopia)contacto_copia, (FuncionDestructora)contacto_destruir);
    glist_recorrer(pila, (FuncionVisitante)contacto_imprimir);

    pila_destruir(pila, (FuncionDestructora)contacto_destruir);
    return 0;
}
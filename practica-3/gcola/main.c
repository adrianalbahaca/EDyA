#include "gcola.h"
#include <stdio.h>
#include "contacto.h"

int main(void) {
    // Lista muestra de contactos para probar cola
    Contacto *contactos[5];
    contactos[0] = contacto_crear("Pepe Argento", "3412695452", 61);
    contactos[1] = contacto_crear("Moni Argento", "3412684759", 60);
    contactos[2] = contacto_crear("Coqui Argento", "3415694286", 32);
    contactos[3] = contacto_crear("Paola Argento", "3416259862", 29);
    contactos[4] = contacto_crear("Maria Elena Fuseneco", "3416874594", 59);

    GCola *cola = cola_crear();

    for(int i = 0; i < 5; i++) {
        cola = cola_encolar(cola, contactos[i], (FuncionCopia)contacto_copia);
        contacto_destruir(contactos[i]);
        cola_imprimir(cola, (FuncionVisitante)contacto_imprimir);
        printf("---\n");
    }

    cola = cola_desencolar(cola, (FuncionDestructora)contacto_destruir);
    cola_imprimir(cola, (FuncionVisitante)contacto_imprimir);
    printf("----\n");

    cola_inicio(cola, (FuncionVisitante)contacto_imprimir);
    printf("----\n");

    cola_destruir(cola, (FuncionDestructora)contacto_destruir);
    return 0;
}
#include "funciones-1.h"
#include <string.h>

#define CANT_PERSONAS 10

/**
 * crear_matriz_dispersa: void -> Matriz
 * Crea una Matriz vacía
 */
Matriz crear_matriz() {

  Matriz tabla = malloc(sizeof(struct _TablaHash));
  assert(tabla != NULL);

  tabla->elems = malloc(sizeof(CasillaHash) * CANT_PERSONAS);
  assert(tabla->elems != NULL);

  tabla->numElems = 0;
  tabla->capacidad = CANT_PERSONAS;

  for (int i = 0; i < tabla->capacidad; i++) {
    tabla->elems[i].asociasiones == iniciar_lista();
    tabla->elems[i].conPersona = 0;
  }

  return tabla;
}

/**
 * anadir_persona: Matriz String -> void
 * Añade una nueva persona a la matriz
 */
void anadir_persona(Matriz matriz, String persona) {
    unsigned hash = valor_hash(persona) % matriz->capacidad;
    matriz->elems[hash].conPersona = 1;
    matriz->numElems++;
}

/**
 * anadir_asociación: Matriz String String -> void
 * Añade una asociación a dos personas que existen en la matriz. Si no existen
 * en la matriz, no hace cambios
 */
void anadir_asociacion(Matriz matriz, String persona, String asociacion) {
    unsigned hash = valor_hash(persona) % matriz->capacidad;
    if (matriz->elems[hash].conPersona == 1) {
        matriz->elems[hash].asociasiones = agregar_elemento(matriz->elems[hash].asociasiones, asociacion);
    }
}
#ifndef __SOLUCION_1__
#define __SOLUCION_1__
#include <stdlib.h>

typedef char* String;

/**
 * Cada casilla de la matriz es una lista de todas sus asociasiones
 */
typedef struct _SNodo {
  int persona_hash;
  int asociasion;
  struct _SNodo *sig;
} SNodo;

/**
 * Estructura de cada casilla
 */
typedef struct {
  SNodo* asociasiones;
} CasillaHash;

/**
 * Estructura principal que representa la matriz
 */
struct _TablaHash {
  CasillaHash *elems;
  unsigned numElems;
  unsigned capacidad;
};

typedef struct _TablaHash *Matriz;

/**
 * crear_matriz_dispersa: void -> Matriz
 * Crea una Matriz vacía
 */
Matriz crear_matriz();

/**
 * anadir_persona: Matriz String -> void
 * Añade una nueva persona a la matriz
 */
void anadir_persona(Matriz matriz, String persona);

/**
 * anadir_asociación: Matriz String String -> void
 * Añade una asociación a dos personas que existen en la matriz. Si no existen
 * en la matriz, no hace cambios
 */
void anadir_asociacion(Matriz matriz, String persona, String asociacion);

/**
 * eliminar_asociacion: Matriz String String -> void
 * Elimina una asociación con una persona
 */
void eliminar_asociacion(Matriz matriz, String persona, String asociacion);

/**
 * eliminar_persona: Matriz String -> void
 * Elimina a una persona a considerar en esta matriz
 */
void eliminar_persona(Matriz matriz, String persona);

/**
 * destruir_matriz: Matriz -> void
 * Destruye una matriz entera
 */
void destruir_matriz(Matriz matriz);

#endif // __SOLUCION_1__
#ifndef __G_ARRAY_H__
#define __G_ARRAY_H__
#include "glist.h"

// Estructuras
typedef void** GArray;

typedef struct {
    char *nombre, *direccion, *dni;
    int edad;
} Persona;

/**
 * Volcar los datos de una lista recibida en un arreglo de tipo GArray
 */
GArray list_to_array(GList lista, FuncionCopia copiar);

/**
 * Toma una lista de estructura Persona
 */
GArray list_to_array_persona(GList lista);

/**
 * Dada una lista, retornar una lista nueva con las personas mayor a 18 años
 */
GList mayores_de_18(GList lista);

#endif
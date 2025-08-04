#include "Plantillas/avl/avl.h"

/**
 * Para una búsqueda veloz y ordenada, uso un AVL
 */

/**
 * crear_conjunto: void -> AVL
 * Crea un conjunto totalmente vacío
 */
AVL crear_conjunto();

/**
 * insertar_a_conjunto: int -> AVLNodo*
 * Inserta un elemento y su cantidad de elementos menores al mismo
 */
AVL insertar_a_conjunto(int elemento);
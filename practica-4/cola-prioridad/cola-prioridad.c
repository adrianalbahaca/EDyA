#include <stdlib.h>
#include "cola-prioridad.h"

// Funciones auxiliares
// ----------------------------------------------------------------------------
static void swap(void** a, void** b){
    void* aux = *a;
    *a = *b;
    *b = aux;
}

// comp_prioridad: Compara las prioridades de los dos elementos de la cola
static int comp_prioridad(Cola_Elemento n1, Cola_Elemento n2) {
    int _n1 = n1.prioridad;
    int _n2 = n2.prioridad;
    return (_n1 - _n2);
}

// hundir: Mueve el nodo hacia abajo de la cola de prioridad hasta que está en la posicion correcta
void hundir(colaPrioridad cola, int i){
    int idx_right = RIGHT(i);
    int idx_left = LEFT(i);
    int largest = i;

    if (idx_left <= cola->ultimo && comp_prioridad(cola->arr[idx_left], cola->arr[largest]) > 0) {
        largest = idx_left;
    }
    else if (idx_right <= cola->ultimo && comp_prioridad(cola->arr[idx_right], cola->arr[largest]) > 0) {
        largest = idx_right;
    }
    if (largest != i) {
        swap(&cola->arr[largest], &cola->arr[i]);
        hundir(cola, largest);
    }
}

// flotar: mueve el elemento hacia arriba de la cola hasta que este en la posicion correcta
void flotar(colaPrioridad cola, int i){
    int idx_padre = PARENT(i);

    if (idx_padre < 0) {
        return;
    }
    else if (comp_prioridad(cola->arr[i], cola->arr[idx_padre]) > 0) {
        swap(&cola->arr[idx_padre], &cola->arr[i]);
        flotar(cola, idx_padre);
    }
}
//------------------------------------------------------------------------------

/**
 * cola_prioridad_crear: Crear una cola de prioridad y guardar las funciones de copia y
 * eliminación de datos
 */
colaPrioridad cola_prioridad_crear(FuncionCopiadora copy_elemento, FuncionDestructora destroy_elemento) {
    colaPrioridad cola = malloc(sizeof(colaPrioridad));
    cola->arr = malloc(QUEUE_SIZE * sizeof(Cola_Elemento));
    cola->capacidad = QUEUE_SIZE;
    cola->ultimo = -1;
    cola->copy = copy_elemento;
    cola->destroy = destroy_elemento;
    return cola;
}

/**
 * cola_prioridad_recorrer:  Recorrer por cada elemento de la cola y aplicar la funcion visitante dada
 */

void cola_prioridad_recorrer(colaPrioridad cola, FuncionVisitante visit) {
    for (int i = 0; i <= cola->ultimo; i++) {
        visit(cola->arr[i].dato);
    }
}

/**
 * cola_prioridad_destruir: Destruit cola de prioridad, sus elementos y las funciones guardadas
 */
void cola_prioridad_destruir(colaPrioridad cola) {
    cola_prioridad_recorrer(cola, cola->destroy);
    free(cola->arr);
    free(cola);
}

/**
 * cola_prioridad_es_vacia: Determina si no hay elementos en la cola
 */
int cola_prioridad_es_vacia(colaPrioridad cola) {
    return (cola->ultimo == -1);
}

/**
 * cola_prioridad_maximo: Muestra el elemento máximo de la cola 
 */
void* cola_prioridad_maximo(colaPrioridad cola) {
    /*
        Como se está usando un heap binario, el elemento de más grande prioridad
        está en el tope de la lista
    */
    return (cola->arr[0].dato);
}

/**
 * cola_prioridad_eliminar_maximo: Elimina el elemento máximo y reordena la cola
 */

void cola_prioridad_eliminar_maximo(colaPrioridad cola) {
    /*
        Como se usa un heap binario, eliminar el máximo es el equivalente a borrar
        la raíz del heap y reordenar todos los elementos
    */
    int pos = -1;
    int i = 0;

    // Buscamos la primera aparicion del elemento
    while (pos == -1 && i <= cola->ultimo) {

        if (comp_prioridad(cola->arr[0], cola->arr[i]) == 0) {
            pos = i;
        }

        i++;

    }

    if(pos == -1){
        printf("El elemento no se encuentra en el arbol\n");
        return;
    }

    //Si el elemento estaba en el arbol, lo quitamos y lo reemplazamos por el ultimo.
    Cola_Elemento elem = cola->arr[pos];
    cola->arr[pos] = cola->arr[cola->ultimo--];

    // Destruimos el dato
    cola->destroy(elem.dato);
    free(&elem);

    // Ubicamos el dato segun corresponda
    if (pos > 0 && comp_prioridad(cola->arr[pos], cola->arr[PARENT(pos)]) > 0) {
        flotar(cola, pos);
    } 
    else {
        hundir(cola, pos);
    }
}

/**
 * cola_prioridad_insertar: Insertar un elemento con una cierta prioridad en la cola
 */
void cola_prioridad_insertar(colaPrioridad cola, void* dato, int prioridad) {
    /*
        Como se usa un heap binario, solo es cuestión de insertar el elemento en el heap
        como un elemento de la cola, guardando el dato y la prioridad
    */
   Cola_Elemento *elem = malloc(sizeof(Cola_Elemento));
   elem->dato = cola->copy(dato);
   elem->prioridad = prioridad;

   // Si la cola no tiene capacidad suficiente, duplicar la capacidad
    if(cola->ultimo + 1 == cola->capacidad) { 
        cola->arr = realloc(cola->arr, sizeof(void*)*cola->capacidad*2);
        cola->capacidad *= 2;
    }

    // Insertamos el elemento al final de la cola
    cola->arr[++cola->ultimo] = *elem;

    // Flotamos el elemento hasta su posición final
    flotar(cola, cola->ultimo);
}


# NOTAS

Estructuras a aprender:

1. Arbol binario: Estructura que involucra nodos vacíos o un nodo raíz de donde descienden otros árboles binarios
    ```
    typedef struct _BTNodo {
        void* dato;
        struct _BTNodo *left, *right;
    } BTNodo;
    ```
    + **Definición recursiva**: Cada función para aplicar en el árbol se aplica recursivamente.
    + Recorrido:
        + Inorder: Nodo->izq -> Nodo->dato -> Nodo->der
        + Postorden: Nodo->izq -> Nodo->der -> Nodo->dato
        + Preorden: Nodo->dato -> Nodo->izq -> Nodo->der
    + Profundidad: Nivel de la hoja con la distancia más larga a la raíz 
    + Altura: 
    + Profundidad máx. = Cant. de nodos
    + Prof. mín: floor(log2(Cant. de nodos)) + 1
    + Nodos mín.: Profundidad
    + Nodos máx:  2^Prof. - 1
    + Balance: Prof._l - Prof._r. (Si |Balance| = {0, 1} && Subárboles balanceados -> Árbol balanceado)
    + Completo: El último nivel está lleno

2. Áboles Binarios de Búsqueda: Árbol binario donde subárboles izquierdos son valores menores y subárboles derechos son valores mayores, con cada subárbol siendo ABB
    ```
    typedef struct _ABBNodo {
        void* dato;
        _ABBNodo *less, *greater;
    } ABBNodo;
    ```
    + Menor dato -> Nodo hoja en la izquierda. Mayor dato -> Nodo hoja de la derecha
    + **Todo dato nuevo se añade como hoja**
    + Borrar dato:
        + 0 Hijos: Borrar dato
        + 1 Hijo, 2 Hijos:
            ```
            ABBNodo *aux = menorDer(raiz->der);
            raiz->dato = aux->dato;
            raiz->der = borrarNodo(raiz->der, dato, dummy_destroy, comp);
            ```
    + **Recorrer inorder genera una lista ordenada**
3. AVL: Árbol Binario de Búsqueda balanceado
    + Borrar e insertar es como ABB, y después se rebalancea
    + Rebalanceado:
    ```
    if(avlFactorBalance(raiz) == 2) {
        if(avlFactorBalance(raiz->der) == -1) {
            raiz->der = rotacionDer(raiz->der)
        }
        raiz = rotacionIzq(raiz)
    }
    else if (AvlFactorBalance(raiz) == -2) {
        if(avlFactorBalance(raiz->izq) == 1) {
            raiz->izq = rotacionIzq(raiz->izq)
        }
        raiz = rotacionDer(raiz)
    }
    return raiz
    ```
    + Rotación a la derecha:
    ```
    AVLNodo *hijoIzq = raiz->izq
    // Verificar si se pudo asignar
    raiz->izq = hijoIzq->der
    hijoIzq->der = raiz
    // Actualizar alturas
    return hijoIzq
    ```
    + Rotación a la izquierda:
    ```
    AVLNodo *hijoDer = raiz->der
    // Verificar si se pudo asignar
    raiz->der = hijoDer->izq
    hijoDer->izq = raiz
    // Actualizar alturas
    return hijoDer
    ```
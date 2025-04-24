# Insertar elemento a una lista

1. *Nodo* = Memoria en espacio(tamano de SGNodo)
    *Nodo->datos* = Copiar(datos)
    1.a Principio de lista
    **SI** *Comp(lista, Nodo)* es True, entonces:
        *Nodo->next* = *lista*
        **DEVOLVER** *Nodo*
    1.b Medio de la lista
        **PARA** (temp = lista, temp != NULL, temp<-temp->sig):
            **SI** *Comp(temp->sig, Nodo)* es True, entonces:
                *Nodo->next* = *temp->sig*
                *temp->sig* = *Nodo*
                **DEVOLVER** *lista*
            **FIN SI**
        **FIN PARA**
    1.c Final de la lista
        **RECORRER HASTA FINAL** (temp = lista)
        temp->sig = Nodo
        Nodo->sig = **NULL**
        **DEVOLVER** *lista*
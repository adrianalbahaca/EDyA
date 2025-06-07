#include "cola-prioridad.h"

static int comp_int(Cola_Elemento n1, Cola_Elemento n2){
    int _n1 = n1.prioridad;
    int _n2 = n2.prioridad;
    return _n1 - _n2;
}


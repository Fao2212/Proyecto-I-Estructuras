#include "Estado.h"

Estado :: Estado(){
    this->estado = true;
}

void Estado :: cambioDeEstado(){
    if( estado == true)
        this->estado = false;
    else
        this->estado = true;
}

#include "Cocinero.h"
#include "Estado.h"
#include "Cola.h"

Cocinero :: Cocinero(){
    this->estado = new Estado();
    this->peticiones = new Cola<Peticion>();
    this->tiempo = 10;
    this-> atendidos = 0;
}




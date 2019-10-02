#include "Cola.h"
#include "CocinaEnsaladas.h"
#include "Cocinero.h"
#include "Estado.h"

CocinaEnsaladas :: CocinaEnsaladas(){
    this->cocinero = new Cocinero();
    this->peticiones = new Cola<Peticion>();
    this->estado = new Estado();
    this->salida = new Cola<Peticion>();
}


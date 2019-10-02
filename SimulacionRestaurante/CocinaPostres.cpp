#include "CocinaPostres.h"
#include "Cocinero.h"
#include "Cola.h"
#include "Estado.h"

CocinaPostres :: CocinaPostres(){
    this->cocinero = new Cocinero();
    this->peticiones = new Cola<Peticion>();
    this->estado = new Estado();
    this->salida = new Cola<Peticion>();
}

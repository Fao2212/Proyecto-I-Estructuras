#include "Lavaplatos.h"
#include "Estado.h"
#include "Cola.h"

Lavaplatos :: Lavaplatos(){
    this->estado = new Estado();
    this->tiempo = 10;
    this->atendidos = 0;
    this->peticiones = new Cola<Peticion>();
}

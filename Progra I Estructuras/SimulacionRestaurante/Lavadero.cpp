#include "Lavadero.h"
#include "Lavaplatos.h"
#include "Estado.h"
#include "Cola.h"

Lavadero :: Lavadero(){
    this->estado = new Estado();
    this->lavaplatos = new Lavaplatos();
    this->peticiones = new Cola<Peticion>();
}

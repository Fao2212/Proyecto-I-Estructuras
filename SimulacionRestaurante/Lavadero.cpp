#include "Lavadero.h"
#include "Lavaplatos.h"
#include "Estado.h"
#include "Cola.h"

Lavadero :: Lavadero(){
    this->estado = new Estado();
    this->peticiones = new Cola<Peticion>();
    this->lavaplatos = new Lavaplatos(this);//revisar que se pase al final solo por seguridad
}

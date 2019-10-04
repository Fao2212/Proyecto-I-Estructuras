#include "Lavaplatos.h"
#include "Estado.h"
#include "Cola.h"
#include "Lavadero.h"
#include "Peticion.h"

Lavaplatos :: Lavaplatos(Lavadero * lavadero){
    this->estado = new Estado();
    this->atendidos = 0;
    this->peticiones = new Cola<Peticion>();
    this->lavadero = lavadero;
}

Peticion * Lavaplatos :: tomarPlato(){
    if(lavadero->peticiones->siguienteEnCola()!= nullptr){
        Peticion * peticion = lavadero->peticiones->desencolar()->dato;
        peticiones->encolar(peticion);
        return peticion;
    }
    return nullptr;
}

Peticion * Lavaplatos :: lavarPlato(){// No usar esta el thread se encarga de tomar lavar el plato;
    if(peticiones->siguienteEnCola()!= nullptr){
        peticiones->desencolar();
    }
    return nullptr;
}

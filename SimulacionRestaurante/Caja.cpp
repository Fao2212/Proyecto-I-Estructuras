#include "Caja.h"
#include "Cajero.h"
#include "Estado.h"
#include "ListaSimple.h"
#include "Cola.h"

Caja :: Caja(){
    this->cajero = new Cajero(this);
    this->estado = new Estado();
    this->peticiones = new Cola<Peticion>();
    this->modo = COLA;
    this->historial = new ListaSimple<Peticion>;

}

void Caja :: desactivar(){
    this->estado->cambioDeEstado();
}

void Caja :: cambioDeModo(){
    switch (this->modo) {
    case COLA:
        this->modo = PILA;
        break;
    case PILA:
        this->modo = COLA;
        break;
    }
}


void Caja :: recibirPeticion(Peticion * peticion){
    switch (this->modo) {
    case COLA:
        peticiones->encolar(peticion);
        break;
    case PILA:
        peticiones->encolarAlIncio(peticion);
        break;
    }
}

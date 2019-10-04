#include "Cajero.h"
#include "Estado.h"
#include "Cola.h"
#include "Caja.h"
#include "ListaSimple.h"
#include "Nodo.h"
#include "Peticion.h"
#include "Plato.h"

Cajero :: Cajero(Caja * caja){
    this->estado = new Estado();
    this->peticiones = new Cola<Peticion>();
    this->atendidos = 0;
    this->caja = caja;
}

Peticion * Cajero:: tomarCuenta(){
    if(caja->peticiones->siguienteEnCola() != nullptr){
        Peticion * peticion = caja->peticiones->desencolar()->dato;
        peticiones->encolar(peticion);
        return peticion;
    }
    return nullptr;
}

Peticion * Cajero :: hacerCobro(){
    if(peticiones->siguienteEnCola() != nullptr){
        Peticion * peticion = peticiones->desencolar()->dato;
        caja->historial->insertar(peticion);
        return peticion;
    }
    return nullptr;
}

double Cajero :: ventasActuales(){
    Nodo<Peticion> * temp = caja->historial->primerNodo;
    double total = 0;
    while (temp != nullptr) {
        for(int i = 0; i < 6; i++){
            if(temp->dato->platos[i]!=nullptr)
                total += temp->dato->platos[i]->precio;
        }

        temp = temp->siguiente;
    }
    return total;
}

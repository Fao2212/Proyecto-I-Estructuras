#include "Cocinero.h"
#include "Estado.h"
#include "Cola.h"
#include "Peticion.h"
#include "Cocina.h"
#include "Plato.h"

Cocinero :: Cocinero(Cocina * cocina){

    this->estado = new Estado();
    this->peticiones = new Cola<Peticion>();
    this->tiempo = 10;
    this-> atendidos = 0;
    this-> cocina = cocina;
}

Peticion * Cocinero :: tomarOrden(){
    if(cocina->peticiones->siguienteEnCola() != nullptr){
        Peticion * peticion = cocina->peticiones->desencolar()->dato;
        recogerOrden(peticion);
        return peticion;
    }
    return nullptr;
}

void Cocinero :: recogerOrden(Peticion * peticion){
    qDebug()<<peticion;
    switch (peticion->fase) {
        case COCINAENTRADA:
        peticion->setFase(COCINANDOENTRADA);
        break;
    case COCINAPRINCIPAL:
        peticion->setFase(COCINANDOPRINCIPAL);
        break;
    case COCINAPOSTRE:
        peticion->setFase(COCINANDOPOSTRE);
        break;
    default:
        break;
    }
    peticiones->encolar(peticion);
}

void Cocinero :: dejarOrden(){
    switch (peticiones->siguienteEnCola()->dato->fase) {
        case COCINANDOENTRADA:
        peticiones->siguienteEnCola()->dato->setFase(ENTRADATERMINADA);
        break;
    case COCINANDOPRINCIPAL:
        peticiones->siguienteEnCola()->dato->setFase(PRINCIPALTERMINADA);
        break;
    case COCINANDOPOSTRE:
        peticiones->siguienteEnCola()->dato->setFase(POSTRETERMINADO);
        break;
    default:
        break;
    }
    cocina->peticiones->encolar(peticiones->desencolar()->dato);
}

int Cocinero :: tiempoDeCoccion(int i){
    if(peticiones->siguienteEnCola()!=nullptr)
        return peticiones->siguienteEnCola()->dato->platos[i]->tiempoDePreparacion;
    else return -1;
}

QString Cocinero :: cocinandoPlato(int i){
    if(peticiones->siguienteEnCola()!=nullptr)
        return peticiones->siguienteEnCola()->dato->platos[i]->nombre;
    else
        return "error";
}
/*
int Cocinero :: tiempoLavado(int i){
    if(peticiones->siguienteEnCola()!=nullptr)
        peticiones->siguienteEnCola()->dato->platos[i]->tiempoDeLavado;
}

int Cocinero :: precioPlato(int i){
    if(peticiones->siguienteEnCola()!=nullptr)
        peticiones->siguienteEnCola()->dato->platos[i]->precio;
}*/

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
    this->id = 0;
}

Peticion * Cocinero :: tomarOrden(){
    if(cocina->peticiones->siguienteEnCola() != nullptr){
        Peticion * peticion = cocina->peticiones->desencolar()->dato;
        return recogerOrden(peticion);

    }
    return nullptr;
}

Peticion * Cocinero :: recogerOrden(Peticion * peticion){
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
        qDebug()<<"Error en la fase";
        qDebug()<<peticion->faseMensaje();
        break;
    }
    peticiones->encolar(peticion);
    qDebug()<<"gAPIN Y BOWES";
    qDebug()<<peticion->faseMensaje();
    return peticion;
}

void Cocinero :: dejarOrden(){
    qDebug()<<"Antes";
    qDebug()<<peticiones->siguienteEnCola()->dato->fase;
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
    qDebug()<<"sI PA?:";
    qDebug()<<peticiones->siguienteEnCola()->dato->faseMensaje();
    cocina->salida->encolar(peticiones->desencolar()->dato);
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

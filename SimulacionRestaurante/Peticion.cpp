#include "Peticion.h"
#include "Estado.h"
#include "GrupoDeClientesBORRADOR.h"

Peticion::Peticion(Mesa * mesa,int grupo){

    this->fase = CREADA;
    this->mesa = mesa;
    this->grupo = grupo;

}

void Peticion :: setFase(Fase state){
    this->fase = state;
}

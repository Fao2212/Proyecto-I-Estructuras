#include "Cliente.h"
#include "Peticion.h"
#include "TablaPlatos.h"
#include "Random.h"

Cliente :: Cliente(int pos){
    this->pos = pos;
    this->comiendo = false;
    this->esperando = true;
}

Plato * Cliente :: tomarDecision(Peticion * peticion){
    switch (peticion->fase) {
        case PEDIRENTRADA:
            if(Random::Probabilidad(1000,tabla->entrada->probabilidad))
                return seleccionPlato(tabla->entrada->tipo);
            break;
        case PEDIDAPRINCIPAL:
            if(Random::Probabilidad(1000,tabla->plato->probabilidad))
                return seleccionPlato(tabla->plato->tipo);
            break;
        case PEDIRPOSTRE:
            if(Random::Probabilidad(1000,tabla->postre->probabilidad))
                return seleccionPlato(tabla->postre->tipo);
            break;
        default:
            break;//excepcion
    }
    return nullptr;
}

Plato * Cliente :: seleccionPlato(Tipo tipo){
    switch (tipo) {
        case ENTRADA:
            //MENU DE ENTRADA SELECCIONAR AL AZAR UNA ENTRADA
            break;
        case PLATO:
            break;
        case POSTRE:
            break;
    }
    return nullptr;
}

void Cliente :: comer(Peticion * peticion){
    switch (peticion->fase) {
        case COMIENDOENTRADA:
            break;
        case COMIENDOPRINCIPAL:
            break;
        case COMIENDOPOSTRE:
            break;
        default:
            break;

    }
}

void Cliente :: setComiendo(bool comiendo){
    this->comiendo = comiendo;
}

void Cliente :: setEsperando(bool esperando){
    this->esperando = esperando;
}

bool Cliente :: listo(){
    return esperando == true && comiendo == false;
}

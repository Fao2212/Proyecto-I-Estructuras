#include "Cliente.h"
#include "Peticion.h"
#include "TablaPlatos.h"
#include "Random.h"
#include "Globals.h"
#include "Menu.h"
Menu* menuglobal = menuglobal;
TablaPlatos * tablaglobal = tablaglobal;
//EL CLIENTE GUARDA EL PLATO QUE SELECCIONA Y ESPERA HASTA QUE LLEGA LA PETICION EN COMER
//eL THREAD USA EL COMER CON EL PLATO ACTUAL Y LUEGO LO BORRA, LO PONE EN NULL PUEDE LLAMARSE PLATO ACTUAL

Cliente :: Cliente(int pos){
    this->pos = pos;
    this->comiendo = false;
    this->esperando = true;
    this->tabla = tablaglobal;
    this->plato = nullptr;
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
            break;
    }
    return nullptr;
}

Plato * Cliente :: seleccionPlato(Tipo tipo){
    switch (tipo) {
        case ENTRADA:
            return menuglobal->platoAlAzar(tipo);
        case PLATO:
            return menuglobal->platoAlAzar(tipo);
        case POSTRE:
            return menuglobal->platoAlAzar(tipo);
    }
    return nullptr;
}

bool Cliente :: estaComiendo(){
    return comiendo == true && esperando == false;
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

bool Cliente :: quierePagar(){
    return comiendo == false && esperando == false;
}


#include "GrupoDeClientesBORRADOR.h"

GrupoDeClientes::GrupoDeClientes(){
    for(int i = 0;i<6;i++){
        this->grupo[i] = nullptr;
    }
    this->reserva = generarReserva();
    this->numeroDeGrupo = 1;
}

int GrupoDeClientes::groupSize(){
    int cont = 0;
    Cliente * comp;
    for(int i =0;i<6;i++){
        comp = this->grupo[i];
        if(comp!= nullptr)
            cont += 1;
    }
    return cont;
}

int GrupoDeClientes:: generarReserva(){
    return 1;
}

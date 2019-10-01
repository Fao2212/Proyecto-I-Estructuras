#include "GrupoDeClientesBORRADOR.h"
#include "Peticion.h"
#include "Cliente.h"

GrupoDeClientes::GrupoDeClientes(){
    for(int i = 0;i<6;i++){
        this->grupo[i] = nullptr;
    }
    this->reserva = generarReserva();
    this->numeroDeGrupo = 1;
    this->mesa = nullptr;

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

void GrupoDeClientes :: sentarEnMesa(Mesa * mesa){// Cuando se les asigne una mesa
    this->mesa = mesa;
    this->peticion = new Peticion(mesa,this->numeroDeGrupo);
}

void GrupoDeClientes :: generarOrden(){
    for(int i = 0;i < groupSize();i++){
        this->peticion->platos[i] = this->grupo[i]->tomarDecision(peticion);
    }
}

void GrupoDeClientes :: SetFasePeticion(Peticion * peticion){
    this->peticion = peticion;
}

bool GrupoDeClientes :: listoParaOrdenar(){
    for(int i = 0;i < groupSize();i++){
        if(grupo[i]->listo() == false)
            return false;
    }
    return true;
}

void GrupoDeClientes :: setTodosEsperando(bool esperando){
    for(int i =0;i<groupSize();i++){
        grupo[i]->setEsperando(esperando);
    }
}

void GrupoDeClientes :: setTodosComiendo(bool comiendo){
    for(int i =0;i<groupSize();i++){
        grupo[i]->setComiendo(comiendo);
    }
}

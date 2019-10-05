#include "GrupoDeClientesBORRADOR.h"
#include "Peticion.h"
#include "Mesa.h"
#include "Cliente.h"
#include "QtDebug"
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

void GrupoDeClientes :: sentarEnMesa(Mesa * mesa){
    this->mesa = mesa;
    this->peticion = new Peticion(mesa,this->numeroDeGrupo);
}

bool GrupoDeClientes :: generarOrden(){
    bool alguienPidio = false;
    for(int i = 0;i < groupSize();i++){
        Plato *p = this->grupo[i]->tomarDecision(peticion);
        if(p != nullptr)
            alguienPidio =true;
        this->peticion->platos[i] = p;
    }
    return alguienPidio;
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

void GrupoDeClientes :: pagarCuenta(){
    mesa->vaciarMesa();
}

bool GrupoDeClientes :: listoParaPagar(){//Cuidadito ehh
    for(int i = 0;i < groupSize();i++){
        if(grupo[i]->quierePagar() == true && peticion->fase == COBROCUENTA)
            return true;
    }
    return false;
}

bool GrupoDeClientes :: listoParaComer(){
    for(int i = 0;i < groupSize();i++){
        if(grupo[i]->estaComiendo() == false)
            return false;
    }
    return true;
}

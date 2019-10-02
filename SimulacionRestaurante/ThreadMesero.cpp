#include "ThreadMesero.h"
#include "Mesero.h"

ThreadMesero :: ThreadMesero(){

}

void ThreadMesero :: __init__(Mesero *mesero,QMutex * mutexEntrada){//Widgets y mutex
    this->pausa = false;
    this->activo = true;
    this->mesero = mesero;
    this->mutexEntrada = mutexEntrada;

}

void ThreadMesero :: run(){
    while(activo){

        if(mutexEntrada->tryLock()){
        mesero->atenderMesa();
        sleep(unsigned(mesero->tiempoDeServido));
        //Mesa atendida por mesero id, orden generada por el grupo,
        log->addItem("Mesa atendida");
        mutexEntrada->unlock();
        }
        if(mutexEntrada->tryLock()){
        mesero->siguientePeticion();
        sleep(unsigned(mesero->tiempoDeServido));
        mutexEntrada->unlock();
        }
        //Peticion revisada en camino a--->
        if(mutexEntrada->tryLock()){
        log->addItem("Peticion Atendida");
        mesero->checkCocinas();
        mutexEntrada->unlock();
        }
        sleep(unsigned(mesero->tiempoDeServido));
        if(mutexEntrada->tryLock()){
        log->addItem("Cocina revisada Atendida");
        mutexEntrada->unlock();
        }
        //Se toma una peticion de la cocina tal.
        while(pausa) {
            msleep(100);
        }
    }
}

void ThreadMesero ::pausar(){
    this->pausa = true;
}

void ThreadMesero ::continuar(){
    this->pausa = false;
}

#include "ThreadCocinero.h"
#include "Cocinero.h"
#include "Peticion.h"
#include "Plato.h"
#include "Utilidades.h"
#include "QString"
//Hacer un thread que solo validen la tabla de escritura otros para los contadores
ThreadCocinero :: ThreadCocinero(){

}

void ThreadCocinero :: __init__(Cocinero *cocinero, QListWidget *log, QMutex *mutexEntrada){
    this->cocinero = cocinero;
    this->log = log;
    this->mutexEntrada = mutexEntrada;
    this->pausa = false;
    this->activo = true;

}

void ThreadCocinero :: run(){
    while(activo){
        msleep(100);
        if(mutexEntrada->tryLock()){
            cocinar();
            mutexEntrada->unlock();
        }
        while(pausa){
            msleep(100);
        }
    }
}

void ThreadCocinero :: cocinar(){
    Peticion * peticion = cocinero->tomarOrden();
    if(peticion != nullptr){
        for(int i = 0;i < 6;i++){
            if(peticion->platos[i]!= nullptr){
                int tiempo = peticion->platos[i]->tiempoDePreparacion;
                //set del nombre del plato cocinando
                QString mensaje = Utilidades<void>::getTime() + ": El cocinero " + QString::number(cocinero->id) + " tomo la peticion y "+ peticion->faseActual();
                log->addItem(mensaje);
                sleep(unsigned(tiempo));
                cocinero->dejarOrden();
                mensaje = Utilidades<void>::getTime() + ": El cocinero " + QString::number(cocinero->id) + " tomo la peticion y "+ peticion->faseActual();
                log->addItem(mensaje);

            }
        }

    }
}

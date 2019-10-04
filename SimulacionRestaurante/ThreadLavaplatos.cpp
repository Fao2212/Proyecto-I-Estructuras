#include "ThreadLavaplatos.h"
#include "Lavaplatos.h"
#include "Peticion.h"
#include "Plato.h"
#include "Cola.h"
ThreadLavaplatos :: ThreadLavaplatos(){

}

void ThreadLavaplatos :: __init__(Lavaplatos *lavaplatos, QListWidget *log, QMutex *mutexEntrada){
    this->log = log;
    this->lavaplatos = lavaplatos;
    this->mutexEntrada = mutexEntrada;
    this->pausa = false;
    this->activo = true;
}

void ThreadLavaplatos :: run(){
    msleep(100);
    while (activo) {
        lavar();
        while (pausa) {
            msleep(100);

        }

    }
}

void ThreadLavaplatos :: lavar(){
    Peticion * peticion = lavaplatos->tomarPlato();
    if(peticion != nullptr){
        for(int i = 0;i < 6; i++){
            if(peticion->platos[i] != nullptr){
                QString mensaje = "El lavaplatos estara lavando por "+QString::number(peticion->platos[i]->tiempoDeLavado)+" segundos";
                sleep(unsigned(peticion->platos[i]->tiempoDeLavado));
                mensaje = "Lavadero ha terminado de lavar el plato";
                //set contador
                lavaplatos->atendidos += 1;
            }
            lavaplatos->peticiones->desencolar();
        }
    }

}

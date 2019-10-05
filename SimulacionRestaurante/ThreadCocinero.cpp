#include "ThreadCocinero.h"
#include "Cocinero.h"
#include "Peticion.h"
#include "Plato.h"
#include "Utilidades.h"
#include "GUIMensaje.h"
#include "QString"
//Hacer un thread que solo validen la tabla de escritura otros para los contadores
ThreadCocinero :: ThreadCocinero(){

}

void ThreadCocinero :: __init__(Cocinero *cocinero, ColaMensajes * mensajes, QMutex *mutexCocina){
    this->cocinero = cocinero;
    this->mutexCocina = mutexCocina;
    this->pausa = false;
    this->activo = true;
    this->mensajes = mensajes;

}

void ThreadCocinero :: run(){
    while(activo){
        msleep(100);
            cocinar();
        while(pausa){
            msleep(100);
        }
    }
}

void ThreadCocinero :: cocinar(){
    Peticion * peticion = nullptr;

    if(mutexCocina->tryLock()){
    peticion = cocinero->tomarOrden();
    mutexCocina->unlock();
    }
    if(peticion != nullptr){
        for(int i = 0;i < 6;i++){
            if(peticion->platos[i]!= nullptr){
                int tiempo = peticion->platos[i]->tiempoDePreparacion;
                QString mensaje = Utilidades<void>::getTime() + ": El cocinero " + QString::number(cocinero->id) + " tomo la peticion y "+ peticion->faseActual();
                mensajes->crearMensaje(COLORCOCINERO,mensaje);
                sleep(unsigned(tiempo));
                mensaje = Utilidades<void>::getTime() + ": El cocinero " + QString::number(cocinero->id) + " tomo la peticion y "+ peticion->faseActual();
                mensajes->crearMensaje(COLORCOCINERO,mensaje);

            }
        }
        cocinero->dejarOrden();

    }
}

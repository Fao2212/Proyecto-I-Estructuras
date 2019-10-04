#include "ThreadMesero.h"
#include "Mesero.h"
#include "Mesa.h"
#include "QDateTime"
#include "Utilidades.h"
#include "Peticion.h"
#include "GUIMensaje.h"

ThreadMesero :: ThreadMesero(){

}

void ThreadMesero :: __init__(Mesero *mesero,QMutex * mutexEntrada,ColaMensajes * mensajes){//Widgets y mutex
    this->pausa = false;
    this->activo = true;
    this->mesero = mesero;
    this->mutexEntrada = mutexEntrada;
    this->mensajes = mensajes;

}

void ThreadMesero :: run(){
    while(activo){
            msleep(100);
            pudoAtender();
            tomoPeticion();
            llevoPeticion();
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

void ThreadMesero :: pudoAtender(){
    Mesa * mesa = mesero->atenderMesa();
    //Set del estatus actual con esta mesa y con la peticion
    if(mesa != nullptr){
        sleep(unsigned(mesero->tiempoDeServido));//Multiplicar el tiempo de cada cliente
        QString mensaje =": El mesero " + QString::number(mesero->id) + " atendio la mesa #"+ QString::number(mesa->numeroDeMesa);
        mensajes->crearMensaje(COLORMESERO,mensaje);

    }
}

void ThreadMesero :: tomoPeticion(){
    Peticion * peticion = mesero->siguientePeticion();
    if(peticion != nullptr){
        sleep(unsigned(mesero->tiempoDeServido));
        QString mensaje =": El mesero " + QString::number(mesero->id) + " tomo la peticion y "+ peticion->faseActual();
        mensajes->crearMensaje(COLORMESERO,mensaje);
    }

}

void ThreadMesero :: llevoPeticion(){
    Peticion * peticion = mesero->checkCocinas();
    if(peticion != nullptr){
        sleep(unsigned(mesero->tiempoDeServido));
        QString mensaje = Utilidades<void>::getTime() + ": El mesero " + QString::number(mesero->id) + " tomo la peticion y "+ peticion->faseActual();
        mensajes->crearMensaje(COLORMESERO,mensaje);
    }
}
//posibilidad de que ninguno pida nada

#include "ThreadCajero.h"
#include "Peticion.h"
#include "Cajero.h"
#include "QString"
#include "Mesa.h"
//Primero lock toma la peticion liuego unlock luego sleep
ThreadCajero :: ThreadCajero (){

}

void ThreadCajero :: __init__(Cajero *cajero, QListWidget *log, QMutex *mutexEntrada){
    this->log = log;
    this->activo = true;
    this->pausa = false;
    this->cajero = cajero;
    this->mutexEntrada = mutexEntrada;
}

void ThreadCajero :: run(){
    msleep(100);
    while (activo) {
        cobrar();
        while (pausa) {
            msleep(100);
        }
    }
}

void ThreadCajero :: cobrar(){
    Peticion * peticion = cajero->tomarCuenta();
    if(peticion != nullptr){
        QString mensaje = "El cajero esta haciendo el cobro de la peticion de la mesa#" + QString::number(peticion->mesa->numeroDeMesa);
        sleep(unsigned(cajero->tiempo));
        cajero->hacerCobro();
        mensaje = "Cobro realizado";
    }
}

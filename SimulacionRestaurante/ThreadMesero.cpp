#include "ThreadMesero.h"
#include "Cola.h"
#include "Mesero.h"
#include "Mesa.h"
#include "QDateTime"
#include "Utilidades.h"
#include "Peticion.h"
#include "GUIMensaje.h"
#include "GrupoDeClientesBORRADOR.h"
#include "Cocina.h"
#include "Cliente.h"

ThreadMesero :: ThreadMesero(){

}

void ThreadMesero :: __init__(Mesero * mesero,QMutex * mutexColaCajero,QMutex * mutexColaLavadero,QMutex * mutexColaCocinaPostre
                              ,QMutex * mutexColaCocinaEntrada,QMutex * mutexColaCocinaPrincipal,ColaMensajes * mensajes){//Widgets y mutex
    this->pausa = false;
    this->activo = true;
    this->mesero = mesero;
    this->mutexColaCajero = mutexColaCajero;
    this->mutexColaLavadero = mutexColaLavadero;
    this->mutexColaCocinaPostre = mutexColaCocinaPostre;
    this->mutexColaCocinaEntrada = mutexColaCocinaEntrada;
    this->mutexColaCocinaPrincipal = mutexColaCocinaPrincipal;
    this->mensajes = mensajes;

}

void ThreadMesero :: run(){
    while(activo){
            msleep(100);
            pudoAtender();
            tomoPeticion();
            revisarCocina();
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
    if(mesa != nullptr){
        int i = 0;
        sleep(unsigned(mesero->tiempoDeServido));
        while (i < mesa->grupo->groupSize()) {
            QString mensaje =": El mesero " + QString::number(mesero->id) + " esta atendiendo al cliente # "+ QString::number(mesa->grupo->grupo[i]->pos+1);
            mensajes->crearMensaje(COLORMESERO,mensaje);
            sleep(unsigned(mesero->tiempoDeServido));
            if(mesa->grupo->peticion->platos[i] != nullptr)
                mensaje ="El cliente # "+ QString::number(mesa->grupo->grupo[i]->pos) +" ordeno " + mesa->grupo->grupo[i]->plato->nombre;
            else
                mensaje ="El cliente # "+ QString::number(mesa->grupo->grupo[i]->pos) +" no ordeno";
            mensajes->crearMensaje(COLORCLIENTE,mensaje);
            i++;
        }
       QString mensaje =": El mesero " + QString::number(mesero->id) + " atendio la mesa # "+ QString::number(mesa->numeroDeMesa)+
                "con un tiempo de servicio de  "+QString::number(unsigned(mesero->tiempoDeServido*mesa->grupo->groupSize()))+" segundos";
        mensajes->crearMensaje(COLORMESERO,mensaje);

    }
}

void ThreadMesero :: tomoPeticion(){
    if(mesero->peticiones->siguienteEnCola() != nullptr){
        Peticion * peticion = mesero->peticiones->siguienteEnCola()->dato;
        switch (peticion->fase) {
            case COCINAENTRADA:
                quickQueue(mutexColaCocinaEntrada);
                break;
            case COCINAPRINCIPAL:
                quickQueue(mutexColaCocinaPrincipal);
                break;
            case COCINAPOSTRE:
                quickQueue(mutexColaCocinaPostre);
                break;
            case LAVARPOSTRE:
                quickQueue(mutexColaLavadero);//Me preocupaa que no pueda lavar
                break;
            case LAVARPRINCIPAL:
                quickQueue(mutexColaLavadero);
                break;
            case LAVADAENTRADA:
                quickQueue(mutexColaLavadero);
                break;
            case CUENTAACAJA:
                quickQueue(mutexColaCajero);
                break;
            default:
                sleep(unsigned(mesero->tiempoDeServido));
                mesero->siguientePeticion();
                QString mensaje =": El mesero " + QString::number(mesero->id) + " tomo la peticion y "+ peticion->faseActual();
                mensajes->crearMensaje(COLORMESERO,mensaje);
            break;
        }
    }
}

void  ThreadMesero :: quickQueue(QMutex * mutex){
    sleep(unsigned(mesero->tiempoDeServido));
    if(mutex->tryLock()){
        Peticion * peticion = mesero->siguientePeticion();
        mutex->unlock();
        QString mensaje =": El mesero " + QString::number(mesero->id) + " tomo la peticion y "+ peticion->faseActual();
        mensajes->crearMensaje(COLORMESERO,mensaje);
    }
}

void ThreadMesero:: revisarCocina(){
    if(mesero->cocinaEntrada->salida->siguienteEnCola() != nullptr){
        quickDraw(mesero->cocinaEntrada,mutexColaCocinaEntrada);
    }
    if(mesero->cocinaPrincipal->salida->siguienteEnCola() != nullptr){
        quickDraw(mesero->cocinaPrincipal,mutexColaCocinaPrincipal);
    }
    if(mesero->cocinaPostres->salida->siguienteEnCola() != nullptr){
        quickDraw(mesero->cocinaPostres,mutexColaCocinaPostre);
    }
}

void ThreadMesero :: quickDraw(Cocina * cocina,QMutex * mutex){
    if(cocina->salida->siguienteEnCola() != nullptr){
        if(mutex->tryLock()){
            if(mesero->validarMesa(cocina->salida->siguienteEnCola()->dato)){
                mesero->recogerOrden(cocina->salida->siguienteEnCola()->dato);
                mesero->peticiones->encolar(cocina->salida->desencolar()->dato);
                qDebug()<<"Quickdraw";
                qDebug()<<mesero->peticiones->siguienteEnCola()->dato->faseMensaje();
                mutex->unlock();
                sleep(unsigned(mesero->tiempoDeServido));
                QString mensaje =": El mesero " + QString::number(mesero->id) + " tomo la peticion y "+ mesero->peticiones->siguienteEnCola()->dato->faseActual();
                mensajes->crearMensaje(COLORMESERO,mensaje);
            }
            else{
                qDebug()<<"Nicoyano";
                mutex->unlock();
            }
        }
    }
}



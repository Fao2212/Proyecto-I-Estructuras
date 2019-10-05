#include "ThreadCliente.h"
#include "GrupoDeClientesBORRADOR.h"
#include "Cliente.h"
#include "TablaPlatos.h"
#include "QString"
#include "GUIMensaje.h"
#include "Peticion.h"

ThreadCliente :: ThreadCliente(){

}
ThreadCliente :: ~ThreadCliente(){

}
void ThreadCliente ::comer(){
    unsigned tiempoTotal = 0;
    unsigned tiempoComiendo = 0;
    for(int i = 0;i< grupo->groupSize();i++){
        if(grupo->grupo[i]->plato != nullptr){
            tiempoComiendo = unsigned(grupo->grupo[i]->tabla->darTiempo(grupo->grupo[i]->plato->tipo));
            QString mensaje = "El cliente " + QString::number(grupo->grupo[i]->pos) + " va a comer " + grupo->grupo[i]->plato->nombre;
            mensajes->crearMensaje(COLORCLIENTE,mensaje);
            tiempoTotal += tiempoComiendo;
        }
    }
    sleep(tiempoComiendo);
    QString mensaje = "El grupo " + QString::number(grupo->numeroDeGrupo) + " ha terminado de comer";
    mensajes->crearMensaje(COLORCLIENTE,mensaje);

    grupo->setTodosComiendo(false);
    grupo->setTodosEsperando(true);

}

void ThreadCliente :: run(){
    while (activo) {
        msleep(100);
        if(grupo->listoParaComer()){
            fasesComiendo(grupo->peticion);
            comer();
            fasesTerminandoComer(grupo->peticion);
        }
        if(grupo->listoParaPagar()){
            //grupo->pagarCuenta(); Si se llega a ir antes de que llegue el mesero se cae
            //Destruir el thread ARREGLAR LA CONDICION DE SALIDA
        }
        while (pausa) {
            msleep(100);
        }
    }


}

void ThreadCliente :: __init__(GrupoDeClientes *grupo, ColaMensajes *mensajes){
    this->grupo = grupo;
    this->mensajes = mensajes;
    this->pausa = false;
    this->activo = true;
}

void ThreadCliente :: fasesComiendo(Peticion * peticion){
    switch (peticion->fase) {
    case ENTREGAENTRADA:
        peticion->setFase(COMIENDOENTRADA);
        break;
    case ENTREGAPRINCIPAL:
        peticion->setFase(COMIENDOPRINCIPAL);
        break;
    case ENTREGAPOSTRE:
        peticion->setFase(COMIENDOPOSTRE);
        break;
    default:
        qDebug()<<"ERROR antes de comer";
    }
}

void ThreadCliente:: fasesTerminandoComer(Peticion * peticion){
    switch (peticion->fase) {
    case COMIENDOENTRADA:
        peticion->setFase(COCINAPRINCIPAL);
        break;
    case COMIENDOPRINCIPAL:
        peticion->setFase(COCINAPOSTRE);
        break;
    case COMIENDOPOSTRE:
        peticion->setFase(COBROCUENTA);
        break;
    default:
        qDebug()<<"ERROR despues de comer";
    }
}

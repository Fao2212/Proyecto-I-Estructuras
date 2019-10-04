#include "ThreadCliente.h"
#include "GrupoDeClientesBORRADOR.h"
#include "Cliente.h"
#include "TablaPlatos.h"
#include "QString"

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
            tiempoTotal += tiempoComiendo;
            //Aqui se puede anadir el contador de cada cliente si se quisiera
        }
    }
    sleep(tiempoComiendo);
    QString mensaje = "El grupo " + QString::number(grupo->numeroDeGrupo) + " ha terminado de comer";
    grupo->setTodosComiendo(false);
    grupo->setTodosEsperando(true);

}

void ThreadCliente :: run(){
    while (activo) {
        msleep(100);
        if(grupo->listoParaComer()){
            comer();
        }
        if(grupo->listoParaPagar()){
            grupo->pagarCuenta();
            //Destruir el thread
        }
        while (pausa) {
            msleep(100);
        }
    }


}

void ThreadCliente :: __init__(GrupoDeClientes *grupo, QListWidget *log, QMutex *mutexEntrada){
    this->grupo = grupo;
    this->log = log;
    this->mutexEntrada = mutexEntrada;
    this->pausa = false;
    this->activo = true;
}


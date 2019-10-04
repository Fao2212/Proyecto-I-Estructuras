#include "ThreadMensaje.h"
#include"Cola.h"
#include "QListWidget"
#include "GUIMensaje.h"

ThreadMensaje :: ThreadMensaje(){

}

void ThreadMensaje :: __init__(ColaMensajes *cola, QListWidget *log){
    this->mensajes = cola;
    this->log = log;
    this->activo = true;
}

void ThreadMensaje :: run(){
    msleep(100);
    while(activo){
        leer();
        while(pausa){
            msleep(100);
        }
    }
}

void ThreadMensaje :: leer(){
    if(mensajes->colaDeMensajes->siguienteEnCola()!=nullptr){
        QListWidgetItem * item = mensajes->imprimirSiguiente();
        log->addItem(item);
    }
}

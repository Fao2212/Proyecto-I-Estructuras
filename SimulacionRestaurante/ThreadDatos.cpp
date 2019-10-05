#include "ThreadDatos.h"
#include "Mesero.h"
#include "Restaurante.h"
#include "ListaSimple.h"

ThreadDatos :: ThreadDatos(){

}

void ThreadDatos :: __init__(Restaurante * restaurante,QLabel * labelStatus){
    this->labelStatus = labelStatus;
    this->activo = true;
    this->restaurante = restaurante;
    this->pausa = false;
}

void ThreadDatos :: run(){
    while (activo) {
        msleep(100);
        imprimirDatos(this->labelStatus);
        while (pausa) {
            msleep(100);
        }
    }
}
void ThreadDatos :: imprimirDatos(QLabel *widgetAUsar){
        widgetAUsar->setText(restaurante->meseros->indexSearch(1)->dato->mostrarCola(1));
    }



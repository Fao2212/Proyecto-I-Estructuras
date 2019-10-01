#include "ThreadEntradaRestaurante.h"
#include "Random.h"
#include "GrupoDeClientesBORRADOR.h"
#include "Mesa.h"

ThreadEntradaRestaurante :: ThreadEntradaRestaurante(){}

void ThreadEntradaRestaurante :: run(){
    while(activo){
        int tiempo = Random::RandomRange(entrada->tiempoDeGeneracionMinimo,entrada->tiempoDeGeneracion);
        qDebug()<<"a dormir";
        sleep(unsigned(tiempo));
        GrupoDeClientes * grupo = entrada->crearGrupo();
        entrada->asignarGrupo(grupo);
        qDebug()<<grupo->mesa;
        if(grupo->mesa!=nullptr){
            QString mensaje = "Se ha generado un grupo de "+ QString::number(grupo->groupSize()) +" personas para la mesa # " + QString::number(grupo->mesa->numeroDeMesa);
            logRestaurante->addItem(mensaje);
        }
        else{
            QString mensajeCola = "Se ha encolado el grupo #"+ QString::number(entrada->consecutivoDeGrupos) +" de " + QString::number(grupo->groupSize()) + " personas";
            logRestaurante->addItem(mensajeCola);
        }
        while(pausa){
            sleep(1);
        }
    }
}

void ThreadEntradaRestaurante :: __init__(EntradaDelRestaurante * entrada,QListWidget * logRestaurante){
    this->entrada = entrada;
    this->pausa = false;
    this->activo = true;
    this->logRestaurante = logRestaurante;

}

void ThreadEntradaRestaurante :: pausar(){
    this->pausa = true;
}

void ThreadEntradaRestaurante :: continuar(){
    this->pausa = false;
}

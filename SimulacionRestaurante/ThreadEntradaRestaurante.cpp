#include "ThreadEntradaRestaurante.h"
#include "Random.h"
#include "GrupoDeClientesBORRADOR.h"
#include "Mesa.h"
#include "GUIMensaje.h"
//Mas de un mutex, uno para la pantalla
ThreadEntradaRestaurante :: ThreadEntradaRestaurante(){}

void ThreadEntradaRestaurante :: run(){
    while(activo){
        msleep(100);
        int tiempo = Random::RandomRange(entrada->tiempoDeGeneracionMinimo,entrada->tiempoDeGeneracion);
        for(int i = tiempo;i > -1;i--){
            contador->setNum(i);
            sleep(1);
        }
        GrupoDeClientes * grupo = entrada->crearGrupo();
        entrada->asignarGrupo(grupo);
        if(grupo->mesa!=nullptr){
            QString mensaje = "Se ha generado un grupo de "+ QString::number(grupo->groupSize()) +" personas para la mesa # " + QString::number(grupo->mesa->numeroDeMesa)
                    +" en " + QString::number(tiempo)+ " segundos";
            mensajes->crearMensaje(COLORENTRADA,mensaje);

        }
        else{
            QString mensajeCola = "Se ha encolado el grupo #"+ QString::number(entrada->consecutivoDeGrupos) +" de " + QString::number(grupo->groupSize()) + " personas";
            mensajes->crearMensaje(COLORENTRADA,mensajeCola);
        }
        while(pausa){
            msleep(100);
        }
    }
}

void ThreadEntradaRestaurante :: __init__(EntradaDelRestaurante * entrada,QListWidget * logRestaurante,QLabel * contador
                                          ,ColaMensajes * mensajes){
    this->entrada = entrada;
    this->pausa = false;
    this->activo = true;
    this->logRestaurante = logRestaurante;
    this->contador = contador;
    this->mensajes = mensajes;

}

void ThreadEntradaRestaurante :: pausar(){
    this->pausa = true;
}

void ThreadEntradaRestaurante :: continuar(){
    this->pausa = false;
}

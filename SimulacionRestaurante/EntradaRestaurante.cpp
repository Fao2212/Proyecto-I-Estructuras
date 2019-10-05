#include "EntradaRestaurante.h"
#include "GrupoDeClientesBORRADOR.h"
#include "Random.h"
#include "Cliente.h"
#include "Estado.h"
#include "ListaSimple.h"
#include "QDebug"
#include "Mesa.h"
#include "Cola.h"
#include "ThreadCliente.h"


EntradaDelRestaurante::EntradaDelRestaurante(int maximoDeGenerados,int tiempoDeGeneracionMinimo,int tiempoDeGeneracionMaximo,
                                             Mesa * matriz[5][4],int cantidadDeMesas,ColaMensajes * mensajes){
    this->estado = new Estado();
    this ->maximoDeGenerados = maximoDeGenerados;
    this ->tiempoDeGeneracion = tiempoDeGeneracionMaximo;
    this->tiempoDeGeneracionMinimo = tiempoDeGeneracionMinimo;
    this-> consecutivoDeClientes = 0;
    this->consecutivoDeGrupos = 0;
    copiarMatriz(matriz);
    this->cantidadDeMesas = cantidadDeMesas;
    this->espera = new Cola<GrupoDeClientes>();
    this->mensajes = mensajes;
    this->clientes = new ListaSimple<ThreadCliente>();
}

GrupoDeClientes * EntradaDelRestaurante::crearGrupo(){

    int generados = Random::Random1(1000,maximoDeGenerados);//Sustituir el 1000 por un seed nombre rest * mesas /meseros * fecha + time 0
    GrupoDeClientes * grupo = new GrupoDeClientes();
    for(int i = 0; i < generados ;i++){
        grupo->grupo[i] = new Cliente(consecutivoDeClientes);
        this->consecutivoDeClientes += 1;
    }
    this->consecutivoDeGrupos += 1;
    return grupo;

}

void EntradaDelRestaurante :: asignarGrupo(GrupoDeClientes *grupo){

    Mesa * mesa = seleccionMesa();
    if(mesa != nullptr){
        mesa->llenarMesa(grupo);
        crearThreadCliente(grupo);
    }
    else
        espera->encolar(grupo);

}

Mesa * EntradaDelRestaurante ::seleccionMesa(){

     Random::Shuffle(this->mesas,this->cantidadDeMesas);
     for(int i = 0;i < cantidadDeMesas;i++){
         if(mesas[i]->estaVacia())
             return mesas[i];
     }
     return nullptr;
}


void EntradaDelRestaurante :: copiarMatriz(Mesa * matriz[5][4]){
    int k = 0;
    for(int i = 0;i<5;i++){
        for(int j = 0;j<4;j++){
            if(matriz[i][j]!=nullptr){
                this->mesas[k] = matriz[i][j];
                k++;
            }
        }
    }
}

void EntradaDelRestaurante :: mesaLiberada(){
   Mesa * mesa = seleccionMesa();
   if(mesa != nullptr)
       mesa->llenarMesa(espera->desencolar()->dato);
}

void EntradaDelRestaurante :: crearThreadCliente(GrupoDeClientes * grupo){
    ThreadCliente * threadCliente = new ThreadCliente();
    threadCliente->__init__(grupo,this->mensajes);
    this->clientes->insertar(threadCliente);
    threadCliente->start();
}

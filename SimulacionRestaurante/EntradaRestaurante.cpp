#include "EntradaRestaurante.h"
#include "GrupoDeClientesBORRADOR.h"
#include "Random.h"
#include "Cliente.h"
#include "Estado.h"
#include "QDebug"
#include "Mesa.h"
#include "Cola.h"


EntradaDelRestaurante::EntradaDelRestaurante(int maximoDeGenerados,int tiempoDeGeneracionMinimo,int tiempoDeGeneracionMaximo,
                                             Mesa * matriz[5][4],int cantidadDeMesas){
    this->estado = new Estado();
    this ->maximoDeGenerados = maximoDeGenerados;
    this ->tiempoDeGeneracion = tiempoDeGeneracionMaximo;
    this->tiempoDeGeneracionMinimo = tiempoDeGeneracionMinimo;
    this-> consecutivoDeClientes = 0;
    this->consecutivoDeGrupos = 0;
    copiarMatriz(matriz);
    this->cantidadDeMesas = cantidadDeMesas;
    this->espera = new Cola<GrupoDeClientes>();
}

GrupoDeClientes * EntradaDelRestaurante::crearGrupo(){

    int generados = Random::Random1(1000,maximoDeGenerados);//Sustituir el 1000 por un seed nombre rest * mesas /meseros * fecha + time 0
    GrupoDeClientes * grupo = new GrupoDeClientes();
    for(int i = 0; i < generados ;i++){
        grupo->grupo[i] = new Cliente(consecutivoDeClientes);
    }
    this->consecutivoDeGrupos += 1;
    return grupo;

}

void EntradaDelRestaurante :: asignarGrupo(GrupoDeClientes *grupo){

    Mesa * mesa = seleccionMesa();
    qDebug()<<mesa;
    if(mesa != nullptr)
        mesa->llenarMesa(grupo);
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
/*int main(int argc, char *argv[])
{
    EntradaDelRestaurante * eR = new EntradaDelRestaurante(new Estado(),6,2);
    GrupoDeClientes * gC = eR->crearGrupo();
    qDebug() << gC->groupSize();
    return 0;
}*/


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

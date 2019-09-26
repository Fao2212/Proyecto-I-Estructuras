#include "EntradaRestaurante.h"
#include "GrupoDeClientesBORRADOR.h"
#include "Random.h"
#include "Cliente.h"
#include "Estado.h"
#include "QDebug"
#include "Mesa.h"

EntradaDelRestaurante::EntradaDelRestaurante(Estado * estado,int maximoDeGenerados,int tiempoDeGeneracion){
    this->estado = estado;
    this ->maximoDeGenerados = maximoDeGenerados;
    this ->tiempoDeGeneracion = tiempoDeGeneracion;
    this-> consecutivoDeClientes = 0;
}

GrupoDeClientes * EntradaDelRestaurante::crearGrupo(){

    int generados = Random::Random1(1000,maximoDeGenerados);//Sustituir el 1000 por un seed nombre rest * mesas /meseros * fecha + time 0
    GrupoDeClientes * grupo = new GrupoDeClientes();
    for(int i = 0; i < generados ;i++){
        this->consecutivoDeClientes += 1;
        grupo->grupo[i] = new Cliente(consecutivoDeClientes);
    }
    return grupo;

}

void EntradaDelRestaurante :: asignarGrupo(GrupoDeClientes *grupo){

    Mesa * mesa;//=random Mesa
    mesa->llenarMesa(grupo);//Mesa tiene que estar vacia, mesa dentro de una matriz,

}

Mesa * EntradaDelRestaurante ::seleccionMesa(){
    int i = 0;
    //while(i < cantidadDeMesas && mesa->estaVacia())
        //Mesa * mesa = Matriz de mesa[][] o una lilsta
        //return mesa; Creo que esto seria mejor si va en el hilo
    return nullptr;
}
/*int main(int argc, char *argv[])
{
    EntradaDelRestaurante * eR = new EntradaDelRestaurante(new Estado(),6,2);
    GrupoDeClientes * gC = eR->crearGrupo();
    qDebug() << gC->groupSize();
    return 0;
}*/



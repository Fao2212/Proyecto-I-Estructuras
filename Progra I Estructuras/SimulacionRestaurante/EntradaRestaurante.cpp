#include "EntradaRestaurante.h"
#include "GrupoDeClientesBORRADOR.h"
#include "Random.h"
#include "Cliente.h"
#include "Estado.h"
#include "QDebug"

EntradaDelRestaurante::EntradaDelRestaurante(Estado * estado,int maximoDeGenerados,int tiempoDeGeneracion){
    this->estado = estado;
    this ->maximoDeGenerados = maximoDeGenerados;
    this ->tiempoDeGeneracion = tiempoDeGeneracion;
    this->totalDeGenerados = 0;
}

GrupoDeClientes * EntradaDelRestaurante::crearGrupo(){

    int generados = Random::Random1(1000,maximoDeGenerados);
    this->totalDeGenerados += generados;
    GrupoDeClientes * grupo = new GrupoDeClientes();
    for(int i = 0; i < generados ;i++){
        grupo->grupo[i] = new Cliente(2);
    }
    return grupo;

}

int main(int argc, char *argv[])
{
    EntradaDelRestaurante * eR = new EntradaDelRestaurante(new Estado(),6,2);
    GrupoDeClientes * gC = eR->crearGrupo();
    qDebug() << gC->groupSize();
    return 0;
}

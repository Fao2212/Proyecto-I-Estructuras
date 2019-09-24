#include "Peticion.h"
#include "Estado.h"
#include "GrupoDeClientesBORRADOR.h"

Peticion::Peticion(Mesa * mesa,Estado * estado,int grupo){

    this->fase = 1;
    this->tiempo = 111111;
    this->mesa = mesa;
    this->estado = estado;
    this->responsable = "clientes";
    this->grupo = grupo;


}

#include "Peticion.h"
#include "Estado.h"
#include "GrupoDeClientesBORRADOR.h"
#include "Plato.h"
#include "Mesa.h"

Peticion::Peticion(Mesa * mesa,int grupo){

    this->fase = CREADA;
    this->mesa = mesa;
    this->grupo = grupo;

}

void Peticion :: setFase(Fase state){
    this->fase = state;
}

QString Peticion :: platosActuales(){
    QString mensaje = "";
    for(int i = 0; i < 6;i++){
        if( platos[i] != nullptr){
            QString plato = this->platos[i]->nombre;
            mensaje += plato + "\n";
        }
    }
    return mensaje;
}

QString Peticion :: faseActual(){
    QString mensaje = "";
    switch (fase) {
    case CREADA:
        mensaje = "Peticion sin atender";
        break;
    case PEDIRENTRADA:
        mensaje = "se dirige a la cocina de entradas";
        break;
    case COCINAENTRADA:
        mensaje = "se dirige a la cocina de entradas";
        break;
    case COCINANDOENTRADA:
        mensaje = "esta cocinando el plato de entrada";
        break;
    case ENTRADATERMINADA:
        mensaje = "El plato de entrada esta listo!";
        break;
    case ENTREGAENTRADA:
        mensaje = "se dirige a la mesa #"+QString::number(mesa->numeroDeMesa)+" para entregar los platos de entrada";
        break;
    case COMIENDOENTRADA:
        mensaje = "esta comiendo el plato de entrada";
        break;
    case LAVADAENTRADA:
        mensaje = "se dirige al lavadero";
        break;
    case PEDIDAPRINCIPAL:
        mensaje = "se dirige a la cocina principal";
        break;
    case COCINAPRINCIPAL:
        mensaje = "se dirige a la cocina principal";
        break;
    case COCINANDOPRINCIPAL:
        mensaje = "esta cocinando el plato principal";
        break;
    case PRINCIPALTERMINADA:
        mensaje = "el plato de entrada esta listo!";
        break;
    case ENTREGAPRINCIPAL:
        mensaje = "se dirige a la mesa #"+QString::number(mesa->numeroDeMesa)+" para entregar los platos principales";
        break;
    case COMIENDOPRINCIPAL:
        mensaje = "esta comiendo el plato principal";
        break;
    case LAVARPRINCIPAL:
        mensaje = "se dirige al lavadero";
        break;
    case PEDIRPOSTRE:
        mensaje = "se dirige a la cocina de postres";
        break;
    case COCINAPOSTRE:
        mensaje = "se dirige a la cocina de postres";
        break;
    case COCINANDOPOSTRE:
        mensaje = "esta cocinando el plato de postre";
        break;
    case POSTRETERMINADO:
        mensaje = "el plato de postre esta listo!";
        break;
    case ENTREGAPOSTRE:
        mensaje = "se dirige a la mesa #"+QString::number(mesa->numeroDeMesa)+" para entregar los platos de postre";
        break;
    case COMIENDOPOSTRE:
        mensaje = "esta comiendo el plato de postre";
        break;
    case COBROCUENTA:
        mensaje = "se cobra al grupo de clientes #";
        break;
    case LAVARPOSTRE:
        mensaje = "se dirige al lavadero";
        break;
    case CUENTAACAJA:
        mensaje = "se dirige a la caja";
        break;
    }
    return mensaje;
}

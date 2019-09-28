#include "Mesero.h"
#include "Peticion.h"
#include "ListaSimple.h"
#include "Mesa.h"
#include "Utilidades.h"
#include "GrupoDeClientesBORRADOR.h"
#include "Cola.h"
#include "CocinaEnsaladas.h"
#include "CocinaPrincipal.h"
#include "CocinaPostres.h"
#include "Lavadero.h"
#include "Caja.h"
#include "Peticion.h"

Mesero :: Mesero(int mesas,Mesa array [],CocinaPrincipal cocinaPrincipal,CocinaEnsaladas cocinaEntrada,CocinaPostres cocinaPostres
                 ,int tiempoDeServido,int tiempoDeEntrega){


}

bool Mesero :: validarMesa(Peticion * peticion){
    for(int i = 0;i < Utilidades<Mesa*>::arraySize(mesasAsignadas) ;i++){
        if(mesasAsignadas[i] == peticion->mesa){//Revision de comparacion
            return true;
        }
    }
    return false;
}

void Mesero :: recogerOrden(Peticion * peticion){
    peticiones->encolar(peticion);
}

void Mesero :: llevarLavar(){
    lavadero->peticiones->encolar(peticiones->desencolar());
}

void Mesero :: entregarCuenta(){
    caja->peticiones->encolar(peticiones->desencolar());
}

void Mesero :: llevarPeticion(Fase fase){
    switch(fase){
    case COCINAENTRADA:
        cocinaEntrada->peticiones->encolar(peticiones->desencolar());
        break;
    case COCINAPRINCIPAL:
        cocinaPrincipal->peticiones->encolar(peticiones->desencolar());
        break;
    case COCINAPOSTRE:
        cocinaPostres->peticiones->encolar(peticiones->desencolar());
        break;
    default:
        break;//Exeption
    }
}

void Mesero :: atenderPeticion(Peticion * peticion){
    switch (peticion->fase) {
        case COCINAENTRADA:
            llevarPeticion(COCINAENTRADA);
            break;
        case ENTREGAENTRADA:
            dejarOrden();
            break;
        case LAVADAENTRADA:
            llevarLavar();
            break;
        case COCINAPRINCIPAL:
            llevarPeticion(COCINAPRINCIPAL);
            break;
        case ENTREGAPRINCIPAL:
            dejarOrden();
            break;
        case LAVARPRINCIPAL:
            llevarLavar();
            break;
        case COCINAPOSTRE:
            llevarPeticion(COCINAPOSTRE);
            break;
        case ENTREGAPOSTRE:
            dejarOrden();
            break;
        case COBROCUENTA:
            cobrarCuenta();
            break;
        case LAVARPOSTRE:
            llevarLavar();
            break;
        case CUENTAACAJA:
            entregarCuenta();
            break;
        default:
            break;//exepcioomn

    }
}
//Cuando toma la orden set esperando en false y cuando entrega la orden set esperando en true y comiendo en true
void Mesero :: atenderMesa(){//Recorrer lista y ver si estan comiendo sino tomar orden
    for(int i = 0;i < Utilidades<Mesa*>::arraySize(mesasAsignadas) ;i++){
        if(mesasAsignadas[i]->necesitaMesero()){
            tomarOrden(mesasAsignadas[i]);//esperar tiempo mesero * #clientes
        }
    }
}

void Mesero :: checkCocinas(){

    if(cocinaEntrada->salida->siguienteEnCola() != nullptr)
        recogerOrden(cocinaEntrada->salida->desencolar());
    else if (cocinaPostres->salida->siguienteEnCola() != nullptr)
        recogerOrden(cocinaPrincipal->salida->desencolar());
    else if (cocinaPrincipal->salida->siguienteEnCola() != nullptr)
        recogerOrden(cocinaPostres->salida->desencolar());
}

void Mesero :: tomarOrden(Mesa * mesa){
    mesa->grupo->generarOrden();
    peticiones->encolar(mesa->grupo->peticion);
    mesa->grupo->setTodosEsperando(false);
}

void Mesero :: siguientePeticion(){
   Peticion * peticion = peticiones->siguienteEnCola();
   if(peticion != nullptr){
       if(peticion->fase == CREADA)
         peticion->setFase(COCINAENTRADA);
       else
        atenderPeticion(peticion);
   }
}

void Mesero :: dejarOrden(){
    peticiones->primerNodo->dato.mesa->grupo->peticion = peticiones->desencolar();
}

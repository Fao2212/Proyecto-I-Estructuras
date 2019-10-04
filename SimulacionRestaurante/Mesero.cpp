#include "Mesero.h"
#include "Peticion.h"
#include "ListaSimple.h"
#include "Mesa.h"
#include "Utilidades.h"
#include "GrupoDeClientesBORRADOR.h"
#include "Cola.h"
#include "Cocina.h"
#include "Lavadero.h"
#include "Caja.h"


Mesero :: Mesero(Cocina * cocinaPrincipal,Cocina * cocinaEntrada,Cocina * cocinaPostres
                 ,int tiempoDeServido){

    this->tiempoDeServido = tiempoDeServido;
    this->cocinaEntrada = cocinaEntrada;
    this->cocinaPostres = cocinaPostres;
    this->cocinaPrincipal = cocinaPrincipal;
    this->peticiones = new Cola<Peticion>();

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
    switch (peticiones->siguienteEnCola()->dato->fase) {
        case ENTRADATERMINADA:
        peticiones->siguienteEnCola()->dato->setFase(ENTREGAENTRADA);
        break;
    case PRINCIPALTERMINADA:
        peticiones->siguienteEnCola()->dato->setFase(ENTREGAPRINCIPAL);
        break;
    case POSTRETERMINADO:
        peticiones->siguienteEnCola()->dato->setFase(ENTREGAPOSTRE);
        break;
    default:
        break;
    }
    peticiones->encolar(peticion);
}

void Mesero :: llevarLavar(){
    lavadero->peticiones->encolar(peticiones->desencolar()->dato);
}

void Mesero :: entregarCuenta(){
    caja->peticiones->encolar(peticiones->desencolar()->dato);
}

void Mesero :: llevarPeticion(Fase fase){
    switch(fase){
    case COCINAENTRADA:
        cocinaEntrada->peticiones->encolar(peticiones->desencolar()->dato);
        break;
    case COCINAPRINCIPAL:
        cocinaPrincipal->peticiones->encolar(peticiones->desencolar()->dato);
        break;
    case COCINAPOSTRE:
        cocinaPostres->peticiones->encolar(peticiones->desencolar()->dato);
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
Mesa * Mesero :: atenderMesa(){//Recorrer lista y ver si estan comiendo sino tomar orden
    for(int i = 0;i < Utilidades<Mesa*>::arraySize(mesasAsignadas) ;i++){
        if(mesasAsignadas[i]->necesitaMesero()){
            tomarOrden(mesasAsignadas[i]);//esperar tiempo mesero * #clientes
            return mesasAsignadas[i];
        }
    }
    return nullptr;
}

Peticion * Mesero :: checkCocinas(){

    if(cocinaEntrada->salida->siguienteEnCola() != nullptr){
        Peticion * peticion = cocinaEntrada->salida->desencolar()->dato;
        recogerOrden(peticion);
        return peticion;
    }
    else if (cocinaPostres->salida->siguienteEnCola() != nullptr){
        Peticion * peticion = cocinaPrincipal->salida->desencolar()->dato;
        recogerOrden(peticion);
        return peticion;
    }
    else if (cocinaPrincipal->salida->siguienteEnCola() != nullptr){
        Peticion * peticion = cocinaPostres->salida->desencolar()->dato;
        recogerOrden(peticion);
        return peticion;
    }
    return nullptr;
}

void Mesero :: tomarOrden(Mesa * mesa){
    mesa->grupo->generarOrden();
    peticiones->encolar(mesa->grupo->peticion);
    mesa->grupo->setTodosEsperando(false);
}

Peticion * Mesero :: siguientePeticion(){
   if(peticiones->siguienteEnCola() != nullptr){
       Peticion * peticion = peticiones->siguienteEnCola()->dato;
       if(peticion != nullptr){
           if(peticion->fase == CREADA){
             peticion->setFase(COCINAENTRADA);
             atenderPeticion(peticion);
           }
           else
            atenderPeticion(peticion);
           return peticion;
       }
   }
   return nullptr;
}

void Mesero :: dejarOrden(){
    peticiones->primerNodo->dato->mesa->grupo->peticion = peticiones->desencolar()->dato;
    peticiones->primerNodo->dato->mesa->grupo->setTodosComiendo(true);
}

void Mesero :: cobrarCuenta(){
    peticiones->primerNodo->dato->mesa->grupo->setTodosComiendo(false);
    peticiones->primerNodo->dato->mesa->grupo->setTodosComiendo(false);
}



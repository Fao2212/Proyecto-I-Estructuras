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
        if(mesasAsignadas[i] == peticion->mesa){
            return true;
        }
    }
    return false;
}

void Mesero :: recogerOrden(Peticion * peticion){
    switch (peticion->fase) {
        case ENTRADATERMINADA:
        peticion->setFase(ENTREGAENTRADA);
        break;
    case PRINCIPALTERMINADA:
        peticion->setFase(ENTREGAPRINCIPAL);
        break;
    case POSTRETERMINADO:
        peticion->setFase(ENTREGAPOSTRE);
        break;
    default:
        break;
    }
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
            qDebug()<<"Pura vida";
            entregarCuenta();
            break;
        default:
            qDebug()<<"No deberia entrar";
            break;

    }
}
//Cuando toma la orden set esperando en false y cuando entrega la orden set esperando en true y comiendo en true
Mesa * Mesero :: atenderMesa(){//Recorrer lista y ver si estan comiendo sino tomar orden
    for(int i = 0;i < Utilidades<Mesa*>::arraySize(mesasAsignadas) ;i++){
        if(mesasAsignadas[i]->necesitaMesero()){
            tomarOrden(mesasAsignadas[i]);
            return mesasAsignadas[i];
        }
    }
    return nullptr;
}

void Mesero :: tomarOrden(Mesa * mesa){
    if(mesa->grupo->generarOrden()){
        peticiones->encolar(mesa->grupo->peticion);
        mesa->grupo->setTodosEsperando(false);
    }
    else{
        qDebug()<<"Tomar Orden";
        qDebug()<<mesa->grupo->peticion->faseMensaje();
        switch (mesa->grupo->peticion->fase) {
        case CREADA:
            mesa->grupo->peticion->setFase(COCINAPRINCIPAL);
            tomarOrden(mesa);
            break;
        case COCINAPRINCIPAL:
            mesa->grupo->peticion->setFase(COCINAPOSTRE);
            tomarOrden(mesa);
            break;
        case COCINAPOSTRE:
            mesa->grupo->peticion->setFase(COBROCUENTA);
            break;
        default:
            qDebug()<<"ERROR cuando nadie ordena";
        }
    }
}

Peticion * Mesero :: siguientePeticion(){
   if(peticiones->siguienteEnCola() != nullptr){
       Peticion * peticion = peticiones->siguienteEnCola()->dato;
       if(peticion != nullptr){
           if(peticion->fase == CREADA){
             peticion->setFase(COCINAENTRADA);
             atenderPeticion(peticion);
           }
           else{
            atenderPeticion(peticion);
            return peticion;
           }
       }
   }
   return nullptr;
}

void Mesero :: dejarOrden(){//Esta llegando sin peticion
    GrupoDeClientes * grupo = peticiones->primerNodo->dato->mesa->grupo;
    grupo->peticion = peticiones->desencolar()->dato;
    grupo->setTodosComiendo(true);
}

void Mesero :: cobrarCuenta(){

    peticiones->primerNodo->dato->mesa->grupo->setTodosComiendo(false);
    peticiones->primerNodo->dato->mesa->grupo->setTodosEsperando(false);
}


QString Mesero :: mostrarCola(int mult){
    Nodo<Peticion>* temp = peticiones->primerNodo;
    int proximas = 10*mult;
    QString mensaje = "";
    for(int i = 0; i<proximas;i++){
        if(temp != nullptr){
            QString construir = "Orden # "+QString::number(temp->dato->grupo)+"\n"+
                                "Mesa # "+QString::number(temp->dato->mesa->numeroDeMesa)+"\n"+
                                "Platos:["+temp->dato->platosActuales()+"]"+"\n"+
                                "Fase: "+temp->dato->faseMensaje();
            mensaje += construir;
            temp = temp->siguiente;
        }
        else
            break;
    }
    return mensaje;
}

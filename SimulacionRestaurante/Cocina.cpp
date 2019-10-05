#include "Cocina.h"
#include "Structs.h"
#include "Cocinero.h"
#include "Cola.h"
#include "Estado.h"
#include "Mesa.h"
#include "Peticion.h"

Cocina :: Cocina(TipoDeCocina tipo){
    this->peticiones = new Cola<Peticion>();
    this->salida = new Cola<Peticion>();
    this->estado = new Estado();
    this->tipo = tipo;
    switch (this->tipo) {
        case ENSALADAS:
            cocineros[0] = new Cocinero(this);
            cocineros[1] = nullptr;
            cocineros[2] = nullptr;
        break;
        case PRINCIPAL:
            cocineros[0] = new Cocinero(this);
            cocineros[1] = new Cocinero(this);
            cocineros[2] = new Cocinero(this);
        break;
        case POSTRES:
            cocineros[0] = new Cocinero(this);
            cocineros[1] =nullptr;
            cocineros[2] =nullptr;
        break;
    }
}

QString Cocina :: mostrarCola(int mult){
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

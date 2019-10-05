#include "Plato.h"

Plato::Plato(QString nombre,Tipo tipo,int tiempoDePreparacion,int tiempoDeLavado,double precio,ListaSimple<QString> * ingredientes){
    this->tipo = tipo;
    this-> nombre = nombre;
    this->tiempoDeLavado = tiempoDeLavado;
    this->precio = precio;
    this->ingredientes = ingredientes;
    this->tiempoDePreparacion = tiempoDePreparacion;
}

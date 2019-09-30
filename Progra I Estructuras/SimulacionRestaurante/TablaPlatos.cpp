#include "TablaPlatos.h"

Tabla :: Tabla(Tipo tipo,int tiempoMinimo,int tiempoMaximo,int probabilidad){
    this->tipo = tipo;
    this->tiempoMinimo = tiempoMinimo;
    this->tiempoMaximo = tiempoMaximo;
    this->probabilidad = probabilidad;
}

void Tabla :: cambiarTiempoMinimo(int tiempoMinimo){
    this->tiempoMinimo = tiempoMinimo;
}

void Tabla :: cambiarTiempoMaximo(int tiempoMaximo){
    this->tiempoMaximo = tiempoMaximo;
}

void Tabla :: cambiarProbabilidad(int probabilidad){
    this->probabilidad = probabilidad;
}

TablaPlatos :: TablaPlatos(int tiempoMinimoEntrada,int tiempoMaximoEntrada,int probabilidadEntrada,
                           int tiempoMinimoPlato,int tiempoMaximoPlato,int probabilidadPlato,
                           int tiempoMinimoPostre,int tiempoMaximoPostre,int probabilidadPostre){
    this->entrada = new Tabla(ENTRADA,tiempoMinimoEntrada,tiempoMaximoEntrada,probabilidadEntrada);
    this->plato = new Tabla(PLATO,tiempoMinimoPlato,tiempoMaximoPlato,probabilidadPlato);
    this->postre = new Tabla(POSTRE,tiempoMinimoPostre,tiempoMaximoPostre,probabilidadPostre);

}

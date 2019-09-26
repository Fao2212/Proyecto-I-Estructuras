#include "Mesa.h"
#include "Estado.h"
#include "Peticion.h"
#include "GrupoDeClientesBORRADOR.h"

Mesa :: Mesa(int consecutivo){

    this->grupo = nullptr;
    this->estado = new Estado();
    this->cuenta = nullptr;
    this->historial = nullptr;
    this->peticion = nullptr;
    this->TiempoDeComida = 1;//Siempre empieza con la entrada
    this->numeroDeMesa = consecutivo;
    this->asientosOcupados = 0;

}

void Mesa :: setGrupo(GrupoDeClientes * grupo){
    this->grupo = grupo;
}

bool Mesa :: estaVacia(){
    return this->grupo == nullptr;
}

void Mesa :: llenarMesa(GrupoDeClientes * grupo){
    setGrupo(grupo);
    this->asientosOcupados = grupo->groupSize();
    this->peticion = new Peticion(this,grupo->numeroDeGrupo);
}

void Mesa :: vaciarMesa(){
    setGrupo(nullptr);
    this->asientosOcupados = 0;
}

Cuenta * Mesa :: pagarCuenta(){
    vaciarMesa();
    return cuenta;
}

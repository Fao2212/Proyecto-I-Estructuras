#include "Mesa.h"
#include "Estado.h"
#include "Peticion.h"
#include "GrupoDeClientesBORRADOR.h"
#include "QDebug"

Mesa :: Mesa(int consecutivo){

    this->grupo = nullptr;
    this->estado = new Estado();
    this->cuenta = nullptr;
    this->historial = nullptr;
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
    grupo->sentarEnMesa(this);
}

void Mesa :: vaciarMesa(){
    setGrupo(nullptr);
    this->asientosOcupados = 0;
}

Cuenta * Mesa :: pagarCuenta(){
    vaciarMesa();
    return cuenta;
}

bool Mesa :: necesitaMesero(){
    if(!estaVacia()){
        if(grupo->listoParaOrdenar() == true)
            return  true;
        else
            return false;
    }
    return false;
}

#include "Cocina.h"
#include "Structs.h"
#include "Cocinero.h"
#include "Cola.h"
#include "Estado.h"

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

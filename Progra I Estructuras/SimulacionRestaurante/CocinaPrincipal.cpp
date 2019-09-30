#include "CocinaPrincipal.h"
#include "Cocinero.h"
#include "Cola.h"
#include "Estado.h"

CocinaPrincipal :: CocinaPrincipal(){
    for(int i = 0 ;i < 3;i++){
        this->cocineros[0] = new Cocinero();
    }
    this->peticiones = new Cola<Peticion>();
    this->estado = new Estado();
    this->salida = new Cola<Peticion>();
}

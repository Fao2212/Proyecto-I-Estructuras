#ifndef COCINA_H
#define COCINA_H
#include "Structs.h"

struct Cocina{

    TipoDeCocina tipo;
    Cocinero * cocineros[3];
    Cola<Peticion> * peticiones;
    Estado * estado;
    Cola<Peticion> * salida;

    Cocina(TipoDeCocina tipo);

};
#endif // COCINA_H

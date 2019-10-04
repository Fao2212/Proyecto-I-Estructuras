#ifndef TABLAPLATOS_H
#define TABLAPLATOS_H
#include "Structs.h"

struct Tabla{//Crear tres tablas una para cada tiempo y que se puedan cambiar
    Tipo tipo;
    int tiempoMinimo,tiempoMaximo;
    int probabilidad;//Nio usar

    Tabla(Tipo tipo,int tiempoMinimo,int tiempoMaximo,int probabilidad);

    void cambiarTiempoMinimo(int tiempoMinimo);
    void cambiarTiempoMaximo(int tiempoMaximo);
    void cambiarProbabilidad(int probabilidad);

};

struct TablaPlatos{
    Tabla * entrada;
    Tabla * plato;
    Tabla * postre;

    TablaPlatos(int tiempoMinimoEntrada,int tiempoMaximoEntrada,int probabilidadEntrada,
                int tiempoMinimoPlato,int tiempoMaximoPlato,int probabilidadPlato,
                int tiempoMinimoPostre,int tiempoMaximoPostre,int probabilidadPostre);

    int darTiempo(Tipo tipo);
   // Conoce();
   // Conoce();

};

#endif // TABLAPLATOS_H

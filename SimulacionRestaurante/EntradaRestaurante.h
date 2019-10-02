#ifndef ENTRADARESTAURANTE_H
#define ENTRADARESTAURANTE_H

#include "Structs.h"

struct EntradaDelRestaurante{

public:
    Cola<GrupoDeClientes> * espera;
    int tiempoDeGeneracion;
    int tiempoDeGeneracionMinimo;
    int maximoDeGenerados,minimoDeGenerados;
    Estado * estado;
    int consecutivoDeClientes;
    int consecutivoDeGrupos;
    Mesa * mesas[20];
    int cantidadDeMesas;

    EntradaDelRestaurante(int maximoDeGenerados,int tiempoDeGeneracionMinimo,int tiempoDeGeneracionMaximo,
                          Mesa * matriz[5][4],int cantidadDeMesas);//Seteado por el  Restaurante que es lo que controla toda la configuracion inicial
    //Anadir constructores por defecto

    GrupoDeClientes * crearGrupo();
    void asignarGrupo(GrupoDeClientes* grupo);//Enviarlos a una mesa disponible aleatoria
    Mesa * seleccionMesa();
    void copiarMatriz(Mesa * matriz[5][4]);
    void mesaLiberada();
};

#endif // ENTRADARESTAURANTE_H

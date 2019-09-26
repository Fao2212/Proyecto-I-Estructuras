#ifndef ENTRADARESTAURANTE_H
#define ENTRADARESTAURANTE_H

#include "Structs.h"

struct EntradaDelRestaurante{

public:
    Cola * espera;
	double tiempoDeGeneracion;
    int maximoDeGenerados;
    Estado * estado;
    int consecutivoDeClientes;

    EntradaDelRestaurante(Estado * estado,int maximoDeGenerados,int tiempoDeGeneracion);//Seteado por el  Restaurante que es lo que controla toda la configuracion inicial
    //Anadir constructores por defecto

    GrupoDeClientes * crearGrupo();
    void asignarGrupo(GrupoDeClientes* grupo);//Enviarlos a una mesa disponible aleatoria
    Mesa * seleccionMesa();
};

#endif // ENTRADARESTAURANTE_H

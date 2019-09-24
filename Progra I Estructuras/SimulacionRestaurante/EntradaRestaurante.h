#ifndef ENTRADARESTAURANTE_H
#define ENTRADARESTAURANTE_H

#include "Structs.h"

struct EntradaDelRestaurante{

public:
	double tiempoDeGeneracion;
    int maximoDeGenerados;
    Estado * estado;
	int totalDeGenerados;//Se puede ir aumentando cada vez que se genera un cliente

    GrupoDeClientes * crearGrupo();
    void asignarGrupo(Cliente * grupoDeClientes[]);//Enviarlos a una mesa disponible aleatoria

    EntradaDelRestaurante(Estado * estado,int maximoDeGenerados,int tiempoDeGeneracion);//Seteado por el  Restaurante que es lo que controla toda la configuracion inicial
    //Anadir constructores por defecto
};

#endif // ENTRADARESTAURANTE_H

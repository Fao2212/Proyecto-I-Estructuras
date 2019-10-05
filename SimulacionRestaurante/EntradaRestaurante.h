#ifndef ENTRADARESTAURANTE_H
#define ENTRADARESTAURANTE_H

#include "Structs.h"
#include "ThreadCliente.h"

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
    ColaMensajes * mensajes;
    ListaSimple<ThreadCliente> * clientes;

    EntradaDelRestaurante(int maximoDeGenerados,int tiempoDeGeneracionMinimo,int tiempoDeGeneracionMaximo,
                          Mesa * matriz[5][4],int cantidadDeMesas,ColaMensajes * mensajes);//Constructor por defecto

    GrupoDeClientes * crearGrupo();
    void asignarGrupo(GrupoDeClientes* grupo);
    Mesa * seleccionMesa();
    void copiarMatriz(Mesa * matriz[5][4]);
    void mesaLiberada();
    void crearThreadCliente(GrupoDeClientes * grupo);
};

#endif // ENTRADARESTAURANTE_H

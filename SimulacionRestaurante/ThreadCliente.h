#ifndef THREADCLIENTE_H
#define THREADCLIENTE_H
//Asegurarse de hacerle un destructor a mi compadre
#include <QtCore>
#include "Structs.h"
#include "qlistwidget.h"

class ThreadCliente : public QThread{
public:
    GrupoDeClientes * grupo;
    bool pausa, activo;
    ColaMensajes * mensajes;

    ThreadCliente();
    ~ThreadCliente();

    void run();

    void __init__(GrupoDeClientes * grupo,ColaMensajes * mensajes);
    void pausar();
    void continuar();
    void fasesComiendo(Peticion * peticion);
    void fasesTerminandoComer(Peticion * peticion);
    void comer();
};
#endif // THREADCLIENTE_H

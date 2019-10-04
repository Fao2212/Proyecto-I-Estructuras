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
    QListWidget * log;
    QMutex * mutexEntrada;

    ThreadCliente();
    ~ThreadCliente();

    void run();

    void __init__(GrupoDeClientes * grupo,QListWidget * log,QMutex * mutexEntrada);
    void pausar();
    void continuar();
    void comer();
};
#endif // THREADCLIENTE_H

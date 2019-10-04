#ifndef THREADCAJERO_H
#define THREADCAJERO_H
#include <QtCore>
#include "Structs.h"
#include "qlistwidget.h"
class ThreadCajero : public QThread{
public:
    Cajero * cajero;
    bool pausa, activo;
    QListWidget * log;
    QMutex * mutexEntrada;

    ThreadCajero();

    void run();

    void __init__(Cajero * cajero,QListWidget * log,QMutex * mutexEntrada);
    void pausar();
    void continuar();
    void cobrar();
};
#endif // THREADCAJERO_H

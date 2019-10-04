#ifndef THREADMESERO_H
#define THREADMESERO_H

#include <QtCore>
#include "Structs.h"
#include "qlistwidget.h"

class ThreadMesero : public QThread{
public:
    Mesero * mesero;
    bool pausa, activo;
    QListWidget * log;
    QMutex * mutexEntrada;
    ColaMensajes * mensajes;

    ThreadMesero();

    void run();

    void __init__(Mesero * mesero,QMutex * mutexEntrada,ColaMensajes * mensajes);
    void pausar();
    void continuar();
    void pudoAtender();
    void tomoPeticion();
    void llevoPeticion();
};

#endif // THREADMESERO_H

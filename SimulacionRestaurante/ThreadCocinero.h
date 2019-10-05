#ifndef THREADCOCINERO_H
#define THREADCOCINERO_H
#include <QtCore>
#include "Structs.h"
#include "qlistwidget.h"

class ThreadCocinero : public QThread{
public:
    Cocinero * cocinero;
    bool pausa, activo;
    ColaMensajes * mensajes;
    QMutex * mutexCocina;

    ThreadCocinero();

    void run();

    void __init__(Cocinero * cocinero,ColaMensajes * mensajes,QMutex * mutexCocina);
    void pausar();
    void continuar();
    void cocinar();
};

#endif // THREADCOCINERO_H

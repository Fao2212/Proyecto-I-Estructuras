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

    ThreadMesero();

    void run();

    void __init__(Mesero * mesero,QMutex * mutexEntrada);
    void pausar();
    void continuar();
};

#endif // THREADMESERO_H

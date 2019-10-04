#ifndef THREADLAVAPLATOS_H
#define THREADLAVAPLATOS_H
#include <QtCore>
#include "Structs.h"
#include "qlistwidget.h"

class ThreadLavaplatos : public QThread{
public:
    Lavaplatos * lavaplatos;
    bool pausa, activo;
    QListWidget * log;
    QMutex * mutexEntrada;

    ThreadLavaplatos();

    void run();

    void __init__(Lavaplatos * lavaplatos,QListWidget * log,QMutex * mutexEntrada);
    void pausar();
    void continuar();
    void lavar();
};
#endif // THREADLAVAPLATOS_H

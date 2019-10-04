#ifndef THREADRESTAURANTE_H
#define THREADRESTAURANTE_H

#include <QtCore>
#include "EntradaRestaurante.h"
#include "qlistwidget.h"
#include "QLabel"

class ThreadEntradaRestaurante : public QThread{
public:
    EntradaDelRestaurante * entrada;
    bool pausa, activo;
    QListWidget * logRestaurante;
    QMutex * mutexEntrada;
    QLabel * contador;
    ColaMensajes * mensajes;

    ThreadEntradaRestaurante();

    void run();

    void __init__(EntradaDelRestaurante * entrada,QListWidget * logRestaurante,QMutex * mutexEntrada,QLabel * contador,ColaMensajes * mensajes);
    void pausar();
    void continuar();
};

#endif // THREADRESTAURANTE_H

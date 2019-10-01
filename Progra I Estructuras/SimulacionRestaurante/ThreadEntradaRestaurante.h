#ifndef THREADRESTAURANTE_H
#define THREADRESTAURANTE_H

#include <QtCore>
#include "EntradaRestaurante.h"
#include "qlistwidget.h"

class ThreadEntradaRestaurante : public QThread{
public:
    EntradaDelRestaurante * entrada;
    bool pausa, activo;
    QListWidget * logRestaurante;

    ThreadEntradaRestaurante();

    void run();

    void __init__(EntradaDelRestaurante * entrada,QListWidget * logRestaurante);
    void pausar();
    void continuar();
};

#endif // THREADRESTAURANTE_H

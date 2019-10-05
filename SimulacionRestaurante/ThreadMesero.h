#ifndef THREADMESERO_H
#define THREADMESERO_H

#include <QtCore>
#include "Structs.h"
#include "qlistwidget.h"

class ThreadMesero : public QThread{
public:
    Mesero * mesero;
    bool pausa, activo;
    QMutex * mutexColaCajero;
    QMutex * mutexColaLavadero;
    QMutex * mutexColaCocinaPostre;
    QMutex * mutexColaCocinaEntrada;
    QMutex * mutexColaCocinaPrincipal;
    ColaMensajes * mensajes;

    ThreadMesero();

    void run();

    void __init__(Mesero * mesero,QMutex * mutexColaCajero,QMutex * mutexColaLavadero,QMutex * mutexColaCocinaPostre
                  ,QMutex * mutexColaCocinaEntrada,QMutex * mutexColaCocinaPrincipal,ColaMensajes * mensajes);
    void pausar();
    void continuar();
    void pudoAtender();
    void tomoPeticion();
    void llevoPeticion();
    void  quickQueue(QMutex * mutex);
    void revisarCocina();
    void  quickDraw(Cocina * cocina, QMutex * mutex);
};

#endif // THREADMESERO_H

#ifndef THREADMESERO_H
#define THREADMESERO_H

#include <QtCore>
#include "Mesero.h"

class ThreadMesero : public QThread{
public:
    Mesero * mesero;
    bool pausa, activo;

    ThreadMesero();

    void run();

    void pausar();
    void continuar();
};

#endif // THREADMESERO_H

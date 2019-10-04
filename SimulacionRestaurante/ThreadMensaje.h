#ifndef THREADMENSAJE_H
#define THREADMENSAJE_H
#include <QtCore>
#include "Structs.h"
#include "qlistwidget.h"

class ThreadMensaje : public QThread{
public:

    ColaMensajes * mensajes;
    QListWidget * log;
    bool activo,pausa;

    ThreadMensaje();

    void run();

    void __init__(ColaMensajes * cola,QListWidget * log);
    void leer();
};

#endif // THREADMENSAJE_H

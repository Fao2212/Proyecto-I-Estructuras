#ifndef THREADDATOS_H
#define THREADDATOS_H
#include <QtCore>
#include <QLabel>
#include "Structs.h"

class ThreadDatos : public QThread{
public:
    QLabel  * labelStatus;
    bool activo,pausa;
    Restaurante * restaurante;
    //Cantidad de Widgets a usar
    ThreadDatos();

    void run();
    void __init__(Restaurante * r,QLabel * labelStatus);

    void continuar();
    void pausar();
    void cambiarWidget(QLabel * widget);
    void imprimirDatos(QLabel * widgetAUsar);
    void cronometro();
};

#endif // THREADDATOS_H

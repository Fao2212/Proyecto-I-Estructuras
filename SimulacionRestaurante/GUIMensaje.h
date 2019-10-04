#ifndef GUIMENSAJE_H
#define GUIMENSAJE_H
#include "QColor"
#include "QString"
#include "QListWidget"
#include "Structs.h"

struct Mensaje {

    ColorTexto color;
    QString contenido;
    QString fuente;
    int size;

    Mensaje();
    Mensaje(ColorTexto color);
    Mensaje(ColorTexto color,QString contenido);
    Mensaje(ColorTexto color,QString contenido,QString fuente);
    Mensaje(ColorTexto color,QString contenido,QString fuente,int size);

    QColor darColor(ColorTexto color);


};

struct ColaMensajes{

    Cola<Mensaje> * colaDeMensajes;

    ColaMensajes();

    QListWidgetItem * imprimirSiguiente();
    void crearMensaje(ColorTexto color,QString contenido);

};

//COLA MENSAJES
#endif // GUIMENSAJE_H
//Un formato de mensajes para la cola por ejempli
//Peticion
//Estado
//....
//Una flecha con un widget para siguiente en cola.

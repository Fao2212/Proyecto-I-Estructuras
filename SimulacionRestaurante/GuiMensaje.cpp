#include "GUIMensaje.h"
#include "Cola.h"
#include "QColor"
#include "Structs.h"
#include "Utilidades.h"

static const QColor * ColorMesero = new QColor("74ebd5");
static const QColor * ColorEntrada = new QColor("ACB6E5");
static const QColor * ColorCocinero = new QColor("74eb9a");
static const QColor * ColorCajero = new QColor("f5af19");
static const QColor * ColorLavaplatos = new QColor("e90ae5");
static const QColor * ColorCliente = new QColor("61f8ee");
static const QColor * Default = new QColor("000000");

Mensaje :: Mensaje(){
    color = COLORDEFAULT;
    contenido = "";
    fuente = "";
    size = 10;
}

Mensaje :: Mensaje(ColorTexto color){
    this->color = color;
    contenido = "";
    fuente = "";
    size = 10;
}

Mensaje :: Mensaje(ColorTexto color,QString contenido){
    this->color = color;
    this->contenido = contenido;
    fuente = "";
    size = 10;
}

Mensaje :: Mensaje(ColorTexto color,QString contenido,QString fuente){
    this->color = color;
    this->contenido = contenido;
    this->fuente = fuente;
    size = 10;
}

Mensaje :: Mensaje(ColorTexto color,QString contenido,QString fuente,int size){
    this->color = color;
    this->contenido = contenido;
    this->fuente = fuente;
    this->size = size;
}

ColaMensajes :: ColaMensajes(){
    this->colaDeMensajes = new Cola<Mensaje>();
}

QListWidgetItem * ColaMensajes :: imprimirSiguiente(){
    QListWidgetItem * item = new QListWidgetItem();
    Mensaje * mensaje = colaDeMensajes->desencolar()->dato;
    QBrush my_brush;
    QColor color = mensaje->darColor(mensaje->color);
    my_brush.setColor(color);
    item->setForeground(my_brush);
    item->setText(mensaje->contenido);

    return item;

}

QColor Mensaje :: darColor(ColorTexto color){
    switch (color) {
    case COLORMESERO:
        return *ColorMesero;
    case COLORCAJERO:
        return *ColorCajero;
    case COLORENTRADA:
        return *ColorEntrada;
    case COLORCOCINERO:
        return *ColorCocinero;
    case COLORLAVAPLATOS:
        return *ColorLavaplatos;
    case COLORCLIENTE:
        return *ColorCliente;
    default:
        return *Default;
    }
}

void ColaMensajes :: crearMensaje(ColorTexto color,QString contenido){
     QString mensaje = Utilidades<void>::getTime();
     mensaje += " " + contenido;
     colaDeMensajes->encolar(new Mensaje(color,mensaje));
}

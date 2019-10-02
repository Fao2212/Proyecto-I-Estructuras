QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Cliente.cpp \
    CocinaEnsalada.cpp \
    CocinaPostres.cpp \
    CocinaPrincipal.cpp \
    Cocinero.cpp \
    Cola.cpp \
    EntradaRestaurante.cpp \
    Estado.cpp \
    Funciones.cpp \
    GrupoDeClientes.cpp \
    LavaPlatos.cpp \
    Lavadero.cpp \
    ListaSimple.cpp \
    Mesa.cpp \
    Mesero.cpp \
    Peticion.cpp \
    Pila.cpp \
    Random.cpp \
    Restaurante.cpp \
    TablaPlatos.cpp \
    ThreadEntradaRestaurante.cpp \
    ThreadMesero.cpp \
    Utilidades.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../../../Documents/C++/Proyecto1/Caja.h \
    ../../../Documents/C++/Proyecto1/Cajero.h \
    ../../../Documents/C++/Proyecto1/Cliente.h \
    ../../../Documents/C++/Proyecto1/CocinaEnsaladas.h \
    ../../../Documents/C++/Proyecto1/CocinaPostres.h \
    ../../../Documents/C++/Proyecto1/CocinaPrincipal.h \
    ../../../Documents/C++/Proyecto1/Cocinero.h \
    ../../../Documents/C++/Proyecto1/Cola.h \
    ../../../Documents/C++/Proyecto1/Cuenta.h \
    ../../../Documents/C++/Proyecto1/EntradaRestaurante.h \
    ../../../Documents/C++/Proyecto1/Estado.h \
    ../../../Documents/C++/Proyecto1/GrupoDeClientesBORRADOR.h \
    ../../../Documents/C++/Proyecto1/Ingrediente.h \
    ../../../Documents/C++/Proyecto1/Lavadero.h \
    ../../../Documents/C++/Proyecto1/Lavaplatos.h \
    ../../../Documents/C++/Proyecto1/ListaSimple.h \
    ../../../Documents/C++/Proyecto1/Menu.h \
    ../../../Documents/C++/Proyecto1/Mesa.h \
    ../../../Documents/C++/Proyecto1/Mesero.h \
    ../../../Documents/C++/Proyecto1/Nodo.h \
    ../../../Documents/C++/Proyecto1/Peticion.h \
    ../../../Documents/C++/Proyecto1/Pila.h \
    ../../../Documents/C++/Proyecto1/Plato.h \
    ../../../Documents/C++/Proyecto1/Random.h \
    ../../../Documents/C++/Proyecto1/Restaurante.h \
    Bitacora.h \
    Caja.h \
    Cajero.h \
    Cliente.h \
    CocinaEnsaladas.h \
    CocinaPostres.h \
    CocinaPrincipal.h \
    Cocinero.h \
    Cola.h \
    Cuenta.h \
    EntradaRestaurante.h \
    Estado.h \
    GrupoDeClientesBORRADOR.h \
    Ingrediente.h \
    Lavadero.h \
    Lavaplatos.h \
    ListaSimple.h \
    Menu.h \
    Mesa.h \
    Mesero.h \
    Nodo.h \
    Peticion.h \
    Pila.h \
    Plato.h \
    Random.h \
    Restaurante.h \
    Structs.h \
    TablaPlatos.h \
    ThreadEntradaRestaurante.h \
    ThreadMesero.h \
    Utilidades.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

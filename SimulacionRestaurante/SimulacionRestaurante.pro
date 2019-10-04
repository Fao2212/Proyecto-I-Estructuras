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
    Caja.cpp \
    Cajero.cpp \
    Cliente.cpp \
    Cocina.cpp \
    CocinaEnsalada.cpp \
    CocinaPostres.cpp \
    CocinaPrincipal.cpp \
    Cocinero.cpp \
    Cola.cpp \
    EntradaRestaurante.cpp \
    Estado.cpp \
    Funciones.cpp \
    GrupoDeClientes.cpp \
    GuiMensaje.cpp \
    LavaPlatos.cpp \
    Lavadero.cpp \
    ListaSimple.cpp \
    Menu.cpp \
    Mesa.cpp \
    Mesero.cpp \
    Peticion.cpp \
    Pila.cpp \
    Random.cpp \
    Restaurante.cpp \
    TablaPlatos.cpp \
    ThreadCajero.cpp \
    ThreadClientes.cpp \
    ThreadCocinero.cpp \
    ThreadEntradaRestaurante.cpp \
    ThreadLavaplatos.cpp \
    ThreadMensaje.cpp \
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
    Cocina.h \
    CocinaEnsaladas.h \
    CocinaPostres.h \
    CocinaPrincipal.h \
    Cocinero.h \
    Cola.h \
    Cuenta.h \
    EntradaRestaurante.h \
    Estado.h \
    GUIMensaje.h \
    Globals.h \
    GrupoDeClientesBORRADOR.h \
    Ingrediente.h \
    Lavadero.h \
    Lavaplatos.h \
    ListaDoble.h \
    ListaSimple.h \
    Menu.h \
    Mesa.h \
    Mesero.h \
    Nodo.h \
    NodoD.h \
    Peticion.h \
    Pila.h \
    Plato.h \
    Random.h \
    Restaurante.h \
    Structs.h \
    TablaPlatos.h \
    ThreadCajero.h \
    ThreadCliente.h \
    ThreadCocinero.h \
    ThreadEntradaRestaurante.h \
    ThreadLavaplatos.h \
    ThreadMensaje.h \
    ThreadMesero.h \
    Utilidades.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icos.qrc \
    icon.qrc

DISTFILES += \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/001-appetizer.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/001-cookies.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/002-bar.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/003-bartender.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/004-beverage.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/004-juice.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/005-bistro.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/005-restaurant.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/006-bistro.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/006-crepe.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/007-lunch.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/007-restaurant-1.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/008-chef.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/008-coffee.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/009-cocktail.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/009-cooker.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/010-chef hat.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/010-cook.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/011-client.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/011-cocktail.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/012-cupcake.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/012-discount.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/013-delicious.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/013-dinner.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/014-dessert.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/014-discount.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/015-dining.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/015-dishwasher.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/016-liquor.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/016-steak.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/017-dining.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/017-dishwasher.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/018-cocktail.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/018-fruits.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/019-kitchen.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/020-location-pin.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/020-restaurant.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/021-dish.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/021-steak.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/022-meal.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/022-rice.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/023-menu.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/024-cutlery.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/024-noodles.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/025-paying.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/025-spaghetti.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/026-credit-card.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/026-restaurant.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/027-menu-1.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/027-restaurant.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/028-nachos.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/028-tips.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/029-porridge.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/029-soup.png \
    ../../../../../Qt/Docs/Qt-5.13.1/qtgui/ResourceFiles/icons/030-waiter.png

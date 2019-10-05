#include "Structs.h"
#include "QString"
// tipo por el estado de la peticion de plato,tiempo,mesa,estado,responsable,mesero,cliente y se agrega en la cola del mesero
//La orden va junta la cocinada por separado

struct Peticion {

    Fase fase;
	Mesa * mesa;
    int grupo;
    Plato * platos[6] = {nullptr};
    QString responsable;


    Peticion(Mesa * mesa,int grupo);
    void vaciarPlatos();
    void llenarPlatos(Plato plato);
    void setFase(Fase state);
    QString platosActuales();
    QString faseActual();
    QString faseMensaje();
	
};


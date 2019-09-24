#include "Structs.h"
#include "QString"
// tipo por el estado de la peticion de plato,tiempo,mesa,estado,responsable,mesero,cliente y se agrega en la cola del mesero
//La orden va junta la cocinada por separado
struct Peticion {

	int fase;
	int tiempo;
	Mesa * mesa;
	Estado * estado;
    QString responsable;//Quien esta manejanod la peticion
    int grupo;

    Peticion(Mesa * mesa,Estado * estado,int grupo);
	
};


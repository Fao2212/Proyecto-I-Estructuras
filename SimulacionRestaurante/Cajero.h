#include "Structs.h"

struct Cajero{
public:
	Estado * estado;
    Cola<Peticion> * peticiones;
	int atendidos;
    int tiempo;//Por definir
    Caja * caja;
	
    Cajero(Caja * caja);

    bool estaCobrando();
    Peticion * tomarCuenta();
    Peticion * hacerCobro();
    double ventasActuales();
	
};

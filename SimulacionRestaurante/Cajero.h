#include "Structs.h"

struct Cajero{
public:
	Estado * estado;
    Cola<Peticion> * peticiones;
	int tiempo;
	int atendidos;
	
    bool estaCobrando();
    void tomarCuenta();
    void hacerCobro();
	
};

#include "Structs.h"

struct Cocinero{
	
	Estado * estado;
	Cola * peticiones;
	int tiempo;
	int atendidos;
	
    bool estaCocinando();
    void tomarOrden();
    void entregarOrden();
    void cocinarPlato();
	
};

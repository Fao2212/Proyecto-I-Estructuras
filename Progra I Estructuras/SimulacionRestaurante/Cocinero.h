#include "Structs.h"

struct Cocinero{
	
	Estado * estado;
    Cola<Peticion> * peticiones;
	int tiempo;
	int atendidos;

    Cocinero();
	
    bool estaCocinando();
    void tomarOrden();
    void entregarOrden();
    void cocinarPlato();
	
};

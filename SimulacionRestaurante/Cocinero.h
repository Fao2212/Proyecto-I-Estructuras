#include "Structs.h"
#include "QString"

struct Cocinero{
	
	Estado * estado;
    Cola<Peticion> * peticiones;
	int tiempo;
	int atendidos;
    int id;
    Cocina * cocina;

    Cocinero(Cocina * cocina);
	
    bool estaCocinando();
    Peticion * tomarOrden();
    Peticion * entregarOrden();
    QString cocinandoPlato(int i);
    int tiempoDeCoccion(int i);

    Peticion * recogerOrden(Peticion * peticion);
    void dejarOrden();
	
};

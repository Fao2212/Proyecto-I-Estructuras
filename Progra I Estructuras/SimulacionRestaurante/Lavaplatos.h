#include "Structs.h"


struct Lavaplatos{
	
	Estado * estado;
	Cola * peticiones;
	int tiempo;
	int atendidos;
	
    bool estaLavando();
    void tomarPlato();
    void lavarPlato();
	
};

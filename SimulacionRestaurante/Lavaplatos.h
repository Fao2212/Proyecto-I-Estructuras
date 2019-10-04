#include "Structs.h"

//aNADIR AL MESERO UN CONTADOR DE PLATOS SUCIOSQUE SE REINICIE CON CADA ENTREGA AL LAVAPLATOS
struct Lavaplatos{
	
	Estado * estado;
    Cola<Peticion> * peticiones;
	int atendidos;
    Lavadero * lavadero;

    Lavaplatos(Lavadero * lavadero);
	
    bool estaLavando();
    Peticion * tomarPlato();
    Peticion * lavarPlato();
	
};

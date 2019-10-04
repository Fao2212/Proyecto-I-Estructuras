#include "Structs.h"

struct Caja{
public:
    enum Modo{
        PILA,COLA
    };
	Cajero * cajero;
    Cola<Peticion> * peticiones;
	Estado * estado;
    Modo modo;
    ListaSimple<Peticion> * historial;
	
    Caja();

    void desactivar();//Esto para todas las estructuras con un estado
    void cambioDeModo();//Se cambia de cola a pila con un cambio de posicion de insercion en cola
    void recibirPeticion(Peticion * peticion);

};

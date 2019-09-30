#include "Structs.h"

struct CocinaPostres{
	
	Cocinero * cocinero;
    Cola<Peticion> * peticiones;
	Estado * estado;
    Cola<Peticion> * salida;

    CocinaPostres();
	
};

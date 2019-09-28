#include "Structs.h"

struct CocinaPrincipal{
	
    Cocinero * cocineros[3];
    Cola<Peticion> * peticiones;
	Estado * estado;
    Cola<Peticion> * salida;
	
};

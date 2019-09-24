#include "Structs.h"

struct Cliente{
	
    int pos;

    int getPos();
	bool estaComiendo();//Avisa cuando termina de comer
    void seleccionarPlato();//Si es null no tiene plato
    void comer();
    Cliente(int pos);

	
};

#include "Structs.h"
#include "Plato.h"

struct Cliente{
	
    int pos;
    TablaPlatos * tabla;
    bool comiendo,esperando;
    Plato * plato;

    Cliente(int pos);

    int getPos();
    bool estaComiendo();
    bool quierePagar();
    Plato * tomarDecision(Peticion * peticion);
    Plato * seleccionPlato(Tipo tipo);
    void setComiendo(bool comiendo);
    void setEsperando(bool esperando);
    bool listo();
	
};

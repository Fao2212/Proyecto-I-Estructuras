#include "Structs.h"
#include "Plato.h"

struct Cliente{
	
    int pos;
    TablaPlatos * tabla;
    bool comiendo,esperando;

    Cliente(int pos);

    int getPos();
	bool estaComiendo();//Avisa cuando termina de comer
    Plato * tomarDecision(Peticion * peticion);//Si es null no tiene plato
    Plato * seleccionPlato(Tipo tipo);
    void comer(Peticion * peticion);//Se le da su plato y segun el tipo de plato un switch con los tiempos definidos
    void setComiendo(bool comiendo);
    void setEsperando(bool esperando);
    bool listo();
	
};

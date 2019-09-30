#include "qstring.h"
#include "Structs.h"

struct Plato{
	//Se puede usar la tarea de recetas
    Tipo tipo;
	int tiempoDePreparacion;
    QString nombre;
	int tiempoDeLavado;
	double precio;
    Ingrediente * ingredientes;
	
};

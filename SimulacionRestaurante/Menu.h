#include "Structs.h"

//Se crea una lista simple con el nombre Menu y se cargar aca todos los platos

struct Menu{

    ListaDoble<Plato> * menu;

    Menu();

    Plato * platoAlAzar(Tipo tipo);
    void menuDefault();
    void imprimirPlatos();
};

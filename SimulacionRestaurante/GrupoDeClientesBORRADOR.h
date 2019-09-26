#include "Structs.h"
struct GrupoDeClientes{

	int reserva;
    Cliente * grupo[6];
    int numeroDeGrupo;

    GrupoDeClientes();
    int groupSize();
    int generarReserva();

};

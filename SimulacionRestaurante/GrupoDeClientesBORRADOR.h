#include "Structs.h"
struct GrupoDeClientes{

	int reserva;
    Cliente * grupo[6];
    int numeroDeGrupo;
    Peticion * peticion;
    Mesa * mesa;

    GrupoDeClientes();

    int groupSize();
    int generarReserva();//tiene que comparar si el grupo coincide con la reserva ccrreada por el restaurante
    bool generarOrden();
    void sentarEnMesa(Mesa * mesa);
    bool listoParaOrdenar();
    void SetFasePeticion(Peticion * peticion);
    void setTodosEsperando(bool esperando);
    void setTodosComiendo(bool comiendo);
    void recibirPeticion();
    bool listoParaPagar();
    bool listoParaComer();
    void pagarCuenta();

};

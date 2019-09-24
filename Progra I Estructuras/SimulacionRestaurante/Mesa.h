#include "Structs.h"
struct Mesa{
	
	int asientos;
    GrupoDeClientes grupo;
    int * AsientosDisponibles[6];
    int* AsientosOcupados[6];
	Estado * estado;
	Cuenta * cuenta;
	ListaSimple * historial;
	Peticion * peticion;
	int TiempoDeComida;
	int numeroDeMesa;
	
	bool estaVacia();//if disponible = 6
	bool estanComiendo();//Si todos avisan  y es la misma cantidad de los ocupados, entonces se hace el llamado al mesero
	void vaciarMesa();
	void llenarMesa();
	void pagarCuenta();//Vaciar la mesa y enviarla a disponible
};//El historial es lo que tiene la mesa en ese momento

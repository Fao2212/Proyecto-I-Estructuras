#include "Structs.h"
struct Mesa{
	
    GrupoDeClientes * grupo;
	Estado * estado;
	Cuenta * cuenta;
    ListaSimple<Mesa> * historial;
    int TiempoDeComida;//1 para entrada 2 para plato principal 3 para postre
	int numeroDeMesa;
    int asientosOcupados;
    bool vacia;
    //Un estadoActual
	
    Mesa(int consecutivo);

    void setGrupo(GrupoDeClientes * grupo);
	bool estaVacia();//if disponible = 6
	bool estanComiendo();//Si todos avisan  y es la misma cantidad de los ocupados, entonces se hace el llamado al mesero
	void vaciarMesa();
    void llenarMesa(GrupoDeClientes * grupo);
    Cuenta * pagarCuenta();//Vaciar la mesa y enviarla a disponible
    void reservada();
    void showInfo();
    bool necesitaMesero();
    //Agregar a la cuenta

};//El historial es lo que tiene la mesa en ese momento

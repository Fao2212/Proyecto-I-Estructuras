#include "Structs.h"

struct Mesero{
	
	Cola * peticiones;
	Estado * estado;
	Cola * cuentas;//Puede que no se necesite una lista de cuentas
	int tiempoDeServido;
	int tiempoDeEntrega;
	int mesasAtendidas;
    Plato * Orden[6];//Lleva un array de platos para repartir a los de la mesa
    Mesa * cantidadDeMesas[];//Puede ser una lista ya que tiene que cambiar en tiempo de ejecucion


	
	//Cambiar algunos nombres a unos mas representativos
    void atenderPeticion();//Toma la orden de la mesa tiene que
    void llevarPeticion();//Lleva la orden a su respectiva cocina
    void dejarOrden();//LLeva la orden a la mesa
    void recogerOrden();//Saca la orden de la cocina
    void entregarCuenta();//Lleva la cuenta a la caja
    void llevarLavar();//Lleva los platos al lavadero
    void repartirPlatos();//Da el plato correspondiente a cada miembro de la mesa
	
	

};//Agregar un label / Una pantalla que diga que esta haciendo cada mesero, Tipo juego donde diga !Mesro Regogio la comida!!
//Entrega un plato por persona, no entrega todo de una vez//Los tiempos pueden cambiarse  en tiempo de ejecucion

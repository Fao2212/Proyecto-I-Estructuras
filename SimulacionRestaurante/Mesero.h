#include "Structs.h"
struct Mesero{
	
    int id;
    Cola<Peticion> * peticiones;
	Estado * estado;
    Cola<Cuenta> * cuentas;//Puede que no se necesite una lista de cuentas
	int tiempoDeServido;
    int mesasAtendidas;//Cuando se termine de comer se agrega 1
    Mesa * mesasAsignadas[20] = {nullptr};
    int numeroMesasAsignadas;
    CocinaPrincipal * cocinaPrincipal;
    CocinaEnsaladas * cocinaEntrada;
    CocinaPostres * cocinaPostres;//Se asignan las cocinas del restauran en los constructores
    Caja * caja;
    Lavadero * lavadero;

    Mesero(CocinaPrincipal * cocinaPrincipal,CocinaEnsaladas *cocinaEntrada,CocinaPostres *cocinaPostres
           ,int tiempoDeServido);
	
    //Cambiar algunos nombres a unos mas representativos
    void setMesas();//Se toma el array que se le da y se reparte en su propio array
    void atenderPeticion(Peticion * peticion);//Realiza la fase de la peticion
    void atenderMesa();
    void tomarOrden(Mesa * mesa);//Toma la orden del cliente
    void llevarPeticion(Fase fase);//Lleva la orden a su respectiva cocina
    void dejarOrden();//Saca la peticion de la cola y la deja en una nueva
    void recogerOrden(Peticion * peticion);//Saca la peticion de un lugar y la encola en su propia cola
    void entregarCuenta();//Lleva la cuenta a la caja
    void llevarLavar();//Lleva los platos al lavadero
    void repartirPlatos();//Da el plato correspondiente a cada miembro de la mesa
    void siguientePeticion();
    void cobrarCuenta();
    void checkCocinas();//Revision de cocinas individual
    bool validarMesa(Peticion * peticion);

};//Agregar un label / Una pantalla que diga que esta haciendo cada mesero, Tipo juego donde diga !Mesro Regogio la comida!!
//Entrega un plato por persona, no entrega todo de una vez//Los tiempos pueden cambiarse  en tiempo de ejecucion
//Un log

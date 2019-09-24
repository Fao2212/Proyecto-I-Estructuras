#include "Structs.h"
// Compuesta de estaciones, matriz de mesas , Lista de meseros ,Hilos para cada uno(Thread mesero,Thread cocinero...)
//Todo lo que esta en verde se puede cambiar en ejecucion / La entrada de clientes es un rango configurable entiempo de ejecucion
//Una ventana donde le pregunta si esta seguro de guardar los cambios APLY una
struct Restaurante{
public:
	//Matriz de mesas
    EntradaDelRestaurante * entrada;
    ListaSimple * meseros;
	//Hilos

    Restaurante(EntradaDelRestaurante entrada);
    void cambiarTiempoMesero();
    void cambiarTiempoCocinero();
    void cambiarTiempoLavadero();
    void cambiarTiempoCajero();
    void cambiarModoCaja();
    void cambiarProbabilidadPlato();
    void cambiarTiempoDeConsumoPlato();
    void cambiarCantidadDeMeseros();
    void cambiarEstado();//De quien quiero cambiar el estado
    void setEntrada(int tiempoDeGeneracion,Estado * estado,int maximoDeGenerados);
    void setArrayMesas();
    void setMeseros();
    void setMesasMeseros();
    void setCocinaPrincipal();
    void setCocinaEnsaladas();
    void setCocinaPostres();
    void setLavadero();
    void setMesero();
    void setCliente();
    void setCocinero();
    void setMenu();
    void setTablaPlato();
    void setCaja();
    void setCajero();
    void initRestaurante();

	
    //Aadir configuracion por defecto
};

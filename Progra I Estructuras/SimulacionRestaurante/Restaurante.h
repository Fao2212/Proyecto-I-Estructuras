#include "Structs.h"
#include "qstring.h"
// Compuesta de estaciones, matriz de mesas , Lista de meseros ,Hilos para cada uno(Thread mesero,Thread cocinero...)
//Todo lo que esta en verde se puede cambiar en ejecucion / La entrada de clientes es un rango configurable entiempo de ejecucion
//Una ventana donde le pregunta si esta seguro de guardar los cambios APLY una
//EXTRA CAMBIO DE NOMBRE DE MESEROS EN EJECUCION//EXTRA REAL MOVIMIENTO EN GUI
//Para pila y cola si esta en cola se pone al final y si se pone en pila esta al principio, siempre se saca del inicio
//Mutex semaforos con una cola con datos y lo shilos osn procesos que estan al mismo tiempo proceso azul lee una cola y rojo la misma y dos instrucciones
//Leen la cola y otro tiene desencolar entonces uno hace if not nulo y da la instruccion de que no esta nulo y el mae de azul hace desencolar
//Y lo deja en nulo y se cae entonces lo que se hace es basada en una cola se bloquea y tiene que ser conpartido por todos los hilos que comparten una pila
//Si esta bloqueado y se hace un mutex se queda esperando if mutex haga si  no espere
//log y los al inicio y final del mutex se inicializa fuera de los hilos tiene que inicializarse en la estructura que tenga todos los hilos
//Es un mutex creado y compartido para los metodos que la utilizan y el hilo es que hace una lectura constante
//Main solo deberia hacer el new al restaurante
//Mutex en una ocla siemrpre y cuando todo tenga que usar la cola
struct Restaurante{
public:
    int cantidadDeMesas;
    int cantidadDeMeseros;//Todo esto pudo ser un array
    int tiempoDeGeneracionMinimo,tiempoDeGeneracionMaximo;
    int tiempoMinimoEntrada,tiempoMaximoEntrada,probabildadEntrada
        ,tiempoMinimoPrincipal,tiempoMaximoPrincipal,probabilidadPrincipal
        ,tiempoMinimoPostre,tiempoMaximoPostre,probabilidadPostre;
    int tiempoServicioMesero;
    EntradaDelRestaurante * entrada;
    ListaSimple<Mesero> * meseros;
    Mesa * matriz[5][4] = {{nullptr}};
    int consecutivoDeMesa;
    QString nombre;
    TablaPlatos * tabla;
    CocinaEnsaladas * cocinaEntradas;
    CocinaPrincipal * cocinaPrincipal;
    CocinaPostres * cocinaPostres;
    Lavadero * lavadero;
    Caja * caja;
    Menu * menu;
    Mesa * mesas[20] = {nullptr};
	//Hilos

    Restaurante(int cantidadDeMesas,int cantidadDeMeseros,QString nombre,int tiempoDeGeneracionMinimo
                ,int tiempoDeGeneracionMaximo,int tiempoMinimoEntrada, int tiempoMaximoEntrada,int probabildadEntrada
                ,int tiempoMinimoPrincipal,int tiempoMaximoPrincipal, int probabilidadPrincipal
                ,int tiempoMinimoPostre,int tiempoMaximoPostre,int probabilidadPostre);
    Restaurante();

    void cambiarTiempoMesero(Mesero * mesero,int tiempo);
    void cambiarTiempoCocinero(Cocinero * cocinero,int tiempo);
    void cambiarTiempoLavaplatos(Lavaplatos * lavaplatos,int tiempo);
    void cambiarTiempoCajero(Cajero * Cajero,int tiempo);
    void cambiarModoCaja();
    void cambiarTiempoLavadoPlato(Plato *plato, int tiempo);
    void cambiarTiempoPreparacionPlato(Plato *plato, int tiempo);
    void cambiarEstado();//De quien quiero cambiar el estado
    void setEntrada(int tiempoDeGeneracion,Estado * estado,int maximoDeGenerados);
    void setMeseros();
    void setMesasMeseros();
    void crearMatriz();
    int * getDisponible();
    void copiarMatriz(Mesa * matriz[5][4]);
    void cambiarTiempoGeneracion(int min, int max);

	
    //Aadir configuracion por defecto
};

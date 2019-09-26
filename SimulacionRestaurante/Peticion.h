#include "Structs.h"
#include "QString"
// tipo por el estado de la peticion de plato,tiempo,mesa,estado,responsable,mesero,cliente y se agrega en la cola del mesero
//La orden va junta la cocinada por separado

enum Fase : int{

    PEDIRENTRADA,COCINAENTRADA,COCINANDOENTRADA
    ,ENTRADATERMINADA,ENTREGAENTRADA,COMIENDOENTRADA
    ,LAVADAENTRADA,PEDIDAPRINCIPAL,COCINAPRINCIPAL,COCINANDOPRINCIPAL
    ,PRINCIPALTERMINADA,ENTREGAPRINCIPAL,COMIENDOPRINCIPAL
    ,LAVARPRINCIPAL,PEDIRPOSTRE,COCINAPOSTRE,COCINANDOPOSTRE
    ,POSTRETERMINADO,ENTREGAPOSTRE,COMIENDOPOSTRE,COBROCUENTA
    ,LAVARPOSTRE,CUENTAACAJA
};

struct Peticion {

    Fase fase;
	Mesa * mesa;
    int grupo;
    Plato * platos[6] = {nullptr};


    Peticion(Mesa * mesa,int grupo);
    void vaciarPlatos();
    void llenarPlatos(Plato plato);
    void setFase(Fase state);
	
};


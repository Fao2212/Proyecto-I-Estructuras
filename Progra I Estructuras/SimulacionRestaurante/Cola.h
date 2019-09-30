#include "Nodo.h"
#include "Structs.h"

template<typename T>
struct Cola {
    public:
    Nodo<T> * primerNodo;
	
    Cola();
    bool estaVacia();
    void encolar(T * dato);
    T * desencolar();//se aplica el ejemplo de objetos donde se pasa deuna cola a otra
    T * siguienteEnCola();
};

extern template struct Cola<Peticion>;
extern template struct Cola<GrupoDeClientes>;

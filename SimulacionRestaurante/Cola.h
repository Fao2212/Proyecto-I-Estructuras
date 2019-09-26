#include "Nodo.h"

template<typename T>
struct Cola {
    public:
    Nodo<T> * primerNodo;
	
    Cola();
    bool estaVacia();
    void encolar(T dato);
    Nodo<T> * desencolar();//se aplica el ejemplo de objetos donde se pasa deuna cola a otra
	
};

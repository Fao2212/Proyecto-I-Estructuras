#include "Nodo.h"
#include "Structs.h"


template<typename T>
struct ListaSimple{
	
    Nodo<T> * primerNodo;

    ListaSimple();
    void insertar();
    Nodo<T> * borrar();
    Nodo<T> * buscar(T buscado);
    bool estaVacia();
    int largo();
	
	
};

extern template struct ListaSimple<Mesa>;

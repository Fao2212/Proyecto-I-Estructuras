#include "Nodo.h"
#include "Structs.h"
#include "QString"


template<typename T>
struct ListaSimple{
	
    Nodo<T> * primerNodo;

    ListaSimple();
    void insertar(T * dato);
    Nodo<T> * borrar();
    Nodo<T> * buscar(T * buscado);
    bool estaVacia();
    int largo();
	
	
};

extern template struct ListaSimple<Mesa>;
extern template struct ListaSimple<QString>;

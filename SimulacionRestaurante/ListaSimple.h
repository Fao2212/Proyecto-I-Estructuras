#include "Nodo.h"

template<typename T>
struct ListaSimple{
	
    Nodo<T> * primerNodo;
	
    ListaSimple();
    void insertar();
    Nodo<T> * borrar();
    Nodo<T> * buscar(T buscado);
    bool estaVacia();
	
	
};

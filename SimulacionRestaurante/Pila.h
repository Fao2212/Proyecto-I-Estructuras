#include "Nodo.h"

template<typename T>
struct Pila{
	
    Nodo<T> * tos;
	
    Pila();
    bool estaVacia();
    Nodo<T> * pop();
    void push(T dato);
    Nodo<T> * peek();
    void imprimir();
	
};
//Para cambiar la pila a cola vaciar toda la pila en la cola y viceversa

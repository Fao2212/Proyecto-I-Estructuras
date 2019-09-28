#include "Cola.h"
#include "Nodo.h"

template<typename T>
Cola<T> :: Cola(){
    primerNodo = nullptr;
}

template<typename T>
bool Cola<T> :: estaVacia(){
    return primerNodo == nullptr;
}

template<typename T>
void Cola<T> :: encolar(T * dato){
    Nodo<T> * nuevo = new Nodo<T>(dato);
    if (estaVacia())

        primerNodo = nuevo;

    else{

        Nodo<T> * temp = primerNodo;
        while (temp -> siguiente != nullptr){
            temp = temp -> siguiente;

        }

        temp -> siguiente = nuevo;
    }
}
template<typename T>

T * Cola<T> :: desencolar(){
    Nodo<T> * borrado = primerNodo;

    if ((! estaVacia() && primerNodo -> siguiente == nullptr) || estaVacia())
        primerNodo = nullptr;

    else{

        primerNodo -> siguiente = nullptr;
        primerNodo = borrado -> siguiente;
        return borrado;

    }

    return borrado;
}

template<typename T>
T * Cola<T>:: siguienteEnCola(){
    return primerNodo;
}
//Se puede insertar al inicio cuando aparece la prioridad

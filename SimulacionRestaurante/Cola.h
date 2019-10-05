#include "Nodo.h"
#include "QDebug"
#include "Structs.h"

template<typename T>
struct Cola {
    public:
    Nodo<T> * primerNodo;
	
    Cola(){
        primerNodo = nullptr;
    }

    bool estaVacia(){
        return primerNodo == nullptr;
    }

    void encolar(T * dato){
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

    Nodo<T> * desencolar(){
        Nodo<T> * borrado = primerNodo;

        if ((! estaVacia() && primerNodo -> siguiente == nullptr) || estaVacia())
            primerNodo = nullptr;

        else{

            primerNodo = borrado -> siguiente;
            borrado -> siguiente = nullptr;
            return borrado;

        }

        return borrado;
    }

    Nodo<T> * siguienteEnCola(){
        return primerNodo;
    }

    void encolarAlIncio(T * dato){
        Nodo<T> * nuevo = new Nodo<T>(dato);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;

    }


//un insertar al inicio para la prioridad
};


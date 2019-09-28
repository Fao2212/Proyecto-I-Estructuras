#include "ListaSimple.h"
#include "Nodo.h"

template<typename T>
ListaSimple<T> :: ListaSimple(){
    primerNodo = nullptr;
}

template<typename T>
bool ListaSimple<T> :: estaVacia(){
    return primerNodo == nullptr;
}

template<typename T>
void ListaSimple<T> ::insertar(){
    Nodo<T> * nuevo = new Nodo<T>();
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
Nodo<T> * ListaSimple<T> ::borrar(){

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
Nodo<T> * ListaSimple<T> :: buscar(T buscado){
    Nodo<T> * temp = primerNodo;

    if(!estaVacia()){

        if (temp->siguiente != nullptr){
            while (temp != nullptr)
                if(temp -> dato != buscado)//que puede buscar
                    temp = temp -> siguiente;
                else
                    return temp;
        }
        else{
            if(temp -> dato == buscado)
                return temp;
        }
    }

    return nullptr;
}

template<typename T>
int ListaSimple<T>:: largo(){
    Nodo<T> * temp = primerNodo;
    int lar = 0;
    while (temp != nullptr){

        lar++;
        temp = temp -> siguiente;

    }
    return lar;
}

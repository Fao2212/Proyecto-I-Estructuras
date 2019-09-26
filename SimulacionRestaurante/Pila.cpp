#include "Pila.h"
#include "Nodo.h"
#include "QtDebug"

template<typename T>
Pila<T>::Pila(){
    this->tos = nullptr;
}
template<typename T>
bool Pila<T> :: estaVacia (){

    return this->tos == nullptr;

}
template<typename T>
void Pila<T> :: push (T dato){

    Nodo<T> * nuevo = new Nodo<T>(dato);
    nuevo -> siguiente = tos;
    tos = nuevo;

}
template<typename T>
Nodo<T> * Pila<T> :: pop (){

    if (tos != nullptr ){

        Nodo<T> * borrado = tos;

        if(tos->siguiente != nullptr){
            tos = tos ->siguiente;
            borrado -> siguiente = nullptr;
        }
        else
            tos = nullptr;
        return borrado;
    }
    else
        return nullptr;

}
template<typename T>
Nodo<T> * Pila<T> :: peek (){

    Nodo<T> * mostrado = tos;
    return mostrado;

}
template<typename T>
void Pila<T> :: imprimir(){
    while(tos != nullptr){
        qDebug()<<tos->dato;
        tos = tos->siguiente;
    }
}


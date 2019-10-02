#include "Nodo.h"
#include "Structs.h"
#include "QDebug"
#include "QString"


template<typename T>
struct ListaSimple{
	
    Nodo<T> * primerNodo;

    ListaSimple(){
        primerNodo = nullptr;
    }

    void insertar(T * dato){
        Nodo<T> * nuevo = new Nodo<T>(dato);
        if (estaVacia()){
qDebug()<< "43";
            primerNodo = nuevo;
}
        else{

            Nodo<T> * temp = primerNodo;
            while (temp -> siguiente != nullptr){
                temp = temp -> siguiente;

            }

            temp -> siguiente = nuevo;
        }
    }
    Nodo<T> * borrar(){

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
    Nodo<T> * buscar(T * buscado){
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
    bool estaVacia(){
        qDebug()<< "55";
        return primerNodo == nullptr;
    }
    int largo(){
        Nodo<T> * temp = primerNodo;
        int lar = 0;
        while (temp != nullptr){

            lar++;
            temp = temp -> siguiente;

        }
        return lar;
    }
	
	
};


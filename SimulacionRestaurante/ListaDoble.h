#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include "NodoD.h"
template<typename T>
struct ListaDoble{
   NodoD<T> * primerNodo;
   NodoD<T> * ultimoNodo;

   ListaDoble(){
       primerNodo = ultimoNodo = nullptr;
   }

   void insertar(T dato){
       NodoD<T> nuevo = new NodoD<T>(dato);
       if (primerNodo == nullptr){
           primerNodo = ultimoNodo = nuevo;
       }
       else{
           if(primerNodo == ultimoNodo){
               primerNodo->siguiente = nuevo;
               ultimoNodo = primerNodo->siguiente;
           }
           else{
               ultimoNodo->siguiente = nuevo;
           }

       }
   }

};
#endif // LISTADOBLE_H

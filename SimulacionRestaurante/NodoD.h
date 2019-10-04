#ifndef NODOD_H
#define NODOD_H
template<typename T>
struct NodoD{
  NodoD*siguiente;
  NodoD*anterior;
  T * dato;

  NodoD(){
      anterior = siguiente = nullptr;
      dato = nullptr;
  }
  NodoD(T* dato){
      anterior = siguiente = nullptr;
      this->dato = dato;
  }

};
#endif // NODOD_H

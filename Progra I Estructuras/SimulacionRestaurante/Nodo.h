#ifndef NODO_H
#define NODO_H

template<typename T>
struct Nodo{
public:
    Nodo * siguiente;
    T dato;
    
    Nodo(){
        siguiente = nullptr;
        this->dato = nullptr;
    }

    Nodo(T dato){
        siguiente = nullptr;
        this-> dato = dato;
    }
    
};

#endif // NODO_H

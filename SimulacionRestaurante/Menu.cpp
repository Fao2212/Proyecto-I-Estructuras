#include "Menu.h"
#include "ListaDoble.h"
#include "Random.h"
#include "Nodo.h"
#include "Plato.h"

//Se crea una lista simple con el nombre Menu y se cargar aca todos los platos
Menu :: Menu(){
    menu = new ListaDoble<Plato>();
}

    Plato * Menu :: platoAlAzar(Tipo tipo){

        NodoD<Plato> * temp3 = nullptr;
        int repeticiones = Random::RandomRange(47,123);
        while(int i = 0 < repeticiones){
            NodoD<Plato> * temp1 = menu->primerNodo;
            NodoD<Plato> * temp2 = menu->ultimoNodo;

            while(temp1 != nullptr){
                if(temp1->dato->tipo == tipo)
                    temp3 = temp1;
                temp1 = temp1->siguiente;
                i++;
            }
            while(temp2 != nullptr){
                if(temp2->dato->tipo == tipo)
                    temp3 = temp2;
                temp2 = temp2->anterior;
                i++;
            }

        }

        return temp3->dato;
    }

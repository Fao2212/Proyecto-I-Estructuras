#include "Utilidades.h"

template<typename T>
int  Utilidades<T> :: arraySize(T array[]){

        int cont = 0;
        T * comp;
        for(int i =0;i<6;i++){
            comp = array[i];
            if(comp!= nullptr)
                cont += 1;
        }
        return cont;
}

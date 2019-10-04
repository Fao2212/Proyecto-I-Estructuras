#ifndef CONSECUTIVO_H
#define CONSECUTIVO_H
#include "Structs.h"
#include "QString"
#include "QDateTime"

//Consnecutivos Conversion de datos To string

template <typename T>
struct Utilidades{

static int arraySize(T array[]){

    int cont = 0;
    T  comp;
    for(int i =0;i<6;i++){
        comp = array[i];
        if(comp!= nullptr)
            cont += 1;
    }
    return cont;
}

static QString getTime(){
    return QTime::currentTime().toString();
}

};

#endif // CONSECUTIVO_H

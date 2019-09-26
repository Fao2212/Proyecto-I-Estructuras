#include "Restaurante.h"
#include "QtDebug"
#include "Mesa.h"
#include "ListaSimple.cpp"

Restaurante::Restaurante(){
    this->consecutivoDeMesa = 0;
    this->meseros = new ListaSimple<Mesero>();
}

void Restaurante :: crearMatriz(){

   int mesas = this->cantidadDeMesas;
//Que pasa ccuando se ingresan 0 mesas no entra todo queda en 0
   for(int i =0;i < mesas;i++){
       int * coordenadas = getDisponible();
       if(coordenadas != nullptr)
           this->consecutivoDeMesa += 1;
           matriz[coordenadas[0]][coordenadas[1]] = new Mesa(this->consecutivoDeMesa);
   }
}

 int * Restaurante :: getDisponible(){
     static int coordenadas[2] = {0};
     for(int i = 0;i <5;i++){
         for(int j = 0;j<4;j++){
             if(matriz[i][j]==nullptr){
                 coordenadas[0] = i;
                 coordenadas[1] = j;
                 return coordenadas;
             }
         }
     }
     return nullptr;
 }

/* int main(int argc, char *argv[])
 {
     Restaurante * r = new Restaurante();
     //Mesa * m = new Mesa();
     //qDebug ()<< m;
     r->crearMatriz();// = m;
     qDebug()<<r->matriz[0][0];
     qDebug()<<r->matriz[0][1];
     qDebug()<<r->matriz[0][2];
     qDebug()<<r->matriz[0][3];
     qDebug()<<r->matriz[1][0];
     qDebug()<<r->matriz[1][1];
     qDebug()<<r->matriz[1][2];
     qDebug()<<r->matriz[1][3];
     return 0;
 }*/

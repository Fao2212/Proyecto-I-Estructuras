#include "Restaurante.h"
#include "QtDebug"
#include "Mesa.h"
#include "ListaSimple.cpp"
#include "EntradaRestaurante.h"
#include "TablaPlatos.h"
#include "CocinaEnsaladas.h"
#include "CocinaPostres.h"
#include "CocinaPrincipal.h"
#include "Caja.h"
#include "Lavadero.h"
#include "Menu.h"

Restaurante::Restaurante(){
    initRestaurante();
}

void Restaurante :: crearMatriz(){

   int mesas = this->cantidadDeMesas;
   for(int i =0;i < mesas;i++){
       int * coordenadas = getDisponible();
       if(coordenadas != nullptr)
           this->consecutivoDeMesa += 1;
           matriz[coordenadas[0]][coordenadas[1]] = new Mesa(this->consecutivoDeMesa);
   }
}

 int * Restaurante :: getDisponible(){//devuelve un par disponible para asignar a la matriz
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

 void Restaurante:: initRestaurante(int cantidadDeMesas,int cantidadDeMeseros,QString nombre,int tiempoDeGeneracionMinimo
                                    ,int tiempoDeGeneracionMaximo,int tiempoMinimoEntrada, int tiempoMaximoEntrada,int probabildadEntrada
                                    ,int tiempoMinimoPrincipal,int tiempoMaximoPrincipal, int probabilidadPrincipal
                                    ,int tiempoMinimoPostre,int tiempoMaximoPostre,int probabilidadPostre){
     this->consecutivoDeMesa = 0;
     this->cantidadDeMesas = cantidadDeMesas;
     this->cantidadDeMeseros = cantidadDeMeseros;
     this->tiempoDeGeneracionMinimo = tiempoDeGeneracionMinimo;
     this->tiempoDeGeneracionMaximo = tiempoDeGeneracionMaximo;
     this->tiempoMinimoPostre = tiempoMinimoPostre;
     this->tiempoMaximoPostre = tiempoMaximoPostre;
     this-> tiempoMaximoEntrada = tiempoMaximoEntrada;
     this-> tiempoMinimoEntrada = tiempoMinimoEntrada;
     this->tiempoMaximoPrincipal =tiempoMaximoPrincipal;
     this->tiempoMinimoPrincipal = tiempoMinimoPrincipal;
     this->probabilidadPrincipal = probabilidadPrincipal;
     this->probabildadEntrada = probabildadEntrada;
     this->probabilidadPostre = probabilidadPostre;
     this->nombre = nombre;
     crearMatriz();
     this->entrada = new EntradaDelRestaurante(6,this->tiempoDeGeneracionMinimo,this->tiempoDeGeneracionMaximo,
                                               this->matriz,this->cantidadDeMesas);
     this->meseros = new ListaSimple<Mesero>();
     //Falta crear el menu puedo cambiar la lista simple por una circular
     this->tabla = new TablaPlatos(this->tiempoMinimoEntrada,this->tiempoMaximoEntrada,this->probabildadEntrada
                                   ,this->tiempoMinimoPrincipal,this->tiempoMaximoPrincipal,this->probabilidadPrincipal
                                   ,this->tiempoMinimoPostre,this->tiempoMaximoPostre,this->probabilidadPostre);
     this->cocinaEntradas = new CocinaEnsaladas();
     this->cocinaPostres = new CocinaPostres();
     this->cocinaPrincipal = new CocinaPrincipal();
     this->lavadero = new Lavadero();
     this->caja = new Caja();
     this->menu = new Menu();

 }//Si se quiere hacer un init default llamar la funcion con valores default
